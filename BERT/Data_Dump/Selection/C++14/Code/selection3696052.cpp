#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,minj,v,count=0;
    cin >> n;

    int a[n];
    for(int i = 0;i<n;i++)cin>>a[i];

    
    for(int i=0;i<n;i++){
        minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;                
            }
        }
        if(minj != i){
                v=a[minj];
                a[minj]=a[i];
                a[i]=v;
                count++;
        }
    }

    cout<<a[0];
    for(int i=1;i<n;i++){
        cout<<" "<<a[i];
    }
    cout << endl << count << endl;
}
