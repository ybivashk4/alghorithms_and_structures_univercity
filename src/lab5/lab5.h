#include <iostream>
#define vowel "aeiouyAEIOUY"
class CharNode;
class CharTree;
class CharNode {
    public:
        char key;
        CharNode *left;
        CharNode *right;
        CharNode *parent;
        bool visited;
        int height;
        void out();
        CharNode(char key){
            left = NULL;
            right = NULL; 
            parent = NULL;
            visited = 0;
            this->key = key; 
            height = -1;
        }
};

class IntNode{
    public:
        int key;
        IntNode *left;
        IntNode *right;
        IntNode *parent;
        bool visited;
        int height;
        int size;
        void out();
        int get_size() {
            int _size = 1;
            if (left!= NULL)
                _size += left->size;
            if (right!= NULL)
                _size += right->size;
            return _size;
        }
        void fix_size() {
            size = 1;
            if (left!= NULL)
                size += left->size;
            if (right!= NULL)
                size += right->size;
            
        };
        IntNode(int key){
            left = NULL;
            right = NULL; 
            parent = NULL;
            visited = 0;
            this->key = key; 
            height = -1;
            size = 1;
        }
};

class CharTree {
    private: 
        int count;
    public:
        CharNode *root;
        static CharTree rand_tree_gen(int size);
        static CharTree sorted_tree_gen(int size);
        void dfs(CharNode * a); // flag to choose function
        void dfs_support(CharNode * a); // NULL visited nodes
        void out();
        void insert(CharNode * rt, char key);
        CharNode * find(CharNode * rt, char key);
        char remove(CharNode*, char key);
        CharNode * find_min(CharNode * node);
        void find_height(CharNode * rt, int * mx);
        void target_func(CharNode * a, int *sheets_vowel);
        CharTree() : root(NULL), count(0) {};
        CharTree(CharNode * rt) : root(rt), count(1) {};


};

class IntTree {
    private: 
        int count;
    public:
        IntNode *root;
        // bin tree search
        static IntTree rand_tree_gen(int size);
        static IntTree sorted_tree_gen(int size);
        //random tree 
        static IntTree rand_rand_tree_gen(int size);
        static IntTree rand_sorted_tree_gen(int size);

        void dfs(IntNode * a);
        void dfs_support(IntNode * a); // NULL visited nodes
        void out();
        void insert(IntNode * rt, int key);
        IntNode * find(IntNode * rt, int key);
        int remove(IntNode*, int key);
        IntNode * find_min(IntNode * node);
        
        IntTree() : root(NULL), count(0) {};
        IntTree(IntNode * rt) : root(rt), count(1) {};
        void find_height(IntNode * a, int * mx);
                // рандомизированное
        IntNode* rotate_right(IntNode* p);
        IntNode* rotate_left(IntNode* p);
        IntNode* insert_root(IntNode* p, int k);
        IntNode* insert_random(IntNode* p, int k);
};

