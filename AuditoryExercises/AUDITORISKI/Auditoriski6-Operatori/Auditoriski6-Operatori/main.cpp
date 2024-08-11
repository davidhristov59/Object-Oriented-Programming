#include <iostream>
#include <cstring>

using namespace std;

/*
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
    
    //void addnumber

    //OPERATOT += ZA DODAVANJE NA NOV ELEMENT VO NIZATA(NAMESTO ADD)
    Array &operator += (int number){ //dodacame nov int
        //na klasata Array mu ddodava nov broj - go modificira
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
        //VRAKA this
        return *this;
    }
    
    //void delete       //broj sto treba da go izbrise
    Array &operator -= (int number){ //da gi izbrise site pojavuvanja na brojot number
        for(int i=0,j=0;i<size;i++){
            if(content[i] != number){
                content[j++]=content[i];
            }
        }
        return *this;
    }

    //VOID PRINT
    //OPERATOR << za printanje na elementite       (out - slicno na cout)
    //prima 2 argumenti sekogas - prviot - ostream &out,
    friend ostream &operator << (ostream &out, const Array &a){
        for (int i = 0; i < a.size; ++i) {
            out << a.content[i] << " ";
     }
        for (int i = a.size; i < a.capacity; ++i) {
                out << "- ";
     }
        out << endl;
        return out;
     }
    
    //OPERATOR ZA VCITUVANJE >>
    //CIN
                                //nema da bide konstantna
    friend istream &operator >>(istream &in, Array &a){
        
        in>>a.capacity;
        
        return in;
    }
    
    //ke vrati int - sostaven e od integeri
    //OPERATOR [] - PRISTAP DO ELEMENT I PROMENA NA VREDNOST NA ELEMENT OD POLETO
    int &operator[] (int index){
        
        return content[index];
        
    }
    
    
    //OPERATOR == za sporedba na 2 objekta od klasata Array
    
    bool operator==(Array &a){
        
        //ako ne se isti
        if(this->size!=a.size){
            return false;

        }
        for(int i=0;i<this->size;i++){
            
            if(this->content[i]!=a.content[i]){
                return false;
            }
        }
        return true; //vrakame true deka nizite se ednakvi ==
    }
    
};
*/


class Ucenik{
    
private:
    
    char *ime;
    int *oceni;
    int broj_oceni;
    int skolska_godina;
    
public:
    
    Ucenik(char *ime=" ", int skolska_godina=0){
        
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->broj_oceni=0;
        this->oceni=new int[0];
        this->skolska_godina=0;
    }
    
    Ucenik(const Ucenik &u){
        this->ime=new char[strlen(u.ime)+1];
        strcpy(this->ime, u.ime);
        this->broj_oceni=u.broj_oceni;
        this->oceni=new int[this->broj_oceni];
        for(int i=0;i<broj_oceni;i++){
            ime[i]=u.ime[i];
        }
        this->skolska_godina=u.skolska_godina;
    }
    
    Ucenik &operator=(const Ucenik &u){
        if(this!=&u){
            delete [] ime;
            delete [] oceni;
            
            this->ime=new char[strlen(u.ime)+1];
            strcpy(this->ime, u.ime);
            this->broj_oceni=u.broj_oceni;
            this->oceni=new int[this->broj_oceni];
            for(int i=0;i<broj_oceni;i++){
                ime[i]=u.ime[i];
            }
            this->skolska_godina=u.skolska_godina;
        }
        return *this;
    }
    
    ~Ucenik(){
        delete [] ime;
        delete [] oceni;
    }
    
    //OPERATOR ++
    //prefiks i sufiks
    
    Ucenik &operator++(){
        //prefiks
        ++skolska_godina;
        return *this;
    }
    
    //za sufiks nema referenca, vraka nov student
    Ucenik operator++(int){ //samo int se pisuva - da ima distinkcija so prefiks operatorot
        
        Ucenik tmp(*this); //ista kopija so this objektot
            ++skolska_godina;
            return tmp;
        }
    
    //operator --
       //mora i prefiks i sufiks
       Ucenik &operator--(){ //prefiks
           skolska_godina--;//zgolemuvame godina
           return *this;
       }

       //sufiks
       //nema referenca &
       Ucenik operator--(int){
           Ucenik tmp=*this;//na[ravi kopija tmp od momentalniot objekt
           skolska_godina--; //ke ja zgolemime godinata na momentalniot objekt
           return tmp; //vrati go staroto
       }
    
    //Operator +=
    Ucenik &operator += (int ocena){
        
        int *tmp = new int [broj_oceni+1];
        for(int i=0;i<broj_oceni;i++){
            tmp[i]=oceni[i];
        }
        tmp[broj_oceni++]=ocena;
        delete [] oceni;
        oceni=tmp;
        
        return *this;
    }
    
    double getAverage() const {
        if(broj_oceni==0){
            return 5.0;
        }
        
        int sum=0;
        for(int i=0;i<broj_oceni;i++){
            sum+=broj_oceni;
        }
        return (double)sum/broj_oceni;
    }
    
    //OPERATOR << ZA PECATENJE
    friend ostream &operator<< (ostream &out, const Ucenik &u){
        
        out<<u.ime<<" "<<u.skolska_godina<<" "<<u.getAverage()<<endl;
  
        return out;
        
    }
    
    bool operator> (Ucenik &u){
        
        return this->getAverage()>u.getAverage();
        
    }
    
};

class Faculty{
    
private:
    Ucenik *ucenici;
    int n;
    
public:
    Faculty(){
        n=0;
        ucenici = new Ucenik[0];
    }
    
    Faculty(const Faculty &f){
        
        this->n=f.n;
        ucenici = new Ucenik[this->n];
        for(int i=0;i<n;i++){
            ucenici[i]=f.ucenici[i];
        }
    }
    
    Faculty &operator=(const Faculty &f){
        
        if(this!=&f){
            delete [] ucenici;
            this->n=f.n;
            ucenici = new Ucenik[this->n];
            for(int i=0;i<n;i++){
                ucenici[i]=f.ucenici[i];
            }
        }
        return *this;
    }
    
    ~Faculty(){
        delete [] ucenici;
    }
    
    //operator +=
    Faculty &operator+=(const Ucenik &new_student){
        
        Ucenik *tmp = new Ucenik[n+1];
        for(int i=0;i<n;i++){
            tmp[i]=ucenici[i];
        }
        tmp[n++] = new_student;
        delete [] ucenici;
        ucenici=tmp;
        return *this;
    }
    
    //operator ++
    Faculty &operator++(){
        
        //prefiks
        for(int i=0;i<n;i++){
            ++ucenici[i];
        }
        return *this;
    }
    
    //operator <<
    
    friend ostream &operator<<(ostream &out, const Faculty &f){
        
        for(int i=0;i<f.n;i++){
            out<<f.ucenici[i]<<endl;
        }
        
        return out;
    }
    
    //Метод nagrada што ги печати само оние ученици кои имаат просек 10.0.
    void nagrada(){
        
        for(int i=0;i<n;i++){
            if(ucenici[i].getAverage()==10.0){
                cout<<ucenici[i];
            }
        }
    }
    
    void najvisok_prosek(){
        Ucenik max=ucenici[0];
        int index=0;
        for(int i=1;i<n;i++){
            if(ucenici[i]>max){
                max=ucenici[i];
                //index=i;
            }
        }
        cout<<max;
    }
    
};

