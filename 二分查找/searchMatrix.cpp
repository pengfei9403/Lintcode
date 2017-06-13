class Solution {
	public:
		/**
		 * @param matrix, a list of lists of integers
		 * @param target, an integer
		 * @return a boolean, indicate whether matrix contains target
		 */
		bool searchMatrix(vector<vector<int> > &matrix, int target) {
			// write your code here
			if(matrix.empty()){
				return false ;
			}
			int left , right , mid ;
			int line ;
			int xlen = matrix[0].size() ;
			int ylen = matrix.size() ;
			left = 0 ;
			right = ylen-1 ;
			mid = (left+right) / 2 ;
			while(left < right){
				if(matrix[mid][0] == target){
					return true ;
				}else{
					if(matrix[mid][0] < target){
						left = mid+1 ;
					}else{
						right = mid-1 ;
					}
					mid = (left+right) / 2 ;
				}
			}
			if(matrix[mid][0] < target){
				line = mid ;
			}else{
				line = mid-1 ;
			}
			if(line < 0){
				return false ;
			}
			left = 0 ;
			right = xlen-1 ;
			mid = (left+right) / 2 ;
			while(left < right){
				if(matrix[line][mid] == target){
					return true ;
				}else{
					if(matrix[line][mid] < target){
						left = mid+1 ;
					}else{
						right = mid-1 ;
					}
					mid = (left+right) / 2 ;
				}
			}
			if(matrix[line][mid] == target){
				return true ;
			}else{
				return false ;
			}
		}
};
