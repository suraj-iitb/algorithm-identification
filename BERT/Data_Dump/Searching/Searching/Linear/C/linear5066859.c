#include <stdio.h>
#define N 10000
#define Q 500

int linearsearch(int,int);

int s[N];

int main(){
    int t[Q];
    int n,q;
    int i,j;
    int result=0;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }

    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d",&t[i]);
    }

    for (i=0;i<q;i++){
        if(linearsearch(t[i],n)==1) result++;
    }
    
    printf("%d\n",result);

    return 0;
}

int linearsearch(int tar,int n){
    int i;
    for(i=0;i<n;i++){
        if(tar==s[i]){
            return 1;
        }
    }
    return 0;
}
