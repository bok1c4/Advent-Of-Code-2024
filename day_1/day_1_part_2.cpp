#include "../types/types.h"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

bool comp(int a, int b) { return a >= b; }

bool check_or_push(int_queue &queue, int val) {
  if (queue.empty()) {
    queue.push(val);
    return false;
  }

  int_queue cp_queue = queue;

  while (!cp_queue.empty()) {
    int back_val = cp_queue.front();
    if (val == back_val)
      return true;
    cp_queue.pop();
  }

  queue.push(val);
  return false;
}

void print_queue(int_queue queue) {
  int_queue cp_queue = queue;
  while (!cp_queue.empty()) {
    std::cout << cp_queue.front() << " ";
    cp_queue.pop();
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  int x, y;
  int_array left_values;
  int_array right_values;

  string_type line;

  std::cout << "Enter your input: \n" << std::endl;
  while (true) {
    std::getline(std::cin, line);

    if (line.empty()) {
      break;
    }

    // Parse integers from input
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

  int_int_hashmap hm;
  for (int val : right_values) {
    hm[val]++;
  }

  int result = 0;
  int_queue queue;

  while (!left_values.empty()) {
    int back_value = left_values.back();
    std::cout << "Processing value: " << back_value << '\n';

    if (check_or_push(queue, back_value)) {
      left_values.pop_back();
      continue;
    }

    int count = hm[back_value];

    if (count > 0) {
      int calc = back_value * count;
      result += calc;
      std::cout << "Value: " << back_value << ", Count: " << count
                << ", Increment: " << calc << std::endl;
    }

    left_values.pop_back();
    print_queue(queue);
  }

  std::cout << "Result: " << result << std::endl;
  return result;
}

