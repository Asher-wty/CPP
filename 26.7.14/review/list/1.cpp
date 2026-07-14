//StudybarCommentBegin
#include <iostream>
using namespace std;
class List
{
private:
	int data;	// 存储元素
	List *link;	// 下一元素结构的指针
public:
	List();
	void append(int val);	// 链尾增加一个元素
	void insertElement(int pos, int val);	// 在指定位置后添加一个元素
	void deleteElement(int val);	// 删除元素
	void travalList()const;	// 从头节点遍历输出链表
};
//StudybarCommentEnd

List::List(): link(0){}

void List::append(int val){
    List * p=this;
    while (p->link != 0){
        p=p->link;
    }
    p->link=new List;
    p->link->data=val;
}

void List::insertElement(int pos, int val){
    List* p=this;
    int cnt=0;
    while(p->link != 0 && cnt < pos + 1){
        p=p->link;
        ++cnt;
    }
    if(cnt == pos + 1){
        List * newval=new List;
        newval->link=p->link;
        newval->data=val;
        p->link=newval;
    }
}

void List::deleteElement(int val){
    List *p=this;
    while(p->link != 0 && p->link->data != val){
        p=p->link;
    }
    if(p->link != 0){
        List * del=p->link;
        p->link=del->link;
        delete del;
    } else {
        cout << "Element " << val << " not Found." << endl;
    }
}

void List::travalList() const{
    const List *p=this->link;
    while(p != 0){
        cout << "->" << p->data;
        p=p->link;
    }
    cout << endl;
}

//StudybarCommentBegin
int main(void)
{
	List list;
	list.append(10);
	list.append(8);
	list.append(12);
	list.append(100);
	list.travalList();
	list.insertElement(1, 20);
	list.travalList();
	list.deleteElement(2);
	list.deleteElement(10);
	list.travalList();
}
//StudybarCommentEnd