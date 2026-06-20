#include<iostream>
using namespace std;
#include<string>

//global customer data
string customerName;
string customerType;
int customerId;
int meterType;

//Funtion Protypes
void registerCustomer();
int displayMenu();
double calculateConsumptionCharges(int units);
double calculateGST(double amount);
double calculateIncomeTax(double amount);
double calculateElectricityDuty(double consumption);
double calculateFixedCharges(int units);
double calculateNewConnectionCharges();
void displayFinalBill();
void displayCustomerDetails();

int main()
{
	registerCustomer();
	int choice;
	
	do{
		choice=displayMenu();
		switch(choice)
		{
			case 1:
				displayFinalBill();
				break;
			case 2:
                cout << "New Connection Charges: Rs. "<<calculateNewConnectionCharges()<<endl;
                break;

            case 3:
                displayCustomerDetails();
                break;

            case 4:
                cout << "Program Exited Successfully."<<endl;
                break;

            default:
                cout << "Invalid Choice!"<<endl;
        }

    } while(choice != 4);

    return 0;	
			
		}
//Reigster customer
void registerCustomer()
{
	cout<<"------------Customer Registeration------------"<<endl;
    cout<<"Enter customer name: ";
    getline(cin,customerName);
    
    cout<<"Enter customer ID: ";
    cin>>customerId;
    
    cout<<"Enter customer type: "<<endl;
    cout<<"1- Household "<<endl;
    cout<<"2- Commercial "<<endl;
    cout<<"Enter choice"<<endl;
    
    int typeChoice;
    cin>>typeChoice;
    
    if(typeChoice==1){
    	customerType = "Household";
	}
	else{
		customerType= "Commercial";
	}
	cout<<"Meter Status"<<endl;
	cout<<"1. 1st Meter"<<endl;
	cout<<"2. 2nd Meter"<<endl;
	cout<<"Enter choice"<<endl;
	cin>>meterType;
}

//display menu
int displayMenu()
{
	int choice;
	
	cout<<"--------MAIN MENU---------"<<endl;
	cout<<"1.Calculate monthly electricity bill"<<endl;
	cout<<"2.Apply for a new connection"<<endl;
	cout<<"3.View customer details"<<endl;
	cout<<"4.Exit program"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
	
	return choice;
}

//consumption charges
double calculateConsumptionCharges(int units)
{
	double rates[8]=
	{   12.21,
        14.53,
        31.51,
        38.41,
        41.62,
        43.04,
        44.18,
        49.10
	};
	if(units<=100){
		return units*rates[0];
	}
	else if(units<=200){
		return units*rates[1];
	}
	else if(units<=300){
		return units*rates[2];
	}
	else if(units<=400){
		return units*rates[3];
	}
	else if(units<=500){
		return units*rates[4];
	}
	else if(units<=600){
		return units*rates[5];
	}
	else if(units<=700){
		return units*rates[6];
	}
	else{
		return units*rates[7];
	}
}
//GST
double calculateGST(double amount)
{
    return amount * 0.18;
}

//INCOME TAX
double calculateIncomeTax(double amount)
{
	if(customerType == "Houshold"){
		return amount*0.10;
	}
	else{
		return amount*0.15;
	}	
}
	
//Electricity duty
double calculateElectricityDuty(double consumption)
{
	return consumption*0.015;
}

//fixed charges
double calculateFixedCharges(int units)
{
	if(units<=300){
		return 0;
	}
	else if(units<=400){
		return 200;
	}
	else if(units<=500){
		return 400;
	}
	else if(units<=600){
		return 600;
	}
	else if(units<=700){
		return 800;
	}
	else{
		return 1000;
	}
}

//new connection charges
double calculateNewConnectionCharges()
{
	double meterCost = 15000;
	double cableCost = 10000;
	double securityCost = 25000;
	double additionalCharges;
	
	if(customerType == "Household"){
		if(meterType=1){
			additionalCharges = 2500;
		}
		else{
			additionalCharges = 5000;
		}
	}
	else{
		if(meterType==1){
			additionalCharges=35000;
		}
		else{
			additionalCharges=70000;
		}
	}
	double properConnectionCost = 250000;
	
	return meterCost+
	       cableCost+
	       securityCost+
	       additionalCharges+
	       properConnectionCost;
}

//display bill
void displayFinalBill()
{
	int units;
	
	cout<<"Enter units consumed: ";
	cin>>units;
	
	double consumption = calculateConsumptionCharges(units);
	double duty = calculateElectricityDuty(consumption);
    double fixedCharges =calculateFixedCharges(units);
    double gst =calculateGST(consumption);
    double incomeTax =calculateIncomeTax(consumption);    
	
	double meterRent = 250;
	double tvFee = 35;
	
	double totalBill = consumption+duty+fixedCharges+gst+incomeTax+meterRent+tvFee;
	
	cout<<"--------LESCO ELECTRICITY BILL--------"<<endl;
	
	cout<<"Customer name: "<<customerName<<endl;
	cout<<"Customer ID: "<<customerId<<endl;
	cout<<"Customer Type: "<<customerType<<endl;
	cout<<"Units Consumed: "<<units<<endl;
	
	cout<<" ELECTRICITY consumption charges: RS.  "<<consumption<<endl;
	cout<<" Electricity duty: RS. "<<duty<<endl;
	cout<<"Fixed charges: RS. "<<fixedCharges<<endl;
	cout<<"Meter Rent: RS. "<<meterRent<<endl;
	cout<<"TV fee: RS. "<<tvFee<<endl;
	cout<<"GST: RS. "<<gst<<endl;
	cout<<"Income tax: RS. "<<incomeTax<<endl;
	cout<<"Total Payable Bill: RS. "<<totalBill<<endl;
	cout << "-----------------------------------------"<<endl;	
}

//customer details
void displayCustomerDetails()
{
	cout<<"----------CUSTOMER DETAILS----------"<<endl;
	cout<< "Customer Name: "<<customerName<<endl;
    cout<< "Customer ID: "<<customerId<<endl;
    cout<< "Customer Type: "<<customerType<<endl;

    if(meterType == 1){
    	cout << "Meter Status: First Meter"<<endl;
	}
	else{
		cout << "Meter Status: Second Meter"<<endl;
	}
}	
	
	

	


