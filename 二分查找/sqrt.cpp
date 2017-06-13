class Solution {
	public:
		/**
		 * @param x: An integer
		 * @return: The sqrt of x
		 */
		int sqrt(int x) {
			// write your code here
			long long left = 0 ;
			long long right = x ;
			long long mid = (left+right) / 2 ;
			while(left < right){
				if(mid*mid == x){
					return mid ;
				}else{
					if(mid*mid < x){
						left = mid+1 ;
					}else{
						right = mid-1 ;
					}
					mid = (left+right) / 2 ;
				}
			}
			if(mid * mid > x){
				return mid-1 ;
			}else{
				return mid ;
			}
		}
};