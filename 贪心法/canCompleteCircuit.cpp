#include <iostream>
#include <vector>

using namespace std ;

void show(vector<int>& temp){
	for(int i = 0 ; i < temp.size() ; ++i){
		cout << temp[i] << " " ;
	}
	cout << endl ;
}

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        if(gas.empty()){
        	return -1 ;
		}
		int start = -1 ;
		int maxleft = 0 ;
		int left = 0 ;
		int num = gas.size() ;
		int ans = 0 ;
        for(int i = 0 ; i < num ; ++i){
        	gas[i] = gas[i] - cost[i] ;
		}
//		cout << "every station left data :" << endl ;
//		show(gas) ;
		for(int i = 0 ; i < 2*num ; ++i){
			left += gas[i%num] ;
			if(left >= 0){
				cost[i%num] = left ;
			}else{
				left = 0 ;
				cost[i%num] = 0 ;
			}
		}
//		cout << "biggest positive data :" << endl ;
//		show(cost) ;
		for(int i = 0 ; i < num ; ++i){
			if(maxleft < cost[i]){
				maxleft = cost[i] ;
				start = i ;
			}
		}
		for(int i = start ; cost[i] ; ){
			ans = i ;
			--i ;
			if(i < 0){
				i += num ;
			}
			if( i == start){
				ans = start ;
				break ;
			}
		}
//		cout << "ans is : " << ans << endl ;
//		cout << "left of every station : " << endl ;
		left = 0 ;
		for(int i = 0 ; i < num ; ++i){
			left += gas[(i+ans)%num] ;
			cout << left << " " ;
			if(left < 0){
				return -1 ;
			}
		}
		return ans ;
    }
};

int main(){
	int gas[] = {0, 2 , 0 , 100} ;
	int cost[] = {20,1,20,0} ;
	int len1 = sizeof(gas) / sizeof(int) ;
	int len2 = sizeof(cost) / sizeof(int) ;
	vector<int> test(gas , gas + len1) ;
	vector<int> test2(cost,cost+len2) ;
	cout << "gas data :" << endl ;
	show(test) ;
	cout << "cost data :" << endl ;
	show(test2) ;
	Solution x ;
	cout << x.canCompleteCircuit(test,test2) <<endl ;
	return 0 ;
}
