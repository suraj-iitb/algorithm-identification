#include<stdio.h>
int main(void){
    int a=0,b = 0,c = 0,i = 0,j = 0;
	scanf("%d",&a);
	int n[a];
	for(i = 0;i < a;i++){
		scanf("%d",&n[i]);
	}
	for(c = 0;c <a;c++){
		if(c == a-1){
			printf("%d\n",n[c]);
		}
		else{
			printf("%d ",n[c]);
		}
		}
	
	for(i = 1;i < a;i++){
		b = n[i];
		j = i-1;
		while(j >=0 && n[j] > b){
			n[j+1] = n[j];
			j--;
		}
		n[j+1] = b;
		for(c = 0;c <a;c++){
			if(c == a-1){
			printf("%d\n",n[c]);
		}
		else{
			printf("%d ",n[c]);
		}
		}
		
	}
    
    
}
