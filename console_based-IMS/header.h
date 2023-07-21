#include<iostream>
#include<conio.h>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

int Module__Selecter();
void Wellcome();
void AfterWellcome();

class signIn
{
protected:
	string userName;
	string password;
public:
	signIn();
	void signIn_interface();
	//virtual void display() = 0;

};

class add_New_Shop_keeper
{
public:
	//protected:
	static int idOfShop;                                   //To generate id numbers to Shopkeepers.I used static member function
	string Fname_shop, Lname_shop, userName_shop;
	string Email_shop, Password_shop, RegistrationDate_shop;
	string contactNum_shop, Address_shop, bloodGroup_shop;
	string gender_shop;
	int S_id;
	//public:
	add_New_Shop_keeper();
	void set_S_Id();
	int get_Id()const;
	void InputDataShop();
	void editData(int);
	void EditDataShop();
	void DeleteDataShop();
};


class add_New_Customer                          //Class to Add Customer
{
public:
	//protected:
	static int idOfCustomer;                                   //To generate id numbers to Customer.I used static member function
	string Fname_customer, Lname_customer, RegistrationDate_customer;
	string userName_customer, Email_customer, Password_customer;
	string contactNum_customer, Address_customer, bloodGroup_customer;
	string gender_customer;
	int C_id;
	//public:
	add_New_Customer();

	void set_C_Id();
	int get_C_Id()const;
	void InputDataCustomer();
	void editingdata(int x);
	void EditDataCustomer();
	void DeleteDataCustomer();
};


class Add_New_Product
{
public:
	static long sports, Garments, Eatables, Medicines, Fashion;
	int     Product_Quantity;
	long P_id;
	string Product_name, Discription_Product, Product_category;

	Add_New_Product();
	void set_P_Id(int n);
	long get_P_Id()const;
	void viewProduct();
	void InputDataOfProduct();
	void editingproductdata(int x);
	void EditDataProduct();
	void DeleteDataProduct();
};


class Administrator_Module :public signIn, public add_New_Shop_keeper, public Add_New_Product, public add_New_Customer
{
private:
	string userName_Admin, pass_Admin;
public:
	Administrator_Module();
	void display_options();
	void check();                             //Which checks whether username and pass are correct or not

};



class  Shopkeeper_Module :public signIn, public add_New_Shop_keeper, public Add_New_Product
{
private:
	string userName_shop, pass_Shop;
public:
	Shopkeeper_Module();
	void check();
	void display_options_shop();
};


class Customer_Module :public signIn, public add_New_Customer, public Add_New_Product
{
private:
	string userName_customer, pass_customer;
public:
	Customer_Module();
	void Display_signin_up_option();
	void Display_options_cus();
	void check();
	void purchase_Product();
	void Check_out();
};
