#include <algorithm>
#include <string>

using namespace std ;

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
