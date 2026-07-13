//StudybarCommentBegin
#include <iostream>  
using namespace std;  
class Skill {  
    int *nSkill;  
    public:  
        Skill(int n) {  
            nSkill = new int; 
            *nSkill = n;  
            cout << "member object "<< (*nSkill) <<" constructed" << endl;   
        }     
        ~Skill(){  
            cout << "member object "<< (*nSkill) <<" destructed" << endl;  
            delete nSkill;  
        }   
};  
class Bug {  
    private :  
        int nLegs; int nColor;  
    public:  
        int nType;  
        Bug (int legs, int color){  
            nLegs = legs;  
            nColor = color;  
            cout << "Bug object constructed" << endl;  
        }  
        ~Bug (){  
            cout << "Bug object destructed" << endl;  
        }   
        void PrintBug () { };  
};  

//StudybarCommentEnd
class FlyBug: public Bug{
    int nWings;
    Skill a,b;
    public:
        FlyBug(int a=0, int b=0, int c=0): nWings(c), a(a), b(b), Bug(a,b){
            cout<<"FlyBug object constructed"<<endl;
        }
        ~FlyBug(){
            cout<<"FlyBug object destructed"<<endl;
        }
};

//StudybarCommentBegin
int main() {   
    FlyBug flyBug(2,1,3);   
    return 0;  
}  

//StudybarCommentEnd