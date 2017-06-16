#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std ;

int getBitofNum(int n){
	if(0 == n){
		return 1 ;
	}
	int cnt = 0 ;
	while(n){
		++cnt ;
		n /= 10 ;
	}
	return cnt ;
}
int getFirstNum(int n , int len){
	return n / pow(10 , len-1) ;
}

bool comp(int m , int n){
	int x = m ;
	int y = n ;
	int temp_x = x ;
	int temp_y = y ;
	if(x == 0){
		return false ;
	}
	int len_x = getBitofNum(x) ;
	int len_y = getBitofNum(y) ;
	while(len_x && len_y){
		if(getFirstNum(x,len_x) < getFirstNum(y,len_y)){
			return false ;
		}
		if(getFirstNum(x,len_x) > getFirstNum(y,len_y)){
			return true ;
		}
		if(getFirstNum(x,len_x) == getFirstNum(y,len_y)){
			--len_x ;
			--len_y ;
			int temp1 = pow(10,len_x) ;
			int temp2 = pow(10,len_y) ;
			temp_x = x ;
			temp_y = y ;
			x = x % temp1 ;
			y = y % temp2 ;
		}
	}
	if(len_x > 0){
		while(len_x){
			if(getFirstNum(x,len_x) > temp_y){
				return true ;
			}
			if(getFirstNum(x,len_x) < temp_y){
				return false ;
			}
			if(getFirstNum(x,len_x) == temp_y){
				--len_x ;
				int temp = pow(10 , len_x) ;
				x = x % temp ;
			}
		}
		return true ;
	}else{
		while(len_y){
			if(getFirstNum(y,len_y) > temp_x){
				return false ;
			}
			if(getFirstNum(y,len_y) < temp_x){
				return true ;
			}
			if(getFirstNum(y,len_y) == temp_x){
				--len_y ;
				int temp = pow(10,len_y);
				y = y % temp ;
			}
		}
		return false ;
	}
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */


	string itos(int x){
		string ans ;
		int len = getBitofNum(x) ;
		for(int i = 0 ; i < len ; ++i){
			char c = '0' + x%10 ;
			x /= 10 ;
			ans += c ;
		}
		reverse(ans.begin(),ans.end());
		return ans ;
	}
    string largestNumber(vector<int> &num) {
        // write your code here
        string ans ;
        if(num.empty()){
        	return ans ;
		}
        sort(num.begin(),num.end(),comp) ;
        for(int i = 0 ; i < num.size() ; ++i){
        	ans += itos(num[i]) ;
		}
		if('0' == ans[0]){
		    ans = "0" ;
		}
		return ans ;
    }
};

int main(){
	Solution a ;
//	int array[] = {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55} ;
	int array[] = {3,30} ;
	int len = sizeof(array) / sizeof(int) ;
	vector<int> test(array,array+len);
	cout << a.largestNumber(test) << endl ;
	
	
	return 0 ;
}



