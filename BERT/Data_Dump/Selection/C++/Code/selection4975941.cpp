#include<iostream>
using namespace std;

int SeSort(int a[], int n){
    int c=0;
    for(int i=0; i<n; i++){
        int minj=i;
        for(int j=i; j<n; j++){
            if(a[minj]>a[j]) minj=j;
        }
        if(i!=minj){
            swap(a[i],a[minj]);
            c++;
        }
    }
    
    return c;
}

int main(){
    int n;
    int a[100]={};
    cin>>n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    int count=SeSort(a,n);
    for(int i=0; i<n; i++){
        if(i) cout << " ";
        cout << a[i];
    }
    cout<<endl<<count<<endl;
}
