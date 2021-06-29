
#include<stdio.h>
#define MAX 101

int main(){
int n,i,j,k,key;
int A[MAX];

scanf("%d",&n);

for( i = 0 ; i < n ; i++ ){
scanf("%d",&A[i]);
} 

for( i = 0 ; i < n ; i++ ){
key = A[i];

j = i - 1;

while( j >= 0 && key < A[j]){
A[j+1] = A[j];
j--;
}
A[j+1] = key;

for( k = 0 ; k < n - 1 ; k++ ) printf("%d ",A[k]);
	printf("%d\n",A[k]);
}

	return 0;
}
