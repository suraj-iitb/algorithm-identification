#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[2000001],b[2000001],c[10000],n,k=10000;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<=k; i++){
        c[i] = 0;
    }
    for(int j=1; j<=n; j++){
        c[a[j]]++;
    }
    
    for(int i=1; i<=k; i++){
        c[i] = c[i] + c[i-1];
    }
    
    for(int j=n; j>=1; j--){
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
    for(int i=1;i<=n-1;i++) printf("%d ",b[i]);
    printf("%d\n",b[n]);
}
