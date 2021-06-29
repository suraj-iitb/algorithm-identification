#include<stdio.h>
void insersion(int *a,int n);

int main(){
	int n;
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	insersion(a,n);

	return 0;
}


void insersion(int *a,int n){
	int i,j,v,k;
	for(i=0;i<=n-1;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		k=0;
		while(1){
			printf("%d",a[k]);
			k++;
			if(k==n){
				printf("\n");
				break;
			}
			printf(" ");
		}
	}

}
