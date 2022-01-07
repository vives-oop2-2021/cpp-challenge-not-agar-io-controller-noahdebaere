# The compiler
CC=g++

# Compiler flags
CFLAGS=-c -Wall -std=c++17
    # -c: Compile or assemble the source files, but do not link.
    # -Wall: This enables all the warnings about constructions that

# Linker flags
# LDFLAGS=

# Libraries
# LIBS=

# Name of executable output
TARGET=controller
SRCDIR=src
LIBDIR=$(SRCDIR)/lib
BUILDDIR=bin

OBJS := $(SRCDIR)/main.o \
				$(LIBDIR)/player.o \
				$(LIBDIR)/menu/main_menu.o \
				$(LIBDIR)/menu/menu_item.o \

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