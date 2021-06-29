#include <stdio.h>
#include <stdlib.h>

int Z[100000],num;

int boxS(int kyoani){
    int L=0,R=num,M;
    while(L<R){
        M=(R+L)/2;
        if(kyoani==Z[M]) return 1;
        if(kyoani>Z[M]) L=M+1;
        else if(kyoani<Z[M]) R=M;
    }
    return 0;
}

int main(){
    int i,q,kuzu,res=0;

    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&Z[i]);
    }

    scanf("%d",&q);
    if(q<0&&q>50000) exit(2);
    for(i=0;i<q;i++){
        scanf("%d",&kuzu);
        if(boxS(kuzu)) res++;
    }
    printf("%d\n",res);
    return 0;
}
