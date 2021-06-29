#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,x[100],co=0;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&x[i]);

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(x[j]>x[j+1])
            {
                swap(x[j],x[j+1]);
                co++;
            }
        }
    }

 for(int i = 0;i < n;i++){
    cout <<x[i];
    if(i !=n-1)
      cout <<" ";
  }
  cout <<endl;
  cout <<co<<endl;

    return 0;
}

