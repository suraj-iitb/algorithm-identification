#include<stdio.h>
#include<stdbool.h>
#define MAX 100000

bool flg;
int cnt=0;
int S[MAX],T[MAX];
int i,j,s,t;

int main(){
    scanf("%d",&s);
    for(i=0;i<s;i++){
        scanf("%d",&S[i]);
        //printf("%d ",S[i]);
    }
    //printf("\n");
    
    scanf("%d",&t);
    for(j=0;j<t;j++){
        scanf("%d",&T[j]);
        //printf("%d ",T[j]);
    }
    //printf("\n");
    
    
    for(j=0;j<t;j++){
        flg=false;
        for(i=0;i<s;i++){
            if(S[i]==T[j])flg=true;
        }
        if(flg)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
 
