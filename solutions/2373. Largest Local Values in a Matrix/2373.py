# Time complexity: O(n^2)
# Space complexity: O(n^2)
class Solution:
  def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
    n = len(grid)
    ans = [[0] * (n - 2) for _ in range(n -2)]

    for i in range(n - 2):
      for j in range(n - 2):
        for x in range(i, i + 3):
          for y in range(j, j + 3):
            ans[i][j] = max(ans[i][j], grid[x][y])

    return ans        