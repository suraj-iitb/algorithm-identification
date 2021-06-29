#include <iostream>
using namespace std;



int main(){
  int a[100]={0},num,kaisu=0,j,i,t;

  cin >>num;
  for(i=0; i<num;i++){
    cin>>a[i];
}


for(i=0;i<num-1;i++){

  for(j=num-1;j>i;j--){

    if(a[j]<a[j-1]){
      t=a[j];a[j]=a[j-1];a[j-1]=t;
      kaisu++;
    }

  }
 }


 for(int i=0;i<num;i++){
   cout<<a[i];
   if(i<num-1) cout<<" ";
 }
 cout << endl;
 cout<<kaisu<<endl;

 return 0;
}
