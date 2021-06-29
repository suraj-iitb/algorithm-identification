#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int num,a[100],i,k,l,j;

  cin>>num;
  for(i=0;i<num;i++){
    cin>>a[i];
  }


 for(k=0; k<num; k++){
   
   if(k<num-1){
   cout << a[k]<<" ";
   }else{
     cout <<a[k];
   }
 }
      cout <<endl;
    
  
  for(i=1;i<num;i++){
    for(j=i-1;j>=0;j--){
      if(a[j]>a[j+1]) swap(a[j],a[j+1]);
	     
	else
	  break;

	
    }
 for(k=0; k<num; k++){

   if(k<num-1){
     cout << a[k]<<" ";

   }else
   cout << a[k];


 }

 // if(i!=num-1){
 cout << endl;
 // }
 // cout <<A<<endl;
 
  }
  






      return 0;
}

	
  
