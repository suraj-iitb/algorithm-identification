#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    
    int count = 0;
    int minj;
    for(int i = 0;i < n;i++){
        minj  = i;
        for(int j = i;j < n;j++){
            if(a[j] < a[minj]){
                minj = j; 
            }
        }
        if(a[i] != a[minj]){
            count++;
        }
        int x;
        x = a[minj];
        a[minj] = a[i];
        a[i] = x;
        
    }
    for(int i = 0;i < n;i++){
        cout << a[i];
        if(i != n - 1){
            cout << " ";    
        }
    }
    cout << endl << count << endl;
}
