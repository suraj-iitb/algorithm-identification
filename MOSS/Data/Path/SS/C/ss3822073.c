#include <vector>
#include <stack>
#include <queue>

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::cin;


template <typename CostType>
/// \brief 辺の情報
struct Edge{
  int to;
  CostType cost;
  Edge(int t,CostType c):to(t),cost(c){}
};

template <typename CostType>
class Graph{

private:





  /// \brief adjacent_list_[n]=ノードnの隣接リストを表すvector<Edge>
  std::vector<std::vector<Edge<CostType>>> adjacent_list_;

public:

  /// \brief 頂点数
  const int NODE_SIZE_;

  /// \brief コンストラクタ
  /// \param node_size 頂点数
  explicit Graph(const int node_size):NODE_SIZE_(node_size),adjacent_list_(node_size){}

  /// \brief 有向グラフの辺を生やす
  /// \param from 辺の根本の頂点の番号
  /// \param to 辺の先の頂点の番号
  /// \param cost 辺のコスト
  void SetDirectedEdge(const int from,const int to,const CostType cost){
    adjacent_list_[from].push_back(Edge<CostType>(to,cost));
  }

  /// \brief 無向グラフの辺を生やす
  /// \param node_a 一方の頂点の番号
  /// \param node_b もう一方の頂点の番号
  /// \param cost 辺のコスト
  void SetUndirectedEdge(const int node_a,const int node_b,const CostType cost){
    SetDirectedEdge(node_a,node_b,cost);
    SetDirectedEdge(node_b,node_a,cost);
  }

  /// \brief ある頂点の隣接リストを取得
  /// \param node_num 頂点の番号
  /// \return 隣接リスト
  std::vector<Edge<CostType>> GetAdjacentList(int node_num)const{
    return adjacent_list_[node_num];
  }
};

/// \brief ダイクストラ法により，ある頂点からの最短経路を求める
/// \tparam CostType 辺のコストの型
/// \param graph グラフ
/// \param start_node どの頂点から最短経路を求めるか
/// \param INF CostType型で十分大きい値
/// \return グラフの各頂点への最短経路を示す配列(到達不可能なときはINF)，負の辺が入っていた場合はsize0の配列
template <typename CostType>
std::vector<CostType> Dijkstra(const Graph<CostType>& graph, const int start_node, CostType INF){
  struct Info{
    int node;
    CostType cost;
    Info(int n,CostType c):node(n),cost(c){};
    bool operator>(const Info& another)const{
      return cost>another.cost;
    }
  };

  std::vector<CostType> min_cost(graph.NODE_SIZE_);
  std::priority_queue<Info,std::vector<Info>,std::greater<Info>> pq;
  for(int i=0;i<min_cost.size();i++){
    min_cost[i]=(i==start_node)?0:INF;
  }
  pq.push(Info(start_node,0));

  while(!pq.empty()){
    Info current_info=pq.top();
    pq.pop();
    if(min_cost[current_info.node]!=current_info.cost) continue;
    const std::vector<Edge<CostType>>& adjacency_list=graph.GetAdjacentList(current_info.node);
    for(auto e:adjacency_list){
      if(min_cost[e.to]>min_cost[current_info.node]+e.cost){
        min_cost[e.to]=min_cost[current_info.node]+e.cost;
        pq.push(Info(e.to,min_cost[e.to]));
      }
    }
  }

  return min_cost;

}

/// \brief ベルマンフォード法により，ある頂点からの最短経路を求める
/// \tparam CostType 辺のコストの型
/// \param graph グラフ
/// \param start_node どの頂点から最短経路を求めるか
/// \param INF CostType型で十分大きい値
/// \return グラフの各頂点への最短経路を示す配列(到達不可能なときはINF)，負の閉路が入っていた場合はsize0の配列
template <typename CostType>
std::vector<CostType> BellmanFord(const Graph<CostType>& graph, const int start_node, CostType INF){
  std::vector<CostType> min_cost;

}



/// \brief BFS，DFSをするときに必要な情報をまとめた構造体
struct State{
  int current_node;
  int prev_node;
  //その他必要な情報を入れる
};

/// \brief BFS，DFSの停止条件を入れる
/// \param state 判定対象の状態
/// \return 停止するべきであればtrue
bool ShouldStop(const State& state){

}

/// \brief 幅優先探索(BFS)をする
/// \tparam CostType グラフの辺のコストの型
/// \param graph グラフ
/// \param start_state 初期状態
/// \attention 単なるフレームワークのため，問題ごとに適当に実装して使う
template <typename CostType>
void BFS(const Graph<CostType>& graph,const State& start_state){
  std::queue<State> queue;
  queue.push(start_state);
  while(!queue.empty()){
    State current_state=queue.front();
    queue.pop();

    //必要があればShouldStop()を実装して下の行をコメントアウト
    //if(ShouldStop(current_state) return;

    //current_stateに対してなにかする

    std::vector<Edge<CostType>> adjacent_list=graph.GetAdjacentList(current_state.current_node);
    for(auto e:adjacent_list){

      int next_node=e.to;

      if(next_node!=current_state.current_node){
        State next_state;
        next_state.prev_node=current_state.current_node;
        next_state.current_node=next_node;
        //その他，next_stateに必要な処理を加える

        queue.push(next_state);
      }

    }
  }
}

/// \brief 深さ優先探索(DFS)をする
/// \tparam CostType グラフの辺のコストの型
/// \param graph グラフ
/// \param start_state 初期状態
/// \attention 単なるフレームワークのため，問題ごとに適当に実装して使う

template <typename CostType>
void DFS(const Graph<CostType>& graph,const State& start_state){
  std::stack<State> stack;
  stack.push(start_state);
  while(!stack.empty()){
    State current_state=stack.top();
    stack.pop();

    //必要があればShouldStop()を実装して下の行をコメントアウト
    //if(ShouldStop(current_state) return;

    //current_stateに対してなにかする

    std::vector<Edge<CostType>> adjacent_list=graph.GetAdjacentList(current_state.current_node);
    for(auto e:adjacent_list){

      int next_node=e.to;

      if(next_node!=current_state.current_node){
        State next_state;
        next_state.prev_node=current_state.current_node;
        next_state.current_node=next_node;
        //その他，next_stateに必要な処理を加える

        stack.push(next_state);
      }

    }
  }
}



int main(void){

  int64_t v,e,r;
  cin>>v>>e>>r;
  Graph<int64_t> graph(v);
  for(int64_t i=0;i<e;i++){
    int s,t,d;
    cin>>s>>t>>d;
    graph.SetDirectedEdge(s,t,d);
  }
  const int64_t INF=INT64_MAX/3;
  std::vector<int64_t> result=Dijkstra(graph,r,INF);
  for(auto r:result){
    if(r==INF){
      cout<<"INF"<<endl;
    }else{
      cout<<r<<endl;
    }
  }



  return 0;
}
