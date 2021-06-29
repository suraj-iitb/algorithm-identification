#include<stdio.h>

int main(void){
    int N[100];
    int x;
    int a,t;
    
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d",&N[i]);
    }
	
	printf("%d",N[0]);
    for(int i=1;i<x;i++){
        printf(" %d",N[i]);
    }
	printf("\n");
    
    for(int s=1;s<x;s++){
        a=N[s];
        t=s-1;
        while(t>=0 && N[t]>a){
            N[t+1]=N[t];
            t--;
        }
        N[t+1]=a;
        printf("%d",N[0]);
		for(int i=1;i<x;i++){
    		printf(" %d",N[i]);
    	}
		printf("\n");
    }
    
    return 0;
}
