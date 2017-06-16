#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        if(A.empty()){
        	return 0 ;
		}
        int ans = A[0] ;
        for(int i = 1 ; i < A.size() ; ++i){
        	ans ^= A[i] ;
		}
		return ans ;
    }
};


int main(){
	int array[] = {1 , 1 , 2 , 2 , 3 , 4 , 4} ;
	int len = sizeof(array) / sizeof(int) ;
	vector<int> test(array , array + len) ;
	Solution x ;
	cout << x.singleNumber(test) << endl ;

	return 0 ;
}
