#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include<unordered_map>
#include <cmath>
#include <set>
using namespace std;


/**
 * @param s: The first string
 * @param b: The second string
 * @return true or false
 */
bool anagram(string s, string t) {
    // write your code here
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s == t){
        return true;
    }else{
        return false;
    }
}

/**
 * @param A: A string includes Upper Case letters
 * @param B: A string includes Upper Case letter
 * @return:  if string A contains all of the characters in B return true
 *           else return false
 */
bool compareStrings(string A, string B) {
    // write your code here
    int flag = 0 ;
    int i = 0 , j = 0 ;
    if(0 == B.size()){
        return true ;
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(; j < B.size() && i < A.size() ;){
        if(A[i] != B[j]){
            flag = 0 ;
            i++ ;
        }else{
            flag = 1 ;
            i++ ;
            j++ ;
        }
    }
    if(flag && j == B.size()){
        return true ;
    }else{
        return false ;
    }
}

/**
 * Returns a index to the first occurrence of target in source,
 * or -1  if target is not part of source.
 * @param source string to be scanned.
 * @param target string containing the sequence of characters to match.
 */
int strStr(const char *source, const char *target) {
    // write your code here
    int pos = -1 ;

    if(!source || !target){
        return -1;
    }
    // char *c = strstr(source , target);
    // if(strlen(source) < strlen(target)){
    //     return -1;
    // }
    if(strstr(source , target)){
        pos = strstr(source , target) - source ;
    }

    if(pos != -1){
        return pos ;
    }
    return -1;
}

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


/**
 * @param A, B: Two string.
 * @return: the length of the longest common substring.
 */
int longestCommonSubstring(string &A, string &B) {
    // write your code here
    int first = 1 ;
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
	int min = strs[0].size() ;
	string ans ;
	for(int i = 0 ; i < len ; i++){
		if(strs[i].size() < min){
			min = strs[i].size();
		}
	}
//	sort(strs.begin(),strs.end(),sortfunc);
	for(j = 0 ; j < min ; j++){
		for(int i = 0 ; i < strs.size() ; i++){
//			cout << "i=" << i << endl ;
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


