#include <iostream>
using namespace std;

struct TOP {
	int value;

	//TOP p;	//에러
	TOP* next;	
};

int main() {
	TOP a, b;
	TOP* p = &a;

	a.value = 20;
	(*p).value = 20;//a.value=20
	p->value = 20;	//a.value=20
					        //p가 "가리키는 변수 안의" value

	a.next = &b;
	a.next->value = 30;//b.value=30

	return 0;
}
