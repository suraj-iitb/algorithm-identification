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
   int n;
   cin>>n;
   for(int i=0;i<n;i++) cin>>arr[i];
   for(int i=0;i<n-1;i++) cout<<arr[i]<<" ";
   cout<<arr[n-1]<<endl;
   for(int i=1;i<n;i++)
   {
     int key=arr[i];
     int j=i-1;
     while(j>=0&&arr[j]>key)
     {
       arr[j+1]=arr[j];
       j--;                     
     }     
     j++;
     arr[j]=key;   
     for(int k=0;k<n-1;k++) cout<<arr[k]<<" ";
     cout<<arr[n-1]<<endl;
   }
   //while(1);
   return 0;
 }
 
