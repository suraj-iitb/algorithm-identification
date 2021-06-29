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

void trace(int A[],int N){
	int i;
	for(int i=0;i<N;i++){
		if(i>0)	printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
}

void insertionSort(int A[],int N){
	int j,i,v;
	for(i=1;i<N;i++){
		v=A[i];
		j=i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		trace(A,N);
	}
}

int main(){
	int N,i,j;
	int A[100];
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	trace(A,N);
	insertionSort(A,N);
	
	return 0;
}


