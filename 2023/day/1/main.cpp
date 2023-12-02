#include <fstream>
#include <iostream>
#include <regex>
#include <string>

std::regex pattern_part_1("[1-9]");
std::regex pattern_part_2(
    "[1-9]"
    "|oneight|twone|threeight|fiveight|sevenine|eightwo|eighthree|nineight"
    "|one|two|three|four|five|six|seven|eight|nine");
std::unordered_map<std::string, int> digits = {
    {"1", 11},        {"2", 22},       {"3", 33},         {"4", 44},
    {"5", 55},        {"6", 66},       {"7", 77},         {"8", 88},
    {"9", 99},

    {"one", 11},      {"two", 22},     {"three", 33},     {"four", 44},
    {"five", 55},     {"six", 66},     {"seven", 77},     {"eight", 88},
    {"nine", 99},

    {"oneight", 18},  {"twone", 21},   {"threeight", 38}, {"fiveight", 58},
    {"sevenine", 79}, {"eightwo", 82}, {"eighthree", 83}, {"nineight", 98},
};

int solve(std::ifstream &input_file, std::regex &pattern) {
  std::string line;
  int sum = 0;

  while (std::getline(input_file, line)) {
    std::sregex_iterator it(line.begin(), line.end(), pattern);
    std::sregex_iterator end;

    std::string first_match = it->str(), last_match;
    while (it != end) {
      last_match = it->str();
      ++it;
    }

    int first = digits[first_match] / 10;
    int last = digits[last_match] % 10;
    sum += first * 10 + last;
  }

  return sum;
}

int main() {
  std::ifstream input_file("input");

  if (!input_file.is_open()) {
    std::cerr << "Could not open input file" << std::endl;
    return 1;
  }

  std::cout << solve(input_file, pattern_part_2) << std::endl;
  return 0;
}
