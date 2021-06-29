#include <iostream>
#include <cstdio>

using namespace std;

void trace(int a[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

int main(void){

  int n;
  int a[1001];
  cin >> n;
    for( int i = 0 ; i < n ; i++ ) // read
      cin >> a[i];
  
  for( int i = 1 ; i < n ; i++ ){
    int temp = a[i];
    trace(a , n);
    if( a[i - 1] > temp ){ // ?????????????????則??????
      int j = i;
      do{
	a[j] = a[j - 1];
	j--;
      } while( j > 0 && a[j - 1] > temp );
      a[j] = temp;
    }
  }
  for( int i = 0 ; i < n ; i++ ){
    if( i > 0 ) cout << " "; 
    cout << a[i];
  }
  cout << endl; 
  return 0;
}
