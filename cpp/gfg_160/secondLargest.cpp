#include <iostream>
#include <vector>
#include <sstream>

class Solution {
  public:
    int getSecondLargest(std::vector<int> &arr) {
      int largest = -1;
      int second_largest = -1;

      for (size_t i = 0; i < arr.size(); i++)
      {
        if (arr[i] > largest) {
          second_largest = largest;
          largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
          second_largest = arr[i];
        }
      }
      
      return second_largest;
    }
};

int main() {
  int t;
  std::cin >> t;
  std::cin.ignore();

  while (t--) {
    std::vector<int> arr;
    std::string input;
    getline(std::cin, input);
    std::stringstream ss(input);
    int number;
    
    while (ss >> number)
    {
      arr.push_back(number);
    }
    Solution obj;
    int ans = obj.getSecondLargest(arr);
    std::cout << ans << std::endl;
    std::cout << "~" << std::endl;
  }
  return 0;
}