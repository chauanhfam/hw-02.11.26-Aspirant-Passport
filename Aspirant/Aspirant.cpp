#include <iostream>
#include <Windows.h>
using namespace std;
class Person //task 1
{
protected:
    char* name;
    int age;
public:
    Person()
    {
        name = nullptr;
        age = 0;
    }

    Person(const char* Name, int Age)
    {
        cout << "Construct Person\n";
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
        age = Age;
    }

    void Print() const
    {
        cout << "Name: " << name << endl
            << "Age: " << age << endl;
    }

    void Input()
    {
        if (name != nullptr) {
            delete[] name;
        }
        char buff[20];
        cout << "Enter name: ";
        cin.ignore(); 
        cin.getline(buff, 20);
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);
        cout << "Enter age: ";
        cin >> age;
    }

    ~Person()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
        cout << "Destruct Person\n";
        Sleep(100); 
    }
};

class Student : public Person
{
protected:
    char* Univer;
public:
    Student()
    {
        Univer = nullptr;
    }

    Student(const char* n, int a, const char* u) : Person(n, a)
    {
        cout << "Construct Student\n";
        Univer = new char[strlen(u) + 1];
        strcpy_s(Univer, strlen(u) + 1, u);
    }

    ~Student()
    {
        if (Univer != nullptr) 
        {
            delete[] Univer;
        }
        cout << "Destruct Student\n";
        Sleep(100);
    }

    void Print() const
    {
        cout << "Output Student \n";
        Person::Print();
        cout << "University: " << Univer << endl;
    }

    void Input(const char* u)
    {
        if (Univer != nullptr) 
        {
            delete[] Univer;
        }
        Univer = new char[strlen(u) + 1];
        strcpy_s(Univer, strlen(u) + 1, u);
        Person::Input();
    }
};

class Aspirant : public Student
{
private:
    char* Thesis;
public:
    Aspirant()
    {
        Thesis = nullptr;
    }

    Aspirant(const char* n, int a, const char* u, const char* t) : Student(n, a, u)
    {
        cout << "Construct Aspirant\n";
        Thesis = new char[strlen(t) + 1];
        strcpy_s(Thesis, strlen(t) + 1, t);
    }

    ~Aspirant()
    {
        if (Thesis != nullptr) 
        {
            delete[] Thesis;
        }
        cout << "Destruct Aspirant\n";
        Sleep(100);
    }

    void Print() const
    {
        cout << "Output Aspirant\n";
        Person::Print();
        cout << "University: " << Univer << endl;
        cout << "Thesis topic: " << Thesis << endl;
    }

    void Input(const char* u, const char* t)
    {
        if (Thesis != nullptr)
        {
            delete[] Thesis;
        }
        Thesis = new char[strlen(t) + 1];
        strcpy_s(Thesis, strlen(t) + 1, t);
        Student::Input(u);
    }
};

//task 2 PASSPORT 
class Passport
{
protected:
    char* name;
    char* surname;
    char* passportNumber;
    char* issuedBy;
    int birthYear;

public:
    Passport()
    {
        name = nullptr;
        surname = nullptr;
        passportNumber = nullptr;
        issuedBy = nullptr;
        birthYear = 0;
    }

    Passport(const char* n, const char* s, const char* number, const char* issued, int year)
    {
        cout << "Construct Passport\n";

        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);

        surname = new char[strlen(s) + 1];
        strcpy_s(surname, strlen(s) + 1, s);

        passportNumber = new char[strlen(number) + 1];
        strcpy_s(passportNumber, strlen(number) + 1, number);

        issuedBy = new char[strlen(issued) + 1];
        strcpy_s(issuedBy, strlen(issued) + 1, issued);

        birthYear = year;
    }

    virtual void Print() const
    {
        cout << "\nPassport information\n";
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Passport number: " << passportNumber << endl;
        cout << "Issued by: " << issuedBy << endl;
        cout << "Birth year: " << birthYear << endl;
    }

    virtual ~Passport()
    {
        delete[] name;
        delete[] surname;
        delete[] passportNumber;
        delete[] issuedBy;

        cout << "Destruct Passport\n";
        Sleep(100);
    }
};


//FOREIGN PASSPORT
class ForeignPassport : public Passport
{
private:
    char* foreignNumber;
    char* visas;

public:
    ForeignPassport()
    {
        foreignNumber = nullptr;
        visas = nullptr;
    }

    ForeignPassport(const char* n, const char* s, const char* number, const char* issued, int year, const char* fNumber, const char* v) : Passport(n, s, number, issued, year)
    {
        cout << "Construct ForeignPassport\n";

        foreignNumber = new char[strlen(fNumber) + 1];
        strcpy_s(foreignNumber, strlen(fNumber) + 1, fNumber);

        visas = new char[strlen(v) + 1];
        strcpy_s(visas, strlen(v) + 1, v);
    }

    void Print() const
    {
        cout << "\nForeign passport information\n";

        Passport::Print();

        cout << "Foreign passport number: " << foreignNumber << endl;
        cout << "Visas: " << visas << endl;
    }

    ~ForeignPassport()
    {
        delete[] foreignNumber;
        delete[] visas;

        cout << "Destruct ForeignPassport\n";
        Sleep(100);
    }
};

int main()
{
    cout << "Testing Student" << endl;
    Student a("Nastya", 19, "Itstep");
    a.Print();

    cout << "\nTesting Aspirant" << endl;
    Aspirant b("Jane", 24, "Politeh", "Artificial Intelligence in Medicine");
    b.Print();

    cout << "\nTesting Passport" << endl;
    Passport p("Anna", "Ivanova", "123456", "Odesa Department", 2005);
    p.Print();
    cout << "\nTesting ForeignPassport" << endl;
    ForeignPassport fp("Anna", "Ivanova", "123456", "Odesa Department", 2005, "FT987654", "Germany, Poland, France");
    fp.Print();

    system("pause");
    return 0;
}