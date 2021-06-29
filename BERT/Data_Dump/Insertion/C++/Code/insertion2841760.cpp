#include <iostream>

using namespace std;
int main()
{
 int N,i,v,j,i2;
 cin>>N;
 int A[N];

 
 for(i=0;i<N;i=i+1)
 { 
  cin>>A[i];
  //cout<<A[i]<<endl;
 }

for(i2=0;i2<N;i2=i2+1)
  {
   if(i2==N-1)
   {
    cout<<A[i2]<<endl;
    }else{
    cout<<A[i2]<<" ";}
  }



for(i=1;i<N;i++)
 {
  v=A[i];
  j=i-1;
  
  while(j>=0 and A[j]>v)
  {
   A[j+1]=A[j];
   j--;
   A[j+1]=v;
  } 
   
   for(i2=0;i2<N;i2=i2+1)
   {
    if(i2==N-1)
    {
    cout<<A[i2]<<endl;
    }else{
    cout<<A[i2]<<" ";}
   }
 }
 



 return 0;
}
