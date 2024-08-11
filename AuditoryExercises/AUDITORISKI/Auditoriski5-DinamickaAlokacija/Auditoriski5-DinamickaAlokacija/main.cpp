#include <iostream>
#include <cstring>

using namespace std;

//VLATKO - AUDITORISKI

//2.1 Array

//cim ima zadaca so dinamicka lokacija - operator =, destruktor, konstruktor, copy konstruktor

//class Array{
//private:
//
//    int *niza; //*-dinamicki da se locira. int niza[50] -ne dinamicki
//    int capacity;//kapacitet
//    int current;//momentalen broj na nizata-kolku od mestata vo nizata se popolneti
//
//public:
//    Array(int capacity){ //sega samo capacity.odposle se dodavaat elementite
//
//        this->capacity=capacity;//this ja sodrzi adresata na objektot zak oj funkciajta e povikana
//        current=0;//broj na elementi momentalno e 0
//        niza = new int[capacity]; //new - dinamicko locirano pole od celi broevi - int so vkupen broj na mesta - capacity. NEW e klucen zbor.
//    }
//
//    //copy konstruktor
//    Array(const Array &a){ //ako nemase & ke se povikuvase sebese celovreme,
//        capacity=a.capacity; //moze i so this, tuka moze bez deka e razlicno imeto a.capacity
//        this->current=a.current;
//        this->niza=new int[capacity]; //alociravme mesto vo memorija.GO STAVIVME A.CAPACITY VO capacity
//        for(int i=0;i<current;i++){ //odi do current bidejki ni gi cuva brojot na elementi
//            niza[i]=a.niza[i];//gi kopirame tie elementi vo niza
//        }
//    }
//
//    //operator =
//
//    Array &operator=(const Array &a){
//        if(this!=&a){//se sporeduvaat adresite da ne dojde do samododeluvanje
//            //ja zimam adresata na a &a
//            //ako this e razlicna od adresata
//            capacity=a.capacity; //moze i so this, tuka moze bez deka e razlicno imeto a.capacity
//            this->current=a.current;
//            delete [] niza; //dealocirame niza - se brise memorijata
//            this->niza=new int[capacity];
//            for(int i=0;i<current;i++){ //odi do current bidejki ni gi cuva brojot na elementi
//                niza[i]=a.niza[i];//gi kopirame tie elementi vo niza
//            }
//        }
//        ~Array(){
//            delete [] niza;
//        }
//
//        void print(){
//            cout<<capacity<<endl;
//            for(int i=0;i<current;i++){
//                cout<<niza[i]<<" ";
//            }
//            cout<<endl;
//        }
//
//        void add(int m){ //ke dodava broj
//
//            if(current==capacity){
//                capacity*=2;
//                int *tmp = new int [capacity];
//                for(i=0;i<current;i++){
//                    tmp[i]=niza[i];
//                }
//                delete [] niza;
//                niza=tmp; //nizata pokazuva kon tmp
//            }
//
//            niza[current]=m;//na nulto mesto stavi mi go elementot m
//
//            current++; //current ke se zgolemi za 1
//            void change(int a, int b){ //sekoja vrednost so ja ima a, da se smeni so b
//                for(int i=0;i<current;i++){
//                    if(niza[i]==a){
//                        niza[i]=b;
//                    }
//                }
//            }
//
//            void deleteall(int m){ //vredost sto sakame da ja izbriseme m
//
//                for(int i=0;j=0;i<current;i++){ //tuka e i++, tuka go zgolemuvame ako se povtoruva elementot?
//                    if(niza[i]!=m){
//                        niza[j]=niza[i];
//                        j++;
//                    }
//                }
//                current=j; //current ke bide j
//            }
//};
//
//
//int main() {
//
//    Array a(3);
//    a.add(9);
//
//
//
//    //9,8,16 - elementite
//
//
//    return 0;
//}


//ZAD 2.2 - VEB SERVERI
//
//class WebPage{
//private:
//    char url[100];
//    char *content;//dinamicki alocirana
//
//public:
//    WebPage(char *url, char *content){
//        strcpy(this->url, url);
//        this->content=new char[strlen(content)+1]; //kolku znaci ima vo content- dolzinata
//        strcpy(this->content, content);
//    }
//
//    WebPage(const WebPage &p){
//        if(this!=p){ //ako stanuva zbor za razlicen element
//            strcpy(this->url, p.url); //p.
//            delete [] content; //dealociraj, izbrisi
//
//            this->content=new char[strlen(p.content)+1]; //kolku znaci ima vo content- dolzinata
//            strcpy(this->content, p.content);
//        }
//    }
//};



//Stojmenski - Auditoriski





//СТЕФАН - АУДИТОРИСКИ
//class String{
//
//private:
//    //char cptr[100] - staticna alocirana niza
//    char *content; //dinamicki alocirana niza
//
//public:
//    //default constructor i constructor so argumenti
//    //MORA = copy constructor, operator =, destructor
//
//    String(char *cptr = " "){ //2 vo 1 - i default i so argumenti konstruktor
//
//        //1.alocirame memorija za this->cptr
//        this->content = new char[strlen(cptr)+1]; //new - alocira memorija. strlen(cptr)+1 e za da ja zeme dolzinata i da pocne od 1
//
//        //2.copy content
//        strcpy(this->content,cptr);
//
//    }
//
//    //copy konstruktor
//    String(const String &other){
//        //realokacija na memorija        //ne dava so . - mora so ->
//        this->content=new char[strlen(other.content)+1]; //so other preku referenca
//    }
//
//    ~String(){  //[] deka e niza
//        delete [] content; //da se oslobodime od dinamicko alocirana memorija
//    }
//
//    //operator =
//
//    String &operator = (const String &s){
//        if(this==&s){ //dali memorijata na this e ista so taa sto ni e alocirana - s
//            delete [] content;
//
//            //isto kako gore samo so s. go pristapuva
//            this->content = new char [strlen(s.content)+1];
//            strcpy(this->content, s.content);
//        }
//        return *this; //vraka sodrzina na *this, sodrzinata na nasiot objekt
//    }
//
//};
//
//int main(){
//
//
//
//    return 0;
//}


/*
class Team{
    
private:
    //dinamicki alocirame
    char *name;
    char *stadium;
    char *city;
    
    void copy(const Team &t){ //ke si go povikame samo da ne go kopirame poveke pati
        
        this->name=new char [strlen(t.name)+1];
        strcpy(this->name, t.name);
        
        this->stadium=new char[strlen(t.stadium)+1];
        strcpy(this->stadium, t.stadium);
        
        this->city=new char[strlen(t.city)+1];
        strcpy(this->city, t.city);
        
    }
    
    void freeMemory(){
        delete [] name;
        delete [] stadium;
        delete [] city;
    }
    
public:
    //2 vo 1 konstruktor
    Team(char *name="", char *stadium="", char *city=""){
        
        this->name=new char [strlen(name)+1];
        strcpy(this->name, name);
        
        this->stadium=new char[strlen(stadium)+1];
        strcpy(this->stadium, stadium);
        
        this->city=new char[strlen(city)+1];
        strcpy(this->city, city);
    }
    
    //copy konstruktor
    
    Team(const Team &t){
        
        copy(t);
        
    }
    
    //destruktor
    ~Team(){
        
        freeMemory();
    }
    
    //operator =
    
   Team &operator = (const Team &t){
       if(this!=&t){
           
           freeMemory();
           
           //isto od gore
           
           copy(t);
           
       }
       return *this;
    }
    
    void print(){
        
        cout<<"Team name: "<<name<<" which plays on stadium: "<<stadium<<" in the city"<<city<<endl;
        
    }
    
};

int main(){
    
    
    int n;
    cin>>n;
    
    //pokazuvac kon dinamicko locirano pole kon objekt od Team
    Team *teams = new Team[n]; //ako nema default constructor, tuka ke padne
    
    //so elementi vo niza
    char name[100];
    char stadium[100];
    char city[100];
    

    for(int i=0;i<n;i++){
        cin>>name>>stadium>>city;
        
        teams[i]=Team(name, stadium, city); //bez operator = ke
    }
    
    for(int i=0;i<n;i++){
        teams[i].print();
    }
    
    
    
    return 0;
}
*/


//Array

class Array{

private:

    int *content;
    int capacity;
    int size;

    void copy(const Array &a){

        this->capacity=a.capacity;
        this->size=a.size; //moze i bez thus
        //mora prvo da se inicijalizira na new int
        this->content=new int[capacity]; //seedno e so ke stavi vo [] - dali capacity ili a.capacity deka pogore go imame inicijalizirano

        //deka e niza zatoa for ciklus
        for(int i=0;i<size;i++){
            this->content[i]=a.content[i];
        }

    }


public:

    Array(int capacity=10){ //samo capacity ni e potrebno vo konstruktorot

        this->capacity=capacity;
        this->content=new int[capacity]; //deka e int. NE E NIZA - so vkupen broj na mesta [capacity]
        this->size=0;
    }

    //copy konstruktor
    Array(const Array &a){
        copy(a);
    }

    //operator =
    Array &operator = (const Array &a){
        if(this!=&a){
            delete [] content;
            copy(a);
        }
        return *this;
    }

    //destruktor
    ~Array (){
        delete [] content;
    }


    void add(int number){
        if(size<capacity){
            content[size++]=number;
        }
        else {
            //move all elements and the new element in an temp array
            int *tmp = new int [size];
            for(int i=0;i<size;i++){
                tmp[i]=content[i];
            }
            tmp[size++]=number;
            delete [] content;
            content = tmp;
        }
    }

};




//VLATKO - 03.04

//WEB-SERVERI
//PRV KOLOKVOIM SLICNA

class WebPage{

private:
    char url[100];
    char *content;//pokazuvac kon dinamicki alocirana niza od karakteri

public:
    //konstruktor so predefinirani argumenti - ke se zemmat tie vrednosti
    WebPage(char *url="", char *content=""){

        //
        strcpy(this->url, url);
        //prvo alociraj
        this->content=new char[strlen(content)+1]; //dodavame plus 1 bidejki strlen ne go broi null znakot
        strcpy(this->content, content); //kopiraj
    }

    //konstruktor
    //copy konstruktor
    //operator =
    //destruktor

    //Copy konstruktor
    WebPage(const WebPage &wp){
        strcpy(this->url,wp.url);
        this->content=new char[strlen(wp.content)+1];
        strcpy(this->content, wp.content);
    }

    //destruktor
    ~WebPage(){
        delete [] content;
    }

    //operator =
    WebPage &operator=(const WebPage &wp){

        if(this!=&wp){
            delete [] content;//prvo delete - dealocirame

            strcpy(this->url,wp.url);
            this->content=new char[strlen(wp.content)+1];
            strcpy(this->content, wp.content);
        }

        return *this;
    }


    bool daliseIsti(WebPage wp){
        if(strcmp(url, wp.url)==0){
            return true;
        }
        else {
            return false;
        }
    }

};

class WebServer{

private:
    char ime[30];
    WebPage *niza;
    int n;//dopolnitelno-broj na elementi za ovaa niza sto ja ima

public:

    WebServer(char *ime="", int n=0, WebPage *niza=0){

        strcpy(this->ime, ime);
        this->n=n;
        this->niza=new WebPage[n]; //alocirame so n elementi
        
        //for ciklus za kopiranje na elementite
        for(int i=0;i<n;i++){ //mora ciklus za kopiranje na elementite vo niza
            this->niza[i]=niza[i];
        }
    }

    //copy konstruktor
    WebServer (const WebServer &w){
        strcpy(this->ime, w.ime);
        this->n=w.n;
        this->niza=new WebPage[n]; //alocirame so n elementi

        for(int i=0;i<n;i++){ //mora ciklus za kopiranje na elementite
            this->niza[i]=w.niza[i];
        }
    }

    //operator =
    WebServer &operator=(const WebServer &w){

        if(this!=&w){
            delete [] niza;
            strcpy(this->ime, w.ime);
            this->n=w.n;
            this->niza=new WebPage[n]; //alocirame so n elementi

            for(int i=0;i<n;i++){ //mora ciklus za kopiranje na elementite
                this->niza[i]=w.niza[i];
            }
        }
        return *this;
    }

    ~WebServer(){
        delete [] niza;
    }
    
    
//    void addPage(WebPage wp){
//
//        WebPage *tmp =new WebPage[n+1];
//        for(int i=0;i<n;i++){
//            tmp[i]=niza[i];
//        }
//        tmp[n++]=wp;
//        delete [] niza;
//        niza=tmp;
//
//    }
   
    void addPage(WebPage wp){ //dodavame nova strana ako taa strana ne postoi vo serverot
        for(int i=0;i<n;i++){
            if(niza[i].daliseIsti(wp)){//ako ja imame ke zavrsime
                return;
            }
        }
        //nadvor od for-ot
        //ja dodavame novata strana
        //da alocirame nova dinamicka alocirana niza

        //da napravime niza za 1 pogolema od segasnata
        //site iskopiraj gi vo temp
        WebPage *tmp = new WebPage[n+1];
        for(int i=0;i<n;i++){
            tmp[i]=niza[i];
        }
        //n e poslednata od n+1
        tmp[n++]=wp; //zgolemi go za 1
        delete [] niza;
        niza=tmp;
    }

    void deletePage(WebPage wp){

        //vo ovaa funkcija mozeme samo 1 strana da najdeme
        int flag=0;
        for(int i=0;i<n;i++){
            //ako ne se isti
            if(niza[i].daliseIsti(wp)){ //ako ja nemame ke zavrsime, site strani treba da se izvrtat togas da se zavrsi
                flag=1; //ako e najdeno barem edna strana
            }
        }

        if(flag==0){ //ako ostane 0
            return;
        }

        WebPage *tmp = new WebPage[n-1]; //tuka n-1 stavame
        int j=0;
        for(int i=0;i<n;i++){
            if(!niza[i].daliseIsti(wp))
            tmp[j]=niza[i];
            j++;
        }
        n--;
        delete [] niza;
        niza=tmp;

    }
    
    
    

};

//tuka ke zastaneme

int main(){


    return 0;
}
