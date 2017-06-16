#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        if(1 == A.size()){
        	return true ;
		}
        int tempstep ;
        bool overZero = false ;
        for(int i = 0 ; i < A.size()-1 ; ++i){
        	if(A[i] == 0){
        		tempstep = 1 ;
        		for(int j = i-1 ; j >=0 ; --j){
        			if(A[j] > tempstep){
        				overZero = true ;
        				break ;
					}
					overZero = false ;
					++tempstep ;
				}
				if(!overZero){
					return false ;
				}
			}
		}
		return true ;
    }
};

int main(){
	Solution x ;
	int array[] = {3,2,1,0} ;
	int len = sizeof(array) / sizeof(int) ;
	vector<int> test(array , array+len) ;
	if(x.canJump(test)){
		cout << "can jump" << endl ;
	}else{
		cout << "can't jump " << endl ;
	}
	return 0 ;
}
