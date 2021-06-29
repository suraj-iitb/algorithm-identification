#include <iostream>

using namespace std;

// function to do selection sort -- O(n^2)
int c=0;
template <class T > // to recieve many data types
void selectionSort( T a[] , int s){
  for(int i=0 ; i<s-1 ;i++){
    int min = i;
    for(int j=i+1 ; j<s ;j++){
      if(a[j] < a[min])
        min = j;
    }
    if(a[i]!=a[min])
      c++;
    swap(a[i],a[min]);
  }
}

int main(){

 //int array [] = {3,6,8,2,4,-1,5};
 // string  array [] = { "paper", "true" ,"soap" ,"floppy" ,"flower"};
 // char array[]={'r','r','x','a','l'};
  int n ;
  cin >>  n;
  int  array[n];
  for(int i=0;i<n;i++)
    cin >> array[i];

 int size = sizeof array / sizeof array[0] ;

 selectionSort(array , size );

 // print the array after sorting 
 for(int i = 0; i<size-1 ; i++)
  cout << array[i] <<' ';
  cout << array[size-1]<<endl;
  cout <<c<<endl;

  return 0;
} 

