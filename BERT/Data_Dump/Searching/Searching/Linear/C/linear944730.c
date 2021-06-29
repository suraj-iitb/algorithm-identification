#include <stdio.h>

int main(int argc , char *argv[]){
    int n,q;
    int i,j;
    int N[10000];
    int Q[500];
    int count=0;
    
    scanf("%d",&n);
    if(n>=10001)return 0;
    
    for(i=0;i<n;i++){
        scanf("%d",&N[i]);
        }
    
    
    
    scanf("%d",&q);
    if(q>=501)return 0;
    
    for(i=0;i<q;i++){
        scanf("%d",&Q[i]);
    }
    
        for(i=0;i<q;i++){
            for(j=0;j<n;j++){
                if(Q[i]==N[j]){
                    count++;
                    break;
                }
            }
        }
    printf("%d\n",count);
    return 0;
}
