

#include<stdio.h>
int main(){
	int n,i,j,k=0,temp;
	int a[100]; 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int flag=1;
	for(i=0;flag==1;i++){
		flag=0;
		for(j=n-1;j>=i+1;j--){
			if(a[j]<a[j-1]){
				flag=1;
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				k++;
			}
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[i]);

	 printf("%d\n",k);

} 
