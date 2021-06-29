#include <stdio.h>
#define M 1002

void printline(int n,int a[]){
	int i;
	printf("%d",a[0]);
	for(i=1;i<n;i++){
		printf(" %d",a[i]);
	}
	printf("\n");
	return;
}

void insertsort(int p, int a[]){

	int pp=p,dum_a,dum_b,i;

	for(i=0;i<p;i++){
		if(a[p]<a[i]){
		 pp=i;
		 dum_a=a[p];
		 break;
		}
	}

	if(i==p) return;

	for(i=pp;i<p+1;i++){
		dum_b=a[i];
		a[i]=dum_a;
		dum_a=dum_b;
	}

	return;

}

int main(void){
	int i,n,a[M];
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++){
		insertsort(i,a);
		printline(n,a);
	}

	return 0;

}
