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
selectionsort(const vector<int> a)
{
    vector<int> work(a);

    int count = 0;
    for (auto it1 = work.begin(); it1 != work.end(); it1++) {
        auto mini = it1;
        for (auto it2 = it1; it2 != work.end(); it2++) {
            if (*it2 < *mini) {
                mini = it2;
            }
        }
        if (it1 != mini) {
            iter_swap(it1, mini);
            count++;
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
    selectionsort(A);

    return 0;
}
