#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define ct(string) cout << string << endl

void cout_vector(vector<int> vec, int n) {
    rep(i,n-1) {
        cout << vec.at(i) << " ";
    }
    ct(vec.at(n-1));
}

void bubbleSort(vector<int> vec, int n) {
    int count=0;
    bool flag=true;
    int i=0;
    while (flag) {
        flag = false;
        for (int j=n-1; j>i; j--) {
            if (vec.at(j) < vec.at(j-1)) {
                swap(vec.at(j), vec.at(j-1));
                flag = true;
                count++;
            }
        }
        i++;
    }
    cout_vector(vec, n);
    ct(count);
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n) cin >> vec.at(i);
    bubbleSort(vec, n);

}
