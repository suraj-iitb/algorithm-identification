#include<stdio.h>

int main (void){
	
	int left,right,mid,A[100000];
	int key = 100;
	int n,counter=0;
	int i;
	int q,B[50000];
	//n?????\???
	//s[0],...,s[n-1]?????§?????\???
	
	scanf("%d",&n);
	
	for(i=0;i<n;++i){
		scanf("%d",&A[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;++i){
		scanf("%d",&B[i]);
	}
		
	for(i=0;i<q;++i){		
		left = 0;
		right = n;
		while (left < right){
			mid = ( left + right ) / 2;
		
			if (A[mid] == B[i]){
				counter=counter+1;
				break;
			}else if(B[i] < A[mid]){
				right = mid;
			}else{
				left = mid +1;
			}
		}
		
	}
		
	printf("%d\n",counter);
	return 0;
}
