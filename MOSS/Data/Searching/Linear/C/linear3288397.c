#include<stdio.h>
#define N 10000

int main(){

    int a,b,i,j,key,cnt = 0,S[N],T[N];

    scanf("%d",&a);
    for(i = 0;i < a;i++){
        scanf("%d",&S[i]);
    }

    scanf("%d",&b);
    for(i = 0;i < b;i++){
        scanf("%d",&T[i]);
    }
    for(i = 0;i < b;i++){
        key = T[i];
        for(j = 0;j < a;j++){
            if(key == S[j]){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
