#include <iostream>
#include <string>

int main() {
  std::string first = "Seshu";
  std::string last = "Babu";
  std::string name = first.append(last);
  int size = name.max_size();

  std::cout << "Value of name using append: " << name << std::endl;
  return 0;
}