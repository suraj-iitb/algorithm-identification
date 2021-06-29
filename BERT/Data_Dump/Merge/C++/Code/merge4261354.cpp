#include<iostream>
#define NMAX 500000
#define SENTINEL 2000000000
using namespace std;

int c=0;

void merge(int a[],int n,int first,int mid,int last){
    int F[NMAX+1],L[NMAX+1];
    int nf=mid-first;
    int nl=last-mid;
    for(int i=0;i<nf;i++) F[i]=a[first+i];
    for(int i=0;i<nl;i++) L[i]=a[mid+i];
    F[nf]=L[nl]=SENTINEL;
    int i=0,j=0;
    for(int k=first;k<last;k++){
        if(F[i]<=L[j]) a[k]=F[i++];
        else a[k]=L[j++];
        c++;
    }
}

void mergeSort(int a[],int n,int first,int last){
    if(last-first>1){
        int mid=(first+last)/2;
        mergeSort(a,n,first,mid);
        mergeSort(a,n,mid,last);
        merge(a,n,first,mid,last);
    }
}

int main(){
    int n,a[NMAX];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    mergeSort(a,n,0,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<((i==n-1)?'\n':' ');
    }
    cout<<c<<endl;
}
