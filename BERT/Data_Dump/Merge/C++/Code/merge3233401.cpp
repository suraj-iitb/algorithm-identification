#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = (int) 5e5 + 10;
const int INF = (int) 0x3f3f3f3f;
typedef long long LL;

int N;
int L[MAXN/2],R[MAXN/2];
int arr[MAXN];
int cnt;

void Merge(int A[],int n,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
//    printf("left = %d , mid = %d , right = %d\n",left,mid,right);
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=R[n2]=INF;
    int i=0,j=0;
//    printf("L:\n");
//    for(int i=0;i<n1;i++) printf("%d ",L[i]);
//    printf("\n");
//    printf("R:\n");
//    for(int i=0;i<n2;i++) printf("%d ",R[i]);
//    printf("\n");
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
//            printf("L: A[%d] = %d\n",k,L[i]);
            A[k]=L[i++];
        }
        else{
//            printf("R: A[%d] = %d\n",k,R[i]);
            A[k]=R[j++];
        }
    }
//    for(int k=left;k<right;k++) printf("%d ",A[k]);
//    printf("\n");
}

void mergeSort(int A[],int n,int left,int right){
    if(left+1<right){
        int mid=(left+right)>>1;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        Merge(A,n,left,mid,right);
    }
}

void work(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    cnt=0;
    mergeSort(arr,N,0,N);
    for(int i=0;i<N;i++){
        printf("%d",arr[i]);
        if(i<N-1) printf(" ");
    }
    printf("\n%d\n",cnt);
}

int main(){
    work();
    return 0;
}

