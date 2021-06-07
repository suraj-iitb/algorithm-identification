#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, *S, q, key;
    int i, left, right, mid, cnt=0;

    scanf("%d",&n);
    S = (int*)malloc( sizeof(int) * n);
    for(i=0; i<n; i++)
        scanf("%d",&S[i]);
    
    scanf("%d",&q);
    for(i=0; i<q; i++){
        scanf("%d",&key);
        
        left = 0;
        right = n;

        while( left < right ){
            mid = (left + right) / 2;
            
            if( S[mid] == key ){
                cnt++;
                break;
            }
            else if(key < S[mid]) right = mid;
            else left = mid +1;

        }
    }
    printf("%d\n",cnt);
    
    free(S);
    return 0;
}
