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
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int count=0;
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(a[i], a[minj]);
            count++;
        }
    }
    for(int i=0; i<n; i++){
        if(i!=n-1) cout << a[i] << " ";
        else cout << a[i];
    }
    cout << endl;
    cout << count << endl;
}
