//选择排序
#include <iostream>

using namespace std;

int main(){
    int n;
    int a[100];

    cin>>n;
    for(int i=0; i<n;++i)
        cin>>a[i];

    int count=0;
    for(int i=0;i<n;++i)
    {
        int minIndex=i;
        for(int j=i;j<n;++j)
        {
            if(a[minIndex]>a[j])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            int temp=a[i];
            a[i]=a[minIndex];
            a[minIndex]=temp;
            count++;
        }
    }

    for(int i=0;i<n;++i)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl<<count<<endl;
    return 0;
}

