#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i,j,num,*arr,count,temp;
	scanf("%d",&num);
	arr = (int*)malloc(num*sizeof(int));
	for(i=0;i<num;i++) scanf("%d",&arr[i]);
	for(i=0;i<num;i++){
		for(j=i;j>0;j--){
			if(arr[j] < arr[j-1]){
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				count++;
				}
			}
		}		
	for(i=0;i<num;i++){
		i != num-1 ? printf("%d ",arr[i]):printf("%d\n",arr[i]);
		}		
	printf("%d\n",count);
	return 0;
}
