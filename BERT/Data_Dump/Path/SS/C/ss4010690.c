#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#define Inf 10000*100000+100
using namespace std;

vector<pair<int,int> >A[500010];
int S[500010],T[500010],D[500010];
bool flag[100010];
int C[100010];
int main()
{
    priority_queue<pair<int,int> > Q;
    int V,E,R,i;
    //scanf("%d %d %d",&V,&E,&R);
    cin >> V >> E >> R;
    for(i=0;i<E;i++)
    {
        //scanf("%d %d %d",&S[i],&T[i],&D[i]);
        cin >> S[i] >> T[i] >> D[i];
        A[S[i]].push_back(make_pair(T[i],D[i]));
    }
    for(i=0;i<V;i++)
    {
        C[i]=Inf;
        flag[i]=true;
    }
    C[R]=0;
    Q.push(make_pair(0,R));
    while(!Q.empty())
    {
        pair<int,int> m = Q.top();
        Q.pop();
        flag[m.second]=false;
        int length=A[m.second].size();
        for(i=0;i<length;i++)
        {
            if(flag[A[m.second][i].first]==true && C[A[m.second][i].first]!=0 && C[A[m.second][i].first]>A[m.second][i].second+C[m.second])
            {
                C[A[m.second][i].first] = A[m.second][i].second+C[m.second];
                Q.push(make_pair(C[A[m.second][i].first]*(-1),A[m.second][i].first));
            }
        }
    }
    for(i=0;i<V;i++)
    {
        if(C[i]!=Inf)
            //printf("%d\n",C[i]);
            cout << C[i] << endl;
        else    //printf("INF\n");
                cout << "INF" << endl;
    }
    return 0;
}
