#include<stdio.h>
int main(){
	int n,i,c;
	int a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (i=1;i<=n;i++){
		c=1;
		for(int k=0;k<n;k++){
			printf("%d",a[k]);
			if(k==n-1){
				c=0;
			}
			if(c){
				printf(" ");
			}else{
				printf("\n");
			}
		}
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
	}

	return 0;
}
