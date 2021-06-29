#include <stdio.h>

int main(){
    int n=0, q=0, C=0;
    int S[100000]={0}, T[100000]={0};
    int i=0, j=0;
    int key;
    
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (j=0; j<q; j++){
        scanf("%d", &T[j]);
    }
    
    for (j=0; j<q; j++){
        i = 0;
        key = T[j];
        S[n] = key;
        while (S[i] != key){
            i++;
        }
        if(i!=n) C++;
    }
    
    printf("%d\n",C);
    return 0;
}
