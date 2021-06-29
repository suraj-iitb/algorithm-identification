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

int selectionSort(vector<int> &v, int N){
    int minj,val,count = 0;

    rep(i, N - 1){
        minj = i;
        rep2(j, i, N){
            if(v.at(j) < v.at(minj)){
                minj = j;
            }
        }

        val = v.at(i);
        v.at(i) = v.at(minj);
        v.at(minj) = val;

        if(i != minj){
            count++;
        }
    }

    return count;
}

int main()
{
    int N,count = 0;
    cin >> N;
    vector<int> v(N);

    rep(i, N){
        cin >> v.at(i);
    }

    count = selectionSort(v, N);

    rep(i, N){
        if(i > 0){
            cout << " ";
        }
        cout << v.at(i);
    }

    cout << endl << count << endl;
}
