#include<iostream>
#include<algorithm>
using namespace std;

void Print(int a[], int n){
    for(int k=0; k<n; k++){
            if(k!=n-1) cout << a[k] << " ";
            else cout << a[k] <<endl;
        }
}

void InsertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        int v=a[i];
        int j=i-1;
        while(a[j]>v && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        
        Print(a,n);
    }
}

int main(){
    int n;
    cin >> n;
    int a[1100]={};
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    Print(a,n);
    InsertionSort(a,n);
}
