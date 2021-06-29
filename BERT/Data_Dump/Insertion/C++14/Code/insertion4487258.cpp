#include <bits/stdc++.h>
#include <iostream> 
using namespace std;

#define ll long long;
#define pi acos(-1);

int main(){
 //  cout << pi;
   int n;
   cin>>n;
   int arr[n];
   for(int i = 0;i<n;i++){cin>>arr[i];}
   	for(int k = 0;k < n; k++){
		if(k != n-1){
			printf("%d ",arr[k]);
		}else{
			printf("%d\n",arr[k]);
		}
	}

   int size = sizeof(arr)/sizeof(arr[0]);
   for (int i = 1; i < size; i++)
   {
      
      int key = arr[i];
      int j = i-1;
      while (key < arr[j] && j >= 0)
      {
         swap(arr[j+1],arr[j]);
         
         j--;
      }
    // key = arr[j+1];
    	for(int k = 0;k < n; k++){
		if(k != n-1){
			printf("%d ",arr[k]);
		}else{
			printf("%d\n",arr[k]);
		}
	}

    
}
   

   
   return 0;
}
