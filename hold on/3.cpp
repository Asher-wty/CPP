//StudybarCommentBegin
#include <iostream>
#include <string>
using namespace std;
class Person
{private:
 int age;
 public:
 virtual int getage(){return age;}

 public:
 void setage(int age)
 {this->age=age;
 }
};

class Student:public Person
{private:
  int id;
  int score;
  virtual int getid(){return id;}
  virtual int getscore(){return score;}
  
  
 public:
 void set(int age,int id,int score)
 {setage(age);
  this->id=id;
  this->score=score; 
 }
};
//StudybarCommentEnd

int main() {
    int n, i;
    cin >> n;
    Student* stus = new Student[n];
    for (i = 0; i < n; ++i) {
        int age, id, score;
        cin >> age >> id >> score;
        stus[i].set(age, id, score);
    }
    int maxIdx = 0;
    int maxScore = -1;
    typedef int (Student::*MemFun)();
    for (i = 0; i < n; ++i) {
        MemFun pGetScore;
        int* vptr = (int*)*(int*)(&stus[i]);
        *(void**)&pGetScore = (void*)vptr[2];
        int score = (stus[i].*pGetScore)();
        if (score > maxScore) {
            maxScore = score;
            maxIdx = i;
        }
    }
    Student& best = stus[maxIdx];
    MemFun pGetId;
    int* vptrBest = (int*)*(int*)(&best);
    *(void**)&pGetId = (void*)vptrBest[1];
    int id = (best.*pGetId)();
    int age = best.getage();
    cout << age << " " << id << " " << maxScore << endl;
    delete[] stus;
    return 0;
}