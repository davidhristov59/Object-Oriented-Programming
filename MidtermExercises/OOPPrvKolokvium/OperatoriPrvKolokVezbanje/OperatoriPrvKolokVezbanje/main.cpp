#include <iostream>
#include <cstring>

using namespace std;

//11ta
/*
class Ucesnik{

private:
    char *ime;
    bool pol;
    int vozrast;
    int n;
    
public:
    Ucesnik(char *ime=" ", bool pol=true, int vozrast=0){
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->pol=pol;
        this->vozrast=vozrast;
    }
    
    Ucesnik(const Ucesnik &u){
        this->ime=new char[strlen(u.ime)+1];
        strcpy(this->ime, u.ime);
        this->pol=u.pol;
        this->vozrast=u.vozrast;
    }
    
    Ucesnik &operator=(const Ucesnik &u){
        if(this!=&u){
            delete [] ime;
            this->ime=new char[strlen(u.ime)+1];
            strcpy(this->ime, u.ime);
            this->pol=u.pol;
            this->vozrast=u.vozrast;
        }
        return *this;
    }
    
    ~Ucesnik(){
        delete [] ime;
    }
    
    int get_vozrast(){
        return vozrast;
    }
    
    bool operator>(Ucesnik &u){
     
        if(this->vozrast>u.vozrast){
            return true;
        }
        return false;
    }
    
    friend ostream &operator<<(ostream &out, const Ucesnik &u){
        
        out<<u.ime<<endl;
        if(u.pol==0){ //deka e bool
            out<<"zhenski"<<endl;
        }
        else { //ako e 1
            out<<"mashki"<<endl;
        }
        out<<u.vozrast<<endl;
        return out;
    }
    
};

class Maraton{
    
private:
    char lokacija[100];
    Ucesnik *ucesnici;
    int br_ucesnici;
    
public:
    Maraton(char *lokacija=" "){
        strcpy(this->lokacija, lokacija);
        br_ucesnici=0;
        ucesnici=new Ucesnik[br_ucesnici];
    }
    
    Maraton(const Maraton &u){
        strcpy(this->lokacija, u.lokacija);
        this->br_ucesnici=u.br_ucesnici;
        this->ucesnici=new Ucesnik[u.br_ucesnici];
        for(int i=0;i<br_ucesnici;i++){
            ucesnici[i]=u.ucesnici[i];
        }
    }
    
    Maraton &operator=(const Maraton &u){
        if(this!=&u){
            delete [] ucesnici;
            strcpy(this->lokacija, u.lokacija);
            this->br_ucesnici=u.br_ucesnici;
            for(int i=0;i<br_ucesnici;i++){
                ucesnici[i]=u.ucesnici[i];
            }
        }
        return *this;
    }
    
    ~Maraton(){
        delete [] ucesnici;
    }
    
    Maraton &operator += (const Ucesnik &u){
        
        Ucesnik *tmp = new Ucesnik[br_ucesnici+1];
        
        for(int i=0;i<br_ucesnici;i++){
            tmp[i]=ucesnici[i];
        }
        tmp[br_ucesnici++]=u;
        delete [] ucesnici;
        ucesnici=tmp;
        return *this;
    }
    
    float prosecnoVozrast(){
        
        float prosek=0.0;
        int zbir=0;
        for(int i=0;i<br_ucesnici;i++){
            zbir+=ucesnici[i].get_vozrast();
        }
        prosek=zbir/(br_ucesnici*1.0);
        
        return prosek;
    }
    
    void pecatiPomladi(Ucesnik &u){
        
        int god=u.get_vozrast();
        for(int i=0;i<br_ucesnici;i++){
            if(god>ucesnici[i].get_vozrast()){
                cout<<ucesnici[i];
            }
        }
    }
                  
                  
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}
*/


//zad 13ta
class Zichara {
    
private:
    char *mesto;
    int cena;
    
public:
    Zichara(char *mesto=" ", int cena=0){
        this->mesto=new char[strlen(mesto)+1];
        strcpy(this->mesto, mesto);
        this->cena=cena;
    }
    
    Zichara(const Zichara &z){
        this->mesto=new char[strlen(z.mesto)+1];
        strcpy(this->mesto, z.mesto);
        this->cena=z.cena;
    }
    
    Zichara &operator=(const Zichara &z){
        if(this!=&z){
            delete [] mesto;
            this->mesto=new char[strlen(z.mesto)+1];
            strcpy(this->mesto, z.mesto);
            this->cena=z.cena;
        }
        return *this;
    }
    
    ~Zichara(){
        delete [] mesto;
    }
    
};

class PlaninarskiDom{
    
private:
    char ime[15];
    int ceni_sezona[2];//поле од 2 цели броеви кои ја претставуваат цената за спиење за еден ден во планинарскиот дом
    char klasa; //еден знак кој може да има вредност од A до F, каде A е најдобра класа
    bool zicara;
    Zichara *pokZicara;//покажувач кон објект од класата Zichara
    
public:
    
    PlaninarskiDom(char *ime=" ", int *ceni_sezona=0, char klasa='A'){
        
        strcpy(this->ime, ime);
        for(int i=0;i<2;i++){
            this->ceni_sezona[i]=ceni_sezona[i];
        }
        this->klasa=klasa;
        this->zicara=true;
        this->pokZicara=0;
        
    }
    
    PlaninarskiDom(const PlaninarskiDom &pl){
        strcpy(this->ime, pl.ime);
        for(int i=0;i<2;i++){
            this->ceni_sezona[i]=pl.ceni_sezona[i];
        }
        this->klasa=pl.klasa;
        this->zicara=pl.zicara;
        this->pokZicara=pl.pokZicara;
    }
    
    PlaninarskiDom &operator=(const PlaninarskiDom &pl){
        if(this!=&pl){

            strcpy(this->ime, pl.ime);
            for(int i=0;i<2;i++){
                this->ceni_sezona[i]=pl.ceni_sezona[i];
            }
            this->klasa=pl.klasa;
            this->zicara=pl.zicara;
            this->pokZicara=pl.pokZicara;
        }
        return *this;
    }
    
    ~PlaninarskiDom (){}
    
    PlaninarskiDom &operator--(){
        if(klasa=='F'){
            --klasa;
        }
        return *this;
    }
    
    friend ostream &operator<<(ostream &out, const PlaninarskiDom &pl){
        if(pl.zicara==1){
                   
            out<<pl.ime<<pl.klasa<<"so zichara"<<endl;
        }
        else {
            out<<pl.ime<<pl.klasa<<endl;
        }
        return out;
    }
    
    bool operator<=(PlaninarskiDom &pl){
        if(this->klasa<=pl.klasa){
            return true;
        }
        return false;
    }
    
};
            
            
            int main(){

               PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

               //во следниот дел се вчитуваат информации за планинарскиот дом
               char imePlaninarskiDom[15],mestoZichara[30],klasa;
               int ceni[12];
               int dnevnakartaZichara;
               bool daliZichara;
               cin>>imePlaninarskiDom;
               for (int i=0;i<2;i++) cin>>ceni[i];
               cin>>klasa;
               cin>>daliZichara;

               //во следниот дел се внесуваат информации и за жичарата ако постои
               if (daliZichara) {
                  cin>>mestoZichara>>dnevnakartaZichara;
                  PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
                  Zichara r(mestoZichara,dnevnakartaZichara);
                  pom.setZichara(r);
                  p=pom;
               }
               else{
                  PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
                  p=*pok;
               }

               //се намалува класата на планинарскиот дом за 2
               --p;
               --p;

               int cena;
               int den,mesec;
               cin>>den>>mesec;
               try{
               p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
               cout<<"Informacii za PlaninarskiDomot:"<<endl;
               cout<<p;
               if (p<='D')
                   cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";
                   
               cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
               }
               catch (int){
                  cout<<"Mesecot ili denot e greshno vnesen!";
               }
            }

