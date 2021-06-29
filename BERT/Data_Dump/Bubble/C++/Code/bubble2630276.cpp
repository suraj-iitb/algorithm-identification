#include <iostream>
#include<algorithm>
using namespace std;
static const int MAX = 105;

/*

*/
int bubbleSort(int a[],int m)
{
    int k = 0;
    int flag = 1;
    for(int i = 0;flag;i++)
    {
        flag = 0;
        for(int j = m-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=1;
                k++;
            }
        }
    }
    return k;
}

int main()
{
    int n,a[MAX],m=0;
    cin>>n;
    for(int i =0; i<n; i++)
    {
        cin>>a[i];
    }
    //cout<<m;
    m = bubbleSort(a,n);

    for(int i =0;i<n;i++)
    {
        if(i)
        {cout<<" ";}
        cout<<a[i];
    }
    cout<<endl;
    cout<<m<<endl;

    return 0;
}
