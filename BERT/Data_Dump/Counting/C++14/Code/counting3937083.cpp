#include<bits/stdc++.h>

typedef long long ll;

int A[2000010], B[2000010];
ll C[10010];
using namespace std;

void coutnting_sort(int n)
{



    for(int j=0;j<n;j++)
    {
        C[A[j]]++;
    }

    for (int i = 1; i <= 10000; i++)
        C[i] += C[i - 1];

    for(int j=n-1;j>=0;j--)
    {
       B[C[A[j]]]=A[j];
       C[A[j]]--;
    }



    for(int i = 1;i <=n;i++){
    cout <<B[i];
    /// last akta space na print korar ar jnno
    if(i !=n)
      cout <<" ";
  }
  cout <<endl;
}




int main()
{

int n;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>A[i];
}
coutnting_sort(n);


return 0;
}

