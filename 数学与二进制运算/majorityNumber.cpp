#include <iostream>
#include <vector>

using namespace std ;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if(nums.empty()){
        	return 0 ;
		}
        int ans = nums[0] ;
        int cnt = 1 ;
        for(int i = 1 ; i < nums.size() ; ++i){
        	if(ans == nums[i]){
				++cnt ;
			}else{
				--cnt ;
			}
			if(0 == cnt){
				ans = nums[++i] ;
				++cnt ;
			}
		}
		return ans ;
    }
};


int main(){
	int array[] = {2 , 1 , 2 , 1 , 2} ;
	int len = sizeof(array) / sizeof(int) ;
	vector<int> test(array , array + len) ;
	Solution x ;
	cout << x.majorityNumber(test) << endl ;
	return 0 ;
}
