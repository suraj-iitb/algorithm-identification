#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);++i)
constexpr lint INF=1LL<<60;

template<typename T>
class skew_heap{
	struct node;
	using np=node*;
	struct node{
		np ch[2]={nullptr,nullptr};
		T val;
        lint lazy=0;
		node(T val):val(val){}
	};
	np root=nullptr;
    void eval(np t){
        if(!t)return;
        t->val=make_pair(t->val.first+t->lazy,t->val.second);
        if(t->ch[0])t->ch[0]->lazy+=t->lazy;
        if(t->ch[1])t->ch[1]->lazy+=t->lazy;
        t->lazy=0;
    }
	np meld(np a,np b) {
        eval(a);eval(b);
		if(!a||!b)return a?a:b;
		if(a->val>b->val)swap(a,b);
		a->ch[1]=meld(a->ch[1],b);
		swap(a->ch[0],a->ch[1]);
		return a;
	}
	public:
	skew_heap(np root=nullptr):root(root){}
    void add(lint val){if(root)root->lazy+=val;}
    bool empty(){return !root;}
	void insert(T val){root=meld(root,new node(val));}
	void pop(){eval(root);root=meld(root->ch[0],root->ch[1]);}
	T top(){eval(root);return root->val;}
	void meld(skew_heap t){root=meld(root,t.root);}
};

int main(){
    lint n,m,r;
    cin>>n>>m>>r;
    vector<skew_heap<pair<lint,lint>>>v(n);
    rep(i,m){
        lint s,t,x;
        cin>>s>>t>>x;
        v[s].insert(make_pair(x,t));
    }
    vector<lint>diff(n,INF);
    skew_heap<pair<lint,lint>>que;
    que.meld(v[r]);
    diff[r]=0;
    while(!que.empty()){
        lint c,e;
        tie(c,e)=que.top();
        que.pop();
        if(diff[e]>c){
            diff[e]=c;
            v[e].add(c);
            que.meld(v[e]);
        }
    }
    rep(i,n){
        if(diff[i]==INF)cout<<"INF"<<endl;
        else cout<<diff[i]<<endl;
    }
}
