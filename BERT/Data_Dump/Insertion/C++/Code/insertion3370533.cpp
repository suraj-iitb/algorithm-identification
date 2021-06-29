#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for (int b=0; b<n; b++){
        cin>>a[b];
    }
    for(int x=0; x<n; x++){
        cout<<a[x];
        if(x!= n-1)cout<<" ";
    }
    cout<<endl;
    for (int i=1; i<n; i++){
        int j=i-1;
        int key=a[i];
        while (j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        for (int m=0; m<n; m++){
                cout<<a[m];
                if(m!=n-1)cout<<" ";
        }
        if(i!=n)
        cout<<endl;
    }
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}

