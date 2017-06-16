#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
		next_permutation(nums.begin(),nums.end());
		return nums ;
    }
};

void show(const vector<int> vec){
	for(int i = 0 ; i < vec.size() ; ++i){
		cout << vec[i] << " " ;
	}
	cout << endl ;
}

int main(){
	Solution x ;
	int array[] = {4,3,2,1} ;
	int len = sizeof(array) / sizeof(int) ;
	vector<int> test(array , array+len) ;
	show(x.nextPermutation(test)) ;
	return 0 ;
}
