#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

//使用pair替代 
struct node
{
    int end;///终点
    int power;///权值
} t;
const int maxn = 100010;

int n;///n为点数
vector<node>q[maxn];///邻接表储存图的信息、//数组大小为边的数量 
int dis[maxn];///距离
int vis[maxn];///标记数组


//void print(){
//	for(int i=0;i<n;i++){
//		printf("%d  ",dis[i]);
//	}
//	printf("\n");
//}


priority_queue<pair<int,int> >qu;

//void Dijkstra(int start)
//{
//    memset(dis,INF,sizeof(dis));
//    memset(vis,0,sizeof(vis));
//    
//    dist[start]=0;
//    
//    q.push(make_pair(0,start));
//    while(!q.empty())
//    {
//    	//先确认优先队列不为空，否则访问错误
//		//将第一关键字取反得到小根堆
//		//是否在队列中，实际代表是否被选取 ？？ 
//        while(!q.empty() && (-q.top().first)>dis[q.top().second])
//            q.pop();
//        if(!q.empty())
//            return;
//        
//         
//        int x=q.top().second;
//        q.pop();
//        for(int i=head[x];i;i=nxt[i])
//        {
//            int y=to[i];
//            if(dis[y]>dis[x]+val[i])
//            {
//                dis[y]=dist[x]+val[i];
//                q.push(make_pair(-dis[y],y));
//            }
//        }
//    }
//}


void Dijkstra(int start)
{
    memset(dis,INF,sizeof(dis));
    dis[start]=0;
    qu.push(make_pair(0,start));
    
    while(!qu.empty())
    {
        int x=qu.top().second;
        qu.pop();
        if(vis[x])
            continue;
        vis[x]=1;
        //节点已被筛选出 
//        for(int i=head[x];i;i=nxt[i])
//        {
//            int y=to[i];
//            if(dist[y]>dist[x]+val[i])
//            {
//                dist[y]=dist[x]+val[i];
//                q.push(make_pair(-dist[y],y));
//            }
//        }
		int len=q[x].size();				///再次更新dis数组
        for(int j=0; j<len; j++)
        {
            if(vis[q[x][j].end]==0&&dis[q[x][j].end]>q[x][j].power+dis[x])
            {
                dis[q[x][j].end] = q[x][j].power+dis[x];
                qu.push(make_pair(-dis[q[x][j].end],q[x][j].end));
            }
        }
    }
}


//void Dijkstra(int start)//,int end
//{
//    int i,len,j,s;
//    memset(vis,0,sizeof(vis));
//    //
//    for(i=0; i<n; i++)
//    {
//    	//起点为0 
//        dis[i]=INF;
//    }
//    //遍历起始节点能到达的边 
//    len=q[start].size();
//    for(i=0; i<len; i++)
//    {
//        if(q[start][i].power<dis[q[start][i].end])
//        {
//            dis[q[start][i].end]=q[start][i].power;
//        }
//    }							///从起点开始的dis数组更新
//    vis[start]=1;
//    dis[start]=0; 
//    for(s=0; s<n-1; s++)		///做(n-1)次即可 
//    {
//        int pos,min=INF;
//        for(i=0; i<n; i++)
//        {
//        	//未访问节点中遴选 
//        	//用堆维护这个最小值 
//            if(vis[i]==0&&dis[i]<min)
//            {
//                min=dis[i];
//                pos=i;					///找到未访问节点中权值最小的
//            }
//        }
//        vis[pos]=1;
//        len=q[pos].size();				///再次更新dis数组
//        for(j=0; j<len; j++)
//        {
//            if(vis[q[pos][j].end]==0&&dis[q[pos][j].end]>q[pos][j].power+dis[pos])
//            {
//                dis[q[pos][j].end] = q[pos][j].power+dis[pos];
//            }
//        }
////        print();
//    }
////    printf("%d\n",dis[end]);
//}

int main()
{
    int m,i;
    int begin,end,power;
    int a,b;
    scanf("%d%d%d",&n,&m,&a);
//    while(scanf("%d%d",&n,&m)!=EOF)
//    {
//        for(i=0; i<n; i++)
//        {
//            q[i].clear();							///将vector数组清空
//        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&begin,&end,&power);		///输入
            t.end=end;
            t.power=power;
            q[begin].push_back(t);
//            t.end=begin;							///无向图
//            t.power=power;
//            q[end].push_back(t);
        }
//        scanf("%d%d",&a,&b);						///输入起点与终点
//        Dijkstra(a,b);
	      Dijkstra(a); 
//    }
	
	for(int t=0;t<n;++t){
		if(dis[t]==INF){
			printf("INF\n");
		}
		else{
			printf("%d\n",dis[t]);
		}
	} 
    return 0;
}
