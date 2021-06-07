// Linear Search

#include<stdio.h>

int search(int a[],int n,int key){
    int i,ans=0;
    for(i=0;i<n;i++){
        if(a[i]==key){
            ans=1;
        }
    }
    return ans;
}

int main(void){
    int n,q,S[10000],i,key,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if(search(S,n,key)){
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}

