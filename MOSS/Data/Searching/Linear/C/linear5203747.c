#include <stdio.h>

int cnt = 0;

int search(int* A, int n, int key){
	int i;
	i=0;
	A[n]=key;
	while(A[i]!=key)i++;
	return i!=n;
}



int main(){
	int A[100011], B[100011], a, b;
	int i, j;
	
	scanf("%d", &a);
	for(i=0;i<a;i++){
		scanf("%d", &A[i]);
	}
	
	scanf("%d", &b);
	for(j=0;j<b;j++){
		scanf("%d", &B[j]);
	}
	
	for(j=0;j<b;j++){
		if(search(A, a, B[j])) cnt++;
	}
	
	printf("%d\n", cnt);
	return 0;
}

