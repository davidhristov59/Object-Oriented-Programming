#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

/*
Да се дефинира класа MobilePhone во која ќе се чуваат податоци за еден мобилен телефон:

модел (низа од карактери не подолга од 20 карактери)
број на модел (цел број)
година на издавање (цел број)
За класата да се дефинира default конструктор, конструктор со аргументи, copy конструктор, деструктор и доколку има потреба get методи. Исто така да се дефинира и фунцкија за печатење на информации за класата која ќе печати во следниот формат „(модел) (број на модел) release year: (година на издавање)“.

Потоа да се дефинира класа Owner во која се чуваат следните информации:

име (низа од карактери не подолга од 20 карактери)
презиме (низа од карактери не подолга од 20 карактери)
мобилен телефон (објект од класа MobilePhone)
Да се креира default конструктор, конструктор со аргументи, деструктор и доколку има потреба get методи. Исто така да се дефинира и функција за печатење на информации за класата која ќе печати во следниот формат:

 (име) (презиме) has a mobile phone:

(информации за мобилен телефон)“
 
 Input              Result
 1                  Marko Petrov has a mobile phone:
                    Iphone 12 release year: 2020
 Iphone
 12
 2020
 Marko
 Petrov
 */
 
 /*
class MobilePhone{

private:
    char model[20];
    int modelNumber;
    int year;

public:
    MobilePhone(char *model="", int modelNumber=0, int year=0){

        strcpy(this->model,model);
        this->modelNumber=modelNumber;
        this->year=year;
    }

    MobilePhone(const MobilePhone &mp){

        strcpy(this->model,mp.model);
        this->modelNumber=mp.modelNumber;
        this->year=mp.year;

    }

    ~MobilePhone(){}

    char *getModel(){
        return model;
    }

    int getModelNumber(){
        return modelNumber;
    }

    int getYear(){
        return year;
    }

    void print()
    {
        cout<<model<<" "<<modelNumber<<" release year: "<<year<<endl;
    }
};


class Owner
{
private:
    char ime[20];
    char prezime[20];
    MobilePhone mb;
public:                                     //const MobilePhone &telefon
    Owner(char *ime=" ",char *prezime="", MobilePhone telefon=0){

        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        mb=telefon;
    }
Owner(const Owner &o)
{
        strcpy(this->ime,o.ime);
        strcpy(this->prezime,o.prezime);
        mb=o.mb;
}
~Owner(){}

    char *getIme(){
        return ime;
    }

    char *getPrezime(){
        return prezime;
    }

    MobilePhone getMb(){
        return mb;
    }

    void print()
    {

        cout<<ime<<" "<<prezime<<" has a mobile phone:"<<endl;
        mb.print();
    }
};



//DO NOT CHANGE THE MAIN FUNCTION
int main() {
    char model[20];
    int modelNumber;
    int year;
    char name[20];
    char surname[20];

    int testCase;

    cin>>testCase;

    cin>>model;
    cin>>modelNumber;
    cin>>year;
    cin>>name;
    cin>>surname;

    if(testCase==1){
        MobilePhone mobilePhone(model,modelNumber,year);

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }
    if(testCase==2){
        MobilePhone mobilePhone(MobilePhone(model,modelNumber,year));

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }

}
*/


//2 ZAD
/*
class Film {
private:
  char name[100];
  float rating;
  float revenue;
    
    public:
    
    Film(){}
        // Konstruktori
        Film (char *ime, float r, float rev)
        {
            strcpy(name, ime);
            rating = r;
            revenue = rev;
        }
      
        
        // Desturkotri
    ~Film(){}
        
    void setName(char *ime)
    {
        strcpy(name, ime);

    }
    void setRating(float r)
    {
        rating = r;
    }
    void setRevenue(float rev)
    {
        revenue = rev;
    }
    
    
    char *getName()
    {
        return name;
    }
    
    float getRating()
    {
        return rating;
    }
    
    float getRevenue()
    {
        return revenue;
    }
    
    void display()
    {
        cout << "Name of film: " << name << endl << "Rating: " << rating <<endl
        << "Revenue: " << revenue <<endl;
    }
    
};

void printMostPopularFilm(Film *films, int n){

    int max=0,max_i=0,i;
    for(i=0;i<n;i++){

        if(films[i].getRevenue()>max){
            max=films[i].getRevenue();
            max_i=i;
        }
    }

    cout<<"Name of film: "<<films[max_i].getName()<<endl;
    cout<<"Rating:" << films[max_i].getRating()<<endl;
    cout<<"Revenue: "<<films[max_i].getRevenue()<<endl;
}




int main() {
    int n;
    cin >> n;
    Film films[100];

    char name[100];
    double rating;
    double revenue;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> rating;
        cin >> revenue;

        // testing constructor with arguments
        films[i] = Film(name, rating, revenue);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> rating;
    cin >> revenue;
    films[n-1].setName(name);
    films[n-1].setRating(rating);
    films[n-1].setRevenue(revenue);

    cout<<"-->Testing set methods and display()"<<endl;
    films[n-1].display();
    cout<<endl;

    cout<<"-->Testing printMostPopularFilm()"<<endl;
    printMostPopularFilm(films , n);
    return 0;
}
*/


//ZAD3 - EMPLOYEE
/*
Да се дефинира класа Employee во која ќе се чуваат информации за:
name(низа од максимум 100 карактери) -име на вработениот
surname(низа од максимум 100 карактери) - презиме
salary(цел број) - колку му е платата
методи кои што класата треба да ги има:
print()

-Принта во формат:
Employee name:
Employee surname:
Employee salary:

Да се дефинира класа TechCompany во која ќе се чуваат информации за:
name(низа од максимум 100 карактери) -име на фирмата
employees(низа од вработени)
numOfEmployees(цел број) - колку вработени има во фирмата
методи кои што класата треба да ги има:

print()

-Принта во формат:
Tech company name:
Number of employees:

 double getAverageOfEmployeeсSalary()

-Враќа средна врендност од платите на секој вработен во таа фирма


Сите променливи внатре во класите треба да бидат приватни. Соодветно во рамките на класите да се дефинираат:
конструктор (без и со параметри)
деструктор
set методи
get методi
copy constructor

Функции надвор од класата:

printCompanyWithHighestAverageSalary(TechCompany companies[], int numCompanies)
-Го враќа TechCompany објектот што има најголема средна вредност за плати на неговите вработени


printCompanyWithHighestStdSalary(TechCompany companies[], int numCompanies)
-Го враќа TechCompany објектот што има најголема стандардна девијација за плати на неговите вработени
𝑉𝐴𝑅=∑𝑓𝑜𝑟 𝑒𝑎𝑐ℎ 𝐸𝑚𝑝𝑙𝑜𝑦𝑒𝑒 𝑒[(𝑒.𝑠𝑎𝑙𝑎𝑟𝑦−𝐴𝑉𝐺)2]𝑛−1𝑆𝑇𝐷=(√𝑉𝐴𝑅)

-Помош: AVG е средната вредност на платите на сите вработен во таа фирма, STD е стандардна девијација, VAR  е помошна променлива. И прво квадрирајте го изразот па потоа додадете го во сумата!
isSameCompany(TechCompany company1, TechCompany company2)

-Враќа boolean вредност: две фирми се исти ако имаат исто име. Треба само да се првери дали им е исто името!

Input

3
CompanyA
5
John Doe 50000
Jane Doe 70000
Bob Smith 60000
Anna Williams 80000
Michael Brown 55000
CompanyB
4
Alice Brown 80000
David Green 70000
Eve White 50000
Frank Black 65000
CompanyC
6
Laura Lee 100000
Benjamin Johnson 65000
Emma Davis 75000
Oliver Wilson 82000
Sophie Martinez 60000
William Clark 72000

OUTPUT

-->Testing get and set methods for one object and copy constructor
copy

-->Testing addEmployee function
Number of employees in copy: 6

-->Testing copy of first employee
Employee name: John
Employee surname: Doe
Employee salary: 50000

-->Testing methods
Tech company with the highest average salary: CompanyC
Tech company with the highest standard deviation for salaries: CompanyC
The tech company: CompanyC has the highest standard deviation and highest average salary
*/

/*
class Employee{

private:
    char name[100];
    char surname[100];
    int salary;

public:
    Employee(){
        strcpy(name,"John");
        strcpy(surname,"Doe");
        salary=0;
    }
    Employee(const char *i, const char *p, int s){

            strcpy(name,i);
            strcpy(surname,p);
            salary=s;

//            strcpy(this->name,name);
//            strcpy(this->surname,surname);
//            this->salary=salary;

    }
    Employee(const Employee &e)
    {
        strcpy(name,e.name);
        strcpy(surname,e.surname);
        salary=e.salary;
    }

    ~Employee(){}

//    void setName(const char *i)
//    {
//        strcpy(name,i);
//    }
//    void setSurname(char *p)
//    {
//        strcpy(surname,p);
//    }
//    void setSalary(int s)
//    {
//        salary=s;
//    }

    char *getName(){
        return name;
    }

    char *getSurname(){
        return surname;
    }

    int getSalary()const{
        return salary;
    }

    void printEmployee()
    {
        cout<<"Employee name: "<<name<<endl;
        cout<<"Employee surname: "<<surname<<endl;
        cout<<"Employee salary: "<<salary<<endl;
    }
};

class TechCompany {
private:
    char name[100];
    Employee employees[20];
    int numofEmployees;
public:

    TechCompany() {
        strcpy(name,"david");
        numofEmployees=0;
        for(int i=0;i<numofEmployees;i++){
            employees[i]=Employee();
        }
    }

    TechCompany(char *ime) {
        strcpy(name, ime);
        numofEmployees = 0;
    }

    TechCompany(const TechCompany &comp) //copy konstruktor
    {
        strcpy(name, comp.name);
        numofEmployees = comp.numofEmployees;
        for (int i = 0; i < numofEmployees; ++i) { //for ciklus za niza
            employees[i] = comp.employees[i];
        }
    }

    ~TechCompany() {}


    void setName(const char *ime) {
        strcpy(name, ime);
    }

    void setNumofEmployees(int noe) {
        numofEmployees = noe;
    }

    char *getName() {
        return name;
    }

    const Employee &getEmployee(int index)const{
        return employees[index];
    }

    int getNumEmployees() {
        return numofEmployees;
    }

    void print() {
        cout << "Tech company name: " << name << endl;
        cout << "Number of employees: " << numofEmployees << endl;
    }

    double getAverageOfEmployeesSalary() {
        double suma = 0.0;
        for (int i = 0; i < numofEmployees; ++i) {
            suma += employees[i].getSalary(); //so get deka sme vo druga klasa
        }
        return suma / numofEmployees; //sredna vrednost
    }

    void addEmployee(Employee e)
    {
        if(numofEmployees<20)
        {
            employees[numofEmployees]=e;
            numofEmployees++;
        }
    }


};

TechCompany printCompanyWithHighestAverageSalary(TechCompany companies[], int numCompanies){

    int i,max_i=0;
    float max=0;
    for(i=0;i<numCompanies;i++) {

        if(companies[i].getAverageOfEmployeesSalary()>max){

            max=companies[i].getAverageOfEmployeesSalary();
            max_i=i;
        }
    }
    return companies[max_i];
}


TechCompany printCompanyWithHighestStdSalary(TechCompany companies[], int numCompanies) {
    int max_i;
    double najgolema_plata = 0;

    for (int i = 0; i < numCompanies; i++) {
        int broj_vraboteni = companies[i].getNumEmployees();
        double srp= companies[i].getAverageOfEmployeesSalary();
        double var = 0;

        for (int j = 0; j < broj_vraboteni; j++) {
            double razlika_plata = companies[i].getEmployee(j).getSalary() - srp;
            //var += diff * diff;
            var+=(razlika_plata*razlika_plata);
        }

        double standardSalary = sqrt(var / (broj_vraboteni-1));

        if (standardSalary > najgolema_plata) {
            najgolema_plata = standardSalary;
            max_i = i;
        }
    }

    return companies[max_i];
}

bool isSameCompany(TechCompany comp1, TechCompany comp2){
    return strcmp(comp1.getName(), comp2.getName())==0;
}



int main() {
    const int MAX_COMPANIES = 10;
    const int MAX_EMPLOYEES = 20;

    TechCompany companies[MAX_COMPANIES];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char name[100];
        std::cin >> name;

        TechCompany company(name);

        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++) {
            char name[100];
            char surname[100];
            int salary;

            std::cin >> name;

            std::cin >> surname;

            std::cin >> salary;

            Employee employee(name, surname, salary);

            company.addEmployee(employee);
        }

        companies[i] = company;
    }

    TechCompany copy = companies[0];

    std::cout<<"-->Testing get and set methods for one object and copy constructor"<<std::endl;
    copy.setName("copy");
    std::cout << copy.getName() << std::endl;


    std::cout<<"-->Testing addEmployee function"<<std::endl;
    Employee newEmployee("John", "Doe", 5000);
    copy.addEmployee(newEmployee);
    std::cout << "Number of employees in copy: " << copy.getNumEmployees() << std::endl;


    std::cout<<"-->Testing copy of first employee"<<std::endl;
    Employee firstEmployee = copy.getEmployee(0);
    firstEmployee.printEmployee();


    std::cout<<"-->Testing methods"<<std::endl;
    TechCompany t = printCompanyWithHighestAverageSalary(companies, n);
    TechCompany t1 = printCompanyWithHighestStdSalary(companies, n);

    std::cout << "Tech company with the highest average salary: " << t.getName() << std::endl;
    std::cout << "Tech company with the highest standard deviation for salaries: " <<t1.getName() << std::endl;

    if (isSameCompany(t, t1)){
        std::cout<<"The tech company: "<<t.getName()<<" has the highest standard deviation and highest average salary"<<std::endl;
    }
    return 0;
}
*/
