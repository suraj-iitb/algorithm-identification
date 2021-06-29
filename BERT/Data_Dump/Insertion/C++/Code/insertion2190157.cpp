#include <iostream>
#include <cstdio>
using namespace std;

void prt(int A[],int n){
    for(int i=0;i<n;++i){
        if(i>0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
}

void insertSort(int A[],int n){
    for(int i=1;i<n;++i){
        int v=A[i];
        int j=i-1;
        while(A[j]>v&&j>=0){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        prt(A,n);
    }
}
int main()
{
    int n;
    int A[100];
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&A[i]);
    prt(A,n);
    insertSort(A,n);
    return 0;
}
