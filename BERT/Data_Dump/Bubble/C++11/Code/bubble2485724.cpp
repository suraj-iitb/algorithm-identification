/**
 *  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

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
bubblesort(const vector<int> a)
{
    vector<int> work(a);

    bool flag = true;
    int count = 0;
    while (flag) {
        flag = false;
        for (auto it = work.rbegin(); it != work.rend(); it++) {
            auto nit = next(it);
            if (*it < *nit) {
                iter_swap(nit, it);
                flag = true;
                count++;
            }
        }
    }
    printv(work);
    cout << count << endl;
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
    bubblesort(A);

    return 0;
}
