//StudybarCommentBegin
#include <iostream>
using namespace std;

typedef struct tagNode
{
     int value;
     tagNode *pNext;
}Node;

class JTList
{
public:
     JTList() : m_pHead(NULL), m_pTail(NULL){};
     ~JTList();    
     Node *First() const;
     Node *Last() const;
     void Append(const int &);
private:
     Node *m_pHead;
     Node *m_pTail;
     long m_lCount;
};

JTList::~JTList()
{
     Node *pCurrent = m_pHead;
     Node *pNextNode = NULL;
     while (pCurrent)
     {
          pNextNode = pCurrent->pNext;
          delete pCurrent;
          pCurrent = pNextNode;
     }
}

void JTList::Append(const int &value)
{     // Create the new node
     Node *pInsertNode = new Node;
     pInsertNode->value = value;
     pInsertNode->pNext = NULL;
     // This list is empty
     if (m_pHead == NULL)
     {    m_pHead = m_pTail = pInsertNode;
	 }
     else
     {    m_pTail->pNext = pInsertNode;
          m_pTail = pInsertNode;
     }
     ++m_lCount;
}
//StudybarCommentEnd

Node* JTList::First() const {
    return m_pHead;
}
Node* JTList::Last() const {
    return m_pTail;
}

class Iterator {
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Node* CurrentItem() const = 0;
    virtual ~Iterator() {}
};

class JTListIterator : public Iterator {
private:
    JTList* m_pList;
    Node* m_pCurrent;
public:
    JTListIterator(JTList* pList) : m_pList(pList), m_pCurrent(nullptr) {}
    void First() override {
        m_pCurrent = m_pList->First();
    }
    void Next() override {
        if (m_pCurrent) m_pCurrent = m_pCurrent->pNext;
    }
    bool IsDone() const override {
        return m_pCurrent == nullptr;
    }
    Node* CurrentItem() const override {
        return m_pCurrent;
    }
};

class ArrayIterator : public Iterator {
private:
    Node* m_pArray;
    int m_size;
    int m_index;
public:
    ArrayIterator(Node* pArray, int size) : m_pArray(pArray), m_size(size), m_index(0) {}
    void First() override {
        m_index = 0;
    }
    void Next() override {
        ++m_index;
    }
    bool IsDone() const override {
        return m_index >= m_size;
    }
    Node* CurrentItem() const override {
        return &m_pArray[m_index];
    }
};

int findMaxValue(Iterator* pIterator) {
    pIterator->First();
    if (pIterator->IsDone()) return -1;
    int maxVal = pIterator->CurrentItem()->value;
    for (pIterator->Next(); !pIterator->IsDone(); pIterator->Next()) {
        int val = pIterator->CurrentItem()->value;
        if (val > maxVal) maxVal = val;
    }
    return maxVal;
}

//StudybarCommentBegin
int findValue(Iterator *pIterator,int value)
{    int i=0;
     for (pIterator->First(); !pIterator->IsDone(); pIterator->Next())
     {   if(pIterator->CurrentItem()->value==value) {return i;}
         i++;
	 }
     return -1;
}

int main()
{    //This is a List
     JTList *pJTList = new JTList;
     int i;
     for(i=0;i<20;i++)
      {
	  pJTList->Append(i*10);
      }
     //This is an Array
     Node temp[10]={{0,NULL},{9,NULL},{8,NULL},{7,NULL},{6,NULL},{5,NULL},{4,NULL},{3,NULL},{2,NULL},{1,NULL}};

     Iterator *pListIterator = new JTListIterator(pJTList);
     Iterator *pArrayIterator = new ArrayIterator(temp,10);
     int x,y,z;
     cin>>x>>y>>z;
     pJTList->Append(z);
     cout<<"\nIn the list, findValue give the index: "<<findValue(pListIterator,x);
     cout<<"\nIn the Array, findValue give the index: "<<findValue(pArrayIterator,y);

     cout<<"\nIn the list, the Max Value is: "<<findMaxValue(pListIterator);
     cout<<"\nIn the Array, the Max Value is: "<<findMaxValue(pArrayIterator);

     delete pListIterator;
     delete pJTList;
     delete pArrayIterator;

     return 0;
}

//StudybarCommentEnd