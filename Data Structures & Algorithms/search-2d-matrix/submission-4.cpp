class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
    int left = 0, right = matrix.size() - 1;

  while (left <= right) {
    
    int mid = left + (right - left) / 2;

    if (left == mid || right == mid) {
        int low = 0; int high = matrix[mid].size()-1;
        int row=mid;
        if(matrix[mid][0]>target){row = mid -1;}
      while (low <= high && row>=0) {
            int row_mid = low + (high - low) / 2;

        if (matrix[row][row_mid] == target) {
          return true; // Found it

        } else if (matrix[row][row_mid] < target) {
          low = row_mid + 1;

        } else {
          high = row_mid - 1;
        }



      }
    }

    if (matrix[mid][0] == target) {
      return true; // Found it

    } else if (matrix[mid][0] < target) {
      left = mid + 1;

    } else {
      right = mid - 1;
    }

  }
  return false;
}


};
