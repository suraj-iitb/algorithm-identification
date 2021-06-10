#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<algorithm>
#include<list>
#include<cmath>
#include<iomanip>
#include<queue>
#include<functional>
#include<climits>
#include<iterator>
using namespace std;

const double pi=4*atan(1.0);

struct cVertex{
	int dist;
	int prev;
};

template<typename T>
struct cIndexedVertex{
	T index;
	int key;
	int parent;
	cIndexedVertex(T index_,int key_,int parent_)
		:index(index_)
		,key(key_)
		,parent(parent_){
	}
	cIndexedVertex():cIndexedVertex(-1,INT_MAX,-1){}
};

class priority_queue_with_decrease_key_by_heap{
private:
	vector<cIndexedVertex<int>> Heap;
	//Heap[HeapPlace[vertex index]].index = vertex index??????????????????????????????????¬???????vertex????????±?????\??£?????????????????\??£?????????
	vector<int> HeapPlace;
private:
	inline int parent(int i)const{ return i%2==0 ? i/2-1 : i/2; }
	inline int left(int i)const{ return 2*i+1; }
	inline int right(int i)const{ return 2*(i+1); }
	void heap_ify(int i){
		if(i<0 || i>Heap.size()-1)return;

		//i???????????¨??????????????????????????§????°?????????????????????????????????¨?????¨??????????????????
		int l(left(i)),r(right(i)),smallest;
		if(l<Heap.size() && Heap[l].key<Heap[i].key){
			smallest=l;
		}
		else smallest=i;

		if(r<Heap.size() && Heap[r].key<Heap[smallest].key){
			smallest=r;
		}

		//????????????????????????????????£????????°
		if(smallest!=i){
			swap(HeapPlace[Heap[i].index],HeapPlace[Heap[smallest].index]);
			swap(Heap[i],Heap[smallest]);
			heap_ify(smallest);
		}
	}
	inline void build_heap(){
		//??????????????????????????????????????????
		for(int i=parent(Heap.size()-1);i>=0;--i){
			heap_ify(i);
		}
	}
private:
	inline int getHeapPlace(size_t vertex)const{ return vertex>=HeapPlace.size() ? -1 : HeapPlace[vertex]; }
public:
	inline bool empty()const{ return Heap.empty(); }
	inline auto front()const{
		if(Heap.empty())return cIndexedVertex<int>();
		return Heap.front();
	}
	inline void pop(){
		if(Heap.empty())return;

		//?????????????????????????±???????????????¨???????°??????????????????????????????????
		HeapPlace[Heap.back().index]=HeapPlace[Heap.front().index];
		//???????????????????????????????????§?¶????
		HeapPlace[Heap.front().index]=-1;

		swap(Heap.front(),Heap.back());
		Heap.pop_back();

		//?????????????????£??????????????????????????£?????????????????????
		heap_ify(0);
	}
	inline auto front_and_pop(){
		auto ans=front();
		pop();
		return ans;
	}
	inline void decrease_key(int key,int VertexIndex){
		if(VertexIndex<0 || VertexIndex>=HeapPlace.size())return;
		int i=HeapPlace[VertexIndex];

		if(key>Heap[i].key)return;

		Heap[i].key=key;
		//?????£??????????????§???????????????
		while(i>0 && Heap[parent(i)].key>Heap[i].key){
			swap(HeapPlace[Heap[i].index],HeapPlace[Heap[parent(i)].index]);
			swap(Heap[parent(i)],Heap[i]);
			i=parent(i);
		}
	}
	inline bool is_heap_in(size_t vertex)const{ return vertex>=HeapPlace.size() ? false : (HeapPlace[vertex]<0 ? false : true); }
	inline int get_key(size_t vertex)const{ return vertex>=HeapPlace.size() ? INT_MAX : Heap[HeapPlace[vertex]].key; }
	inline void set_parent(size_t vertex,int parent){ if(vertex<HeapPlace.size() && HeapPlace[vertex]>=0)Heap[HeapPlace[vertex]].parent=parent; }
	inline int get_parent(size_t vertex)const{ return vertex<HeapPlace.size() ? Heap[HeapPlace[vertex]].parent : -1; }
public:
	inline void reset(size_t size,size_t root){
		if(size==0){
			Heap.clear();
			HeapPlace.clear();
			return;
		}
		if(root>size-1)root=0;

		Heap=vector<cIndexedVertex<int>>(size);
		for(int i=0;i<Heap.size();++i){
			Heap[i].index=i;
			Heap[i].key=(i==root ? 0 : INT_MAX);
			Heap[i].parent=-1;
		}
		HeapPlace.reserve(size);
		for(int i=0;i<Heap.size();++i){
			HeapPlace.push_back(i);
		}
		build_heap();
	}
	inline size_t get_vertex_num()const{ return HeapPlace.size(); }
public:
	priority_queue_with_decrease_key_by_heap(size_t size,size_t root){
		reset(size,root);
	}
public:
	inline auto Heap_cbegin()const{ return Heap.cbegin(); }
	inline auto Heap_cend()const{ return Heap.cend(); }
	inline auto HeapPlace_cbegin()const{ return HeapPlace.cbegin(); }
	inline auto HeapPlace_cend()const{ return HeapPlace.cend(); }
};

class priority_queue_with_decrease_key_by_array{
private:
	static constexpr int null_index=-1;
	//?????\?????????????????????????????£?????´??????index=null_index??¨??????
	vector<cIndexedVertex<int>> Vertices;
	size_t Q_size;
public:
	inline bool empty()const{ return Q_size==0 ? true : false; }
	inline auto front()const{
		if(empty())return cIndexedVertex<int>();

		cIndexedVertex<int> MinVertex;
		for(const auto& val:Vertices){
			if(val.index!=null_index && MinVertex.key>val.key)MinVertex=val;
		}

		return MinVertex;
	}
	inline void pop(){
		if(empty())return;

		int MinIndex=-1;
		for(const auto& val:Vertices){
			if(val.index!=null_index){
				MinIndex=val.index;
				break;
			}
		}

		for(int i=MinIndex+1;i<Vertices.size();++i){
			if(Vertices[i].index!=null_index && Vertices[i].key<Vertices[MinIndex].key){
				MinIndex=i;
			}
		}

		Vertices[MinIndex].index=null_index;
		--Q_size;
	}
	inline auto front_and_pop(){
		if(empty())return cIndexedVertex<int>();

		cIndexedVertex<int> MinVertex;
		for(const auto& val:Vertices){
			if(val.index!=null_index && MinVertex.key>val.key)MinVertex=val;
		}

		Vertices[MinVertex.index].index=null_index;
		return MinVertex;
	}
	inline void decrease_key(int key,int vertex){
		if(vertex<0 || Vertices.size()-1<vertex || key>Vertices[vertex].key)return;

		Vertices[vertex].key=key;
	}
	inline bool is_heap_in(size_t vertex)const{ return vertex>=Vertices.size() ? false : (Vertices[vertex].index==null_index ? false : true); }
	inline bool get_key(size_t vertex){ return vertex>=Vertices.size() ? false : (Vertices[vertex].index==null_index ? false : true); }
	inline void set_parent(size_t vertex,int parent){ if(vertex<Vertices.size())Vertices[vertex].parent=parent; }
	inline int get_parent(size_t vertex)const{ return vertex<Vertices.size() ? Vertices[vertex].parent : -1; }
	inline int get_vertex_num()const{ return Vertices.size(); }
public:
	inline void reset(size_t size,int root){
		if(size==0){
			Vertices.clear();
			Q_size=0;
			return;
		}

		if(root>size-1)root=0;
		Vertices=vector<cIndexedVertex<int>>(size);
		Q_size=size;
		for(int i=0;i<Vertices.size();++i){
			Vertices[i].index=i;
			Vertices[i].key=(i==root ? 0 : INT_MAX);
			Vertices[i].parent=null_index;
		}
	}
public:
	priority_queue_with_decrease_key_by_array(size_t size,int root){
		reset(size,root);
	}
};

using cWeightEdges=std::vector<std::vector<std::pair<int,int>>>;
constexpr int parent_null=-1;

template<typename priority_queue_with_decrease_key>
inline void relax(cIndexedVertex<int> from,cIndexedVertex<int> to,int weight_from_to,priority_queue_with_decrease_key& Q){
	if(from.index<0 || Q.get_vertex_num()-1<from.index || to.index<0 || Q.get_vertex_num()-1<to.index)return;

	//????????§???????????§??????????????????????????????
	if(from.key==INT_MAX && from.parent==parent_null)return;

	if(!Q.is_heap_in(to.index))return;

	if(to.key>from.key+weight_from_to){
		Q.set_parent(to.index,from.index);
		Q.decrease_key(from.key+weight_from_to,to.index);
	}
}

template<typename priority_queue_with_decrease_key>
vector<cVertex> solve_by_Dijkstra(const cWeightEdges& Edges,int start){
	if(Edges.empty())return vector<cVertex>();

	vector<cVertex> Vertices(Edges.size());
	priority_queue_with_decrease_key Q(Edges.size(),start);

	while(!Q.empty()){
		auto now=Q.front_and_pop();

		Vertices[now.index]={now.key,now.parent};
		for(const auto& val:Edges[now.index]){
			if(Q.is_heap_in(val.first)){
				relax(now,cIndexedVertex<int>(val.first,Q.get_key(val.first),Q.get_parent(val.first)),val.second,Q);
			}
		}
	}

	return Vertices;
}
inline vector<cVertex> solve_by_Dijkstra_with_array(const cWeightEdges& Edges,int start){
	return solve_by_Dijkstra<priority_queue_with_decrease_key_by_array>(Edges,start);
}
inline vector<cVertex> solve_by_Dijkstra_with_heap(const cWeightEdges& Edges,int start){
	return solve_by_Dijkstra<priority_queue_with_decrease_key_by_heap>(Edges,start);
}

int main() {
	int N,M,root;
	cin>>N>>M>>root;
	cWeightEdges Edges(N);
	for(int i=0;i<M;++i){
		int u,v,w;
		cin>>u>>v>>w;

		Edges[u].push_back(make_pair(v,w));
	}

	auto ans=solve_by_Dijkstra_with_heap(Edges,root);

	for(const auto& val:ans){
		if(val.dist==INT_MAX)cout<<"INF"<<endl;
		else cout<<val.dist<<endl;
	}

	//system("pause");
	return 0;
}
