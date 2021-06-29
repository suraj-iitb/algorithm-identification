#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    for (int i = 0; i < N; ++i) {
        auto v = A[i];
        int j = i - 1;
        while(j >= 0 && v < A[j]) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
        ostringstream os;
        for_each(A.begin(), A.end() - 1,
                 [&os](const int& e){
                     os << e << " ";
                 });
        os << *(A.end() - 1);
        cout << os.str() << endl;
    }
    return 0;
}

