#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int> &a, int n){
    int cnt = 0;
for (int i = 0; i < n; i++)
{
    int minj = i;
    for (int j = i + 1; j < n; j++)
    {
        if (a[j] < a[minj])
        {
            minj = j;
        }
    }
    if(minj != i){
    swap(a[i],a[minj]);
    cnt++;
    }
}
return cnt;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt = selectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl << cnt << endl;

return 0;
}
