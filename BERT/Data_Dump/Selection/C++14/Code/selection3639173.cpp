#include<iostream>
using namespace std;

void f(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int g(int *a,int n){
    int cnt = 0;
    bool flag =true;
    for(int i=0;i<n;i++){
        flag = false;
        int mini=i;
        for(int j=i;j<n;j++){
            if(*(a+j)<*(a+mini)){
                mini = j;
            }
        }
        if(mini != i){
            flag = true;
            f(a+i,a+mini);
        }
        if(flag)cnt++;
    }
    return cnt;
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    int res;
    res = g(a,n);
    for(int i=0; i<n; i++){
        if(i){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    cout << res << endl;
    return 0;
}
