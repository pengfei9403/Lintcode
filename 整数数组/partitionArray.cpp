class Solution {
	public:
		int partitionArray(vector<int> &nums, int k) {
			// write your code here
			int len = nums.size() ;
			for(int i = 0 ; i < len ;){
				if(nums[i] >= k){
					swap(nums[i],nums[len-1]);
					len--;
				}else{
					i++;
				}
			}
			return len ;
		}
};