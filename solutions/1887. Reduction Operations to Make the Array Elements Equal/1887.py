# Time complexity: O(sort)
# Space complexity: O(sort)
class Solution:
  def reductionOperations(self, nums: List[int]) -> int:
    ans = 0
    nums.sort()

    for i in range(len(nums) - 1, 0, -1):
      if nums[i] != nums[i - 1]:
        ans += len(nums) - i

    return ans