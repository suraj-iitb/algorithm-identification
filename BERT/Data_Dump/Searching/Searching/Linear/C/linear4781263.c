#include<stdio.h>
#include<stdbool.h>

bool linearSearch(int *S, int t, int n){
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(S[i] == t){
            flag = 1;
            break;
        }
    }
    if(flag){
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    int n, q;
    scanf("%d", &n);
    int S[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    int T[q];
    for(int i = 0; i < q; i++){
        scanf("%d",&T[i]);
    }
    int count = 0;
    for(int i = 0; i < q; i++){
        if(linearSearch(S,T[i], n)){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
