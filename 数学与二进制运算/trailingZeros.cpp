class Solution {
	public:
		// param n : description of n
		// return: description of return 
		long long trailingZeros(long long n) {
			long long cnt = 0 ;
			long long powerOfFive = 5 ;
			while(n / powerOfFive > 0){
				cnt += (n/powerOfFive) ;
				powerOfFive *= 5 ;
			}
			return cnt ;        
		}
};
