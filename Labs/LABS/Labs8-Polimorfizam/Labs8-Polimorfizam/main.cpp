#include <iostream>
#include <cstring>

using namespace std;

//1va zad
/*
Дизанирате програма за систем за хотелски резервации. За ова ке треба да креирате базична класа наречена Room што претставува генеричка хотелска соба и ги има овие две чисти виртуелни функции:
• display Roominfo0
• display Room Price)
Понатаму, треба да креирате 2 подкласи на Room наречени:
• StandardRoom
• DeluxeRoom
Класата StandardRoom треба да ги има овие информации:
• hasBathroom - bool променлива
и имплементирате ги двете функции погоре со овие имплементации:
• 3a displayRoomInfo0 треба да се печати This is a standard room with a queen-sized bed. Ако собата има и баа, треба да додадете "and a bathroom* на краот од пораката.
• За displayRoom Price() треба да се печати The price for a standard room is [price] per night. каде што цената се пресметува врз основа на тоа дали собата има баа или не. Ако има бана е 100$ а ако не е 80$.
Класата DeluxeRoom треба да ги има овие информации:
• hasBalcony - bool променлива
и имплементирате ги двете функции погоре со овие имплементации:
• 3a displayRoomInfo0 треба да печати This is a deluxe room with a king-sized bed, a bathroom, a mini-fridge. Доколку собата дополнително има и балкон, додадете and a balcony*
на краіот од пораката.
• За displayRoom Price() треба да се печати The price for a deluxe room is [price] per night. каде цената се пресметува врз основа на тоа дали собата има балкон или не. Ако има балкон е 2005 а ако не е 1605.
*/
 
 /*
class Room{
    
public:
    Room(){}
    
    virtual void displayRoomInfo()=0;
    
    virtual void displayRoomPrice()=0;
    
};

class StandardRoom: public Room{
    
private:
    bool hasBathroom;
    
public:
    StandardRoom(bool hasBathroom=false){ //BOOL NA FALSE DA SE STAVA VO KONSTRUKTOR
        this->hasBathroom=hasBathroom;
    }
                            //override
    void displayRoomInfo () {
        
        cout<<"This is a standard room with a queen-sized bed";
        if(hasBathroom){
            cout<<" and a bathroom";
        }
            cout<<".\n";
        
    }
    
    void displayRoomPrice(){
        
        cout<<"The price for a standard room is $";
        if(hasBathroom){
            cout<<"100";
        }
        else {
            cout<<"80";
        }
        cout<<" per night."<<endl;
    }
    
};

class DeluxeRoom : public Room{
    
private:
    bool hasBalcony;
    
public:
    DeluxeRoom(bool hasBalcony=false){
        this->hasBalcony=hasBalcony;
    }
    
    void displayRoomInfo(){
        cout<<"This is a deluxe room with a king-sized bed, a bathroom, a mini-fridge";
        if(hasBalcony){
            cout<<" and a balcony";
        }

            cout<<".\n";
    }
    
    void displayRoomPrice(){
        cout<<"The price for a standard room is $";
        if(hasBalcony){
            cout<<"200";
        }
        else {
            cout<<"160";
        }
        cout<<" per night."<<endl;
    }
    
};

int main() {
    Room* rooms[5];

    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "TEST CASE 1: TESTING STANDARD ROOM CLASS" << endl;

        for (int i = 0; i < 5; i++) {
            rooms[i] = new StandardRoom();
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    } else if (testCase == 2) {
        cout << "TEST CASE 2: TESTING DELUXE ROOM CLASS" << endl;
        for (int i = 0; i < 5; i++) {
            rooms[i] = new DeluxeRoom();
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    } else {
        cout << "TEST CASE 3: TESTING BOTH CLASSES" << endl;
        for (int i = 0; i < 5; i++) {
            if (i % 2) {
                bool hasBalcony;
                cin >> hasBalcony;
                rooms[i] = new DeluxeRoom(hasBalcony);
            }
            else {
                bool hasBathroom;
                cin >> hasBathroom;
                rooms[i] = new StandardRoom(hasBathroom);
            }
            rooms[i]->displayRoomInfo();
            rooms[i]->displayRoomPrice();
        }
    }

    return 0;
}
*/


//2ra ZAD

/*
class FoodItem{
    
protected:
    char *type;
    int num;
    
public:
    
    FoodItem(char *type=" ", int num=0){
        
        this->type=new char[strlen(type)+1];
        strcpy(this->type, type);
        this->num=num;
    }
    
    FoodItem(const FoodItem &fi){
        
            this->type=new char[strlen(fi.type)+1];
            strcpy(this->type, fi.type);
            this->num=fi.num;
    }
    
    FoodItem &operator=(const FoodItem &fi){
        
        if(this!=&fi){
            delete [] type;
            this->type=new char[strlen(fi.type)+1];
            strcpy(this->type, fi.type);
            this->num=fi.num;
        }
        return *this;
    }
    
    ~FoodItem(){
        delete [] type;
    }
    
    virtual int getPrice()=0;
    
    virtual int getTime()=0;
    
};

class Pizza : public FoodItem{
    
private:
    char *dough;
    
public:
    Pizza(char *type=" ", int num=0, char *dough=" ") : FoodItem(type, num){
        this->dough=new char[strlen(dough)+1];
        strcpy(this->dough, dough);
    }
    
    int getPrice(){
        
        if(strcmp(this->dough, "wholeWheat")==0){
            return 250*num;
        }
        else if(strcmp(this->dough, "glutenFree")==0){
            return 350*num;
        }
        else {
            return 0;
        }
    }
    
    int get_Time(){
        return 25;
    }
    
    ~Pizza(){
        delete [] dough;
    }
};

class Steak:public FoodItem{
    
private:
    bool cooked;
    
public:
    Steak(char *type=" ", int num=0, char *dough=" ", bool cooked=false) : FoodItem(type, num){
        
        this->cooked=cooked;
    }
    
    int get_time(){
        if(cooked){
            return 20;
        }
        else if(!cooked){
            return 15;
        }
        else {
            return 0;
        }
    }
    
    int get_cena(){
        return 1300*num;
    }
    
    ~Steak(){}
    
};

FoodItem getMaxFoodItem(FoodItem *pItem [], int n){
    
    FoodItem *item=pItem[0]
    int max_foodprice=pItem[0]->getPrice();
    
    for(int i=0;i<n;i++){
        
        if(pItem[i]->getPrice()>max_foodprice){
            max_foodprice=pItem[i]->getPrice();
            item=pItem[i];
        }
    }
    return item;
}
    

int main() {
    FoodItem *p;
    int n;
    cin>>n;

    char type[30];
    char dough[30];
    bool cooked;
    int size;

    FoodItem *items[n];

    for (int i = 0; i <n; ++i) {
        cin>>type;
        cin>>size;


        if(strcmp(type, "pizza")==0 ) {
            cin>>dough;
            items[i] = new Pizza(type, size, dough);
        }else{
            cin>>cooked;
            items[i] = new Steak(type, size, cooked);
        }


    }

    FoodItem *it = getMaxFoodItem(items, n);
    cout<<"Type: "<<it->getType()<<endl;
    cout<<"The max price is: "<<it->getPrice()<<endl;
    cout<<"Time to cook: "<<it->getTime();
    return 0;
}
*/


//mene sto mis e padna
/*
Треба да се напише класа за спортски реквизити SportsItem која што ги има овие две чисти виртуелни функции:
getPrice() - цена на реквизит
getDiscount() - попуст на реквизит
Исто така, треба класата да ги има следните информации:

name (динамички алоцирана низа од карактери) - име на реквизит
price - цена на реквизитот
Понатаму, треба да креирате 2 подкласи на SportsItem наречени:

Jersey
Equipment
Класата Jersey треба да ги има овие информации:

team (динамички алоцирана низа од карактери) - од кој тим е дресот
Цена на еден дрес:
- За тим Lakers : +450 од обичната цена
- За тим Celtics : +350 од обичната цена

Попустот за секој купен дрес е 20%. Во вкупната цена на дресот се зема предвид и попустот.

Класа Equipment треба да ги има овие информации:

isProfessional (boolean) - дали е професионален
Доколку реквизитот е професионален има 10% попуст, инаку има 25% попуст. Во вкупната цена на реквизитот се зема предвид и попустот.

Треба исто така да напишете глобална функција:

getMaxSportsItem(SportsItem *sItem[], int n) , која што ќе враќа покажувач до најскапиот SportsItem
 
 input
 4
 jersey Jersey1 1200 Lakers
 equipment Equipment1 1000 1
 jersey Jersey2 1500 Celtics
 equipment Equipment2 600 0
 
 output
 SPORTS ITEMS:
 ============================
 Item: Jersey1
 Price: 1320

 Item: Equipment1
 Price: 900

 Item: Jersey2
 Price: 1480

 Item: Equipment2
 Price: 450

 MOST EXPENSIVE SPORTS ITEM:
 ============================
 Item: Jersey2
 Price: 1480
 
 */

class SportsItem{
    
protected:
    char *name;
    int price;
    
public:
    virtual float getPrice() = 0;
    
    virtual float getDiscount() = 0;
    
    SportsItem(char *name, int price=0){
        
        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->price=price;
        
    }
    
    SportsItem(const SportsItem &si){
          this->name=new char[strlen(si.name)+1];
          strcpy(this->name, si.name);
          this->price=si.price;
      }
    
    SportsItem &operator=(const SportsItem &si){
            if(this!=&si) {
                delete [] name;
                this->name = new char[strlen(si.name) + 1];
                strcpy(this->name, si.name);
                this->price = si.price;
            }
            return *this;
        }

        ~SportsItem(){
            delete [] name;
        }

    char *getName() {
            return name;
        }
    
};

class Jersey: public SportsItem{
    
private:
    char *team;
    
public:
    Jersey(char *name=" ", int price=0, char *team=" "):SportsItem(name,price){
        
        this->team=new char[strlen(team)+1];
        strcpy(this->team, team);
        
    }
    
    Jersey(const Jersey &j):SportsItem(name,price){
            this->team=new char[strlen(j.team)+1];
            strcpy(this->team, j.team);
        }

    Jersey &operator=(const Jersey &j) {
        if (this != &j) {
            this->team = new char[strlen(j.team) + 1];
            strcpy(this->team, j.team);
        }
        return *this;
        }

        ~Jersey(){
            delete [] team;
        }
    
                //override
    float getPrice(){
        if(strcmp(this->team, "Lakers")==0){
            return 450+price;
        }
        else if(strcmp(this->team, "Celtics")==0){
            return 350+price;
        }
        else {
            return 0;
        }
    }
    
                    //override
    float getDiscount(){
        return 20;
    }
    
};

class Equipment:public SportsItem{
    
private:
    bool isProfessional;
    
public:
    Equipment(char *name=" ", int price=0, bool isProfessional=false):SportsItem(name,price){
        
        this->isProfessional=isProfessional;
        
    }
    
    
//    float get_discount(){
//
//        if(isProfessional==1){ //dokolku rekvizitot e profesionalen
//            return 10;
//        }
//        else {
//            return 25;
//        }
//
//    }
    
    float getDiscount()
        {
            if(isProfessional==1)
                return (10*price)/100;
            else
                return (25*price)/100;
        }
    
    
        float getPrice()
        {
            return price-getDiscount();
        }
    
};

SportsItem *getMaxSportsItem(SportsItem *sItem[], int n){
    
    SportsItem *max = sItem[0];
    
    for(int i=0;i<n;i++){
        
        if(sItem[i]->getPrice()>max->getPrice()){
            max=sItem[i];
        }
    }
    return max;
    
    
    //i vaka moze
//        int max=0;
//        SportsItem *item;
//
//
//        for(int i=0;i<n;i++){
//
//            if(sItem[i]->getPrice()>max){
//                max=sItem[i]->getPrice();
//                item=sItem[i];
//            }
//
//        }
//        return item;
    
}


int main() {
    SportsItem *p;
    int n;
    cin>>n;

    char type[30];
    char name[30];
    int price;
    bool isProfessional;
    char team[30];

    SportsItem *items[n];

    for (int i = 0; i <n; ++i) {
        cin>>type>>name>>price;

        if(strcmp(type, "jersey")==0 ) {
            cin>>team;
            items[i] = new Jersey(name, price, team);
        }else{
            cin>>isProfessional;
            items[i] = new Equipment(name, price, isProfessional);
        }

    }

    cout<<"SPORTS ITEMS: "<<endl;
    cout<<"============================"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Item: "<<items[i]->getName()<<endl;
        cout<<"Price: "<<items[i]->getPrice()<<endl;
        cout<<endl;
    }

    cout<<"MOST EXPENSIVE SPORTS ITEM: "<<endl;
    cout<<"============================"<<endl;

    SportsItem *it = getMaxSportsItem(items, n);
    cout<<"Item: "<<it->getName()<<endl;
    cout<<"Price: "<<it->getPrice()<<endl;
    return 0;
}

