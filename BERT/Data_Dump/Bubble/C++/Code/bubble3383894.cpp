#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    bool flag = true;
    int count = 0;
    while(flag)
    {
        flag = false;
        for(int j = n-1; j>0; --j)
        {
            if(a[j] < a[j-1])
            {
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
                flag = true;
                ++count;
            }
                
        }
    }
    for(int k=0;k<n;++k)
    {
        cout << a[k];
        if(k==n-1)
            cout << endl;
        else
            cout << " ";
    }
    cout << count << endl;

}

