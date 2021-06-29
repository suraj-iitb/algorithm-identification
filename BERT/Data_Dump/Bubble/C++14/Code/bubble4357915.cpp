#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        
        for(int j = n - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                cnt++;
                swap(a[j],a[j - 1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << (i != n - 1 ? " ": "\n");
    }
    cout << cnt << endl;
}
