#include<iostream>
#include<string>
using namespace std;
class Invoice{
    private:
        string num,des;
        int price,amount;
    public:
        Invoice(string a, string b, int c,int d) : num(a), des(b), price(d), amount(c){
            if (d<0) amount = 0;
            if (c<0) price = 0;
        }
        string getPartNumber(){
            return num;
        }
        string getPartDescription(){
            return des;
        }
        int getPricePerItem(){
            return price;
        }
        int getQuantity(){
            return amount;
        }
        int getInvoiceAmount(){
            return price*amount;
        }
        void setPartNumber(string a){
            num=a;
        }
        void setPartDescription(string a){
            des=a;
        }
        void setQuantity(int a){
            amount= a;
            if(amount<0) {amount = 0; cout<<"\nquantity cannot be negative. quantity set to 0.\n";}
        }
        void setPricePerItem(int a){
            price = (a<0? 0 : a);
        }

};



//StudybarCommentBegin
int main()
{
    // create an Invoice object
    Invoice invoice( "12345", "Hammer", 100, 5 );
    
    // display the invoice data members and calculate the amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    
    // modify the invoice data members
    invoice.setPartNumber( "123456" );
    invoice.setPartDescription( "Saw" );
    invoice.setQuantity( -5 ); // negative quantity, so quantity set to 0
    invoice.setPricePerItem( 10 );
    cout << "\nInvoice data members modified.\n";
    
    // display the modified invoice data members and calculate new amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd