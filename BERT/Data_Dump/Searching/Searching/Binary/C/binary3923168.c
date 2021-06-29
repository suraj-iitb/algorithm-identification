
#include <stdio.h>

int main(){
    int n=0, q=0, C=0;
    int S[100000]={0}, T[100000]={0};
    int i=0, j=0, k=0;
    int key, left, right, mid;
    
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (j=0; j<q; j++){
        scanf("%d", &T[j]);
    }
    

    for (j=0; j<q; j++){
        key = T[j];
        left = 0;
        right = n;
        while(left < right){
            //printf("%d %d %d \n",left,mid,right);
            mid = (left + right) / 2;
            if(S[mid] == key) {
                C++;
                break;
            }else if(key < S[mid]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
    }
    
    printf("%d\n",C);
    return 0;
}
