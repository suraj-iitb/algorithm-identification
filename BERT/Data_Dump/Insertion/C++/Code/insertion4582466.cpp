#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int N;cin >> N;
    vector<int> p(110,0);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        cout << p[0];
        for (int j = 1; j < N; j++)
        {
            cout << " " << p[j];
        }
        cout << endl;

        int key = p[i+1];
        int k = i;
        while (k >= 0 && p[k] > key)
        {
            int tmp = p[k+1];
            p[k+1] = p[k];
            p[k] = tmp;
            k--;
        }
    }
    
}
