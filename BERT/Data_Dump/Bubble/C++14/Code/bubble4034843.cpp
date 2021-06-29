#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    int a[n];
    int count = 0;
    for(auto &i:a) cin >> i;
    bool flag = true;
    while(flag){
        flag = false;
        for(int j=n-1;j>=1;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag = true;
                count++;
            }
        }
    }
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
    cout << a[n-1] << endl << count << endl;
}
