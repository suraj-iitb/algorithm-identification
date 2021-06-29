#include <bits/stdc++.h>
using namespace std;

void insert_sort(int n,int A[]){
    for(int i=0;i<n;i++){
    int x=A[i];
    int j;
    for(j=i-1;j>=0;j--){
        if(x<A[j])A[j+1]=A[j];
        else break;
    }
    A[j+1]=x;
    for(int k=0;k<n;k++){
        if(k!=0)printf(" ");
        printf("%d",A[k]);
    }
    printf("\n");
    }
    return ;
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    insert_sort(n,A);
}
