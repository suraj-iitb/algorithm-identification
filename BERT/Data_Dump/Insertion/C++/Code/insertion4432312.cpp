#include<vector>
#include<iostream>
using namespace std;

int main(){
    vector<long long> v;
    long long n;
    long long x;
    long long temp;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i=0; i < v.size()-1; i++){
        cout << v[i] << " ";
    }
    cout << v[v.size()-1] << endl;
    for(int i=0; i < n-1; i++){
        
        for(int j=i+1; j>0; j--){
            if(v[j-1]>v[j]){
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
                continue;
            }
            break;
        }
        for(int i=0; i < v.size()-1; i++){
            cout << v[i] << " ";
        }
        cout << v[v.size()-1] << endl;
    }

}

