class Trie {
public:
    /** Initialize your data structure here. */

    struct TrieNode{

        TrieNode *children[26];
        bool end;

        TrieNode()
        {
            end = false;
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
            }

        }
    };

    TrieNode *root;
    Trie() 
    {

        root = new TrieNode();

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
       // cout<<"HERE"<<endl;
        TrieNode *temp = root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                TrieNode *node = new TrieNode;
                temp->children[word[i]-'a']= node;
            }

            temp = temp->children[word[i]-'a'];
        }
        TrieNode *node = new TrieNode;
        temp->end = true;

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        TrieNode *temp = root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                return 0;
            }

            temp = temp->children[word[i]-'a'];
        }

        if(temp->end==false)
            return 0;
        return 1;


    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {

        TrieNode *temp = root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                return 0;
            }

            temp = temp->children[word[i]-'a'];
        }


        return 1;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */ 