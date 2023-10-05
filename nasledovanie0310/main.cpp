#include <iostream>
using namespace std;

class Person
{
protected:
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		cout << "Person construct\n";
	}
	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
	void Input()
	{
		char buff[20];
		cout << "Input name: ";
		cin.getline(buff, 20);
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Input age: ";
		cin >> age;
	}
	~Person()
	{
		delete[] name;
		cout << "Destruct person\n";
	}
};

class Student :public Person
{
	char* Universe;
public:
	Student() = default;
	Student(const char* n, int a, const char* Univer) : Person(n, a)
	{
		Universe = new char[strlen(Univer) + 1];
		strcpy_s(Universe, strlen(Univer) + 1, Univer);
		cout << "Student construct\n";
	}
	void Print()
	{
		Person::Print();
		cout << "University: " << Universe << endl;

	}
	~Student()
	{
		delete[] Universe;
		cout << "Destruct Student\n";
	}

	void Input(const char* Univer)
	{
		if (Universe != nullptr)
		{
			delete[] Universe;
		}

		Universe = new char[strlen(Univer) + 1];
		strcpy_s(Universe, strlen(Univer) + 1, Univer);
		Person::Input();
	}
};

class Teacher :public Person
{
	string school;
	float salary;
	string* subject;
	int size;
public:
	Teacher() = default;
	Teacher(const char* n, int a, string sc, float sal, int s, string* sb) : Person(n, a)
	{
		school = sc;
		salary = sal;
		size = s;
		subject = new string[s];
		for (int i = 0; i < s; i++)
		{
			subject[i] = sb[i];;
		}
	}

	void Print()
	{
		Person::Print();
		cout << "school: " << school << endl;
		cout << "salary: " << salary << endl;
		cout << "classes: ";
		for (int i = 0; i < size; i++) {
			cout << subject[i];
			if (i < size - 1) {
				cout << ", ";
			}
		}

	}
	~Teacher()
	{
		delete[] subject;
		cout << "Destruct Teacher\n";
	}

	void Input()
	{
		Person::Input();
		cout << "Input a school: ";
		cin >> school;
		cout << "Input a salary: ";
		cin >> salary;
		cout << "Input quantity of classes: ";
		cin >> size;
		subject = new string[size];
		for (int i = 0; i < size; i++) {
			cout << "Input a subject: ";
			cin >> subject[i];
		}
	}
};

class Driver :public Person
{
	int serialNumb;
	int numberCar;
	string document;
public:
	Driver() = default;

	Driver(const char* n, int a, int nc, int sn, string d) : Person(n, a) {
		numberCar = nc;
		serialNumb = sn;
		document = d;
	}
	void Print()
	{
		Person::Print();
		cout << "Number car: " << numberCar << endl;
		cout << "Serial number car: " << serialNumb << endl;
		cout << "Document car: " << document << endl;

	}

	void Input()
	{
		Person::Input();
		cout << "Input a number car: ";
		cin >> numberCar;
		cout << "Input a serial number car: ";
		cin >> serialNumb;
		cout << "Input a document car: ";
		cin >> document;
	}
};

class Doctor : public Person
{
	string speciality;
	float expirience;
	bool doctorHome;
public:
	Doctor() = default;
	Doctor(const char* n, int a, string scpec, float exp, bool dHome) : Person(n, a) {
		speciality = scpec;
		expirience = exp;
		doctorHome = dHome;
	}

	void Input()
	{

		char buff[20];
		Person::Input();
		cout << "Input a speciality: ";
		cin >> speciality;
		cout << "Input a work experience: ";
		cin >> expirience;
		while (true)
		{
			cout << "Are you a family doctor?(Y/N): ";
			cin >> buff;

			if (buff == "Y" || buff == "y")
			{
				doctorHome = true;
				break;
			}
			else if (buff == "N" || buff == "n")
			{
				doctorHome = false;
				break;
			}
			else
			{
				cout << "Wrong input!\nInput only 'Y' or 'N' " << endl;
			}
		}

	}

	void Print()
	{
		Person::Print();
		cout << "Speciality: " << speciality << endl;
		cout << "Work experience: " << expirience << endl;
		cout << "Family doctor: " << endl;
		if (doctorHome == true) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}

	}
};

int main()
{
	Person a("baba", 23);
	a.Print();

	cout << endl << endl;

	Student b("Alex", 19, "ITstep");
	b.Print();

	cout << endl << endl;

	string subjects[] = { "Math", "Science", "History", "English" };
	Teacher c("Maxim", 26, "School #67", 5435,4, subjects);
	c.Print();

	cout << endl << endl;

	Driver d("Vadim", 27, 9265, 2312, "1HGBH41JXMN109186");
	d.Print();

	cout << endl << endl;

	Doctor e("Stiv", 49, "Neurologists", 23, true);
	e.Print();

	cout << endl << endl;
}