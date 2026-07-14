#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0, Node* n = NULL) : data(d), next(n) {}
};

class List {
private:
    Node* head;
    int length;

public:
    List() : head(NULL), length(0) {}

    List(const List& other) : head(NULL), length(0) {
        Node* p = other.head;
        Node* tail = NULL;
        while (p) {
            Node* newNode = new Node(p->data);
            if (!head) {
                head = newNode;
                tail = head;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            ++length;
            p = p->next;
        }
    }

    ~List() {
        Node* p = head;
        while (p) {
            Node* q = p;
            p = p->next;
            delete q;
        }
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* p = head;
            while (p->next) p = p->next;
            p->next = newNode;
        }
        ++length;
    }

    void travalList() const {
        Node* p = head;
        while (p) {
            cout << "->" << p->data;
            p = p->next;
        }
        cout << endl;
    }

    void getLength() const {
        cout << "The length of this List is " << length << "." << endl;
    }
};

//StudybarCommentBegin
int main(void)
{
    int n;
    List  listA;

    cin >> n;
    while (n != -1)
    {
        listA.append(n);
        cin >> n;
    }
    
    listA.travalList();
    List listB(listA);
    listA.append(250);
    listB.getLength();
    listB.travalList();
}
//StudybarCommentEnd