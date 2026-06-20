#include <iostream>
#include <string>
using namespace std;

string customerName, contactNo, orderType;
int persons;

string foodItems[8] = {"Chicken Burger","Zinger Burger","Pizza Small","Pizza Large",
"Chicken Biryani","BBQ Platter","Fries","Cold Drink"};

double prices[8] = {450,550,900,1800,350,1200,250,120};

double foodBill=0, serviceCharges=0, gst=0, discount=0, totalBill=0;

int  registerCustomer()
{
    cout<<"Enter Customer Name: ";
    cin>>customerName;
    cout<<"Enter Contact Number: ";
    cin>>contactNo;
    cout<<"Enter Order Type: ";
    cin>>orderType;
    cout<<"Enter Number of Persons: ";
    cin>>persons;
}

int displayMenu()
{
    cout<<"\nFood Menu\n";
    for(int i=0;i<8;i++)
        cout<<i+1<<". "<<foodItems[i]<<" RS. "<<prices[i]<<endl;
}

int  placeOrder()
{
    int itemNo, qty;
    char choice;

    do
    {
        displayMenu();
        cout<<"Enter Item Number: ";
        cin>>itemNo;
        cout<<"Enter Quantity: ";
        cin>>qty;

        foodBill += prices[itemNo-1] * qty;

        cout<<"Add More Items? (Y/N): ";
        cin>>choice;

    }while(choice=='Y' || choice=='y');
}

int  calculateServiceCharges()
{
    if(orderType=="Dine-in" || orderType=="dine-in")
        serviceCharges = foodBill * 0.10;
    else
        serviceCharges = foodBill * 0.05;
}

void calculateGST()
{
    gst = foodBill * 0.16;
}

int  calculateDiscount()
{
    if(foodBill >= 3000 && foodBill <= 5000)
        discount = foodBill * 0.05;
    else if(foodBill >= 5001 && foodBill <= 10000)
        discount = foodBill * 0.10;
    else
        discount = 0;
}

int  displayFinalBill()
{
    totalBill = foodBill + serviceCharges + gst - discount;

    cout<<"\nRestaurant Bill\n";
    cout<<"Customer Name: "<<customerName<<endl;
    cout<<"Order Type: "<<orderType<<endl;
    cout<<"Number of Persons: "<<persons<<endl;
    cout<<"Food Bill: Rs. "<<foodBill<<endl;
    cout<<"Service Charges: Rs. "<<serviceCharges<<endl;
    cout<<"GST: Rs. "<<gst<<endl;
    cout<<"Discount: Rs. "<<discount<<endl;

    if(foodBill > 5000)
        cout<<"Free Delivery Added"<<endl;

    cout<<"Total Payable Amount: Rs. "<<totalBill<<endl;
    cout<<"Enjoy your meal!"<<endl;
}

void customerDetails()
{
    cout<<"Customer Name: "<<customerName<<endl;
    cout<<"Contact Number: "<<contactNo<<endl;
    cout<<"Order Type: "<<orderType<<endl;
    cout<<"Persons: "<<persons<<endl;
}

int main()
{
    int choice;

    do
    {
        cout<<"\nRestaurant Management System\n";
        cout<<"1. Register Customer\n";
        cout<<"2. View Food Menu\n";
        cout<<"3. Place Order\n";
        cout<<"4. Calculate Bill\n";
        cout<<"5. View Customer Details\n";
        cout<<"6. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: registerCustomer(); break;
            case 2: displayMenu(); break;
            case 3: placeOrder(); break;
            case 4:
                calculateServiceCharges();
                calculateGST();
                calculateDiscount();
                displayFinalBill();
                break;
            case 5: customerDetails(); break;
            case 6: cout<<"Thank You"; break;
            default: cout<<"Invalid Choice";
        }

    }while(choice != 6);

    return 0;
}

