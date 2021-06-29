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

    int count = 0;
    int minj = 0;

    for (int i = 0; i < N; i++) {
        minj = i;

        for (int j = i; j < N; j++) {
            if(vec.at(j) < vec.at(minj)) {
                minj = j;
            }
        }

        if(i != minj) {
            swap(vec.at(i), vec.at(minj));

            count++;
        }
        
    }

    for (int k = 0; k < N; k++) {
        if(k == N - 1) {
            cout << vec.at(k);
        } else {
            cout << vec.at(k) << " ";
        }
    }

    cout << endl;

    cout << count << endl;

    return 0;
}

