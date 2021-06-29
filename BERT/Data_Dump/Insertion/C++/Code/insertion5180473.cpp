#include <iostream>

using namespace std;

int main()
{   
   int N,j,i,key,m;
   cin >> N;
   int A[N];
   for(i=0;i<N;i++)
   {
       cin >> A[i];
   }
   
   for(i=1;i<N;i++)
   {
       for (m=0;m<N;m++)
       {
           if(A[m]==A[N-1])
           {
              cout<<A[m] ;
              break;
           }
           else
           {
             cout <<A[m] << " "  ;
           }
       }
       cout << endl;
       key=A[i];
       j=i-1;
       while(j>=0&&A[j]>key)
       {
         A[j+1]=A[j];
          j--;
         A[j+1] = key;
       }
       
       
   }
   for (m=0;m<N;m++)
       {
           if(A[m]==A[N-1])
           {
              cout<<A[m] ;
              break;
           }
           else
           {
             cout <<A[m] << " "  ;
           }
       }
    cout << endl;
    
   
   return 0 ;
}



