#include "List.h"
#include<fstream>
using namespace std;

int main(int argc,  char* argv[]) {
	LinkList List;
	//for(int i = 1; i < 1001 ; i++)
	//	List.insertNode(i,i);
	int length = List.GetLength();
	//cout<<length<<endl;
	ifstream in;	
	in.open("number.txt");
	int i;
	int j = 1;
	while(in>>i) {
		cout<<"position : "<<j<<" value : "<<i<<endl;
		List.insertNode(j++,i);
		
	}
	//List.printfList();
//	int a = List.findNode(10);
//	cout<<"position is " <<a<<endl;
	int a = List.findMaxNode();
	cout<<"The Max is "<<a<<endl;	
	return 0;
}
