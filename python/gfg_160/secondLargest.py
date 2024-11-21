class Solution:
  def getSecondLargest(self, arr):
    n = len(arr)
    
    if n < 2:
      return -1
    
    largest = second_largest = float('-inf')
    
    for num in arr:
      if num > largest:
        second_largest = largest
        largest = num
      elif num > second_largest and num != largest:
        second_largest = num

    if second_largest == float('-inf'):
      return -1
    else:
      return second_largest
    
if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    arr = list(map(int, input().split()))
    ob = Solution()
    ans = ob.getSecondLargest(arr)
    print(ans)
    print("~")