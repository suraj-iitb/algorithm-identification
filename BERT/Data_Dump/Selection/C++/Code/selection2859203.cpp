#include <cstdio>
#include <algorithm>
using namespace std;

void print_A(int A[],int n){
	for (int i = 0 ;i<n;i++) {
		if (i!=n-1 )printf("%d ",A[i]);
		else printf("%d",A[i]);
	}
	printf("\n");
	return ;
}

int selectionsort(int A[],int n ){
	int count = 0;
	for(int i =0;i<n-1;i++){
		int y=i;
		for(int j=i;j<n;j++) if(A[j]<A[y]) y=j;
		if(A[y]<A[i]) {
			swap(A[i],A[y]);
			count++;
		}
	}
	return count;
}

int main (){
	int n,A[110];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int a=selectionsort(A,n);
	print_A(A,n);
	printf("%d\n",a);
	return 0;
}
