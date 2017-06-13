class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
	public:
		int searchInsert(vector<int> &A, int target) {
			// write your code here
			if(A.empty()){
				return 0 ;
			}
			int len = A.size() ;
			int left = 0 ;
			int right = len-1 ;
			int mid = (left+right) / 2 ;
			while(left < right){
				if(A[mid] == target){
					return mid;
				}else{
					if(A[mid] < target){
						left = mid+1 ;
					}else{
						right = mid-1 ;
					}
					mid = (left+right) / 2 ;
				}
			}
			if(A[mid] >= target){
				return mid ;
			}else{
				return mid+1 ;
			}
		}
};