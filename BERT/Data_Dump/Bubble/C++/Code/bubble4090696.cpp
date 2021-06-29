#include<iostream>

using namespace std;

int main(){
    int n,b,c,d;
    int a[100];
    b = 1;
    d = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n - b;j++){
            if(a[j] > a[j+1]){
                c = a[j];
                a[j] = a[j+1];
                a[j+1] = c;
                d = d + 1;
            }
            
        }
        b=b+1;
    }
    for (int i = 0;i < n;i++){
        cout << a[i];
        if(i<n-1){
            cout<<" ";
        }
    }
    cout << endl;
    cout << d<<endl;
}

