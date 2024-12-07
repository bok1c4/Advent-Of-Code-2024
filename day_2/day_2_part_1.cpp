#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using string_type = std::string;

bool is_safe(const string_type &line) {
  std::istringstream stream(line);
  std::vector<int> levels;
  int number;

  while (stream >> number) {
    levels.push_back(number);
  }

  if (levels.size() < 2)
    return true;

  bool is_increasing = levels[1] > levels[0];
  bool is_decreasing = levels[1] < levels[0];

  for (size_t i = 1; i < levels.size(); ++i) {
    int diff = levels[i] - levels[i - 1];

    if (std::abs(diff) < 1 || std::abs(diff) > 3) {
      return false;
    }

    if (is_increasing && diff <= 0)
      return false;
    if (is_decreasing && diff >= 0)
      return false;
  }

  return true;
}

int main() {
  std::vector<string_type> reports;
  string_type line;

  std::cout << "Enter reports (press Enter twice or EOF to finish):"
            << std::endl;

  while (std::getline(std::cin, line)) {
    if (line.empty()) {
      break;
    }
    reports.push_back(line);
  }

  int safe_count = 0;

  for (const auto &report : reports) {
    if (is_safe(report)) {
      ++safe_count;
    }
  }

  std::cout << "Number of safe reports: " << safe_count << std::endl;

  return 0;
}
