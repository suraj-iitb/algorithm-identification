#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
#include<queue>
#include<map>

using namespace std;


int main(){
    int cnt = 0;
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];
    
    for(int j=0;j<n-1;j++)
        for(int i=n-1;i>j;i--) {
            if(a[i] < a[i-1]) {
                swap(a[i], a[i-1]);
                cnt++;
            }
        }

    for(int i=0;i<n;i++){
        if(i > 0) {cout  << " ";}
        cout << a[i];
    }

    cout << endl;
    cout << cnt << endl;
}
