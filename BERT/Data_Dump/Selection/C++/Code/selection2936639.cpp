#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n=0;
    int i=0;
    int j=0;
    long S[101];
    int T1=0;
    int T2=0;
    int minj=0;
    
    int count=0;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>S[i];
        
    }
    
    for (i=1;i<=n;i++)
    {
        minj=i;
        for (j=i;j<=n;j++)
        {
            if (S[j]<S[minj])
            {
                minj=j;
                
                
            }
                
        }
        if(S[i]!=S[minj])
        {
            T1=S[i];
            T2=S[minj];
            S[i]=T2;
            S[minj]=T1;
            count++;
        }    
    }
    
    for (i=1;i<n;i++)
    {
        
        cout<<S[i]<<" ";
    }
    cout<<S[n]<<endl;
    cout<<count<<endl;
}

