#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,cnt = 0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    for(int i=0;i<n;i++){
        int minj = i;
        for(int j=i;j<n;j++)
            if(a[j] < a[minj])minj = j;
        swap(a[i], a[minj]);
        if(minj != i)cnt++;
    }

    for(int i=0;i<n;i++){
        cout << a[i];
        if(i != n-1)cout << " ";
        else cout << endl;
    }
    cout << cnt << endl;

    return 0;
}
