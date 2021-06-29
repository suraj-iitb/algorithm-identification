#include <bits/stdc++.h>
using namespace std;


int main(){
int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++)
{
    cin >> a[i];
}

bool b = 1;
int cnt = 0;
while (b)
{
    b = 0;
    for (int j = n-1; j > 0; j--)
    {
        if (a[j] < a[j-1])
        {
            int v = a[j];
            int w = a[j-1];
            a[j] = w;
            a[j-1] = v;
            b = 1;
            cnt++;
        }
        
    }
    
}
for (int i = 0; i < n; i++)
{
    cout << a[i];
    if (i == n-1)
    {
        cout << endl;
        break;
    }
    cout << " ";
    
}

cout << cnt << endl;
return 0;
}
