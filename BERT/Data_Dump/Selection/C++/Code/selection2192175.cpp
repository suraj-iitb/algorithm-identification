 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<math.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 #include<queue>
 
 using namespace std;
 
 int arr[100+5];
 
 int main()
 {
   int N;
   int count=0;
   cin>>N;
   for(int i=0;i<N;i++) cin>>arr[i];
   for(int i=0;i<N;i++)
   {
     int mini=i;
     for(int j=i;j<N;j++)
     {
       if(arr[j]<arr[mini])
       {
         mini=j;                    
       }        
     }       
     if(mini!=i)
     {
       count++;
       swap(arr[i],arr[mini]);           
     }
   }
   for(int i=0;i<N-1;i++) cout<<arr[i]<<" ";
   cout<<arr[N-1]<<endl;
   cout<<count<<endl;
   //while(1);
   return 0;
 }
 
 
 
