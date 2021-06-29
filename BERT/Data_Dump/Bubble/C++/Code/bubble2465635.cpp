#include <iostream>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;


int main()
{
  int N; cin>>N;
  int seq[N]; REP(i,N) cin>>seq[i];
  
  int swap=0;
  for(int i=0; i<N; i++)
  {
    for(int j=N-1; j>i; j--)
    {
      if(seq[j-1] > seq[j])
      {
        int tmp = seq[j];
        seq[j] = seq[j-1];
        seq[j-1] = tmp;
        swap++;
      }
    }
  }
  
  REP(i,N)
  {
    if(i) cout<<' ';
    cout<<seq[i];
  }
  cout<<endl;

  cout<<swap<<endl;
}
