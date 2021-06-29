#include <iostream>
using namespace std;

int main()
{
    int i,j,k,N,key,arr[100];
    cin>>N;
    for(i=0;i<N;i++)
        cin>>arr[i];
    for(i=1;i<N;i++){
        for(k=0;k<N;k++)
            cout<<(k==0?"":" ")<<arr[k];
        cout<<endl;
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(k=0;k<N;k++)
        cout<<(k==0?"":" ")<<arr[k];
    cout<<endl;
    return 0;
}
