#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it;
        if ((it+1) != v.end())
            cout << " ";
    }
    cout << endl;
}

int main() {
    int len;
    vector<int> v;

    cin >> len;
    for (int i; i < len; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 1; i < v.size(); i++) {
        print_vec(v);

        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
    print_vec(v);

    return 0;
}
