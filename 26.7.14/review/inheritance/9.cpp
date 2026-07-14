#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void bark() const { cout << "Animal::bark()" << endl; }
    int TellAge() const {cout<<"The animal's age is "<<Age<<endl; return Age; }
    unsigned int Age;
    Animal(int Age=1) {this->Age=Age;}
};
class Cat : public Animal
{
public:
    void bark() const { cout << "miaomiao" << endl; }
};
class Dog : public Animal
{
public:
    void bark() const { cout << "wangwang" << endl; }
};
class Duck : public Animal
{
public:
    void bark(){ cout << "gaga" << endl; }
};
class Bird : public Animal{
        unsigned int WingNum;
    public:
        void bark() const {cout<<"jiji"<<endl;}
        int TellAge() const {cout<<"I am a bird with "<<WingNum<<" Wings, my age is "<<Age<<endl; return Age; }
        Bird(int a):Animal(a),WingNum(2){}
};
void AnimalBark_Ref(Animal &a) { a.bark(); }
void AnimalBark_Pointer(Animal *a) { a->bark(); /*  (a*).bark  */ a->TellAge();}
void AnimalBark_Var(Animal a) { a.bark(); }
//StudybarCommentBegin
int main()
{	Cat c;
	Dog d;
	Duck du;
	Bird *pbird=new Bird(3);

    cout<<"This sizeof(Animal):"<<sizeof(Animal)<<endl;
    cout<<"This sizeof(c):"<<sizeof(c)<<endl;
    cout<<"This sizeof(d):"<<sizeof(d)<<endl;
    cout<<"This sizeof(du):"<<sizeof(du)<<endl;
    cout<<"This sizeof(Bird):"<<sizeof(Bird)<<endl;
    cout<<"This sizeof(int *):"<<sizeof(int *)<<endl;

    cout<<"--by Pointer:"<<endl;
	AnimalBark_Pointer( &c);
	AnimalBark_Pointer( &d);
	AnimalBark_Pointer( &du);
	AnimalBark_Pointer( pbird);
	pbird->TellAge();
	return 0;
}
//StudybarCommentEnd