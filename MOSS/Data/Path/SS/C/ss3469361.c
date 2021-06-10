#include <iostream>
#include <cassert>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr8,pr7,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
#define prArr(a) {cerr<<(#a)<<"={";int i=0;for(auto t:(a))cerr<<(i++?", ":"")<<t;cerr<<"}"<<endl;}
using namespace std;
//INSERT ABOVE HERE

template<typename T>
class Deque{
public:
  T *val;
  int sz;
  int length;
  int head, tail;
  
  Deque(){sz = 0, length = 0;}
  Deque(int size, T init = T()){
    length = 1;
    while(length < size) length *= 2;
    val = new T[length];
    sz = size;
    head = 0;
    tail = 0;
    for(int i=0;i<size;i++) val[tail++] = init;
  }
  
  T& operator [] (int i){assert(0 <= i && i < sz);return val[(head + i)%length];}
  int size(){return sz;}

  void increaseMemory(){
    int length_ = length;
    
    length = length * 2;
    if(length == 0) length = 1;
    T *val2 = new T[length];
    for(int i=0;i<sz;i++) val2[i] = val[(head + i)%length_];
    head = 0;
    tail = sz;
    delete [] val;
    val = val2;
  };
  
  void push_back(T v){
    if(sz == length) increaseMemory();
    sz++;
    val[tail++] = v;
    if(tail == length) tail = 0;
  }
  
  void push_front(int v){
    if(sz == length) increaseMemory();
    sz++;
    head--;
    if(head == -1) head = length - 1;
    val[head] = v;
  }

  void pop_back(int v){
    tail--;
    if(tail == -1) tail = 0;
  }
  
  void pop_front(int v){
    head++;
    if(head == length) head = 0;
  }
};
template <typename T>
using vector = Deque<T>;

template<typename T>
class Priority_queue{
public:
  T *A;
  int H;
  int sz;
  T MIN;

  constexpr Priority_queue(){H = 0, sz = 0;}
  constexpr Priority_queue(int size, T mn){
    MIN = mn;
    A = new T[size];
    H = 0;
    sz = 0;
  }

  int size(){return sz;}
  int empty(){return sz == 0;}

  void swap(T &a, T & b){
    T tmp = a;
    a = b;
    b = tmp;
  }
  
  void maxHeapify(int i){
    int l=i * 2;
    int r=i * 2 + 1;
    int largest;
    if(l <= H && A[l] > A[i]) largest = l;
    else largest = i;
    
    if(r <=H && A[r] > A[largest]) largest = r;
   
    if(largest != i) {
      swap(A[i], A[largest]);
      maxHeapify(largest);
    }
  }
 
  void heapIncreaseKey(int i, T key){
    A[i] = key;
    while(i > 1 && A[i/2] < A[i]){
      swap(A[i], A[i/2]);
      i /= 2;
    }
  }
 
  void push(T k){
    sz++;
    H++;
    A[H] = MIN;
    heapIncreaseKey(H, k);  
  }
  
  T top(){return A[1];}
  
  T pop(){
    sz--;
    T res = A[1];
    A[1] = A[H];
    H--;
    maxHeapify(1);
    return res;
  }
};

template <typename T, typename D>
class Pair{
public:
  T first;
  D second;
  Pair(){first = second = 0;}
  Pair(const T first, const D second):first(first), second(second){}
  
  bool operator < (const Pair t)const{
    return first != t.first? (first < t.first):(second < t.second);
  }
  bool operator > (const Pair t)const{
    return first != t.first? (first > t.first):(second > t.second);
  }
};
  

signed main(){
    srand((unsigned)time(NULL));
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int V, E, r;
    cin>>V>>E>>r;
    typedef Pair<int, int> P;
    vector<vector<P> > G(V);
    
    for(int i=0;i<E;i++){
      int s, t, d;
      cin>>s>>t>>d;
      G[s].push_back(P(t, d));
    }
    
    Priority_queue <P> Q(1000000, P(-1e9, -1e9));
    const int INF = 1000000010;
    vector<int> D(V ,INF);
    vector<int> visited(V ,0);
    D[r] = 0;
    Q.push(P(0, r));
    
    while(!Q.empty()){
      P t = Q.top(); Q.pop();
      int cost = -t.first;
      int pos = t.second;
      if(visited[pos]++) continue;

      for(int i=0;i<(int)G[pos].size();i++){
	int to = G[pos][i].first;
	int ncost = cost + G[pos][i].second;
	if(visited[to] || D[to] <= ncost) continue;
	D[to] = ncost;
	Q.push(P(-ncost, to));
      }
    }

    for(int i=0;i<V;i++){
      int ans = D[i];
      if(ans == INF) cout<<"INF"<<endl;
      else cout<<ans<<endl;
    }
    
    return 0;
  }

