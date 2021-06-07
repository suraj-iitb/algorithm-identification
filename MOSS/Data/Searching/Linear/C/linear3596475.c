#include<stdio.h>

int main(){
    int n,q;
    int i,j;
    int count=0;
    scanf("%d",&n);
    int S[n];
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    int T[q];
    int T_checked[q];
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
        T_checked[i]=0;
    }

    for(i=0;i<n;i++){
        for(j=0;j<q;j++){
            if(S[i]==T[j] && T_checked[j]==0){
                count+=1;
                T_checked[j]=1;
                break;
            }
        }
    }
    printf("%d\n",count);
}
