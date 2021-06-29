#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std ;
#define endl '\n' 

struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
unordered_map<pair<int,int>,int,HASH>mp;
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

int cnt ;
void selectionSort(int n , int ara[]) 
{
	for(int i = 0 ; i < n ; i++){
		int min = i ;  
		for(int j = i ; j < n ; j++){ 
			if(ara[j] < ara[min]){
				min = j ;
			}
		}
		swap(ara[i] , ara[min]) ;
		if(i == min) cnt-- ;
		cnt++ ;
	}
}

int main(){
	int n , ara[105] ; 
	scanf("%d" ,&n) ;
	for(int i = 0 ; i < n ; i++){ 
		scanf("%d" ,&ara[i]) ;
	}
	
	selectionSort(n , ara) ;
	
	for(int i = 0 ; i < n ; i++){
		if(i > 0) printf(" ") ;
		printf("%d" ,ara[i]) ;
	}
	printf("\n") ;
	printf("%d\n",cnt) ;
	return 0 ;
}

