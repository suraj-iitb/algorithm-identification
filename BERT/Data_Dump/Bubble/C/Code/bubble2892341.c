#include<stdio.h>

void sort(void);

int i,j,p,irekae,n=0;
int a[200];

int main(void){
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	
	sort();
	
	for(i=0;i<n;i++){
		if(i!=0)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n%d\n",irekae);
	
	return 0;
}

void sort(void){
	int t=0;
	
	for(p=0;p<n;p++){
		for(i=n-1,j=n-2;j>=p;i--,j--){
			if(a[i]<a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				irekae=irekae+1;
			}
		}
	}
	return;
}
