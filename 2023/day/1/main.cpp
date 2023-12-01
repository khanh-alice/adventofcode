#include <fstream>
#include <iostream>
#include <regex>
#include <string>

// std::regex pattern("[1-9]"); // part 1
std::regex pattern(
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

int main() {
  std::ifstream inputFile("input");

  if (!inputFile.is_open()) {
    std::cerr << "Could not open input file" << std::endl;
    return 1;
  }

  std::string line;
  int sum = 0;

  while (std::getline(inputFile, line)) {

    std::sregex_iterator it(line.begin(), line.end(), pattern);
    std::sregex_iterator end;
    std::vector<std::string> matches;

    while (it != end) {
      matches.push_back(it->str());
      ++it;
    }

    int first = digits[matches[0]] / 10;
    int last = digits[matches[matches.size() - 1]] % 10;
    sum += first * 10 + last;
  }

  std::cout << sum << std::endl;

  inputFile.close();
  return 0;
}
