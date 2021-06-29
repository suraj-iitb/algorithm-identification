#include<iostream>
#include<vector>
using namespace std;
#define F(i,s,e) for(int i=s;i<e;++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n,0);
    F(i,0,n) cin >> a[i];
    F(i,0,n){
        cout << a[i];
        if(i!=n-1) cout << ' ';
    }
    cout << endl;
    F(i,1,n){
        int k=a[i];
        int j=i;
        while(j>0 && a[j-1]>k){
            a[j]=a[j-1];
            --j;
        }
        a[j]=k;
        F(i,0,n){
            cout << a[i];
            if(i!=n-1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
