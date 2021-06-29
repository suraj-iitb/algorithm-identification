#include <stdio.h>
int main(){
 	int i,j,k;
 	int len;
 	int key;
 	
 	scanf("%d",&len);
 	int A[len];
 	
 	for(i=0;i<len;i++)
 		scanf("%d",&A[i]);
 		
 	for(i=0;i<len;i++){
 	    printf("%d",A[i]);
 	    if(i!=len-1) printf(" ");
 	}
 	printf("\n");

 	for(i=1;i<len;i++){
 		key = A[i];
 		j = i-1;
 		while (j>=0 && A[j]>key){
 			A[j+1] = A[j];
 			j--;
		}
		A[j+1] = key; 
		
		for(k=0;k<len;k++){
			printf("%d",A[k]);
			if(k!=len-1) printf(" ");
		}
		//if(i!=len)	
		printf("\n");
	}
	
	return 0;
}
 	
 
 
