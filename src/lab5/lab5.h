#include <iostream>
#define vowel "ауоиэыяюеёАУОИЭЫЯЮЕЁ"
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
        void out();
        IntNode(char key){
            left = NULL;
            right = NULL; 
            visited = 0;
            this->key = key; 
            height = -1;
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
        static IntTree rand_tree_gen(int size);
        static IntTree sorted_tree_gen(int size);
        void dfs(IntNode * a);
        void dfs_support(IntNode * a); // NULL visited nodes
        void out();
        void insert(IntNode * rt, int key);
        IntNode * find(IntNode * rt, int key);
        int remove(IntNode*, int key);
        IntNode * find_min(IntNode * node);
        void find_height(IntNode * rt, int * mx);
        IntTree() : root(NULL), count(0) {};
        IntTree(IntNode * rt) : root(rt), count(1) {};
};

