#include<iostream>
using namespace std;

int bubbleSort( int num[], int n ){
 bool flag = true;
 int count = 0;
 while( flag ){
  flag = false;
  for( int j=n-1; j>0; j-- ){
   if( num[j] < num[j-1] ){
    swap(num[j], num[j-1]);
    flag = true;
    count++;
   }
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

 int b_count = bubbleSort( num, n );

 for( int i=0; i<n; i++ ){
  if( i!=n-1 ){
    cout << num[i] << " ";
  }else{
    cout << num[i] << endl;
  }
 }

 cout << b_count << endl;

 return 0;
}
