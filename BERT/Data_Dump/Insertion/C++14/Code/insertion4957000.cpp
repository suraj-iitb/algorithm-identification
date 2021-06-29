#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

int n;
int a[100];
void print(){
    for(int i = 0;i < n;i++){
        if(i < n-1){
            cout << a[i] << " ";
        }else{
            cout << a[i] << endl;
        }
    }
}

int main() {
    cin >> n; for(int i = 0;i < n;i++) cin >> a[i];
    print();
    for(int i = 1;i < n;i++){
        int j = i-1;
        int x = a[i];
        while(j >= 0 && x < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
        print();
    }
}


