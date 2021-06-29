#include<stdio.h>
#include<stdlib.h>

#define SIZE 100000

int array[SIZE];

int binary_search(int b,int from,int to){
	int now=(from+to)/2;
	int a=array[now];
	if(from>to){return 0;}
	
	if(a==b){
		return 1;
	}
	else if(a>b){
		return binary_search(b,from,now-1);
	}
	else if(a<b){
		return binary_search(b,now+1,to);
	}else{
		printf("error\n");
		exit(1);
	}
}

int main(void){
    int num,count=0;
    int b;
	
    scanf("%d",&num);
	
    for(int i=0;i<num;i++){
        scanf("%d",&array[i]);
    }
    
	int tmp;
    scanf("%d",&tmp);
    
    for(int i=0;;i++){
    	if(scanf("%d",&b)==EOF)break;
    	if(binary_search(b,0,num-1))count++;
    }
    
    printf("%d\n",count);
	return 0;
}
