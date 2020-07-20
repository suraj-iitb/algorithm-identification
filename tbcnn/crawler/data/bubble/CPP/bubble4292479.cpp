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

    int flag = 1;
    int count = 0;

    while(flag) {

        flag = 0;
        for (int j = N - 1; j > 0; j--) {
            if(vec.at(j) < vec.at(j - 1)) {
                int temp = vec.at(j);
                vec.at(j) = vec.at(j - 1);
                vec.at(j - 1) = temp;

                flag = 1;

                count ++;
            }
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

