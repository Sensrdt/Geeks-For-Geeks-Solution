#include<bits/stdc++.h>

using namespace std;

struct trie {
    unordered_map<char, trie*> trie_map;
    bool end_of_word;
};

trie* getNewNode(){
    trie* node = new trie;
    node->end_of_word = false;
    return node;
}

void insert(trie*& root, const string& s){
    if (root == nullptr){
        root = getNewNode();
    }

    trie* temp = root;
    for (int i=0; i<s.length(); i++){
        char x = s[i];

        if (temp->trie_map.find(x) == temp->trie_map.end()) {
            temp->trie_map[x] = getNewNode();
        }

        temp = temp->trie_map[x];
    }

    temp->end_of_word = true;
}

bool search(trie* root, const string& s){
    if (root == nullptr) return false;

    trie* temp = root;
    for (int i=0; i<s.length(); i++){
        temp = temp->trie_map[s[i]];

        if (temp == nullptr) return false;
    }

    return temp->end_of_word;
}
int main()
{
    int t; cin>>t;
    trie* root = nullptr;
    while(t--){
        int one_two;
        cout<<"1. Insert 2. Search\n";
        cin>>one_two;
        if (one_two == 1) {
            string s; cin>>s;
            insert(root, s);
        }else {
            string s; cin>>s;
            cout<<search(root, s)<<endl;
        }
        
    }
}