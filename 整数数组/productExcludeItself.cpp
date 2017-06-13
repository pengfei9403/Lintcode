class Solution {
	public:
		/**
		 * @param A: Given an integers array A
		 * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
		 */
		vector<long long> productExcludeItself(vector<int> &nums) {
			// write your code here
			int len = nums.size();
			long long left[len];
			long long right[len];
			left[0] = 1 ; right[len-1] = 1 ;
			long long left_temp = 1 , right_temp = 1 ;
			vector<long long> ans ;
			for(int i = 1 ; i < len ; i++){
				left_temp *= nums[i-1] ;
				right_temp *= nums[len-i] ;
				left[i] = left_temp ;
				right[len-i-1] = right_temp ;
			}
			for(int i = 0 ; i < len ; i++){
				ans.push_back(left[i]*right[i]);
			}
			return ans ;
		}
};