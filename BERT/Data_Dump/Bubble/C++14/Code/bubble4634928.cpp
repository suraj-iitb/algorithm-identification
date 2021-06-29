#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    
    int cnt = 0;
    bool f=1;
    while(f){
        f=0;
        for(int j=n-1;j>=1;j--){
            if(a[j]<a[j-1]) swap(a[j],a[j-1]),cnt++,f=1;
        }
    }
    cout << a[0];
    for(int i=1;i<n;i++) cout << " " << a[i];
    cout << endl;
    cout << cnt << endl;
}
