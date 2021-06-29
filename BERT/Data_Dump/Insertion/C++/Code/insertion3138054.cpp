#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX = 101;


void trace(int a[],int n)
{
    for(int i = 0 ;i<n;i++)
    {   if(i > 0)
    {
        cout << " ";
    }
        cout << a[i];
    }

    cout << "\n";
}

int main()
{
    int n,a[MAX];

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    trace(a,n);
    for(int i = 1;i < n; i++)
    {
        int temp = a[i];
        int j = i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];  //更新
            j--;
        }
        a[j+1] = temp;

        trace(a,n);

    }
    return 0;
    


}

