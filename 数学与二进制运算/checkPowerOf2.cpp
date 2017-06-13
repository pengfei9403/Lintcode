class Solution {
	public:
		/*
		 * @param n: An integer
		 * @return: True or false
		 */
		bool checkPowerOf2(int n) {
			// write your code here
			if(0 >= n){
				return false ;
			}
			if(n & (n-1)){
				return false ;
			}else{
				return true ;
			}
		}
};