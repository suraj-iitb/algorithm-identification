#include <iostream>
using namespace std;

int BS(int a[],int n){
    int ans = 0;
    bool flag = 1;
    for(int i =0;flag;i++){
        flag = 0;
        for(int j =n-1;j>= i+1;j--){
            if(a[j]<a[j-1]){
                int k = a[j];
                a[j] = a[j-1];
                a[j-1] = k;
                flag=1;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    int aa[100];
    cin >> n;
    for(int i = 0;i<n;i++){
        int v;
        cin >> v;
        aa[i] = v;
    }
    int ans = BS(aa,n);
    for(int h =0;h<n;h++){
        if(h != n-1){
            cout << aa[h] << ' ';
        }else{
            cout << aa[h] << endl;
        }
    }
    cout << ans << endl;
}
