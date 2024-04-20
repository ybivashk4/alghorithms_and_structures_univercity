#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include "lab5.h"
using namespace std;

int main () {
    srand(time(NULL));
    
    // ключи - 10 50 100 150 200
    int sizes[5] = {5000, 10000, 15000, 20000, 25000};
    int height = -2;
    
    for (auto &size : sizes) {
        IntTree tree;
        for (int i = 0; i < size; i++) {
            tree.insert(tree.root, rand());
        }
        tree.find_height(tree.root, &height);
        cout << size << " " << height << endl;
        height = -2;
    }
    
    for (auto &size : sizes) {
        IntTree tree = IntTree::sorted_tree_gen(size);
        tree.find_height(tree.root, &height);
        cout << size << " " << height << endl;
        height = -2;
    }

    for (auto &size : sizes) {
        IntTree tree = IntTree::rand_rand_tree_gen(size);
        tree.find_height(tree.root, &height);
        cout << size << " " << height << endl;
        height = -2;
    }
    height = -2;
    for (auto &size : sizes) {
        IntTree tree = IntTree::rand_sorted_tree_gen(size);
        tree.find_height(tree.root, &height);
        cout << size << " " << height << endl;
        height = -2;
    }
    // rand gen
    
    CharTree targetTree;
    char start_low = 'a';
    char start_up = 'A';
    
    for (int i = 0; i < 52; i++) {
        targetTree.insert(targetTree.root, (i%2 ? start_low+i/2 : start_up + i/2));
    }
    targetTree.out();
    cout << "find nodes with keys z, a, J\n";
    targetTree.find(targetTree.root, 'z')->out();
    targetTree.find(targetTree.root, 'a')->out();
    targetTree.find(targetTree.root, 'J')->out();
    cout << "\nbefore removing\n";

    targetTree.out();
    
    for (int i = 0; i < 52; i++) {
        targetTree.remove(targetTree.root, (i%2 ? start_low+i/2 : start_up + i/2));
    }

    cout << "\nafter removing\n";
    targetTree.out();
    cout << "\ntarget func start\n";
    int res = 0;
    // g f a i y
    targetTree.insert(targetTree.root, 'g');
    targetTree.insert(targetTree.root, 'f');
    targetTree.insert(targetTree.root, 'a');
    targetTree.insert(targetTree.root, 'y');
    targetTree.insert(targetTree.root, 'i');
    targetTree.out();
    targetTree.target_func(targetTree.root, &res);
    cout << "num of vowels is " << res << endl;
    for (int i = 0; i < 52; i++) {
        targetTree.remove(targetTree.root, (i%2 ? start_low+i/2 : start_up + i/2));
    }
    res = 0;
    targetTree.insert(targetTree.root, 'g');
    targetTree.insert(targetTree.root, 'f');
    targetTree.insert(targetTree.root, 'b');
    targetTree.insert(targetTree.root, 'c');
    targetTree.out();
    cout << "num of vowels is " << res << endl;
    //cout << res << endl;
    
    return 0;
}

CharNode * CharTree::find(CharNode * node, char key) {
    if (node == NULL)   return NULL;
    else if (node->key == key)   return node;
    else if (node->key < key)   find(node->right, key);
    else    find(node->left, key);
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
            
            min->left = removed->left;
            if (min != removed->right) min->right = removed->right;
            removed->right->parent = min;
            removed->left->parent = min;
            min->parent = removed->parent;
            root = min;
        }
        else {
            removed->parent->right = min;
            min->left = removed->left;
            if (min != removed->right) min->right = removed->right;
            removed->left->parent = min;
            removed->right->parent = min;
            min->parent = removed->parent;
        }
        
        
    }
    else if (removed->left) {
        removed->left->parent = removed->parent;
        if (removed->parent) {
            if (removed->parent->right == removed) removed->parent->right = removed->left;
            else removed->parent->left = removed->left;
        }
        else {
            root = removed->left;
            root->parent = NULL;
        }
    }
    else if (removed->right){
        removed->right->parent = removed->parent;
        if (removed->parent) {
            if (removed->parent->right == removed) removed->parent->right = removed->right;
            else removed->parent->left = removed->right;
        }
        else {
            root = removed->right;
            root->parent = NULL;
        }

    }
    else if (removed == root){
        root = NULL;
    }
    else if (removed->parent->left == removed){
        removed->parent->left = NULL;
    }
    else if (removed->parent->right == removed) {
        removed->parent->right = NULL;
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
		dfs_support(root);
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
		dfs_support(root);
		static int cnt = 0;
		if (!a->visited){
            if (a->left == NULL && a->right == NULL &&  (strchr(vowel, a->key) != NULL)) (*sheets_vowel)++;
			a->visited = 1;
			cnt += 1;
		}
		if (cnt != this->count && a->left)
			target_func(a->left, sheets_vowel);
		if(cnt != this->count && a->right)
			target_func(a->right, sheets_vowel);

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
    char _key = removed->key;
    IntNode * l;
    IntNode * r;
    if (removed->left && removed->right) {
        
        IntNode * min = this->find_min(removed->right);
        if (removed->parent == NULL) {
            
            min->left = removed->left;
            if (min != removed->right) min->right = removed->right;
            removed->right->parent = min;
            removed->left->parent = min;
            min->parent = removed->parent;
            root = min;
        }
        else {
            removed->parent->right = min;
            min->left = removed->left;
            if (min != removed->right) min->right = removed->right;
            removed->left->parent = min;
            removed->right->parent = min;
            min->parent = removed->parent;
        }
        removed->left->fix_size();
        removed->right->fix_size();
        min->fix_size();
        
        
    }
    else if (removed->left) {
        removed->left->parent = removed->parent;
        if (removed->parent) {
            if (removed->parent->right == removed) removed->parent->right = removed->left;
            else removed->parent->left = removed->left;
        }
        else {
            root = removed->left;
            root->parent = NULL;
        }
        removed->left->fix_size();
    }
    else if (removed->right){
        removed->right->parent = removed->parent;
        if (removed->parent) {
            if (removed->parent->right == removed) removed->parent->right = removed->right;
            else removed->parent->left = removed->right;
        }
        else {
            root = removed->right;
            root->parent = NULL;
        }
        removed->right->fix_size();

    }
    else if (removed == root){
        root = NULL;
    }
    else if (removed->parent->left == removed){
        removed->parent->left = NULL;
        removed->parent->fix_size();
    }
    else if (removed->parent->right == removed) {
        removed->parent->right = NULL;
        removed->parent->fix_size();
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
                temp->fix_size();
                new_node->fix_size();
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
                temp->fix_size();
                new_node->fix_size();
				return;
			}
		}
	}else{
		root = new IntNode(key);
        root->fix_size();
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

void IntTree::dfs(IntNode * a){
	if (a){
		dfs_support(root);
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


IntTree IntTree::sorted_tree_gen(int size) {
    IntTree tree;
    tree.insert(tree.root, -1);
    int key = 0;
    for (int i = 0; i < size-1; i++) {
        key++;
        tree.insert(tree.root, key);
    }
    return tree;
}

IntTree IntTree::rand_rand_tree_gen(int size) {
    IntTree tree;
    tree.insert(tree.root, -1);
    for (int i = 0; i < size-1; i++) {
        tree.insert_random(tree.root, rand());
    }
    return tree;
}
IntTree IntTree::rand_sorted_tree_gen(int size) {
    IntTree tree;
    tree.insert(tree.root, -1);
    int key = 0;
    for (int i = 0; i < size-1; i++) {
        key++;
        tree.insert_random(tree.root, key);
    }
    return tree;
}


// рандомизированныое
// не тестилось 
IntNode* IntTree::rotate_right(IntNode* p) {
    IntNode* q = p->left;
    if (!q) return NULL;
    p->left = q->right;
    if (q->right)
        q->right->parent = p;
    q->right = p;

    if (p->parent) {
        if (p == p->parent->left)
            p->parent->left = q;
        else
            p->parent->right = q;
    }
    else {
        root = q;
    }
    p->parent = q;
    p->fix_size();
    q->fix_size();
    return q;
}
IntNode* IntTree::rotate_left(IntNode* q) {
    IntNode* p =  q->right;
    if (!p) return NULL;
    q->right = p->left;
    if (p->left)
        p->left->parent = q;
    p->left = q;

    if (q->parent) {
        if (q == q->parent->left)
            q->parent->left = q;
        else
            q->parent->right = q;
    }
    else {
        root = p;
    }
    q->parent = p;
    p->fix_size();
    q->fix_size();
    return p;
}
IntNode* IntTree::insert_root(IntNode* p, int k) {
	if (!p) {count++;return new IntNode(k);}

    if (p->key > k) {
        p->left = insert_root(p->left, k);
        p->fix_size();
        return rotate_right(p);
        
    }
    else {
        p->right = insert_root(p->right, k);
        p->fix_size();
        return rotate_left(p);
    }
    
}
IntNode* IntTree::insert_random(IntNode* p, int k) {
    if (!p) {count++;return new IntNode(k);}
    if (rand() % (p->size+1) == 0) {
        return insert_root(p, k);
    }
    if (p->key > k) {
        p->left = insert_random(p->left, k);
        p->left->parent = p;
        
    }
    else {
        p->right = insert_random(p->right, k);
        p->right->parent = p;
    }
    p->fix_size();
    return p;
}
