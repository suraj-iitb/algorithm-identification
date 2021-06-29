#include<stdio.h>

int main(void){
    int N[100];
    int x,flag,t,c=0;
    
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d",&N[i]);
    }
	
	flag=1;
	while(flag==1){
		flag=0;
		for(int j=x-1;j>0;j--){
			if(N[j] < N[j-1]){
				t=N[j];
				N[j]=N[j-1];
				N[j-1]=t;
				c++;
				flag=1;
			}
		}
	}
	
	printf("%d",N[0]);
    for(int i=1;i<x;i++){
        printf(" %d",N[i]);
    }
	printf("\n");
	printf("%d\n",c);
	
    return 0;
}

