
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

    print_func(A, GET_ARRAY_SIZE(A));

    int v;
    int tmp;
    for (int i = 1; i < N; ++i) {
        v = A[i];
        tmp = i;
        for (int j = i-1; j >= 0 && A[j] > v ; --j) {
            A[j+1] = A[j];
            tmp = j;
        }
        A[tmp] = v;

        print_func(A, GET_ARRAY_SIZE(A));
    }

}
