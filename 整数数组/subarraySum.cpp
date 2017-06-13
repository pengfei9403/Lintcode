class Solution {
	public:
		/**
		 * @param nums: A list of integers
		 * @return: A list of integers includes the index of the first number 
		 *          and the index of the last number
		 */
		vector<int> subarraySum(vector<int> nums){
			// write your code here
			int begin = -1 , end ;
			int len = nums.size() ;
			int sortsum[len] ;
			int indexsum[len] ;
			int find = 0 , sum = 0 ;
			vector<int> ans ;
			for(int i = 0 ; i < len ; i++){
				sum += nums[i] ;
				sortsum[i] = sum ;
				indexsum[i] = sum ;
			}
			if(0 == sum){
				begin = 0 ;
				end = len - 1 ;
				ans.push_back(begin);
				ans.push_back(end);
				return ans ;
			}
			sort(sortsum,sortsum+len);
			for(int i = 0 ; i < len-1 ; i++){
				if(sortsum[i] == sortsum[i+1]){
					for(int j = 0 ; j < len ; j++){
						if(indexsum[j] == sortsum[i]){
							if(-1 == begin){
								begin = j+1 ;
							}else{
								find = 1 ;
								end = j ;
								break ;
							}
						}
					}
					if(find){
						break ;
					}
				}
			}
			ans.push_back(begin);
			ans.push_back(end);
			return ans ;
		}
};