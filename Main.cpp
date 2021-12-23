#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Avl.h"
#include"PriortyQueue.h"
using namespace std;
Priority_Queue PQ;
avlTree AVL;
avl_node* Root;
class Admin_Section
{
public:
	
	bool Admin_Login()
	{
		string ID, fName, lName, password, Password, id, FName, LName;
		cout << "Enter ID Card Number and password " << endl;
		cout << "Enter Name:> ";
		cin >> fName;
		cin >> lName;
		ID = fName + " " + lName;
		cout << "password:> ";
		cin >> Password;
		cout << "Checking info" << endl;
		fstream file;
		file.open("AdminLogin.txt", ios::beg || ios::in);
		if (file.fail())
		{
			cout << "file Is Not Open " << endl;
		}
		while (!file.eof())
		{
			file >> FName;
			file >> LName;
			id = FName + " " + LName;
			file >> password;
			if (Password == password && id == ID)
			{
				return true;
			}
		}
		if (file.eof())
		{
			cout << "User With This Id does Not Exist" << endl;
			return false;
		}
	}

	void start()
	{
		if (Admin_Login())
		{
			system("CLS");
			system("color 60");
			ADmenu();
			
		}
	}
	void ADmenu()
	{
		int choice;
		string CNIC;
			
			while (1)
			{
				cout << "wellcome To Admin's Menu " << endl;
				cout << "Press 1 to Take Data from User" << endl;
				cout << "Press 2 To Give Priorty to any Claint in Queue " << endl;
				cout << "Enter 3 to Know Number of claints " << endl;
				cout << "press 4 to for Rapid password production" << endl;
				cout << "press 5 to see Data of All Claints " << endl;
				cout << "Press 6 to see list of Claints " << endl;
                cout << "Press 7 to go Back" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					Get_Info();
					break;
				case 2:
					cout << "Enter The CNIC of Cliant to Whome you want to give priorty " << endl;
					cin >> CNIC;
					Givepriorty(CNIC);
					break;
				case 3:
					cout << PQ.count() << endl;;
					break;
				case 4:
					cout << "Enter Your CNIC " << endl;
					cin >> CNIC;
					AVL.Changestatus(Root,CNIC);
					break;
				case 5:
					AVL.inorder(Root);
					break;
				case 6:
					PQ.display();
					break;
				case 7:
					return;
				default:
					cout << "Enter Right choice " << endl;
					break;
			}
			
			}
		
	}

	void Givepriorty(string CNIC)
	{ 
		string D;
		D=PQ.DeleteNode(CNIC);
		cout << "your  NEW Password is " << "99889" << endl;
		int y;
		y=PQ.gettop()->priority - 1;
		PQ.insert(D,y,99889);
		return;
	}

	void Get_Info()
	{
		system("CLS");
		system("color 80");
		if (PQ.IsEmpty())
		{
			cout << "Creat Queue First " << endl;
			return;
		}
		string *Getdata;
		Getdata = new string[9];
		int Date_of_Submission[3];
		char Gender;
		
		int type;
		int Password;
		ofstream file;
		file.open("Userdata.txt", ios::app);
		if (file.fail())
		{
			cout << "File Not Found " << endl;
			return;
		}
		while (PQ.IsEmpty() != 1)
		{
			Getdata[2] = PQ.gettop()->info;
			Password = PQ.gettop()->password;
			cout << "Insert Data for CNIC: " << PQ.gettop()->info << endl;
			cout << "Enter First Name:> ";
			cin >> Getdata[0];
			cout << "Enter Last Name:> ";
			cin >> Getdata[1];
			cout << "Enter Date of Birth:> ";
			cin >> Getdata[3];
			cout << "Enter Phone Number:> ";
			cin >> Getdata[4];
			cout << "Enter Address:> ";
			cin >> Getdata[5];
			cout << "Enter City:> ";
			cin >> Getdata[6];
			cout << "Enter Nationality:> ";
			cin >> Getdata[7];
			cout << "Enter Sex (Press 'M' or 'F'):> ";
			cin >> Gender;
			cout << "Enter Date of Submission:> ";
			cout << "DAY    :> ";
			cin >> Date_of_Submission[0];
			if (Date_of_Submission[0]<0 || Date_of_Submission[0]>31)
			{
				cout << "Wrong Entery " << endl;
				return;
			}
			cout << "Month  :> ";
			cin >> Date_of_Submission[1];
			if (Date_of_Submission[1]<0 || Date_of_Submission[0]>12)
			{
				cout << "Wrong Entery " << endl;
				return;
			}
			cout << "Year   :> ";
			cin >> Date_of_Submission[2];
			Getdata[8] = "P";
			cout << "IF you want passport Urgently press 4 Not Press 5" << endl;
			cin >> type;
			if (type == 4)
			{
				cout << "you will get your password After 10 Days" << endl;
			}
			else if (type==5)
			{
				cout << "you will get your password After 20 Days " << endl;
			}
			file << Getdata[0] << " " << Getdata[1] << " " << Getdata[2] << " " << Getdata[3] << " " << Date_of_Submission[0] << " " << Date_of_Submission[1] << " " << Date_of_Submission[2]<<" " << Getdata[4] << " " << Getdata[5] << " " << Getdata[6] << " " << Getdata[7] << " " << Gender << " " << type << " " << Password <<" "<<Getdata[8]<< endl;
			Root = AVL.insert(Root, Date_of_Submission,Getdata, Gender, type, Password);
			PQ.del();
		}
	}
};
class User_Section
{
public:
	void Registration()
	{
		string ID;
		system("color 90");
		long int password;
		int type;
		cout << "Enter CNIC Number :> ";
		cin >> ID;
		if (getdata_from_user_login(ID))
		{
			cout << "User With This CNIC Number Already Exist" << endl;
			return;
		}
		cout << "If You Are  Handicap Press 1 If Your Not Handicap press 2  " << endl;
		cin >> type;
		password = rand();
		PQ.insert(ID, type, password);
		cout << "Your Password is " << password << endl;
		ofstream file;
		file.open("UserLogin.txt", ios::app);
		file << ID << " " << type << " " << password << endl;
		file.close();
	}
	bool Login()
	{
		string Idcard, getId, password, get; int p;
		cout << "Enter ID Card Number and password " << endl;
		cout << "ID card Number:> ";
		cin >> getId;
		cout << "password:> ";
		cin >> get;
		cout << "Checking info" << endl;
		fstream file;
		file.open("UserLogin.txt", ios::beg || ios::in);
		if (file.fail())
		{
			cout << "file Is Not Open " << endl;
		}
		while (!file.eof())
		{
			file >> Idcard;
			file >> p;
			file >> password;
			if (get == password&&getId == Idcard)
			{
				return true;
			}
		}
		if (file.eof())
		{
			cout << "User With This Id does Not Exist" << endl;
			return false;
		}
	}
	void start()
	{
		int choice, S;
		system("CLS");
		cout << "wellcome To User's Menu " << endl;
		cout << "Press 1 For Registration " << endl;
		cout << "Press 2 for Login " << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "How Many Customer you want to Register they should not Be Greater then 20 " << endl;
			cin >> S;
			if (S < 0&&S>20)
			{
				cout << "Enter Valid Information " << endl;
				return;
			}
			for (int E = 0; E < S; E++)
			{
				Registration();
			}
		}
		else if (choice==2)
		{
			if (Login())
			{
				menu();
			}
				
		}
		else
		{
			cout << "Wrong choice " << endl;
			return;
		}
	}
	void menu()
	{
		string CNIC;
		int choice;
		while (1)
		{
			cout << "Press 1 for Looking Your Status" << endl;
			cout << "Enter 2 To See The  Information You have Provided " << endl;
			cout << "Press 3 to go Back" << endl;
			cin >> choice;
			switch(choice)
			{
			
			case 1:
				UserStatus();
				break;
			case 2:
				cout << "Enter your CNIC Number " << endl;
				cin >> CNIC;
				AVL.Seeinformation(Root, CNIC);
				break;
			case 3:
				return;
			default:
				cout << "Enter Right choice " << endl;
				break;
			}

		}
	}

	void UserStatus()
	{
		string CNIC; int Date[3];
		cout << "Enter your CNIC NUMBER " << endl;
		cin >> CNIC;
		cout << "ENTER Current Date" << endl;
		cout << "Day   :>";
		cin >> Date[0];
		if (Date[0]<0 || Date[0]>31)
		{
			cout << "Wrong Entery " << endl;
			return;
		}
		cout << "Month :>";
		cin>> Date[1];
		if (Date[1]<0 || Date[1]>12)
		{
			cout << "Wrong Entery " << endl;
			return;
		}
		cout << "Year  :>";
		cin >> Date[2];
		AVL.Userinformation(Root, CNIC, Date);


	}
	bool getdata_from_user_login(string CNIC)
	{
		ifstream file;
		string id;
		int type, pass;
		file.open("UserLogin.txt", ios::in || ios::beg);
		if (file.fail())
		{
			cout << "File Not Found " << endl;
			return true;
		}
		while (!file.eof())
		{
			file >> id;
			file >> type;
			file >> pass;
			if (id == CNIC)
			{
				file.close();
				return true;
			}
		}
		file.close();
		return false;
	}
};

void Refill_File()
{
	
	AVL.Refile(Root);
}

void main()
{

	Admin_Section AS;
	User_Section US;
	int choice;
	while (1)
	{
		cout << "Wellcome To Passport Office" << endl;
		cout << "Press 1 to access Admin Section" << endl;
		cout << "Press 2 to access User Section" << endl;
		cout << "Press 3 to exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			AS.start();
			break;
		case 2:
			US.start();
			break;
		case 3:
			Refill_File();
			exit(1);
		default:
			cout << "Enter Right choice " << endl;
			break;
		}
	}
	system("pause");
}
