#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
	    /**
	     * @param strs: A list of strings
	     * @return: The longest common prefix
	     */

	    bool sortfunc(const string& a , const string& b){
		    return a.size() - b.size() ;
	    }
	    string longestCommonPrefix(vector<string> &strs) {
	        // write your code here
	        int len = strs.size();
	        int j = 0 ;
	    	int flag = 1 ;
	    	string ans ;
	    	if(0 == strs.size()){
	    	    return ans;
	    	}
	    	int min = strs[0].size() ;
	    	for(int i = 0 ; i < len ; i++){
	    		if(strs[i].size() < min){
	    			min = strs[i].size();
	    		}
	    	}
	    	for(j = 0 ; j < min ; j++){
	    		for(int i = 0 ; i < strs.size() ; i++){
	    			if(strs[0][j] != strs[i][j]){
	    				flag = 0 ;
	    				break ;
	    			}
	    		}
	    		if(flag){
	    			ans += strs[0][j] ;
	    		}else{
	    			break;
	    		}
	    	}
	    	return ans ;
	    }
};
