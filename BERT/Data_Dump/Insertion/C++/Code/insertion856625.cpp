#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int seq[100];
    for (int i=0; i<n; ++i) {
        cin >> seq[i];
    }

    for (int i=0; i<n; ++i) {
        int key = seq[i];
        int j;
        for (j=i; j>=1; --j) {
            seq[j] = seq[j-1];
            if (key >= seq[j]) {
                break;
            }
        }
        seq[j] = key;

        //trace:start
        for (int k=0; k<n; ++k) {
            if (k == 0) {
                cout << seq[k];
            } else {
                cout << " " << seq[k];
            }
        }
        cout << endl;
        //trace:end
    }

    return 0;
}
