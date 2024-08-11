#include <iostream>
#include <cstring>

using namespace std;

//ISKLUCOCI SE FRLAAT SEKOGAS KOGA KE IMA NESOODVETNO ODNESUVANJE
//SE POTREBNI ZA NESOOSDVETNI COVECKI AKCII - AKO VNESEME NESTO GRESNO ILI SL.

//za isklucocite sekogas klasa treba

/*
class NotValidUsernameException{
  
private:
    char notValidEmail[50];
    
public:
    NotValidUsernameException(char *email="test@test.com"){
        strcpy(notValidEmail, email);
    }
    void showMessage(){ //ke se pojavi poraka koga korisnikot ke napravi nevalidna akcija
        cout<<notValidEmail<<"is not valid! TRY AGAIN"<<endl;
    }
    
};

class User{

protected:
    int id;
    char username[50];
    static int ID_TRACKER; //statickite promenlivi se pisuvaat so golemi bukvi i so _
    //ovoj tracker ke se zgolemuva sekogas koga ke se povikuvaat konstruktorite

public:
    User (char * username = "test", int id = 0) {
        //prvo vo konstruktorot ke proverime dali ima meil ili . vo user - PRIMER
        bool atSignFound = false;
        bool dotSignFound = false;
        for(int i=0;i<strlen(username);i++){
            if(username[i]=='@'){
                atSignFound=true;
            }
            if(atSignFound){
                if(username[i]=='.'){
                    dotSignFound=true;
                }
            }
        }
        
        //EXCEPTION-OT go frlame vo konstruktorot
        
        //se frla isklucok dokolku edno od ovie 2 e USTE FALSE - dokoklu ne sme nasle @ ili . - togas se frla isklucokot bidejki userot ne se odnesuva kako sto treba so sistemot.
        
        //frlanje isklucok
        if(!atSignFound || !dotSignFound){
            throw NotValidUsernameException(username); //objekt od NotValid...
        }
        
        strcpy (this->username, username);
        this->id = ID_TRACKER++; //prviot objekt ke bide 1 i edinicata ke se zgolemi na 2, pa na 3ka ...
        
    }

    void print(){
        cout<< id << " "<<username<<endl;
    }

};

int User::ID_TRACKER = 1; //ja inicijaliziram na 1 od klasata USER

//static clenovite koi se deklarirani za 1 klasa se isti za site objekti od taa klasa

int main(){

    //3te linii opasni mesta za isklucokot
    //vo ovie 3 mesta korisnikot moze da vnese nesto so ne treba - METODI
    
    //so isklucoci se spravuvame so TRY and CATCH
    //opasniot del od kodot go zaobikoluvame so try
    try{
        User u1 ("stefan"); // ID = 1
        User u2 ("trajce"); // ID = 2
        User u3 ("petko"); // ID = 3
    
        u1.print();
        u2.print();
        u3.print();
        
    }
    
    //naveduvame vo catch kakov exception ke fatime
    catch(NotValidUsernameException e){
        e.showMessage();
    }

    return 0;
}
*/


//ZADACA 3 - AUD
/*
Дел од производите во една продавница по новата политика на продавницата
мора да имаат одреден попуст. За таа цел во системот на продавницата
потребно е да се моделира апстрактната класа Discount. Оваа класа како
податок ги има курсевите на евра и долари во денари и методите кои мора
секоја класа што ќе наследи од неа да ги имплементира:

float discount_price();

float price();

void print_rule();
 
За секој производ треба да се чуваат информации за името и цената на
производот. Со ова треба да се моделира класата Product. Во неа покрај
конструкторите треба да се имплементираат сите потребни методи.
Производите се поделени на неколку типови: FoodProduct, Drinks и
Cosmetics.
Според новата политика на продавницата храната нема попуст. Пијалоците и
тоа алкохолните поскапи од 20 евра имаат попуст 5%, а неалкохолните од
брендот Coca-Cola имаат попуст од 10%. Сите козметички производи поскапи од
5 евра имаат попуст 12%, а оние поскапи од 20 долари имаат попуст 14%.
Да се пресмета вкупната цена на сите производи заедно со попустот.
Исто така да се креира функција changePrice(float) во класата Product која
што ќе нуди можност за промена на постоечката цена на производот. Ако се
направи обид да се внесе негативна вредност за цената да се фрли исклучок
(објект од класата NegativeValueException). Фатете го исклучокот во главната
функција каде што ќе ги излистате сите производи од тип Cosmetics и ќе им ја
промените цената.
*/

class NegativeValueException{
    
private:
    char productName[50];
    
public:
    NegativeValueException(char *productName=" "){
        
        strcpy(this->productName, productName);
    }

    void showMessage(){
        cout<<"The product"<<productName<<"cannot have a negative value for the price "<<endl;
    }
    
};

class Discount{
    
public:
    Discount(){
        
    }
    
    static float EUR_TO_MKD;
    static float USD_TO_MKD;
    
    virtual float discount_price() = 0;

    virtual float get_price() = 0;
    
    virtual void print_rule() = 0;
    
};

float Discount::EUR_TO_MKD=61.5;
float Discount::USD_TO_MKD=55.5;

class Product {
protected:
    char name [50];
    float price;
public:
    Product (char *name = "", float price = 0.0) {
        strcpy(this->name, name);
        this->price = price;
    }
    
    void changePrice(float newPrice){
        if(newPrice<0){ //ako nekoj saka ad vnese negativna cena  ke frlime isklucok
            throw NegativeValueException(); //default konstruktor ima
        }
        this->price=newPrice;
    }
    
};


class FoodProduct : public Product, public Discount{
    
public:
    FoodProduct(char *name = "", float price = 0.0) : Product(name, price){
        
    }
    
    float discount_price(){
        return get_price();
    }

    float get_price(){
        return price * Discount::EUR_TO_MKD;//cenata saka da se vrati
    }
    
    void print_rule(){
        cout<<"No discount for food products"<<endl;
    }
};

class Drinks : public Product, public Discount{
private:
    bool isAlcohol;
    
public:
    Drinks(char *name = "", float price = 0.0, bool isAlcohol=false) : Product(name,price){
        
        this->isAlcohol=isAlcohol;
    }
    
    float discount_price(){
        if(isAlcohol && price>20.0){
            return get_price() *0.95;
        }
        if(!isAlcohol && strcmp(name, "coca-cola")==0){
            return get_price()*0.9;
        }
        return get_price();
    }
    
    float get_price(){
        return price*Discount::EUR_TO_MKD;
    }
    
    void print_rule(){
        cout<<"No discount for drink products"<<endl;

    }
    
};

class Cosmetics: public Product, public Discount{
    
public:
    Cosmetics(char *name = " ", float price = 0.0, bool isAlcohol=false) : Product(name,price){
        
    }
    
    float discount_price(){
        float priceInUSD = price * Discount:: EUR_TO_MKD / Discount:: USD_TO_MKD;
        if (priceInUSD>20.0) {
        return get_price() *0.86;
        }
        if (price > 5.0) {
        return get_price() *0.88;
        }
        return get_price ();
    }

    float get_price(){
        return price * Discount::EUR_TO_MKD;//cenata saka da se vrati
    }
    
    void print_rule(){
        cout << "price is USD > 20$ -> 14%; price in EUR > SEUR -> 12%" << endl;
    }
    
    
};


int main (){
    
//    Product *p = new FoodProduct("leb", 0.5);
//
//    //kajsto go povikam changePrice tamu ke go fatam isklucokot
//    try{
//        //ovoj kod e problematicen
//        p->changePrice(-5); //NEGATTIVNA CENA
//
//    } catch(NegativeValueException e){
//        e.showMessage();
//    }
    
    int n=0;
    Discount **d = new Discount* [10];
    
    //cosmetics products - set price to negative value
    
    for(int i=0;i<n;i++){
        Cosmetics *c = dynamic_cast<Cosmetics*>(d[i]); //d od [i] objektot
        if(c!=0){
            int newPrice;
            cin>>newPrice;
            try{
                c->changePrice(newPrice);
            }
            catch(NegativeValueException e){
                e.showMessage();
            }
        }
    }
    
    return 0;
}
