class Solution {
	public:
		/**
		 * @param nums: a rotated sorted array
		 * @return: the minimum number in the array
		 */
		int findMin(vector<int> &nums) {
			// write your code here
			int min ;
			int left = 0 ;
			int right = nums.size()-1 ;
			int mid = (left+right) / 2 ;
			if(nums.empty()){
				return min ;
			}
			min = nums[mid] ;
			while(left < right){
				if(nums[left] < nums[right]){
					if(nums[left] < min){
						return nums[left] ;
					}else{
						return min ;
					}
				}
				if(nums[right] < nums[mid]){
					left = mid+1 ;
				}else{
					right = mid-1 ;
				}
				mid = (left+right) / 2 ;
				if(nums[mid] < min){
					min = nums[mid] ;
				}
			}
			if(nums[mid] < min){
				min = nums[mid] ;
			}
			return min ;
		}
};