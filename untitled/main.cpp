#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class List {

public:
    List():head(NULL){};
    ~List() {
        clear();
    }
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
    return head == nullptr;
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

void List::remove(int num) {
    Node* temp1 = head;
    Node* temp2 ;
    while (head != NULL && head->data == num) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    while (temp1 != NULL && temp1->next != NULL) {
        if (temp1->next->data == num) {
            temp2 = temp1->next;
            temp1->next = temp1->next->next;
            delete temp2;
        } else {
            temp1 = temp1->next;
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

int main() {
    List Pruebas;
    List Pruebas3;
    List Combinado;
    Pruebas.pushfront(2);
    Pruebas.pushfront(1);
    Pruebas.pushfront(4);
    Pruebas.pushfront(3);
    Pruebas.sort();
    Pruebas.display();
    cout << endl;
    Pruebas3.pushfront(5);
    Pruebas3.pushfront(8);
    Pruebas3.pushfront(6);
    Pruebas3.pushfront(7);
    Pruebas3.sort();
    Pruebas3.display();
    cout << endl;
    Combinado=merge(Pruebas3,Pruebas);
    Combinado.display();
    return 0;
}
