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

int bubblesort(int A[],int n){
	int count=0;
	for (int i =0 ;i<n;i++){
		for(int j=n-1;j>=i+1;j--){
			if(A[j-1]>A[j]) {swap(A[j-1], A[j]);count++;} 
		}
	}
	return count;
}

int main (){
	int n,A[110];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int a = bubblesort(A,n);
	print_A(A,n);
	printf("%d\n",a);
	return 0;
}
