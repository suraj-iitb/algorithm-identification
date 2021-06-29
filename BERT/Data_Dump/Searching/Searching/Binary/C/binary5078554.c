#include<stdio.h>

int S[1000000],n;

int binarysearch(int);

int main(){
    int i,m,key,sum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }

    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&key);
        if(binarysearch(key)) sum++;
    }
    printf("%d\n",sum);
    return 0;
}

int binarysearch(int key){
    int left=0,right=n,mid;
    while(left<right){
        mid = (left + right) / 2;
        if(key==S[mid]) return 1;
        if(key > S[mid]) left = mid + 1;
        else if(key < S[mid]) right = mid;
    }
return 0;
}
