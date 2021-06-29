#include<iostream>
using namespace std;
int main()
{
  int n,v,j,i,s;
  int A[1001];
  cin >> n;
  for(i=0; i<n;i++){
    cin >> A[i];
  }
for(s=0;s<n;s++){
  if(s==n-1) cout << A[s];
  else cout << A[s] << " ";
}
cout << "\n";
   for(i=1; i<n; i++){
     v = A[i];
     j = i-1;
     while(j>=0&&A[j]>v){
       A[j+1]=A[j];
       j--;
       A[j+1]=v;
     }
     for(s=0;s<n;s++){
       if(s==n-1) cout << A[s];
       else cout << A[s] << " ";

     }
     cout << "\n";
   }

     return 0;
   }

