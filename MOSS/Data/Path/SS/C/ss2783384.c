#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
#define Vmax 100000

struct Edges{
  int edges_to;
  int edges_cost;
};
std::vector<Edges>V_info[Vmax];
int main()
{
  int v,e,r,i;
  std::cin >> v>> e >> r;
  int si,ti,di;
  for(i=0;i<e;i++)
    {
      std::cin >> si >> ti>> di; 
      V_info[si].push_back( (Edges){ti,di} );
    }
  std::priority_queue< std::pair <int,int> > queue;
  int d[v];
  for(i=0;i<v;i++)
    d[i] = INF;
  d[r] = 0;
  queue.push(std::make_pair(0,r));
  int t_first;
  int t_second;
  Edges temp;
  while(!queue.empty())
    {
      t_first = queue.top().first;
      t_second = queue.top().second;
      queue.pop();
      for(i=0;i<V_info[t_second].size();i++)
	{
	  temp = V_info[t_second][i];
	  if(t_first + d[temp.edges_to] > temp.edges_cost)
	    {
	      d[temp.edges_to] = temp.edges_cost - t_first;
	      queue.push(std::make_pair(-d[temp.edges_to],temp.edges_to));
	    }
	}
    }
  for(i=0; i<v; i++)
    {
      if(d[i] == INF ) std::cout << "INF" << std::endl;
      else std::cout << d[i] << std::endl;
    }
  return 0;
}
