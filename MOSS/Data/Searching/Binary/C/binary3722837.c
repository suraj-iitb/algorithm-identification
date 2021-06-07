#include<stdio.h>

int A[110000], n;

int binarySearch(int key){
    int left=0;
    int right=n;
    int mid;

    while(left<right){
        mid = (left+right)/2;
        if(A[mid] == key){
            return(mid);
        }else if(key<A[mid]){
            right = mid;
        }else{
            left = mid +1;
        }
    }
    return(-1);
}

int main(){
    int q, t[100000];
    int i, j, k;
    int tmp, ans=0;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d", &t[i]);
    }

    for(i=0; i<q; i++){
        tmp = binarySearch(t[i]);
        if(tmp>=0){
            ans++;
        }
        //printf("%d\n", tmp);
    }

    printf("%d\n", ans);

    return 0;
}
