#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
	    /**
	     * @param A, B: Two string.
	     * @return: the length of the longest common substring.
	     */
	    int longestCommonSubstring(string &A, string &B) {
	        // write your code here
	        int max = 0 ;
	    	int len = B.size();
	    	int arrbefore[len], arr[len] ;
	    	for(int i = 0 ; i < len ; i++){
	    		arr[i] = 0 ;
	    		arrbefore[i] = 0 ;
	    	}
	    	for(int i = 0 ; i < A.size() ; i++){
	    		if(A[i] == B[0]){
	    			arr[0] = 1 ;
	    			if(max < 1){
	    				max = 1 ;
	    			}
	    		}else{
	    			arr[0] = 0 ;
	    		}
	    		for(int j = 1 ; j < B.size() ; j++){
	    			if(A[i] == B[j]){
	    				arr[j] = 1 + arrbefore[j-1];
	    				if(max < arr[j]){
	    					max = arr[j];
	    				}
	    			}else{
	    				arr[j] = 0 ;
	    			}
	    		}
	    		for(int j = 0 ; j < B.size() ; j++){
	    			arrbefore[j] = arr[j] ;
	    		}
	    	}
	    	return max ;
	    }
};

