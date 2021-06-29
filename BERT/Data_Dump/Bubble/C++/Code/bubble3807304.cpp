#include<iostream>
using namespace std;

void trace(int a[],int n){
    for(int i=0; i<n; i++){
        if(i>0)cout << " ";
        cout << a[i];
    }
    cout << endl;
    return;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)cin >> a[i];
    bool flag = 1;
    int sw=0;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j=n-1; j>i; j--){
            flag = 1;
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                sw++;
            }
        }
    }
    trace(a, n);
    cout << sw << endl;
    return 0;
}
