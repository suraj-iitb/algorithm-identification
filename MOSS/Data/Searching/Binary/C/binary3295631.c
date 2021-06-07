#include<stdio.h>

int binarySearch(int n,int *S,int key){
    int left = 0, right = n,mid;
    while(left<right){
        mid = (left + right)/2;
        if(key == S[mid]){
            return 1;
        }
        if(key > S[mid]){
            left = mid + 1;
        }
        else if(key < S[mid]){
            right = mid;
        }
    }
    return 0;
}

int main(){
    int i,j,n,q,S[100000],T[50000],count = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(j=0;j<q;j++){
        scanf("%d",&T[j]);
    }

    for(j=0;j<q;j++){
        if(binarySearch(n,S,T[j]) == 1)
        count++;
    }

    printf("%d\n",count);
}
