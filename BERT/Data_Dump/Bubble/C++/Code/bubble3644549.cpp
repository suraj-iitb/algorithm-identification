#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    int flag = 1;
    int count = 0;
    while(flag){
        flag = 0;
        for(int i = 0;i < n - 1;i++){
            if(a[i] > a[i + 1]){
                int x;
                x = a[i];
                a[i] = a[i + 1];
                a[i + 1] = x;
                flag = 1;
                count++;
            }
        }
    }
    for(int i = 0;i < n;i++){
        cout << a[i];
        if(i != n - 1){
            cout << " ";
        }
    }
    cout << endl << count << endl;
}
