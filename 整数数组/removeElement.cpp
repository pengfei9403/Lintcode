class Solution {
	public:
		/** 
		 *@param A: A list of integers
		 *@param elem: An integer
		 *@return: The new length after remove
		 */
		int removeElement(vector<int> &A, int elem) {
			// write your code here
			int ans = A.size() ;
			vector<int>::iterator remove = A.begin() ;
			for(int i = 0 ; i < A.size() ; i++){
				if(A[i] == elem){
					A.erase(remove + i);
					i-- ;
				}
			}
			ans = A.size() ;
			return ans ;
		}
};