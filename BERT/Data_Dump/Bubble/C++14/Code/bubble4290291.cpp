#include <cstdio>
#include <algorithm>
using namespace std;

void bubbleSort(int A[],int N){
	bool flag=false;
	int cnt=0;
	do{
		flag=false;
		for(int i=0;i<N-1;++i){
			if(A[i]>A[i+1]){
				swap(A[i],A[i+1]);
				cnt++;
				flag=true;
			}
		}
	} while(flag);
	for(int i=0;i<N;++i){
		if(i==0) printf("%d",A[i]);
		else printf(" %d",A[i]);
	}
	puts("");
	printf("%d\n",cnt);
}

int main(){
	int N;scanf("%d",&N);
	int A[100];
	for(int i=0;i<N;++i) scanf("%d",&A[i]);
	bubbleSort(A,N);
}

