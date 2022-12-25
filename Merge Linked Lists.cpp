#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head) {

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}


bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}

void mergeList(Node* &head,Node* &head1,int m,int n){
Node* temp=head;
Node* temp1=head1;
Node* list3=new Node(temp->data);
Node* head3=list3;
Node* tail3=list3;
print(head3);
int a=1;
while(a<=(m+n)){
if(a>=(2*m)){
        cout<<a<<"yes";
    insertAtTail(tail3,temp1->data);
    temp1=temp1->next;
    print(head3);
}
else
{

     if(a%2==0){
     temp=temp->next;
     insertAtTail(tail3,temp->data);
     print(head3);
    }
    else{
    insertAtTail(tail3,temp1->data);
    temp1=temp1->next;
print(head3);
}}
a++;
}
print(head3);
}

int main() {

    //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
   // cout << node1 -> next << endl;
    Node* node2= new Node(0);
    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    Node* head1 = node2;
    Node* tail1 = node2;
    print(head);
    //print(head);
    insertAtTail(tail,1);
    insertAtTail(tail,5);
    insertAtTail(tail1,7);
    insertAtTail(tail1,2);
    insertAtTail(tail1,3);

    mergeList(head,head1,3,4);


    /*
    print(head);

    if(isCircularList(head)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    */


    return 0;
}
