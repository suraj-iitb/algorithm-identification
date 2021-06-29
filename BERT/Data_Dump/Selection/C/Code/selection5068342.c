#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[100],minj,n,i,j,m,q,sort;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<=n-1;i++){
        minj = i;
        for(j=i;j<=n-1;j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(a[i] != a[minj]){
            q = a[i];
            a[i] = a[minj];
            a[minj] = q;
            sort++;
        }       
    }
    for(i=0;i<n-1;i++) printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    printf("%d\n",sort);
}
