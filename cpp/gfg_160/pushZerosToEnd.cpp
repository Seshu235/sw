#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int> &arr) {
      int nonzero_index = 0;
      int n = arr.size();

      for (size_t i = 0; i < n; i++)
      {
        if (arr[i] != 0) {
          int temp = arr[i];
          arr[i] = arr[nonzero_index];
          arr[nonzero_index] = temp;
          nonzero_index++;
        }
      }
    }
};

int main() {
  int t;
  cin >> t;
  cin.ignore();

  while (t--) {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;

    while (ss >> number) 
    {
      arr.push_back(number);
    }
    Solution obj;
    int n = arr.size();
    obj.pushZerosToEnd(arr);
    for (size_t i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }    
    cout << "\n" << endl;
  }
  return 0;
}