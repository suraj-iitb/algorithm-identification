#include <bits/stdc++.h>
using namespace std;
 
int bubblesort(vector<int> &a){
    int cnt=0,n=a.size(),flag=1;
    while(flag){
        flag=0;
        for(int j=n-1;j>0;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=1;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans=bubblesort(a);
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
    cout << endl;
    cout << ans << endl;
}
