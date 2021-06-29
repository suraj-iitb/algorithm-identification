#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[100],cnt=0,minj;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        minj = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(minj != i){
            cnt++;
        }
        swap(a[i],a[minj]);
    }
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i!=n-1){
            cout << ' ';
        }
    }
    cout << endl;
    cout << cnt << endl;
}
