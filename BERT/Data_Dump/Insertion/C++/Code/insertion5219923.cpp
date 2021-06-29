#include <bits/stdc++.h>
using namespace std;


int main(){
int n;
cin >> n;
vector<int> A(n);
for (int i = 0; i < n; i++)
{
    cin >> A[i];
}
for (int i = 0; i < n; i++)
{
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v)//これポイントはvは変動しないということか
    {
        A[j+1] = A[j];
        j--;
        A[j+1] = v;
    }
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if(i == n-1)break;
        cout << " ";
    }
    cout << endl;  
}


return 0;
}
