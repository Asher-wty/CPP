#include<iostream>
using namespace std;
class GradeBook{
    private:
        string course, instructor;
    public:
        GradeBook(string a, string b): course(a), instructor(b) {}
        string getInstructorName(){
            return instructor;
        }
        void setInstructorName(string set){
            instructor=set;
        }
        void displayMessage(){
            cout<<"Welcome to the grade book for\nCS101 Introduction to C++ Programming!\n"<<"This course is presented by: "<<instructor;
        }
};

//StudybarCommentBegin
int main()
{
   // create a GradeBook object; pass a course name and instructor name
   GradeBook gradeBook( 
      "CS101 Introduction to C++ Programming", "Professor Smith" );

   // display initial value of instructorName of GradeBook object
   cout << "gradeBook instructor name is: " 
      << gradeBook.getInstructorName() << "\n"; 

   // modify the instructorName using set function
   gradeBook.setInstructorName( "Assistant Professor Bates" );

   // display new value of instructorName
   cout << "new gradeBook instructor name is: " 
      << gradeBook.getInstructorName() << "\n";

   // display welcome message and instructor's name
   gradeBook.displayMessage(); 
   return 0; // indicate successful termination
} // end main

//StudybarCommentEnd