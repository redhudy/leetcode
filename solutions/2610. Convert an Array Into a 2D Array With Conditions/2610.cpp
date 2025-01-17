// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<vector<int>> findMatrix(const vector<int>& nums) {
    vector<int> freq(nums.size() + 1);
    vector<vector<int>> ans;

    for (int num : nums) {
      if (freq[num] >= ans.size())
        ans.push_back({});

      ans[freq[num]].push_back(num);
      freq[num]++;
    }

    return ans;
  }
};