#include<iostream>
#include"binaryTree.h"
using namespace std;



int main(int argc, char * argv[]) {
	btree BinaryTree_test;
	BinaryTree_test.insert(1);
	BinaryTree_test.insert(2);
	BinaryTree_test.insert(10);
	node * root = BinaryTree_test.return_root();
	cout<<root->key_value<<endl;

	BinaryTree_test.print_all_node(root);
	return 0;
}
