#include <iostream>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;

void putseq(int seq[],int n)
{
  REP(i,n)
  {
    if(i) cout<<' ';
    cout<<seq[i];
  }
  cout<<endl;
}

int main()
{
  int N;
  cin>>N;
  int seq[N];
  REP(i,N) cin>>seq[i];
  putseq(seq,N);

  int key,j;
  for(int i=1;i<N;i++)
  {
    key=seq[i];
    j = i - 1;
    while(j>=0 && seq[j] > key)
    {
      seq[j+1] = seq[j];
      j--;
    }
    seq[j+1] = key;
    putseq(seq,N);
  }
}
