class Solution {
	public:
		/**
		 * @param A: sorted integer array A which has m elements, 
		 *           but size of A is m+n
		 * @param B: sorted integer array B which has n elements
		 * @return: void
		 */
		void mergeSortedArray(int A[], int m, int B[], int n) {
			// write your code here
			int index = m+n-1 ;
			n--;m--;
			while(m >= 0 && n >= 0){
				if(A[m] > B[n]){
					A[index] = A[m] ;
					index--;
					m--;
				}else{
					A[index] = B[n];
					index--;
					n--;
				}
			}
			if(n >= 0){
				while(n >= 0){
					A[index] = B[n] ;
					index-- ;
					n-- ;
				}
			}
		}
};