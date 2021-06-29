#include<iostream>

using namespace std;
int a[500000];
int b[500000];
int c =0;
void merge_sort(int l,int r){
    if (r-l==1)return;
    int mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid,r);


    int lp=l,rp=mid;
    for(int i=l;i<r;i++){
        if (lp==mid){
            b[i]=a[rp];
            rp++;
        }
        else if(rp==r){
            b[i]=a[lp];
            lp++;
        }
        else if(a[lp]>a[rp]){
            b[i]=a[rp];
            rp++;
        }
        else{
            b[i]=a[lp];
            lp++;
        }
        c++;
    }
    for(int i=l;i<r;i++){
        a[i]=b[i];
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    merge_sort(0,n);
    for (int i = 0;i < n;i++){
        cout << a[i];
        if(i<n-1){
            cout<<" ";
        }
    }
    cout<<endl;
    cout<<c<<endl;
}
