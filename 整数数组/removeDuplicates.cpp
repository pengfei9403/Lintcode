class Solution {
	public:
		/**
		 * @param A: a list of integers
		 * @return : return an integer
		 */
		int removeDuplicates(vector<int> &nums) {
			// write your code here
			int ans ;
			if(nums.empty()){
				return ans ;
			}
			int old = nums[0] ;
			vector<int>::iterator temp = nums.begin() ;
			for(int i = 1 ; i < nums.size() ; i++){
				if(old == nums[i]){
					nums.erase(temp+i);
					i-- ;
				}else{
					old = nums[i] ;
				}
			}
			ans = nums.size();
			return ans ;
		}
};