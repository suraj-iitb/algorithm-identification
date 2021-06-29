#include<iostream>
using namespace std;

int num[101];
int main() {
  int N;
  cin >> N;
  for(int i=1; i<=N; i++) {
    cin >> num[i];
  }

  int sum = 0;
  int minj=1;
  for(int i=1; i<=N; i++) {
    minj = i;
    for(int j=i+1; j<=N; j++) {
      if(num[j]<num[minj]) {
        minj=j;
      }
    }
    swap(num[i], num[minj]);
    if(i!=minj) sum++;
  }


  cout << num[1];
  for(int i=2; i<=N; i++) {
    cout << " " << num[i];
  }
  cout << endl;
  cout << sum << endl;;
}

