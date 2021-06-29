#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    for(int i=0; i<n; i++){
        int cc=i+1;
        while(cc--){
            if(v[cc-1]>v[cc]){
                swap(v[cc-1],v[cc]);
            }
        }
        for(int j=0; j<n; j++){
            if(j!=n-1)           cout << v[j] << " ";
            else cout << v[j] << endl;
        }
    }
    return 0;
}
