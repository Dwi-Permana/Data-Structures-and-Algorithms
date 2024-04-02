#include <iostream>
using namespace std;

class Stack{
	
	public:
		int size = 0;
		int top  = -1;
		char *items;
		
		Stack(int stackSize){//constructor
			size = stackSize;
			items = new char[size];
		}
		
		void push(char item){//stack penuh
			if(top == size-1){
				cout << "Stack overflow, stack is full" << endl;
			}else{	
				top++;
				items[top] = item;
			}
		}
	
		char pop(){
			char item;
			if(top == -1){//stack kosong
				cout << "ERROR !!! Stack is empty" << endl;
			}else{
			item = items[top];
			//items[top] = '-';
			top--;
			}
			return item;
		}	
};

int main(int argc, char** argv) {
	
	Stack kantong1(5);

	kantong1.push('A');
	kantong1.push('B');
	kantong1.push('C');
    kantong1.push('D');
	kantong1.push('E');
    kantong1.push('F');

    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;	

	return 0;
}