#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, q, key;
    int *S;
    int i, j, cnt=0;

    scanf("%d",&n);
    S = (int*)malloc( sizeof(int)*(n+1) );
    for(i=0; i<n; i++)
        scanf("%d",&S[i]);
    
    scanf("%d",&q);
    for(i=0; i<q; i++){
        scanf("%d",&key);
        S[n] = key;
        
        j = 0;
        while(S[j] != key) j++;
        if(j != n) cnt++;
    
    }
    
    printf("%d\n",cnt);
    
    free(S);
    return 0;
}
