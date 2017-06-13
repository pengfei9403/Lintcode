class Solution {
	public:
		/**
		 *@param n: Given a decimal number that is passed in as a string
		 *@return: A string
		 */
		string reverse(string& str){
			string ans ;
			int len = str.size() ;
			for(int i = 0 ; i < len ; i++){
				ans += str[len-i-1] ;
			}
			return ans ;
		}
		
		string itobs(long long n){
			string ans ;
			while( n != 0){
				ans += to_string(n%2) ;
				n /= 2 ;
			}
			return reverse(ans) ;
		}
		
		string dtobs(long long m , long long n){
			string ans ;
			int cnt = 0 ;
			while(n != 0 && cnt <= 33){
				n *= 2 ;
				ans += to_string(n / m) ;
				if(n >= m){
					n -= m ;
				}
				cnt ++ ;
			}
			if(cnt > 32){
				ans = "ERROR" ;
			}
			return ans ;
		}
		
		long long stol(string& str){
			long long ans = 0 ;
			for(int i = 0 ; i < str.size() ; i++){
				ans *= 10 ;
				ans += str[i] - '0' ;
			}
			return ans ;
		}
		string binaryRepresentation(string n) {
			// wirte your code here
			if(n == "0"){
				return "0" ;
			}
			string ans ;
			string error = "ERROR" ;
			int positive = 1 ;
			if(n[0] == '-'){
				ans = "-" ;
				positive = 0 ;
			}
			string before ;
			string after ;
			int len = n.size() ;
			int pointIndex = 0 ;
			for(int i = 0 ; i < len ; i++){
				if(n[i] == '.'){
					pointIndex = i ;
					break ;
				}
			}
			if(!pointIndex){
				if(positive){
					before = n.substr(0,n.size());
				}else{
					before = n.substr(1,n.size());
				}
				before = itobs(stol(before));
				ans = ans + before ;
				return ans ;
			}
			if(positive){
				before = n.substr(0,pointIndex);
			}else{
				before = n.substr(1,pointIndex-1);
			}
			after = n.substr(pointIndex+1,n.size());
			long long m = pow(10,after.size()) ;
			after = dtobs(m,stol(after)) ;
			if(after == "ERROR"){
				return "ERROR" ;
			}
			before = itobs(stol(before));
			if(before.empty()){
				before = "0" ;
			}
			if(after.empty()){
				ans = ans + before ;
			}else{
				ans = ans + before + '.' + after ;
			}
			return ans ;
		}
};
