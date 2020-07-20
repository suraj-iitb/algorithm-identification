#include <iostream>
#include <algorithm>

using namespace std;

int bubblesort(int n,int a[])
{   
    int count = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j = n-1 ;i<j;j--)
        {
            if(a[j-1]>a[j])
            {
                swap(a[j-1],a[j]);
                count++;
            }
        }
    }

    return count;

}

static const int MAX = 100;

int main()
{
    int n = 0,a[MAX],cnt = -1;
    cin >> n;

    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
    }

    cnt = bubblesort(n,a);

    for(int i = 0;i<n;i++)
    {   
        if(i>0)
        {
            cout << " ";
        }
        cout << a[i];

    }

    cout << "\n";

    cout << cnt << endl;

    return 0;


    

}
