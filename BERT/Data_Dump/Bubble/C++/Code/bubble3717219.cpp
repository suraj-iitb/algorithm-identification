#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <limits>
using namespace std;

//static const int MAX = 1000;
int main(){
    int N;
    cin >> N;
    int A[100];
    for (int i=0;i<N;i++) cin >> A[i];
    
    bool loop = true;
    int count = 0;
    while (loop) {
        loop = false;
        for (int i=N-1;i>=1;i--){
            int v = A[i];
            if (v < A[i-1]) {
                A[i] = A[i-1];
                A[i-1] = v;
                count++;
                loop = true;
            }
        }
    }
    cout << A[0];
    for (int i=1;i<N;i++) cout << " " << A[i];
    cout << endl;
    cout << count << endl;
}

