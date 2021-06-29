#include <iostream>
using namespace std;
const int INF = 10000*100000+100;
int V,E,R,S[500010],T[500010],D[500010];
int C[100010];
int main()
{
	cin >> V >> E >> R;
	for(int i = 0; i < E; ++i)
	{
		cin >> S[i] >> T[i] >> D[i];
	}
	
	for(int i = 0; i < V; ++i){
		C[i] = INF;
	}
	C[R] = 0;
	for(int t = 0; t < V; ++t)
	{
		bool update = false;
		for(int i = 0; i < E; ++i)
		{
			int s = S[i], t = T[i], d = D[i];
			if(C[s] < INF && C[t] > C[s] + D[i])
			{
				C[t] = C[s] + D[i];
				update = true;
			}
		}
		if(!update) break;
	}
	for(int i = 0 ;i < V; i++)
	{
		if(C[i] == INF)
			cout<<"INF"<<endl;
        else
            cout << C[i] << endl;
	}
    return 0;
}
