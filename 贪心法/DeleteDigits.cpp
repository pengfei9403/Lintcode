#include <iostream>
#include <string>
#include <cstring>

using namespace std ;

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
	string del(string& str , int pos , int len){
		string ans ;
		for(int i = pos ; i < len ; ++i){
			str[i] = str[i+1] ;
		}
		ans = str.substr(0,len);
		return ans ;
	}
    string DeleteDigits(string A, int k) {
        // wirte your code here
		string ans ;
        int len = A.size() - k ;
        if(0 == len){
			return ans ;
		}
		ans = A.substr(0,len) ;
		for(int i = len ; i < A.size() ; ++i){
			ans += A[i] ;
			for(int i = 0 ; i <= len ; ++i){
				if(ans[i] > ans[i+1]){
					ans = del(ans , i , len) ;
					break ;
				}
			}
			ans = del(ans , len , len) ;
		}
		for(int i = 0 ; i < ans.size() ; ++i){
			if('0' != ans[i]){
				return ans.substr(i,len) ;
			}
		}
		return "0" ;
    }
};


int main(){
	string str = "90249" ;
	int k = 2 ;
	Solution x ;
	cout << x.DeleteDigits(str,k) << endl ;
	return 0 ;
}
