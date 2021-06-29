#include <stdio.h>
void swap(int *a,int *b);
int main(void) {
	int n,i,j,hanten=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
				hanten++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1)printf(" ");
	}
	puts("");
	printf("%d\n",hanten);
	return 0;
}
void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
