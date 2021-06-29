#include <cstdio>
#include <algorithm>
using namespace std;

void selectionSort(int A[],int N){
	int cnt=0;
	for(int i=0;i<N;++i){
		int minv=A[i];
		int p=i;
		for(int j=i+1;j<N;++j){
			if(minv>A[j]){
				minv=A[j];
				p=j;
			}
		}
		if(p!=i){
			swap(A[i],A[p]);
			cnt++;
		}
	}
	for(int i=0;i<N;++i) {
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
	selectionSort(A,N);
}

