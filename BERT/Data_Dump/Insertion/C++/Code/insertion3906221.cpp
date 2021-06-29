#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(){
    int N;
    vector<int> v;
    cin >> N;
    v.resize(N);
    for(int i=0; i<N; i++)
        cin >> v[i];

    for(int i=1; i<N; i++){
        for(int k=0; k<N; k++){
            cout << v[k];
            if(v[k] != v.back()) cout << ' ';
        }
        cout << endl;

        int num = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > num){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = num;
    }
    for(int k=0; k<N; k++){
        cout << v[k];
        if(v[k] != v.back()) cout << ' ';
    }
    cout << endl;

    return 0;
}
