#include<stdio.h>

#define SIZE 10000

int main(void){
    int num,count=0;
    int a[SIZE];
    int b[SIZE];
    
    scanf("%d",&num);
    
    for(int i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    
	int tmp;
    scanf("%d",&tmp);
    
    for(int i=0;i<SIZE;i++){
    	if(scanf("%d",&b[i])==EOF)break;
        
        for(int j=0;j<num;j++){
            if(a[j]==b[i]){
                count++;
                break;
            }
        }
    }
    
    printf("%d\n",count);
}
