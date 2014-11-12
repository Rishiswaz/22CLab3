#pragma once

#include<iostream>
#include<conio.h>
#include<stack>
#include<queue>


typedef int valuetype;
class Node{
public:
	valuetype data;
	Node* left;
	Node* right;
	Node();
	Node(valuetype);
};
//OK
class BST{
	Node* findNodebyvalue(valuetype);
	Node* findparentforNode(valuetype);
	Node* findrightnode(Node*);
	void inorder(Node*);
	void postorder(Node*);
	void preorder(Node*);
public:
	Node* root;
	Node* current;
public:
	BST();
	void insert(valuetype);
	void remove(valuetype);
	void traverse();
	valuetype retrieve();
	void custom_print();
};
//default constructor
Node::Node(){
	left = right = NULL;
}
//constructor
Node::Node(valuetype val){
	data = val;
	left = right = NULL;
}
//default constructor
BST::BST(){
	root = current = NULL;
}
//insert a node with a value in tree
void BST::insert(valuetype val){
	if (root == NULL)
		root = new Node(val);
	else{
		Node* p = findNodebyvalue(val);
		if (p == 0)
		{
			//cout<<"fine1";
			Node* parent = root;
			if (p != root)
				parent = findparentforNode(val);
			if (val>parent->data) parent->right = new Node(val);
			else parent->left = new Node(val);
		}
		//cout<<"fine2";
	}
}
//remove a node of a given value
void BST::remove(valuetype val){
	Node* p = findNodebyvalue(val);
	if (p != 0){
		//if both of children of the node are null(leaf node)
		if (p->left == NULL&&p->right == NULL){
			if (p != root){
				Node* parent = findparentforNode(val);
				if (val<parent->data) parent->left = NULL;
				else parent->right = NULL;
			}
			else root = NULL;
			delete (p);
		}
		//if the left child is not null
		else if (p->left != NULL&&p->right == NULL){
			if (p != root){
				Node* parent = findparentforNode(val);
				if (val<parent->data) parent->left = p->left;
				else parent->right = p->left;
			}
			else root = NULL;
			delete (p);
		}
		//if the right child is not null
		else if (p->left == NULL&&p->right != NULL){
			if (p != root){
				Node* parent = findparentforNode(val);
				if (val<parent->data) parent->left = p->right;
				else parent->right = p->right;
			}
			else root = NULL;
			delete (p);
		}
		//if both children are not null
		else{
			Node* righty = findrightnode(p->left);
			Node* parent = findparentforNode(righty->data);
			p->data = righty->data;
			if (parent != p) parent->right = righty->left;
			else p->left = righty->left;
		}
	}
}
//finds a node with a given value key
Node* BST::findNodebyvalue(valuetype key){
	Node* p = root;
	while ((p != NULL) && (p->data != key)){
		if (key<p->data)p = p->left;
		else p = p->right;
	}
	return p;
}
//finds the parent of a node with a given value key
Node* BST::findparentforNode(valuetype key){
	Node* p = root;
	Node* q = 0;
	while ((p != NULL) && (p->data != key)){
		q = p;
		if (key<p->data)p = p->left;
		else p = p->right;
	}
	return q;
}
//finds the most right of a given node "p"
//the immediate succesor of "p" in inorder representation
Node* BST::findrightnode(Node* p){
	Node* righty = p;
	while (righty->right != NULL)
		righty = righty->right;
	return righty;
}
//inorder
void BST::inorder(Node* p){
	if (p != NULL){
		inorder(p->left);
		std::cout << p->data << " ";
		inorder(p->right);
	}
}
//postorder
void BST::preorder(Node* p){
	if (p != NULL){
		std::cout << p->data << " ";
		preorder(p->left);
		preorder(p->right);
	}
}
//postorder
void BST::postorder(Node* p){
	if (p != NULL){
		postorder(p->left);
		postorder(p->right);
		std::cout << p->data << " ";
	}
}
void BST::traverse(){
	std::cout << "Preorder: ";
	preorder(root);
	std::cout << std::endl << "Inorder: ";
	inorder(root);
	std::cout << std::endl << "PostOrder: ";
	postorder(root);
	std::cout << std::endl;
}
//to print tree hightwise i.e. all nodes at h1, then all nodes at h2, then at h3
void BST::custom_print(){
	//Node* temp;
	if (root == NULL)
		return;
	std::queue<Node*> Q;
	Q.push(root);
	//Q.push(NULL);
	while (!Q.empty()){
		current = Q.front();
		std::cout << current << " ";
		Q.pop();
		Q.push(current->left);
		Q.push(current->right);
	}
}