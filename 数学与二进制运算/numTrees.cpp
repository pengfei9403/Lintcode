class Solution {
	public:
		/**
		 * @paramn n: An integer
		 * @return: An integer
		 */
		int numTrees(int n) {
			// write your code here
			unsigned long long data[n+1] ;
			memset(data,0,(n+1)*sizeof(unsigned long long));
			data[0] = 1 ;
			data[1] = 1 ;
			for(int i = 2 ; i <= n ; i++){
				for(int j = 0 ; j < i ; j++){
					data[i] += data[j] * data[i-j-1] ;
				}
			}
			return data[n] ;
		}
};