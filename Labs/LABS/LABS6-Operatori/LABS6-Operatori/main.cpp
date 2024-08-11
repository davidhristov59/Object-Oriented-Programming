#include <iostream>
#include <cstring>

using namespace std;

/*
class DisciplinaryAction{

private:

    char *name;
    char *reason;
    int index;
    int sessions;

    public:
        DisciplinaryAction(char *name=" ",int index=0, char *reason=" ", int sessions=0){

            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);
            this->reason=new char[strlen(reason)+1];
            strcpy(this->reason,reason);
            this->index=index;
            this->sessions=sessions;

        }

        //copy konstruktor
        DisciplinaryAction(const DisciplinaryAction &d){
            this->name=new char[strlen(d.name)+1];
            strcpy(this->name,d.name);
            this->reason=new char[strlen(d.reason)+1];
            strcpy(this->reason,d.reason);
            this->index=d.index;
            this->sessions=d.sessions;
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
                this->name=new char[strlen(d.name)+1];
                strcpy(this->name,d.name);
                this->reason=new char[strlen(d.reason)+1];
                strcpy(this->reason,d.reason);
                this->index=d.index;
                this->sessions=d.sessions;
            }
            return *this;
        }

        int getIndex()  {
            return index;
        }

        void setIndex(int index) {
            this->index=index;
        }

        int get_sessions(){
            return sessions;
        }

        //operator <<
        friend ostream &operator<<(ostream &out, const DisciplinaryAction &da){
        out<<"Student: "<<da.name<<endl;
        out<<"Student's index: "<<da.index<<endl;
        out<<"Reason: "<<da.reason<<endl;
        out<<"Sessions: "<<da.sessions<<endl;

            return out;
        }

        //operator ++ - prefiks
        DisciplinaryAction &operator++(){

        ++sessions;
        return *this;

        }

        //operator >=
        bool operator >= (DisciplinaryAction &da){

            return this->get_sessions() >= da.get_sessions();

        }
    
//    bool operator>=(const DisciplinaryAction &d)
//       {
//           if(this->br_sesii>=d.br_sesii)
//           {
//               return true;
//           }
//           return false;
//       }

};

int main() {
    int n;
    cin >> n;

    /// Testing Default constructor and equal operator
    /// Array input

    DisciplinaryAction arr[n];

    for (int i = 0; i < n; i++) {
        char name[100];
        char reason[100];
        int index;
        int sessions;

        cin >> name >> index >> reason >> sessions;

        arr[i] = DisciplinaryAction(name, index, reason, sessions);
    }

    cout << "-- Testing operator = & operator <<  --\n";
    cout << arr[0];

    /// Testing copy constructor & set index

    DisciplinaryAction merka(arr[0]);
    merka.setIndex(112233);

    cout << "\n-- Testing copy constructor & set index --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    cout << arr[0];

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    cout << merka;

    /// Testing if array is OK

    cout << "\n-- Testing if array was inputted correctly --\n";

    for (int i = 0; i < n; i++)
        cout << arr[i];


    cout << "\nTesting operator ++ and <<" << endl;
    for (int i = 0; i < n; i++)
        cout << (++arr[i]);


    cout << "\nTesting operator >=" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << i << " " << ((arr[i] >= arr[j]) ? ">= " : "< ") << j << endl;
            }
        }
    }

    return 0;
}
*/

/*
class Book{

    private:
    char *name;
    int *ISBN;
    int num_pages;

    public:
    Book(char *name=" ",int *ISBN=0,int num_pages=5){

        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->ISBN=new int[5];
        this->num_pages=num_pages;

    }

    Book(const Book &b){
        this->name=new char[strlen(b.name)+1];
        strcpy(this->name,b.name);
        this->ISBN=new int[5];
        this->num_pages=b.num_pages;
        for(int i=0;i<5;i++){
            ISBN[i]=b.ISBN[i];
        }
        
        //        for(int i=0;i<5;i++){
        //            ISBN[i]=b.ISBN[i];
        //        }
        
    }


    Book &operator=(const Book &b){
        if(this!=&b){
            delete [] name;
            delete [] ISBN;

            this->name=new char[strlen(b.name)+1];
            strcpy(this->name,b.name);
            this->ISBN=new int[5];
            this->num_pages=b.num_pages;
            
            for(int i=0;i<5;i++){
                ISBN[i]=b.ISBN[i];
            }
            
            //        for(int i=0;i<5;i++){
            //            ISBN[i]=b.ISBN[i];
            //
        }
        return *this;
    }

    ~Book(){
        delete [] name;
        delete [] ISBN;
    }

    int *get_ISBN(){
        return ISBN;
    }
    
   bool operator == (Book &b){
        
       for(int i=0;i<5;i++){
           if(this->ISBN[i]!=b.ISBN[i]){
               return false;
           }
       }
       return true;
    }
    
    
    friend ostream &operator << (ostream &out, const Book &b){
        
        out<<"Title: "<<b.name<<" ISBN: [ ";
        for(int i=0;i<5;i++){
            out<<b.ISBN[i]<<" ";
            
        }
        out<<"]";
        return out;
    }
    
    int get_numpages(){
        return num_pages;
    }

    };


class BorrowABook{
    
private:
    
    char name[100];
    Book *books ;
    int numPages;
    
public:
    BorrowABook(char *name="")
    {
        strcpy(this->name, name);
        this->books=new Book[numPages];
        this->numPages=0;
        
    }
    
    
    BorrowABook(const BorrowABook &bb){
        
        strcpy(this->name, bb.name);
        this->books=new Book[bb.numPages];
        this->numPages=bb.numPages;
        for(int i=0;i<numPages;i++){
            books[i]=bb.books[i];
        }
    }
    
    BorrowABook &operator=(const BorrowABook &bb){
        
        if(this!=&bb){
            delete [] books;
            strcpy(this->name, bb.name);
            this->books=new Book[bb.numPages];
            this->numPages=bb.numPages;
            for(int i=0;i<numPages;i++){
                books[i]=bb.books[i];
            }
        }
        return *this;
    }
    
    ~BorrowABook(){
        delete [] books;

    }
    
    BorrowABook &operator += (Book b){
        
        Book *tmp=new Book[numPages+1];
        
        for(int i=0;i<numPages;i++){
            tmp[i]=books[i];
        }
        tmp[numPages++]=b;
        delete [] books;
        books=tmp;
        return *this;
    }
    
    
    BorrowABook &operator -= (Book b){
        
        int flag=0;
        for(int i=0;i<numPages;i++){
            if(books[i]==b){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return *this;
        }
        
        //moze i vaka
        //        int brojac=0;
        //               for(int i=0;i<numPages;i++)
        //               {
        //                   if(!(books[i]==b))
        //                   {
        //                       brojac++;
        //                   }
        //               }
        //        return *this;
        //    }
        
        Book *tmp=new Book[numPages-1];
        
        for(int i=0,j=0;i<numPages;i++){
            if(!(books[i]==b)){
                tmp[j++]=books[i];
            }
        }
        numPages--;
        delete [] books;
        books=tmp;
        return *this;
        
    }
    
    void printNumberOfPages(int max)
       {
           cout<<name<<endl;
           for(int i=0;i<numPages;i++)
           {
               if(books[i].get_numpages()>max)
               {
                   cout<<books[i]<<endl;
               }
           }
       }


    
};


int main()
{
    BorrowABook library("FINKI-Library");
    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        char title[100];
        int isbn[5];
        int pages;

        cin>>title;

        for (int i=0;i<5;i++)
            cin>>isbn[i];

        cin>>pages;

        Book nov=Book(title,isbn,pages);

        //adding a new book
        library+=nov;
    }

    //the book which has the same isbn as some previous one
    char title[100];
    int isbn[5];
    int pages;
    cin>>title;
    for (int i=0;i<5;i++)
        cin>>isbn[i];
    cin>>pages;

    Book greshka=Book(title,isbn,pages);

    //deleting a book
    library-=greshka;

    library.printNumberOfPages(150);

    return 0;
}
*/

//STO MI SE PADNA
/*
Да се напише класа InvoiceItem во која се чуваат информации за:

име на ставка (динамичка алокација од карактери)
опис на ставка (динамичка алокација од карактери)
цена на ставка (цел број)
Да се креираат:

copy конструктор
конструктор без параметри
конструктор со параметри
оператор =
деструктор
Дополнително да се преоптоварат следниве оператори:

оператор за печатење, кој што ги печати информациите за ставката во следниов формат:
Name: [name]
Description: [description]
Price: [price]
оператор ++ кој има за цел да ја зголеми цената на ставката за 10.
Потоа да се креира класа Invoice во која што ги има следните имформации:

број на фактура (низа од максимум 10 карактери)
низа од ставки (динамички алоцирана низа од InvoiceItem)
број на ставки (број на елементи во низата, цел број)
Да се креираат:
конструктор со еден параметар (број на фактура)
деструктор
функција totalPrice() што го пресметува вкупниот збир на сите ставки во фактурата
Дополнително да се преоптовари следниот оператор:

оператор += за додавање на ставка во фактурата
оператор << за печатење на сите ставки во една фактура во форматот:
Invoice Items:
Name: [inv_item_1_name]
Description: [inv_item_1_name]
Price: [inv_item_1_price]
...
Total invoice price: [totalPrice()]
For example:

Input
3
item1 description1 100
item2 description2 200
item3 description3 300
 
Result
Invoice Items:
Name: item1
Description: description1
Price: 110
Name: item2
Description: description2
Price: 210
Name: item3
Description: description3
Price: 310
Total invoice price: 630
*/

class InvoiceItem{

private:
    char *name;
    char *description;
    int price;

public:
    InvoiceItem(char *name=" ", char *description=" ", int price=0){

        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->description=new char[strlen(description)+1];
        strcpy(this->description, description);
        this->price=price;

    }

    InvoiceItem(const InvoiceItem &ii){
        this->name=new char[strlen(ii.name)+1];
        strcpy(this->name, ii.name);
        this->description=new char[strlen(ii.description)+1];
        strcpy(this->description, ii.description);
        this->price=ii.price;
    }

    InvoiceItem &operator=(const InvoiceItem &ii) {
        if (this != &ii) {
            delete [] name;
            delete [] description;
            this->name = new char[strlen(ii.name) + 1];
            strcpy(this->name, ii.name);
            this->description = new char[strlen(ii.description) + 1];
            strcpy(this->description, ii.description);
            this->price = ii.price;
        }
        return *this;
    }

    ~InvoiceItem(){
        delete [] name;
        delete [] description;
    }

    friend ostream &operator<<(ostream &out, const InvoiceItem &ii){

        out<<"Name: "<<ii.name<<endl;
        out<<"Description: "<<ii.description<<endl;
        out<<"Price: "<<ii.price<<endl;
        return out;
    }

    InvoiceItem &operator ++(){

        price+=10;
        return *this;
    }

    int getPrice() const {
        return price;
    }

};


class Invoice {

private:

    char br_faktura[10];
    InvoiceItem *items;
    int broj_stavki;

public:

    Invoice(char *br_faktura=" "){

        strcpy(this->br_faktura, br_faktura);
        items=0;
        this->broj_stavki=0;
    }

    Invoice(const Invoice &other){

        strcpy(this->br_faktura, other.br_faktura);
        this->broj_stavki=other.broj_stavki;
        this->items=new InvoiceItem[other.broj_stavki];

    }

    Invoice &operator=(const Invoice &other){

        if(this!=&other) {

            delete [] items;
            strcpy(this->br_faktura, other.br_faktura);
            this->broj_stavki = other.broj_stavki;
            this->items = new InvoiceItem[other.broj_stavki];

        }
        return *this;
    }


    ~Invoice(){
        delete [] items;
    }

    int totalPrice(){
        int vkupno=0;
        for(int i=0;i<broj_stavki;i++){
            vkupno+=items[i].getPrice();
        }
        return vkupno;
    }
    
    Invoice &operator+=(InvoiceItem inv){
        
        InvoiceItem *tmp=new InvoiceItem[broj_stavki+1];
        for(int i=0;i<broj_stavki;i++){
            tmp[i]=items[i];
        }
        tmp[broj_stavki++]=inv;
        delete [] items;
        items=tmp;
        return *this;
        
    }
                                            //ne treba const bidejki dole funkcijata totalPrice e vo ista klasa
    friend ostream &operator<<(ostream &out, Invoice &other){
        out<<"Invoice Items: "<<endl;
        for(int i=0;i<other.broj_stavki;i++){
            
            out<<other.items[i];
            
        }
        
        out<<"Total invoice price: "<<other.totalPrice()<<endl;
        
        return out;
    }

};

int main()
{
    // -- TESTING INVOICE CONSTRUCTOR WITH ONLY ONE PARAMETER
    Invoice invoice("inv001");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char name[100];
        char description[100];
        int price;

        cin >> name;
        cin >> description;
        cin >> price;

        // -- TESTING CONSTRUCTOR WITH PARAMETERS FOR INVOICE ITEM
        InvoiceItem tempParameters = InvoiceItem(name, description, price);

        // --  TESTING COPY CONSTRUCTOR FOR INVOICE ITEM
        InvoiceItem tempCopy(tempParameters);

        // -- TESTING OPERATOR = FOR INVOICE ITEM
        InvoiceItem invoiceItem = tempCopy;

        // -- TESTING OPERATOR ++ FOR INVOICE ITEM
        ++invoiceItem;

        // -- TESTING OPERATOR += FOR INVOICE
        invoice += invoiceItem;
    }

    // -- TESTING OPERATOR << FOR INVOICE
    cout << invoice;

    return 0;
}
