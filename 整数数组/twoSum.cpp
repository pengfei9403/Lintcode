class Solution {
	public:
		/*
		 * @param numbers : An array of Integer
		 * @param target : target = numbers[index1] + numbers[index2]
		 * @return : [index1+1, index2+1] (index1 < index2)
		 */
		vector<int> twoSum(vector<int> &nums, int target) {
			// write your code here
			int value ;
			int first , second ;
			int len = nums.size() ;
			vector<int> ans ;
			vector<int>::iterator begin = nums.begin() ;
			vector<int>::iterator point ;
			for(int i = 0 ; i < len ; i++){
				value = target - nums[i] ;
				point = find(begin+i+1,nums.end(),value);
				if( point != nums.end()){
					first = i+1 ;
					second = point - begin + 1 ;
					break ;
				}
			}
			ans.push_back(first);
			ans.push_back(second);
			return ans ;
		}
};
