#include <iostream>
#define MAX 500000
#define SENTINEL 2000000000
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int L[MAX/2+2],R[MAX/2+2];
int cnt;

//統治作業
void merge(int A[], int n,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    rep(i,n1) L[i]=A[left+i];//左側に分けられた数値を配列L[0],L[1]...と入れていく
    rep(i,n2) R[i]=A[mid+i];//右側に分けられた数値を配列R[0],L[1]...と入れていく
    L[n1]=R[n2]=SENTINEL;//n1,n2はmidに当たる部分なので、同じ値になるはず！
    int i=0,j=0;
    
    for (int k=left; k<right; k++){//右側ブロックvs左側ブロック
        cnt++;
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }
}

//分割作業
void mergeSort(int A[], int n, int left, int right){
    if(left+1<right){//部分配列の要素数が１になるまで分割する！
        int mid=(left+right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(){
    int A[MAX],n,i;
    cnt=0;
    
    cin >> n;
    rep(i,n) cin >> A[i];
    mergeSort(A,n,0,n);
    rep(i,n){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

