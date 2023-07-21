#include"Header.h"
static int signErrorResolver = 0;

signIn::signIn() :userName("/0"), password("/0")
{}

void signIn::signIn_interface()
{
	//cin.ignore();
	system("CLS");
	cout << "*******************************************************************" << endl;

	for (int i = 0; i <= 6; i++)
	{
		cout << "*                                                                 *" << endl;
	}
	cout << "*                   ENTER USER NAME   : ";
	//cin >> userName;
	//cin.ignore();
	getline(cin, userName);
	cout << "*                   ENTER PASSWORD    : ";
	//cin >> password;
	getline(cin, password);
	//cin.ignore();
	for (int i = 0; i <= 6; i++)
	{
		cout << "*                                                                 *" << endl;
	}
	cout << "*******************************************************************" << endl;

	system("pause>0");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int add_New_Shop_keeper::idOfShop = 0001;

add_New_Shop_keeper::add_New_Shop_keeper() :Fname_shop("/0"), Lname_shop("/0"), userName_shop("/0"), Email_shop("/0"), Password_shop("/0"), RegistrationDate_shop("/0"), contactNum_shop("/0"), Address_shop("/0"), bloodGroup_shop("/0")
{
	S_id = 0;
	gender_shop = "/0";
}

void add_New_Shop_keeper::editData(int x)
{
	cout << "   'ID Of ShopKeeper': " << x << endl;
	cout << "Enter First Name          : ";
	cin >> Fname_shop;
	cout << "Enter Last Name           : ";
	cin >> Lname_shop;
	cout << "Enter UserName            : ";
	cin.ignore();
	getline(cin, userName_shop);
	cout << "Enter Email               : ";
	cin >> Email_shop;
	cout << "Enter Password            : ";
	cin.ignore();
	getline(cin, Password_shop);
	cout << "Enter Registration Date   : ";
	cin >> RegistrationDate_shop;
	cout << "Enter Address             : ";
	cin >> Address_shop;
	cout << "Enter Contact-Num         : ";
	cin >> contactNum_shop;
l2:
	cout << "Enter Blood-Group         : ";
	cin >> bloodGroup_shop;
	if (bloodGroup_shop != "A+" && bloodGroup_shop != "A-" && bloodGroup_shop != "B+"
		&& bloodGroup_shop != "B-" && bloodGroup_shop != "AB+" && bloodGroup_shop != "AB-"
		&& bloodGroup_shop != "O+" && bloodGroup_shop != "O-")
	{
		goto l2;
	}
l1:
	cout << "Enter Gender (M or F)     : ";
	cin >> gender_shop;
	if (gender_shop != "M" && gender_shop != "F" && gender_shop != "m" && gender_shop != "f")
	{
		goto l1;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	ofstream write("Shopkeeper.txt", ios::app);

	write << get_Id() << " " << Fname_shop << " " << Lname_shop << " " << userName_shop << " " << Email_shop << " "
		<< Password_shop << " " << RegistrationDate_shop << " " << Address_shop << " " << contactNum_shop << " "
		<< bloodGroup_shop << " " << gender_shop << endl;

	write.close();

	cout << "!! Data Updated in ShopKeeper file !!" << endl;
}

void add_New_Shop_keeper::InputDataShop()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "-----------------------------------------SHOP-KEEPER--------------------------------------------" << endl;
	set_S_Id();
	cout << "   'ID Of ShopKeeper': " << get_Id() << endl;
	cout << "Enter First Name          : ";
	cin >> Fname_shop;
	cout << "Enter Last Name           : ";
	cin >> Lname_shop;
	cout << "Enter UserName            : ";
	cin.ignore();
	getline(cin, userName_shop);
	cout << "Enter Email               : ";
	cin >> Email_shop;
	cout << "Enter Password            : ";
	cin.ignore();
	getline(cin, Password_shop);
	cout << "Enter Registration Date   : ";
	cin >> RegistrationDate_shop;
	cout << "Enter Address             : ";
	cin >> Address_shop;
	cout << "Enter Contact-Num         : ";
	cin >> contactNum_shop;
l2:
	cout << "Enter Blood-Group         : ";
	cin >> bloodGroup_shop;
	if (bloodGroup_shop != "A+" && bloodGroup_shop != "A-" && bloodGroup_shop != "B+"
		&& bloodGroup_shop != "B-" && bloodGroup_shop != "AB+" && bloodGroup_shop != "AB-"
		&& bloodGroup_shop != "O+" && bloodGroup_shop != "O-")
	{
		goto l2;
	}
l1:
	cout << "Enter Gender (M or F)     : ";
	cin >> gender_shop;
	if (gender_shop != "M" && gender_shop != "F" && gender_shop != "m" && gender_shop != "f")
	{
		goto l1;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	ofstream write("Shopkeeper.txt", ios::app);

	write << get_Id() << " " << Fname_shop << " " << Lname_shop << " " << userName_shop << " " << Email_shop << " "
		<< Password_shop << " " << RegistrationDate_shop << " " << Address_shop << " " << contactNum_shop << " "
		<< bloodGroup_shop << " " << gender_shop << endl;

	write.close();

	cout << "!! Data Updated in ShopKeeper file !!" << endl;
}

void add_New_Shop_keeper::EditDataShop()
{
	int x;
	ifstream read("Shopkeeper.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	add_New_Shop_keeper* temp = new add_New_Shop_keeper[count2];
	count = 0;

	read.open("Shopkeeper.txt");
	while (!read.eof())
	{
		read >> temp[count].S_id >> temp[count].Fname_shop >> temp[count].Lname_shop >> temp[count].userName_shop >> temp[count].Email_shop
			>> temp[count].Password_shop >> temp[count].RegistrationDate_shop >> temp[count].Address_shop >> temp[count].contactNum_shop
			>> temp[count].bloodGroup_shop >> temp[count].gender_shop;
		count++;
	}
	read.close();

here3:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < count2 - 1; i++)
	{
		cout << temp[i].get_Id() << " " << temp[i].Fname_shop << " " << temp[i].Lname_shop << " " << temp[i].userName_shop << " " << temp[i].Email_shop << " "
			<< temp[i].Password_shop << " " << temp[i].RegistrationDate_shop << " " << temp[i].Address_shop << " " << temp[i].contactNum_shop << " "
			<< temp[i].bloodGroup_shop << " " << temp[i].gender_shop << endl;
	}
	try
	{
		cout << "\nEnter Id of Shopkeeeper which you want to edit    : ";
		cin >> x;
		throw x;
	}
	catch (int)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here3;
		}
	}

	int checking = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp[i].S_id == x)
		{
			temp[i].editData(x);
			break;
		}
		if (temp[i].S_id != x)
		{
			checking++;
		}
	}
	if (checking == count)
	{
		cout << "!!      ID not Found         !!" << endl;
	}

	ofstream write("Shopkeeper.txt");

	for (int i = 0; i < count - 1; i++)
	{
		/*if (i == var)
			continue;*/
		write << temp[i].get_Id() << " " << temp[i].Fname_shop << " " << temp[i].Lname_shop << " " << temp[i].userName_shop << " " << temp[i].Email_shop << " "
			<< temp[i].Password_shop << " " << temp[i].RegistrationDate_shop << " " << temp[i].Address_shop << " " << temp[i].contactNum_shop << " "
			<< temp[i].bloodGroup_shop << " " << temp[i].gender_shop << endl;
	}
	write.close();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void add_New_Shop_keeper::DeleteDataShop()
{

	int x;

	ifstream read("Shopkeeper.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	add_New_Shop_keeper* temp = new add_New_Shop_keeper[count2];
	count = 0;

	read.open("Shopkeeper.txt");
	while (!read.eof())
	{
		read >> temp[count].S_id >> temp[count].Fname_shop >> temp[count].Lname_shop >> temp[count].userName_shop >> temp[count].Email_shop
			>> temp[count].Password_shop >> temp[count].RegistrationDate_shop >> temp[count].Address_shop >> temp[count].contactNum_shop
			>> temp[count].bloodGroup_shop >> temp[count].gender_shop;
		count++;
	}
	read.close();
here3:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


	for (int i = 0; i < count2 - 1; i++)
	{
		cout << temp[i].get_Id() << " " << temp[i].Fname_shop << " " << temp[i].Lname_shop << " " << temp[i].userName_shop << " " << temp[i].Email_shop << " "
			<< temp[i].Password_shop << " " << temp[i].RegistrationDate_shop << " " << temp[i].Address_shop << " " << temp[i].contactNum_shop << " "
			<< temp[i].bloodGroup_shop << " " << temp[i].gender_shop << endl;
	}
	try
	{
		cout << "\nEnter Id of Shopkeeeper which you want to Delete    : ";
		cin >> x;
		throw x;
	}
	catch (int)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here3;
		}
	}


	int checking = 0, findingIndex = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp[i].S_id == x)
		{
			findingIndex = temp[i].S_id;
			break;
		}
		if (temp[i].S_id != x)
		{
			checking++;
		}
	}
	if (checking == count)
	{
		cout << "!!      ID not Found         !!" << endl;
	}

	ofstream write("Shopkeeper.txt");

	for (int i = 0; i < count - 1; i++)
	{
		if (temp[i].get_Id() != findingIndex)
		{
			write << temp[i].get_Id() << " " << temp[i].Fname_shop << " " << temp[i].Lname_shop << " " << temp[i].userName_shop << " " << temp[i].Email_shop << " "
				<< temp[i].Password_shop << " " << temp[i].RegistrationDate_shop << " " << temp[i].Address_shop << " " << temp[i].contactNum_shop << " "
				<< temp[i].bloodGroup_shop << " " << temp[i].gender_shop << endl;
		}
	}
	write.close();
	if (checking != count)
	{
		cout << "!!   RECORD SUCCESSFULLY DELETED  !!" << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void add_New_Shop_keeper::set_S_Id()
{
	ifstream read("Shopkeeper.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}
	read.close();

	add_New_Shop_keeper* temp = new add_New_Shop_keeper[count2];
	count = 0;

	read.open("Shopkeeper.txt");
	while (!read.eof())
	{
		read >> temp[count].S_id >> temp[count].Fname_shop >> temp[count].Lname_shop >> temp[count].userName_shop >> temp[count].Email_shop
			>> temp[count].Password_shop >> temp[count].RegistrationDate_shop >> temp[count].Address_shop >> temp[count].contactNum_shop
			>> temp[count].bloodGroup_shop >> temp[count].gender_shop;
		count++;
	}
	read.close();


	int size = count2 - 1;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = temp[i].S_id;
	}

	int max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	if (max <= 0)
	{
		S_id = idOfShop;
		idOfShop++;
	}
	else
	{
		for (int i = idOfShop; i <= max; i++) { idOfShop++; }
		S_id = idOfShop;
		idOfShop++;
	}
	free(arr);
}
int add_New_Shop_keeper::get_Id()const
{
	return S_id;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int add_New_Customer::idOfCustomer = 0001;

add_New_Customer::add_New_Customer() :contactNum_customer("/0"), Address_customer("/0"), bloodGroup_customer("/0"), Fname_customer("/0"), Lname_customer("/0"), userName_customer("/0"), Email_customer("/0"), Password_customer("/0"), RegistrationDate_customer("/0")
{
	C_id = 0;
	gender_customer = 'M';
}


void add_New_Customer::editingdata(int x)
{
	cout << "   'ID Of Customer  ': " << x << endl;
	cout << "Enter First Name          : ";
	cin >> Fname_customer;
	cout << "Enter Last Name           : ";
	cin >> Lname_customer;
	cout << "Enter UserName            : ";
	cin.ignore();
	getline(cin, userName_customer);
	cout << "Enter Email               : ";
	cin >> Email_customer;
	cout << "Enter Password            : ";
	cin.ignore();
	getline(cin, Password_customer);
	cout << "Enter Registration Date   : ";
	cin >> RegistrationDate_customer;
	cout << "Enter Address             : ";
	cin >> Address_customer;
	cout << "Enter Contact-Num         : ";
	cin >> contactNum_customer;
l2:
	cout << "Enter Blood-Group         : ";
	cin >> bloodGroup_customer;
	if (bloodGroup_customer != "A+" && bloodGroup_customer != "A-" && bloodGroup_customer != "B+"
		&& bloodGroup_customer != "B-" && bloodGroup_customer != "AB+" && bloodGroup_customer != "AB-"
		&& bloodGroup_customer != "O+" && bloodGroup_customer != "O-")
	{
		goto l2;
	}
l1:
	cout << "Enter Gender              : ";
	cin >> gender_customer;
	if (gender_customer != "M" && gender_customer != "F" && gender_customer != "m" && gender_customer != "f")
	{
		goto l1;
	}

	ofstream write("Customer.txt", ios::app);

	write << get_C_Id() << " " << Fname_customer << " " << Lname_customer << " " << userName_customer << " " << Email_customer << " "
		<< Password_customer << " " << RegistrationDate_customer << " " << Address_customer << " " << contactNum_customer << " "
		<< bloodGroup_customer << " " << gender_customer << endl;

	write.close();

	cout << "!! Data Updated in Customer file !!" << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void add_New_Customer::InputDataCustomer()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "-------------------------------------------CUSTOMER---------------------------------------------" << endl;
	set_C_Id();
	cout << "   'ID Of Customer  ': " << get_C_Id() << endl;
	cout << "Enter First Name          : ";
	cin >> Fname_customer;
	cout << "Enter Last Name           : ";
	cin >> Lname_customer;
	cout << "Enter UserName            : ";
	cin.ignore();
	getline(cin, userName_customer);
	cout << "Enter Email               : ";
	cin >> Email_customer;
	cout << "Enter Password            : ";
	cin.ignore();
	getline(cin, Password_customer);
	cout << "Enter Registration Date   : ";
	cin >> RegistrationDate_customer;
	cout << "Enter Address             : ";
	cin >> Address_customer;
	cout << "Enter Contact-Num         : ";
	cin >> contactNum_customer;
l2:
	cout << "Enter Blood-Group         : ";
	cin >> bloodGroup_customer;
	if (bloodGroup_customer != "A+" && bloodGroup_customer != "A-" && bloodGroup_customer != "B+"
		&& bloodGroup_customer != "B-" && bloodGroup_customer != "AB+" && bloodGroup_customer != "AB-"
		&& bloodGroup_customer != "O+" && bloodGroup_customer != "O-")
	{
		goto l2;
	}
l1:
	cout << "Enter Gender              : ";
	cin >> gender_customer;
	if (gender_customer != "M" && gender_customer != "F" && gender_customer != "m" && gender_customer != "f")
	{
		goto l1;
	}

	ofstream write("Customer.txt", ios::app);

	write << get_C_Id() << " " << Fname_customer << " " << Lname_customer << " " << userName_customer << " " << Email_customer << " "
		<< Password_customer << " " << RegistrationDate_customer << " " << Address_customer << " " << contactNum_customer << " "
		<< bloodGroup_customer << " " << gender_customer << endl;

	write.close();

	cout << "!! Data Updated in Customer file !!" << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}


void add_New_Customer::EditDataCustomer()
{
	int x;

	ifstream read("Customer.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	add_New_Customer* temp = new add_New_Customer[count2];
	count = 0;

	read.open("Customer.txt");
	while (!read.eof())
	{
		read >> temp[count].C_id >> temp[count].Fname_customer >> temp[count].Lname_customer >> temp[count].userName_customer >> temp[count].Email_customer
			>> temp[count].Password_customer >> temp[count].RegistrationDate_customer >> temp[count].Address_customer >> temp[count].contactNum_customer
			>> temp[count].bloodGroup_customer >> temp[count].gender_customer;
		count++;
	}
	read.close();
here3:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	for (int i = 0; i < count2 - 1; i++)
	{
		cout << temp[i].get_C_Id() << " " << temp[i].Fname_customer << " " << temp[i].Lname_customer << " " << temp[i].userName_customer << " " << temp[i].Email_customer << " "
			<< temp[i].Password_customer << " " << temp[i].RegistrationDate_customer << " " << temp[i].Address_customer << " " << temp[i].contactNum_customer << " "
			<< temp[i].bloodGroup_customer << " " << temp[i].gender_customer << endl;
	}
	try
	{
		cout << "\nEnter Id of Customer which you want to edit    : ";
		cin >> x;
		throw x;
	}
	catch (int)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here3;
		}
	}
	int checking = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp[i].C_id == x)
		{
			temp[i].editingdata(x);
			break;
		}
		if (temp[i].C_id != x)
		{
			checking++;
		}
	}
	if (checking == count)
	{
		cout << "!!      ID not Found         !!" << endl;
	}

	ofstream write("Customer.txt");

	for (int i = 0; i < count - 1; i++)
	{

		write << temp[i].get_C_Id() << " " << temp[i].Fname_customer << " " << temp[i].Lname_customer << " " << temp[i].userName_customer << " " << temp[i].Email_customer << " "
			<< temp[i].Password_customer << " " << temp[i].RegistrationDate_customer << " " << temp[i].Address_customer << " " << temp[i].contactNum_customer << " "
			<< temp[i].bloodGroup_customer << " " << temp[i].gender_customer << endl;
	}
	write.close();

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void add_New_Customer::DeleteDataCustomer()
{
	int x;

	ifstream read("Customer.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	add_New_Customer* temp = new add_New_Customer[count2];
	count = 0;

	read.open("Customer.txt");
	while (!read.eof())
	{
		read >> temp[count].C_id >> temp[count].Fname_customer >> temp[count].Lname_customer >> temp[count].userName_customer >> temp[count].Email_customer
			>> temp[count].Password_customer >> temp[count].RegistrationDate_customer >> temp[count].Address_customer >> temp[count].contactNum_customer
			>> temp[count].bloodGroup_customer >> temp[count].gender_customer;
		count++;
	}
	read.close();
here3:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	for (int i = 0; i < count2 - 1; i++)
	{
		cout << temp[i].get_C_Id() << " " << temp[i].Fname_customer << " " << temp[i].Lname_customer << " " << temp[i].userName_customer << " " << temp[i].Email_customer << " "
			<< temp[i].Password_customer << " " << temp[i].RegistrationDate_customer << " " << temp[i].Address_customer << " " << temp[i].contactNum_customer << " "
			<< temp[i].bloodGroup_customer << " " << temp[i].gender_customer << endl;
	}
	try
	{
		cout << "\nEnter Id of Customer which you want to delete    : ";
		cin >> x;
		throw x;
	}
	catch (int)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here3;
		}
	}
	int checking = 0, findingIndex = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp[i].C_id == x)
		{
			findingIndex = temp[i].C_id;
			break;
		}
		if (temp[i].C_id != x)
		{
			checking++;
		}
	}
	if (checking == count)
	{
		cout << "!!      ID not Found         !!" << endl;
	}

	ofstream write("Customer.txt");

	for (int i = 0; i < count - 1; i++)
	{
		if (temp[i].get_C_Id() != findingIndex)
		{
			write << temp[i].get_C_Id() << " " << temp[i].Fname_customer << " " << temp[i].Lname_customer << " " << temp[i].userName_customer << " " << temp[i].Email_customer << " "
				<< temp[i].Password_customer << " " << temp[i].RegistrationDate_customer << " " << temp[i].Address_customer << " " << temp[i].contactNum_customer << " "
				<< temp[i].bloodGroup_customer << " " << temp[i].gender_customer << endl;

		}
	}
	write.close();
	if (checking != count)
	{
		cout << "!!   RECORD SUCCESSFULLY DELETED  !!" << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void add_New_Customer::set_C_Id()
{
	ifstream read("Customer.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}
	read.close();

	add_New_Customer* temp = new add_New_Customer[count2];
	count = 0;

	read.open("Customer.txt");
	while (!read.eof())
	{
		read >> temp[count].C_id >> temp[count].Fname_customer >> temp[count].Lname_customer >> temp[count].userName_customer >> temp[count].Email_customer
			>> temp[count].Password_customer >> temp[count].RegistrationDate_customer >> temp[count].Address_customer >> temp[count].contactNum_customer
			>> temp[count].bloodGroup_customer >> temp[count].gender_customer;
		count++;
	}
	read.close();
	int size = count2 - 1;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = temp[i].C_id;
	}

	int max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	if (max <= 0)
	{
		C_id = idOfCustomer;
		idOfCustomer++;
	}
	else
	{
		for (int i = idOfCustomer; i <= max; i++) { idOfCustomer++; }
		C_id = idOfCustomer;
		idOfCustomer++;
	}
	free(arr);
}
int add_New_Customer::get_C_Id()const
{
	return C_id;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long Add_New_Product::sports = 1;
long Add_New_Product::Garments = 1;
long Add_New_Product::Eatables = 1;
long Add_New_Product::Medicines = 1;
long Add_New_Product::Fashion = 1;


Add_New_Product::Add_New_Product() :Product_category("/0"), P_id(0), Product_Quantity(0), Product_name("/0"), Discription_Product("/0")
{}

void Add_New_Product::viewProduct()
{
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	cout << "    Id-num\t\tCategory\t\tProduct\t\t\tQuantity" << endl;
	ifstream read("Product.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	Add_New_Product* temp = new Add_New_Product[count2];
	count = 0;

	read.open("Product.txt");
	while (!read.eof())
	{
		read >> temp[count].P_id >> temp[count].Product_category >> temp[count].Product_name
			>> temp[count].Product_Quantity;
		count++;
	}
	read.close();
	int c = 1;
	for (int i = 0; i < count - 1; i++, c++)
	{
		cout << c << "   " << temp[i].P_id << "\t\t" << temp[i].Product_category << "\t\t\t"
			<< temp[i].Product_name << "\t\t\t" << temp[i].Product_Quantity << endl;
	}
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
}


void Add_New_Product::set_P_Id(int n)
{
	ifstream read("Product.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	Add_New_Product* temp = new Add_New_Product[count2];
	count = 0;

	read.open("Product.txt");
	while (!read.eof())
	{
		read >> temp[count].P_id >> temp[count].Product_category >> temp[count].Product_name
			>> temp[count].Product_Quantity;
		count++;
	}
	read.close();
	int size = count2 - 1;
	int size1 = 0, size2 = 0, size3 = 0, size4 = 0, size5 = 0;
	for (int i = 0; i < size; i++)
	{
		if (temp[i].P_id >= 10000 && temp[i].P_id < 20000)
			size1++;
		if (temp[i].P_id >= 20000 && temp[i].P_id < 30000)
			size2++;
		if (temp[i].P_id >= 30000 && temp[i].P_id < 40000)
			size3++;
		if (temp[i].P_id >= 40000 && temp[i].P_id < 50000)
			size4++;
		if (temp[i].P_id >= 50000)
			size5++;
	}

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	int* arr3 = new int[size3];
	int* arr4 = new int[size4];
	int* arr5 = new int[size5];
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
	for (int i = 0; i < size; i++)
	{
		if (temp[i].P_id >= 10000 && temp[i].P_id < 20000)
		{
			arr1[x1] = temp[i].P_id;
			x1++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (temp[i].P_id >= 20000 && temp[i].P_id < 30000)
		{
			arr2[x2] = temp[i].P_id;
			x2++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (temp[i].P_id >= 30000 && temp[i].P_id < 40000)
		{
			arr3[x3] = temp[i].P_id;
			x3++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (temp[i].P_id >= 40000 && temp[i].P_id < 50000)
		{
			arr4[x4] = temp[i].P_id;
			x4++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (temp[i].P_id >= 50000)
		{
			arr5[x5] = temp[i].P_id;
			x5++;
		}
	}

	int max1 = arr1[0];
	for (int i = 1; i < size1; i++)
	{
		if (max1 < arr1[i])
		{
			max1 = arr1[i];
		}
	}

	int max2 = arr2[0];
	for (int i = 1; i < size2; i++)
	{
		if (max2 < arr2[i])
		{
			max2 = arr2[i];
		}
	}

	int max3 = arr3[0];
	for (int i = 1; i < size3; i++)
	{
		if (max3 < arr3[i])
		{
			max3 = arr3[i];
		}
	}
	int max4 = arr4[0];
	for (int i = 1; i < size4; i++)
	{
		if (max4 < arr4[i])
		{
			max4 = arr4[i];
		}
	}
	int max5 = arr5[0];
	for (int i = 1; i < size5; i++)
	{
		if (max5 < arr5[i])
		{
			max5 = arr5[i];
		}
	}

	if (n == 1)
	{
		if (max1 <= 0)
		{
			if (sports == 1) { sports += 10000; }
			P_id = sports;
			sports++;
			Product_category = "SPORTS";
		}
		else
		{
			for (int i = sports; i <= max1; i++) { sports++; }
			P_id = sports;
			sports++;
			Product_category = "SPORTS";
		}
	}
	if (n == 2)
	{
		if (max2 <= 0)
		{
			if (Garments == 1) { Garments += 20000; }
			P_id = Garments;
			Garments++;
			Product_category = "GARMENTS";
		}
		else
		{
			for (int i = Garments; i <= max2; i++) { Garments++; }
			P_id = Garments;
			Garments++;
			Product_category = "GARMENTS";
		}

	}
	if (n == 3)
	{
		if (max3 <= 0)
		{
			if (Eatables == 1) { Eatables += 30000; }
			P_id = Eatables;
			Eatables++;
			Product_category = "EATABLES";
		}
		else
		{
			for (int i = Eatables; i <= max3; i++) { Eatables++; }
			P_id = Eatables;
			Eatables++;
			Product_category = "EATABLES";
		}
	}
	if (n == 4)
	{
		if (max4 <= 0)
		{
			if (Medicines == 1) { Medicines += 40000; }
			P_id = Medicines;
			Medicines++;
			Product_category = "Medicines";
		}
		else
		{
			for (int i = Medicines; i <= max4; i++) { Medicines++; }
			P_id = Medicines;
			Medicines++;
			Product_category = "Medicines";
		}
	}
	if (n == 5)
	{
		if (max5 <= 0)
		{
			if (Fashion == 1) { Fashion += 50000; }
			P_id = Fashion;
			Fashion++;
			Product_category = "FASHION";
		}
		else
		{
			for (int i = Fashion; i <= max5; i++) { Fashion++; }
			P_id = Fashion;
			Fashion++;
			Product_category = "FASHION";
		}
	}
	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
}
long Add_New_Product::get_P_Id()const
{
	return P_id;
}
void Add_New_Product::InputDataOfProduct()
{
	int choice = 0, check = 0;
	bool flag = true;
here1:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "------------------------------------------ Product ---------------------------------------------" << endl;

	cout << "SELECT PRODUCT CATEGORIES : " << endl;
	cout << "1. Sports    " << endl;
	cout << "2. Garments  " << endl;
	cout << "3. Eatables  " << endl;
	cout << "4. Medicines " << endl;
	cout << "5. Fashion   " << endl;
	cout << "6. Menue " << endl;
	while (flag == true)
	{
		cout << "Choice : ";
		cin >> choice;
		check = choice;

		if (!cin || check < 0)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here1;
		}
		if (check == 1 || check == 2 || check == 3 || check == 4 || check == 5)
		{
			set_P_Id(choice);

			cout << "Product ID         : " << get_P_Id();
			cout << "\nProduct Category   : " << Product_category;
			cout << "\nEnter Name         : ";
			cin >> Product_name;
		L1:
			cout << "Enter its quantity : ";
			cin >> Product_Quantity;
			if (!cin || Product_Quantity < 0)
			{
				cin.clear();
				cin.ignore();
				system("CLS");
				cout << "Wrong Input  .Plz Input Again !" << endl;
				goto L1;
			}
			cout << "Enter Discription  : ";
			cin.ignore();
			getline(cin, Discription_Product);

			ofstream write("Product.txt", ios::app);

			write << get_P_Id() << " " << Product_category << " "
				<< Product_name << " " << Product_Quantity << endl;

			write.close();
			cout << "!! Data Updated in Product file !!" << endl;

			flag = false;
		}
		if (check == 6)
		{
			flag = false;
		}
		if (check != 6 && check != 1 && check != 2 && check != 3 && check != 4 && check != 5 && check != 0)
		{
			cout << "Wrong Input plz select from (1-5) !" << endl;
		}
		/*if (check == 0)                          //To Avoid infinite loop
		{
			flag = false;
			cout << "!!!        PROGRAM TERMINATED     !!!" << endl;
		}*/
	}

}

void Add_New_Product::editingproductdata(int x)
{
	int choice = 0, check = 0;
	bool flag = true;
here1:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "------------------------------------------ Product ---------------------------------------------" << endl;
	while (flag == true)
	{
		cout << "Product ID         : " << get_P_Id();
		cout << "\nProduct Category   : " << Product_category;
		cout << "\nEnter Name         : ";
		cin >> Product_name;
	L1:
		cout << "Enter its quantity : ";
		cin >> Product_Quantity;
		if (!cin || Product_Quantity < 0)
		{
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << "Wrong Input  .Plz Input Again !" << endl;
			goto L1;
		}
		cout << "Enter Discription  : ";
		cin.ignore();
		getline(cin, Discription_Product);

		ofstream write("Product.txt", ios::app);

		write << get_P_Id() << " " << Product_category << " "
			<< Product_name << " " << Product_Quantity << endl;

		write.close();
		cout << "!! Data Updated in Product file !!" << endl;

		flag = false;

	}

}



void Add_New_Product::EditDataProduct()
{
	int x;

	ifstream read("Product.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	Add_New_Product* temp = new Add_New_Product[count2];
	count = 0;

	read.open("Product.txt");
	while (!read.eof())
	{
		read >> temp[count].P_id >> temp[count].Product_category >> temp[count].Product_name
			>> temp[count].Product_Quantity;
		count++;
	}
	read.close();
here3:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	for (int i = 0; i < count2 - 1; i++)
	{
		cout << temp[i].get_P_Id() << " " << temp[i].Product_category << " "
			<< temp[i].Product_name << " " << temp[i].Product_Quantity << endl;
	}
	try
	{
		cout << "\nEnter Id of Product which you want to edit    : ";
		cin >> x;
		throw x;
	}
	catch (int)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here3;
		}
	}
	int checking = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp[i].P_id == x)
		{
			temp[i].editingproductdata(x);
			break;
		}
		if (temp[i].P_id != x)
		{
			checking++;
		}
	}
	if (checking == count)
	{
		cout << "!!      ID not Found         !!" << endl;
	}

	ofstream write("Product.txt");

	for (int i = 0; i < count2 - 1; i++)
	{
		write << temp[i].get_P_Id() << " " << temp[i].Product_category << " "
			<< temp[i].Product_name << " " << temp[i].Product_Quantity << endl;
	}
	write.close();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void Add_New_Product::DeleteDataProduct()
{
	int x;

	ifstream read("Product.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	Add_New_Product* temp = new Add_New_Product[count2];
	count = 0;

	read.open("Product.txt");
	while (!read.eof())
	{
		read >> temp[count].P_id >> temp[count].Product_category >> temp[count].Product_name
			>> temp[count].Product_Quantity;
		count++;
	}
	read.close();
here3:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < count2 - 1; i++)
	{
		cout << temp[i].get_P_Id() << " " << temp[i].Product_category << " "
			<< temp[i].Product_name << " " << temp[i].Product_Quantity << endl;
	}
	try
	{
		cout << "\nEnter Id of Product which you want to delete    : ";
		cin >> x;
		throw x;
	}
	catch (int)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here3;
		}
	}
	int checking = 0, findingIndex = 0;
	for (int i = 0; i < count; i++)
	{
		if (temp[i].P_id == x)
		{
			findingIndex = temp[i].P_id;
			break;
		}
		if (temp[i].P_id != x)
		{
			checking++;
		}
	}
	if (checking == count)
	{
		cout << "!!      ID not Found         !!" << endl;
	}

	ofstream write("Product.txt");

	for (int i = 0; i < count2 - 1; i++)
	{
		if (temp[i].get_P_Id() != findingIndex)
		{
			write << temp[i].get_P_Id() << " " << temp[i].Product_category << " "
				<< temp[i].Product_name << " " << temp[i].Product_Quantity << endl;
		}
	}
	write.close();
	if (checking != count)
	{
		cout << "!!   RECORD SUCCESSFULLY DELETED  !!" << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Administrator_Module::Administrator_Module() :userName_Admin("admin"), pass_Admin("admin")
{
	cin.ignore();
	signIn_interface();
	check();
	display_options();

}

void Administrator_Module::display_options()
{
	system("CLS");
here2:
	cout << "--------------------------------------------------------------------------------------" << endl << endl << endl << endl << endl;
	cout << "                   1 - Add New ShopKeeper                       " << endl;
	cout << "                   2 - Add New Customer                         " << endl;
	cout << "                   3 - Add New Product                         " << endl;
	cout << "                   4 - Edit ShopKeeper detail                     " << endl;
	cout << "                   5 - Edit Customer detail                     " << endl;
	cout << "                   6 - Edit Product detail                     " << endl;
	cout << "                   7 - Delete Shopkeeper                     " << endl;
	cout << "                   8 - Delete Customer                     " << endl;
	cout << "                   9 - Delete Product                     " << endl;
	cout << "                   10- Module Selecter                     " << endl;
	int choice = 0, check = 0; bool flag = true;
	while (flag == true)
	{

		cout << "           Choice : ";
		cin >> choice;
		check = choice;
		if (!cin || check < 0)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here2;
		}
		if (check == 1 || check == 2 || check == 3 || check == 4 || check == 5 || check == 6 || check == 7 || check == 8 || check == 9 || check == 10)
		{
			flag = false;
			switch (choice)
			{
			case 1:
				system("CLS");
				InputDataShop();
				_getch();
				display_options();
				break;
			case 2:
				system("CLS");
				InputDataCustomer();
				_getch();
				display_options();
				break;
			case 3:
				system("CLS");
				InputDataOfProduct();
				_getch();
				display_options();
				break;
			case 4:
				system("CLS");
				EditDataShop();
				_getch();
				display_options();
				break;
			case 5:
				system("CLS");
				EditDataCustomer();
				_getch();
				display_options();
				break;
			case 6:
				system("CLS");
				EditDataProduct();
				_getch();
				display_options();
				break;
			case 7:
				system("CLS");
				DeleteDataShop();
				_getch();
				display_options();
				break;
			case 8:
				system("CLS");
				DeleteDataCustomer();
				_getch();
				display_options();
				break;
			case 9:
				system("CLS");
				DeleteDataProduct();
				_getch();
				display_options();
				break;
			case 10:
				AfterWellcome();
				break;
			}
		}
		if (check != 0 && check != 1 && check != 2 && check != 3 && check != 4 && check != 5 && check != 6 && check != 7 && check != 8 && check != 9 && check != 10)
		{
			cout << "\n!!!        Wrong Input....        !!!\n" << endl;
		}
		/*if (check == 0)                          //To Avoid infinite loop
		{
			flag = false;
			cout << "!!!        PROGRAM TERMINATED     !!!" << endl;

		}*/

	}
	cout << endl << endl << endl << endl << "--------------------------------------------------------------------------------------" << endl;
}

void Administrator_Module::check()
{
	bool flag = true;
	while (flag == true)
	{
		if (userName == userName_Admin && password == pass_Admin)
		{
			system("CLS");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "                         ~~~~~~WELL-COME~~~~~~~                           " << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			_getch();
			system("CLS");
			flag = false;
		}
		if (userName != userName_Admin || password != pass_Admin)
		{
			system("CLS");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "                         ~~~~~~WRRONG PASSWORD OR NAME~~~~~~~                           " << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			//_getch();
			cin.ignore();
			system("CLS");

			signIn_interface();
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Shopkeeper_Module::Shopkeeper_Module() :userName_shop("shopkeeper"), pass_Shop("shopkeeper")
{
	cin.ignore();
	signIn_interface();
	check();
	display_options_shop();
}

void Shopkeeper_Module::display_options_shop()
{
	system("CLS");
here2:
	cout << "--------------------------------------------------------------------------------------" << endl << endl << endl << endl << endl;
	cout << "                   1 - Register to system                     " << endl;
	cout << "                   2 - Add a product                          " << endl;
	cout << "                   3 - Edit a product                         " << endl;
	cout << "                   4 - View products                          " << endl;
	cout << "                   5 - Module Selecter                        " << endl;
	int choice = 0, check = 0; bool flag = true;
	while (flag == true)
	{

		cout << "           Choice : ";
		cin >> choice;
		check = choice;
		if (!cin || check < 0)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here2;
		}
		if (check == 1 || check == 2 || check == 3 || check == 4 || check == 5)
		{
			flag = false;
			switch (choice)
			{
			case 1:
				system("CLS");
				InputDataShop();
				_getch();
				display_options_shop();
				break;
			case 2:
				system("CLS");
				InputDataOfProduct();
				_getch();
				display_options_shop();
				break;
			case 3:
				system("CLS");
				EditDataProduct();
				_getch();
				display_options_shop();
				break;
			case 4:
				system("CLS");
				viewProduct();
				_getch();
				display_options_shop();
				break;
			case 5:
				AfterWellcome();
				break;
			}
		}
		if (check != 0 && check != 1 && check != 2 && check != 3 && check != 4 && check != 5)
		{
			cout << "\n!!!        Wrong Input....        !!!\n" << endl;
		}



		/*if (check == 0)                          //To Avoid infinite loop
		{
			flag = false;
			cout << "!!!        PROGRAM TERMINATED     !!!" << endl;

		}*/

	}
}

void Shopkeeper_Module::check()
{
	ifstream read("Shopkeeper.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	add_New_Shop_keeper* temp = new add_New_Shop_keeper[count2];
	count = 0;
	string* usernamearray = new string[count2];
	string* passwordarray = new string[count2];

	read.open("Shopkeeper.txt");
	while (!read.eof())
	{
		read >> temp[count].S_id >> temp[count].Fname_shop >> temp[count].Lname_shop >> temp[count].userName_shop >> temp[count].Email_shop
			>> temp[count].Password_shop >> temp[count].RegistrationDate_shop >> temp[count].Address_shop >> temp[count].contactNum_shop
			>> temp[count].bloodGroup_shop >> temp[count].gender_shop;
		usernamearray[count] = temp[count].userName_shop;
		passwordarray[count] = temp[count].Password_shop;
		count++;
	}
	read.close();

	bool flag = true, flag2 = true;
	while (flag == true)
	{
		if (flag2 == true)
		{
			for (int i = 0; i < count2 - 1; i++)
			{
				flag2 = false;
				if ((userName == userName_shop || userName == usernamearray[i]) && (password == pass_Shop || password == passwordarray[i]))
				{
					system("CLS");
					cout << endl << endl << endl << endl << endl << endl;
					cout << "--------------------------------------------------------------------------" << endl;
					cout << "                         ~~~~~~WELL-COME~~~~~~~                           " << endl;
					cout << "--------------------------------------------------------------------------" << endl;
					_getch();
					system("CLS");
					i = count2 + 1;
					flag = false;
					flag2 = true;
				}
			}
		}
		if (flag2 == false)
		{
			system("CLS");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "                         ~~~~~~WRRONG PASSWORD OR NAME~~~~~~~                           " << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			//_getch();
			cin.ignore();
			system("CLS");
			signIn_interface();
			flag2 = true;
		}

	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Customer_Module::Customer_Module() :userName_customer("customer"), pass_customer("customer")
{
	Display_signin_up_option();
	//Display_options_cus();
}
void Customer_Module::Display_signin_up_option()
{
	system("CLS");
here2:
	cout << "--------------------------------------------------------------------------------------" << endl << endl << endl << endl << endl;
	cout << "                   1 - Register to system                     " << endl;
	cout << "                   2 - Sign-In                                " << endl;
	cout << "                   3 - Module Selecter                        " << endl;
	int choice = 0, check2 = 0; bool flag = true;
	while (flag == true)
	{

		cout << "           Choice : ";
		cin >> choice;
		check2 = choice;
		if (!cin || check2 < 0)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here2;
		}
		if (check2 == 1 || check2 == 2 || check2 == 3)
		{
			flag = false;
			switch (choice)
			{
			case 1:
				system("CLS");
				InputDataCustomer();
				_getch();
				Display_options_cus();
				break;
			case 2:
				system("CLS");
				cin.ignore();
				signIn_interface();
				check();
				Display_options_cus();
				break;
			case 3:
				AfterWellcome();
				break;
			}
		}
		if (check2 != 1 && check2 != 2 && check2 != 3)
		{
			cout << "\n!!!        Wrong Input....        !!!\n" << endl;
		}
		/*if (check == 0)                          //To Avoid infinite loop
		{
			flag = false;
			cout << "!!!        PROGRAM TERMINATED     !!!" << endl;

		}*/

	}
}

void Customer_Module::purchase_Product()
{
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	cout << "    Id-num\t\tCategory\t\tProduct\t\t\tQuantity" << endl;
	ifstream read("Product.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	Add_New_Product* temp = new Add_New_Product[count2];
	count = 0;

	read.open("Product.txt");
	while (!read.eof())
	{
		read >> temp[count].P_id >> temp[count].Product_category >> temp[count].Product_name
			>> temp[count].Product_Quantity;
		count++;
	}
	read.close();
	int c = 1;
	for (int i = 0; i < count - 1; i++, c++)
	{
		cout << c << "   " << temp[i].P_id << "\t\t" << temp[i].Product_category << "\t\t\t"
			<< temp[i].Product_name << "\t\t\t" << temp[i].Product_Quantity << endl;
	}

	c = c - 1;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	int p;
	int quantity = 0;
	char s;
	bool flag = true;
here3:
	while (flag == true)
	{
		try
		{
			cout << "Select number of product you want to purchase  : ";
			cin >> p;
			throw p;
		}
		catch (int)
		{
			if (!cin)
			{
				cin.clear();
				cin.ignore();
				system("cls");
				goto here3;
			}
		}
	here4:
		if (p <= c)
		{
			try
			{
				cout << "Enter Quantity : ";
				cin >> quantity;
				throw quantity;
			}
			catch (int)
			{
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					system("cls");
					goto here4;
				}
			}

			ofstream write("addToCart.txt", ios::app);
			write << temp[p - 1].get_P_Id() << " " << temp[p - 1].Product_category << " "
				<< temp[p - 1].Product_name << " " << quantity << endl;
			write.close();
			cout << "\nSelected Product added to cart\n " << endl;
		}
		if (p > c || p < 0)
		{
			cout << "\n!!    No Product Exit In this item no.    !!\n" << endl;
		}

		if (temp[p - 1].Product_Quantity - quantity <= 0)
		{
			temp[p - 1].Product_Quantity += 3;
		}
		if (temp[p - 1].Product_Quantity - quantity > 0)
		{
			temp[p - 1].Product_Quantity -= quantity;
		}

		cout << "Want to order more  (y/N) : ";
		cin >> s;
		cout << endl;
		if (s == 'Y' || s == 'y')
		{
			continue;
		}
		if (s == 'N' || s == 'n')
		{
			flag = false;
		}
		if (s != 'Y' && s != 'y' && s != 'N' && s != 'n')
		{
			cout << "!!   Wrong Input   !!" << endl;
			cout << "!!   Default YES   !! " << endl;
		}
	}
	ofstream write("Product.txt");

	for (int i = 0; i < count - 1; i++)
	{

		write << temp[i].get_P_Id() << " " << temp[i].Product_category << " "
			<< temp[i].Product_name << " " << temp[i].Product_Quantity << endl;
	}
	write.close();


	int cou2 = 0;
	read.open("Product.txt");
	while (!read.eof())
	{
		read >> temp[cou2].P_id >> temp[cou2].Product_category >> temp[cou2].Product_name
			>> temp[cou2].Product_Quantity;
		cou2++;
	}
	read.close();

	cout << "\n!!     Inventory Updated      !!\n" << endl;

	c = 1;
	for (int i = 0; i < count - 1; i++, c++)
	{
		cout << c << "   " << temp[i].P_id << "\t\t" << temp[i].Product_category << "\t\t\t"
			<< temp[i].Product_name << "\t\t\t" << temp[i].Product_Quantity << endl;
	}


	cout << "\nThanks For purchasing \n" << endl;

}
//void Customer_Module::Add_to_cart()
//{
//	cout << "!!        Nothing Here        !!" << endl;
//}
void Customer_Module::Check_out()
{

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIST OF PRODUCTS IN CART~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	cout << "    Id-num\t\tCategory\t\tProduct\t\t\tQuantity\t\tAmount" << endl;
	ifstream read("addToCart.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	Add_New_Product* temp = new Add_New_Product[count2];
	count = 0;

	read.open("addToCart.txt");
	while (!read.eof())
	{
		read >> temp[count].P_id >> temp[count].Product_category >> temp[count].Product_name
			>> temp[count].Product_Quantity;
		count++;
	}
	read.close();
	int c = 1,
		countTotalQuantity = 0;

	int amountGiver[10] = { 200,300,250,150,520,210,100,600,550,330 };
	int calulateamount[10];
	for (int i = 0; i < count - 1; i++, c++)
	{
		cout << c << "   " << temp[i].P_id << "\t\t" << temp[i].Product_category << "\t\t\t"
			<< temp[i].Product_name << "\t\t\t" << temp[i].Product_Quantity << "\t\t\t" << amountGiver[i] << endl;
		calulateamount[i] = amountGiver[i] * temp[i].Product_Quantity;
		//countTotalQuantity += temp[i].Product_Quantity;
	}

	int amount = 0;
	for (int i = 0; i < count - 1; i++, c++)
	{
		amount += calulateamount[i];
	}
	//amount *= countTotalQuantity;
	int payment;
	bool flag = true;
	cout << "\nAMOUNT OF PRODUCTS SELECTED         : " << amount << endl;
	if (amount == 0)
	{
		cout << "AFTER ADDING (200)Delevery CHARGES  : " << amount << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CART IS EMPTY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	else if (amount > 0)
	{
		amount += 200;
		cout << "AFTER ADDING (200)Delevery CHARGES  : " << amount << endl;

		while (flag == true)
		{
			cout << "\nEnter payment    : " << endl;
			cin >> payment;
			if (payment >= amount)
			{
				flag = false;
				cout << "Return Amount      : " << payment - amount << endl;
				ofstream write("addToCart.txt");
				write;
				write.close();

			}
			if (payment < 0 || payment < amount)
			{
				cout << "\n!!    InValid Input    !!" << endl;
			}
		}

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~THANKS FOR SHOPPING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
}

void Customer_Module::Display_options_cus()
{
	system("CLS");
here2:
	cout << "--------------------------------------------------------------------------------------" << endl << endl << endl << endl << endl;
	cout << "                   1 - Purchase a product                     " << endl;
	cout << "                   2 - Check out                              " << endl;
	cout << "                   3 - Module Selecter                        " << endl;
	int choice = 0, check = 0; bool flag = true;
	while (flag == true)
	{

		cout << "           Choice : ";
		cin >> choice;
		check = choice;
		if (!cin || check < 0)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here2;
		}
		if (check == 1 || check == 2 || check == 3)
		{
			flag = false;
			switch (choice)
			{
			case 1:
				system("CLS");
				purchase_Product();
				_getch();
				Display_options_cus();
				break;
			case 2:
				system("CLS");
				Check_out();
				_getch();
				Display_options_cus();
				break;
			case 3:
				AfterWellcome();
				break;
			}
		}
		if (check != 1 && check != 2 && check != 3)
		{
			cout << "\n!!!        Wrong Input....        !!!\n" << endl;
		}
		/*if (check == 0)                          //To Avoid infinite loop
		{
			flag = false;
			cout << "!!!        PROGRAM TERMINATED     !!!" << endl;

		}*/

	}

}

void Customer_Module::check()
{
	ifstream read("Customer.txt");

	//counting the number of shopkeepers stored in file
	string t; int count = 0, count2 = 0;
	while (!read.eof())
	{
		getline(read, t);
		count2++;
	}

	read.close();
	if (count2 == 0)
	{
		cout << "File Is Empty.\n";
		system("pause");
		return;
	}

	//storing data in array
	add_New_Customer* temp = new add_New_Customer[count2];
	count = 0;

	string* usernamearray = new string[count2];
	string* passwordarray = new string[count2];

	read.open("Customer.txt");
	while (!read.eof())
	{
		read >> temp[count].C_id >> temp[count].Fname_customer >> temp[count].Lname_customer >> temp[count].userName_customer >> temp[count].Email_customer
			>> temp[count].Password_customer >> temp[count].RegistrationDate_customer >> temp[count].Address_customer >> temp[count].contactNum_customer
			>> temp[count].bloodGroup_customer >> temp[count].gender_customer;
		usernamearray[count] = temp[count].userName_customer;
		passwordarray[count] = temp[count].Password_customer;
		count++;
	}
	read.close();

	bool flag = true, flag2 = true;
	while (flag == true)
	{
		if (flag2 == true)
		{
			for (int i = 0; i < count2 - 1; i++)
			{
				flag2 = false;
				if ((userName == userName_customer || userName == usernamearray[i]) && (password == pass_customer || password == passwordarray[i]))
				{
					system("CLS");
					cout << endl << endl << endl << endl << endl << endl;
					cout << "--------------------------------------------------------------------------" << endl;
					cout << "                         ~~~~~~WELL-COME~~~~~~~                           " << endl;
					cout << "--------------------------------------------------------------------------" << endl;
					_getch();
					system("CLS");
					i = count2 + 1;
					flag = false;
					flag2 = true;
				}
			}
		}
		if (flag2 == false)
		{
			system("CLS");
			cout << endl << endl << endl << endl << endl << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "                         ~~~~~~WRRONG PASSWORD OR NAME~~~~~~~                           " << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			//_getch();
			cin.ignore();
			system("CLS");
			signIn_interface();
			flag2 = true;
		}

	}
}

void Wellcome()
{
	cout << "\n\n\n\n\n---------------------------------------------------------------------------------------------------------------------" << endl << endl << endl << endl << endl << endl;
	cout << "                     _______                               ________      _________      ________________      _______" << endl;
	cout << "||            ||   ||          ||           ||           ||            ||         ||   ||      ||      ||   ||       " << endl;
	cout << "||   ______   ||   ||          ||           ||           ||            ||         ||   ||      ||      ||   ||       " << endl;
	cout << "||  ||    ||  ||   ||_______   ||           ||           ||            ||         ||   ||      ||      ||   ||_______" << endl;
	cout << "||  ||    ||  ||   ||          ||           ||           ||            ||         ||   ||      ||      ||   ||       " << endl;
	cout << "||  ||    ||  ||   ||          ||           ||           ||            ||         ||   ||      ||      ||   ||       " << endl;
	cout << "||__||    ||__||   ||_______   ||________   ||________   ||________    ||_________||   ||      ||      ||   ||_______" << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	_getch();
	system("CLS");
}
int Module__Selecter()
{
	system("CLS");
	int choice = 0, check = 0; bool flag = true;
here3:
	cout << "----------------------------------------------------------------------------------------------------------" << endl << endl << endl << endl;
	cout << "------------------------------SELECT THE MODULE FROM THE GIVEN OPTIONS------------------------------------" << endl;
	cout << "           0. TO TARMINATE & Restart        " << endl;
	cout << "           1. ADMINISTRATOR        " << endl;
	cout << "           2. SHOP-KEEPER          " << endl;
	cout << "           3. CUSTOMER             " << endl;
	cout << "           4. Quit                 " << endl;


	while (flag == true)
	{

		cout << "           Choice : ";
		cin >> choice;
		if (!cin || check < 0)
		{
			cin.clear();
			cin.ignore();
			system("cls");
			goto here3;
		}
		check = choice;
		if (check == 1 || check == 2 || check == 3 || check == 0 || check == 4)
		{
			flag = false;
			return choice;
		}
		if (check != 1 && check != 2 && check != 3 && check != 0 && check != 4)
		{
			cout << "\n!!!        Wrong Input....        !!!\n" << endl;

		}
		/*if (check == 0)                          //To Avoid infinite loop
		{
			flag = false;
			cout << "!!!        PROGRAM TERMINATED     !!!" << endl;
			return 0;
		}*/

	}
}

void AfterWellcome()
{
	int option;
	option = Module__Selecter();

	if (option == 0)
	{
		AfterWellcome();
	}

	if (option == 1)                              // Administrator module
	{
		Administrator_Module A1;
	}

	if (option == 2)                              // Shop-keeper module
	{
		Shopkeeper_Module S1;
	}

	if (option == 3)                              // Costomer module
	{
		Customer_Module C1;
	}

	if (option == 4)
	{
		system("CLS");
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~THANKS FOR COMING~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
}



