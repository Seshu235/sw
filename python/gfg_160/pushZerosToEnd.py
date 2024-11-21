class Solution:
  # Method 1
  '''
  def pushZerosToEnd(self, arr):   
    n = len(arr)
    nonzero_index = 0
    
    for i in range(n):
      if arr[i] != 0:
        arr[nonzero_index] = arr[i]
        nonzero_index += 1
            
    for i in range(nonzero_index, n):
      arr[i] = 0
'''
  # Method 2
  def pushZerosToEnd(self, arr):
    count = 0

    for i in range(len(arr)):
      if arr[i] != 0:
        arr[i], arr[count] = arr[count], arr[i]
        count += 1
    
if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    arr = list(map(int, input().split()))
    ob = Solution()
    ob.pushZerosToEnd(arr)
    n = len(arr)
    for num in arr:
      print(num, end=" ")
    print()
    t -= 1