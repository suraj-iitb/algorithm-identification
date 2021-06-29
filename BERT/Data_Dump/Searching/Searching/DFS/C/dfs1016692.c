#include<stdio.h>
#include<stdlib.h>

#define MAX 101
#define NON -1

int *d,*f,*stack;
char *color;
int time,n;
int top;

struct Data{
	int num;
	struct Data *next;
};

struct Data *data;

void Make_list(void);
struct Data* New_list(void);
void DFS(void);
void DFS_visit(int);
void Push(int);
void Pop(void);
int Next(int);

int main(void){
	int i;
	
	scanf("%d",&n);

	d=(int*)malloc(sizeof(int)*(n+1));
	f=(int*)malloc(sizeof(int)*(n+1));
	stack=(int*)malloc(sizeof(int)*n);
	color=(char*)malloc(sizeof(char)*(n+1));
	data=(struct Data*)malloc(sizeof(struct Data)*(n+1));

	for(i=1;i<=n;i++) Make_list();

	DFS();

	for(i=1;i<=n;i++){
		printf("%d %d %d\n",data[i].num,d[i],f[i]);
	}

	free(d);
	free(f);
	free(stack);
	free(color);
	free(data);

	return 0;
}


void Make_list(void){
	int edg,ver,num;
	int i;
	struct Data *new,*work;

	scanf("%d",&ver);
	scanf("%d",&edg);

	data[ver].num=ver;
	data[ver].next=NULL;

	work=&data[ver];

	for(i=0;i<edg;i++){
		work->next=New_list();
		work=work->next;
	}
}


struct Data* New_list(void){
	struct Data *new;

	new=(struct Data*)malloc(sizeof(struct Data));

	scanf("%d",&new->num);
	new->next=NULL;

	return new;
}


void DFS(void){
	int i;

	time=0;
	top=0;
	
	for(i=0;i<n;i++) stack[i]=-1;

	for(i=1;i<=n;i++) color[i]='w';

	for(i=1;i<=n;i++){
		if(color[i]=='w') DFS_visit(i);
	}

}


void DFS_visit(int u){
	int v;

	Push(u);

	color[u]='g';

	d[u]=++time;

	while(top!=0){
		u=stack[top-1];
		v=Next(u);

		if(v!=-1){
			Push(v);
			color[v]='g';
			d[v]=++time;
		}
		else{
			Pop();
			color[u]='b';
			f[u]=++time;
		}
	}

}


void Push(int u){
	stack[top]=u;
	top++;
}


void Pop(void){
	top--;
	stack[top]=NON;
}


int Next(int u){
	struct Data *work;

	work=&data[u];

	while(work->next != NULL){
		if(color[work->next->num]=='w') return work->next->num;

		work=work->next;	
	}

	return -1;	
}
