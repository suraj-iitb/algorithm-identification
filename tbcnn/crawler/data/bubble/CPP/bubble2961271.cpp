//冒泡排序
#include <iostream>

using namespace std;

void trace(int a[], int N, int count){

    for(int i=0; i<N;++i)
    {
        if(i>0)
            cout<<" ";
        cout<<a[i];
    }

    cout<<"\n"<<count<<endl;
}
int main(){
    int n;
    int a[100];

    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>a[i];

    int count =0;
    bool flag=1;

    for(int i=0;i<n-1;++i)
    {
        if(flag)
            flag=0;
        else
        {
            trace(a,n,count);
            return 0;
        }
        for(int j=0;j<n-i-1;++j)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                count++;
                flag=1;
            }
        }
    }

    trace(a,n,count);
    return 0;
}

