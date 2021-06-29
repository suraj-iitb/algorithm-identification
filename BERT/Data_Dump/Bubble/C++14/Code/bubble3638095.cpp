#include<iostream>
using namespace std;

void f(int* x,int* y){
    int z = *x;
    *x = *y;
    *y = z;
}

int g(int* u,int n){
    int cnt = 0;
    bool flag = true;
    for(int i=0;flag;i++){
        flag = false;
        for(int j=n-1;j>=i+1;j--){
            if(u[j]<u[j-1]){
                f(u+j,u+j-1);
                flag = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n,res; cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    res = g(a,n);
    for(int i=0; i<n; i++){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << res << endl;
    return 0;
}
