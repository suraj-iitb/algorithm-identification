#include <stdio.h>


int search(int a[],int b[],int m,int n)
{
	int i,j,t=0;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if (a[i]==b[j]){
				t++;
				break;
			}
		}
	}
	return t;
}

int main ()
{
	int a[10000]={0};
	int b[500]={0};
	int m,n,i,t;
	scanf ("%d",&n);
	for (i=0;i<n;i++){
		scanf ("%d",&a[i]);
	}
	scanf ("%d",&m);
	for (i=0;i<n;i++){
		scanf ("%d",&b[i]);
	}
	if (n>m){
		t=search (b,a,m,n);
	}
	else{
		t=search (a,b,n,m);
	}
	printf ("%d\n",t);
	return 0;
} 
