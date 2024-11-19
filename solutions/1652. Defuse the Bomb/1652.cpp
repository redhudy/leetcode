// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> decrypt(const vector<int>& code, int k) {
    const int n = code.size();
    vector<int> ans(n);

    if (k == 0)
      return ans;

    int sum = 0;
    int start = k > 0 ? 1 : n + k;
    int end = k > 0 ? k : n - 1;

    for (int i = start; i <= end; ++i)
      sum += code[i];

    for (int i = 0; i < n; ++i) {
      ans[i] = sum;
      sum -= code[start++ % n];
      sum += code[++end % n];
    }

    return ans;
  }
};