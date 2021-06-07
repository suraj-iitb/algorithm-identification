#include <stdio.h>
#define MAX1 10000
#define MAX2 10000

int main(){
    int n,q,i,j;
    int a[MAX1];
    int b[MAX2];
    int count=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&b[i]);
    }

    for(i=0;i<q;i++){
        for(j=0;j<n;j++){
            if(a[j]==b[i]){
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
}
