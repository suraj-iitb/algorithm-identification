#include <stdio.h>
void printl(int *x,int n){
	for(int t=0;t<n;t++){
			printf("%d",x[t]);
			printf(t==n-1?"\n":" ");
		}
	}
int main(){
	int n,i,j,v,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printl(a,n);
	for(i=1;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
			}
		a[j+1]=v;
		printl(a,n);
		}
	}
