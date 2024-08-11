#include <iostream>
#include <cstring>
#include <math.h>

//TEST PRIMER

//5
//Damjan 123042 Prepis
//Iskra 227700 Prepis
//Jakov 217070 Nedolicno_odnesuvanje
//Vladislav 232323 Prepis
//Jovan 210000 Nedolicno_odnesuvanje

using namespace std;

/*
class DisciplinaryAction
{
private:

    char *name;
    int index;
    char *reason;

void copy(const DisciplinaryAction &d){

    this->name=new char[strlen(d.name)+1];
    strcpy(this->name,d.name);
    this->index=d.index;
    this->reason=new char[strlen(d.reason)+1];
    strcpy(this->reason,d.reason);

}

public:
    DisciplinaryAction(char *name=" ",int index=0,char *reason=" ")
    {

        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->index=index;
        this->reason=new char[strlen(reason)+1];
        strcpy(this->reason,reason);
    }

    //copy konstruktor
    DisciplinaryAction(const DisciplinaryAction &d){
        copy(d);
    }

    //destruktori
    ~DisciplinaryAction(){
        delete [] name;
        delete [] reason;
    }

    //operator =
    DisciplinaryAction &operator=(const DisciplinaryAction &d){

        if(this!=&d){

            delete[] name;
            delete [] reason;
            copy(d);
        }
        return *this;
    }

    int getIndex()  {
        return index;
    }

    void setIndex(int index) {
        this->index=index;
    }

    void print(){
    cout<<"Student: "<<name<<endl;
    cout<<"Student's index: "<<index<<endl;
    cout<<"Reason: "<<reason<<endl;
}

};

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for(int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;

        cin >> name >> index >> reason;

        arr[i] = DisciplinaryAction(name, index, reason);
    }

    cout << "-- Testing operator = & print() --\n";
    arr[0].print();

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    arr[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    merka.print();

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for(int i = 0; i < n; i++)
        arr[i].print();

    return 0;
}
 */
 

//sto mi se padna
/*
Да се дефинира класа Product за која се чува информација за:

име на продукт (низа од карактери)
набавна цена (цел број)
продажна цена (цел број)
За класата да се дефинираат следните методи:

default конструктор
конструктор со аргументи
copy конструктор
int profit() метод што ја враќа добивката (продажна - набавна цена)
void display() метод за печатење на производ во формат ИМЕ - ПРОФИТ
Потоа дефинирајте класа Company за која се чува информација за:

име (низа од карактери)
низа од продукти (динамички алоцирана низа од објекти од класата Product)
број на елементи во низата (цел број)
За класата да се дефинираат следните методи:

default конструктор
конструктор со аргументи
copy конструктор
деструктор
оператор =
int totalProfit() метод за пресметување на профит
void display() метод за печатење на информации за компанијата во формат
 ИМЕ
 производ1
 .
 .
производN
профит
void addNewProduct(Product p) метод за додавање на нов производ
void deleteProduct(Product p) метод за бришење на производот р

*/

class Product{
private:
    char name[20];
    int originalCost;
    int sellingPrice;

public:
    Product(char *name=" ", int originalCost=0, int sellingPrice=0){
        strcpy(this->name,name);
        this->originalCost=originalCost;
        this->sellingPrice=sellingPrice;
    }

    Product(const Product &p){
        strcpy(this->name,p.name);
        this->originalCost=p.originalCost;
        this->sellingPrice=p.sellingPrice;
    }

    void setOriginalCost(int originalCost) {
        this->originalCost = originalCost;
    }

    int profit(){

       return sellingPrice-originalCost;
    }

    void display(){
        cout<<name<<" - "<<profit()<<endl;
        
    }

    //GO dodavam daliseisti za da se vidi dali toa sto go sporeduvam go ima vo nizata za posle da go izbrisam vo funkcijata
    bool daliseisti(Product &p){
        if(strcmp(name, p.name)==0){
            return true;
        }
        else {
            return false;
        }
    }

};

class Company{
private:
    char ime[20];
    Product *products;
    int num_of_products;
    
public:
    
    Company(char *ime=" ", Product *products=0,int num_of_products=0){
        strcpy(this->ime, ime);
        this->num_of_products=num_of_products;
        this->products=new Product[num_of_products];
        for(int i=0;i<num_of_products;i++){
            this->products[i]=products[i];
        }
        
    }
    
    Company(const Company &c){
        strcpy(this->ime, c.ime);
        this->num_of_products=c.num_of_products;
        this->products=new Product[num_of_products];
        
        for(int i=0;i<num_of_products;i++){
            this->products[i]=c.products[i];
        }
        
    }
    
    ~Company(){
        delete [] products;
    }
    
    Company &operator=(const Company &c){
        if(this!=&c){
            delete [] products;
            strcpy(this->ime, c.ime);
            this->num_of_products=c.num_of_products;
            this->products=new Product[num_of_products];
            
            for(int i=0;i<num_of_products;i++){
                this->products[i]=c.products[i];
            }
        }
        return *this;
    }
    
    int totalProfit(){
        
        int total=0;
        for(int i=0;i<num_of_products;i++){
            total+=products[i].profit();
        }
        return total;
    }
    
    void display(){
        for(int i=0;i<num_of_products;i++){
            products[i].display();
        }
        cout<<totalProfit()<<endl;
    }
    
    void addNewProduct(Product p){
        
        Product *tmp = new Product[num_of_products++];
        for(int i=0;i<num_of_products;i++){
            tmp[i]=products[i];
        }
        tmp[num_of_products++]=p;
        delete [] products;
        products=tmp;
        
    }
    
    void deleteProduct(Product p){
        
        int counter=0;
        
        for(int i=0;i<num_of_products;i++){
            if(!products[i].daliseisti(p)){
                counter++;
            }
        }
        
        Product *tmp = new Product[counter];
        counter=0;
        for(int i=0;i<num_of_products;i++){
            if(!products[i].daliseisti(p)){
                tmp[counter++]=products[i];
            }
        }
        
        delete [] products;
        products=tmp;
        num_of_products=counter;
        
    }
    
};

int main()
{
   int check;
   cin>>check;
   if(check == 0)
   {
       cout<<"--- Testing Product class ---"<<endl;
       Product p1;
       char name[100];
       cin>>name;
       p1=Product(name, 80, 111);
       Product p2=p1;
       p2.display();
   }
   Product products[100];
   for(int i=0; i<7; i++)
   {
       char name[100];
       int originalCost;
       int sellingPrice;
       cin>>name>>originalCost>>sellingPrice;
       products[i]=Product(name, originalCost, sellingPrice);
   }
   if(check == 1)
   {
       cout<<"--- Testing Company class ---"<<endl;
       char cmpName[100];
       cin>>cmpName;
       Company company;
       company=Company(cmpName, products, 7);
       company.display();
   }
   if(check == 2)
   {
       cout<<"--- Testing addNewProduct() and deleteProduct() method ---"<<endl;
       char n[100];
       cin>>n;
       Product p=Product(n, 29, 49);
       char cmpName[100];
       cin>>cmpName;
       Company company;
       company=Company(cmpName, products, 7);
       company.addNewProduct(p);
       company.display();
       company.deleteProduct(p);
       company.display();
   }
}




//File zadaca - Marce
//OOP ZAD ZA VEZBANJE - 14
//ne iskacaat samo extensions, izleguvaat kako 0 i 1


/*
enum Extension{
        
    txt,pdf,exe
};

class File{
    
private:
    char *fileName;
    char *fileOwner;
    int fileSize;
    Extension ex;
    
public:
    
    File(char *fileName=" ", char *fileOwner=" ", int fileSize=0, Extension ex=txt){
        
        this->fileName=new char[strlen(fileName)+1];
        strcpy(this->fileName, fileName);
        this->fileOwner=new char[strlen(fileOwner)+1];
        strcpy(this->fileOwner, fileOwner);
        this->fileSize=fileSize;
        this->ex=ex;
        
    }
    
    File(const File &f){
        this->fileName=new char[strlen(f.fileName)+1];
        strcpy(this->fileName, f.fileName);
        this->fileOwner=new char[strlen(f.fileOwner)+1];
        strcpy(this->fileOwner, f.fileOwner);
        this->fileSize=f.fileSize;
        this->ex=f.ex;
    }
    
    ~File(){
        delete [] fileName;
        delete [] fileOwner;
    }
    
    File &operator=(const File &f){
        if(this!=&f){
            delete [] fileName;
            delete [] fileOwner;
            
            this->fileName=new char[strlen(f.fileName)+1];
            strcpy(this->fileName, f.fileName);
            this->fileOwner=new char[strlen(f.fileOwner)+1];
            strcpy(this->fileOwner, f.fileOwner);
            this->fileSize=f.fileSize;
            this->ex=f.ex;
        }
        return *this;
    }
    
    void print(){
        
        char* ext = "";
                if (ex == 0) ext = "pdf";
                if (ex == 1) ext = "txt";
                if (ex == 2) ext = "exe";
        
        cout<<"File name: "<<fileName<<"."<<ex<<endl;
        cout<<"File owner: "<<fileOwner<<endl;
        cout<<"File size: "<<fileSize<<endl;
    }
    
    bool equals(const File &f){
        if((strcmp(this->fileName, f.fileName)==0) && (this->ex == f.ex) && (strcmp(this->fileOwner, f.fileOwner)==0)){
            return true;
        }
        else {
            return false;
        }
    }
    
    bool equalsType(const File &f){
        if((strcmp(this->fileName, f.fileName)==0) && (this->ex == f.ex)){
            return true;
        }
        else {
            return false;
        }
    }
    
};

class Folder{
    
private:
    char *name;
    File *files;
    int num_files;
    
public:
    
    Folder(const char *name){
        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->num_files=0;
        this->files=0;
    }
    
    Folder(const Folder &f){
        this->name=new char[strlen(f.name)+1];
        strcpy(this->name, f.name);
        this->num_files=f.num_files;
        this->files=f.files;
    }
    
    ~Folder(){
        delete [] name;
        delete [] files;
    }
    
    Folder &operator=(const Folder &f){
        if(this!=&f){
            delete [] name;
            delete [] files;
            this->name=new char[strlen(f.name)+1];
            strcpy(this->name, f.name);
            this->num_files=f.num_files;
            this->files=f.files;
            
        }
        return *this;
    }
    
    void add(const File &f){
        
        File *tmp = new File[num_files+1];
        for(int i=0;i<num_files;i++){
            tmp[i]=files[i];
        }
        
        tmp[num_files++]=f;
        delete [] files;
        files=tmp;
        
    }
    
    void remove(const File &f){
        int counter=0;
        
        for(int i=0;i<num_files;i++){
            if(!files[i].equals(f)){
                counter++;
            }
        }
        
        File *tmp=new File[counter];
        counter=0;
        for(int i=0;i<num_files;i++){
            if(!files[i].equalsType(f)){
                tmp[counter++]=files[i];
            }
        }
        
        delete [] files;
        files=tmp;
        num_files=counter;
    }
    
    void print(){
        cout<<"Folder's name: "<<name<<endl;
        for(int i=0;i<num_files;i++){
            files[i].print();
        }
    }
    
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    }
    else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    }
    else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    }
    else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    }
    else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
*/

//courses resenie

/*
enum Extension {
    PDF,TXT,EXE
};

class File {
private:
    char* name;
    char* owner;
    int size;
    Extension extension;

    void copy(const File & that) {
        this->name = new char[strlen(that.name) + 1];
        strcpy(this->name, that.name);
        this->owner = new char[strlen(that.owner) + 1];
        strcpy(this->owner, that.owner);
        this->size = that.size;
        this->extension = that.extension;
    }
public:
    File() {
        this->name = new char[0];
        this->owner = new char[0];
        this->size = 0;
    }
    File(const char* name, const char* owner, const int size, const Extension extension) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->owner = new char[strlen(owner) + 1];
        strcpy(this->owner, owner);
        this->size = size;
        this->extension = extension;
    }

    File(const File & that) {
        copy(that);
    }

    File & operator = (const File & that) {
        if (&that != this) {
            delete [] name;
            delete [] owner;
            copy(that);
        }
        return *this;
    }

    bool equals(const File & that) {
        return equalsType(that)&&strcmp(this->owner, that.owner) == 0;
    }

    bool equalsType(const File & that) {
        return strcmp(this->name, that.name) == 0&&this->extension == that.extension;
    }

    void print() {
        char* ext = "";
        if (extension == 0) ext = "pdf";
        if (extension == 1) ext = "txt";
        if (extension == 2) ext = "exe";
        cout << "File name: " << name << "." << ext << endl;
        cout << "File owner: " << owner << endl;
        cout << "File size: " << size << endl;
    }

    ~File() {
        delete [] name;
        delete [] owner;
    }
};

class Folder {
private:
    char* name;
    int numberOfFiles;
    File* files;
public:
    Folder(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->numberOfFiles = 0;
        this->files = 0;
    }

    void add(const File & file) {
        File* tmp = files;
        this->files = new File[numberOfFiles + 1];
        for (int i = 0; i < numberOfFiles; i++)
            files[i] = tmp[i];
        files[numberOfFiles++] = file;
    }


//  void add(const File &f){
        
// //        File* tmp = files;
//         File *temp = new File[br_dat+1];
//         for(int i=0;i<br_dat;i++){
//             temp[i]=files[i];
//         }
//         temp[br_dat++]=f;
//         delete [] files;
//         files=temp;
//     }

    void remove(const File & file) {
        int indexToDelete = -1;
        for (int i = 0; i < numberOfFiles; i++)
            if (files[i].equals(file)) {
                indexToDelete = i;
                break;
            }

        if (indexToDelete != -1) {
            File* tmp = files;
            this->files = new File[numberOfFiles - 1];
            for (int i = 0, j = 0; i < numberOfFiles; i++)
                if (i != indexToDelete)
                    files[j++] = tmp[i];
            numberOfFiles--;
        }
    }

    void print() {
        cout << "Folder name: " << name << endl;
        for (int i = 0; i < numberOfFiles; i++)
            files[i].print();
    }

    ~Folder() {
        delete [] name;
        delete [] files;
    }
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    }
    else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    }
    else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    }
    else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    }
    else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
 */


//STUDENTS - ONLINE LAB
/*
class Student{
    
private:
    char *name;
    int age;
    char *major;

    void copy(const Student &s){

        this->name = new char [strlen(s.name)+1];
        strcpy(this->name,s.name);
        this->age = s.age;
        this->major = new char [strlen(s.major)+1];
        strcpy(this->major,s.major);

    }

public:
    Student(char *name=" ", int age=0, char *major=" "){

        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age=age;
        this->major=new char[strlen(major)+1];
        strcpy(this->major,major);

    }

    Student(const Student &s)
    {
        copy(s);
    }


    ~Student(){
        delete[]name;
        delete[]major;
    }

    Student &operator=(const Student &s){
        if(this!=&s){
            delete[]name;
            delete[]major;
            copy(s);
        }
        return *this;
    }


};

class Classroom
{
private:
    Student *students;
    int numStudents;
    int capacity;

    void copy(const Classroom &c)
    {
        this->numStudents=c.numStudents;
        this->students = new Student[c.numStudents];
        this->capacity= c.capacity;
        for (int i = 0; i < numStudents; ++i) {
            this->students[i]=c.students[i];
        }
    }
public:
    Classroom(Student *students=0,int numStudents=0,int capacity=0)
    {
        this->numStudents=numStudents;
        this->capacity=capacity;
        this->students = new Student[numStudents];
        for (int i = 0; i < numStudents; ++i) {
            this->students[i]=students[i];
        }
    }

    Classroom(const Classroom &c){
        copy(c);
    }

    ~Classroom(){
        delete [] students;
    }

    //operator =
    Classroom &operator =(const Classroom &c){
        if(this!=&c){
            delete [] students;
            copy(c);
        }
        return *this;
    }

    void add(Student s){
        Student *tmp = new Student[numStudents];
        for (int i = 0; i < numStudents; ++i) {
            tmp[i]=students[i];
        }
        tmp[numStudents++]=s;
        delete[]students;
        students=tmp;
    }

    void remove()

    //    void deletePage(WebPage p)
//    {
//        int flag=0;
//        for (int i = 0; i < n; ++i) {
//            if(niza[i].daliseIsti(p))
//            {
//                flag=1;
//            }
//        }
//        if(flag==0){
//            return;
//        }
//        WebPage *tmp = new WebPage[n-1];
//        int j=0;
//        for (int i = 0; i < n; ++i) {
//            if(!niza[i].daliseIsti(p)){
//                tmp[j] = niza[i];
//                j++;
//            }
//        }
//        n--;
//        delete[]niza;
//        niza=tmp;
//    }
//    void add(int number){
//        if(size<capacity){
//            content[size++]=number;
//        }
//        else {
//            //move all elements and the new element in a temp array
//            int *tmp = new int [size];
//            for(int i=0;i<size;i++){
//                tmp[i]=content[i];
//            }
//            tmp[size++]=number;
//            delete [] content;
//            content = tmp;
//        }
//    }
};


int main() {
    int numClassrooms, numStudents;
    cin >> numClassrooms;
    Classroom classrooms[100];
    Student students[100];

    // Testing add method
    for (int i = 0; i < numClassrooms; i++) {
        cin >> numStudents;
        for (int j = 0; j < numStudents; j++) {
            char name[100], major[100];
            int age;
            cin >> name >> age >> major;
            Student student(name, age, major);
            classrooms[i].add(student);
            students[i*numStudents + j] = student;
        }
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }


    // Testing findMedianAge method
    int targetClassroom;
    cin >> targetClassroom;
    double medianAge = findMedianAge(classrooms[targetClassroom]);
    cout << "The median age in classroom " << targetClassroom << " is: " << medianAge << endl;

    // Testing remove method
    cin >> numStudents;
    for (int j = 0; j < numStudents; j++) {
        char name[100];
        cin >> name;
        for (int i = 0; i < numClassrooms; i++) {
            classrooms[i].remove(name);
        }
    }
    for (int i = 0; i < numClassrooms; i++) {
        cout<<"Classroom "<<i<<endl;
        classrooms[i].printStudents();
    }

    return 0;
}
*/
