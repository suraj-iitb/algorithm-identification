#include <stdio.h>

void output(int x[],int y){
	int i;
	for(i=0;i<y;i++){
		if(i>0){ printf(" "); }
		printf("%d",x[i]);
		if(i==y-1){ printf("\n"); }
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	int i,j,temp;
	for(i=0;i<n;i++){ scanf("%d",&a[i]); }
	output(a,n);
	
	for(i=1;i<n;i++){
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		output(a,n);
	}
	
	return 0;
}
