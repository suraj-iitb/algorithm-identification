#include <iostream>
using namespace std;

void insertionSort (int a[100] , int n) {
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < n-1 ; j++){
        cout<<a[j]<<" ";
    }
    cout<< a[n-1] <<endl;
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}

int main(void){
    // Your code here!
    int n,a[100];
    cin>>n;
    for(int i = 0 ; i < n ; i++ ){
        cin>>a[i];
    }
    insertionSort(a,n);
    
    for(int i = 0 ; i < n-1 ; i++){
        cout<<a[i]<<" ";
    }
    cout<< a[n-1] <<endl;
}
