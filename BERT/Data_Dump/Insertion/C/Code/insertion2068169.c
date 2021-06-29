#include <stdio.h>
int main(void){
    int i,j,k,n,v;
    int a[100]={0};
    
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    for(i=0; i<n; i++){
        if(i!=n-1) printf("%d ",a[i]);
        if(i==n-1) printf("%d\n",a[i]);
    }
    
    for(i=1; i<n; i++){
        v = a[i];
        j=i-1;
        
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
            a[j+1]=v;
        }
        
        for(k=0; k<n; k++){
        if(k!=n-1) printf("%d ",a[k]);
        if(k==n-1) printf("%d\n",a[k]);
    }
    }
    
    return 0;
    
}
