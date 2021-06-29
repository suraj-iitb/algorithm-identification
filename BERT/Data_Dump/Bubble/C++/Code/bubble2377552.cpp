#include <iostream>

using namespace std;

int a[100];
int n;

int main()
{
    cin>>n;
    int i,j,countnum=0;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                countnum++;
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<a[i];
        if(i!=n-1)cout<<" ";
    }
    cout<<endl;
    cout<<countnum<<endl;
    return 0;
}
