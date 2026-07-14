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
    void insertElement(int pos, const T& val) {
        if (pos < 0) return;
        Node<T>* newNode = new Node<T>(val);
        if (pos == 0) {
            if (head) {
                newNode->next = head->next;
                head->next = newNode;
            } else {
                head = newNode;
            }
        } else {
            Node<T>* p = head;
            int i = 0;
            while (p && i < pos) {
                p = p->next;
                ++i;
            }
            if (p) {
                newNode->next = p->next;
                p->next = newNode;
            } else {
                delete newNode;
                return;
            }
        }
        ++length;
    }
    void deleteElement(const T& val) {
        bool found = false;
        while (head && head->data == val) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            --length;
            found = true;
        }
        if (!head) {
            if (!found) {
                cout << "Element " << val << " not Found." << endl;
            }
            return;
        }
        Node<T>* p = head;
        while (p->next) {
            if (p->next->data == val) {
                Node<T>* temp = p->next;
                p->next = temp->next;
                delete temp;
                --length;
                found = true;
            } else {
                p = p->next;
            }
        }
        if (!found) {
            cout << "Element " << val << " not Found." << endl;
        }
    }
    void travalList() const {
        Node<T>* p = head;
        while (p) {
            cout << "->" << p->data;
            p = p->next;
        }
        cout << endl;
    }
};

//StudybarCommentBegin
int main(void)
{
    List<int> list;
    list.append(10);
    list.append(8);
    list.append(12);
    list.append(100);
    list.append(8);
    list.travalList();

    list.insertElement(1, 20);
    list.travalList();

    list.deleteElement(2);
    list.deleteElement(10);
    list.travalList();

    list.deleteElement(8);
    list.travalList();
}
//StudybarCommentEnd