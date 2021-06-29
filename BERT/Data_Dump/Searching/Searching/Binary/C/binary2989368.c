#include <stdio.h>
int Search(int *,int, int);

int main(){
 int S[100000],T[50000];
    int n,q,i,count=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)    scanf("%d",&S[i]);

    scanf("%d",&q);

    for(i=0;i<q;i++) {
        scanf("%d",&T[i]);
        if(Search(S,n,T[i])==1) count++;
    }

    printf("%d\n",count);

    return 0;
}

int Search(int *A,int n,int key){
    int left=0,middle=0,right=0;
    right=n;

    while(left<right){
        middle=(left+right)/2;
        if(A[middle]==key) return 1;
        if(A[middle]<key) left=middle+1;
        else if(A[middle]>key) right=middle;
    }
    return 0;
}
