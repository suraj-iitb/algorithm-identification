#include <stdio.h>
#define N 100

int a[N];

void PrintMatrix(int n){
	int i;
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
}

void Bubble(int n){
	int i,j,f,temp,c=0;
	f=1;
	i=0;
	while(f){
		f=0;
		for(j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				f=1;
				c++;
			}
		}
		i++;
	}
	PrintMatrix(n);
	printf("%d\n",c);
}


int main(void){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	Bubble(n);
	return 0;
}
