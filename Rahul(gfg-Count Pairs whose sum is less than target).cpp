class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size(), left=0, right=n-1, ans=0;
        sort(arr.begin(), arr.end());
        
        while(left < right){
            if(arr[left] + arr[right] < target) ans += right - left, left++;
            else right--;
        }
        return ans;
    }
};
