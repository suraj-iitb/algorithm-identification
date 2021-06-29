#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;

int bubbleSort(int A[],int N){
	int sw =0;
	bool flag = 1;
	for(int i=0;flag;i++){
		flag =0;
		for(int j=N-1;j>=i+1;j--){
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}

int main(){
	int A[100],N,sw;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	sw = bubbleSort(A,N);
	
	for(int i=0;i<N;i++){
		if(i) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",sw);
	
	return 0;
}


