#include <algorithm>
#include <string>

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
