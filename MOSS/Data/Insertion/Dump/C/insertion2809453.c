#include<stdio.h>
#define N 100

int main(void){
    int n,i,j,k,a[N],base;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        base=a[i];
        j=i-1;
        while(j>=0 && a[j]>base){
            a[j+1]=a[j];
            j=j-1;
            a[j+1]=base;
        }
	    for(k=0;k<n;k++){
		    if(k<n-1){
                printf("%d ",a[k]);
            }
            if(k==n-1){
                printf("%d\n",a[k]);
            }
        }
    }
        return 0;
}
