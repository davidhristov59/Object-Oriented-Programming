#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

//KOMPOZICII

//kompozicija imame koga element od edna klasa e clen vo druga klasa
//kompozicii imavme vo strukturi
//copy konstruktor koga se prai kopija od elementot - se povikuva copy konstruktor

//class Person {
//
//private:
//    int year;
//public:
//    Person(int y) {
//        cout << "Konstruiranje" << endl;
//        year = y;
//    }
//
//    ~Person() {
//        cout << "Destruirane" << endl;
//    }
//
//    Person(const Person &f) {//copy konstruktor. PRIMA OBJEKT OD KLASA F. so & se razlikuva od drugiot konstruktor, vusnost pravam kopija
//    //copy konstruktor prima po referenca
//        cout<<"Kopi"<<endl;
//        year=f.year;
//
//    }
//};
////nadvor od klasata
//void presmetka(Person k){
//    cout <<"Funkcija"<<endl;
//}
//
//int main() {
//
//    Person p(3000);
//    presmetka (p);
//
//
//    return 0;
//}

//ZADACA1

//BEZ THIS->
/*
class Momche{
    
private:
    
    char ime[50];
    char prezime[50];
    int godini;

public:
    //default konstruktori
    //Momche(int godini=0, char *ime = " ", char *prezime = " "){
        
//        this->godini=godini;
//        strcpy(this->ime, ime);
//        strcpy(this->prezime,prezime);
        
    Momche(){}
            Momche(char *i, char *p, int g){
                strcpy(ime, i);
                strcpy(prezime, p);
                godini=g;
            }
    
    
    ~Momche(){}
    
    void print(){
        cout<<"Momche: "<<ime<<" "<<prezime<<" "<<godini<<endl;
    }
    
    int get_godini(){
        return godini;
    }
    
};

class Devojce{
    
private:
    
    char ime[50];
    char prezime[50];
    int godini;

public:
    //default konstruktori
    Devojce(){}
        Devojce(char *i, char *p, int g){
            strcpy(ime, i);
            strcpy(prezime, p);
            godini=g;
        }
    
    ~Devojce(){}
    
    void print(){
        cout<<"Devojce: "<<ime<<" "<<prezime<<" "<<godini<<endl;
    }
    
    int get_godini(){
        return godini;
    }
    
};

class Sredba{
    
private:
    
    Momche momce;
    Devojce devojce;
    
public:
    Sredba(Momche m, Devojce d){
        momce=m;
        devojce=d;
    }
    
    ~Sredba(){}
    
    void print(){
        cout<<"Sredba: ";
        momce.print();
        devojce.print();
    }
    
    void daliSiOdgovaraat(){
        
        if(abs(momce.get_godini()-devojce.get_godini())<5){
            cout<<"Si odgovaraat"<<endl;
        }
        else {
            cout<<"Ne si odgovaraat"<<endl;
        }
    }
    
};

int main(){
    
    char ime[50];
    char prezime[50];
    int godini;
    
    cout<<"Vnesi podatoci za momce:"<<endl;
    cin>>ime>>prezime>>godini;
    
    Momche m(ime,prezime,godini);
    
    cout<<"Vnesi podatoci za devojce:"<<endl;
    cin>>ime>>prezime>>godini;
    
    Devojce d(ime,prezime,godini);
    
    Sredba s(m,d);
    s.print();
    s.daliSiOdgovaraat();
    
}
 
 */
//ZAD1 - SREDBA
/*
Да се дефинира класа Momche која содржи информации за име, презиме и
години. За класата да се дефинираат конструктори, деструктор и метод за
печатење на објектот на екран во формат:
Momche: Ime Prezime Godini.
Да се дефинира класа Devojche со истите атрибути и методи со разлика во
форматот на печатење:
Devojche: Ime prezime godini.
Креирајте класа Sredba која содржи податоци за едно момче и едно девојче.
• Креирајте функција print() која ги печати податоците за момчето и
девојчето во следниот формат:
Sredba: Momche: Ime Prezime Godini Devojche: Ime Prezime Godini.
• Напишете функција daliSiOdgovaraat() која печати "Si odgovaraat" доколку
разликата на нивните години е помала или еднаква на 5 или "Ne si
odgovaraat" во спротивно.
*/

//KOMPOZICIJA

//class Momche{
//
//private:
//    char ime[20];
//    char prezime[20];
//    int godini;
//
//public:
//    Momche(int godini=0, char *ime= " ", char *prezime= " "){ //go smeta za default konstruktor
//
//        //so this-> pokazuvame kon istiot objekt bez menuvanje na imeto vo default konstruktor. Fakticki mu ja dodeluvame istata vrednost. Ne pisuvame druga promenliva i ne ja zadavame
//        this->godini=godini;
//        strcpy(this->ime, ime);
//        strcpy(this->prezime, prezime);
//
//    }
//
//    void print(){
//
//        cout<<"Momce: "<<ime<<" "<<prezime<<" "<<godini<<endl;
//    }
//
//    int get_godini(){
//        return godini;
//    }
//
//};
//
//class Devojce{
//
//private:
//    char ime[20];
//    char prezime[20];
//    int godini;
//
//public:
//    Devojce(int godini=0, char *ime= " ", char *prezime= " "){ //go smeta za default konstruktor
//
//        //so this-> pokazuvame kon istiot objekt bez menuvanje na imeto vo default konstruktor. Fakticki mu ja dodeluvame istata vrednost. Ne pisuvame druga promenliva i ne ja zadavame
//        this->godini=godini;
//        strcpy(this->ime, ime);
//        strcpy(this->prezime, prezime);
//
//    }
//
//    void print(){
//
//        cout<<"Devojce: "<<ime<<" "<<prezime<<" "<<godini<<endl;
//    }
//
//pravime get metod za da gi zememe godinite za vo funkcijata da iskoristime
//    int get_godini(){
//        return godini;
//    }
//
//};
//
//
//class Sredba{
//
//private:
//    //eden objekt od tip Momce i eden objekt od tip Devojce
//    //KOMPOZICIJA - objekt od momce i objekt od devojce
//    Momche momce;
//    Devojce devojce;
//
//public:
//
//    Sredba(Momche m, Devojce d){ //obicen konstruktor
//
//        //zadavame vrednosti
//        momce=m;
//        devojce=d;
//
//    }
//    ~Sredba(){}
//
//    void print(){
//        cout<<"Sredba: ";
//         //povikuvame print funkcijata za 2 objekta
//        momce.print();
//        devojce.print();
//    }
//
//    void daliSiOdgovaraat(){
//        if(abs(momce.get_godini()-devojce.get_godini())<5){ //ako apsolutnata vrednost pomegju razlikata od nivnite godini e pomala od 5
//            cout<<"Si odgovaraat"<<endl;
//        }
//        else {
//            cout<<"Ne si odgovaraat"<<endl;
//        }
//    }
//
//};
//
//int main(){
//
//    char ime[20];
//    char prezime [20];
//    int godini;
//
//    cout<<"Vnesi podatoci za masko:"<<endl;
//    cin>>ime>>prezime>>godini;
//    Momche m(godini,ime,prezime);
//
//    cout<<"Vnesi podatoci za devojce:"<<endl;
//    cin>>ime>>prezime>>godini;
//    Devojce d(godini,ime,prezime);
//
//    Sredba s(m, d);
//    s.print();
//    s.daliSiOdgovaraat();
//
//
//    return 0;
//}



//ZAD 2 - EKIPA
/*
class Ekipa{
  
private:
    char ime[20];
    int godina;
    char grad[20];
    
public:
    //so zadavanje vrednosti pravime konstruktorot da bide i default i so argumenti
    Ekipa(char *ime = " ", char *grad = " ", int godina=0){
         strcpy(this->ime, ime);
        strcpy(this->grad,grad);
        this->godina=godina;
    }
    
//    Ekipa(char *i = " ", char *gr = " ", int g=0){
//        strcpy(ime, i);
//        strcpy(grad,gr);
//        godina=g;
//    }
    
        //copy konstruktor
    Ekipa(const Ekipa &e){ //objektot da bide const - da ne dozvoluvame promena dodeka se naoga vo drug objekt.
        
        //ovie podatoci ke gi vleceme od objektot e.
        //e.godina, e.ime...
        
        //ke se iskoopira vo e.
        strcpy(ime, e.ime);
        strcpy(grad,e.grad);
        godina=e.godina;
        
    }
    
    ~Ekipa(){}
    
    char *getIme(){
        return ime;
    }
};

class Natprevar {
    
private:
    //objekti od klasata Ekipa
    Ekipa domakin,gostin;
    int goloviDomakin, goloviGostin;
    
public:
            //ekipa domakin, ekipa gostin, goloviDom, goloviGost
    Natprevar(Ekipa d, Ekipa g, int gDom, int gGost){
        
        //davame vrednosti - moze i so this->
        domakin=d;
        gostin=g;
        goloviDomakin=gDom;
        goloviGostin=gGost;
    }
    
    ~Natprevar(){}
    
    //GET METODI
    //vrakam objekt od tip ekipa bidejki domakin i gostin mi se objekti od tip ekipa, tuka e kompozicijata.
    Ekipa getDomakin(){
        return domakin;
    }
    
    Ekipa getGostin(){
        return gostin;
    }
    
    int getGoloviDomakin(){
        return goloviDomakin;
    }
    
    int getGoloviGostin(){
        return goloviGostin;
    }
    
    
};

//prima dva objekta od klasata Natprevar i proveruva dali edniot natp e revans na drugiot
bool revans(Natprevar n1, Natprevar n2){ //dali e revans ili ne e
    
    //ako na prviot natrpevar domakinot imeto e isto so na prviot naptrevar gostinot imeto
    
    if(strcmp(n1.getDomakin().getIme(), n2.getGostin().getIme())==0 && strcmp(n1.getGostin().getIme(), n2.getDomakin().getIme())==0){
        
        return true; //ako ovie dva se isti , znaci e revans
    }
    else {
        
        return false;
        
    }
}

//ke vraka cela Ekipa
Ekipa duel(Natprevar n1, Natprevar n2){
    
    if(revans(n1, n2)){
        
        //vkupniot broj na golovi na dvete ekipi
        int ekipa1Golovi=n1.getGoloviDomakin() + n2.getGoloviGostin();
        int ekipa2Golovi=n1.getGoloviGostin() + n2.getGoloviDomakin();
        
        if(ekipa1Golovi>ekipa2Golovi){
            return n1.getDomakin();
        }
        else if(ekipa2Golovi>ekipa1Golovi){
            return n2.getGostin();
        }
        else {
            return 0;
        }
        
    }
    else {
        cout<<"Ne se sovpagaat"<<endl;
        return 0;
    }
}


int main(){
    
    //dvete ekipi
            //tim, grad, godina
    Ekipa e1("Real Madrid", "Madrid", 1990);
    Ekipa e2("FC Barcelona", "Barcelona", 1995);
    
    //
    Natprevar n1(e1,e2,4,2);
    Natprevar n2(e2,e1,1,0);
    
    cout<<duel(n1,n2).getIme(); //da vrati ime
    
    
    return 0;
}
*/


//ZAD3 - Vraboten

class Datum {
  
private:
    
    int den;
    int mesec;
    int godina;

public:
    
    Datum(int den=0, int mesec = 0, int godina = 0){
        
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;
    }
    
    //copy konstruktor
    Datum(const Datum &d){
        godina=d.godina;
        mesec=d.mesec;
        den=d.den;
    }
    
    ~Datum (){}
    
    int get_den(){
        return den;
    }
    
    int get_mesec(){
        return mesec;
    }
    
    int get_godina(){
        return godina;
    }
    
};

class Vraboten{
    
private:
    char ime[20];
    int plata;
    Datum datum_raganje;
    
public:
    
    //koga imame referenca mora da kazeme kon koj objekt taa reference ke refencira
    
                                        //const Datum &data - MOZE I VAKA KAKO COPY KONSTRUKTOR namesto Datum data=0
    Vraboten(char *ime=" ", int plata=0, Datum data=0){
        strcpy(this->ime,ime);
        this->plata=plata;
        datum_raganje=data;
    }
    
    int get_plata(){
        return plata;
    }
    
    char *get_ime(){
        return ime;
    }
    
    //OD TIP DATUM
    Datum get_Data_Raganje(){
        return datum_raganje;
    }
    
    void print(){

        cout<<"Ime: "<<ime;
        cout<<"Plata: "<<plata;             //OBJEKT
        //go printa vo forma na datum xx..yy..2222
        cout<<"Datum na raganje:   "<<datum_raganje.get_den()<<"."<<datum_raganje.get_mesec()<<"."<<datum_raganje.get_godina()<<endl;
    }
};



//funkcija za vraboten so najgolema plata
Vraboten najgolema_plata(Vraboten v[], int n){
    
    int i,max=0, max_i=0;
    for(i=0;i<n;i++){
        if(v[i].get_plata()>max){
            max=v[i].get_plata();
            max_i=i;
        }
    }
    return v[max_i]; //max indeks vraka so vraboten so max plata
}

int sporedba(Datum d1, Datum d2){
    
    if(d1.get_godina()>d2.get_godina()){
        return 1;
    }
    else if(d1.get_godina()<d2.get_godina()){
        return 2;
    }
    else if(d1.get_mesec()>d2.get_mesec()){
        return 1;
    }
    else if(d1.get_mesec()<d2.get_mesec()){
        return 2;
    }
    else if(d1.get_den()>d2.get_den()){
        return 1;
    }
    else if(d1.get_den()<d2.get_den()){
        return 2;
    }
    else { //datumite se isti
        return 0;
    }
    
}
                            //Vraboten *v
Vraboten najmlad_vraboten(Vraboten v[], int n){
    
    int i,min_i=0;
    
    //2 nacin
    Datum min(v[0].get_Data_Raganje()); //isto kako min
    
    for(i=0;i<n;i++){
            
        if(sporedba(v[i].get_Data_Raganje(), min)==1){
            min=v[i].get_Data_Raganje();
            min_i=i;
        }
    }
    
    return v[min_i];
}

int main(){
    
    //10 pati se povikuva default konstuktorot
    Vraboten v[10];
    
    char ime[20];
    int plata;
    int den,mesec,godina;
    
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        
        cin>>ime>>plata>>den>>mesec>>godina;
        
        Datum d(den,mesec,godina);
        v[i]=Vraboten(ime,plata,d);
    }
    
    najgolema_plata(v, n).print();
    najmlad_vraboten(v, n).print();
    
//    Datum d1(11,12,2003);
//    Datum d2(2,2,2002);
//    Datum d3(15,10,1999);

    
    return 0;
}
