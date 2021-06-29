#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }

    //sort
    for(int i = 0;i < n;i++)
    {
        int min = i;
        for(int j = i;j < n;j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        if(min != i)
        {
            swap(a[i], a[min]);
            cnt++;
        }
    }

    for(int i = 0;i < n;i++)
    {
        if(i == n-1)
            cout<<a[i]<<endl;
        else
            cout<<a[i]<<" ";
    }
    cout<<cnt<<endl;
}
