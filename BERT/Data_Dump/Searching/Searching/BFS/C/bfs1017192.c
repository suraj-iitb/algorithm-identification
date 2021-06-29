#include<stdio.h>
#include<stdlib.h>

struct Data{
	int num;
	struct Data *next;
};

struct Data *data;

void Make_list(void);
struct Data* New_list(void);
void Enqueue(int);
int Dequeue(void);
void BFS(int);

int *d;
char *color;
int n;
int *queue;
int head,tail;

int main(void){
	int i;

	scanf("%d",&n);

	d=(int*)malloc(sizeof(int)*(n+1));
	color=(char*)malloc(sizeof(char)*(n+1));
	queue=(int*)malloc(sizeof(int)*(n));
	data=(struct Data*)malloc(sizeof(struct Data)*(n+1));

	for(i=1;i<=n;i++) Make_list();

	BFS(1);

	for(i=1;i<=n;i++) printf("%d %d\n",i,d[i]);

	free(d);
	free(color);
	free(queue);

	return 0;
}


void Make_list(void){
	int edg,ver,num;
	int i;
	struct Data *work;

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



void BFS(int s){
	int i;
	int u;
	struct Data *work;

	for(i=s;i<=n;i++){
		d[i]=-1;
		color[i]='w';
	}
	for(i=0;i<n;i++) queue[i]=-1;
	head=0;
	tail=0;

	color[s]='g';
	d[s]=0;

	Enqueue(s);
	while(head!=tail){
		u=Dequeue();
		work=&data[u];
		while(work->next != NULL){
			work=work->next;
			if(color[work->num]=='w'){
				color[work->num]='g';
				d[work->num]=d[u]+1;
				Enqueue(work->num);
			}
		}
		color[u]='b';
	}
}


void Enqueue(int num){
	queue[tail]=num;
	tail++;
	if(tail>=n) tail=0;
}


int Dequeue(){
	int num;

	num=queue[head];
	head++;
	if(head>=n) head=0;
	return num;
}
