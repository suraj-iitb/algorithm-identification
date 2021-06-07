#include <stdio.h>

int main(void){
    int n,q,i,j,count,t;
    int s[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    count = 0;
    for(i=0;i<q;i++){
        scanf("%d",&t);
        for(j=0;j<n;j++){
            if(s[j]==t){
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
}

