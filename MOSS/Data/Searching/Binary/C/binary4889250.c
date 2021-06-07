#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    int count=0;
    long long n, q, i, j;

    scanf("%lld", &n);
    long long S[n];
    for(i=0; i<n; i++){
        scanf("%lld", &S[i]);
    }

    scanf("%lld", &q);
    long long T[q];
    for(i=0; i<q; i++){
        scanf("%lld", &T[i]);
    }

    long long left, mid, right;

    for(j=0; j<q; j++){

        left = 0;
        right = n;

        while(left<right){
            mid = (left+right)/2;
            if(S[mid]==T[j]){
                count++;
                break;
            }
            if(S[mid]<T[j]){
                left=mid+1;
            }else{
                right=mid;
            }
        }

    }

    printf("%d\n", count);

    return 0;
}
