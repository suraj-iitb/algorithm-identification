#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    int N; cin >> N;
    vector<int> v;
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        v.push_back(a);
    }
    
    for(int i = 1; i <= N-1; i++){
        cout << v[0];
        for(int j = 1; j < N; j++){
            cout << " " << v[j];
        }
        cout << endl;
        int j = i-1;
        int w = v[i];
        while(j >= 0 && v[j] > w){
            v[j + 1] = v[j];
            j--;
            v[j + 1] = w;
        }
        
    }
    cout << v[0];
    for(int i = 1; i < N; i++){
        cout << " " << v[i];
    }
    cout << endl;
    return 0;
}
    
