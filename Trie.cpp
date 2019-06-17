#include<iostream>

using namespace std;


struct node{
    bool endmark;
    node* next[26+1];

    node(){
        endmark=0;
        for(int i=0; i<26 ; i++){
            next[i]= NULL;
        }
    }

}*root;

void Insert(string str, int len){

    node* cur = root;
    for(int i=0 ; i< len; i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL){
            cur->next[id] = new node();
        }
        cur=cur->next[id];
    }
    cur->endmark=1;

}

bool Search(string str, int len){
    node* cur = root;
    for(int i=0 ; i<len ; i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL){
            return 0;
        }
        cur=cur->next[id];
    }
    return cur->endmark;
}

void del(node* cur){
    for(int i=0 ; i<26 ; i++){
        if(cur->next[i]!=NULL){
            del(cur->next[i]);
        }
        delete(cur);
    }
}

int main(){

    root = new node();

    cout << "Enter Number of Word" << endl;
    int num_word;
    cin >> num_word;

    cout << "Enter String : " << endl;
    for(int i=0 ; i<num_word ; i++){
        string s;
        cin >> s;
        Insert(s, s.size());
    }

    cout <<"Enter Number Of Query : " << endl;

    int Q;
    cin >> Q;
    while(Q--){
        string s;
        cin >> s;

        cout << Search(s, s.size()) << endl;
    }
    del(root);
    return 0;
}
