
#include<stdio.h>

int a[110];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++){
		int j=i;
		while(i>0&&a[j-1]>a[i])j--;
		int t=a[i];
		for(int k=i;k>j;k--)a[k]=a[k-1];
		a[j]=t;
		for(int j=0;j<n;j++)printf("%d%c",a[j],j==n-1?10:32);
	}
}
