#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[100],n,v,i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        v = a[i];
        j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(int m=1;m<=n;m++){
            printf("%d",a[m]);
            if(m==n) break;
            printf(" ");
        }
        printf("\n");
    }
}


