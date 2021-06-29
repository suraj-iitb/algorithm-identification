#include<stdio.h>
int t=0;
void print(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		if(i>0)
		printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}
void bubble(int a[],int n){
	int flag=1,i,mid;
	while(flag){
		flag=0;
		for(i=n-1;i>0;i--){
			if(a[i]<a[i-1])
			{
				mid=a[i];
				a[i]=a[i-1];
				a[i-1]=mid;
				t++;
				flag=1;
			}
		}
	}
}
int main(){
	int i,n;
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	bubble(a,n);
	print(a,n); 
	printf("%d\n",t);
	return 0;
}
