#include <bits/stdc++.h>
using namespace std;

int bubble_sort(int n,int A[]){
    int sum=0;int x;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(A[j]<A[j-1]){
                x=A[j];
                A[j]=A[j-1];
                A[j-1]=x;
                sum++;
            }
        }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    int sum=bubble_sort(n,A);
    for(int i=0;i<n;i++){
        if(i!=0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n%d\n",sum);
}
