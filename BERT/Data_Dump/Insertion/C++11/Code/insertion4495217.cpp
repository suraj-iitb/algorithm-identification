#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <cmath>
#include <sstream>

typedef long long ll;

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(v[j] > v[j + 1]) {
                int a = v[j + 1];
                v[j + 1] = v[j];
                v[j] = a;
            }
        }
        string s = "";
        for(int j = 0; j < n; j++){
            s += to_string(v[j]);
            if(j != n - 1) s += " ";
        }
        cout << s << endl;
    }
}


