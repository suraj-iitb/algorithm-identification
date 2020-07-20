#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n=0;
    int i=0;
    int k=0;
    long S[101];
    int T1=0;
    int T2=0;
    bool flug=true;
    int count=0;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>S[i];
        
    }
    
    while (flug==true)
    {
        flug=false;
        for (k=n;k>=2;k--)
        {
            if (S[k]<S[k-1])
            {
                T1=S[k];
                T2=S[k-1];
                S[k]=T2;
                S[k-1]=T1;
                flug=true;
                count++;
            }
        }
    }
    
    for (i=1;i<n;i++)
    {
        
        cout<<S[i]<<" ";
    }
    cout<<S[n]<<endl;
    cout<<count<<endl;
}

