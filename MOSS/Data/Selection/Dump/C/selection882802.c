#include<stdio.h>/*selection sort(選択ソート)*/
#include<stdlib.h>

int sort(int *,int);
void swap(int *,int,int);
void print(int *,int,int);

int main(void){
	int i,time,*num,count;

	scanf("%d",&time);
	
	num=malloc(sizeof(int)*time);
	
	for(i=0;i<time;i++){
		scanf("%d",num+i);
	}
	count=sort(num,time);
	print(num,count,time);
	
	return 0;
}

int sort(int *num,int time){
	int i,j,min,keep,count=0;
	
	for(i=0;i<time-1;i++){
		min=*(num+i);
		for(j=i;j<time;j++){
			if(*(num+j) < min){
				min = *(num+j);
				keep = j;
			}
		}
		if(min != *(num+i)){
			swap(num,keep,i);
			count++;
		}
	}
	return count;
}

void swap(int *num,int keep,int i){
	int temp;
	temp = *(num+i);
	*(num+i) = *(num+keep);
	*(num+keep) = temp;
}

void print(int *num,int count,int time){	
	int i;
	
	for(i = 0 ;i < time; i++){
		printf("%d",*(num + i));
		if(i != (time - 1))/*最後の数字の後にスペースを入れないようにする*/
			printf(" ");
	}
	printf("\n%d\n",count);
}
