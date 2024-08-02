class Node{
    public:
    char ch;
    Node* children[26];
    bool isEnd;

    Node(){
        ch = '\0';
        isEnd = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }

    void setEnd(){
        isEnd = true;
    }

    Node* get(char ch){
        return children[ch-'a'];
    }

    void put(char ch,Node* node){
        children[ch-'a'] = node;
    }

    bool containKey(char ch){
        if(children[ch-'a'] == NULL) return false;
        return true;
    }

    int count(){
        int count = 0;
        for(int i=0;i<26;i++){
            if(children[i]!=NULL) count++;
        }
        return count;
    }
};

class trie{
    public:
    Node* node;

    trie(){
        node = new Node();
    }

    void insertString(string word){
        Node* n1 = node;
        for(int i=0;i<word.size();i++){
            if(!(n1->containKey(word[i]))){
                n1->put(word[i],new Node());
            }
            n1->ch = word[i];
            n1 = n1->get(word[i]);
        }
        n1->setEnd();
    }

    string prefix(){
        string st= "";
        Node* n1 = node;
        while(!n1->isEnd){
            if(n1->count()==1){
                st += n1->ch;
            }
            else break;
            n1 = n1->get(n1->ch);
        }
        return st;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie* t = new trie();
        for(int i=0;i<strs.size();i++){
            t->insertString(strs[i]);
        }
        return t->prefix();
    }
};