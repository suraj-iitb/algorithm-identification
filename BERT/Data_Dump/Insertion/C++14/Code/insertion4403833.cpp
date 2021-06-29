#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

void insertionSort(int A[], int N){
    for(int i=1; i<N; i++){
        int v = A[i];
        int j = i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        rep(k,N){
            cout << A[k];
            if(k != N-1) cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N; cin >> N;
    int A[N];
    rep(i,N){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    rep(k,N){
        cout << A[k];
        if(k != N-1) cout << " ";
    }
    cout << endl;
    insertionSort(A, N);
}
