# Time Complexity: O(n)
# Space Complexity: O(1)
class Solution:
  def singleNumber(self, nums: List[int]) -> List[int]:
    xors = functools.reduce(operator.xor, nums)
    lowbit = xors & -xors
    ans = [0, 0]

    for num in nums:
      if num & lowbit:
        ans[0] ^= num
      else:
        ans[1] ^= num

    return ans