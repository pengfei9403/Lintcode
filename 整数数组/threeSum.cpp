class Solution {
	public:    
		/**
		 * @param numbers : Give an array numbers of n integer
		 * @return : Find all unique triplets in the array which gives the sum of zero.
		 */
		vector<vector<int> > threeSum(vector<int> &nums) {
			// write your code here
			sort(nums.begin(),nums.end());
			vector<vector<int> > ans ;
			set<vector<int> > set ;
			int len = nums.size() ;
			for(int i = 0 ; i < len ; i++){
				int end = len - 1 ;
				for(int j = i+1 ; j < end ; ){
					int sum = nums[i] + nums[j] + nums[end] ;
					if(0 == sum){
						vector<int> temp ;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[end]);
						set.insert(temp);
					}
					if(0 < sum){
						end--;
					}else{
						j++ ;
					}
				}
			}
			for(auto point = set.begin() ; point != set.end() ; point++){
				ans.push_back(*point);
			}
			return ans ;
		}
};
