#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int get_game_id(const std::string &record) {
  const std::regex pattern("Game (\\d+):");
  std::smatch match;
  std::regex_search(record, match, pattern);
  return std::stoi(match[1]);
}

int get_max_color_count(const std::string &color, std::string record) {
  const std::regex pattern("(\\d+) " + color);

  std::sregex_iterator it(record.begin(), record.end(), pattern);
  std::sregex_iterator end;
  int max = 0;

  while (it != end) {
    if (int count = std::stoi(it->str(1)); count > max) {
      max = count;
    }
    ++it;
  }

  return max;
}

int solve_part_1(const std::vector<std::string> &input_lines) {
  int sum = 0;

  for (const auto &line : input_lines) {
    if (get_max_color_count("red", line) > 12) {
      continue;
    }
    if (get_max_color_count("green", line) > 13) {
      continue;
    }
    if (get_max_color_count("blue", line) > 14) {
      continue;
    }

    sum += get_game_id(line);
  }

  return sum;
}

int solve_part_2(const std::vector<std::string> &input_lines) {
  int sum = 0;

  for (const auto &line : input_lines) {
    const int red = get_max_color_count("red", line);
    const int green = get_max_color_count("green", line);
    const int blue = get_max_color_count("blue", line);

    sum += red * green * blue;
  }

  return sum;
}

std::vector<std::string> read_input_file() {
  std::ifstream input_file("input");

  if (!input_file.is_open()) {
    std::cerr << "Failed to open input file" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(input_file, line)) {
    lines.push_back(line);
  }
  return lines;
}

int main() {
  const std::vector<std::string> input_lines = read_input_file();
  std::cout << solve_part_1(input_lines) << std::endl;
  std::cout << solve_part_2(input_lines) << std::endl;
  return 0;
}
