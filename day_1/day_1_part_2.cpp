
#include "../types/types.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

// we have this:
// 3   4
// 4   3
// 2   5
// 1   3
// 3   9
// 3   3
//
// we need to get to this:
//
// 1   3
// 2   3
// 3   3
// 3   4
// 3   5
// 4   9
//

bool comp(int a, int b) { return a >= b; }

int main(int argc, char *argv[]) {
  // read user input
  // store the input as string
  // remove the whitespaces
  // then we need to sort the left side
  // then we need to sort the right side
  // if i % 2 == 0 -> ako je paran onda ide levo
  // if i % 2 != 0 -> ako ne neparan onda ide desno

  // later try to remove the x, y and append to the list from the std::cin
  // (append from the input)
  int x, y;
  int_array left_values;
  int_array right_values;

  string_type line;

  std::cout << "Enter your input: \n" << std::endl;
  while (true) {
    std::getline(std::cin, line);

    // check for blank line
    if (line.empty()) {
      break;
    }

    // when the line is not empty we should parse the integers
    // the istringstream is skipping the whitespaces and treats the input
    // as input string (read numbers, float and etc from string)
    std::istringstream iss(line);
    if (iss >> x >> y) {
      std::cout << "Read pair: " << x << " " << y << std::endl;
      left_values.push_back(x);
      right_values.push_back(y);
    } else {
      std::cerr << "Invalid input. Please enter two integers." << std::endl;
    }
  }

  std::sort(left_values.begin(), left_values.end(), comp);
  std::sort(right_values.begin(), right_values.end(), comp);

  int result = 0;

  while (!left_values.empty() && !right_values.empty()) {
    int val_left = left_values.back();
    int val_right = right_values.back();

    int res = 0;
    if (val_right > val_left) {
      res = val_right - val_left;
    }

    if (val_right < val_left) {
      res = val_left - val_right;
    }

    result += res;

    left_values.pop_back();
    right_values.pop_back();
  }

  std::cout << result << "\n";

  return result;
}
