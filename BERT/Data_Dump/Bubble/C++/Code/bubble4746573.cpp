#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <algorithm>
#define INF 100000000000000
using namespace std;

int main() {
    long long N;
    long long temp;
    long long cnt=0;
    cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    for(int i=0; i<N-1; i++){
        for(int j=N-1; j > i; j--){
            if(A.at(j) < A.at(j-1)){
                temp = A.at(j);
                A.at(j) = A.at(j-1);
                A.at(j-1) = temp;
                cnt++;
            }
        }
    }
    for(int i=0; i<N-1; i++){
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;
    cout << cnt << endl;
}

