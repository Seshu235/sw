#include <iostream>

int main() {
  bool is_true = true;

  std::cout << "Enter bool value (0 or 1): ";
  std::cin >> is_true;

  if (is_true) {
    std::cout << "Condition True\n";
  } else {
    std::cout << "Condition False\n";
  }

  return 0;
}