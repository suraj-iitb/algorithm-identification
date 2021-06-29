#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin>>n;
    int A[100]{};
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        int v{};
        v=A[i];
        int j;
        j=i-1;
        while(A[j]>v&&j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        cout<<A[0];
        for(int t=1;t<n;t++)cout<<" "<<A[t];
        cout<<endl;
    }
    
    return 0;
}

