#include <stdio.h>

void insertion(int a[], int n)
{
	int i, j, k;
	for(i=1;i<n;i++){
		int tmp=a[i];
		for(j=i;j>0&&a[j-1]>tmp;j--){
			a[j]=a[j-1];
		}
			a[j]=tmp;
			for(k=0;k<n;k++){
				if(k<n-1)
					printf("%d ",a[k]);
				else
					printf("%d\n", a[k]);
			}
	}
}
//#define N 6
int main()
{
	int N, i;
	scanf("%d", &N);
	int a[N];
	
	
	for(i=0;i<N;i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<N;i++){
		if(i<N-1)
			printf("%d ", a[i]);
		else
			printf("%d\n", a[i]);
	}
	
	insertion(a, N);
	
	return 0;
}
