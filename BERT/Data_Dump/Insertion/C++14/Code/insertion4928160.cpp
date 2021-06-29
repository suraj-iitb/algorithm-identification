#include<iostream>
using ll = long long;
using namespace std;

int main(){
    int n,v,i,j;
    cin >> n;
    int A[n];
    for(i=0;i<n;i++){
        cin >> A[i];
    }
    for(i=0;i<n;i++){
        v = A[i];
        j = i - 1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(int z=0;z<n-1;z++){
            cout << A[z] <<" ";
            
        }
        cout << A[n-1] <<"\n";
    }
    return 0;
}

