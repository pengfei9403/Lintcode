class Solution {
	public:    
		/**
		 * @param numbers: Give an array numbers of n integer
		 * @param target: An integer
		 * @return: return the sum of the three integers, the sum closest target.
		 */
		int threeSumClosest(vector<int> nums, int target) {
			// write your code here
			sort(nums.begin(),nums.end());
			int len = nums.size() ;
			int diff = 0 ;
			int mindiff = abs(target - nums[0] - nums[1] - nums[2]);
			int minsum = 0 ;
			for(int i = 0 ; i < len ; i++){
				int end = len-1 ;
				for(int j = i+1 ; j < end ; ){
					diff = target - nums[i] - nums[j] - nums[end];
					if(abs(diff) <= mindiff){
						mindiff = abs(diff) ;
						minsum = nums[i] + nums[j] + nums[end] ;
					}
					if(diff < 0){
						end--;
					}else{
						j++;
					}
				}
			}
			return minsum;
		}
};
