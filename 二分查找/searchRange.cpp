class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
	public:
		vector<int> searchRange(vector<int> &A, int target) {
			// write your code here
			vector<int> ans ;
			int start = -1;
			int end = -1;
			if(A.empty()){
				ans.push_back(start);
				ans.push_back(end);
				return ans ;
			}
			int left = 0 ;
			int right = A.size()-1 ;
			int mid = (left+right) / 2 ;
			while(left < right){
				if(A[mid] == target){
					break;
				}
				if(A[mid] < target){
					left = mid+1 ;
				}else{
					right = mid-1 ;
				}
				mid = (left+right) / 2 ;
			}
			if(A[mid] == target){
				while(A[mid] == target){
					mid--;
				}
				mid++ ;
				start = mid ;
				while(A[mid] == target){
					mid++ ;
				}
				mid-- ;
				end = mid ;
			}
			ans.push_back(start);
			ans.push_back(end);
			return ans;
		}
};