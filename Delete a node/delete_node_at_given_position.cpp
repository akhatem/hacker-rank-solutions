#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;
        node = node->next;
        if (node) fout << sep;
    }
}

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& cout) {
    while (node) {
        cout << node->data;
        node = node->next;
        if (node) cout << sep;
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
	SinglyLinkedListNode* t = head;
	int c=0;
	while(t != NULL){
		c++;
		t = t->next;
	}	
	pair <int, SinglyLinkedListNode*> pNode[c];
	t = head;
	for(int i=0; i<c; ++i){
		pNode[i] = make_pair(i,t);
		t = t->next;
	}
	if(position == 0){
		head = head->next;
		//pNode[position].second->next = pNode[position].second->next;
	}
	else pNode[position-1].second->next = pNode[position].second->next;
	return head;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);

    print_singly_linked_list(llist1, " ", fout);
    print_singly_linked_list(llist1, " ", cout);
    cout << "\n";
    fout << "\n";

    free_singly_linked_list(llist1);

    fout.close();

    return 0;
}
