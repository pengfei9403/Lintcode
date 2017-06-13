#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
	    /**
	     * @param strs: A list of strings
	     * @return: A list of strings
	     */
	    bool anagram(string s, string t) {
	        // write your code here
	        if(0 == t.size()){
	        	return true ;
			}
	        if(s == t){
	            return true;
	        }else{
	            return false;
	        }
	    }
	    vector<string> anagrams(vector<string> &strs) {
	        // write your code here
	        int flag = 0 ;
	        vector<int> arr(strs.size()) ;
	        vector<string> temp(strs) ;
	        vector<string> ans ;
	        vector<string>::iterator str=strs.begin();
	        int temp_size = temp.size();
	        for(int i = 0 ; i < temp_size ; i++){
	        	sort(temp[i].begin(),temp[i].end());
			}
			if(0 == temp_size){
				return ans;
			}else if(1 == temp_size){
				return temp;
			}
	       	vector<string> temp2(temp);
			sort(temp2.begin(),temp2.end());
			for(int i = 0 ; i < temp_size-1 ; i++){
				if(temp2[i] == temp2[i+1]){
					flag = 1 ;
				}else{
					if(flag){
						flag = 0 ;
						for(int j = 0 ; j < temp_size ; j++){
							if(temp2[i] == temp[j]){
								ans.push_back(strs[j]);
							}
						}
					}
				}
			}
			if(flag){
				flag = 0 ;
				for(int j = 0 ; j < temp_size ; j++){
					if(temp2[temp_size-1] == temp[j]){
						ans.push_back(strs[j]);
					}
				}
			}
			return ans ;
	    }
};

