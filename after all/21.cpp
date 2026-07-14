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
};

//StudybarCommentBegin
int main(void)
{
    int n;
    List<int>  listA;

    cin >> n;
    while (n != -1)
    {
        listA.append(n);
        cin >> n;
    }
    
    listA.travalList();
    List<int> listB(listA);
    listA.append(250);
    cout << "The length of this List is " << listB.getLength() << "." <<endl;
    listB.travalList();
}
//StudybarCommentEnd