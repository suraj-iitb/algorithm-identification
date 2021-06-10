#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <limits.h>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

#define INF (INT_MAX/2)

typedef struct{
  int vno;   // vertex No.
  int dist;  // accumulated distance fromt start vertex
} v_t;

typedef struct{
  vector<v_t>            vertex;
  vector< vector<int> >  adj;
} g_t;

bool cmpD(const vector<v_t>::iterator &lhs, const vector<v_t>::iterator &rhs){
  return (*lhs).dist < (*rhs).dist;
};

bool cmpVno(const vector<v_t>::iterator &lhs, const vector<v_t>::iterator &rhs){
  return (*lhs).vno < (*rhs).vno;
};

int main(){ // Dijkstra P.254
  g_t G;  // graph : index is each vertex
  unordered_map< string, int > W; // Weight between Source and Target
  string sv; // "Source,Target"
  multimap< int, vector<v_t>::iterator > Q; // Key: dist 
  int vmax; int emax; int start;

  scanf("%d %d %d" ,&vmax ,&emax ,&start);
  // initialize G
  for( int i=0 ; i < vmax ; i++ ){
    v_t v = { i, INF + i };
    vector<int> a;
    G.vertex.push_back(v);
    G.adj.push_back(a);
  }
  v_t vs = { start, 0 };
  G.vertex.at(start) = vs;
  // initialize Adj
  for( int cnt=0 ; cnt<emax ; cnt++ ){
    int s, t, w; // source, target, weight
    scanf("%d %d %d" ,&s ,&t, &w);
    G.adj[s].push_back(t);
    sv = to_string(s) + "," + to_string(t);
    W[sv] = w;
  }

  for( auto itr = G.vertex.begin() ; itr != G.vertex.end() ; ++itr ){
    Q.insert( make_pair((*itr).dist, itr) );
  }

  while(!Q.empty()){
    auto u_itit = Q.begin();
    int uno = (*(u_itit->second)).vno;
    Q.erase(u_itit);
    for( auto v_it = G.adj[uno].begin() ; v_it != G.adj[uno].end() ; ++v_it ){
      // relax
      int w_uv = -1; // when no adj
      sv = to_string(uno) + "," + to_string(*v_it);
      auto w_it = W.find(sv);
      if( w_it != W.end() ){
        w_uv = w_it->second;
      }
      if( w_uv != -1 && G.vertex[(*v_it)].dist > ( G.vertex[uno].dist + w_uv ) ){
        int old_dist = G.vertex[(*v_it)].dist;
        int old_vno  = *v_it;
        for( auto it = Q.find(old_dist) ; it != Q.end() ; ++it ){
          if( (*(it->second)).vno == old_vno ){
            auto up_vit = it->second;
            Q.erase(it);
            Q.insert( make_pair( G.vertex[uno].dist + w_uv ,up_vit ) );
            break;
          }
        }
        G.vertex[(*v_it)].dist = G.vertex[uno].dist + w_uv;
      }
    }
  }

  for( auto itr = G.vertex.begin() ; itr != G.vertex.end() ; ++itr ){
    if( (*itr).dist < INF ){
      printf("%d\n" ,(*itr).dist );
    }else{
      printf("INF\n");
    }
  }

  return 0;
}


