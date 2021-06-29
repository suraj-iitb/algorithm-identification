#include <stdio.h>

int searchfunction(int A[],int num,int x){
    int j=0;
    int ans=0;
    
    while(A[j]!=num){
        j++;
        if(j==x)break;
    }
    
    if(j!=x)
        ans=1;
    
    return ans;
}

int main(){
    int n,q,S[10000];
    int keynum;
    int i,cnt=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&S[i]);
    
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&keynum);
        cnt += searchfunction(S,keynum,n);
    }
    
    printf("%d\n",cnt);
    return 0;
}
