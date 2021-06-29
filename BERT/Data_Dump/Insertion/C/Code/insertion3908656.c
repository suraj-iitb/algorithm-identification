#include <stdio.h>

int main(void){
	
	int i,j,t,n,w[100],cp;
	
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		scanf("%d",&w[i]);
	}
	
	for(t=0; t<n; t++){
		cp = w[t];             
        for (j = t; j > 0 && w[j-1] > cp; j--){
            w[j] = w[j -1];
        }
        w[j] = cp;
		
		for(i=0; i<n; i++){
		
		printf("%d",w[i]);
			
			if(i != n-1){
				printf(" ");
			}
		}
		
		printf("\n");
		
		
	}
	
	return 0;
}

