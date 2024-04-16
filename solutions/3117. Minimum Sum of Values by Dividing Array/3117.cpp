// Time complexity: O(n*m*log(max element))
// Space complexity: O(n*m*log(max element))
class Solution {
public:
  int minimumValueSum(const vector<int>& nums, const vector<int>& andValues) {
    vector<vector<unordered_map<int, int>>> mem(
      nums.size(), vector<unordered_map<int, int>>(andValues.size()));

    const int ans = minimumValueSum(nums, andValues, 0, 0, kAllMask, mem);

    return ans == kInf ? -1 : ans;
  }
private:
  static constexpr int kInf = 1'000'000'000;
  static constexpr int kAllMask = (1 << 17) - 1;

  int minimumValueSum(const vector<int>& nums, const vector<int>& andValues, 
                      int i, int j, int mask, 
                      vector<vector<unordered_map<int, int>>>& mem) {
    if (i == nums.size() && j == andValues.size())
      return 0;
    if (i == nums.size() || j == andValues.size())
      return kInf;
    if (const auto it = mem[i][j].find(mask); it != mem[i][j].cend())
      return it->second;
    mask &= nums[i];
    if (mask < andValues[j])
      return mem[i][j][mask] = kInf;
    if (mask == andValues[j])
      return mem[i][j][mask] = 
                min(minimumValueSum(nums, andValues, i + 1, j, mask, mem),
                    nums[i] + minimumValueSum(nums, andValues, i + 1, j + 1,
                                              kAllMask, mem));

    return mem[i][j][mask] = 
              minimumValueSum(nums, andValues, i + 1, j, mask, mem);           
  };  
};