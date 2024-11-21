#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
      int n = arr.size();

      for (size_t i = 0, j = n-1; i < j; i++, j--)
      {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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
    obj.reverseArray(arr);
    for (size_t i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }    
    cout << "\n" << endl;
  }
  return 0;
}