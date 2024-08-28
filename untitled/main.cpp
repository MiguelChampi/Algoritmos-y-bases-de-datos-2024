#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class List {
public:
    void display();
    void pushfront(int num);
    void pushback(int num);
    void popfront();
    void popback();
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
};
void List::pushfront(int num) {
    Node* pushing = new Node;
    pushing->data = num;
    pushing->next = head;
    head = pushing;
};
void List::pushback(int num) {
    Node* pushing = new Node;
    pushing->data = 5;
    Node* temp = head;
    while (temp->next !=NULL)
        temp = temp->next;
    temp->next = pushing;
    pushing->next = NULL;
};
void List::popfront() {
    Node* temp = head;
    head = head->next;
    delete temp;
};
void List::popback() {
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else{
        Node* temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
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
bool List::empty() {
    if(head == NULL)
        return true;
    else
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

// NO ENCUENTRA EL DEL PRIMER VALOR, VERIFICAR COMO HACERLO
void List::remove(int num) {
    Node* temp1 = head;
    Node* temp2 = temp1->next;
    Node* temp3;
    while (temp2 != NULL) {
        if (temp2->data == num){
            temp3 = temp2;
            temp2 = temp2->next;
            temp1->next=temp2;
            delete temp3;}
        else {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
};


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
    Node* sorted = NULL;
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        if (sorted == NULL || sorted->data >= temp->data) {
            temp->next = sorted;
            sorted = temp;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < temp->data) {
                temp = temp->next;
            }
            temp->next = temp->next;
            temp->next = temp;
        }
        temp = next;
    }
    head = sorted;
};//Use insertion sort y tambien otro de merge sort

void bit2dec(List num) {
    if (num.size() == 0)
        return;

    while (1) {

    }
};


int main()
{
    List Pruebas;
    Pruebas.pushfront(9);
    Pruebas.pushfront(7);
    Pruebas.pushfront(2);
    Pruebas.pushfront(1);
    Pruebas.pushfront(3);
    Pruebas.pushfront(2);
    Pruebas.pushfront(6);
    Pruebas.sort();
    Pruebas.display();
    cout << endl;
    Pruebas.reverse();
    Pruebas.display();
    return 0;
}
