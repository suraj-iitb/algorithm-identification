#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i,j,num,*arr,min,temp,count = 0;
	scanf("%d",&num);
	arr = (int *)malloc(sizeof(int) * num);
	for(i=0;i<num;i++)scanf("%d",&arr[i]);
	for(i=0;i<num;i++){
		min = i;
		for(j=i;j<num;j++){
		if(arr[j] < arr[min]) min = j;
		}
	if(arr[i] != arr[min]){
	temp = arr[i];
	arr[i] = arr[min];
	arr[min] = temp;
	count++;
	}
	}
	for(i=0;i<num;i++) i != num-1 ? printf("%d ",arr[i]) : printf("%d\n",arr[i]);
	printf("%d\n",count);
	free(arr);
	return  0;
	}	
