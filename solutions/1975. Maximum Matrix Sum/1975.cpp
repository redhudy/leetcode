// Time complexity: O(mn)
// Space complexity: O(1)
class Solution {
 public:
  long long maxMatrixSum(const vector<vector<int>>& matrix) {
    long absSum = 0;
    int minAbs = INT_MAX;
    int oddNeg = 0;

    for (const vector<int>& row : matrix)
      for (const int num : row) {
        absSum += abs(num);
        minAbs = min(minAbs, abs(num));
        if (num < 0)
          oddNeg ^= 1;
      }

    return absSum - oddNeg * minAbs * 2;
  }
};