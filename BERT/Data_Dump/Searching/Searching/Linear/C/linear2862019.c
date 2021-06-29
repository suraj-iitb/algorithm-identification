#include <stdio.h>

void getN(int *x){
    scanf("%d",x);
}
void getElement(int s[],int n){
    int i;
    for(i=0;i<n;i++)scanf("%d",&s[i]);
}

int main(){
    int n;
    getN(&n);
    int S[n];
    getElement(S,n);
    
    int q;
    getN(&q);
    int T[q];
    getElement(T,q);
    
    int i,j;
    int count=0;
    for(i=0;i<q;i++){
        for(j=0;j<n;j++){
            if(T[i]==S[j]){
                count++;
                break;
            }
        }
    }
    printf("%d\n",count);
}
