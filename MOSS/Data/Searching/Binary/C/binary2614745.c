#include<stdio.h>

int binarySearch(int S[], int n, int key){
    int left=0;
    int right=n;
    int mid;

    while(left<right){
        mid = (left+right)/2;
        if(S[mid]==key){
            return 1;
        }else if(key<S[mid]){
            right=mid;
        }else if(key>S[mid]){
            left=mid+1;
        }
    }
    return 0;
}

int main(){
    int S[500000], i, n, q, k, cnt;
    cnt=0;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%d", &k);
        if(binarySearch(S,n,k) == 1){
            cnt++;            
        }
    }

    printf("%d\n", cnt);

    return 0;
}
