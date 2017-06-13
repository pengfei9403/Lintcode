class Solution {
	public:
		/**
		 * @param nums: The integer array.
		 * @param target: Target number to find.
		 * @return: The first position of target. Position starts from 0. 
		 */
		int binarySearch(vector<int> &array, int target) {
			// write your code here
			int left = 0 ;
			int right = array.size() ;
			int mid = (left+right) / 2 ;
			while(left < right){
				if(array[mid] == target){
					break ;
				}else{
					if(array[mid] < target){
						left = mid+1 ;
					}else{
						right = mid-1 ;
					}
					mid = (left+right) / 2 ;
				}
			}
			if(array[mid] == target){
				while(array[mid] == target){
					mid-- ;
				}
				return mid+1 ;
			}
			return -1;
		}
};