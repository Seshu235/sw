#include <iostream>

int main() {
  std::string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  std::cout << "The length of the txt string using length() is: " << txt.length() << std::endl;

  std::cout << "The length of the txt string using size() is: " << txt.size() << std::endl;

  std::cout << "Max size of the txt string is: " << txt.max_size() << std::endl;
  return 0;
}