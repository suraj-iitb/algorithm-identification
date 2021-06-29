#include <iostream>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;


int main()
{
    int N; cin>>N;
    int seq[N]; REP(i,N) cin>>seq[i];

    int mini;
    int swap=0;
    REP(i,N)
    {
      mini = i;
      for(int j=i; j<N; j++)
      {
        if(seq[j] < seq[mini]) mini = j;
      }
      if( i == mini) continue;
      int tmp=seq[mini];
      seq[mini]=seq[i];
      seq[i]=tmp;
      swap++;
    }

    REP(i,N)
    {
      if(i) cout<<' ';
      cout<<seq[i];
    }
    cout<<endl;

    cout<<swap<<endl;
}
