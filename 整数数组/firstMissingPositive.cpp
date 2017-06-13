class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    // void swap(int& x , int& y){
    // 	int temp ;
    // 	temp = x ;
    // 	x = y ;
    // 	y = x ;
    // }
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int len = A.size();
        for(int i = 0 ; i < len ; ){
        	if(A[i] == i+1){
        		i++ ;
    		}else{
    			if(A[i]>0 && A[i] <= len && A[i] != A[A[i]-1]){
    				swap(A[i],A[A[i]-1]) ;
    			}else{
    				i++;
    			}
    		}
    	}
    	for(int i = 0 ; i < len ; i++){
    		if(A[i] != i+1){
    			return i+1 ;
    		}
    	}
    	return len+1 ;
    }
};