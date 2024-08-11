#include <iostream>
#include <cmath>
#include <cstring>


using namespace std;

//Класа е логичка група на пдоатоци кои се групирани во една целина да можат да опишат еден ентитет. Тие податоци ни репрезентираат ентитет.

//private - samo vnatre vo klasata, nevidlivo nadvor od klasata.
//public- nadvor od klasata i vo ramki na main funkcijata



//КЛАСИ

//class Cuboid{
//private:
//    int a,b,c;
//public:
//    //imeto na klasata
//    Cuboid(){ //default konstruktor - ne se pisuva return type, nema int,float..
//        cout<<"Default constructor" << endl;
//    }
//    //ednas se povikuva konstruktorot
//    Cuboid(int aa, int bb, int cc){ //konstruktor so argumenti
//        a = aa;
//        b = bb;
//        c = cc;
//        cout << "Constructor" << endl;
//    }
//    ~Cuboid() { cout << "Destructor" << endl; } //destruktor - unistuvanje na objektot
//
//    int area(){
//
//
//
//    }
//
//};
//
//int main() {
//
//
//
//    return 0;
//}


//ZAD1 - Triagolnik

/*
Да се напише класа за опишување на геометриско тело триаголник. Во класата
да се напишат методи за пресметување на плоштината и периметарот на
триаголникот.
Потоа да се напише главна програма во која ќе се инстнацира еден објект од
оваа класа со вредности за страните кои претходно ќе се прочитаат од
стандарден влез. На овој објект да се повикат соодветните методи за
пресметување на плоштината и периметарот.*/

/*
class Triagolnik{
    
    //nie ovozmuzuvame vo private sigurnost na vrednostite i nivna zastita za da ne moze korisnikot da gi menuva
private:
    int a,b,c; //dolzina na strani
public:
    //konstruktor za klasata triagolnik
    Triagolnik(int aa, int bb, int cc){ //konstruktor - se povikuvak oga se povikuva objekt. Imeto na klasat e konstrukt. Atributite - od koi sto ke se konstruira objektot
        
        a=aa; //vrednostite gi dodeluvame na nasite vrednosti a,b,c
        b=bb;
        c=cc;

    }
    ~Triagolnik(){} //destruktor - nemame argumenti
        //bez default konstruktor
    
    //perimetar
    int perimeter(){
        
        return a+b+c;
        
    }
    
    float plostina(){
        
        //float s = (a+b+c)/2.0; //1 opcija
        float s = perimeter()/2.0; //2 opcija  - da se povika funkcijata
        
        return sqrt(s*(s-a)*(s-b)*(s-c));
        
    }
    
};

int main(){
    
    int a,b,c;
    cin>>a>>b>>c;
    
    //da instancirame objekt od klasata
    
    Triagolnik t(a,b,c); //objekt e t, vrednostite na konstruktorot
                        
                            //ime na objektot...
    cout<<"Perimetarot e " << t.perimeter()<<endl;
    cout<<"Plostinata e " << t.plostina()<<endl;
    
    
    return 0;
}
*/


//ZAD2 - Vraboten

/*
Да се напише класа во која ќе се чуваат основни податоци за вработен:
• име
• плата
• работна позиција (работната позиција може да биде вработен, директор или
шеф).
Напишете главна програма во која се читаат од стандарден влез податоци за N
вработени, а потоа се пачати листа на вработените сортирани според висината
на платата во опаѓачки редослед.
 
 4
 aleksandar
 40000
 1
 test
 50000
 2
 vladimir
 60000
 3
 Jana
 35000
 2
 
 */

/*
enum  pozicija{//se koristi enum koga sekogas ke treba da se izbere od nekoe malo, ograniceno mnozestvo vrednosti vo slucajov - vraboten, direktor ili sef (3 vrednosti).Koga zadaden atribut na klasata moze da primi ograniceno mnozestvo vrednosti. POVEKE VREDNOSTI KOGA SE DADENI
    
    //3 vrednosti se dadeni-fiksni vrednosti
    vraboten,direktor=50,shef //vraboten ke bide 0, direktor 50, shef=51
    
};

class Vraboten{
  
private:
    char ime[100];
    int plata;
    pozicija p;//atribut za pozicija - VO.lp p se cuva pozicijata-ENUM
    
public:
    
    Vraboten(){} //konstruktor bez argumenti - se kreira objekti bez
    
    //konstruktor - nema return type
    //konstruktoro se povikuva ednas koga objektot se kreira
    Vraboten(char *i, int pl, pozicija pp){
        
        //gi doddeluvame vrednostite
        strcpy(ime, i); //vo ime sakame toa od i da se iskopira
        plata=pl;
        p=pp;
    }
    
    ~Vraboten(){}
    
    //ne vraka nisto
    
    //set funkcija zaz site posebno da stavime vrednosti
    
    void set_ime(char *i){//set funkciite primaat argumenti, setirame vrednost
        strcpy(ime,i);
    }
    
    void set_plata(int pl){//set funkciite primaat argumenti, setirame vrednost
        plata=pl;
    }
    
//    void set_pozciija(int pp){//set funkciite primaat argumenti, setirame vrednost
//        p=(pozicija)pp; //ke ja kastiram vo pp zosto vo funkcijata nemaa vrednost pozicija e samo bez tip
//
//    }
    
    void set_pozicija(pozicija pp){//set funkciite primaat argumenti, setirame vrednost
        p=pp;
        
    }
    
    //3te funkcii gi spojuvame vo edna - EDNA SET FUNKCIJA
    
//    void set_all(char *i, int pl, pozicija pp){
//        strcpy(ime, i);
//        plata=pl;
//        p=pp;
//    }
    
    char *get_Ime(){
        return ime;
    }
    
    int get_plata(){ //ne prima argumenti, zima argumenti
        return plata; //zemanje na vrednost - plata
    }
    
    //get za pozicjata
    pozicija getPosition(){
        return p;
    }
};

void sort(Vraboten *vraboteni, int n){
    
    Vraboten temp;
    int i,j;
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(vraboteni[i].get_plata()<vraboteni[j].get_plata()){
                temp=vraboteni[i];
                vraboteni[i]=vraboteni[j];
                vraboteni[j]=temp;
            }
        }
    }
    
}


int main(){
    
    int n,i;
    //se zima od default konstruktorot vo public sto e prazen Varboten()
    Vraboten vraboteni[100]; //niza so ime Vraboteni od objekt od klasata vraboten
    //vo ovoj objekt ke e generiraat 100 vraboteni - 100 objekti
    
    cin>>n;
    char ime [50];
    int plata;
    int poz;
    
    for(i=0;i<n;i++){
        cin>>ime>>plata>>poz;
        vraboteni[i].set_ime(ime);
        vraboteni[i].set_plata(plata);
        vraboteni[i].set_pozicija((pozicija)poz); //kastirame
    }
    
    sort(vraboteni,n);
    
    for(i=0;i<n;i++){
        
        cout<<i+1<<". "<<vraboteni[i].get_Ime()<<"\t"<<vraboteni[i].get_plata()<<"\t"<<vraboteni[i].getPosition()<<endl;
          
        //namesto vraboteni[i].getPosition()
        //ako sakame spored enum da odremi koja pozicija e
   
//        if(vraboteni[i].getPosition()==0){
//            cout<<" vraboten "<<endl;
//        }
//
//        if(vraboteni[i].getPosition()==1){
//            cout<<" direktor "<<endl;
//        }
//        if(vraboteni[i].getPosition()==0){
//            cout<<" sef "<<endl;
//        }

    }
    
    return 0;
}

*/

//ZAD3
//EMAIL
/*
Да се напише класа која опишува една e-mail порака. Во класата треба да се
имплементира метод за прикажување на целокупната порака на екран. Потоа
да се напише главна програма во која се внесуваат параметрите на пораката, се
инстанцира објект од оваа класа и се печати на екран неговата содржина. За
проверување на валидноста на e-mail пораката (постоење на знакот @ во
адресата) да се напише соодветна функција.
*/

class Email{
    
private:
    char to[100];
    char from[100];
    char subject[200];
    char body[500];
    
public:
    
    Email(){}
    
    Email(char *_to, char *_from, char *_subject, char *_body){
        
        strcpy(to, _to);
        strcpy(from, _from);
        strcpy(subject,_subject);
        strcpy(subject, _body);

    }
    
    ~Email(){}
    
    void setTo(char *_to){
        strcpy(to, _to);
    }
    
    void setDo(char *_from){
        strcpy(from, _from);
    }
    
    void setSubject(char *_subject){
        strcpy(subject, _subject);
    }
    
    void setBody(char *_body){
        strcpy(body, _body);
    }
    
    char *get_to(){
        return to;
    }
    
    char *get_from(){
        return from;
    }
    
    char *getSubject(){
        return subject;
    }
    
    char *getBody(){
        return body;
    }
    
    void print(){
        
        cout<<"To: "<<to<<endl;
        cout<<"From: "<<from<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"Body: "<<body<<endl;
        
    }
    
};

//funkcija za proverka na validen e-mail
//proveruva dali @ ke bide ednas vo adresata
bool checkEmail(char *address){
    
    int brojac=0,i;
    
    for(i=0;i<strlen(address);i++){
        if(address[i]=='@'){
            brojac++;
        }
    }
    if(brojac==1){ //edno @ da ima ke e true
        return true;
    }
    else {
        return false;
    }
    
}


int main(){
    
    char to[100];
    char from[100];
    char subject[200];
    char body[500];
    
    cin>>to;
    
    //dokolku e validna adresata do koja sto prakame gi citame i drugite raboti
    if(checkEmail(to)){
        
        cin>>from>>subject>>body;
    
        Email email(to,from,subject,body); //pravime objekt od email
        
        cout<<"Pratena poraka: "<<endl;
        email.print();
        
    }
    
    else {
        cout<<"Nevalidna poraka"<<endl;
    }
    
        return 0;
}
