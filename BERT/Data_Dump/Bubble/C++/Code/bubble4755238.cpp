#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }
    bool flag = 1;
    int count = 0;
    //flagでバブルソート 
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = N-1; j >= i+1; j--) {
            if (vec.at(j) < vec.at(j-1)) {
                swap (vec.at(j), vec.at(j-1));
                flag = 1;
                count++;
            }
        }
    }
    for (int i = 0; i < N-1; i++) {
        cout << vec.at(i) << " ";
    }
    cout << vec.at(N-1) << endl;
    cout << count << endl;
}
