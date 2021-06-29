#include<iostream>
using namespace std;

int selectionSort( int num[], int n ){
 int count = 0;
 for( int i=0; i<n; i++ ){
   int min = i;
   for( int j=i; j<n; j++ ){
    if( num[j] < num[min] ){
      min = j;
    }
   }
   if( i!=min ){
    swap( num[i], num[min] );
    count++;
   }
 }

 return count;
}

int main(){
 int n;
 cin >> n;

 int num[n];
 for( int i=0; i<n; i++ ){
   cin >> num[i];
 }

 int s_count = selectionSort( num, n );

 for( int i=0; i<n; i++ ){
  if( i!=n-1 ){
    cout << num[i] << " ";
  }else{
    cout << num[i] << endl;
  }
 }

 cout << s_count << endl;

 return 0;
}
