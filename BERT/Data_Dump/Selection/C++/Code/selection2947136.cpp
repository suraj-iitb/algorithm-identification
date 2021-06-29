#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a[100]={0},i,j,kaisu=0,num,mini;

  cin >>num;
  for(i=0;i<num;i++){
    cin >>a[i];
  }



  for(i=0 ; i<num-1;i++){
    mini=i;
    for(j=i+1;j<num;j++){//num-1
      
      if(a[j]<a[mini]){ mini=j;
      }
    
    

    }
    if(mini!=i){
    swap(a[i],a[mini]);
    kaisu++;
    }

  }
  





      for(i=0;i<num;i++){
	cout <<a[i];
	if(i<num-1){cout <<" ";
	}
      }


      cout<<endl;
      cout<<kaisu<<endl;
      
      return 0;
}

