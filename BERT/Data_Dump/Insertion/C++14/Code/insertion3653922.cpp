#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
typedef long long ll;
typedef int64_t in;
using namespace std;
#define INF 1000000007


int main() {
	int n;
    int j,v;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i==n-1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
    for(int i=1; i<n; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
            a[j+1] = v;
        }
        for(int k=0; k<n; k++){
            if(k==n-1) cout << a[k] << endl;
            else cout << a[k] << " ";
        }
    }
}
