#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int select(int n,vector<int> v){
    int times=0,mindex;

    for(int i=0;i<n;i++){
        mindex = i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[mindex]){
                mindex = j;
            }
        }
        if(i != mindex){
            swap(v[i],v[mindex]);
            times++;
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i] << (i<n-1?' ':'\n');
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
    cout << select(n,v) << endl;

    return 0;
}
