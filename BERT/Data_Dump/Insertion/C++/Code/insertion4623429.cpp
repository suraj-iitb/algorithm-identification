#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
        cout << a.at(i);
        if(i!=n-1)cout << " ";
    }
    for(int i=1;i<n;i++){
        int j=i-1;
        int v=a[i];
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        cout << endl;
        for(int k=0;k<n;k++){
            if(k>0)cout << " ";
            cout << a[k];
        }
    }
    cout << endl;
}
