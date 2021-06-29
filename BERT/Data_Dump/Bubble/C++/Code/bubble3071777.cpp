#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int n;
int A[105];
int ans;
int bubbleSort(int A[],int n){
    ans = 0;
    bool flag=1;
    for(int i=0;flag;i++){
    flag=0;
    for(int j=n-1;j>=i+1;j--){
     if(A[j]<A[j-1]){
         swap(A[j],A[j-1]);
         flag=1;
         ans++;
     }    
    }    
}
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    ans=bubbleSort(A,n);
    for(int i=0;i<n;i++){
        if(i){
            printf(" ");
        }
    printf("%d",A[i]);
    }
    printf("\n%d\n",ans);
    return 0;
}
