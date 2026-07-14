#include <iostream>
#include <vector>
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

    List(const vector<int>& v) : head(NULL), length(0) {
        for (size_t i = 0; i < v.size(); ++i) {
            append(v[i]);
        }
    }

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

    bool isEqual(const List& other) const {
        if (length != other.length) return false;
        Node* p = head;
        Node* q = other.head;
        while (p && q) {
            if (p->data != q->data) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }

    void connect(const List& other) {
        Node* p = other.head;
        while (p) {
            append(p->data);
            p = p->next;
        }
        cout << "After connect:" << endl;
    }
};

//StudybarCommentBegin
int main(void)
{
    int a;
    vector<int> in1, in2;
    while (cin >> a)
    {
        in1.push_back(a);
        if (getchar() == '\n')
            break;
    }
    while (cin >> a)
    {
        in2.push_back(a);
        if (getchar() == '\n')
            break;
    }
    List listA(in1), listB(in2);
    listA.travalList();
    listB.travalList();
    if (listA.isEqual(listB))
        cout << "They are the same LinkList." << endl;
    else
        cout << "They are different LinkList." << endl;
    listA.connect(listB);
    listA.getLength();
    listA.travalList();
}
//StudybarCommentEnd