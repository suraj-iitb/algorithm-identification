#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0;i<n-1;i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    for(int i=1; i<n; i++){
        int v = a[i];
        for(int j=i-1; j>=0; j--){
            if(v>=a[j]){
                break;
            }else{
                a[j+1] = a[j];
                a[j] = v;
            }
        }
        for(int j=0;j<n-1;j++){
            cout << a[j] << " ";
        }
        cout << a[n-1] << endl;
    }
    return 0;
}
