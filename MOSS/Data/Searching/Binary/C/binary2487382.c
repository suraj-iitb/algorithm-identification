#include <stdio.h>

int binarySearch(int S[], int n, int key){
    int left = 0;
    int right = n;
    int mid;
    
    while(left < right){
        mid = (left+right)/2;
        
        if(S[mid] == key){
            return 1;
        }
        if(key < S[mid]){
            right = mid;
        }else if(key > S[mid]){
            left = mid+1;
        }
    }
    
    return 0;
}


int main(void){
    int i;
    int n, q;
    int  S[1000000];
    int key;
    int count = 0;
    
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%d", &key);
        if(binarySearch(S, n, key)) count++;
    }
    
    printf("%d\n", count);
    
    return 0;
}
