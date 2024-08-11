#include <iostream>
#include <string.h>

using namespace std;

/*
Да се дефинира класа Film во која ќе се чуваат информации за:
name(низа од максимум 100 карактери) -име на филмот
rating (децимален број) - рејтинг на филмот
revenue(децимален број) - колку заработил филмот во милиони долари

Сите променливи внатре во класата треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:

конструктор (без и со параметри)
деструктор
set методи
get методи

Да се дефинираат следните методи во класата:
display() која што ќе ги печати информациите за сметката во следниот формат:
Name of film: …
Rating: …
Revenue: …

Надвор од класата:

printMostPopularFilm(Film *films, int n) која што ќе го најде филмот со најголема заработувачка,

ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА
 
 Input
 10
 Inception 8.8 828.3
 Titanic 7.8 2187.5
 Avatar 7.8 2787.9
 Jaws 8.0 470.7
 Rocky 8.1 225.0
 Grease 7.2 394.5
 Alien 8.4 1043.4
 Jumanji 7.0 962.1
 Gladiator 8.5 460.5
 Memento 8.4 39.7
 
 Output
 -->Testing set methods and display()
 Name of film: Memento
 Rating: 8.4
 Revenue: 39.7

 -->Testing printMostPopularFilm()
 Name of film: Avatar
 Rating: 7.8
 Revenue: 2787.9
 
 */

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



//COUNTRY

//Да се дефинира класа Country во коа ке се чуваат информации за:
//• пате(низа од максимум 100 карактери) име на джавата
//• capital(низа од максимум 100 карактери) главен град
//• area(децимален бро) - површина во илада km?
//• population(децимален бро) - популациа во милиони.
//Сите променливи внатре во класата треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:
//• конструктор (без и со параметри)
//• деструктор
//• set методи
//• get методи
//Да се дефинираат следните методи во класата:
//• display0 коа што ке ги печати информациите за сметката во следниот формат:

//Country: Guyana
//Capital: Georgetown
//Area: 214
//Population: 0.8

//Надвор од класата:
//• sortCountries(Country *countries, int n) коа што ке ги сортира државите растечки по нивната површина.

class Country
{
    char ime[100];
    char glavengrad[100];
    float povrsina;
    float naselenie;
    
public:
    Country() {}
 
    Country(char *i,char *gg,float povrs,float nas)
    {
        strcpy(ime,i);
        strcpy(glavengrad,gg);
        povrsina=povrs;
        naselenie=nas;
    }
    
    ~Country(){
    }

    void setime(char *i)
    {
        strcpy(ime,i);
    }
    
    void setglavengrad(char *gg)
    {
        strcpy(glavengrad,gg);
    }
    
    void setpovrsina(float povrs)
    {
        povrsina=povrs;
    }
    
    void setnaselenie(float nas)
    {
        naselenie=nas;
    }
    
    
    char *getime()
    {
        return ime;
    }
    
    char *getglavengrad()
    {
        return glavengrad;
    }
    
    float getpovrsina()
    {
        return povrsina;
    }
    
    float getnaselenie()
    {
        return naselenie;
    }

    void display(Country a[],int n)
    {
        for (int i = 0; i < n; ++i) {
            cout<<"Country: "<<a[i].ime<<endl;
            cout<<"Capital: "<<a[i].glavengrad<<endl;
            cout<<"Area: "<<a[i].povrsina<<endl;
            cout<<"Population: "<<a[i].naselenie<<endl;
        }
    }
};

void sortCountries(Country a[],int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) { //n-1
            if(a[i].getpovrsina()>a[j].getpovrsina())
            {
                Country temp = a[i];
                a[i]= a[j];
                a[j]= temp;
            }
        }
    }
    
//    for(i=0;i<n-1;i++){
//        for(j=i+1;j<n;j++){
//            if(books[i].getYear()>books[j].getYear()){
//                temp=books[j];
//                books[j]=books[i];
//                books[i]=temp;
//
//            }
//        }
//    }
    
    for (int i = 0; i < n; ++i) {
        cout<<"Country: "<<a[i].getime()<<endl;
        cout<<"Capital: "<<a[i].getglavengrad()<<endl;
        cout<<"Area: "<<a[i].getpovrsina()<<endl;
        cout<<"Population: "<<a[i].getnaselenie()<<endl;
    }
}




//DADENA MAIN FUNKCIJA

int main() {
    int n;
    cin >> n;
    Country c[100];

    char name[100];
    char capital[100];
    double area;
    double population;

    for (int i = 0; i < n-1; i++)  {
        cin>>name;
        cin >> capital;
        cin >> area;
        cin>>population;

        // testing constructor with arguments
        c[i] = Country(name, capital, area, population);

    }


    // testing set methods and display for last element
    cin>>name;
    cin >> capital;
    cin >> area;
    cin>>population;
    c[n-1].setime(name);
    c[n-1].setglavengrad(capital);
    c[n-1].setpovrsina(area);
    c[n-1].setnaselenie(population);

    cout<<"-->Testing set methods and display()"<<endl;
    c[n-1].display(c,n);
    cout<<endl;

    cout<<"-->Testing sortCountries()"<<endl;
    sortCountries(c,n);
    return 0;
}



//STO MI SE PADNAA

//ZAD1
/*
Да се креира класа BasketballPlayer која ќе ги чува следните информации:
име на кошаркарот (низа од знаци не подолга од 20 карактери)
презиме на кошаркарот (низа од знаци не подолга од 20 карактери)
број на дрес (цел број)
поени од прв натпревар (цел број)
поени од втор натпревар (цел број)
поени од трет натпревар (цел број)
Да се направат потребните методи за класата, како и метод за печатење на информации за кошаркарот во следен формат "Player: name surname with number: number has avg_pts points on average".

Од стандарден влез се внесуваат име, презиме, број на дрес и поени за сите три натпревари за еден кошаркар.

На стандарден излез се печатат информациите за кошаркарот.

For example:

Input    Result
Marko    Player: Marko Petrov with number: 10 has 14 points on average
Petrov
10
13
14
15
*/




/*
Да се дефинира класа Производ во која се чуваат информации за:

име на производ
основна цена на производ
ДДВ (изразено во %)
попуст (изразен во %)
Сите променливи треба да бидат приватни.

Во класата да се реализираат:

default конструктор и конструктор со аргументи
set и get методи
метод за пресметување на крајна цена на производ(основна цена со ДДВ)
метод за пресметување на крајна цена на производ заедно со попустот(крајна цена со попуст)
метод за печатење на производ во формат: Име -> крајна цена
Надворешна функција void productToPrint(Product *products, int n) која ќе го испечати најскапиот производ (според цена со попуст) во формат:
    Име -> крајна цена

Да не се менува main функцијата.
*/

/*
class Product{

private:

    char ime_proizvod[20];
    int cena_proizvod;
    double ddv;
    double popust;

public:

    Product(){}

    Product(char *name, int cena, double d, double p){

       strcpy(ime_proizvod,name);
        cena_proizvod=cena;
        ddv=d;
        popust=p;
    }

    ~Product(){}

    void setName(char *name){
        strcpy(ime_proizvod,name);
    }

    void setPrice(int cena){
        cena_proizvod=cena;
    }

    void setDDV(double d){
        ddv=d;
    }

    void setDiscount(double p){
        popust=p;
    }

    char *getName(){
        return ime_proizvod;
    }

    int getCena(){
        return cena_proizvod;
    }

    double getDDV(){
        return ddv;
    }

    double getDiscount(){
        return popust;
    }
    
    double finalPrice(){
        
        return cena_proizvod+(ddv*cena_proizvod)/100;
    }
    
    double priceWithDiscount(){
        return finalPrice()-(popust*finalPrice())/100;
    }
    
    void print(){
        cout<<ime_proizvod<<" -> "<<finalPrice()<<endl;
    }

};

void productToPrint(Product *products, int n){
    
    int max=0, max_i=0,i;
    
    for(i=0;i<n;i++){
        if(products[i].priceWithDiscount()>max){
            max=products[i].priceWithDiscount();
            max_i=i;
        }
    }
    cout<<products[max_i].getName()<<" -> "<<products[max_i].finalPrice()<<endl;
    //products->print();
}


int main()
{
    int m, n;
    cin>>m>>n;
    if(m==1)
    {
        cout<<"TESTING CONSTRUCTOR WITH ARGUMENTS AND PRINT METHOD"<<"\n";
        char name[100]={'a', 'p', 'p', 'l', 'e'};
        Product p1=Product(name, 100, 18, 10);
        p1.print();
    }
    else if(m==2)
    {
        cout<<"TESTING GET, SET, FINAL PRICE AND PRICE WITH DISCOUNT"<<"\n";
        Product p2;
        char name[100]={'a', 'p', 'p', 'l', 'e'};
        p2.setName(name);
        p2.setPrice(100);
        p2.setDDV(18);
        p2.setDiscount(10);
        cout<<"Name: "<<p2.getName()<<"\n";
        cout<<"Final price: "<<p2.finalPrice()<<"\n";
        cout<<"Price with discount: "<<p2.priceWithDiscount()<<"\n";
    }
    else if(m==3)
    {
        Product products[100];
        for(int i=0; i<n; i++)
        {
            char name[100];
            int price, ddv, discount;
            cin>>name;
            cin>>price>>ddv>>discount;
            products[i].setName(name);
            products[i].setPrice(price);
            products[i].setDDV(ddv);
            products[i].setDiscount(discount);
        }
        cout<<"TESTING PRODUCTTOPRINT FUNCTION"<<"\n";
        productToPrint(products, n);
    }
    return 0;
}
*/


/*
Да се дефинира класа Книга за која се чуваат следните информации:

име на книга (низа од максимум 100 карактери)
име на автор (низа од максимум 100 карактери)
презиме на автор (низа од максимум 100 карактери)
ISBN (низа од максимум 100 карактери)
година на издавање (цел број)
Сите променливи треба да бидат приватни.
 Дополнително во класата да се реализираат:

default конструктор и конструктор со аргументи
set методи
get методи
display() метод за печатење на книга во формат:
Име на книга, автор на книга, ISBN
Да се дефинира надворешна функција void booksByOrder(Book *books, int n) која на екран ќе ги испечати сите книги сортирани според година на издавање (прва се печати книгата што е издадена најрано).
Да не се менува main функцијата.
*/

/*
class Book{

private:
    char ime_kniga[100];
    char ime_avtor[100];
    char prezime_avtor[100];
    char ISBN[100];
    int god_izdavanje;
    
public:
    
    Book(){}
    
    Book(char *ime_k, char *ime_av, char *prezime_av, char *isbn, int god_izd){
        
        strcpy(ime_kniga, ime_k);
        strcpy(ime_avtor, ime_av);
        strcpy(prezime_avtor, prezime_av);
        strcpy(ISBN, isbn);
        god_izdavanje=god_izd;
    }
    
    ~Book(){}
    
    void setBookName(char *ime_k){
        strcpy(ime_kniga, ime_k);
    }

    void setAuthorName(char *ime_av){
        strcpy(ime_avtor, ime_av);
    }

    void setAuthorSurname(char *prezime_av){
        strcpy(prezime_avtor, prezime_av);
    }
    
    void setISBN(char *isbn){

        strcpy(ISBN, isbn);
    }
    
    void setYear(int god_izd){
        god_izdavanje=god_izd;
    }
    
    char *getBookName(){
        
        return ime_kniga;
    }

    char *getAuthorName(){

        return ime_avtor;
    }

    char *getAuthorSurname(){

        return prezime_avtor;
    }
    
    char *getISBN(){
        return ISBN;
    }
    
    int getYear(){
        return god_izdavanje;
    }
    
    void display(){
        
        cout<<ime_kniga<<", "<<ime_avtor<<" "<<prezime_avtor<<", "<<ISBN<<endl;
        
    }
};

void booksByOrder(Book *books, int n){
    
    Book temp;
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(books[i].getYear()>books[j].getYear()){
                temp=books[j];
                books[j]=books[i];
                books[i]=temp;
                
            }
        }
    }
    
    for(i=0;i<n;i++){
        books[i].display();
    }
    
}



int main()
{
    int m, n;
    cin>>m>>n;
    if(m==0)
    {
        cout<<"---Testing constructor with arguments and display()---"<<"\n";
        char name[100]={'H', 'a', 'm', 'l', 'e', 't'};
        char aN[100]={'W', 'i', 'l', 'l', 'i', 'a', 'm'};
        char aS[100]={'S', 'h', 'a', 'k', 'e', 's', 'p', 'e', 'a', 'r', 'e'};
        char isbn[100]={'I', 'S', 'B', 'N', '1', '2', '3', '4'};
        Book b=Book(name, aN, aS, isbn, 1847);
        b.display();
    }
    else if(m==1)
    {
        cout<<"---Testing get and set methods---"<<"\n";
        char name[100]={'H', 'a', 'm', 'l', 'e', 't'};
        char aN[100]={'W', 'i', 'l', 'l', 'i', 'a', 'm'};
        char aS[100]={'S', 'h', 'a', 'k', 'e', 's', 'p', 'e', 'a', 'r', 'e'};
        char isbn[100]={'I', 'S', 'B', 'N', '1', '2', '3', '4'};
        Book b;
        b.setYear(1847);
        b.setISBN(isbn);
        b.setAuthorSurname(aS);
        b.setAuthorName(aN);
        b.setBookName(name);
        cout<<"Name: "<<b.getBookName()<<"\n";
        cout<<"Author: "<<b.getAuthorName()<<" "<<b.getAuthorSurname()<<"\n";
        cout<<"ISBN: "<<b.getISBN()<<"\n";
        cout<<"Year: "<<b.getYear()<<"\n";
    }
    else if(m==2)
    {
        Book books[100];
        for(int i=0; i<n; i++)
        {
            char name[100], aN[100], aS[100], isbn[100];
            int year;
            cin>>name;
            cin>>aN;
            cin>>aS;
            cin>>isbn;
            cin>>year;
            books[i]=Book(name, aN, aS, isbn, year);
        }
        cout<<"---Testing order function---"<<"\n";
        booksByOrder(books, n);
    }
    return 0;
}
*/
