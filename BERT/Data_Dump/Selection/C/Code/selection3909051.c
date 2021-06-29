#include<stdio.h>

int main(void){
    int A[100];
    int x,minj,tmp,c=0;
    
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d",&A[i]);
    }
	
	for(int i=0;i<x;i++){
		minj=i;
		for(int j=i;j<x;j++){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		if(i!=minj){
			tmp=A[i];
			A[i]=A[minj];
			A[minj]=tmp;
			c++;
		}
	}
	
	printf("%d",A[0]);
    for(int i=1;i<x;i++){
        printf(" %d",A[i]);
    }
	printf("\n");
	printf("%d\n",c);
	
    return 0;
}

