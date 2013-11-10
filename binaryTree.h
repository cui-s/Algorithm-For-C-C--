#include<iostream>
using namespace std;

strcut node {
	int key_value;
	node * left;
	node * right;
}


class btree { 
	public:
		btree();
		~btree();
		void insert(int key);
		void insert(int key,node * leaf);
		search *node(int key);
		void detroy_node(int key);
		
	private:
		node * root;
};

btree::btree() {
	root = NULL;
}

void btree::insert(int key,node *leaf) {


}

btree::~btree() {
	}


void btree::insert(int key) {
	if(root!=NULL)
		insert(key,root);
	else {
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void btree::insert(int key,node * leaf) {
	if (key < leaf->key_value) {
		if (leaf->left != NULL) 
			insert(key,leaf->left);
		else {
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			left->left->right = NULL;	
		}
	} else if (key >= leaf->key_value) {
		if(leaf->rigth!=NULL)
			insert(key,leaf->right);
		else {
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->rigth->right = NULL;
		}

	}

}



	
		

}


