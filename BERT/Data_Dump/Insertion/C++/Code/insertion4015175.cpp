#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i!=n-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    for(int i=1;i<n;i++){
        int v = a[i];
        int j = i-1;
        for(;j>=0 && a[j] > v;j--){
            a[j+1] = a[j];
        }
        a[j+1] = v;
        for(int i=0;i<n;i++){
            cout << a[i];
            if(i!=n-1){
                cout << " ";
            }else{
                cout << endl;
            }
        }
    }
}
