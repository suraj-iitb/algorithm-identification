#include <iostream>
#include <algorithm>
using namespace std;
const static int LEN=100;
int bubblesort(int a[], int  N)
{
    int num=0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1; j>0; j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                num++;
            }
        }
    }
    return num;
}
void trace(int a[], int N)
{
    int i;
    for(i=0;i<N-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[i]<<endl;
}
int main()
{
    int n;
    cin>>n;
    int a[LEN];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int x = bubblesort(a,n);
    trace(a,n);
    cout<<x<<endl;
    return 0;
}

