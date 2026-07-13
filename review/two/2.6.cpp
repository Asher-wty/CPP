#include <iostream>
using namespace std;
class Account{
    double money;
    public:
        Account(double m):money(m){
            if(money<0) {
                money=0;
                cout<<"Error:Initial balance cannot be negative."<<endl;
            }
        };
        void debit(double t){
            if(t>money){
                cout<<"Debit amount exceeded account balance."<<endl;
            }
            else
            money-=t;
        }
        double getBalance() const{
            return money;
        }
        void credit(double t){
            money+=t;
        }
};

//StudybarCommentBegin
int main()
{
    Account account1(50.0);

    double withdrawalAmount;
//    cout<<"\nEnter withdrawal amount for account1:";
    cin>>withdrawalAmount;
    cout<<"\nattempting to subtract "<<withdrawalAmount<<" from account1 balance\n";
    
    account1.debit(withdrawalAmount);
    cout<<"account1 balance:$"<<account1.getBalance()<<endl;
    
    Account account2(-2);
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;
    account2.credit(156.4);
    cout<<"\nattempting to add "<<156.4<<" to account2\n";
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;

    return 0;
}
//StudybarCommentEnd