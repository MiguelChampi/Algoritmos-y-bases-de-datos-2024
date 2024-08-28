#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {};
    Node(int val, Node* siguiente) : data(val), next(siguiente) {};
};

struct ListNode
{
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {};
    ListNode(int val, ListNode* siguiente) : data(val), next(siguiente) {};
};

class List {

public:
    List():head(NULL){};
    ~List() {
        clear();
    }
    Node* headshow(){return head;};
    void headset(Node* newhead){head=newhead;};
    void display();
    void pushfront(int num);
    void pushback(int num);
    int popfront();
    int popback();
    void insert(int num, int pos);
    void clear();
    int front();
    int back();
    int size();
    int Nnume(int pos);
    bool empty();
    void reverse();
    int find(int num);
    void remove(int num);
    void sort();

private:
    Node* head;
};

void List::display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};
void List::pushfront(int num) {
    Node* pushing = new Node(num);
    pushing->next = head;
    head = pushing;
};
void List::pushback(int num) {
    Node* newNode = new Node(num);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
};
int List::popfront() {
    int aux;
    Node* temp = head;
    aux=temp->data;
    head = head->next;
    delete temp;
    return aux;
};
int List::popback() {
    int aux;
    if(head->next == NULL)
    {
        aux=head->data;
        delete head;
        head = NULL;
    }
    else{
        Node* temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;
        aux=temp->data;
        delete temp->next;
        temp->next = NULL;
    }
    return aux;
};
void List::insert(int num, int pos) {
    Node* nodo = new Node(num);
    Node* temp = head;
    int i = 0;
    while(i++ < pos - 1) temp = temp->next;
    nodo->next = temp->next;
    temp->next = nodo;
};
void List::clear() {
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};


int List::front() {
    return head->data;
};
int List::back() {
    Node* temp = head;
    while (temp->next != NULL){temp = temp->next;}
    return temp->data;

};
int List::size() {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
};
int List::Nnume(int pos) {
    Node* temp = head;
    int i = 0;
    while(i++ < pos - 1) temp = temp->next;
    return temp->data;
};
bool List::empty(){
    if (head == NULL)
        return true;
    return false;
};
int List::find(int num) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->data == num)
            count++;
        temp = temp->next;
    }
    return count;
};


//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
//AQUIIIIIIIIIII

void List::remove(int val) {
    Node* temp1 = head;
    if(temp1==NULL){
        return;
    }
    Node* temp2 = temp1->next;
    while(temp1->data==val && temp2 != NULL){
        head=head->next;
        delete temp1;
        temp1=head;
        temp2 = temp1->next;
    }

    while (temp2 != NULL) {
        if (temp2->data == val){
            Node* temp3 = temp2;
            temp2 = temp2->next;
            temp1->next=temp2;
            delete temp3;}
        else {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    if(head->data== val){
        temp1=head;
        head= nullptr;
        delete temp1;
    }
};

//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
//AQUIIIIIIIIIII
void List::reverse() {
    Node* temp = head;
    Node* temp2 = temp->next;
    Node* temp3 = temp2->next;
    temp->next = NULL;
    while (temp2 != NULL) {
        temp3 = temp2->next;
        temp2->next = temp;
        temp = temp2;
        temp2 = temp3;
    }
    head = temp;
};

void List::sort() {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node* sorted = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

int bit2dec(List num) {
    int dec = 0;
    while (!num.empty()) {
        dec *=2;
        dec = dec + num.popfront();
        }
    return dec;
};

List merge(List& l1, List& l2) {
    List result;
    while (!l1.empty() && !l2.empty()) {
        if (l1.front() <= l2.front()) {
            result.pushback(l1.popfront());
        } else {
            result.pushback(l2.popfront());
        }
    }

    // Agregar elementos restantes de l1
    while (!l1.empty()) {
        result.pushback(l1.popfront());
    }

    // Agregar elementos restantes de l2
    while (!l2.empty()) {
        result.pushback(l2.popfront());
    }

    return result;
}

Node* remove(int num, Node* cabeza) {
    Node* temp1 = cabeza;
    Node* temp2 = temp1->next;

    while(temp1->data==num && temp2 != NULL){
        cabeza=cabeza->next;
        delete temp1;
        temp1=cabeza;
        temp2 = temp1->next;
    }

    while (temp2 != NULL) {
        if (temp2->data == num){
            Node* temp3 = temp2;
            temp2 = temp2->next;
            temp1->next=temp2;
            delete temp3;}
        else {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    if(cabeza->data== num){
        temp1=cabeza;
        cabeza= nullptr;
        delete temp1;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp1 = head;
        if(temp1==NULL){
            return head;
        }
        ListNode* temp2 = temp1->next;
        while(temp1->data==val && temp2 != NULL){
            head=head->next;
            delete temp1;
            temp1=head;
            temp2 = temp1->next;
        }

        while (temp2 != NULL) {
            if (temp2->data == val){
                ListNode* temp3 = temp2;
                temp2 = temp2->next;
                temp1->next=temp2;
                delete temp3;}
            else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        if(head->data== val){
            temp1=head;
            head= nullptr;
            delete temp1;
        }
        return head;
    }
};

int main() {
    List Pruebas;
    Solution testing;
    Pruebas.pushfront(5);
    Pruebas.pushfront(4);
    Pruebas.pushfront(6);
    Pruebas.pushfront(4);
    Pruebas.pushfront(4);
    Pruebas.pushfront(4);
    //testing.removeElements(Pruebas.headshow(), 4);

    /*
    Node ulti(3);
    Node terce(4, &ulti);
    Node segu(4, &terce);
    Node prime(2, &segu);
    Node* ver=remove(7, &prime);
    Pruebas.headset(ver);
     */
    Pruebas.display();

    return 0;
}
