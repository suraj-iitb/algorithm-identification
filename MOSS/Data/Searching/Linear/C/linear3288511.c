#include<stdio.h>
int linerSearch(int,int S[],int);
int main(){
    int n,S[10000];
    int q,T[500];
    int i,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
       scanf("%d",&S[i]); 
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
        count+=linerSearch(n,S,T[i]);
    }
    printf("%d\n",count);
    return 0;
}

int linerSearch(int n,int S[],int key){
    int i;
    for(i=0;S[i]!=key;i++){
        if(i==n)
        return 0;
    }
    return 1;
}
