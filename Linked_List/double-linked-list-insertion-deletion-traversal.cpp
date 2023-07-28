#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void insertAtHead(Node* &head, int data){
    Node* new_node = new Node(data);
    if(head== nullptr){
        head = new_node;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head=new_node;
}

void insertAtEnd(Node* &head, int data){
    Node* new_node = new Node(data);
    if(head== nullptr){
        head = new_node;
        return;
    }
    Node *temp = head;
    while(temp->next!= nullptr)
        temp=temp->next;
    temp->next = new_node;
    new_node->prev=temp;
}

void insertAtAnyPosition(Node* &head, int data, int pos){

    if(head== nullptr || pos<=1){
        insertAtHead(head, data);
        return;
    }
    int count=1;
    Node *curr = head;
    while(count<pos-1 && curr->next!= nullptr){
        curr=curr->next;
        count++;
    }

    if(curr->next== nullptr){
        insertAtEnd(head, data);
        return;
    }

    Node* new_node = new Node(data);
    new_node->next = curr->next;
    curr->next->prev = new_node;
    curr->next = new_node;
    new_node->prev = curr;
}

void printDLL(Node* curr){
    while(curr!= nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

void deleteHead(Node* &head){
    if(head== nullptr) return;

    if(head->next == nullptr){
        delete head;
        head= nullptr;
        return;
    }

    Node *temp = head;
    head=head->next;
    delete temp;
}

void deleteEnd(Node* &head){
    if(head == nullptr){
        return;
    }
    if(head->next == nullptr){
        delete head;
        head= nullptr;
        return;
    }

    Node *curr = head;
    while(curr->next->next!= nullptr){
        curr=curr->next;
    }
    delete curr->next;
    curr->next= nullptr;
}


void deleteFromAnyPosition(Node* &head, int pos){
    if(head== nullptr || pos<=1){
        deleteHead(head);
        return;
    }

    int count=1;
    Node* curr = head;
    while(count<pos-1 && curr->next!= nullptr){
        curr = curr->next;
        count++;
    }
    if(curr->next->next== nullptr){
        deleteEnd(head);
        return;
    }

    Node *temp = curr->next;
    curr->next = curr->next->next;
    curr->next->prev = curr;
    delete temp;
}
int main(){

    Node *head = nullptr;

    //INSERTION:
    insertAtAnyPosition(head, 5, 0);
    insertAtAnyPosition(head, 4, 2);
    insertAtAnyPosition(head, 2, 23);
    insertAtAnyPosition(head, 3, 2);
    insertAtAnyPosition(head, 9, 4);
    printDLL(head);
    //DELETION:

    deleteFromAnyPosition(head, 5);
    printDLL(head);
}