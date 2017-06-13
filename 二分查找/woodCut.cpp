class Solution {
	public:
		/** 
		 *@param L: Given n pieces of wood with length L[i]
		 *@param k: An integer
		 *return: The maximum length of the small pieces.
		 */
		int cut(vector<int>& wood , long long len){
			int cnt = 0 ;
			for(int i = 0 ; i < wood.size() ; i++){
				cnt += wood[i] / len ;
			}
			return cnt ;
		}
		int woodCut(vector<int> L, int k) {
			// write your code here
			long long max = 0 ;
			for(int i = 0 ; i < L.size() ; i++){
				if(L[i] > max){
					max = L[i] ;
				}
			}
			long long left = 0 ;
			long long right = max ;
			long long mid = (left+right) / 2 ;
			int cnt = 0 ;
			while(left < right){
				cnt = cut(L,mid) ;
				if(cnt < k){
					right = mid-1 ;
				}else{
					left = mid+1 ;
				}
				mid = (left+right) / 2 ;
			}
			if(0 == mid){
				return 0 ;
			}
			if(cut(L,mid) >= k){
				return mid ;
			}else{
				return mid-1 ;
			}
		}
    
};