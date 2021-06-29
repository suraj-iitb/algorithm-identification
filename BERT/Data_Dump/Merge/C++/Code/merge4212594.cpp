#include<iostream>
using namespace std;
#define F(i,s,e) for(int i=s;i<e;++i)

int n,cnt=0;

void merge(int a[], int left, int mid, int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1],R[n2+1];
    F(i,0,n1) L[i]=a[left+i];
    F(i,0,n2) R[i]=a[mid+i];
    L[n1]=2000000000;
    R[n2]=2000000000;
    int i=0,j=0;
    F(k,left,right){
        if(L[i]<=R[j]){
            a[k]=L[i];
            ++i;
        }
        else{
            a[k]=R[j];
            ++j;
        }
        ++cnt;
    }
}

void mergeSort(int a[], int left, int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}

int main()
{
    cin >> n;
    int a[n];
    F(i,0,n) cin >> a[i];
    mergeSort(a,0,n);
    F(i,0,n){
        cout << a[i];
        if(i!=n-1) cout << " ";
    }
    cout << endl << cnt << endl;
    return 0;
}
