#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    
    int cnt=0;
    
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(a[j]>a[j+1]){
                a[j]^=a[j+1]^=a[j]^=a[j+1];
                cnt++;
            }
        }
    }
    
    cout << a[0];
    for(int i=1;i<n;++i) cout <<" " << a[i];
    cout << endl;
    cout << cnt << endl;
}
