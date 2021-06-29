
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <deque>

#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))

using namespace std;

void print_func(int *array, int size){
    for (int j = 0; j < size; ++j) {
        cout << ( j ? " " : "" ) << array[j];
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int tmp, minj, cnt=0;
    bool flag;
    for (int i = 0; i < N; ++i) {
        minj = i;
        flag = false;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[minj]) {
                minj = j;
                flag = true;
            }
        }

        if (flag) {
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            cnt++;
        }
    }

    print_func(A, GET_ARRAY_SIZE(A));
    cout << cnt << endl;

}
