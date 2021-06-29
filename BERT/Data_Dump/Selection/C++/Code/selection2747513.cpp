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

int selectionSort(int A[],int N){
	int i,j,t,sw=0,minj;
	for(i=0;i<N-1;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(A[j]<A[minj])	minj=j;
		}
		t = A[i];A[i]=A[minj];A[minj]=t;
		if(i!=minj)	sw++;
	}
	return sw;
}

int main(){
	int A[100],N,i,sw;
	
	scanf("%d",&N);
	for(i=0;i<N;i++)	scanf("%d",&A[i]);
	
	sw = selectionSort(A,N);
	
	for(i=0;i<N;i++){
		if(i>0)	printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",sw);

	return 0;
}


