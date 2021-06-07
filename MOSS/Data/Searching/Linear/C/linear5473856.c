#include<stdio.h>

int main(void){
    int i,j,n,q,count=0;
    long long a[10000],b[500];

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%lld", &a[i]);
    }
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%lld", &b[i]);
    }

    for(j=0;j<q;j++){
        for(i=0;i<n;i++){
            if(a[i] == b[j]){
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
