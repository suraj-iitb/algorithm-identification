#include <stdio.h>
int main(void){
    int i,j,n,minj,tmp,cnt=0;
    int a[100]={};
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(a[minj]>a[j]){
                minj=j;
            }
        }
        if(minj!=i){
            tmp=a[minj];
            a[minj]=a[i];
            a[i]=tmp;
            cnt++;
        }
    }
    
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i==n-1)puts("");
        else printf(" ");
    }
    printf("%d\n",cnt);
    
    return 0;
}
