
#include <iostream>

using namespace std;
class myclass{
	int i;
	public :
	myclass(int j){
		i=j;
	}
	void print(){
		cout<<i<<endl;
	}
};

int main(){

	myclass *m = new myclass(2);
	m->print();

	myclass m1 = myclass(4);
	m1.print();

	m->print();

}

