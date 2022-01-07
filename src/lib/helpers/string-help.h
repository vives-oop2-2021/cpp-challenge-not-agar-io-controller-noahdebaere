#pragma once
#include <string>
#include <vector>

namespace NotAgarIOController {

  class StringHelper {

    public:
      //static bool is_valid_number(std::string value);
      //static bool try_to_parse_number(std::string value, int * number);
      static std::string generate_single_character_string(char character, unsigned int length);
      //static int index_of_space_before(std::string text, unsigned int index);
      static std::string center_text(std::string text, unsigned int boundaryLength);
      //static std::vector<std::string> wrap_text(std::string text, unsigned int wrapLength);
      static std::string pad_text(std::string text, unsigned int totalLength, char character=' ', bool padAtBack=true);
  };

};