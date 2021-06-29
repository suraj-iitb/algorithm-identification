#include<stdio.h>

int main(){

int n,q,S[10000],T[500];
int a,b=0,i,j,count=0;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&S[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++)
        scanf("%d",&T[i]);

    for(i=0;i<n;i++){
        for(j=0;j<q;j++){
            if(S[i]==T[j]){
                for(a=0;a<i;a++){
                    if(S[a]==S[i]){
                        b++;
                        break;
                    }
                }
            count++;
            }
        }
    }

printf("%d\n",count-b);

return 0;

}
