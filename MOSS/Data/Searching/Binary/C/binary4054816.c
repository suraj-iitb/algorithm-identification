#include <stdio.h>
int func(int,int *,int);
int main (){
    int n,s[100001],i,q,t,j,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&t);
        cnt+=func(n,s,t);
    }
    printf("%d\n",cnt);
    return 0;
}

int func(int n,int *s,int key){
    int left=0,right=n,mid;
    while(left<right){
        mid=(left+right)/2;
        if(key==s[mid]){
            return 1;
        }
        if(key>s[mid]){
            left=mid+1;
        }
        else if(key<s[mid]){
            right=mid;
        }
    }
    return 0;
}

