#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include "lab5.h"
using namespace std;

int main () {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");
    // ключи - 10 50 100 150 200
    int sizes[5] = {1000, 5000, 10000, 20000, 30000};
    int height = -2;
    for (auto &size : sizes) {
        IntTree tree = IntTree::rand_tree_gen(size);
        tree.find_height(tree.root, &height);
        cout << size << " " << height << endl;
    }
    height = -2;
    for (auto &size : sizes) {
        IntTree tree = IntTree::sorted_tree_gen(size);
        tree.find_height(tree.root, &height);
        cout << size << " " << height << endl;
    }

    
    // don't work
     char start = 'а'; // without ё
    CharTree targetTree;
    for (int i = 0; i < 32; i++) {
        targetTree.insert(targetTree.root, start+i);
    }
     char _start = 'А'; // without ё
    for (int i = 0; i < 32; i++) {
        targetTree.insert(targetTree.root, _start+i);
    }
    targetTree.out();
    return 0;
}

CharNode * CharTree::find(CharNode * node, char key) {
    if (node == NULL)   return NULL;
    if (node->key == key)   return node;
    else if (node->key < key)   find(node->right, key);
    else    find(node->left, key);
    return NULL;
}


char CharTree::remove(CharNode * node, char key) {
    CharNode * removed = find(node, key);
    if (removed == NULL) return 0;
    char _key = removed->key;
    CharNode * l;
    CharNode * r;
    if (removed->left && removed->right) {
        CharNode * min = this->find_min(removed->right);
        if (removed->parent == NULL) {
            root = min;
            min->parent = removed->parent;
            min->left = removed->left;
            removed->left->parent = min;
            min->right = removed->right;
            removed->right->parent = min;
        }
        else {
            removed->parent->right = min;
            min->parent = removed->parent;
            min->left = removed->left;
            removed->left->parent = min;
            min->right = removed->right;
            removed->right->parent = min;
        }
    }
    else if (removed->left) {
        removed->left->parent = removed->parent;
        if (removed->parent) {
            removed->parent->left = removed->left;
        }
        else {
            root = removed->left;
            root->parent = NULL;
        }
    }
    else if (removed->right){
        removed->right->parent = removed->parent;
        if (removed->parent) {
            removed->parent->right = removed->right;
        }
        else {
            root = removed->right;
            root->parent = NULL;
        }
    }
    else if (node == root){
        root = NULL;
    }
    count--;
    delete removed;
    return _key;
} 

CharNode * CharTree::find_min(CharNode * node) {
    if (node) {
        CharNode * temp = node;
        while (temp->left) {
            temp = temp->left;
        }
        return temp;
    }
    return NULL;
}

void CharTree::insert(CharNode * node, char key){
    CharNode * temp = node;
	if (node){
		if (node->key - key == 0){
            // key already exist
			return;
		}else if (node->key < key){
			if (node->right){
                temp = node;
				insert(node->right, key);
			}
				
			else{
				CharNode * new_node = new CharNode(key);
				new_node->parent = temp;
				node->right = new_node;
				count++;
				return;
			}
		}else{
			if (node->left){
                temp = node;
				insert(node->left, key);
			}
			else{
				CharNode * new_node = new CharNode(key);
                new_node->parent = temp;
				node->left = new_node;
				count++;
				return;
			}
		}
	}else{
		root = new CharNode(key);
		count++;
		return;
	}

}

void CharTree::out(){
	cout.width(4);
	cout << "---------------------------------\n";
	cout << "self\t" << "left\t" << "right\t" << "parent\n";
	cout << "---------------------------------\n";
	dfs(this->root); 
	cout << "count of nodes: " << count << "\n";
}


void CharNode::out(){
	cout << "---------------------------------\n";
	cout.width(4);
	if (!this)
		cout << "Pointer error\n";
	else if (this->left && this->right)
		cout << this->key << "\t" << this->left->key << "\t" << this->right->key << "\t" << (parent ? parent->key : 0) << "\n";
	else if (this->left)
		cout << this->key << "\t" << this->left->key << "\t" << "0000" << "\t" << (parent ? parent->key : 0)<< "\n";
	else if (this->right)
		cout << this->key << "\t" << "0000" << "\t" << this->right->key << "\t" << (parent ? parent->key : 0)<< "\n";
	else
		cout << this->key << "\t" << "0000" << "\t" << "0000"<< "\t" << (parent ? parent->key : 0) <<"\n";
	cout << "---------------------------------\n\n";
}

// 1 - out all
void CharTree::dfs(CharNode * a){
	if (a){
		// dfs_support(root);
		static int cnt = 0;
		if (!a->visited){
			a->out();
			a->visited = 1;
			cnt += 1;
		}
		if (cnt != this->count && a->left)
			dfs(a->left);
		if(cnt != this->count && a->right)
			dfs(a->right);

		dfs_support(root);			
	}
}

void CharTree::target_func(CharNode * a, int *sheets_vowel){
	if (a){
		// dfs_support(root);
		static int cnt = 0;
		if (!a->visited){
            if (a->left == NULL && a->right == NULL &&  strchr(vowel, a->key)) (*sheets_vowel)++;
			a->visited = 1;
			cnt += 1;
		}
		if (cnt != this->count && a->left)
			dfs(a->left);
		if(cnt != this->count && a->right)
			dfs(a->right);

		dfs_support(root);			
	}
}

void CharTree::dfs_support(CharNode * a){
	static int cnt = 0;
	if (a->visited){
		a->visited = 0;
		cnt++;
	}
	if (cnt != this->count && a->left)
		dfs_support(a->left);
	if (cnt != this->count && a->right)
		dfs_support(a->right);
}

void CharTree::find_height(CharNode * a, int * mx) {
    if (a) {
        static int cnt = 0;
		if (!a->visited){
			if (a->parent) {
                a->height = a->parent->height + 1;
            }
            else {
                a->height = 1;
            }
            *mx = *mx > a->height? *mx : a->height;
			a->visited = 1;
			cnt += 1;
		}
		if (cnt != this->count && a->left)
			find_height(a->left, mx);
		if(cnt != this->count && a->right)
			find_height(a->right, mx);

		dfs_support(root);			
    }
}

CharTree CharTree::rand_tree_gen(int size) {
    CharTree tree;
    for (int i = 0; i < size; i++) {
        char key = rand() % 256;
        tree.insert(tree.root, key);
    }
    return tree;
}

CharTree CharTree::sorted_tree_gen(int size) {
    CharTree tree;
    char key = 255;
    for (int i = 0; i < size; i++) {
        key++;
        tree.insert(tree.root, key);
    }
    return tree;
}

IntNode * IntTree::find(IntNode * node, int key) {
    if (node == NULL)   return NULL;
    if (node->key == key)   return node;
    else if (node->key < key)   find(node->right, key);
    else    find(node->left, key);
    return NULL;
}


int IntTree::remove(IntNode * node, int key) {
    IntNode * removed = find(node, key);
    if (removed == NULL) return 0;
    int _key = removed->key;
    IntNode * l;
    IntNode * r;
    if (removed->left && removed->right) {
        IntNode * min = this->find_min(removed->right);
        if (removed->parent == NULL) {
            root = min;
            min->parent = removed->parent;
            min->left = removed->left;
            removed->left->parent = min;
            min->right = removed->right;
            removed->right->parent = min;
        }
        else {
            removed->parent->right = min;
            min->parent = removed->parent;
            min->left = removed->left;
            removed->left->parent = min;
            min->right = removed->right;
            removed->right->parent = min;
        }
    }
    else if (removed->left) {
        removed->left->parent = removed->parent;
        if (removed->parent) {
            removed->parent->left = removed->left;
        }
        else {
            root = removed->left;
            root->parent = NULL;
        }
    }
    else if (removed->right){
        removed->right->parent = removed->parent;
        if (removed->parent) {
            removed->parent->right = removed->right;
        }
        else {
            root = removed->right;
            root->parent = NULL;
        }
    }
    else if (node == root){
        root = NULL;
    }
    count--;
    delete removed;
    return _key;
} 

IntNode * IntTree::find_min(IntNode * node) {
    if (node) {
        IntNode * temp = node;
        while (temp->left) {
            temp = temp->left;
        }
        return temp;
    }
    return NULL;
}

void IntTree::insert(IntNode * node, int key){
    IntNode * temp = node;
	if (node){
		if (node->key - key == 0){
            // key already exist
			return;
		}else if (node->key < key){
			if (node->right){
                temp = node;
				insert(node->right, key);
			}
				
			else{
				IntNode * new_node = new IntNode(key);
				new_node->parent = temp;
				node->right = new_node;
				count++;
				return;
			}
		}else{
			if (node->left){
                temp = node;
				insert(node->left, key);
			}
			else{
				IntNode * new_node = new IntNode(key);
                new_node->parent = temp;
				node->left = new_node;
				count++;
				return;
			}
		}
	}else{
		root = new IntNode(key);
		count++;
		return;
	}

}

void IntTree::out(){
	cout.width(4);
	cout << "---------------------------------\n";
	cout << "self\t" << "left\t" << "right\t" << "parent\n";
	cout << "---------------------------------\n";
	dfs(this->root); 
	cout << "count of nodes: " << count << "\n";
}


void IntNode::out(){
	cout << "---------------------------------\n";
	cout.width(4);
	if (!this)
		cout << "Pointer error\n";
	else if (this->left && this->right)
		cout << this->key << "\t" << this->left->key << "\t" << this->right->key << "\t" << (parent ? parent->key : 0) << "\n";
	else if (this->left)
		cout << this->key << "\t" << this->left->key << "\t" << "0000" << "\t" << (parent ? parent->key : 0)<< "\n";
	else if (this->right)
		cout << this->key << "\t" << "0000" << "\t" << this->right->key << "\t" << (parent ? parent->key : 0)<< "\n";
	else
		cout << this->key << "\t" << "0000" << "\t" << "0000"<< "\t" << (parent ? parent->key : 0) <<"\n";
	cout << "---------------------------------\n\n";
}

// 1 - out all, 2 - height
void IntTree::dfs(IntNode * a){
	if (a){
		// dfs_support(root);
		static int cnt = 0;
		if (!a->visited){
			a->out();
			a->visited = 1;
			cnt += 1;
		}
		if (cnt != this->count && a->left)
			dfs(a->left);
		if(cnt != this->count && a->right)
			dfs(a->right);

		dfs_support(root);			
	}
}

void IntTree::dfs_support(IntNode * a){
	static int cnt = 0;
	if (a->visited){
		a->visited = 0;
		cnt++;
	}
	if (cnt != this->count && a->left)
		dfs_support(a->left);
	if (cnt != this->count && a->right)
		dfs_support(a->right);
}

void IntTree::find_height(IntNode * a, int * mx) {
    if (a) {
        static int cnt = 0;
		if (!a->visited){
			if (a->parent) {
                a->height = a->parent->height + 1;
            }
            else {
                a->height = 1;
            }
            *mx = *mx > a->height? *mx : a->height;
			a->visited = 1;
			cnt += 1;
		}
		if (cnt != this->count && a->left)
			find_height(a->left, mx);
		if(cnt != this->count && a->right)
			find_height(a->right, mx);

		dfs_support(root);			
    }
}

IntTree IntTree::rand_tree_gen(int size) {
    IntTree tree;
    int key = rand();
    for (int i = 0; i < size; i++) {
        tree.insert(tree.root, key);
    }
    return tree;
}

IntTree IntTree::sorted_tree_gen(int size) {
    IntTree tree;
    int key = 0;
    for (int i = 0; i < size; i++) {
        key++;
        tree.insert(tree.root, key);
    }
    return tree;
}