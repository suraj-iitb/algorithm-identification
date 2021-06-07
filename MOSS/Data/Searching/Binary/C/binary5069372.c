#include <stdio.h>

int main(){
    int n, q, S[100000], T[50000], C=0, i, l, r, m;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d", &T[i]);
    }
    for(i=0; i<q; i++){
        l=0;
        r=n;
        while(l<r){
            m=(l+r)/2;
            if(T[i]==S[m]){
                C++;
                break;
            }
            else if(T[i]<S[m]){
                r=m;
            }else{
                l=m+1;
            }
        }
    }
    printf("%d\n", C);
    return 0;
}
