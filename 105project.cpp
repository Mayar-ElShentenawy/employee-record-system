//EMPLOYEE RECORD SYSTEM.

// Group 2.

// Rougina Michelle : 2019/ 02401.
// Mayar Khaled		: 2019/ 08067.
// Beshoy Samir		: 2019/ 02364.

// Time | From: 1:00 PM | To: 1:30 Pm

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class EMPLOYEE
{
	int idnum;
	char name[50];
	char position[50];
	char dep[50];
	int  salary, exp;
	int age;

public:
	void getdata();
	void showdata() const;
	int getIDNum() const;
};

void EMPLOYEE::getdata()
{
	cout << "Enter The ID number of the Employee : ";
	cin >> idnum;

	cout << "Enter employee's Name		    : ";
	cin.ignore();
	cin.getline(name, 50);

	cout << "Enter employee's Age		    : ";
	cin >> age;

	cout << "Enter employee's position	    : ";
	cin.ignore();
	cin.getline(position, 50);

	cout << "Enter employee's Department         : ";
	cin.ignore();
	cin.getline(dep, 50);

	cout << "Enter employee's salary             : ";
	cin >> salary;

	cout << "Enter employee's Experience         : ";
	cin >> exp;
}

void EMPLOYEE::showdata() const
{
	cout << "ID Number  : " << idnum << endl;
	cout << "Name	   : " << name << endl;
	cout << "Age	   : " << age << endl;
	cout << "Department : " << dep << endl;
	cout << "position   : " << position << endl;
	cout << "Salary     : " << salary << endl;
	cout << "Experience : " << exp << endl;
	cout << endl;
}

int  EMPLOYEE::getIDNum() const
{
	return idnum;
}

void write_EMPLOYEE();
void display_all();
void search_emp(int);
void modify_EMPLOYEE(int);
void delete_EMPLOYEE(int);

void write_EMPLOYEE()
{
	EMPLOYEE st;
	ofstream outFile;
	outFile.open("Employee.txt", ios::binary | ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char*> (&st), sizeof(EMPLOYEE));
	outFile.close();
	cout << "Employee record Has Been Created " << endl << endl;
	cout << "Press any key...to continue " << endl << endl;
	cin.ignore();
	cin.get();
}

void display_all()
{
	EMPLOYEE st;
	ifstream inFile;
	inFile.open("Employee.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout << endl << endl << endl << "	RECORDS LIST : " << endl << endl;
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(EMPLOYEE)))
	{
		st.showdata();
		cout << endl << endl << "====================================" << endl;
	}
	inFile.close();
	cout << "Press any key...to continue" << endl << endl;
	cin.ignore();
	cin.get();
}

void search_emp(int n)
{
	EMPLOYEE st;
	ifstream inFile;
	inFile.open("Employee.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag = false;
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(EMPLOYEE)))
	{
		if (st.getIDNum() == n)
		{
			st.showdata();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "Record not exist" << endl << endl;
	cout << "Press any key...to continue" << endl;
	cin.ignore();
	cin.get();
}

void modify_EMPLOYEE(int n)
{
	bool found = false;
	EMPLOYEE st;
	fstream File;
	File.open("Employee.txt", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&st), sizeof(EMPLOYEE));
		if (st.getIDNum() == n)
		{
			st.showdata();
			cout << "Please Enter The New Details of employee: " << endl << endl;
			st.getdata();
			int pos = (-1) * static_cast<int>(sizeof(st));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&st), sizeof(EMPLOYEE));
			cout << endl << endl << "	 Record Updated ";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << " Record Not Found " << endl << endl;
	cout << "Press any key...to continue" << endl;
	cin.ignore();
	cin.get();
}

void delete_EMPLOYEE(int n)
{
	EMPLOYEE st;
	ifstream inFile;
	inFile.open("Employee.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.txt", ios::out);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(EMPLOYEE)))
	{
		if (st.getIDNum() != n)
		{
			outFile.write(reinterpret_cast<char*> (&st), sizeof(EMPLOYEE));
		}
	}
	outFile.close();
	inFile.close();
	remove("Employee.txt");
	rename("Temp.txt", "Employee.txt");
	cout << "	Record Deleted .. " << endl << endl;
	cout << "Press any key...to continue " << endl << endl;
	cin.ignore();
	cin.get();
}

int main()
{
	char ch;
	int ID;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2);
	do
	{
		system("cls");

		cout << "	############################################### ";
		cout << endl << "	----------------------------------------------- " << endl << endl;

		cout << "	           EMPLOYEE RECORD SYSTEM			    " << endl;
		cout << "	----------------------------------------------- " << endl << endl;
		cout << "	############################################### " << endl << endl;
		cout << "	1. ADD A NEW RECORD " << endl << endl;
		cout << "	2. DISPLAY ALL RECORDS " << endl << endl;
		cout << "	3. SEARCH A RECORD " << endl << endl;
		cout << "	4. MODIFY A RECORD " << endl << endl;
		cout << "	5. DELETE A RECORD " << endl << endl;
		cout << "	6. EXIT " << endl << endl;
		cout << "	############################################### " << endl << endl;
		cout << "	Please Enter Your Choice (1-6): " << endl;
		cin >> ch;
		system("cls");
		switch (ch)
		{

		case '1':	write_EMPLOYEE();
			break;

		case '2':	display_all();
			break;

		case '3':
			cout << endl << endl << "	Please Enter EMPLOYEE ID number: " << endl;
			cin >> ID;
			cout << endl;
			search_emp(ID);
			break;

		case '4':
			cout << endl << endl << "	Please Enter EMPLOYEE ID number: " << endl;
			cin >> ID;
			cout << endl;
			modify_EMPLOYEE(ID);
			break;

		case '5':
			cout << endl << endl << "	Please Enter EMPLOYEE ID number: " << endl;
			cin >> ID;
			cout << endl;
			delete_EMPLOYEE(ID);
			break;

		case '6':
			exit(0);

		default:
			cout << "\a";
		}

		cout << "press enter to get to main menu" << endl;

	} while (ch != '6');

	return 0;
}
