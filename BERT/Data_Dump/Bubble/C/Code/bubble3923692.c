#include<stdio.h>

int main(void){
	
	int n,w[100],i,j,t,count,cp;
	count=0;
	t=0;
	
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		scanf("%d",&w[i]);
	}
	for(j=0; j<n; j++){
		for(i=n-1; i>=1; i--){
			
			if(w[i] < w[i-1]){
				cp = w[i-1];
				w[i-1] = w[i];
				w[i] = cp;
				
				count++;
		    }
		}
	}
	
	for(i=0; i<n; i++){
		printf("%d",w[i]);
		if(i != n-1){
			printf(" ");
		}
		
		
	}
	printf("\n");
	printf("%d\n",count);
	
	return 0;
}

	
