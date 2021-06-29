#include <stdio.h>
#define NotFound 0
#define Found 1

int linearSearch(int n,int A[10000],int key){
    int i=0;
    while(A[i]!=key){
        i++;
        if(i==n){
        return NotFound;
        }
    }
    return Found;
}

int main(){
    int i,j,n,q,S[10000],T[500],C=0; 

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d", &T[i]);
    }

    for(j=0;j<q;j++){
    if(linearSearch(n,S,T[j])==Found)C++;
    else continue;
    }
    printf("%d\n",C);

    return 0;
}
