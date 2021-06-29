#include <stdio.h>
int main(void){
    int n,i,j,k,a[100],v;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=1;i<n;i++){
    	printf("%d",a[0]);
    	for(k=1;k<n;k++){
    		printf(" %d",a[k]);
    		//if(k<=n-1) printf(" *");
    	}
    	printf("\n");
    	v=a[i];
    	j=i-1;
    	while(j>=0&&a[j]>v){
    		a[j+1]=a[j];
    		j--;
    	}
    	a[j+1]=v;
    	
    }
    printf("%d",a[0]);
    for(k=1;k<n;k++){
    		printf(" %d",a[k]);
    		//if(k<=n-1) printf(" *");
    	}
    	printf("\n");
    return 0;
}
