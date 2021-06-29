/**
 *  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void
printv(const vector<int> a)
{
    stringstream ss;
    for (auto it = a.cbegin(); it != a.cend(); it++) {
        if (it != a.begin()) {
            ss << ' ';
        }
        ss << *it;
    }
    cout << ss.str() << endl;
}

void
trace(const vector<int> a)
{
    vector<int> work(a);

    for (int i = 1; i < work.size(); i++) {
        int j = i - 1;
        int key = work[i];
        while (j >= 0 && work[j] > key) {
            work[ j + 1 ] = work[j];
            j--;
        }
        work[ j + 1 ] = key;
        printv(work);
    }
}

int
main()
{
    int N;
    cin >> N; cin.ignore();

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i]; cin.ignore();
    }
    printv(A);

    trace(A);

    return 0;
}
