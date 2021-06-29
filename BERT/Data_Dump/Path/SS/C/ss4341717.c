#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<math.h> 
#include<queue>
#include<string.h>



#define INF 1000000000

using namespace std;

int v,e,r;
vector<pair<int,int> > g[100000];
int olded[100000];



void tanitu(){
	priority_queue<pair<int, int> >pri_qu;
	int a[100000];

	for(int i=0;i<v;i++){
		a[i]=INF;
	}
	a[r]=0;
	pri_qu.push(make_pair(r,0));

	while(1){

		int fir=pri_qu.top().first;
		int sec=pri_qu.top().second;
		pri_qu.pop();

		int g_size=g[fir].size();

		for(int i=0;i<g_size;i++){

			int tmp1=g[fir][i].first;
			int tmp2=g[fir][i].second;

			if(a[tmp1]>tmp2-sec){
				a[tmp1]=tmp2-sec;
				pri_qu.push(make_pair(tmp1, -a[tmp1]));
			}
		}
		if(pri_qu.empty())break;
	}
	for(int i=0;i<v;i++){
		if(a[i]==INF)cout<<"INF"<<endl;
		else cout<<a[i]<<endl;
	}
}


int main(){
	cin>>v>>e>>r;
	int s,t,d;
	for(int i=0;i<e;i++){
		cin>>s>>t>>d;
		g[s].push_back(make_pair(t,d));
	}
	tanitu();
}



