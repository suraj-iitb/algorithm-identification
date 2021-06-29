#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

long long co=0;

void merge(vector<int> &da,int le,int mi,int ri){
    int n1=mi-le;
    int n2=ri-mi;
    vector<int> L(n1+1),R(n2+1);
    for(int i=0;i<n1;i++){
        L[i]=da[le+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=da[mi+i];
    }
    L[n1]=INT_MAX;R[n2]=INT_MAX;
    int i=0,j=0;
    for(int k=le;k<ri;k++){
        if(L[i]<R[j]){
            da[k]=L[i];
            i++;
        }
        else{
            da[k]=R[j];
            j++;
        }
        co++;
    }
}

void mergesort(vector<int> &da,int le,int ri){
    if (le+1<ri){
        int mi=(le+ri)/2;
        mergesort(da,le,mi);
        mergesort(da,mi,ri);
        merge(da,le,mi,ri);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> da(n);
    for(int i=0;i<n;i++){
        cin >> da[i];
    }
    mergesort(da,0,n);
    for(int i=0;i<n;i++){
        if(i!=n-1){
            cout << da[i] << ' ';
        }
        else{
            cout << da[i] << endl;
        }
    }
    cout << co << endl;
}
