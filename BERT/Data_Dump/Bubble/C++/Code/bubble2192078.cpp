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
   cin>>N;
   int count=0;
   for(int i=0;i<N;i++) cin>>arr[i];
   for(int i=0;i<N;i++)
   {
     for(int j=N-1;j>i;j--)
     {
       if(arr[j]<arr[j-1])
       {
         count++;
         int temp=arr[j];
         arr[j]=arr[j-1];
         arr[j-1]=temp;                   
       }          
     }        
   }
   for(int i=0;i<N-1;i++) cout<<arr[i]<<" ";
   cout<<arr[N-1]<<endl;
   cout<<count<<endl;
   //while(1);
   return 0;
 }
 
 
 
