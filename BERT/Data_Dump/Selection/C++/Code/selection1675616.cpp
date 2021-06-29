#include <iostream>
#include <cstdio>

using namespace std;

int selsort(int a[],int n){
  int count = 0;
  int j;
  for(int i=0;i<n;i++){
    int minj = i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj])
	minj=j;
    }
    if(minj!=i){
      swap(a[minj],a[i]);
      count++;
    }
  }
  return count;
}
  
  int main() {

  int n;
  int a[100];
  cin >> n;

  for(int i = 0;i<n;++i)
    cin >> a[i];
  
  int count = selsort(a,n);

  for(int i=0;i<n;++i){
    if(i>0) cout << " ";
    cout << a[i];
  }
  putchar('\n');

  cout << count << endl;

}
