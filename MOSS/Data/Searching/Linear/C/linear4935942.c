#include<stdio.h>


int linearSearch(int A[], int n, int key){
	
	int i=0;
	A[n]=key;
	while(A[i]!=key){
		i++;
	}
    
	return i;
}

int main(void){
	
	int n,q,count=0;
	
	scanf("%d",&n);
    
    int S[n];
    for(int i=0; i<n; i++){
        scanf("%d",&S[i]);
    	
    }
	
    scanf("%d",&q);
    int T[q];
    for(int j=0; j<q; j++){
        scanf("%d",&T[j]);
        int c=linearSearch(S, n, T[j]);
    	if(c<n){
    		count++;
    	}
    }
    printf("%d\n",count);
	return 0;
}
