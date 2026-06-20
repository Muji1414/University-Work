#include <iostream>
using namespace std;

// All Global Variables Here
string customerName, customerType, paymentMethod;
int customerId;
double grossBill = 0;
string itemsNames[9] = {"Wheat 20kg", "Sugar 1kg", "Daal Chana 1kg", "Daal Maash 1kg", "Cooking Oil 1 Liter", "White Flour 10kg", "Milk Pack", "Dozen Eggs", "Detergent" };
int itemPrices[9] = {3400, 210, 130, 145, 620, 1970, 370, 275, 710};
int itemsToCart[9];
int itemsToCartQuantity[9];

// Functions Declare Here
void customerInfo();
void groceryManue();
void mainManue();
void addToCart();
double calculateGrossBill();
double calculateSalesTax();
double calculateMembershipDiscount(double bill);
double calculateBillDiscount(double bill);
double calculateCardCharges(double bill);
double calculateLoyaltyPoints(double bill);
void viewCustomerDetails();
void displayFinalBill();

//MAIN FUNCTION ----------------------------------------------->
int main()
{
    //Call customer info function
    customerInfo();


    //Call main manue function here
    mainManue();

    return 0;
}

void customerInfo()
{
    cout << "~ Welcome to Suses Super Mart ~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                                 " << endl;

    // Ask customer name
    cout << "Please Enter Your Name: " << endl;
    getline(cin, customerName);

    // Ask customer Id
    cout << "---------" << endl;
    cout << "Enter you Customer ID: " << endl;
    cin >> customerId;

    // Ask customer type
    int askId;
    do
    {
        cout << "---------" << endl;
        cout << "Enter Your Customer Status. " << endl;
        cout << "Press 1 ---> 'Regular'" << endl;
        cout << "Press 2 ---> 'Member'" << endl;
        cin >> askId;

        if (askId == 1)
        {
            customerType = "Regular";
        }
        else if (askId == 2)
            customerType = "Member";
        else
            cout << "Invalid! Try again" << endl;

    } while (askId != 1 && askId != 2);

    // Payment Method
    int paymentAsk;
    do
    {
        cout << "---------" << endl;
        cout << "Enter your preferred payment method." << endl;
        cout << "Press 1 --------> 'Cash'" << endl;
        cout << "Press 2 --------> 'Card'" << endl;

        cin >> paymentAsk;
        
        if (paymentAsk == 1)
            paymentMethod = "Cash";
        else if (paymentAsk == 2)
            paymentMethod = "Card";
        else
            cout << "Invalid! Try again" <<endl;
    } while (paymentAsk != 1 && paymentAsk != 2);
}
//-------------------------------------------------------------------------


//Grocery Manue
void groceryManue()
{
    cout<<"\n";
    cout<<"_________________________________"<<endl;
    cout<<"\n";
    cout<<"~Items List & Prices~" << endl;
    cout<<"---------------------"<<endl;
    cout<<"\n";

    //Loop for printing items
    for(int i = 0; i < 9; i++)
    {
        cout<<i+1 <<":"<<itemsNames[i]<<" - Rs."<<itemPrices[i]<<endl;
    }
}
//----------------------------------------------------------------------


//Main Manue Here
void mainManue()
{
    int manueList;

    do
    {
        cout<<"\n";
        cout<<"\n";
        cout<<"_________________________________"<<endl;
        cout<<"~ Main Manue ~"<<endl;
        cout<<"\n";
        cout<<"1. View Grocery Items"<<endl;
        cout<<"2. Add Items to Cart"<<endl;
        cout<<"3. Calculate Bill"<<endl;
        cout<<"4. View Customer Details"<<endl;
        cout<<"5. Exit"<<endl; 
        cin>>manueList;

        //switch statment for print
        switch(manueList)
        {
            case 1:
            groceryManue();
            break;

            case 2:
            addToCart();
            break;

            case 3:
            displayFinalBill();
            break;

            case 4:
            viewCustomerDetails();
            break;

            case 5:
            cout<<"Thank you for your buisness...!(:"<<endl;
            break;

            default:
            cout<<"Invalid!" <<endl;
        }

    }while (manueList != 5);
    
}
//------------------------------------------------------------------------------------



//Add to cart function here
void addToCart()
{
    cout<<"\n";
        cout<<"\n";
        cout<<"_________________________________"<<endl;
    int itemNumber, itemQuantity;
    cout<<"Please add your items to cart."<<endl;
    
    do
    {
        cout<<"Item no: ";
        cin>>itemNumber;
    }while(itemNumber < 1 || itemNumber > 9);
    
    cout<<"Item Quantity: ";
    cin>>itemQuantity;

    itemsToCartQuantity[itemNumber - 1] += itemQuantity;

} 
//-----------------------------------------------------------------------------



//Gross bill function here
double calculateGrossBill()
{
    grossBill = 0;

    for(int i = 0; i < 9; i++)
    {
        grossBill +=itemsToCartQuantity[i] * itemPrices[i];
    }
    return grossBill;
}
//--------------------------------------------------------------------------------


//sales tax function here
double calculateSalesTax()
{
    double foodTotal = 0, nonFoodTotal = 0;

    for (int i = 0; i< 8; i++)
    {
        foodTotal += itemsToCartQuantity[i] * itemPrices[i];

        nonFoodTotal = itemsToCartQuantity[8] * itemPrices[8];

    }
    return (foodTotal * 0.05) + (nonFoodTotal * 0.10);
}
//------------------------------------------------------------------------------------



//Member discount funcion
double calculateMembershipDiscount(double bill)
{
    if(customerType == "Member")
        return bill * 0.07;
    return 0;
}
//---------------------------------------------------------------------------------




// bill discount functin here
double calculateBillDiscount(double bill)
{
    if(bill >= 10000) return bill * 0.10;
    else if(bill >= 5000) return bill * 0.05;
    return 0;
}
//------------------------------------------------------------------------------------



//card charges function
double calculateCardCharges(double bill)
{
    if(paymentMethod == "Card")
        return bill * 0.02;
    return 0;
}
//-----------------------------------------------------------



//Royalty point function here
double calculateLoyaltyPoints(double bill)
{
    return bill / 100;
}
//-----------------------------------------------------------




//Customer detail function here
void viewCustomerDetails()
{
    cout<<"~ CUSTOMER DETAILS ~"<<endl;
    cout<<"\n";
    cout<<"Name: "<<customerName<<endl;
    cout<<"ID: "<<customerId<<endl;
    cout<<"Type: "<<customerType<<endl;
    cout<<"Payment: "<<paymentMethod<<endl;
    cout<<"======================================"<<endl;
}
//-----------------------------------------------------------




//Final bill display here 
void displayFinalBill()
{
    double gross = calculateGrossBill();
    double tax = calculateSalesTax();
    double memberDiscount = calculateMembershipDiscount(gross);
    double billDiscount = calculateBillDiscount(gross);
    double afterDiscounts = gross + tax - memberDiscount - billDiscount;
    double cardCharges = calculateCardCharges(afterDiscounts);
    double totalBill = afterDiscounts + cardCharges;
    double newPoints = calculateLoyaltyPoints(totalBill);

    cout<<"\n";
    cout<<"\n";
    cout<<"~----- Suses Bill Portal ~-----"<<endl;
    cout<<"\n";
    cout<<"Customer Name: "<<customerName<<endl;
    cout<<"Customer Type: "<<customerType<<endl;
    cout<<"Payment Method: "<<paymentMethod<<endl;
    cout<<"\n";
    cout<<"Gross Bill: Rs. "<<gross<<endl;
    cout<<"Sales Tax: Rs. "<<tax<<endl;
    cout<<"Membership Discount: Rs. "<<memberDiscount<<endl;
    cout<<"Bill Discount: Rs. "<<billDiscount<<endl;
    cout<<"Card Charges: Rs. "<<cardCharges<<endl;
    cout<<"\n";
    cout<<"Generated Loyalty Points: "<<newPoints<<endl;

    int existingPoints;
    cout<<"Enter Existing Loyalty Points (0 if new): ";
    cin>>existingPoints;

    double totalPoints = newPoints + existingPoints;
    cout<<"Loyalty Points after Purchase: "<<totalPoints<<endl;

    int redeemChoice;
    cout<<"Press 1 to redeem, Press 2 to continue: ";
    cin>>redeemChoice;

    if(redeemChoice == 1)
    {
        totalBill -= totalPoints;
        cout<<"Loyalty points redeemed!"<<endl;
    }

    cout<<"---------------------------------------"<<endl;
    cout<<"Total Payable Amount: Rs. "<<totalBill<<endl;
    cout<<"\n";
    cout<<"Thank You For Shopping :)"<<endl;
    cout<<"\n";
    cout<<"======================================="<<endl;
}
//Tension Ends here :)