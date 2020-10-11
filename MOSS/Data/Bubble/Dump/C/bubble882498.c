#include<stdio.h>
#include<stdlib.h>

int swap(int *,int time);
int main(void){
	int i,count=0,time,*num;
	
	scanf("%d",&time);
	num=malloc(sizeof(int)*time);
	for(i=0;i<time;i++)
		scanf("%d",&num[i]);
	if(time!=1)
		count=swap(num,time);
	for(i=0;i<time;i++){
		printf("%d",num[i]);
		if(i!=time-1)
			printf(" ");
	}
	printf("\n%d\n",count);
	return 0;
}

int swap(int *num,int time){
	int temp,i,j,count=0;
	for(i=time;i>0;i--)
		for(j=0;j<i-1;j++)
			if(*(num+j)>*(num+j+1)){
				temp=*(num+j);
				*(num+j)=*(num+j+1);
				*(num+j+1)=temp;
				count++;
			}
	return count;
}
