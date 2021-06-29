#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    
    cin >> n;
    vector<int> a(n);

    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int k=0;k<n;k++){
        if(k==n-1){
            cout << a[k] << endl;
            break;
        }
        cout << a[k] << " ";
    }

    for(int i=1;i<n;i++){
        
        int key = a[i];
        int j=i-1;
        while(j>=0&&(a[j+1]<a[j])){
            a[j+1] = a[j];
            a[j] = key;
            j--;
        }

        for(int k=0;k<n;k++){
            if(k==n-1){
                cout << a[k] << endl;
                break;
            }
            cout << a[k] << " ";
        }
    }
    
    return 0;
}
