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
        int mini = i;
        for (int j = i; j < N; j++) {
            if (p[j] < p[mini]) mini = j;
        }
        if (i != mini) {
            int tmp2 = p[i];
            p[i] = p[mini];
            p[mini] = tmp2;
            count++;
        }
    }
    for (int i = 0; i < N-1; i++) {
        cout << p[i] << " ";
    }
    cout << p[N-1] << endl;
    cout << count << endl;
    return 0;
}
