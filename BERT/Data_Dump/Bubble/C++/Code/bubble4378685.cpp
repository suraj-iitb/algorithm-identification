#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void output(vector<int> x){
    int y = x.size();
    for(int i=0;i<y-1;i++){
        cout << x[i] << " ";
    }
    cout << x[y-1] << endl;;
}

void bubblesort(vector<int> x){
    int n = x.size();
    bool flag = true;
    int cnt = 0;
    while(flag){
        flag = false;
        for(int j = n-1;j>=1;j--){
            if(x[j] < x[j-1]){
                swap(x[j],x[j-1]);
                flag = 1;
                cnt ++ ;
            }
        }
    }
    output(x);
    cout << cnt << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    bubblesort(a);
}
