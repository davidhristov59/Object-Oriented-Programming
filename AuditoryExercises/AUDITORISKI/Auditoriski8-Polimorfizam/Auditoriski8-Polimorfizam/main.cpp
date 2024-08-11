#include <iostream>
#include <cstring>

using namespace std;

//PRIMER

/*
Да се дефинира класа за репрезентација на публикација. За секоја публикација
се чуваат информации за годината на издавање (цел број) и за називот на
издавачката куќа (низа од знаци).
Од класата публикација да се изведе (public) класа за книга. За секоја книга
дополнително треба да се чува и бројот на страници на книгата.
Од класата публикација да се изведе (protected) класа за весник. За весник се
чува редниот број на весникот.
Од класата весник да се изведе (private) класа за дневен весник. За секој дневен
весник се чува информација за денот и месецот на издавање на весникот.
Со разни функции да се испита пристапот до податоците и функциите!
*/
 
/*
 class Publikacija{
    
 private:
     char naziv[100];
     
 protected:
     int godina;
     //se pravi get za da imame pristap do naziv
     char *getNaziv(){ //get metod za koristenje na kreiranje na objekti od klasa Publiakcija
         return naziv;
     }
     
 public:
     
     int getGodina(){
         return godina;
     }
     
     void pecati(){
         cout<<" Publikacija: "<<naziv<<" - "<<godina<<endl;
     }
    
     Publikacija(char *naziv,int godina){
         strcpy(this->naziv, naziv);
         this->godina=godina;
     }
 };


class Kniga : public Publikacija{
    
    //ke nemame pristap do nazivot vo Publikaciaj bidejki e private
private:
    int broj_strani;
    
public:
    Kniga(char *naziv, int godina, int broj_strani) : Publikacija(naziv, godina){
        
        this->broj_strani=broj_strani;
        
    }
    
    void pecatiGodinaKniga(){
        cout<<godina;
    }
    
    void pecatiNazivKniga(){
        cout<<getNaziv();
    }
    
    void pecatiStrani(){
        cout<<broj_strani;
    }
    
};

//protected izveduvanje
class Vesnik:protected Publikacija{
    
private:
    int broj;
    
public:
    Vesnik(char *naziv, int godina, int broj):Publikacija(naziv, godina){
        
        this->broj=broj;
    }
    
    void pecatiGodinaVesnik(){ //пристап до public getGodina(), која во оваа класа има protected pristap
        cout<<getGodina();
    }
    
    void pecatiNazivVesnik(){
        cout<<getNaziv(); //NAZIV NE MOZE DA SE PRISTAPI BIDEJKI E PRIVATE
    }
    
    void pecatiBroj(){
        cout<<broj;
    }
    
};


//sve sto e vo public ke bide private i ke nema pristap
class DnevenVesnik:private Vesnik{
    
private:
    int den;
    int mesec:
    
public:
    DnevenVesnik(char *naziv, int den, int mesec, int godina,
                 int broj):Vesnik(naziv, godina,broj){
        this->den=den;
        this->mesec=mesec;
    }
    
    //so using:: moze nekoj privaten metod da go napravime public i moze da pristapime do toj metod
    using Vesnik::pecatiBroj();
    

};


int main()
{
  Publikacija p("Tabernakul", 1992);
  p.pecati(); // public - функција
  Kniga *k = new Kniga("ProsvetnoDelo", 1900, 123);
  k->pecati(); //pecati e public во Kniga
  k->pecatiGodinaKniga(); // public - функција
  // cout<<k->getNaziv(); // грешка! protected - функција
  Vesnik *s = new Vesnik("Tea", 2013 ,30);
  // s->pecati(); //грешка! protected - функција
  // cout<<s->getGodina(); // грешка! protected - функција
  s->pecatiNazivVesnik(); // public - функција
  DnevenVesnik d("Vest",2,3,2014,25);
  d.pecati(); //public-функција
  // d.pecatiNazivVesnik(); // грешка! private - функција
  // cout<<d.getNaziv(); // грешка! private – функција
}
*/

/*
class Animal {
    
protected:
    char name [30];
    
public:
    Animal (char *name) {
        strcpy (this->name,name);
    }
    //se stava virtual

    virtual void makeSound() {
        cout << name << " is making the sound bla bla"<<endl;
    }
};

class Dog : public Animal {

public:

Dog (char * name) : Animal (name) {

}
    //se stava virtual

virtual void makeSound() {
    cout << name << " is making the sound afafaf"<<endl;
    }
};

class Cat : public Animal {
public:
    Cat (char * name) : Animal (name) {}
    
    //se stava virtual
    virtual void makeSound() {
        cout << name << " is making the sound mjau mjau mjau"<<endl;
    }
};


int main() {
    
    //koristime dinamicka alokacija za objektite
    //pokazuvac kon klasata Animal
//Animal *a=new Animal("simba");
//a->makeSound();
//
//Animal *dog = new Dog ("kuci");
//dog->makeSound();
//
//Animal *cat = new Cat ("Luna");
//cat->makeSound();
    
    
Animal ** animals=new Animal *[3]; //niza od zivotni koristime **(dva pokazuvaci)

    animals[0]= new Animal("simba");
    animals[1] = new Dog ("kuci");
    animals[2] = new Cat ("Luna");
    
    for(int i=0;i<3;i++){
        animals[i]->makeSound(); // za sekoe zivotince animals od i ke go povikame metodot makeSound KOJ STO E POLIMORFIZAM i za sekoe zivotno ke go ispecati negovata impplemntacija za zvuk
    }
    
return 0;
}

*/


//ZADACA 1
/*
Да се дефинира класа за Хотелска резервација. За хотелската резервација се
чува бројот на денови, бројот на лица, име и презиме на лицето за контакт.
Да се земе дека цената на резервацијата за едно лице за еден ден е 25 евра.

Во класата да се дефинира функција vratiCena() која враќа колкава е цената
на резервацијата. Во класата да се дефинира функција vratiCena(int uplata)
која враќа колкава цена треба да се врати од касата ако корисникот на
резервацијата ја доставува дадената уплата.

 Да се изведе класа Полупансионска хотелска резервација за резервирање на
хотелска соба со појадок. Цената на појадокот за едно лице за еден ден е 5 евра.
Да се препокрие соодветно функцијата vratiCena(int uplata).

 Да се дефинира класа за Хотел со информации за името на хотелот и салдо на
хотелот. Во класата да се дефинира функција int
uplatiZaRezervacija(HotelsaRezervacija &hr, int uplata); Со оваа
функција треба да се направи уплата за дадена хотелска резервација. Ако
уплатата ја надминува бараната сума функцијататреба да врати колку пари
треба да му се врати на корисникот кој ја прави уплатата. Уплатата треба да се
додаде во салдото на хотелот
*/

/*
class HotelReservation{
    
protected: //bidejki imame izveduvanje na ovaa klasa
    int days;
    int guests;
    char name[50];
    
public:
    HotelReservation(char *name=" ", int days=0, int guests=0){
        strcpy(this->name, name);
        this->days=days;
        this->guests=guests;
    }
    
    virtual double vratiCena(){ //vraka kolkava e cenata na rezervacijata
        return guests*days*25;
        //Дасе земе дека цената на резервацијата за едно лице за еден ден е 25 евра
    }
    
     virtual double vratiCena(int uplata){ //vrz osnova na depozitot da vidime kolku ke bide  kusurot
        
        return uplata-vratiCena();
        
    }
    
};

//polupansionska
class HalfBoardReservation : public HotelReservation{
    
public:
    
    HalfBoardReservation(char *name=" ", int days=0, int guests=0) : HotelReservation(name,days,guests){
        
    }
    
    double vratiCena (){
        return HotelReservation::vratiCena()*1.2; //ako plakam i dorucek plakam plus 20% zatoa 1.2
    }
    
};

class Hotel{
private:
    char name[20];
    double balance; //saldo
public:
    Hotel(char *name=" ", double balance=0.0){
        strcpy(this->name, name);
        this->balance=balance;
    }
    
    double uplatiZaRezervacija(HotelReservation &hr, double uplata){
        
        double totalPrice=hr.vratiCena();
        balance+=totalPrice;
        return hr.vratiCena(uplata);
    }
    
    friend ostream &operator<<(ostream &out, const Hotel &h){
        out<<h.name<<" "<<h.balance;
        return out;
    }
    
};

int main(){
                //name          balance
    Hotel hotel("FINKI hotel", 1000);
    
    int n;//broj na rezervacii
    cin>>n;
    
    HotelReservation ** reservations= new HotelReservation *[n];
    
    for(int i=0;i<n;i++){
        int type; //1-obicna, 2-polupansion
        char name[30];
        int day,guests;
        cin>>type>>name>>day>>guests;
        if(type==1){
            reservations[i]=new HotelReservation(name,day,guests);
        }
        else {
            reservations[i]=new HalfBoardReservation(name,day, guests);
        }
        cout<<name<<" "<<day<<" "<<guests<<" "<<reservations[i]->vratiCena();
    }
    
    return 0;
    
}

*/


//PRIMER
/*
class Animal { //ABSTRACT CLASS
    
protected:
    char name [30];
    
public:
    Animal (char *name) {
        strcpy (this->name,name);
    }
    //se stava virtual
    
    virtual void makeSound()=0; //CISTO VIRTUELNA FUNKCIJA, NEMA IMPLEMENTACIJA OVOJ METOD
        //SO OVA KLASATA ANIMAL STANA APSTRAKTNA KLASA
};

*/


//ZADACA 3
/*
Да се дефинира апстрактна класа за репрезентација на едно геометриско тело. Секое
геометриско тело има висина (децимален број) и основа која може да биде различна за
различни геометриски фигури.
За апстракната класа да се дефинираат функциите:
- pecati() во која се печатат информациите за телото
- volumen() која ќе го враќа волуменот на телото
- getVisina() која ќе ја враќа висината на телото

Од класата геометриско тело да се изведе класа за цилиндер, конус и квадар. За еден
цилиндер и за еден конус покрај висината се чува и информација за радиусот на основата
(децимален број).За квадарот се чуваат информации за страните `а` и `b` на основата
(децимални броеви).
Во `main` функцијата да се декларира и иницизијализра динамички алоцирана низа од
покажувачи кон класата која претставува геометриско тело. Од оваа низа:
*/

/*
class GeometriskoTelo{
    
protected:
    double visina;
    
public:
    GeometriskoTelo(double visina=0.0){
        this->visina=visina;
    }
    
    //bez print metod site klasi ke bidat abstraktni
    //virtual void print()=0; //ke bide cisto virtuelen print metodot bidejki treba da imam konkretna forma za da znam kako da ja ispecatam. Vo ovaa klasa ne znam formata kakva ke bide
    
    //moze i da ne bide prazna print bidejki imame visina i samo da pecatime visina
    void print(){
        cout<<visina;
    }
    
    virtual double volumen()=0;
    
    double get_visina(){
        return visina;
    }
};

class Cilinder : public GeometriskoTelo{
    
private:
    double radius;
    
public:
    //i visina ja prima
    Cilinder(double visina=0.0,double radius=0.0) : GeometriskoTelo(visina){
        
        this->radius=radius;
    }
    
    //definicija za ovaa funkcija bidejki vo base class ni e prazna virtuelna
    //ako ne ja definirame i cilinder ke ostane apstraktna
    double volumen(){
        return 3.14*radius*radius*visina;
        //plostina. So mnozenje na visina dobivame volument
    }
    
    //prepokrivanje na metodot print
//    void print(){
//      cout<<"Cilindar so visina ";
//      GeometriskoTelo::print(); //od geometrisko telo povikaj ja funkcijata print
//      cout<<" i radius "<<radius<<endl;
//}
    
    void print(){
        cout<<"Cilindar so volumen: "<<volumen()<<endl;
    }
    
};

class Konus : public GeometriskoTelo{
    
private:
    int radius;
    
public:
    Konus(double visina=0.0,double radius=0.0) : GeometriskoTelo(visina){
        
        this->radius=radius;
        
    }
        double volumen(){
            return 3.14*radius*radius*visina;
            //plostina. So mnozenje na visina dobivame volument
        }
    
    //prepokrivanje na metodot pecati
//    void print(){
//      cout<<"Konus so visina ";
//      GeometriskoTelo::print(); //od geometrisko telo povikaj ja funkcijata print
//      cout<<" i radius<<radius<<endl;
//}
    
    void print(){
        cout<<"Konus so visina: "<<volumen()<<endl;
    }
    
};


class Kvadar : public GeometriskoTelo{
    
private:
    
    int a,b;

public:
    Kvadar(double visina=0.0, double radius=0.0, int a=0, int b=0):GeometriskoTelo(visina){
        
        this->a=a;
        this->b=b;
    }
    
    //prepokrivanje na funkcijata volumen
    double volumen(){
        return a*b*visina;
    }
    
    //prepokrivanje na metodot pecati
//    void print(){
//      cout<<"Kvadar so visina ";
//      GeometriskoTelo::print(); //od geometrisko telo povikaj ja funkcijata print
//      cout<<" i shirina "<<a<<" i visina: "<<b<<endl;
//}
    
    void print(){
        cout<<"Kvadar so volumen: "<<volumen()<<endl;
    }
    
};
                            //**shapes
void teloSoNajgolemVolumen(GeometriskoTelo *gtela[], int n){
    
    //moze i negativen broj da se stai
    float max_volumen=gtela[0]->volumen(); //prviot element od nizata go zima
    //GeometriskoTelo *max = niza[0];
    int max_i=0;
    
    for(int i=0;i<n;i++){
        if(gtela[i]->volumen()>max_volumen){
            max_volumen=gtela[i]->volumen();
            max_i=i;
        }
    }
    gtela[max_i]->print();
}

        //getRadius
int shapeswithoutbasecircle(GeometriskoTelo *gtela, int n){
    
//dynamic cast - nacin kako moze da utvrdime dali pokazuvac kon osnovnata klasa e  nekakva konkretna implementacija od izvedenata klasa. Za daden shape, dali e cilidnar, konus ili kuboid
    
    int counter=0;
    for(int i=0;i<n;i++){ //ke gi pomineme site formi
        //*c(FORMI) ke go kastiram vo Kvadar
                            //kon sto kastirame(Kvadar*) (pokazuvac kon Kvadar) i sto kastirame(g-formi)
        Kvadar *c = dynamic_cast<Kvadar *>(gtela); //Sekoja forma ke ja kastirame vo Kvadar, KE PROBAM DA JA NAPRAVAM KVADAR. gO ZIMAM kvadar bidejki nema kruzna osnova
        //SEKOJA I=TA FORMA KE PROBAJ DA JA PRETVORAM KAKO KVADRAT
        
        //spored poakzuvacot ke znam dali kastiranje e uspesno ili ne
        
        //ako pokazuvacot e null, togas e neuspesno
        if(c==nullptr){ //moze i 0
            ++counter; //nema kruzna osnova ako se zgolemi
        }
    }
    return counter;
}

int main(){
    
    int n;
    double visina,radius,a,b; //za korisnikot da vnesuva vrednosti
    cin>>n;
    
    //pokazuvac kon niza na pokazuvaci
    GeometriskoTelo **gtela = new GeometriskoTelo *[n];
    
    //ako korisnikot vnese 1 saka da vnese cilindar
    //ako korisnikot vnese 2 saka da vnese konus
    //ako korisnikot vnese 3 saka da vnese kvadar
    for(int i=0;i<n;i++){
        
        int type;
        cin>>type;
        if(type==1){
            cin>>visina>>radius; // cilindar imavme visina i radius
            gtela[i]=new Cilinder(visina,radius); //za cilinder vnesuvame visina i radius
        }
       if(type==2){
            cin>>visina>>radius;
            gtela[i]=new Konus(visina,radius);
        }
        if(type==3) {
            cin>>visina>>a>>b;
            gtela[i]=new Kvadar(visina,a,b);
        }
        //dodeka ne go implementiram print metodot site 3 klasi se abstraktni
        
    }
    
    teloSoNajgolemVolumen(gtela, n);
    
    cout<<"Number of shapes without a circle base is: "<<shapeswithoutbasecircle(*gtela, n);
    
    return 0;
}
*/


