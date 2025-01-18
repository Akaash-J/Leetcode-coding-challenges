typedef struct TrieNode{
    struct TrieNode* children[26];
    bool isend;
}TrieNode;

TrieNode* createNode(){
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isend = false;
    for(int i=0; i<26; i++){
        node->children[i] = NULL;
    }
    return node;
}


typedef struct {
    TrieNode* root;
} Trie;


Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* current = obj->root;
    while(*word){
        int index = *word - 'a';
        if(current->children[index] == NULL){
            current->children[index] = createNode();
        }
        current = current->children[index];
        word++;
    }
    current->isend = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* current = obj->root;
    while(*word){
        int index = *word - 'a';
        if(current->children[index] == NULL){
            return false;
        }
        current = current->children[index];
        word++;
    }
    return current->isend;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* current = obj->root;
    while(*prefix){
        int index = *prefix - 'a';
        if(current->children[index] == NULL){
            return false;
        }
        current = current->children[index];
        prefix++;
    }
    return true;
}

void freeTrieNode(TrieNode* node) {
    if (node == NULL) return;
    for (int i = 0; i < 26; i++) {
        freeTrieNode(node->children[i]);
    }
    free(node);
}

void trieFree(Trie* obj) {
    freeTrieNode(obj->root);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
