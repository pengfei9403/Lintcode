class Solution {
	public:
		/**
		 * @param A: An integers array.
		 * @return: return any of peek positions.
		 */
		int findPeak(vector<int> A) {
			// write your code here
			int left = 0 ;
			int right = A.size()-1 ;
			int mid = (left+right) / 2 ;
			while(left < right){
				if(A[mid-1] < A[mid] && A[mid+1] < A[mid]){
					return mid ;
				}
				if(A[mid-1] > A[mid]){
					right = mid ;
				}else{
					left = mid+1 ;
				}
				mid = (left+right) / 2 ;
			}
		}
};
