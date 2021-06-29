#include<stdio.h>

int main(){


int n;
scanf("%d",&n);
int arr[100] = {0};
int count = 0;
for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
for(int i=0;i<n;i++){
	for(int j=n-1;j>=i+1;j--){
		if(arr[j]<arr[j-1]){
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			count++;
		}
	}
}
for(int i=0;i<n;i++){
	if(i==n-1)
	printf("%d\n",arr[i]);
	else 
	printf("%d ",arr[i] );
}
printf("%d\n",count);



	return 0;
}
