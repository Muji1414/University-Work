	#include<iostream>
	#include<string>
	using namespace std;
	
	//global variables
	string userName;
	string email;
	string city;
	string customerType;
	
	string productNames[8]=
	{
	    "T-Shirt",
	    "Jeans",
	    "Shoes",
	    "Watch",
	    "Handbag",
	    "Headphones",
	    "Mobile Cover",
	    "Perfume"
	};
	double productPrices[8]=
	{
		1200,
	    3500,
	    5000,
	    2500,
	    4200,
	    3000,
	    700,
	    2800
	};
	double cartTotal=0;
	
	//Function Protypes
	void registerUser();
	int displayMenu();
	void displayProducts();
	void addProductToCart();
	double calculateProductTotal();
	double calculateGST(double total);
	double calculateDeliveryCharges();
	double calculateCustomerDiscount(double total);
	double calculateOrderDiscount(double total);
	double calculatePaymentCharges(double amount);
	void displayCheckoutBill();
	void displayUserDetails();
	
	int main()
	{
		registerUser();
		int choice;
		
		do
		{
			choice = displayMenu();
			switch(choice)
			{
				case 1:displayProducts();
				break;
				case 2:addProductToCart();
				break;
				case 3:displayCheckoutBill();
				break;
				case 4:displayUserDetails();
				break;
				case 5:
					cout<<"\nThank you for using the system\n";
					break;	
				
				default:
					cout<<"\nInvalid choice\n";
			}
		}
		while(choice != 5);
		
		return 0;
	}
	//register user
	void registerUser()
	{
		cout<<"--------REGISTER USER--------\n";
		
		cout<<"Enter username: ";
		getline(cin,userName);
		
		cout<<"Enter EMAIL: ";
		getline(cin,email);
		
		cout<<"Enter City: ";
		getline(cin,city);
		
		cout<<"\nCustomer Type\n";
		cout<<"1. New customer\n";
		cout<<"2. Returning Customer\n";
		cout<<"Enter choice: ";
		
		int choice;
		cin>>choice;
		
		if(choice==1){
			customerType = "New";
		}
		else{
			customerType = "Returning";
		}
	}
	
	//menu
	int displayMenu()
	{
		int choice;
		
		cout<<"\n--------- MAIN MENU ----------\n";
	    cout<<"1. View Products\n";
	    cout<<"2. Add Product To Cart\n";
	    cout<<"3. Calculate Checkout Bill\n";
	    cout<<"4. View User Details\n";
	    cout<<"5. Exit\n";
	    cout<<"Enter Choice: ";
	
	    cin>>choice;
	
	    return choice;
	}
	
	//display products
	void displayProducts()
	{
		cout << "\n----------- PRODUCT LIST -----------\n";
		
		for(int i=0;i<8;i++)
		{
			cout<<i+1<<". "<<productNames[i]<<" - Rs. "<<productPrices[i]<<endl;
		}
		
	}
	
	//add to cart
	void addProductToCart()
	{
		int productNo;
		int quantity;
		
		displayProducts();
		
		cout<<"\nEnter Product NO: ";
		cin>>productNo;
		
		cout<<"\nEnter Quantity: ";
		cin>>quantity;
		
		if(productNo>=1 && productNo<=8){
			cartTotal += productPrices[productNo-1]*quantity;
		}
		else{
			cout<<"Invalid Product No!\n";
		}
	}
	
	//product total
	double calculateProductTotal()
	{
		return cartTotal;
	}
	
	//GST
	double calculateGST(double total)
	{
		return total*0.17;
	}
	
	//delivery charges
	double calculateDeliveryCharges()
	{
		if(city == "Lahore"||city == "Karachi"||city == "Islamabad"){
			return 250;
		}
		return 500;	
	}
	
	//customer discount
	double calculateCustomerDiscount(double total)
	{
		if(customerType== "New"){
			return total*0.05;
		}
		return total*0.10;
	}
	
	//order value discount
	double calculateOrderDiscount(double total)
	{
		if (total>=5000 &&total<=10000){
			return total*0.05;
		}
		else if(total>10000){
			return total*0.10;
		}
		return 0;
	}
	
	//Payment charges
	double calculatePaymentCharges(double amount)
	{
		int paymentMethod;
		
		cout<<"\nPayment Method\n";
		cout<<"1. Cash on Delivery\n";
		cout<<"2. Credit/Debit Card\n";
		cout<<"Enter choice: ";
		
		cin>>paymentMethod;
		
		if(paymentMethod==2){
			return amount*0.025;
		}
		return 0;
	}
	
	//Display Bill
	void displayCheckoutBill()
	{
		double productTotal = calculateProductTotal();
		double gst = calculateGST(productTotal);
		double deliveryCharges = calculateDeliveryCharges();
		double customerDiscount = calculateCustomerDiscount(productTotal);
		double orderDiscount = calculateOrderDiscount(productTotal);
		
		double subTotal = productTotal+gst+deliveryCharges-customerDiscount-orderDiscount;
		
		double paymentCharges = calculatePaymentCharges(subTotal);
		double finalAmount = paymentCharges + subTotal;
		
		cout<<"\n\n----------ONLINE SHOPPING BILL----------\n";
		cout<<"User Name: "<<userName<<endl;
		cout<<"City: "<<city<<endl;
		cout<<"Customer Type"<<customerType<<endl;
		cout<<"\nProduct Total:	"<<productTotal<<endl;
		cout<<"GST:RS. "<<gst<<endl;
		cout<< "Delivery Charges: Rs. "<<deliveryCharges<<endl;
	    cout<< "Customer Discount: Rs. "<<customerDiscount<<endl;
	    cout<< "Order Discount: Rs. "<<orderDiscount<<endl;
	    cout<<"Payment Charges: Rs. "<<paymentCharges<<endl;
	    
	    cout<<"\n-----------------------------------------\n";
	    
	    cout<<"Final Payable amount:RS. "<<finalAmount<<endl;
	    cout<<"Thank You For Shopping\n";
	    cout<<"--------------------------------------------\n";
	}
	
	//user details
	void displayUserDetails()
	{
		cout<<"/n===========USER DETAILS===========\n";
		cout<<"User Name: "<<userName<<endl;
		cout<<"Email: "<<email<<endl;
		cout<<"City: "<<city<<endl;
		cout<<"Customer Type"<<customerType<<endl;
	}
	
	
	
	
	

