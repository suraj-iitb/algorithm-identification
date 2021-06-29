#include <bits/stdc++.h>
using namespace std;

int select_sort(int A[],int n){
    int sum=0;
    int j,minj;
    for(int i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            minj=(A[minj]>A[j])?j:minj;
        }
        if(i!=minj){
        swap(A[i],A[minj]);sum++;
        }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)scanf("%d",&A[i]);
    int sum=select_sort(A,n);
    for(int i=0;i<n;i++){
        if(i!=0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n%d\n",sum);

}
