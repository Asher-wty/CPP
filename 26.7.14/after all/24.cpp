//StudybarCommentBegin
#include"iostream"
using namespace std;

template<typename T>
class List{
	private:
		T data;
		List *link;
	public:
		List();
		~List();  //这个析构有陷阱，有可能发生递归析构，请注意。
		void append(const T& val);	// 链尾增加一个元素
        void insertElement(int pos, const T& val);	// 在指定位置val后添加一个元素
        void deleteElement(const T& val);	// 删除所有值为val的元素 ， 有析构函数侯，这个delete也可能引起析构函数的调用。
        void travalList()const;	// 从头节点遍历输出链表

};


class Point{
private:
	int x,y;
public:
	Point(int nx=0,int ny=0){
		x=nx;y=ny;
		cout<<"\nPoint("<<x<<","<<y<<") is called!";
	}
	~Point(){
		cout<<"\n~Point("<<x<<","<<y<<") is called!";
	}
	friend ostream &operator<<(ostream& out,const Point &p);
	bool operator==( const Point &p)
	{
		if (x!=p.x || y!=p.y) return false;
		return true;
	}
};
//StudybarCommentEnd

template<typename T>
List<T>::List() : link(nullptr) {}

template<typename T>
List<T>::~List() {
    List* p = link;
    while (p) {
        List* q = p->link;
        p->link = nullptr;
        delete p;
        p = q;
    }
}

template<typename T>
void List<T>::append(const T& val) {
    List* newNode = new List;
    newNode->data = val;
    List* p = this;
    while (p->link) p = p->link;
    p->link = newNode;
}

template<typename T>
void List<T>::insertElement(int pos, const T& val) {
    List* newNode = new List;
    newNode->data = val;
    List* current = this;
    for (int i = 0; i <= pos; ++i) {
        if (!current->link) break;
        current = current->link;
    }
    newNode->link = current->link;
    current->link = newNode;
}

template<typename T>
void List<T>::deleteElement(const T& val) {
    bool found = false;
    List* p = this;
    while (p->link) {
        if (p->link->data == val) {
            List* toDelete = p->link;
            p->link = toDelete->link;
            toDelete->link = nullptr;
            delete toDelete;
            found = true;
        } else {
            p = p->link;
        }
    }
    if (!found) {
        cout << "\nElement " << val << " not Found.";
    }
}

template<typename T>
void List<T>::travalList() const {
    cout << "\n";
    const List* p = link;
    while (p) {
        cout << "->" << p->data;
        p = p->link;
    }
}

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

//StudybarCommentBegin
int main(void)
{
	List<Point> list;
	list.append(Point(1,2));
	list.append(Point(2,3));
	list.append(Point(3,4));
	list.append(Point(5,6));
    list.append(Point(1,2));
	list.travalList();

	list.insertElement(1, Point(7,8));
	list.travalList();

	list.deleteElement(Point(1,2));
    list.travalList();

    list.deleteElement(Point(7,8));
	list.travalList();
	list.deleteElement(Point(9,0));

}
//StudybarCommentEnd
