#include<stdio.h>

int s[100000],n;

int binarySearch(int key){
    int left,mid,right;
    left=0;
    right=n;
    while(left<right){
        mid=(left+right)/2;
        if(s[mid]==key)return mid;
        else if(key>s[mid])left=mid+1;
        else right=mid;
    }
    return 0;
}

int main(){
    int q,key,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if(binarySearch(key))sum++;
    }
    printf("%d\n",sum);
    return 0;
}
