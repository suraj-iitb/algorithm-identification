#pragma region
#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, m, n) for (int i = m; i < n; i++)
#define all(v) v.begin(), v.end()
#define INF 1e9
#define EPS 1e-10
using namespace std;
typedef long long ll;
#pragma endregion


void printout(vector<int> v, int N){
    rep(i, N){
        if(i > 0){
            cout << " ";
        }

        cout << v.at(i);
    }

    cout << endl;
}

void insertionSort(vector<int> &v, int &N){
    int k,j;
    rep1(i, N - 1){

        k = v.at(i);
        j = i - 1;

        while(j >= 0 && v.at(j) > k){
            v.at(j + 1) = v.at(j);
            j--;
        }
        v.at(j + 1) = k;

       printout(v, N);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);

    rep(i, N){
        cin >> v.at(i);
    }

    printout(v,N);
    insertionSort(v, N);
}
