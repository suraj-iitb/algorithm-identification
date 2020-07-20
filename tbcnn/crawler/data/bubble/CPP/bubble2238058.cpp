
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
    for (int j = 0; j < N; ++j) {
        cin >> A[j];
    }


    bool flag = true;
    int tmp, cnt=0;
    while(flag) {
        flag = false;
        for (int i = N - 1; i > 0; --i) {
            if (A[i] < A[i - 1]) {
                tmp = A[i - 1];
                A[i - 1] = A[i];
                A[i] = tmp;


                flag = true;
                cnt++;
            }
        }
    }

    print_func(A, GET_ARRAY_SIZE(A));
    cout << cnt << endl;
}
