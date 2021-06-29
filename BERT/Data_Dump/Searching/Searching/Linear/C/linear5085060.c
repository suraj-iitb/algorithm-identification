#include <stdio.h>
#include <stdlib.h>

int dastel(int noa[],int gorira,int kuzu){
    int i=0;
    noa[gorira]=kuzu;
    while(noa[i]!=kuzu){
        i++;
    }
    return i!=gorira; 
}

int main(){
    int i,num,s[10000+1],q,kyo,res=0;

    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&s[i]);
    }

    scanf("%d",&q);
    if(q<0&&q>500) exit(1);
    for(i=0;i<q;i++){
        scanf("%d",&kyo);
        if(dastel(s,num,kyo)) res++;
    }
    printf("%d\n",res);
    return 0;
}
