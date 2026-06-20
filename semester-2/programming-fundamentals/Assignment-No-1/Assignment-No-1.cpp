//Question 1

#include<iostream>
using namespace std;

int main()
{
    int x, y;

    cout << "Enter value of y: ";
    cin >> y;

    if(y == 10)
        x = 0;
    else
        x = 1;

    cout << "x is " << x << endl;

    return 0;
}



//Question 2

#include<iostream>
using namespace std;

int main()
{
    int temperature;

    cout << "Enter temperature: ";
    cin >> temperature;

    if(temperature >= -50 && temperature <= 150)
        cout << "The number is valid" << endl;

    return 0;
}



//Question 3

#include<iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    if(a < b)
        cout << a << " is smaller, " << b << " is larger" << endl;
    else if(b < a)
        cout << b << " is smaller, " << a << " is larger" << endl;
    else
        cout << "Both numbers are equal" << endl;

    return 0;
}



//Question 4

#include<iostream>
using namespace std;

int main()
{
    double a = 10, b = 10;

    a = a + 0.2;

    if(a > b)
        cout << "a is larger, b is smaller" << endl;
    else
        cout << "b is larger, a is smaller" << endl;

    return 0;
}



//Question 5

#include<iostream>
using namespace std;

int main()
{
    double num, den;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    if(den != 0)
        cout << "Result: " << num / den << endl;
    else
        cout << "Division by zero is not possible." << endl;

    return 0;
}


//Question 6 


A) a == 4 || b > 2        -> True  (b>2 is true)
B) 6 <= c && a > 3        -> False (a>3 is false)
C) 1 != b && c != 3       -> True  (both true)
D) a >= -1 || a <= b      -> True  (both true)
E) !(a > 2)               -> True  (a>2 is false, so ! makes it true)



//Question 7


#include<iostream>
using namespace std;

int main()
{
    double r1, r2, r3;

    cout << "Enter time for runner 1: ";
    cin >> r1;
    cout << "Enter time for runner 2: ";
    cin >> r2;
    cout << "Enter time for runner 3: ";
    cin >> r3;

    if(r1 < r2 && r1 < r3)
    {
        cout << "1st place: Runner 1" << endl;
        if(r2 < r3)
        {
            cout << "2nd place: Runner 2" << endl;
            cout << "3rd place: Runner 3" << endl;
        }
        else
        {
            cout << "2nd place: Runner 3" << endl;
            cout << "3rd place: Runner 2" << endl;
        }
    }
    else if(r2 < r1 && r2 < r3)
    {
        cout << "1st place: Runner 2" << endl;
        if(r1 < r3)
        {
            cout << "2nd place: Runner 1" << endl;
            cout << "3rd place: Runner 3" << endl;
        }
        else
        {
            cout << "2nd place: Runner 3" << endl;
            cout << "3rd place: Runner 1" << endl;
        }
    }
    else
    {
        cout << "1st place: Runner 3" << endl;
        if(r1 < r2)
        {
            cout << "2nd place: Runner 1" << endl;
            cout << "3rd place: Runner 2" << endl;
        }
        else
        {
            cout << "2nd place: Runner 2" << endl;
            cout << "3rd place: Runner 1" << endl;
        }
    }

    return 0;
}


//Question 8

#include<iostream>
using namespace std;

int main()
{
    int choice;
    double r, l, w, base, height;

    cout << "Geometry Calculator" << endl;
    cout << "1. Calculate the Area of a Circle" << endl;
    cout << "2. Calculate the Area of a Rectangle" << endl;
    cout << "3. Calculate the Area of a Triangle" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if(choice == 1)
    {
        cout << "Enter radius: ";
        cin >> r;
        cout << "Area: " << 3.14159 * r * r << endl;
    }
    else if(choice == 2)
    {
        cout << "Enter length: ";
        cin >> l;
        cout << "Enter width: ";
        cin >> w;
        cout << "Area: " << l * w << endl;
    }
    else if(choice == 3)
    {
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter height: ";
        cin >> height;
        cout << "Area: " << base * height * 0.5 << endl;
    }

    return 0;
}



//Question 9

#include<iostream>
using namespace std;

int main()
{
    char ch;

    for(ch = 'A'; ch <= 'Z'; ch++)
        cout << ch << " = " << (int)ch << endl;

    return 0;
}



//Question 10


#include<iostream>
using namespace std;

int main()
{
    double mass, weight;

    cout << "Enter mass: ";
    cin >> mass;

    weight = mass * 9.8;
    cout << "Weight: " << weight << " newtons" << endl;

    if(weight > 1000)
        cout << "Too heavy" << endl;
    else if(weight < 10)
        cout << "Too light" << endl;

    return 0;
}



//Question 11


#include<iostream>
using namespace std;

int main()
{
    double sales;

    cout << "Enter sales: ";
    cin >> sales;

    if(sales > 50000)
        sales = sales + (sales * 0.25) + 250;

    cout << "Sales: " << sales << endl;

    return 0;
}



//Question 12


#include<iostream>
using namespace std;

int main()
{
    double income;
    int years;

    cout << "Enter annual income: ";
    cin >> income;
    cout << "Enter years at current job: ";
    cin >> years;

    if(income >= 35000 && years > 5)
        cout << "You qualify for the loan" << endl;
    else
        cout << "You do not qualify for the loan" << endl;

    return 0;
}



//Question 13


#include<iostream>
using namespace std;

int main()
{
    int model;

    cout << "Enter TV model (100, 200, 300): ";
    cin >> model;

    if(model == 300)
        cout << "Features: Picture-in-picture, Stereo sound, Remote control" << endl;
    else if(model == 200)
        cout << "Features: Stereo sound, Remote control" << endl;
    else if(model == 100)
        cout << "Features: Remote control" << endl;
    else
        cout << "Invalid model" << endl;

    return 0;
}



//Question 14

#include<iostream>
using namespace std;

int main()
{
    int month, day, year;

    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter two digit year: ";
    cin >> year;

    if(month * day == year)
        cout << "MAGIC" << endl;
    else
        cout << "NOT MAGIC" << endl;

    return 0;
}



//Question 15

#include<iostream>
using namespace std;

int main()
{
    double sales, commission;

    cout << "Enter sales: ";
    cin >> sales;

    if(sales <= 10000)
        commission = 0.10;
    else if(sales <= 15000)
        commission = 0.15;
    else
        commission = 0.20;

    cout << "Commission rate: " << commission << endl;

    return 0;
}



//Question 16

#include<iostream>
using namespace std;

int main()
{
    double balance, fees, checkFee;
    int checks;

    cout << "Enter beginning balance: ";
    cin >> balance;
    cout << "Enter number of checks written: ";
    cin >> checks;

    if(checks < 20)
        checkFee = checks * 0.10;
    else if(checks <= 39)
        checkFee = checks * 0.08;
    else if(checks <= 59)
        checkFee = checks * 0.06;
    else
        checkFee = checks * 0.04;

    fees = 10 + checkFee;

    if(balance < 400)
        fees = fees + 15;

    cout << "Total service fees: $" << fees << endl;

    return 0;
}


//Question 17

#include<iostream>
using namespace std;

int main()
{
    int choice;

    cout << "1. Noise Canceling - $249.00" << endl;
    cout << "2. Wireless - $199.00" << endl;
    cout << "3. Wired Budget - $49.00" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 1)
        cout << "Price: $249.00" << endl;
    else if(choice == 2)
        cout << "Price: $199.00" << endl;
    else if(choice == 3)
        cout << "Price: $49.00" << endl;
    else
        cout << "Invalid choice" << endl;

    return 0;
}



//Question 18

#include<iostream>
using namespace std;

int main()
{
    int choice, months;
    double total;

    cout << "1. Standard Adult Membership" << endl;
    cout << "2. Child Membership" << endl;
    cout << "3. Senior Citizen Membership" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 4)
    {
        cout << "Goodbye" << endl;
        return 0;
    }

    cout << "Enter number of months: ";
    cin >> months;

    if(choice == 1)
        total = 40 * months;
    else if(choice == 2)
        total = 20 * months;
    else if(choice == 3)
        total = 30 * months;
    else
    {
        cout << "Invalid choice" << endl;
        return 0;
    }

    cout << "Total amount: Rs." << total << endl;

    return 0;
}



//Question 19

#include<iostream>
using namespace std;

int main()
{
    int package, gb;
    double total;

    cout << "Enter the package purchased (1, 2, or 3): ";
    cin >> package;
    cout << "Enter the number of gigabytes used: ";
    cin >> gb;

    if(package == 1)
    {
        total = 39.99;
        if(gb > 4)
            total = total + (gb - 4) * 10;
    }
    else if(package == 2)
    {
        total = 59.99;
        if(gb > 8)
            total = total + (gb - 8) * 5;
    }
    else
        total = 69.99;

    cout << "The total amount due is: $" << total << endl;

    return 0;
}




//Question 20


#include<iostream>
using namespace std;

int main()
{
    long seconds;

    cout << "Enter number of seconds: ";
    cin >> seconds;

    if(seconds >= 86400)
        cout << "Days: " << seconds / 86400 << endl;
    else if(seconds >= 3600)
        cout << "Hours: " << seconds / 3600 << endl;
    else if(seconds >= 60)
        cout << "Minutes: " << seconds / 60 << endl;
    else
        cout << seconds << " seconds" << endl;

    return 0;
}
