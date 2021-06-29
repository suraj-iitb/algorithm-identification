#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    vector<int> a(N);

    int ct = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        int minv = 110;
        int minid = -1;
        for (int j = i; j < N; j++)
        {
            if (a[j] < minv)
            {
                minv = a[j];
                minid = j;
            }
            
        }

        if (i != minid)
        {
            int tmp = a[i];
            a[i] = a[minid];
            a[minid] = tmp;
            ct++;
        }
    }

    cout << a[0];
    for (int i = 1; i < N; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
    cout << ct << endl;

}
