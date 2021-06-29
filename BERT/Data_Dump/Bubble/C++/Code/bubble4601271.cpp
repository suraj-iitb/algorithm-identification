#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    vector<int> a(N);
    bool flag = 1;

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < N-1; i++)
        {
            if (a[i] > a[i+1])
            {
                int tmp = a[i+1];
                a[i+1] = a[i];
                a[i] = tmp;
                count++;
                flag = 1;
            }
        }
    }
    

    cout << a[0];
    for (int i = 1; i < N; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
    cout << count << endl;

}
