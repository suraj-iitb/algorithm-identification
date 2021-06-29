#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int SelectSort(int A[],int N){
	int cout=0;
	int minj;
	for(int i=0;i<N-1;i++){
		minj=i;
		for(int j=i;j<N;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		swap(A[i],A[minj]);
		if(i!=minj)cout++;
	}
return cout;
}

int main(){
	int A[100],N,cout;
	scanf("%d",&N);
	for(int t=0;t<N;t++){
		scanf("%d",&A[t]);
	}
	cout=SelectSort(A,N);

	for(int t=0;t<N;t++){
		if(t)printf(" ");
		printf("%d",A[t]);
	}
	printf("\n");
	printf("%d\n",cout);

return 0;
}
