#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> da(n);
    int k=0;
    for(int i=0;i<n;i++){
        cin >> da[i];
        k=max(k,da[i]);
    }
    vector<int> c(k+1);
    for(int i=0;i<n;i++){
        c[da[i]]++;
    }
    vector<int> ans(n,-1);
    for(int i=0;i<k;i++){
        c[i+1]=c[i]+c[i+1];
    }
    for(int i=n-1;i>-1;i--){
        ans[c[da[i]]-1]=da[i];
        c[da[i]]--;
    }
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout <<ans[i] << endl;
        }
        else{
            cout <<ans[i] << ' ';
        }
    }
}
