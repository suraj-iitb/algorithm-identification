#include <iostream>

using namespace std;

int selectionsort(int n,int a[])
{
    int count = 0;

    for(int i = 0; i<n ;i++)
    {   
        int minv = i;
        
        for(int j = i ;j<n;j++)
        {   
            if(a[minv] > a[j])
            {
                minv = j;
            }

        }

            int temp = a[minv];
            a[minv] = a[i];
            a[i] = temp;
        if(i != minv)
        {
           
            count++;
        }
        
        
    }
    return count;
}

static const int MAX = 100;

int main()
{
    int n,a[MAX],count;
    
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
    }

    count = selectionsort(n,a);

    for(int i = 0;i<n ;i++)
    {
        if(i>0)
        {
            cout << " ";
        }
        cout << a[i];
    }

    cout << endl;

    cout << count << endl;

    return 0;
}
