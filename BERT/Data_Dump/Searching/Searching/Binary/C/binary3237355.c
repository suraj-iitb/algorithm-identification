#include<stdio.h>

int main(){
    int right, left, n, q, middle, i, j, S[100000], T[50000], count = 0;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++){
        scanf("%d", &T[i]);
    }
    
    left = 0;
    right = n;
    for (i = 0; i < q; i++){
        while(right > left){
            middle = (right + left)/2;
            if(S[middle] == T[i]){
                count++;
                break;
            } else if(S[middle] > T[i]){
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        left = 0;
        right = n;
    }
    
    printf("%d\n", count);
    
    return 0;
}

