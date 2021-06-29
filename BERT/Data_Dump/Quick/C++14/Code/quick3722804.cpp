#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template<typename T>
int partition(vector<T> &a, int p, int r) {
    T x = a[r];
    int i = p-1;
    for(int j=p; j<r; j++) {
        if(a[j]<=x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

template<typename T>
void quicksort(vector<T> &a, int p, int r) {
    if(p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

struct card {
    string suit;
    int rank;
    card() {}
    //card(string s, int r) : suit(s), rank(r) {}
};

bool operator<(const card &a, const card &b) {
    return a.rank < b.rank;
}
bool operator<=(const card &a, const card &b) {
    return a.rank <= b.rank;
}
bool operator==(const card &a, const card &b) {
    return a.suit == b.suit && a.rank == b.rank;
}

ostream& operator<<(ostream &os, const card &a) {
    os << a.suit << " " << a.rank;
    return os;
}

istream& operator>>(istream &is, card &a) {
    is >> a.suit >> a.rank;
    return is;
}

int main() {
    int n;
    cin >> n;
    vector<card> cs(n);
    for(int i=0; i<n; i++) cin >> cs[i];
    vector<card> copy(cs);
    quicksort(cs, 0, n-1);
    stable_sort(copy.begin(), copy.end());
    cout << (cs==copy ? "Stable" : "Not stable") << endl;
    for(auto&& c : cs) cout << c << endl;
}
