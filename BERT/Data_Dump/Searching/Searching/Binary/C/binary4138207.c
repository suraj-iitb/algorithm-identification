#include <stdio.h>

#define N 100000
#define Q 50000



int main(){
    int i,j,n,q;
    int cen;
    int S[N],T[Q];
    int cnt=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    cen = S[(n+1)/2];

    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
    }

    for(i=0;i<q;i++){
        if(cen > T[i]){
            for(j=0;j<n/2+1;j++){
                if(S[j] == T[i]){
                    cnt++;
                    break;
                }    
            }
        }
        else{
            for(j=n/2;j<n+1;j++){
                if(S[j] == T[i]){
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

