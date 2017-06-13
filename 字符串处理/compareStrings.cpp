#include <algorithm>
#include <string>

using namespace std;

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
