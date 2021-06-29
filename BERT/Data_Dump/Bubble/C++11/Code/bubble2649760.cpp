#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bubble(int n,vector<int> v){
    int times=0;

    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(v[j-1]>v[j]) {
                swap(v[j-1],v[j]);
                times++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i] << (i < n-1?' ':'\n');
    }
    return times;
}

int main(){
    int n,tmp;
    vector<int> v;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << bubble(n,v) << endl;

    return 0;
}
