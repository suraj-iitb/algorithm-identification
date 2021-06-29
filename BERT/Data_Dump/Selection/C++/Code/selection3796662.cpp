#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define ct(string) cout << string << endl

int n, c = 0;

void selectionSort(vector<int> &vec) {
    rep(i,n) {
        int minn = i;
        for (int j=i; j<n; j++) { //i以降で最小の
            if (vec.at(j) < vec.at(minn)) minn = j;
        }
        swap(vec.at(i), vec.at(minn));
        if (i != minn) c++;
    }
}

void cout_vector(vector<int> vec) {
    rep(i,n-1) {
        cout << vec.at(i) << " ";
    }
    ct(vec.at(n-1));
}

int main() {
    cin >> n;
    vector<int> vec(n);
    rep(i,n) cin >> vec.at(i);
    selectionSort(vec);
    cout_vector(vec);
    ct(c);
}
