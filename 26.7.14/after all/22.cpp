#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& d = T(), Node* n = nullptr) : data(d), next(n) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    int length;
public:
    List() : head(nullptr), length(0) {}

    List(const T* arr, int len) : head(nullptr), length(0) {
        for (int i = 0; i < len; ++i) {
            append(arr[i]);
        }
    }

    List(const List& other) : head(nullptr), length(0) {
        Node<T>* p = other.head;
        Node<T>* tail = nullptr;
        while (p) {
            Node<T>* newNode = new Node<T>(p->data);
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
        Node<T>* p = head;
        while (p) {
            Node<T>* q = p;
            p = p->next;
            delete q;
        }
    }

    void append(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* p = head;
            while (p->next) p = p->next;
            p->next = newNode;
        }
        ++length;
    }

    void travalList() const {
        Node<T>* p = head;
        while (p) {
            cout << "->" << p->data;
            p = p->next;
        }
        cout << endl;
    }

    int getLength() const {
        return length;
    }

    bool isEqual(const List& other) const {
        if (length != other.length) return false;
        Node<T>* p = head;
        Node<T>* q = other.head;
        while (p && q) {
            if (p->data != q->data) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }

    void connect(const List& other) {
        Node<T>* p = other.head;
        while (p) {
            append(p->data);
            p = p->next;
        }
    }
};

//StudybarCommentBegin
int main()
{
    int a, i, lengthA, lengthB;
    int in1[100], in2[100];

    for (i = 0, lengthA = 1; cin >> a; i++, lengthA++){
        in1[i] = a;
        if('\n' == getchar()){
            break;
        }
    }
    for (i = 0, lengthB = 1; cin >> a; i++, lengthB++){
        in2[i] = a;
        if('\n' == getchar()){
            break;
        }
    }
    List<int> listA(in1, lengthA), listB(in2,lengthB);

    listA.travalList();
    listB.travalList();
    if (listA.isEqual(listB))
        cout << "They are the same LinkList." << endl;
    else
        cout << "They are different LinkList." << endl;
    listA.connect(listB);
    cout << "After connect:" << endl;
    cout << "The length of this List is " << listA.getLength() << "." <<endl;
    listA.travalList();
}
//StudybarCommentEnd