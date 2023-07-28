#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node* &head, int data){
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(Node* &head, int data){
    if(head== nullptr) {
        insertAtHead(head, data);
    }
    Node *temp = head;
    Node *new_node = new Node(data);
    while(temp->next!= nullptr)
        temp=temp->next;
    temp->next = new_node;
}

void insertion(Node* &head, int data, int pos){
    if(head== nullptr || pos<=1) {
        insertAtHead(head, data);
        return;
    }

    int count=1;
    Node *curr=head;
    while(count<pos-1 && curr->next!= nullptr){
        curr=curr->next;
        count++;
    }
    if(curr->next== nullptr) {
        insertAtEnd(head, data);
        return;
    }

    Node *new_node = new Node(data);
    new_node->next = curr->next;
    curr->next = new_node;

}

void deleteHead(Node* &head){
    if(head== nullptr) return;
    Node *temp = head;
    head=head->next;
    delete temp;
}

void deleteEnd(Node* &head){
    if(head== nullptr) return;  //LL Empty

    if(head->next == nullptr){  //LL containing one node.
        delete head;
        head = nullptr;
        return;
    }

    Node *curr = head;
    while(curr->next->next!= nullptr)
        curr=curr->next;
    delete curr->next;
    curr->next = nullptr;

}

void deletion(Node *&head, int pos){
    if(head== nullptr) return;

    if(head->next== nullptr || pos<=1){
        deleteHead(head);
        return;
    }

    int count=1;
    Node *curr=head;
    while(count<pos-1 && curr->next->next!= nullptr){
        curr = curr->next;
        count++;
    }

    if(curr->next->next == nullptr) {
        deleteEnd(head);
        return;
    }

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;


}



void printLL(Node* head){
    while(head!= nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){

    //INSERTION:
    Node *head = nullptr;
    insertion(head, 5, 0);
    insertion(head, 10, -1);
    insertion(head, 12, 100);
    insertion(head, 13, 2);
    insertion(head, 14, 5);
    printLL(head);    //10 13 5 12 14

    //DELETION:
    deletion(head, 7);
    deletion(head, 0);
    deletion(head, 1);
    deletion(head, 2);
    deletion(head, 3);
    deletion(head, 0);
    printLL(head); //10 13 5 12
}