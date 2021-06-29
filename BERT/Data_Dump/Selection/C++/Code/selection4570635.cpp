#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, n_swaps=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    //Selection sort
    int m, temp;
    for(int i=0; i<n; i++){
        m = i;
        for(int j=i+1; j<n; j++){
            if(v[j] < v[m]) m=j;
        }
        if(m!=i){
            temp = v[m];
            v[m] = v[i];
            v[i] = temp;
            n_swaps++; 
        }
    }
    
    for(int i=0; i<n; i++) cout << v[i] << " \n"[i==n-1];
    cout << n_swaps << endl;
    
    return 0;
}
