#include <iostream>
#include <algorithm>
using namespace std;

void print_array(int n, int a[])
{
    for(int i=0;i<n;i++)
    {
        cout << a[i];
        if(i!=n-1) cout << " ";
    }
    cout << endl;
}

int main()
{
    int n, count=0;
    cin >> n;
    //n=5;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    //a[0]=5;
    //a[1]=3;
    //a[2]=2;
    //a[3]=4;
    //a[4]=1;

    for(int left=0;left<n-1;left++)
    {
        for(int i=n-1;i>left;i--)
        {
            if(a[i-1] > a[i])
            {
                swap(a[i],a[i-1]);
                count++;
            }
        }
    }
    
    print_array(n, a);
    cout << count << endl;
    
    return 0;
}
