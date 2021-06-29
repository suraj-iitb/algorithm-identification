#include <stdio.h>
int main(void){
	int i,j,t,n,c=0,a[100],f,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		f=0;
		m=i;
		for(j=i+1;j<n;j++){
			if(a[m]>a[j]){
				m=j;
				f=1;
			}
		}
		t=a[i];
		a[i]=a[m];
		a[m]=t;
		if(f) c++;
	}
	for(i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n%d\n",c);
			
    return 0;
}
