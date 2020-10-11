#include <stdio.h>
int main(void){
    int c=0,n,t,i,j,k,a[100],f=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d",&a[i]);
    }
    while(f){
    	f=0;
    	for(i=n-1;i>=1;i--){
    		if(a[i]<a[i-1]){
    			t=a[i];
    			a[i]=a[i-1];
    			a[i-1]=t;
    			f=1;
    			c++;
    		}
    	}
    }
    for(i=0;i<n;i++){
    	if(i!=0) printf(" ");
    	printf("%d",a[i]);
    }
    printf("\n%d\n",c);
    
    return 0;
}
