#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define ct(string) cout << string << endl

void cout_vector(vector<int>, int);

void insertion_sort(vector<int> vec, int n) {
    rep(i,n-1) {
        int v = vec.at(i+1);
        int j = i;
        while (j >= 0 && vec.at(j) > v) {
            vec.at(j+1) = vec.at(j);
            j--;
        }
        vec.at(j+1) = v;
        cout_vector(vec, n);
    }
}

void cout_vector(vector<int> vec, int n) {
    rep(i,n-1) {
        cout << vec.at(i) << " ";
    }
    ct(vec.at(n-1));
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n) cin >> vec.at(i);
    cout_vector(vec, n);
    insertion_sort(vec, n);
}
