#include <stdio.h>
#define N 100

int bubble(int a[],int n);
void printline(int a[], int n);

int main(){

	int i,n,a[N],change;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	change = bubble(a,n);

	printline(a,n);
	printf("%d\n",change);


}

int bubble(int a[], int n){

	int i,j,change=0,dum;
	for(i=n;i>0;i--){
		for(j=1;j<i;j++){
			if(a[j]<a[j-1]){
				dum=a[j];
				a[j]=a[j-1];
				a[j-1]=dum;
				change++;
			}
		}
	}

	return change;

}

void printline(int a[],int n){

	int i;
	for(i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);

}
