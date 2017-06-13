class Solution {
	public:
		/**
		 *@param a, b: Two integer
		 *return: An integer
		 */
		int bitSwapRequired(int a, int b) {
			// write your code here
			int temp = a ^ b ;
			int flag = 1 ;
			int cnt = 0 ;
			for(int i = 0 ; i < 32 ; i++){
				if((temp & flag) != 0){
					cnt++ ;
				}
				flag = flag << 1 ;
			}
			return cnt ;
		}
};