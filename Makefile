# The compiler
CC=g++

# Compiler flags
CFLAGS=-c -Wall -std=c++17
    # -c: Compile or assemble the source files, but do not link.
    # -Wall: This enables all the warnings

# Linker flags
LDFLAGS=-lcurlpp -lcurl

# Libraries
LIBS=-lcurlpp -lcurl

# Name of executable output
TARGET=controller
SRCDIR=src
LIBDIR=$(SRCDIR)/lib
BUILDDIR=build

OBJS := $(SRCDIR)/main.o \
				$(LIBDIR)/player.o \
				$(LIBDIR)/controller.o \
				$(LIBDIR)/player_manager.o \
				$(LIBDIR)/game.o \
				$(LIBDIR)/user_io.o \
				$(LIBDIR)/interact.o \
				$(LIBDIR)/helpers/terminal-help.o \
				$(LIBDIR)/helpers/string-help.o \
				$(LIBDIR)/menu/main_menu.o \
				$(LIBDIR)/menu/menu_item.o \
				$(LIBDIR)/menu/loading-screen.o \
				
all: builddir $(TARGET)

run: all
	./$(BUILDDIR)/$(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(BUILDDIR)/$@ $(OBJS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(BUILDDIR)
	rm -f $(OBJS)

builddir:
	mkdir -p $(BUILDDIR)