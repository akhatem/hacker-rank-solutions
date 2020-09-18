#include <bits/stdc++.h>

using namespace std;

class List{
private:
    typedef struct node{
        node* next;
        string data;
    }* nPtr;

    nPtr h, c, t;

public:
    List();
    void AddNode(string data);
    void DelNode(string data);
    void AddAtBegin(string data);
    void AddAtGivenPostion(string data, string pd);
    void PrintList();
};

void List::AddAtBegin(string data){
    nPtr n = new node;
    n->data = data;
    if (h != NULL){
        n->next = h;
        h = n;
    }
    else{
        n->next = NULL;
        h = n;
    }
}

int main(){
  return 0;
}
