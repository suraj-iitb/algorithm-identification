#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    int a[n];
    int count = 0;
    for(auto &i:a) cin >> i;
    for(int i=0;i<n;i++){
        int minj = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            swap(a[i],a[minj]);
            count++;
        }
    }
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
    cout << a[n-1] << endl << count << endl;
    return 0;
}
