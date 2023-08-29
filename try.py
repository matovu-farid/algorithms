t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    res = arr[0]
    for i in range(1, n):
        res ^= arr[i]
    bitLength = res.bit_length() 
    ans = 1 << bitLength - 1 if bitLength > 0 else 0
    print(ans)
class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        maxLength = 1
       
        for i in range(n):
            length = 0
            remaining = k
            for j in range(i + 1, n):
                if nums[i] == nums[j]:
                    length += 1
                else:
                    remaining -= 1
                if remaining == 0:
                    break
            maxLength = max(maxLength, length)
            
                    

            return maxLength
        
