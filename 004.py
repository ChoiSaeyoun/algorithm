#include <iostream>
using namespace std;

int main(){
	//소스코드와 같은 위치, 아니라면 절대/상대경로 입력
	//rt=read text vs r=read
	//stdin : cin 
	freopen("input.txt","rt",stdin);
	int N, input, min=2147000000, max=-2147000000;
	
	cin>>N;
	int age[N];
	for(int i=0;i<N;i++){
		cin>>age[i];
	}
	
	for(int i=0;i<N;i++){
		if(age[i]<min)min=age[i];
		if(age[i]>max)max=age[i];
	}
	cout<<max-min;
	
	return 0;
}
