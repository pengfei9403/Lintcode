class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
	public:
		int search(vector<int> &A, int target) {
			// write your code here
			if(A.empty()){
				return -1 ;
			}
			int left = 0 ;
			int right = A.size()-1 ;
			int mid = (left+right) / 2 ;
			while(left < right){
				if(A[mid] == target){
					return mid ;
				}
				if(A[left] < A[right]){
					if(A[mid] < target){
						left = mid+1 ;
					}else{
						right = mid-1 ;
					}
				}else{
					if(A[left] < A[mid]){
						if(A[mid] > target && target > A[left]){
							right = mid-1 ;     		
						}else{
							left = mid+1 ;      
						}
					}else{
						if(A[mid] < target && target < A[right]){    
							left = mid+1;      
						}else{
							right = mid-1 ;      
						}
					}
				}
				mid = (left+right) / 2 ;
			}
			if(A[mid] == target){
				return mid ;
			}else{
				return -1 ;
			}
		}
};