#include <stdio.h>

int main(void){
    int i, j;
    int n, q;
    long S[10000], T[10000];
    int count = 0;
    
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%ld", &S[i]);
    }
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%ld", &T[i]);
    }
    
    for(i=0;i<q;i++){
        for(j=0;j<n;j++){
            if(T[i] == S[j]){
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);
    
    return 0;
}
