#include<iostream>
using namespace std;

class Bubble{
	int *p;
	int size;
public:
	Bubble();
	Bubble(const Bubble&);
	Bubble& operator=(const Bubble&);
	void input();
	void narabekae();
	int get_size()const{ return size; };
	~Bubble();
};

Bubble::Bubble(){
	int comp;
	cin>>comp;
	this->size = comp;
	p = new int[get_size()];
}

Bubble::Bubble(const Bubble& x){
	p = new int[x.get_size()];
}

Bubble& Bubble::operator=(const Bubble& x){
	if(this==&x) return *this;
	delete p;
	p = new int[x.get_size()];
	return *this;
}

Bubble::~Bubble(){
	delete [] p;
}

void Bubble::input(){
	for(int i=0;i<get_size();i++)
		cin>>*(p+i);
}

void Bubble::narabekae(){
	int flag = 1;
	int count = 0;
	while(flag){
		flag = 0;
		for(int j=get_size()-1;j!=0;j--){
			if(p[j-1]>p[j]){
				int temp = p[j-1];
				p[j-1] = p[j];
				p[j] = temp;
				flag = 1;
				count++;
			}
		}
	}

	for(int i=0;i<get_size();i++){
		if(i!=get_size()-1){
			cout<<p[i]<<" ";
		}else{
			cout<<p[i]<<endl;
		}
	}
	cout<<count<<endl;
}

int main(){

	Bubble test;
	test.input();
	test.narabekae();

	cin.get();
	cin.get();
}
