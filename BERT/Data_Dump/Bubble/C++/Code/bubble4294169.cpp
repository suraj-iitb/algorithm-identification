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

int bubbleSort(vector<int> &v, int N){
    bool flag = true;
    int val,count = 0;

    while(flag){
        flag = 0;
        
        repr(j, N - 1){
            if(j == 0){
                break;
            }

            if(v.at(j) < v.at(j - 1)){
                val = v.at(j - 1);
                v.at(j - 1) = v.at(j);
                v.at(j) = val;
                flag = true;
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int N,count;
    cin >> N;
    vector<int> v(N);
 
    rep(i, N){
        cin >> v.at(i);
    }

    count = bubbleSort(v, N);

    rep(i, N){
        if(i > 0){
            cout << " ";
        }
        cout << v.at(i);
    }

    cout << endl << count << endl;
}
