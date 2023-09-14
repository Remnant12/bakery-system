#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//Structures

struct User{
    //for sign-in purpose
    string username;
    string password1;
    string password2;
    //for log-in purpose
    string login_username;
    string login_password;

    string role;
    string id;
};

struct Products{
    string name;
    string id;
    int quality;
    float price;
    string category;
    float size;
    string availability;
    string health;
    string description;

        void print_detail(){
            cout << id << setw(15) << name << setw(15) << quality << setw(15) << price << endl;
        }
};

struct Bill{
    string name;
    string id;
    int quality;
    float unitprice;
    string category;
    string bill_id;
    int total;
    string staff;

        int totalprice(){
            return unitprice * quality;
        }

        void print_detail2(){
            cout << id << setw(15) << name << setw(15) << quality << setw(15) << unitprice << endl;
        }
};

struct Package{
    string id;
    string name;
    string description;
    float price;
    string category;
    float size;
    string availability;
    string health;
};

struct Customers{
    string fullname;
    string phonenumber;
    string address;
    int age;
    string gender;
    string payment_method;
    string package;
    string id;
};

//functions
void sign_in();
void login_form();
int main();

//function for common user interface
void common_interface();

// function for admin interface
void admin_interface1();
void admin_interface2();
void admin_interface3();
void admin_interface4();
void if_admin();
//core features for products ( under admin's authority )
void view_products();
void search_products();
void remove_products();
void add_products();
void update_products();
// function for staff interface
void staff_interface1();
void staff_interface2();
void staff_interface3();

void if_staff();
// core functions for packages ( under admin's authority )
void add_packages();
void remove_packages();
void view_packages();
void search_packages();
void update_packages();
void add_packages();

void view_customers();
void remove_customers();
void search_customers();
void update_customers();


//global variable
string current_role;


void sign_in(ofstream& writeuser){

    User newuser;
    bool confirm = false;
    bool id = false;
    bool role = false; // for the condition of role
    bool user1 = false, user2 = false, user3 = false, user4 = false; // for the conditions of the username
    bool pass1 = false, pass2 = false, pass3 = false, pass4 = false; // for the conditions of the password

    cout << "Welcome to Registration Form" << endl;
    cout << "============================" << endl << endl;
                        do {
                            cout << "Enter the ID: ";
                            cin >> newuser.id;
                                bool hasdigit2 = false, hasupper2 = false;
                                int t = (newuser.id).length();

                                for (int i = 0; i < t; i++ ) {
                                    if (isdigit(newuser.id[i])) hasdigit2 = true;
                                    if (isupper(newuser.id[i])) hasupper2 = true;
                                }

                                    if (t > 4 && t < 6 && hasdigit2 && hasupper2){
                                        cout << "ID Registered Successfully" << endl << endl;
                                        id = true;
                                    } else {
                                        cout << "Input had failed to meet requirements" << endl;
                                    }
                        } while (!(id));

                        do {
                            cout << "Enter the Role: ";
                            cin >> newuser.role;

                                if (newuser.role == "admin" || newuser.role == "staff") {
                                    cout << "Role Registered Successfully" << endl << endl;
                                    role = true;
                                    break;
                                } else {
                                    cout << "Incorrect Input" << endl;
                                    cout << "Input either <<Staff>> or <<Admin>>" << endl;
                                }

                        } while (!(role));

                        do {

                            cout << "Enter a Username: ";
                            cin >> newuser.username;

                                bool hasupper = false, haslower = false, hasdigit = false, hasspecial = false;
                                int m = (newuser.username).length(); // created a variable "m" to replace the length of the username
                                string j = newuser.username; // created a variable "j" for the purpose of spotting special characters

                                for (int i = 0; i < m; i++) {
                                    if (islower(newuser.username[i])) haslower = true;
                                    if (isupper(newuser.username[i])) hasupper = true;
                                    if (isdigit(newuser.username[i])) hasdigit = true;
                                    if (!(j[i] >= 97 && j[i] <= 122 || j[i] >= 65 && j[i] <= 90 || j[i]  >= 47 && j[i] <= 57)) hasspecial = true;
                                }


                                if (m >= 7 && hasspecial || m >= 7 && hasspecial && hasdigit){
                                    cout << "Alert Message: Username cannot contain special characters" << endl << endl;
                                    user4 = true;

                                } else if (m >= 7 &&( hasupper || haslower ) && hasdigit){
                                    cout << "Username Strength: <<Strong>>" << endl << endl;
                                    break;

                                } else if (m <= 7){
                                    cout << "Alert Message: Username must contain more than 7 Characters" << endl << endl;
                                    user1 = true;

                                } else if (m >= 7 && hasupper || m >= 7 && hasupper && hasdigit) {
                                    cout << "Alert Message: Username can't have consecutive uppercase letters"<< endl << endl;
                                    user3 = true;


                                } else {
                                    cout << "Alert Message: Username cannot contain only numbers consecutively" << endl << endl;
                                    user4 = true;
                                }

                            } while (user1 == true || user3 == true || user4 == true);

                        do {
                                cout << "========================================================================" << endl;
                                cout << "Password must contain Lower/Uppercase, digits and more than 6 characters" << endl;
                                cout << "========================================================================"  << endl << endl;

                                do {

                                    cout << "Enter a Password: ";
                                    cin >> newuser.password1;

                                        bool haslower1 = false, hasupper1 = false, hasdigit1 = false, hasspecial1 = false;

                                        int n = (newuser.password1).length();
                                        string k = newuser.password1;

                                        for (int i = 0; i < n; i++){

                                            if (islower(newuser.password1[i])) haslower1 = true;
                                            if (isupper(newuser.password1[i])) hasupper1 = true;
                                            if (isdigit(newuser.password1[i])) hasdigit1 = true;
                                            if (!(k[i] >= 97 && k[i] <= 122 || k[i] >= 65 && k[i] <= 90 || k[i]  >= 47 && k[i] <= 57)) hasspecial1 = true;

                                        }
                                            if (n >= 7 && hasspecial1 || n >= 7 && hasspecial1 && hasdigit1){
                                                cout << "Password Strength: <<Moderate>>" << endl;
                                                cout << "Alert Message: Password cannot contain special characters" << endl;
                                                pass4 = true;

                                            } else if (n <= 7){
                                                cout << "Password Strength: <<Weak>>" << endl;
                                                cout << "Alert Message: Password must contain more than 7 Characters" << endl << endl;
                                                pass1 = true;

                                            } else if(n >= 7 && hasupper1 && haslower1 && hasdigit1){
                                                cout << "Password Strength: <<Strong>>" << endl;
                                                break;

                                            } else if (n >= 7 && hasupper1 && haslower1 || n >= 7 && haslower1 && hasdigit1 || n >= 7 && haslower1){
                                                cout << "Password Strength: <<Moderate>>"<< endl;
                                                cout << "Alert Message: Password must have an uppercase and digit"<< endl << endl;
                                                pass2 = true;

                                            } else if (n >= 7 && hasupper1 || n >= 7 && hasupper1 && hasdigit1) {
                                                cout << "Password Strength: <<Moderate>>" << endl;
                                                cout << "Alert Message: Password can't have consecutive uppercase letters"<< endl << endl;
                                                pass3 = true;

                                            } else {
                                                cout << "Username Strength: <<Moderate>>" << endl;
                                                cout << "Alert Message: Username cannot contain only numbers consecutively" << endl << endl;
                                                pass4 = true;
                                            }

                                } while (pass1 == true || pass2 == true || pass3 == true || pass4 == true);

                                cout << "Re-Enter the Password: ";
                                cin >> newuser.password2;

                                    if (newuser.password1 == newuser.password2) {
                                        cout << "<< Registration Successful >>" << endl << endl << endl;
                                        confirm = true;


                                    } else {
                                        cout << "Status: Password does not match" << endl << endl;

                                    }

                            } while (!confirm);

    writeuser.open("Userdetail", ios::app);
    writeuser << newuser.username << " "<< newuser.password2 << " " << newuser.id << " " << newuser.role << endl;
    writeuser.close();
}

bool login_form(ifstream& readuser){

    bool login_result = false;

    User user;
    int i = 0;
    cout << "========================" << endl;
    cout << "Welcome to Login Section" << endl;
    cout << "========================" << endl;

        do {
            cout << "Enter the Username: ";
            cin >> user.login_username;
            cout << "Enter the Password: ";
            cin >> user.login_password;
            cout << endl;

            readuser.open("Userdetail", ios::in);
            User newuser;

            while (readuser >> newuser.username >> newuser.password2 >> newuser.id >> newuser.role){
                if (user.login_username == newuser.username && user.login_password == newuser.password2){

                    cout << "Status: Login Successful" << endl << endl;
                    cout << "You have Logged-In as: " << newuser.role << endl;
                    cout << "Your ID is: " << newuser.id << endl;
                    cout << "=======================" << endl << endl;
                    login_result = true;
                    current_role = newuser.role;
                    break;

                }
            }

            if (!(login_result)){
                cout << "-------------------------------" << endl;
                cout << "Status: Login Failed. Try Again" << endl;
                cout << "-------------------------------" << endl;
                cout << endl;
            }

            i++;
            readuser.close();

        } while (!(login_result) && (i < 3));

    return login_result;
}

// Common user interface functions
void common_interface(int &option) {

    do {
        cout << "1. Login" << setw(25) << "2. About Company" << endl << endl;
        cout << "Enter the option: ";
        cin >> option;
            if (!(option == 1 || option == 2)) {
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            } else {
                cout << "Selection: Login" << endl;
            }
    } while (!(option == 1 || option == 2));
    cout << endl << endl;
}

// staff user interface functions
void staff_interface1(int &option){

    cout << "1. Manage Products" << "       " << "2. Manage Customers" << "       " << "3. Logout" << endl << endl;
    cout << "Enter the option: ";
    cin >> option;
    cout << endl << endl;
}

void staff_interface2(int &option){

    cout << "1. View Products" << "       " << "2. Bill Products" << "       " << "3. View Packages" << "       " << "4. Bill Packages" << "       " << "5. Go Back" << endl << endl;

    cout << "Enter the option: ";
    cin >> option;
    cout << endl << endl;
}

void staff_interface3(int& option) { //sub interface for staff interface

    cout << "1. View Customers" << "       " << "2. Search Customers" << "       " << "3. Update Customers" << "       " << "4. Remove Customers" << "       " << "5. Go Back" << endl << endl;

    cout << "Enter the option: ";
    cin >> option;
    cout << endl << endl;

}

// admin user interface functions
void admin_interface1(int &option){

    do {
            cout << "1. Management" << "       " << "2. Logout"<< endl << endl;
            cout << "Enter 1 or 2: ";
            cin >> option;

            try { // try the below snippet of code
               // option = stoi(input); // convert the int to string to perform a non-integer validation
                if (!(cin)) {
                    break;
                } else {
                    cout << "Invalid input. Try again." << endl;
                }
            } catch (invalid_argument&) { // catch if any invalid input is spotted
                cout << "Invalid input. Try again." << std::endl;
            }

    } while (!(cin >> option));
    cout << endl << endl;

}

void admin_interface2(int &option){ // sub interface for admin_interface1

    cout << "1. Manage Staffs" << "       " << "2. Manage Products" << "       " << "3. Manage Product Packages" << "       " << "4. Go Back" << endl << endl;
    cout << "Enter the option: ";
    cin >> option;
    cout << endl << endl;
}

void admin_interface3(int& option){ //sub interface for admin_interface2

    cout << "1. Add Staff" << "       " << "2. Remove Staff" << "       " << "3. Update Staff" << "       " << "4. Search Staff" << "       " << "5. Update Products" << endl;
    cout << "6. Go Back" << "       " << "7. Main Menu"<< endl << endl;

    cout << "Enter the option: ";
    cin >> option;
    cout << endl << endl;

}
void admin_interface5(int &option){
    cout << "1. Add Packages" << "       " << "2. View Packages" << "       " << "3. Remove Packages" << "       " << "4. Search Packages" << "       " << "5. Update Packages" << endl;
    cout << "6. Go Back" << "       " << "7. Main Menu" << endl << endl;
    cout << "Enter the option: ";
    cin >> option;
    cout << endl << endl;

}
void admin_interface4(int& option){

    cout << "1. Add Products" << "       " << "2. View Products" << "       " << "3. Remove Products" << "       " << "4. Search Products" << "       " << "5. Update Products" << endl;
    cout << "6. Go Back" << "       " << "7. Main Menu" << endl << endl;
    cout << "Enter the option: ";
    cin >> option;
    cout << endl << endl;
}

bool loop_option(int &option){
    bool loop_it = false;
        do {
            cout << endl;
            cout << "1. Go Back" << endl;
            cout << "2. Quit" << endl;
            cout << "Enter your option: ";
            cin >> option;
            cout << endl << endl;

                if (option == 1) {
                    loop_it = true;
                } else if (option == 2) {
                    break;
                } else {
                    cout << "Incorrect Input" << endl;

                }
        } while (!(loop_it));

        return loop_it;

}

// PRODUCT ARDUS
//==============

//add product

void category_interface1(int &option){
    cout << "Category Menu" << endl;
    cout << "1. Cake" << "       " << "2. Bread" << "       " << "3. Pastries" << "       " <<  "4. Cookies" << "       " << "5. Beverages" << endl << endl;
    cout << "Select the Category to add: ";
    cin >> option;
}

void add_products(ofstream& write){

int option;
int option2;
int option3;
char option4;
int option8;
int option9;
Products p;
bool invalid_category = false;
bool incorrect_input = false; // flag for choosing availability
bool incorrect_input2 = false; // flag for choosing health aspects
bool incorrect_input3 = false; // do you like to add more product's flag
bool go_back = false;
int noofproducts = 0;

    do {
        category_interface1(option8);
                switch(option8){
                    case 1:
                        //cake
                        p.category = "cake";
                    break;

                    case 2:
                        //bread
                        p.category = "bread";
                    break;

                    case 3:
                        //Pastries
                        p.category = "Pastries";
                    break;

                    case 4:
                        //Cookies
                        p.category = "Cookies";
                    break;

                    case 5:
                        p.category = "Beverages";
                    break;

                    default:
                        cout << "Status: INVALID CATEGORY" << endl;
                        invalid_category = true;
                    break;
                }

    } while (invalid_category);


                while (!(invalid_category)) {
                        cout << "1. Go Back" << endl;
                        cout << "2. Enter ITEM details" << endl << endl;
                        cout << "Enter the input: ";
                        cin >> option;
                        cout << endl << endl;

                        if (option == 1) {
                            category_interface1(option8);

                        } else if (option == 2) {


                            cout << "Enter the Number of Products to Add: ";
                            cin >> noofproducts;

                            cout << "ITEM'S DETAILS" << endl;
                            cout << "--------------" << endl;

                            for (int i = 0; i < noofproducts; i++){
                                if (!(invalid_category)) {

                                    cout << "ID: ";
                                    cin >> p.id;

                                    cout << "Name: ";
                                    cin >> p.name;

                                    cout << "Price: ";
                                    cin >> p.price;

                                    do {

                                        cout << "Choose Product's Availability: " << endl;


                                        cout << "1. In_Stock" << endl;
                                        cout << "2. Unavailable" << endl;
                                        cout << "Choose: ";
                                        cin >> option2;
                                        cout << endl;
                                            if (option2 == 1) {
                                                p.availability = "In_Stock";
                                            } else if (option2 == 2) {
                                                p.availability = "Unavailable";
                                            } else {
                                                cout << "Incorrect Input. Try again" << endl << endl;
                                                incorrect_input = true;
                                                p.availability = "Unknown";
                                            }

                                    } while (incorrect_input);

                                    do {

                                        cout << "Choose Product's Health Aspect: " << endl;

                                        cout << "Sugar Level" << endl;
                                        cout << "1. High Sugar" << endl;
                                        cout << "2. Medium Sugar" << endl;
                                        cout << "3. Low Sugar" << endl;
                                        cout << "4. No Sugar Added" << endl;
                                        cout << "Choose: ";
                                        cin >> option3;
                                        cout << endl;
                                            if (option3 == 1) {
                                                p.health = "High_Sugar";
                                            } else if (option3 == 2) {
                                                p.health = "Medium_Sugar";
                                            } else if (option3 == 3) {
                                                p.health == "Low_Sugar";
                                            } else if (option3 == 4) {
                                                p.health = "No_Sugar_Added";
                                            } else {
                                                cout << "Invalid Input" << endl << endl;
                                                incorrect_input2 = true;
                                                p.health = "Not Specified";
                                            }
                                    } while (incorrect_input2);

                                write.open("products", ios::app);
                                write << p.category << " " << p.id << " " << p.name << " " << p.price << " " << p.availability << " " << p.health << endl;
                                write.close();

                                }

                            }

                        } else {
                            cout << "Status: Invalid Input" << endl;
                        }
                        break;
                }
}

void view_products(ifstream &read){

    Products p;
    read.open("products", ios::in);
         if (!read.is_open()) {
            cout << "Error opening the file." << endl;
            return;
         }


    cout << left << setw(17) << "CATEGORY" << setw(10) << "ID" << setw(20) << "NAME" << setw(20) <<  setw(10) << "PRICE" << setw(15) << "AVAILABILITY" << setw(10) << "HEALTH" << endl;
    cout << left << setw(17) << "--------" << setw(10) << "--" << setw(20) << "----" << setw(20) <<  setw(10) << "-----" << setw(15) << "------------" << setw(10) << "------" << endl << endl;

    while (read >> p.category >> p.id >> p.name >> p.price >> p.availability >> p.health) {

        cout << setw(17) << p.category << setw(10) << p.id << setw(20) << p.name << setw(20) << fixed << setprecision(2) << setw(10) << p.price << setw(15) << p.availability << setw(10) << p.health << endl;
        cout << endl;

    }

    read.close();
}

void search_products(ifstream &read){
    string input;
    char input1;
    bool invalid_input = false;
    bool found = false;
            do {
                repeat_loop:

                cout << "Enter the ID / NAME / CATEGORY of the Products: ";
                cin >> input;
                Products p;

                read.open("products", ios::in);
                cout << left << setw(17) << "CATEGORY" << setw(10) << "ID" << setw(20) << "NAME" << setw(20) << setw(10) << "PRICE" << setw(15) << "AVAILABILITY" << setw(10) << "HEALTH" << endl;
                cout << left << setw(17) << "--------" << setw(10) << "--" << setw(20) << "----" << setw(20) << setw(10) << "-----" << setw(15) << "------------" << setw(10) << "------" << endl << endl;


                while (read >> p.category >> p.id >> p.name >> p.price >> p.availability >> p.health) {
                        if ( p.id == input || p.name == input || p.category == input){
                            cout << setw(17) << p.category << setw(10) << p.id << setw(20) << p.name << setw(20) << fixed << setprecision(2) << setw(10) << p.price << setw(15) << p.availability << setw(10) << p.health << endl;
                            cout << endl;
                            found = true;
                        }
                }

                read.close();

                if (!(found)){
                    cout << "Invalid Input" << endl;
                }

                cout << "Do you want to search again (Y/N)?: ";
                cin >> input1;
                    if (input1 == 'Y' || input1 == 'y') {
                        goto repeat_loop;
                    } else if (input1 == 'N' || input1 == 'n') {
                        break;
                    } else {
                        cout << "Invalid Input" << endl << endl;
                        invalid_input = true;
                    }

            } while (!(found) || invalid_input);
}


void update_products(ifstream &read){
    string id;
    int option;
    int option2;
    ifstream readproducts;
    ifstream readtemporaryproducts;
    ofstream writetemporaryproducts;

        cout << "Selection Preview" << endl;
        cout << "--------- -------" << endl;
        cout << "1. View Products" << endl;
        cout << "2. Search Products" << endl;
        cout << "Enter the result: ";
        cin >> option;

        switch(option) {
            case 1:
                view_products(readproducts);
            break;

            case 2:
                search_products(readproducts);
            break;
        }
        cout << endl;
        cout << "Update Session" << endl;
        cout << "--------------" << endl << endl;

        cout << "Enter the ID for Update: ";
        cin >> id;

        read.open("products", ios::in);

        writetemporaryproducts.open("temp", ios::app);

        Products p;
        bool updated = false;

        while (read >> p.category >> p.id >> p.name >> p.price){
            if (id == p.id) {
                cout << "Enter the New Category: ";
                cin >> p.category;
                cout << "Enter the New ID: ";
                cin >> p.id;
                cout << "Enter the New Name: ";
                cin >> p.name;
                cout << "Enter the New Price: ";
                cin >> p.price;
                cout << "Enter the Availability: ";
                cin >> p.availability;
                cout << "Enter the health aspect: ";
                cin >> p.health;
                cout << endl;

                updated = true;
            }
            writetemporaryproducts << p.category << " " << p.id << " " << p.name << " " << p.price << " " << p.availability << " " << p.health << endl;

        }

        if (!(updated)) {
            writetemporaryproducts << p.category << " " << p.id << " " << p.name << " " << p.price << " " << p.availability << " " << p.health << endl;

        }
        read.close();
        writetemporaryproducts.close();

            remove ("products");
            rename ("temp", "products");
            cout << "Information Updated Successfully" << endl;


        cout << "1. View the updated file: ";
        cin >> option2;

            if (option2 == 1) {
                readtemporaryproducts.open("products", ios::in);

                cout << left << setw(17) << "CATEGORY" << setw(10) << "ID" << setw(20) << "NAME" << setw(20) << setw(10) << "PRICE" << setw(15) << "AVAILABILITY" << setw(10) << "HEALTH" << endl;
                cout << left << setw(17) << "--------" << setw(10) << "--" << setw(20) << "----" << setw(20) << setw(10) << "-----" << setw(15) << "------------" << setw(10) << "------" << endl << endl;

                while (readtemporaryproducts >> p.category >> p.id >> p.name >> p.price) {
                    cout << setw(17) << p.category << setw(10) << p.id << setw(20) << p.name << setw(20) << fixed << setprecision(2) << setw(10) << p.price << setw(15) << p.availability << setw(10) << p.health << endl;
                    cout << endl;
                }
                readtemporaryproducts.close();

            } else {
                cout << "Incorrect Input" << endl;
            }

}

void remove_product(ifstream &read){

    string id;
    int option;
    int option2;
    ifstream readproducts;
    ifstream readtemporaryproducts;
    ofstream writetemporaryproducts;

        cout << "Selection Preview" << endl;
        cout << "--------- -------" << endl;
        cout << "1. View Products" << endl;
        cout << "2. Search Products" << endl;
        cout << "Enter the result: ";
        cin >> option;
        switch(option) {
            case 1:
                view_products(readproducts);
            break;

            case 2:
                search_products(readproducts);
            break;
        }
        cout << endl;
        cout << "Update Session" << endl;
        cout << "--------------" << endl << endl;

        cout << "Enter the ID for Remove: ";
        cin >> id;
        cout << endl;

        read.open("products", ios::in);

        writetemporaryproducts.open("temp", ios::app);

        Products p;
        bool deleted = false;

        while (read >> p.category >> p.id >> p.name >> p.price){
            if (id == p.id) {
                deleted = true;
                continue;
            }
            writetemporaryproducts << p.category << " " << p.id << " " << p.name << " " << p.price << " " << p.availability << " " << p.health << endl;

        }

        if(!(deleted)){
            writetemporaryproducts << p.category << " " << p.id << " " << p.name << " " << p.price << " " << p.availability << " " << p.health << endl;

        }

        read.close();
        writetemporaryproducts.close();

            remove ("products");
            rename ("temp", "products");
            cout << "Product Deleted Successfully" << endl;

        cout << "1. View the updated file: ";
        cin >> option2;

            if (option2 == 1) {
                readtemporaryproducts.open("products", ios::in);

                cout << left << setw(17) << "CATEGORY" << setw(10) << "ID" << setw(20) << "NAME" << setw(20) << setw(10) << "PRICE" << setw(15) << "AVAILABILITY" << setw(10) << "HEALTH" << endl;
                cout << left << setw(17) << "--------" << setw(10) << "--" << setw(20) << "----" << setw(20) << setw(10) << "-----" << setw(15) << "------------" << setw(10) << "------" << endl << endl;

                while (readtemporaryproducts >> p.category >> p.id >> p.name >> p.price) {
                    cout << setw(17) << p.category << setw(10) << p.id << setw(20) << p.name << setw(20) << fixed << setprecision(2) << setw(10) << p.price << setw(15) << p.availability << setw(10) << p.health << endl;
                    cout << endl;
                }
                readtemporaryproducts.close();

            } else {
                cout << "Incorrect Input" << endl;
            }
}

void category_interface2(int &option){
    cout << "Select Category" << endl;
    cout << "1. Wedding" << endl;
    cout << "2. Corporate" << endl;
    cout << "3. Seasonal" << endl;
    cout << "4. Specialty" << endl;
    cout << endl;
    cout << "Enter the option: ";
    cin >> option;
}

void add_packages(ofstream &write){

Package p1;
int option1;
int option2;
int numofpackages;
bool go_back = false;
bool invalid_category = false;

    do {
        category_interface2(option1);
        switch (option1) {

            case 1: //wedding
                p1.category = "Wedding";
                break;

            case 2: //corporate
                p1.category = "Corporate";
                break;

            case 3: //seasonal
                p1.category = "Seasonal";
                break;

            case 4: //specialty
                p1.category = "Specialty";
                break;

            default:
                cout << "Status: Invalid Options. Try again" << endl << endl;
                invalid_category = true;
                continue;
        }
    } while (invalid_category);

         while (!(invalid_category)) {

            cout << "1. Go Back" << endl;
            cout << "2. Enter Package details" << endl << endl;

            cout << "Enter the input: ";
            cin >> option2;
            cout << endl << endl;

            if (option2 == 1) {
                category_interface2(option1);
                continue;

            } else if (option2 == 2) {

                cout << "Enter the Number of Packages to Add: ";
                cin >> numofpackages;

                cout << "PACKAGE INFO" << endl;
                cout << "------------" << endl;

                for (int i = 0; i < numofpackages; i++){

                    if (!(invalid_category)){

                        Package pack;
                        cout << "Package ID: ";
                        cin >> p1.id;
                        cout << "Package Name: ";
                        cin >> p1.name;
                        cout << "Package Price: ";
                        cin >> p1.price;
                        cout << "Package descriptions: ";
                        cin >> p1.description;
                        cout << "Availability: ";
                        cin >> p1.availability;
                        cout << "Health Option: ";
                        cin >> p1.health;
                        cout << endl;


                    write.open("packages", ios::app);
                    write << p1.category << " " << p1.id << " " << p1.name << " " << p1.description << " " << p1.price << " " << p1.availability << " " << p1.health << " " << endl;
                    write.close();

                    } else {
                        cout << "Status: Invalid Input" << endl;
                    }

                    break;
                }

            }
         }

}

void view_Packages(ifstream &read){

    Package p1;

    read.open("packages", ios::in);

    cout << left << setw(17) << "CATEGORY" << setw(10) << "ID" << setw(20) << "NAME" << setw(20) << "DESCRIPTION" << setw(10) << "PRICE" << setw(15) << "AVAILABILITY" << setw(10) << "HEALTH" << endl;
    cout << left << setw(17) << "--------" << setw(10) << "--" << setw(20) << "----" << setw(20) << "-----------" << setw(10) << "-----" << setw(15) << "------------" << setw(10) << "------" << endl;

    while (read >> p1.category >> p1.id >> p1.name >> p1.description >> p1.price >> p1.availability >> p1.health) {

        cout << setw(17) << p1.category << setw(10) << p1.id << setw(20) << p1.name << setw(20) << p1.description << fixed << setprecision(2) << setw(10) << p1.price << setw(15) << p1.availability << setw(10) << p1.health << endl;

        cout << endl;

    }

    read.close();
}


void search_packages(ifstream &read){

    string input;
    bool found = false;
            do {
                cout << "Enter the ID / NAME / CATEGORY of the Package: ";
                cin >> input;
                Package p1;

                read.open("packages", ios::in);
                cout << left << setw(17) << "CATEGORY" << setw(10) << "ID" << setw(20) << "NAME" << setw(20) << "DESCRIPTION" << setw(10) << "PRICE" << setw(15) << "AVAILABILITY" << setw(10) << "HEALTH" << endl;
                cout << left << setw(17) << "--------" << setw(10) << "--" << setw(20) << "----" << setw(20) << "-----------" << setw(10) << "-----" << setw(15) << "------------" << setw(10) << "------" << endl;


                while (read >> p1.category >> p1.id >> p1.name >> p1.description >> p1.price >> p1.availability >> p1.health) {

                        if ( p1.id == input || p1.name == input || p1.category == input){
                            cout << setw(17) << p1.category << setw(10) << p1.id << setw(20) << p1.name << setw(20) << p1.description << fixed << setprecision(2) << setw(10) << p1.price << setw(15) << p1.availability << setw(10) << p1.health << endl;
                            found = true;
                            cout << endl;
                        }
                }

                read.close();

                if (!(found)){
                    cout << "Invalid Input" << endl << endl;
                }
            } while (!(found));
}

void update_packages(ifstream &read){
    string id;
    char input1;
    int option;
    int option2;
    ifstream readpackages;
    ifstream readtemporarypackages;
    ofstream writetemporarypackages;
    bool inc_input = false; //incorrect input

        cout << "Selection Preview" << endl;
        cout << "--------- -------" << endl;
        cout << "1. View Packages" << endl;
        cout << "2. Search Packages" << endl;
        cout << "Enter the result: ";
        cin >> option;

        switch(option) {
            case 1:
                view_Packages(readpackages);
            break;

            case 2:
                search_packages(readpackages);
            break;
        }

        cout << endl;
        cout << "Update Session" << endl;
        cout << "--------------" << endl << endl;

        cout << "Enter the ID for Update: ";
        cin >> id;

        read.open("packages", ios::in);

        writetemporarypackages.open("temp1", ios::app);

        Package p1;
        bool updated = false;

        while (read >> p1.category >> p1.id >> p1.name >> p1.description >> p1.price >> p1.availability >> p1.health){
            if (id == p1.id) {

                    cout << "Package ID: ";
                    cin >> p1.id;
                    cout << "Package Name: ";
                    cin >> p1.name;
                    cout << "Package Price: ";
                    cin >> p1.price;
                    cout << "Package descriptions: ";
                    cin >> p1.description;
                    cout << "Availability: ";
                    cin >> p1.availability;
                    cout << "Health Option: ";
                    cin >> p1.health;
                    cout << endl;

                updated = true;
            }
             writetemporarypackages << p1.category << " " << p1.id << " " << p1.name << " " << p1.description << " " << p1.price << " " << p1.availability << " " << p1.health << " " << endl;
        }

        if (!(updated)) {
            writetemporarypackages << p1.category << " " << p1.id << " " << p1.name << " " << p1.description << " " << p1.price << " " << p1.availability << " " << p1.health << " " << endl;
        }

        read.close();
        writetemporarypackages.close();

            remove ("packages");
            rename ("temp1", "packages");
            cout << "Information Updated Successfully" << endl;

        cout << "View the Updated File" << endl;
        cout << "Y. Yes" << "      " << "N. No" << endl;
        cin >> input1;

            do {
                if (input1 == 'Y' || input1 == 'y') {
                    view_Packages(readpackages);

                } else if (input1 == 'N' || input1 == 'n') {
                    break;

                } else {
                    cout << "Status: Incorrect Input" << endl << endl;
                    inc_input = true;

                }

            } while (inc_input);

}

void remove_packages(ifstream &read){

    string id;
    int option;
    char input1;
    bool inc_input = false;
    ifstream readpackages;
    ifstream readtemporarypackages;
    ofstream writetemporarypackages;

        cout << "Selection Preview" << endl;
        cout << "--------- -------" << endl;
        cout << "1. View Packages" << endl;
        cout << "2. Search Packages" << endl;
        cout << "Enter the result: ";
        cin >> option;

        switch(option) {
            case 1:
                view_Packages(readpackages);
            break;

            case 2:
                search_packages(readpackages);
            break;
        }

        cout << endl;
        cout << "Update Session" << endl;
        cout << "--------------" << endl << endl;

        cout << "Enter the ID for Remove: ";
        cin >> id;
        cout << endl;

        read.open("packages", ios::in);

        writetemporarypackages.open("temp", ios::app);

        Package p1;
        bool deleted = false;

        while (read >> p1.category >> p1.id >> p1.name >> p1.description >> p1.price >> p1.availability >> p1.health){

            if (id == p1.id) {
                deleted = true;
                continue;
            }
             writetemporarypackages << p1.category << " " << p1.id << " " << p1.name << " " << p1.description << " " << p1.price << " " << p1.availability << " " << p1.health << " " << endl;
        }

        if(!(deleted)){
             writetemporarypackages << p1.category << " " << p1.id << " " << p1.name << " " << p1.description << " " << p1.price << " " << p1.availability << " " << p1.health << " " << endl;
        }

        read.close();
        writetemporarypackages.close();

            remove ("packages");
            rename ("temp", "packages");
            cout << "Product Deleted Successfully" << endl;

            do {

                cout << "View the Updated File" << endl;
                cout << "Y. Yes" << "      " << "N. No" << endl;
                cin >> input1;


                if (input1 == 'Y' || input1 == 'y') {
                    view_Packages(readpackages);

                } else if (input1 == 'N' || input1 == 'n') {
                    break;

                } else {
                    cout << "Status: Incorrect Input" << endl << endl;
                    inc_input = true;

                }

            } while (inc_input);

}

///admin or staff in

void if_admin(){

int option; // for go back input
int option2; // for go_back2
int option4;
int option5;
int option6;
int option7;
int option8;
bool continue_loop = false;
bool logout2 = false;
bool invalid_category2 = false;

bool go_back2;
//products
ofstream writeproducts;
ifstream readproducts;
//packages
ofstream writepackages;
ifstream readpackages;
//user
ifstream readuserdetail;
ofstream writeuserdetail;


    admin_interface1:



        admin_interface1(option4);

        switch(option4){

            case 1:
                admin_interface2:
                    admin_interface2(option5);

                        switch (option5){

                            case 1:
                            do {
                                    admin_interface3(option6);

                                    switch(option6){

                                        case 1:
                                            sign_in(writeuserdetail);
                                            break;

                                        case 2:
                                            // remove staff
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 3:
                                            // view staff
                                            break;

                                        case 4:
                                            // search staff
                                            break;

                                        case 5:
                                            // update staff
                                            break;

                                        case 6:
                                            goto admin_interface2;
                                            break;

                                        case 7:
                                            goto admin_interface1;
                                            break;

                                        default:
                                            cout << "Invalid Input" << endl;
                                            invalid_category2 = true;
                                            break;
                                    }
                            } while (go_back2);
                            break;

                            case 2:

                                do {
                                    admin_interface4(option7);

                                    switch(option7){

                                        case 1:
                                            // add products
                                            add_products(writeproducts);
                                            cout << endl;
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 2:
                                            // view products
                                            view_products(readproducts);
                                            cout << endl;
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 3:
                                            // remove products
                                            remove_product(readproducts);
                                            cout << endl;
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 4:
                                            // search products
                                            search_products(readuserdetail);
                                            cout << endl;
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 5:
                                            //update products
                                            update_products(readproducts);
                                            cout << endl;
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 6:
                                            goto admin_interface2;
                                            break;

                                        case 7:
                                            goto admin_interface1;
                                            break;

                                        default:
                                            cout << "Invalid Category" << endl;
                                            invalid_category2 = true;
                                            break;

                                    }

                                } while (go_back2);

                            break;

                            case 3:
                                do {
                                    admin_interface5(option8);
                                    switch (option8){
                                        case 1:
                                            // add_packages
                                            add_packages(writepackages);
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 2:
                                            //view packages
                                            view_Packages(readpackages);
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 3:
                                            //remove packages
                                            remove_packages(readpackages);
                                            go_back2 = loop_option(option2);
                                           break;

                                        case 4:
                                            search_packages(readpackages);
                                            go_back2 = loop_option(option2);
                                            break;

                                        case 5:
                                            //update packages
                                            update_packages(readpackages);
                                            go_back2 = loop_option(option2);
                                            break;


                                        case 6:
                                            goto admin_interface2;
                                            break;

                                        case 7:
                                            goto admin_interface1;
                                            break;
                                    }

                                } while (go_back2);

                                break;

                            case 4:
                                goto admin_interface1;
                                break;
                        }
            break;

            case 2:
                // log out
            break;
        }
}


void billing_products(ifstream &read_pro){
    ifstream readproducts;
    int nop; // number of products
    int option;
    int j = 0;
    bool confirmed = false;
    Products p;

    //for bill
    ofstream writebill;
    ifstream readbill;

        view_search:
            cout << "1. View Products" << endl;
            cout << "2. Search Products" << endl;
            cout << "Enter the result: ";
            cin >> option;
            switch(option) {
                case 1:
                    view_products(readproducts);
                break;

                case 2:
                    search_products(readproducts);
                break;

                default:
                    cout << "Incorrect Input " << endl;
                    goto view_search;
                break;
            }

        cout << "Billing Session" << endl;
        cout << "Number of Products for Billing: ";
        cin >> nop;

        Bill b[nop];

        for (int j = 0; j < nop; j++) {
            cout << "Enter the ID: ";
            cin >> b[j].id;

               do {
                    read_pro.open("products", ios::in);
                    while (read_pro >> p.category >> p.id >> p.name >> p.price){
                        if (b[j].id == p.id){
                            b[j].category = p.category;
                            b[j].name = p.name;
                            b[j].unitprice = p.price;

                            confirmed = true;
                            break;
                        }
                    }
                    if (!(confirmed)) {
                        cout << "Invalid Input" << endl;
                    }

                    read_pro.close();

               } while (!(confirmed));

               cout << "Enter the Quality: ";
               cin >> b[j].quality;
               cout << endl << endl;

               b[j].total = b[j].totalprice();
               confirmed = false;

        }

            cout << left << setw(17) << "CATEGORY" << setw(10) << "ID" << setw(20) << "NAME" << setw(10) << "PRICE" << setw(10) << "QUALITY" << setw(10) << "TOTAL"  << endl;
            cout << left << setw(17) << "--------" << setw(10) << "--" << setw(20) << "----" << setw(10) << "-----" << setw(10) << "-------" << setw(10) << "-----" << endl << endl;

            int totalbill = 0;
            writebill.open("billinfo", ios::app);
            readbill.open("billinfo", ios::in);

            for (int i = 0; i < nop; i++){
                cout << setw(17) << b[i].category << setw(10) << b[i].id << setw(20) << b[i].name << setw(10) << b[i].unitprice << setw(10) << b[i].quality << setw(10) << b[i].total <<  endl;
                totalbill = totalbill + b[i].total;
                writebill << setw(17) << b[i].bill_id << setw(10) << b[i].category << setw(10) << b[i].id << setw(20) << b[i].name << setw(10) << b[i].unitprice << setw(10) << b[i].quality << setw(10) << b[i].total;

                if (readbill){
                    int currentbill_id = 0;
                    while (readbill >> b[i].bill_id >> b[i].category >> b[i].id >> b[i].name >> b[i].unitprice >> b[i].quality >> b[i].total) {
                        b[i].bill_id  = currentbill_id + 1;
                }
                } else {
                        b[i].bill_id = 1;
                }

            }
            writebill.close();
            readbill.close();
            cout << "Total Bill: " << totalbill << endl;

}

void view_customers(ifstream &read3){
Customers c;

    cout << "CUSTOMER VIEW SESSION" << endl;
    cout << "---------------------" << endl << endl;
    read3.open("customers",ios::in);

        if (!read3.is_open()) {
        cout << "Error: File not found" << endl;
        return; // Exit the function if the file is not found
    }

    cout << left << setw(10) << "ID" << setw(20) << "FULL NAME" << setw(10) << "GENDER"<< setw(5) << "AGE" << setw(15) << "PHONE NUMBER" << setw(15) << "ADDRESS" << endl;
    cout << left << setw(10) << "--" << setw(20) << "---------" << setw(10) << "------"<< setw(5) << "---" << setw(15) << "------------" << setw(15) << "-------" << endl;

        while (read3 >> c.id >> c.fullname >> c.gender >> c.age >> c.phonenumber >> c.address) {
            cout << left << setw(10) << c.id << setw(20) << c.fullname << setw(10) << c.gender << setw(5) << c.age << setw(15) << c.phonenumber << setw(15) << c.address << endl;
        }
}

bool viewcustomer_option(){
bool flag = false;
bool invalid_input1 = false;
char input2;
ifstream readcustomers;

        do {
            cout << "View Customer Details (Y/N): ";
            cin >> input2;
                if (input2 == 'Y' || input2 == 'y') {
                    view_customers(readcustomers);
                    flag = true;
                } else if (input2 == 'N' || input2 == 'n'){
                    continue;
                } else {
                    cout << "Invalid Input" << endl;
                    invalid_input1 = true;
                }

            cout << endl;
        } while (invalid_input1);

    return flag;
}

void search_customers(ifstream &read3){
Customers c;
string input;
int input1;
int input2;
ifstream readcustomers;
bool invalid_input = false;
bool viewcustomer;

    repeat_session:
        cout << "CUSTOMER SEARCH SESSION" << endl;
        cout << "-----------------------" << endl;

        viewcustomer = viewcustomer_option(); // to select if the user wants to view the customers.

        cout << "Enter the ID/ Name / Phone Number:  ";
        cin >> input;

        cout << left << setw(10) << "ID" << setw(20) << "FULL NAME" << setw(10) << "GENDER"<< setw(5) << "AGE" << setw(15) << "PHONE NUMBER" << setw(15) << "ADDRESS" << endl;
        cout << left << setw(10) << "--" << setw(20) << "---------" << setw(10) << "------"<< setw(5) << "---" << setw(15) << "------------" << setw(15) << "-------" << endl;

        read3.open("customers", ios::in);
        while (read3 >> c.id >> c.fullname >> c.gender >> c.age >> c.phonenumber >> c.address) {
            if (input == c.id || input == c.fullname || input == c.phonenumber) {
            cout << left << setw(10) << c.id << setw(20) << c.fullname << setw(10) << c.gender << setw(5) << c.age << setw(15) << c.phonenumber << setw(15) << c.address << endl;            }
        }

        read3.close();

        while (invalid_input == true) {

            cout << "Would you like to Search again ( Y/N )?: ";
            cin >> input1;
                 if (input2 == 'Y' || input2 == 'y') {
                    goto repeat_session;
                } else if (input2 == 'N' || input2 == 'n'){
                    break;
                } else {
                    cout << "Invalid Input" << endl << endl;
                    invalid_input = true;
                }
        }



}

void remove_customers(ifstream &read3){

    string id;
    int option;
    char input1;
    bool inc_input = false;
    ifstream readtemporarycustomerdata;
    ofstream writetemporarycustomerdata;

        cout << "-----------------------" << endl;
        cout << "CUSTOMER REMOVE SESSION" << endl;
        cout << "-----------------------" << endl << endl << endl;

        cout << "Selection Preview" << endl;
        cout << "--------- -------" << endl << endl;

        cout << "1. View Customers" << endl;
        cout << "2. Search Customers" << endl;
        cout << "Enter the result: ";
        cin >> option;
        cout << endl;
        switch(option) {
            case 1:
                view_customers(read3);
                break;

            case 2:
                search_customers(read3);
                break;
        }

        cout << endl << endl;

        cout << "---------------" << endl;
        cout << "Removal Session" << endl;
        cout << "---------------" << endl << endl;

        cout << "Enter the ID to Remove: ";
        cin >> id;
        cout << endl;

        read3.open("customers", ios::in);

        writetemporarycustomerdata.open("temp1", ios::app);

        Customers c;
        bool deleted = false;

        while (read3 >>c.id >> c.fullname >> c.gender >> c.age >> c.phonenumber >> c.address){

            if (id == c.id) {
                deleted = true;
                continue;
            }
            writetemporarycustomerdata << c.id << "  " << c.fullname << "  " << c.gender << "  " << c.age << "  " << c.phonenumber << "  " << c.address << endl;
        }

        if(!(deleted)){
            writetemporarycustomerdata << c.id << "  " << c.fullname << "  " << c.gender << "  " << c.age << "  " << c.phonenumber << "  " << c.address << endl;
        }

        read3.close();
        writetemporarycustomerdata.close();

            remove ("customers");
            rename ("temp1", "customers");
            cout << "Product Deleted Successfully" << endl;

        viewupdate:
            cout << "View the Updated File" << endl;
            cout << "Y. Yes" << "      " << "N. No" << endl;
            cin >> input1;

                if (input1 == 'Y' || input1 == 'y') {
                    view_customers(read3);
                } else if (input1 == 'N' || input1 == 'n') {
                    cout << "Exiting the program" << endl;
                    exit(0);
                } else {
                    cout << "Invalid Input" << endl;
                    goto viewupdate;
                }


}

void update_customers(ifstream &read3){
    string id;
    int option;
    int option1;
    int option2;
    int input1;
    bool confirmed = false;
    bool confirmed2 = false;
    //structs
    Customers c;
    ifstream readtemporarycustomerdata;
    ofstream writetemporarycustomerdata;

        cout << "Selection Preview" << endl;
        cout << "--------- -------" << endl;
        cout << "1. View Customers" << endl;
        cout << "2. Search Customers" << endl;
        cout << "Enter the result: ";
        cin >> option;

        switch(option) {
            case 1:
                view_customers(read3);
                break;

            case 2:
                search_customers(read3);
                break;
        }
        cout << endl;
        cout << "--------------" << endl;
        cout << "Update Session" << endl;
        cout << "--------------" << endl << endl;

        cout << "Enter the ID for Update: ";
        cin >> id;

        read3.open("customers", ios::in);

        writetemporarycustomerdata.open("temp1", ios::app);

        bool updated = false;

        while (read3 >>c.id >> c.fullname >> c.gender >> c.age >> c.phonenumber >> c.address){
            if (id == c.id) {

                cout << "CUSTOMER INFO FOR UPDATE" << endl;
                cout << "------------------------" << endl;

                do {
                    cout << "---------------------------------------------" << endl;
                    cout << "Note: 1 Uppercase and 4 Numbers Consecutively" << endl;
                    cout << "---------------------------------------------" << endl;
                    cout << "Enter the ID: ";
                    cin >> c.id;

                        bool hasdigit2 = false, hasupper2 = false;
                        int t = (c.id).length();

                        for (int i = 0; i < t; i++ ) {
                            if (isdigit(c.id[i])) hasdigit2 = true;
                            if (isupper(c.id[i])) hasupper2 = true;
                        }

                            if (t > 4 && t < 6 && hasdigit2 && hasupper2){
                                cout << "ID Registered Successfully" << endl << endl;
                                confirmed = true;
                            } else {
                                cout << "Input had failed to meet requirements" << endl;
                            }

                } while (!(confirmed));

                    cout << "Customer's Full Name: ";
                    cin >> c.fullname;
                    cout << endl;

                    choose_gender:
                        cout << "Customer's Gender: " << endl << endl;
                        cout << "1. Male" << endl;
                        cout << "2. Female" << endl;
                        cout << "Choose: ";
                        cin >> option1;

                            switch(option1){
                                case 1:
                                    cout << "Gender: Male" << endl;
                                    c.gender = "Male";
                                    break;

                                case 2:
                                    cout << "Gender: Female" << endl;
                                    c.gender = "Female";
                                    break;

                                default:
                                    goto choose_gender;
                                    break;
                            }
                        cout << endl;

                    cout << "Customer's Age: ";
                    cin >> c.age;

                    do{
                        cout << "Customer's Phone Number: ";
                        cin >> c.phonenumber;
                            bool hasdigit1 = false;
                            int phone = (c.phonenumber).length();

                                for (int j = 0; j < phone; j++){
                                     if (isdigit(c.phonenumber[j])) hasdigit1 = true;
                                }
                                if ((phone > 9 && phone < 11) && hasdigit1) {
                                    cout << "Valid Phone Number" << endl;
                                    confirmed2 = true;
                                } else {
                                    cout << "Input has failed to meet requirements" << endl;
                                }
                                cout << endl;

                    } while (!(confirmed2));

                    cout << "Customer's Address: ";
                    cin >> c.address;

                updated = true;
            }
             writetemporarycustomerdata << c.id << "  " << c.fullname << "  " << c.gender << "  " << c.age << "  " << c.phonenumber << "  " << c.address << endl;
        }

        if (!(updated)) {
             writetemporarycustomerdata << c.id << "  " << c.fullname << "  " << c.gender << "  " << c.age << "  " << c.phonenumber << "  " << c.address << endl;
        }
        read3.close();
        writetemporarycustomerdata.close();

            remove ("customers");
            rename ("temp1", "customers");
            cout << "Status: Information Updated Successfully" << endl << endl;

        viewupdate:
            cout << "View the Updated File" << endl;
            cout << "Y. Yes" << "      " << "N. No" << endl;
            cin >> input1;

                if (input1 == 'Y' || input1 == 'y') {
                    view_customers(read3);
                } else if (input1 == 'N' || input1 == 'n') {
                    cout << "Exiting the program" << endl;
                    exit(0);
                } else {
                    cout << "Invalid Input" << endl;
                    goto viewupdate;
                }


}

void Order_billing_packages(ifstream &read_pack){
ifstream readpackages;
ofstream writecustomers;
ifstream readcustomers;
int nop; // number of products
int option;
int option1;
char option2;
int j = 0;
bool confirmed = false;
bool confirmed1 = false; // for customer ID
bool confirmed2 = false; // for customer's phone number
Package p1;

//for bill
ofstream writebill;
ifstream readbill;

Customers c;
int input1;

    cout << "-------------" << endl;
    cout << "CUSTOMER INFO" << endl;
    cout << "-------------" << endl;
    cout << "Number of customers to Add: ";
    cin >> input1;
    cout << endl;
    for (int i = 0; i < input1; i++) {

        do {
            cout << "---------------------------------------------" << endl;
            cout << "Note: 1 Uppercase and 4 Numbers Consecutively" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Enter the ID: ";
            cin >> c.id;

                bool hasdigit2 = false, hasupper2 = false;
                int t = (c.id).length();

                for (int i = 0; i < t; i++ ) {
                    if (isdigit(c.id[i])) hasdigit2 = true;
                    if (isupper(c.id[i])) hasupper2 = true;
                }

                    if (t > 4 && t < 6 && hasdigit2 && hasupper2){
                        cout << "ID Registered Successfully" << endl << endl;
                        confirmed = true;
                    } else {
                        cout << "Input had failed to meet requirements" << endl;
                    }

        } while (!(confirmed));

            cout << "Customer's Full Name: ";
            cin >> c.fullname;
            cout << endl;

            choose_gender:
                cout << "Customer's Gender: " << endl << endl;
                cout << "1. Male" << endl;
                cout << "2. Female" << endl;
                cout << "Choose: ";
                cin >> option1;


                    switch(option1){
                        case 1:
                            cout << "Gender: Male" << endl;
                            c.gender = "Male";
                            break;

                        case 2:
                            cout << "Gender: Female" << endl;
                            c.gender = "Female";
                            break;

                        default:
                            goto choose_gender;
                            break;
                    }
                cout << endl;

            cout << "Customer's Age: ";
            cin >> c.age;

            do{
                cout << "Customer's Phone Number: ";
                cin >> c.phonenumber;
                    bool hasdigit1 = false;
                    int phone = (c.phonenumber).length();

                        for (int j = 0; j < phone; j++){
                             if (isdigit(c.phonenumber[j])) hasdigit1 = true;
                        }
                        if ((phone > 9 && phone < 11) && hasdigit1) {
                            cout << "Valid Phone Number" << endl;
                            confirmed2 = true;
                        } else {
                            cout << "Input has failed to meet requirements" << endl;
                        }
                        cout << endl;

            } while (!(confirmed2));

            cout << "Customer's Address: ";
            cin >> c.address;

            writecustomers.open("customers", ios::app);
            writecustomers << c.id << "  " << c.fullname << "  " << c.gender << "  " << c.age << "  " << c.phonenumber << "  " << c.address << endl;
            writecustomers.close();

            viewcustomer_option();

            cout << "1. View Packages" << endl;
            cout << "2. Search Packages" << endl;
            cout << "Enter the result: ";
            cin >> option;
            cout << endl;

            switch(option) {
                case 1:
                    view_Packages(readpackages);
                break;

                case 2:
                    search_packages(readpackages);
                break;
            }

            cout << "Billing Session" << endl;
            cout << "Number of Packages for Billing: ";
            cin >> nop;

            Bill b1[nop];

            for (int j = 0; j < nop; j++) {
                cout << "Enter the ID: ";
                cin >> b1[j].id;

                   do {
                        read_pack.open("packages", ios::in);
                        while (read_pack >> p1.category >> p1.id >> p1.name >> p1.description >> p1.price >> p1.availability >> p1.health){
                            if (b1[j].id == p1.id){
                                b1[j].category = p1.category;
                                b1[j].name = p1.name;
                                b1[j].unitprice = p1.price;

                                confirmed = true;
                                break;
                            }
                        }
                        if (!(confirmed)) {
                            cout << "Invalid Input" << endl;
                        }

                        read_pack.close();

                   } while (!(confirmed));

                   cout << "Enter the Quality: ";
                   cin >> b1[j].quality;
                   cout << endl << endl;

                   b1[j].total = b1[j].totalprice();
                   confirmed = false;

            }

                cout << left << setw(17) << "CATEGORY" << setw(10) << "ID" << setw(20) << "NAME" << setw(10) << "PRICE" << setw(10) << "QUALITY" << setw(10) << "TOTAL"  << endl;
                cout << left << setw(17) << "--------" << setw(10) << "--" << setw(20) << "----" << setw(10) << "-----" << setw(10) << "-------" << setw(10) << "-----" << endl << endl;

                int totalbill = 0;
                writebill.open("billinfo_packages", ios::app);
                readbill.open("billinfo_packages", ios::in);

                for (int i = 0; i < nop; i++){

                    cout << setw(17) << b1[i].category << setw(10) << b1[i].id << setw(20) << b1[i].name << setw(10) << b1[i].unitprice << setw(10) << b1[i].quality << setw(10) << b1[i].total <<  endl;
                    totalbill = totalbill + b1[i].total;
                    writebill << setw(17) << b1[i].bill_id << setw(10) << b1[i].category << setw(10) << b1[i].id << setw(20) << b1[i].name << setw(10) << b1[i].unitprice << setw(10) << b1[i].quality << setw(10) << b1[i].total << endl;

                    if (readbill){
                        int currentbill_id = 0;
                        while (readbill >> b1[i].bill_id >> b1[i].category >> b1[i].id >> b1[i].name >> b1[i].unitprice >> b1[i].quality >> b1[i].total) {
                            b1[i].bill_id  = currentbill_id + 1;
                    }

                    } else {
                            b1[i].bill_id = 1;
                    }

                }

                writebill.close();
                readbill.close();
                cout << endl;
                cout << "------------" << endl;
                cout << "Total Bill: " << totalbill << endl;
                cout << "------------" << endl;
    }
}

void if_staff(){
int option2; // for staff_interface1 function
int option3; // for staff_interface2 function
int option1; // for staff_interface3 function
bool go_back2;
bool continue_loop2 = false;
bool logout1 = false;
ifstream readuserdetail;
ifstream readproducts;
ifstream readpackages;
ifstream readcustomers;


        staff_interface1:
         staff_interface1(option2);
                switch(option2){
                    case 1:
                        do {
                            staff_interface2(option3);
                                switch(option3){

                                    case 1:
                                        view_products(readproducts);
                                        go_back2 = loop_option(option2);
                                    break;

                                    case 2:
                                        billing_products(readproducts);
                                        go_back2 = loop_option(option2);
                                    break;

                                    case 3:
                                        view_Packages(readpackages);
                                        go_back2 = loop_option(option2);
                                        break;
                                    case 4:
                                        //billing for package
                                        Order_billing_packages(readpackages);
                                        go_back2 = loop_option(option2);
                                    break;

                                    case 5:
                                        goto staff_interface1;
                                    break;
                                }
                            } while(go_back2);
                    break;

                    case 2:
                        // manage customers
                        do {
                            staff_interface3(option1);
                            switch(option1){

                                case 1:
                                    // view customers
                                    view_customers(readcustomers);
                                    go_back2 = loop_option(option2);
                                    break;
                                case 2:
                                    // search customers
                                    search_customers(readcustomers);
                                    go_back2 = loop_option(option2);
                                    break;
                                case 3:
                                    //update customers
                                    update_customers(readcustomers);
                                    go_back2 = loop_option(option2);
                                    break;

                                case 4:
                                    //remove customers
                                    remove_customers(readcustomers);
                                    go_back2 = loop_option(option2);
                                    break;

                                case 5:
                                    goto staff_interface1;
                                    break;

                            }
                        } while(go_back2);

                    break;

                    case 3:
                        logout1 = true;
                    break;
                }

}

int main(){

//fstream library
ofstream writeuserdetail;
ifstream readuserdetail;
bool incorrect_input = false;
int option1; // for common_interface function

bool get_login_resultl;

    cout << "============" << endl;
    cout << "AMBER BAKERY" << endl;
    cout << "============" << endl << endl;

    common_interface:
        common_interface(option1);

            switch(option1){
                case 1:
                    get_login_resultl = login_form(readuserdetail);
                    break;

                case 2:
                    cout << "Amber Bakery” is an award-winning artisan bakery which was founded in 2005." << endl;
                    cout << "We are producing authentic rye breads and patisserie products using a selection of best and most popular traditional recipes from Eastern Europe." << endl;
                    cout << "We supply our products to over 160 shops in London, the Home Countries and many major cities across the UK." << endl;
                    break;

                default:
                    cout << "Incorrect Input" << endl;
                    cin.clear();                // Clear the fail state
                    cin.ignore(INT_MAX, '\n');  // Ignore characters up to a newline
                    goto common_interface;
                    break;
                }



    if (current_role == "admin") {
        if_admin();

    } else if (current_role == "staff"){
       if_staff();

    } else {
        cout << "Incorrect Input" << endl;
    }

  return 0;

}
