Program#1: Grocery Mart shopping And Billing System
#include <iostream>
using namespace std;

int main()
{
    string customerName, customerType, paymentMethod;

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Customer Type (Regular/Member): ";
    getline(cin, customerType);

    cout << "Enter Payment Method (Cash/Card): ";
    getline(cin, paymentMethod);

    string items[8] = {
        "Rice","Sugar","Cooking Oil","Milk",
        "Tea","Flour","Eggs","Detergent"
    };

    int prices[8] = {350,180,580,220,450,950,320,600};

    double bill = 0;

    char more;
    int choice, quantity;

    do
    {
        for(int i=0; i<8; i++)
        {
            cout << i+1 << ". "
                 << items[i]
                 << " - Rs. "
                 << prices[i] << endl;
        }

        cout << "Enter Item Number: ";
        cin >> choice;

        cout << "Enter Quantity: ";
        cin >> quantity;

        bill += prices[choice-1] * quantity;

        cout << "Add More? (y/n): ";
        cin >> more;

    } while(more == 'y');

    double tax;

    if(choice == 8)
        tax = bill * 0.10;
    else
        tax = bill * 0.05;

    double membershipDiscount = 0;

    if(customerType == "Member")
        membershipDiscount = bill * 0.07;

    double billDiscount = 0;

    if(bill >= 5000 && bill <= 10000)
        billDiscount = bill * 0.05;
    else if(bill > 10000)
        billDiscount = bill * 0.10;

    double cardCharges = 0;

    if(paymentMethod == "Card")
        cardCharges = bill * 0.02;

    double total = bill + tax + cardCharges
                   - membershipDiscount - billDiscount;

    cout << "\n========== GROCERY BILL ==========\n";

    cout << "Customer Name: " << customerName << endl;
    cout << "Gross Bill: Rs. " << bill << endl;
    cout << "Tax: Rs. " << tax << endl;
    cout << "Membership Discount: Rs. "
         << membershipDiscount << endl;

    cout << "Bill Discount: Rs. "
         << billDiscount << endl;

    cout << "Card Charges: Rs. "
         << cardCharges << endl;

    cout << "Total Payable Amount: Rs. "
         << total << endl;

    return 0;
}


Program#2: Electricity Bill Management System
#include <iostream>
#include <string>
using namespace std;

string customerName, customerId, customerType;
int installedMeters;

void registerCustomer()
{
    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Customer ID: ";
    getline(cin, customerId);

    cout << "Customer Type (Household/Commercial): ";
    getline(cin, customerType);

    cout << "Number of Installed Meters (1 or 2): ";
    cin >> installedMeters;
}

double calculateConsumptionCharges(int units)
{
    double rates[8] = {12.21,14.53,31.51,38.41,41.62,43.04,44.18,49.10};

    if(units <= 100) return units * rates[0];
    else if(units <= 200) return units * rates[1];
    else if(units <= 300) return units * rates[2];
    else if(units <= 400) return units * rates[3];
    else if(units <= 500) return units * rates[4];
    else if(units <= 600) return units * rates[5];
    else if(units <= 700) return units * rates[6];
    else return units * rates[7];
}

double calculateGST(double amount)
{
    return amount * 0.18;
}

double calculateIncomeTax(double amount)
{
    if(customerType == "Household")
        return amount * 0.10;
    else
        return amount * 0.15;
}

double calculateDuty(double consumption)
{
    return consumption * 0.015;
}

double calculateFixedCharges(int units)
{
    if(units <= 300) return 0;
    else if(units <= 400) return 200;
    else if(units <= 500) return 400;
    else if(units <= 600) return 600;
    else if(units <= 700) return 800;
    else return 1000;
}

void displayCustomerDetails()
{
    cout << "\nCustomer Name: " << customerName;
    cout << "\nCustomer ID: " << customerId;
    cout << "\nCustomer Type: " << customerType;
    cout << "\nInstalled Meters: " << installedMeters << endl;
}

void calculateBill()
{
    int units;

    cout << "Enter Units Consumed: ";
    cin >> units;

    double consumption = calculateConsumptionCharges(units);
    double duty = calculateDuty(consumption);
    double fixedCharges = calculateFixedCharges(units);

    double subtotal = consumption + duty + fixedCharges + 250 + 35;

    double gst = calculateGST(subtotal);
    double incomeTax = calculateIncomeTax(subtotal);

    double totalBill = subtotal + gst + incomeTax;

    cout << "\n========== LESCO BILL ==========\n";
    cout << "Customer Name: " << customerName << endl;
    cout << "Consumption Charges: " << consumption << endl;
    cout << "Electricity Duty: " << duty << endl;
    cout << "Fixed Charges: " << fixedCharges << endl;
    cout << "Meter Rent: 250\n";
    cout << "TV Fee: 35\n";
    cout << "GST: " << gst << endl;
    cout << "Income Tax: " << incomeTax << endl;
    cout << "Total Bill: " << totalBill << endl;
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        cout << "\n1. Calculate Bill";
        cout << "\n2. View Customer Details";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                calculateBill();
                break;

            case 2:
                displayCustomerDetails();
                break;

            case 3:
                cout << "Program Ended";
                break;

            default:
                cout << "Invalid Choice";
        }

    } while(choice != 3);

    return 0;
}
Program#3: Online Shopping System
#include <iostream>
#include <string>
using namespace std;

string userName, email, city, customerType;

string products[8] =
{
    "T-Shirt","Jeans","Shoes","Watch",
    "Handbag","Headphones","Mobile Cover","Perfume"
};

double prices[8] =
{
    1200,3500,5000,2500,
    4200,3000,700,2800
};

double cartTotal = 0;

void registerUser()
{
    cout << "Enter User Name: ";
    getline(cin, userName);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "Customer Type (New/Returning): ";
    getline(cin, customerType);
}

void displayProducts()
{
    cout << "\n------ Product List ------\n";

    for(int i=0;i<8;i++)
    {
        cout << i+1 << ". "
             << products[i]
             << " - Rs." << prices[i] << endl;
    }
}

void addToCart()
{
    int productNo, quantity;

    cout << "Enter Product Number: ";
    cin >> productNo;

    cout << "Enter Quantity: ";
    cin >> quantity;

    cartTotal += prices[productNo-1] * quantity;
}

double calculateGST()
{
    return cartTotal * 0.17;
}

double deliveryCharges()
{
    if(city == "Lahore" || city == "Karachi" || city == "Islamabad")
        return 250;
    else
        return 500;
}

double customerDiscount()
{
    if(customerType == "Returning")
        return cartTotal * 0.10;
    else
        return cartTotal * 0.05;
}

double orderDiscount()
{
    if(cartTotal > 10000)
        return cartTotal * 0.12;
    else if(cartTotal >= 5000)
        return cartTotal * 0.05;
    else
        return 0;
}

double paymentCharges(int method)
{
    if(method == 2)
        return cartTotal * 0.025;
    else
        return 0;
}

void checkout()
{
    int method;

    cout << "\n1. Cash On Delivery";
    cout << "\n2. Card Payment";
    cout << "\nChoose Method: ";
    cin >> method;

    double gst = calculateGST();
    double delivery = deliveryCharges();
    double custDiscount = customerDiscount();
    double orderDisc = orderDiscount();
    double payCharges = paymentCharges(method);

    double finalBill =
        cartTotal + gst + delivery + payCharges
        - custDiscount - orderDisc;

    cout << "\n========== ONLINE SHOPPING BILL ==========\n";
    cout << "User Name: " << userName << endl;
    cout << "City: " << city << endl;
    cout << "Customer Type: " << customerType << endl;
    cout << "Product Total: " << cartTotal << endl;
    cout << "GST: " << gst << endl;
    cout << "Delivery Charges: " << delivery << endl;
    cout << "Customer Discount: " << custDiscount << endl;
    cout << "Order Discount: " << orderDisc << endl;
    cout << "Payment Charges: " << payCharges << endl;
    cout << "Final Payable Amount: " << finalBill << endl;
}

void viewUserDetails()
{
    cout << "\nUser Name: " << userName;
    cout << "\nEmail: " << email;
    cout << "\nCity: " << city;
    cout << "\nCustomer Type: " << customerType << endl;
}

int main()
{
    registerUser();

    int choice;

    do
    {
        cout << "\n1. View Products";
        cout << "\n2. Add Product To Cart";
        cout << "\n3. Checkout";
        cout << "\n4. View User Details";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayProducts();
                break;

            case 2:
                addToCart();
                break;

            case 3:
                checkout();
                break;

            case 4:
                viewUserDetails();
                break;

            case 5:
                cout << "Program Ended";
                break;

            default:
                cout << "Invalid Choice";
        }

    } while(choice != 5);

    return 0;
}
Program#4: Restaurant Order and Billing System
#include <iostream>
using namespace std;

string customerName, orderType;
int persons;

string food[8] = {
    "Chicken Burger",
    "Zinger Burger",
    "Pizza Small",
    "Pizza Large",
    "Chicken Biryani",
    "BBQ Platter",
    "Fries",
    "Cold Drink"
};

int price[8] = {450,550,900,1800,350,1200,250,120};
int qty[8] = {0};

void registerCustomer()
{
    cout<<"Enter Customer Name: ";
    cin>>customerName;

    cout<<"Enter Order Type (Dine-in/Takeaway): ";
    cin>>orderType;

    cout<<"Enter Number of Persons: ";
    cin>>persons;
}

void displayMenu()
{
    cout<<"\n------ FOOD MENU ------\n";

    for(int i=0; i<8; i++)
    {
        cout<<i+1<<". "<<food[i]
            <<" - Rs."<<price[i]<<endl;
    }
}

void placeOrder()
{
    int item, quantity;

    cout<<"Enter Item Number (1-8): ";
    cin>>item;

    cout<<"Enter Quantity: ";
    cin>>quantity;

    if(item>=1 && item<=8)
    {
        qty[item-1] += quantity;
        cout<<"Item Added Successfully!\n";
    }
    else
    {
        cout<<"Invalid Item Number!\n";
    }
}

double calculateBill()
{
    double bill = 0;

    for(int i=0; i<8; i++)
    {
        bill += qty[i] * price[i];
    }

    return bill;
}

void displayFinalBill()
{
    double bill = calculateBill();

    double serviceCharges;

    if(orderType=="Dine-in")
        serviceCharges = bill * 0.10;
    else
        serviceCharges = bill * 0.05;

    double gst = bill * 0.16;

    double discount = 0;

    if(bill >= 3000 && bill <= 5000)
        discount = bill * 0.05;
    else if(bill > 5000 && bill <= 10000)
        discount = bill * 0.10;
    else if(bill > 10000)
        discount = bill * 0.15;

    double total = bill + serviceCharges + gst - discount;

    cout<<"\n========== RESTAURANT BILL ==========\n";
    cout<<"Customer Name: "<<customerName<<endl;
    cout<<"Order Type: "<<orderType<<endl;
    cout<<"Number of Persons: "<<persons<<endl;
    cout<<"Food Bill: Rs. "<<bill<<endl;
    cout<<"Service Charges: Rs. "<<serviceCharges<<endl;
    cout<<"GST: Rs. "<<gst<<endl;
    cout<<"Discount: Rs. "<<discount<<endl;

    if(total > 5000)
        cout<<"Free Delivery Added\n";

    cout<<"------------------------------------\n";
    cout<<"Total Payable Amount: Rs. "<<total<<endl;
    cout<<"====================================\n";
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        cout<<"\n1. View Food Menu";
        cout<<"\n2. Place Order";
        cout<<"\n3. Calculate Bill";
        cout<<"\n4. Exit";
        cout<<"\nEnter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                displayMenu();
                break;

            case 2:
                placeOrder();
                break;

            case 3:
                displayFinalBill();
                break;

            case 4:
                cout<<"Program Ended.\n";
                break;

            default:
                cout<<"Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
