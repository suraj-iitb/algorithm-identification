#include<iostream>
using namespace std;

void insertionSort( int *a, int n ){
 for( int i=0; i<n; i++ ){
   int v = a[i];
   int j=i-1;
   while( j>=0 && a[j] > v ){
     a[j+1] = a[j];
     j--;
   }
   a[j+1] = v;
   for( int h=0; h<n; h++ ){
       if( h !=n-1 ){
         cout << a[h] << " ";
       }else{
         cout << a[h] << endl;
       }
   }
 }
 return;
}

int main(){
 int n;
 cin >> n;

 int a[n];
 for( int i=0; i<n; i++ ){
   cin >> a[i];
 }

 insertionSort( a, n );

 return 0;
}
