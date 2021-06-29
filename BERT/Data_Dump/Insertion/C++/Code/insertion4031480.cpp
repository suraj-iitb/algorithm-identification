#include<bits/stdc++.h>
using namespace std;
/*
void insersionSort(int *a,int n){
    for(int i=1;i<n-1;i++){
        int p=a[i];
        int j=i-1;
        while(j>=0 && a[j]>p){
            a[j+1]=a[j];
            j--;
        }
        a[j]=p;
        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
    }
}
*/
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) {
        cout << a[i];
        if(i!=n-1)cout << " ";
        else cout << endl;
    }
    
    for(int i=1;i<n;i++){
        int p=a[i];
        int j=i-1;
        while(j>=0 && a[j]>p){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=p;
        for(int i=0;i<n;i++){
            cout << a[i];
            if(i!=n-1)cout << " ";
            else cout << endl;
        } 
    }
    return 0;
}
