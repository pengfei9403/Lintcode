class Solution {
	public:
		/**
		 *@param n, m: Two integer
		 *@param i, j: Two bit positions
		 *return: An integer
		 */
		int updateBits(int n, int m, int i, int j) {
			// write your code here
			long long temp = pow(2,j-i+1)-1;
			temp = temp << i ;
			temp = ~temp ;
			n = temp & n ;
			m  = m << i ;
			n = m | n ;
			return n ;
		}
};