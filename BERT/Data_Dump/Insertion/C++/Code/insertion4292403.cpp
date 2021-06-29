#include <iostream>
#include <vector> 
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    
    cin >> N;

    vector<int> vec(N);

    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }

    for (int i = 0; i < N; i++) {
        int v = vec.at(i);
        int j = i - 1;

        while(j >= 0 && vec.at(j) > v) {
            vec.at(j + 1) = vec.at(j);
            j--;
        }

        vec.at(j + 1) = v;

        for (int k = 0; k < N; k++) {

            if(k == N - 1) {
                cout << vec.at(k);
            } else {
                cout << vec.at(k) << " ";
            }
        }
        cout << endl;
    }

    return 0;

}

