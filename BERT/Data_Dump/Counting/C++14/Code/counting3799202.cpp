#include<bits/stdc++.h>

#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FOR_DOWN(i,a,b) for(int (i)=(a);i>=(b);--(i))
#define ALL(obj) (obj).begin(),(obj).end()
#define space <<" "<<
#define maxs(x,y) (x=max(x,y))
#define mins(x,y) (x=min(x,y))
#define FIX fixed<<setprecision(10)
using namespace std;

using ll = long long; using ull = unsigned long long;
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pii = pair<int,int>; using pll = pair<ll,ll>;

const ll MOD = 1e9+7;

class Stack{
private:
char m[20000];
int tp;
public:
    Stack(){
    tp=0;
    }
    void push(char x){
        tp++;
        m[tp]=x;
    }
    char pop(){
        tp--;
        return m[tp+1];
    }
}; 
class Queue{
private:
pair<string,int> m[60000];
int head,tail;
public:
    Queue(){
        head=0;
        tail=0;
    }
    bool isEmpty(){
        return head==tail;
    }
    void enqueue(pair<string,int> x){
        m[tail]=x;
        if(tail +1 ==60000)tail=0;
        else tail++;
    }
    pair<string,int> deque(){
        pair<string,int> x=m[head];
        if(head+1==60000)head=0;
        else head++;
        return x;
    } 
};

struct Node{
    int key;
    Node* prev;
    Node* next;
};

class LinkedList{
public:
LinkedList(){
    dammy= new Node();
    dammy->key =0;
    dammy->prev= dammy;
    dammy->next= dammy;
}
~LinkedList(){
    Node* tmpNode =dammy->next;
    Node* nextNode;
    while(tmpNode != dammy){
        nextNode=tmpNode->next;
        delete tmpNode;
        tmpNode=nextNode;
    }
    delete dammy;
}
void insertNode(int x){
    Node* currentNode=dammy->next;
    dammy->next=new Node();
    dammy->next-> key =x;
    dammy->next->next=currentNode;
    dammy->next->prev=dammy;
    currentNode->prev = dammy->next;
}
    Node* find(int key){
    for(Node* i=dammy->next;i!=dammy;i=i->next){
      if(i->key==key)return i;
    }
    return dammy;
    }
    void deleteNode(int x){
    Node* currentNode = find(x);
    if(currentNode==dammy)return;
    currentNode->prev->next=currentNode->next;
    currentNode->next->prev=currentNode->prev;
    delete currentNode;
    }
    void deleteFirst(){
        Node* currentNode = dammy->next;
        dammy->next = dammy->next->next;
        dammy->next->prev = dammy;
        delete currentNode; 
    };
 
    void deleteLast(){
        Node* currentNode = dammy->prev;
        dammy->prev = dammy->prev->prev;
        dammy->prev->next = dammy;
        delete currentNode; 
    };

    void printList(){
    Node* currentNode = dammy->next;;
    int sp = 1;
    while(1){
    if ( currentNode == dammy ) break;
    if ( sp == 0)  cout<<" ";
    cout<<currentNode->key;
    currentNode = currentNode->next;
    sp = 0;
    }
    cout<<endl;
    }
    private:
    Node* dammy;
};
    int n;
void CountingSort(int* A,int* B,int k){
    int C[k+1];
    REP(i,k+1){
        C[i]=0;
    }
    REP(i,n){
        C[A[i+1]]++;
    }
    FOR(i,1,k+1){
        C[i]+=C[i-1];
    }
    for(int i=n;i>=1;i--){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }
}

int main(){
    int k;
    cin>>n;
    int A[n+1],B[n+1];
    A[0]=0;
    B[0]=0;
    REP(i,n){
        cin>>A[i+1];
    }
    k=A[1];
    REP(i,n){
        k= A[i+1]>k? A[i+1]:k;
    }
    CountingSort(A,B,k);
    REP(i,n-1){
        cout<<B[i+1]<<" ";
    }
        cout<<B[n]<<endl;
}

