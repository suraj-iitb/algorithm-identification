#include<vector>
#include<iostream>
using namespace std;

int main(){
    vector<long long> v;
    long long n;
    cin >> n;
    long long x;
    long long count=0;
    long long temp;
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(v[j-1]>v[j]){
                count = count + 1;
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        cout << v[i] << " ";
    }
    cout << v[n-1] << endl;
    cout << count << endl;
    return 0;
}
