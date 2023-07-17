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
