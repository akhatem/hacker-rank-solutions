/*
	Filename:  Merge two sorted Linked Lists
	created by: akhatem
*/
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

        if (node) {
            fout << sep;
        }
    }
}
void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& cout) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}



void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;
    
    SinglyLinkedListNode* t1 = head1;
    SinglyLinkedListNode* t2 = head2;
    SinglyLinkedListNode* head3 = nullptr;

    if(t1->data < t2->data){
    	head3 = t1;
    	t1 = t1->next;
    }
    else{
    	head3 = t2;
    	t2 = t2->next;
    }
    SinglyLinkedListNode* t3 = head3;

    while(t1 != NULL && t2 != NULL){
    	if(t1->data < t2->data){
    		t3->next = t1;
    		t1 = t1->next;
    	}
    	else{
    		t3->next = t2;
    		t2 = t2->next;
    	}
    	t3 = t3->next;
    }
    if(t1 == NULL){
    	t3->next = t2;
    }
    else{
    	t3->next = t1;
    }
   
	return head3;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";
        print_singly_linked_list(llist3, " ", cout);
        cout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
