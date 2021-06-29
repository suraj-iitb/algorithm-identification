#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    int count = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = N-1; i >= 1; i--)
        {
            if (A.at(i) < A.at(i-1)){
               int temp = A.at(i);
               A.at(i) = A.at(i-1);
               A.at(i-1) = temp;
               flag = true;
               count++;
            }
        }
           
    }

    for (int i = 0; i < N; i++)
    {
        if (i == N-1) cout << A.at(i) << endl;
        else cout << A.at(i) << " ";
    }
    
    cout << count << endl;
}
