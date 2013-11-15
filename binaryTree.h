#include<iostream>
using namespace std;

struct node {
	int key_value;
	node * left;
	node * right;
};


class btree { 
	public:
		btree();
		~btree();
		void insert(int key);
		void insert_leaf(int key,node * leaf);
		node *search(int key,node *leaf);
		void detroy_node(int key);
		node * return_root();
		int return_tree_height();
		void print_all_node(node * leaf);		
	private:
		node * root;
};

btree::btree() {
	root = NULL;
}


btree::~btree() {
	}


void btree::insert(int key) {
	if(root!=NULL)
		insert_leaf(key,root);
	else {
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}
//search key from node called leaf
void btree::insert_leaf(int key,node * leaf) {
	if (key < leaf->key_value) {
		if (leaf->left != NULL) 
			insert_leaf(key,leaf->left);
		else {
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;	
		}
	} else if (key >= leaf->key_value) {
		if(leaf->right!=NULL)
			insert_leaf(key,leaf->right);
		else {
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}

	}

}


node  * btree::search(int key,node * leaf) {
	if(leaf!=NULL){
		if(key==leaf->key_value)
			return leaf;
		if(key>leaf->key_value)
			return search(key,leaf->left);
		if(key<leaf->key_value)
			return search(key,leaf->right);
	}
	else return NULL;
}

void btree::print_all_node(node * root) {
	if(!root)
		return;
			
	cout<<root->key_value<<" ";
	
	print_all_node(root->left);
	print_all_node(root->right);
}

node * btree::return_root() {
	return root;
}

	
int btree::return_tree_height(node * leaf) {
	if(!leaf)
		return 0;
	int length;
	length = 1;
		

}


