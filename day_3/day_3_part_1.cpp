#include <iostream>
#include <regex>
#include <string>

using namespace std;

// Type alias for clarity
typedef std::basic_string<char> basic_string_char;

// Function to calculate the product of numbers in a "mul(number1,number2)"
// pattern
int calculate(basic_string_char match) {
  cout << "Processing match: " << match << endl;

  std::regex num_expr(R"(\((\d+),(\d+)\))"); // Regex to extract numbers
  std::smatch num_match;

  if (std::regex_search(match, num_match, num_expr) && num_match.size() == 3) {
    // Extract numbers
    int num1 = std::stoi(num_match[1].str());
    int num2 = std::stoi(num_match[2].str());

    // Multiply the numbers
    int result = num1 * num2;
    cout << "Result of multiplication: " << result << endl;
    return result;
  }

  cout << "Invalid format, no numbers found to multiply." << endl;
  return 0;
}

int main() {
  std::string str;

  cout << "Enter the input string:\n";
  std::getline(cin, str); 

  std::regex str_expr(R"(mul\((\d{1,3}),(\d{1,3})\))");

  std::sregex_iterator currentMatch(str.begin(), str.end(), str_expr);
  std::sregex_iterator lastMatch;

  int totalResult = 0;

  while (currentMatch != lastMatch) {
    std::smatch match = *currentMatch;
    std::string fullMatch = match.str();
    int res = calculate(fullMatch);
    totalResult += res;
    currentMatch++;
  }

  std::cout << "\nTotal Result: " << totalResult << endl;

  return 0;
}

