#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, tmp, count = 0;
    vector<int> p;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        p.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= i+1; j--) {
            if (p[j] < p[j-1]) {
                int tmp2 = p[j];
                p[j] = p[j-1];
                p[j-1] = tmp2;
                count++;
            }
        }
    }
    for (int i = 0; i < N-1; i++) {
        cout << p[i] << " ";
    }
    cout << p[N-1] << endl;
    cout << count << endl;
    return 0;
}
