#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main(){

    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int swap_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; i < j; j--) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                swap_count++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << A[i] << " ";
        } else {
            cout << A[i] << endl;
        }        
    }
    cout << swap_count << endl;

    return 0;
}

