#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n, x;
    long long temp;
    long long temp2;
    long long count=0;
    vector<long long> v;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i=0; i<n-1; i++){
        temp = i;
        for(int j=i+1;j<n;j++){
            if(v[temp]>v[j]){
                temp = j;
            }
        }
        if(i!=temp){
            count = count + 1;
        }
        temp2 = v[temp];
        v[temp] = v[i];
        v[i] = temp2;

    }

    for(int i=0; i<v.size()-1; i++){
        cout << v[i] << " ";
    }
    cout << v[v.size()-1] << endl;
    cout << count << endl;
    return 0;
}
