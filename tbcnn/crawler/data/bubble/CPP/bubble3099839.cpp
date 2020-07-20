#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,cnt=0;
cin >> n;
int a[n];
for(int i=0;i<n;i++)
{
cin >> a[i]; 
}

for(int i=0;i<n;i++)
    for(int j=1;j<n;j++)
    {
        if(a[j-1]>a[j])
        {
        swap(a[j-1],a[j]);
        cnt++;
        }
    }
for(int i=0;i<n-1;i++)
{
cout << a[i] << " ";
}
cout << a[n-1];
cout << endl;
cout << cnt << endl;




return 0;
}
