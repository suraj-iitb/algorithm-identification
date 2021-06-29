#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
#define MAX 100000
struct Card{char suit;int value;};
struct Card A[MAX],B[MAX];int n;
void merge(int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    Card L[MAX/2+2],R[MAX/2+2];
    rep(i,0,n1)L[i]=A[left+i];
    rep(i,0,n2)R[i]=A[mid+i];
    L[n1].value=2000000000;R[n2].value=2000000000;
    int i=0,j=0;
    rep(k,left,right){
        if(R[i].value>=L[j].value){
            A[k]=L[j];
            j++;
        }
        else{
            A[k]=R[i];
            i++;
        }
    }
}
void mergesort(int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergesort(left,mid);
        mergesort(mid,right);
        merge(left,mid,right);
    }
}
int partition(int p,int r){
    int x=B[r].value;
    int i=p-1;
    rep(j,p,r){
        if(B[j].value<=x){
            i++;
            swap(B[i],B[j]);
        }
    }
    swap(B[i+1],B[r]);
    return i+1;
}
void quicksort(int p, int r){
    if(p<r){
        int q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}
int main(){
    cin>>n;
    rep(i,0,n){
        cin>>A[i].suit>>A[i].value;
        B[i].suit=A[i].suit;
        B[i].value=A[i].value;
    }
    mergesort(0,n);
    quicksort(0,n-1);
    int stable=1;
    rep(i,0,n){
        if(A[i].suit!=B[i].suit)stable=0;
    }
    if(stable)cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;
    rep(i,0,n){
        cout<<B[i].suit<<" "<<B[i].value<<endl;
    }
    return 0;
}
