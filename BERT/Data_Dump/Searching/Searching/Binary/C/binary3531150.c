#include <stdio.h>
#include <stdlib.h>
int binarySearch(int S[], int T[], long n, int q){
    int counter=0;
    for(int i=0; i<q; i++){
        int left = 0, right = n;
        // Searching algorithm
        while(left < right){
            int mid = (left+right)/2;
            if(T[i] == S[mid]){
                counter++;
                break;
            }
            else if(T[i] > S[mid]) left = mid + 1;
            else right = mid;
        }
    }
    return counter;
}

int main(){
    // Input n
    long n;
    scanf("%ld",&n);
    // Input S
    int S[n];
    for(int i=0; i<n; i++){
        scanf("%d",&S[i]);
    }
    // Inpupt q
    int q;
    scanf("%d",&q);
    // Input T
    int T[q];
    for(int i=0; i<q; i++){
        scanf("%d",&T[i]);
    }
    // Execution
    printf("%d\n",binarySearch(S,T,n,q));
    return 0;    
}
