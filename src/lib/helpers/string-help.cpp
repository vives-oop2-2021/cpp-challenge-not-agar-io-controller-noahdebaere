#include "string_helper.h"

namespace NotAgarIOController {

  std::string StringHelper::generate_single_character_string(char character, unsigned int length) {
    std::string output = "";
    for (unsigned int i = 0; i < length; i++) {
      output += character;
    }
    return output;
  }

  std::string StringHelper::center_text(std::string text, unsigned int boundaryLength) {
    if (boundaryLength > text.length()) {
      unsigned int leftOverSpace = boundaryLength - text.length();
      unsigned int leftSideSpaces = leftOverSpace / 2;
      unsigned int rightSideSpaces = (leftOverSpace / 2) + (leftOverSpace % 2);

      text = StringHelper::generate_single_character_string(' ', leftSideSpaces)
        + text + StringHelper::generate_single_character_string(' ', rightSideSpaces);
    }
    return text;
  }

  std::string StringHelper::pad_text(std::string text, unsigned int totalLength, char character, bool padAtBack) {
    for (unsigned int i = text.length(); i < totalLength; i++ ) {
      if (padAtBack) {
        text += character;
      } else {
        text = character + text;
      }
    }
    return text;
  }

};