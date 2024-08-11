#include <iostream>
#include <cstring>

using namespace std;

/*
Да се состави класа за автомобил со млазен погон кој наследува својства од две класи, автомобил и млазен авион (дијамант проблем).
*/

/*
class Vehicle{
    
protected:
    int acceleration;
    
public:
    Vehicle(){
        acceleration=0;
        cout<<"Vehicle constructor called "<<endl;
    }
    
    //cim e virtuelen ke go preoptovarime - override
    //override - daden metod od klasa go preoptovaruvame vo izvedenite klasi
    virtual void accelerate(){
        cout<<"Vehicle acceleration called"<<endl;
        acceleration++; //go zgolemuva zabrzuvanjeto
    }
    
    ~Vehicle(){
        cout<<" Vehicle destructor called"<<endl;
    }
};

class Car:virtual public Vehicle{
    
public:
  
    Car(){
        cout<<"Car constructor called"<<endl;
    }
    
    void accelerate(){
        
        cout<<"Car acceleration called"<<endl;
        //2 pati go povkiuvame od base class
        //isto kako accelerate+=2;
        Vehicle::accelerate();
        Vehicle::accelerate();
    }
    
    virtual void drive(){
        cout<<"Car is driving"<<endl;
    }
    
    ~Car(){
        cout<<"Car destructor called"<<endl;
    }
    
    int getAcceleration(){
        return acceleration;
    }
    
};

class Jet:virtual public Vehicle{
    
public:
    Jet(){
        cout<<"Jet constructor called"<<endl;
    }
    
//    virtual void accelerate(){
//
//        cout<<"Jet acceleration called"<<endl;
//        acceleration+=50;
//    }
    
    virtual void fly(){
        cout<<"Jet is flying"<<endl;
    }
    
    ~Jet(){
        cout<<"Jet destructor called"<<endl;
    }
    
};

//i Jet i Car - nasleduva i od Car i od Jet
class JetCar : public Car, public Jet{
    
public:
    JetCar(){
        cout<<"JetCar constructor called"<<endl;
    }
    
    ~JetCar(){
        cout<<"JetCar destructor called"<<endl;
    }
    
    void fly(){
        cout<<"JetCar is flying";
    }
    
};

int main(){
    
//    Car car;
//    car.drive();
//    car.accelerate();
//    cout<<car.getAcceleration();
//
//    prvo konstruktoro na klasata Vehicle - base class
//    vtoro konstruktorot na klasata Car
//    so metodot car.drive se povikuva car is driving;
//    pa so metodot car acceleration se povikuva Car acceleration
//    pa so override 2 pati se povikvuva vehicle acceleration
//    na kraj destruktorite se povikuvaat na Car-izvedenata klasa, pa na base class- Vehicle

    
//    Vehicle constructor called
//    Car constructor called
//    Car is driving
//    Car acceleration called
//    Vehicle acceleration called
//    Vehicle acceleration called
//    2Car destructor called
//     Vehicle destructor called

    JetCar jetCar;
    jetCar.fly();
    jetCar.drive();
    jetCar.accelerate(); //sega so virtual na dvete klasi Vehicle se povkiva ednas , potoa Car i Jet i na kraj JetCar se povikuvame
    //isto so destruktorot - od dole kon gore - JetCar prvo, pa Jet destruktorot, pa Car pa Vehicle

//    Vehicle constructor called
//    Car constructor called
//    Jet constructor called
//    JetCar constructor called
//    JetCar is flyingCar is driving
//    Car acceleration called
//    Vehicle acceleration called
//    Vehicle acceleration called
//    JetCar destructor called
//    Jet destructor called
//    Car destructor called
//     Vehicle destructor called
    
    
    //    cout << jetCar.getAcceleration() << endl;
    //tuka e problemot bidejki vo JetCar accelerate go imame od 2 osnovni klasi-Car i Jet I NEMA IDEA KOJ DA GO POVIKA OD TIE 2 - ambigious e
    
    return 0;
}

//prvo Vehicle konstruktorot se povikuva - base class, pa konstruktort na Car se povkiuva, potoa deka naselduva i d od Jet klasata, VEHICLE konstruktorot SE POVIKUVA USTE EDNAS, PA JET KONSTRUKTOROT SE POVIKUVA i NA KRAJ SE POVIKUVA JETCAR KONSTRUKTOROT.

//za unistuvanje na objektite - Pocnuvame od DOLE KON GORE  - JETCAR destruktor, JET destruktor, Vehicle Destruktor, Car destruktor, pa Vehicle destruktor
    
//PROBLEM E BIDEJKI NEMA POTREBA 2 PATI DA SE POVIKUVA KONSTRUKTOROT NA KLASATA VEHICLE I 2 PAT I 2 PATI DA SE POVIKUVA DESTRUKTOROT
//SE RESAVA SO KE BIDE I VIRTUELNO PUBLIC NASELDUVANJETO
//virtual public Car i virtual public Jet

//Vehicle constructor called
//Car constructor called
//Vehicle constructor called
//Jet constructor called
//JetCar constructor called
//JetCar is flyingCar is driving
//JetCar destructor called
//Jet destructor called
// Vehicle destructor called
//Car destructor called
// Vehicle destructor called

*/


/*
Да се имплементира класа Product за која се чуваат името и цената. Да се
имплементира апстрактна класа Discount во која има два чисто виртуелни
методи за цена и за цена со попуст. Од овие класи да се изведат класите:
• FoodProduct за која дополнително се чува бројот на калории;
• DigitalProduct за која дополнително се чува големината (во MB)
Да се имплементира надворешна функција total_discount која ќе пресметува
вкупен попуст на неколку продукти на попуст кои ги прима како аргумент.
*/


class Product{
    
protected:
    char name[50];
    float price;
    
public:
    Product(char *name=" ", float price=0.0){
        
        strcpy(this->name, name);
        this->price=price;
    }
    
};

class Discount{ //interface - dava pristap do nekakvi metodi
    
public:
    virtual float getPrice()=0;
    
    virtual float getPriceWithDiscount()=0;
    
    virtual void print()=0;
};

class FoodProduct:public Product, public Discount{
  
private:
    int calories;
    
public:
    FoodProduct(char *name=" ", float price=0.0, int calories=0) : Product(name,price){
        
        this->calories=calories;
    }
    
    float getPrice(){
        return price;
    }
    
    float getPriceWithDiscount(){
        if(calories>500){
            return 0.8*price;
        }
        else if(calories>100){
            return 0.9*price;
        }
        else {
            return 0.95*price;
        }
    }
    
    void print(){
        cout<<"FoodProduct" <<name<<" Price: "<< getPrice()<<" Price with discount: "<< getPriceWithDiscount();
    }
    
};


class DigitalProduct:public Product, public Discount{
  
private:
    int MB;
    
public:
    DigitalProduct(char *name=" ", float price=0.0, int MB=0) : Product(name,price){
        
        this->MB=MB;
    }
    
    float getPrice(){
        return price;
    }
    
    float getPriceWithDiscount(){
        if(MB>1024){
            return 0.7*price;
        }
        else if(MB>512){
            return 0.85*price;
        }
        else {
            return 0.925*price;
        }
    }
    
    void print(){
        cout<<"DigitalProduct" <<name<<" Price: "<< getPrice()<<" Price with discount: "<< getPriceWithDiscount();
    }
    
};

float total_discount(Discount **d, int n){
    
    float total_discount=0.0;
    
    for(int i=0;i<n;i++){
        total_discount+=(d[i]->getPrice()-d[i]->getPriceWithDiscount());
    }
    
    return total_discount;
}

int countFoodProducts(Discount **discountedProducts, int n){
    int brojac=0;
    for(int i=0;i<n;i++){
        FoodProduct *fp = dynamic_cast<FoodProduct*>(discountedProducts[i]);
        if(fp!=0){
            brojac++;
        }
    }
    return brojac;
}

int main(){
    
    int n;
    cin>>n;
    
    Discount **discountedProducts=new Discount *[n]; //discount bidejki mora da iamme pristap do metodite
    
    for(int i=0;i<n;i++){
        int type;//1-food, 2-digital
        char name[50];
        float price;
        int MB;
        int calories;
        cin>>type;
        if(type==1){
            cin>>name>>price>>calories;
            discountedProducts[i]=new FoodProduct[name, price, calories];
        }
        else {
            cin>>name>>price>>MB;
            discountedProducts[i]=new DigitalProduct[name, price,MB];
        }
    }
    
    for(int i=0;i<n;i++){
        discountedProducts[i]->print();
    }
    
    cout<<"Total discount for the products is: "<<total_discount(discountedProducts, n);
    
    cout<<"Total number of food products is: "<<countFoodProducts(discountedProducts, n);

    
    return 0;
}



