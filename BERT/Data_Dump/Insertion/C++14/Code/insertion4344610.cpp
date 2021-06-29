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
    for (int x = 0; x < N; x++){
            if (x == N-1) cout << A.at(x) << endl;
            else cout << A.at(x) << " ";
        }
    
    for (int i = 1; i < N; i++)
    {   int v = A.at(i);int j = i-1;
        while (j >= 0 and A.at(j) > v)
        {
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = v;
        for (int x = 0; x < N; x++)
        {
            if (x == N-1) cout << A.at(x) << endl;
            else cout << A.at(x) << " ";
        }
        
    }
    
}
