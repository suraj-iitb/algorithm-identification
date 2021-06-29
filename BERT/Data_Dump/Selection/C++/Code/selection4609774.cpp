#include <iostream>
#include <algorithm>
using namespace std;
const static int LEN=100;
void trace(int a[],int N)
{
    int i;
    for(i=0;i<N-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[i]<<endl;
}
int selectsort(int a[], int N)
{
    int num=0;
    for(int i=0;i<N;i++){
        int minx=i;
        for(int j=i;j<N;j++){
            if(a[j]<a[minx]){
                minx=j;
            }
        }
        swap(a[i],a[minx]);
        if(minx!=i) num++;
    }
    return num;
}
int main()
{
    int n;
    cin>>n;
    int a[LEN];
    for(int i=0;i<n;i++) cin>>a[i];
    int x=selectsort(a,n);
    trace(a,n);
    cout<<x<<endl;
    return 0;
}

