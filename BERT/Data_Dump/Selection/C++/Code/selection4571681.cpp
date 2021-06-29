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
    int min;
    int idx;
    int n;
    int cnt = 0;
    cin >> n;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];
    
    for(int i=0;i<n-1;i++){
        min = a[i];
        idx = i;
        for(int j=i+1;j<n;j++){
            if(min > a[j]){
                min = a[j];
                idx = j;
            }
        }
        if(idx != i) cnt++;
        swap(a[idx], a[i]);
    }

    for(int i=0;i<n;i++){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
}
