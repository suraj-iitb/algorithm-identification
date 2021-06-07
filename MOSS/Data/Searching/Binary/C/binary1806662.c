#include<stdio.h>
int main(){
	int n,q;
	int A[100000],T[50000];
    int i,count=0;
	int left,right,mid;

	scanf("%d",&n);

	for(i=0 ; i<n ; i++){
		scanf("%d",&A[i]);
	}

	scanf("%d",&q);

	for(i=0 ; i<q ; i++){
		scanf("%d",&T[i]);
	}

	for(i=0 ; i<q ; i++){
		right = n;
		left = 0;
	while(left < right){
	mid = (left + right)/2;
	if(T[i] == A[mid]){
		count++;
		break;
	}

	else if(T[i] > A[mid])left = mid+1;
	else right = mid;
		     }
  
					
		}

	printf("%d\n",count);

	return 0;
	}
