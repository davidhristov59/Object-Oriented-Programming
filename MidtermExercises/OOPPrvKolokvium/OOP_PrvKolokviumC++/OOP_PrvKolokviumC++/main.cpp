#include <iostream>
#include <cstring>

using namespace std;

/*
enum Extension{
        
    txt,pdf,exe
};

class File{
    
private:
    char *fileName;
    char *fileOwner;
    int fileSize;
    Extension ex;
    
public:
    
    File(char *fileName=" ", char *fileOwner=" ", int fileSize=0, Extension ex=txt){
        
        this->fileName=new char[strlen(fileName)+1];
        strcpy(this->fileName, fileName);
        this->fileOwner=new char[strlen(fileOwner)+1];
        strcpy(this->fileOwner, fileOwner);
        this->fileSize=fileSize;
        this->ex=ex;
        
    }
    
    File(const File &f){
        this->fileName=new char[strlen(f.fileName)+1];
        strcpy(this->fileName, f.fileName);
        this->fileOwner=new char[strlen(f.fileOwner)+1];
        strcpy(this->fileOwner, f.fileOwner);
        this->fileSize=f.fileSize;
        this->ex=f.ex;
    }
    
    ~File(){
        delete [] fileName;
        delete [] fileOwner;
    }
    
    File &operator=(const File &f){
        if(this!=&f){
            delete [] fileName;
            delete [] fileOwner;
            
            this->fileName=new char[strlen(f.fileName)+1];
            strcpy(this->fileName, f.fileName);
            this->fileOwner=new char[strlen(f.fileOwner)+1];
            strcpy(this->fileOwner, f.fileOwner);
            this->fileSize=f.fileSize;
            this->ex=f.ex;
        }
        return *this;
    }
    
    void print(){
        
        char* ext = "";
                if (ex == 0) ext = "pdf";
                if (ex == 1) ext = "txt";
                if (ex == 2) ext = "exe";
        
        cout<<"File name: "<<fileName<<"."<<ex<<endl;
        cout<<"File owner: "<<fileOwner<<endl;
        cout<<"File size: "<<fileSize<<endl;
    }
    
    bool equals(const File &f){
        if((strcmp(this->fileName, f.fileName)==0) && (this->ex == f.ex) && (strcmp(this->fileOwner, f.fileOwner)==0)){
            return true;
        }
        else {
            return false;
        }
    }
    
    bool equalsType(const File &f){
        if((strcmp(this->fileName, f.fileName)==0) && (this->ex == f.ex)){
            return true;
        }
        else {
            return false;
        }
    }
    
};

class Folder{
    
private:
    char *name;
    File *files;
    int num_files;
    
public:
    
    Folder(const char *name){
        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->num_files=0;
        this->files=0;
    }
    
    Folder(const Folder &f){
        this->name=new char[strlen(f.name)+1];
        strcpy(this->name, f.name);
        this->num_files=f.num_files;
        this->files=f.files;
    }
    
    ~Folder(){
        delete [] name;
        delete [] files;
    }
    
    Folder &operator=(const Folder &f){
        if(this!=&f){
            delete [] name;
            delete [] files;
            this->name=new char[strlen(f.name)+1];
            strcpy(this->name, f.name);
            this->num_files=f.num_files;
            this->files=f.files;
            
        }
        return *this;
    }
    
    void add(const File &f){
        
        File *tmp = new File[num_files+1];
        for(int i=0;i<num_files;i++){
            tmp[i]=files[i];
        }
        
        tmp[num_files++]=f;
        delete [] files;
        files=tmp;
        
    }
    
    void remove(const File &f){
        int counter=0;
        
        for(int i=0;i<num_files;i++){
            if(!files[i].equals(f)){
                counter++;
            }
        }
        
        File *tmp=new File[counter];
        counter=0;
        for(int i=0;i<num_files;i++){
            if(!files[i].equalsType(f)){
                tmp[counter++]=files[i];
            }
        }
        
        delete [] files;
        files=tmp;
        num_files=counter;
    }
    
    void print(){
        cout<<"Folder's name: "<<name<<endl;
        for(int i=0;i<num_files;i++){
            files[i].print();
        }
    }
    
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    }
    else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    }
    else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    }
    else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    }
    else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
 
 */


//1VA ZAD

/*
enum Tip{
    pop,rap,rok
};

class Pesna{

private:
    char *ime;
    int minuti;
    Tip tip;

public:

    Pesna(char *ime=" ", int minuti=0, Tip tip=pop){
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->minuti=minuti;
        this->tip=tip;
    }

    Pesna(const Pesna &p){
        this->ime=new char[strlen(p.ime)+1];
        strcpy(this->ime, p.ime);
        this->minuti=p.minuti;
        this->tip=p.tip;
    }

    ~Pesna(){
        delete [] ime;
    }

    Pesna &operator=(const Pesna &p){
        if(this!=&p){
            delete [] ime;
            this->ime=new char[strlen(p.ime)+1];
            strcpy(this->ime, p.ime);
            this->minuti=p.minuti;
            this->tip=p.tip;
        }
        return *this;
    }

    void pecati(){
        cout<<'"'<<ime<<'"'<<"-"<<minuti<<"min"<<endl;
        //cout << "\"" << ime << "\"" << "-" << min << "min" << endl;

    }

    Tip getTip(){
        return tip;
    }

    int getMinuti() {
        return minuti;
    }


    };

class CD {

private:
    Pesna pesni[10];
    int broj_pesni;
    int max_traenje;

public:


    CD(int Broj=0, int max_traenje=0){
        this->broj_pesni=Broj;
        this->max_traenje=max_traenje;
        //this->pesni=new Pesna[Broj];
//        for(int i=0; i < Broj; i++){
//            this->pesni[i]=pesni[i];
//        }
    }

    CD(const CD &c){
        this->broj_pesni=c.broj_pesni;
        this->max_traenje=c.max_traenje;
        for(int i=0;i<broj_pesni;i++){
            this->pesni[i]=c.pesni[i];
        }
    }

    ~CD(){}

    CD &operator=(const CD &c){
        if(this!=&c){
            this->broj_pesni=c.broj_pesni;
            this->max_traenje=c.max_traenje;

            for(int i=0;i<broj_pesni;i++){
                this->pesni[i]=c.pesni[i];
            }
        }
        return *this;
    }

    void dodadiPesna(Pesna p){

//        Pesna *tmp = new Pesna[broj_pesni+1];
//        for(int i=0;i<broj_pesni;i++){
//            tmp[i]=pesni[i];
//        }
//        tmp[broj_pesni++]=p;
//        tmp=pesni;

        int zbir=0;
    for(int i=0;i<broj_pesni;i++){
        zbir+=pesni[i].getMinuti();
    }
        if((broj_pesni<10)&&(p.getMinuti()<=max_traenje-zbir)){
            pesni[broj_pesni++]=p;
        }
    }

    void pecatiPesniPoTip(Tip t){
        for(int i=0;i<broj_pesni;i++){
            if(pesni[i].getTip()==t){
                pesni[i].pecati();
            }
        }
    }

//    int getBroj(){
//        return Broj;
//    }
//
//    Pesna getPesna(){
//        return pesni;
//    }

    Pesna &getPesna(int indeks) {
        return pesni[indeks];
    }

    int getBroj()  {
        return broj_pesni;
    }


};




int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (Tip) kojtip);
        p.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (Tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (Tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (Tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((Tip) kojtip);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (Tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((Tip) kojtip);

    }

    return 0;
}
*/



//21 zad
/*
struct Tanc{

    char ime_tanc[15];
    char zemja[15];

};

typedef struct Tanc Tanc;

struct Tancer{

    char ime[20];
    char prezime[20];
    Tanc niza[5];

};

typedef struct Tancer Tancer;

void tancuvanje(Tancer *t, int n, char *zemja){

    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(zemja, t[i].niza[j].zemja) == 0){ //zemja prvo pa posle od strukturata
                cout << t[i].ime << " " << t[i].prezime << ", " << t[i].niza[j].ime_tanc << endl;
                break; //STAVAME BREAK DEKA VISE NAJDOVME 1 DRZAVA I DA ZAVRSI KOGA KE SE NAJDE
        }
        }
    }

}


int main(){

    int i, j, n;
    char zemja[15];
    Tancer tanceri[5];
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> tanceri[i].ime;
        cin >> tanceri[i].prezime;
        for(j = 0; j < 3; j++){
            cin >> tanceri[i].niza[j].ime_tanc;
            cin >> tanceri[i].niza[j].zemja;
        }
    }
    cin >> zemja;
    tancuvanje(tanceri, n, zemja);

    return 0;
}
*/



//ZADACA - konsultacii Vlatko (kolokviumska)

/*
class Product {
    
private:
    char *ime;
    int cena;
    int popust;
    int kolicina;
    
public:
    Product(char *ime=" ", int cena=0, int popust=0, int kolicina=0){
        
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->cena=cena;
        this->popust=popust;
        this->kolicina=kolicina;
        
    }
    
    Product (const Product &p){
        this->ime=new char[strlen(p.ime)+1];
        strcpy(this->ime, p.ime);
        this->cena=p.cena;
        this->popust=p.popust;
        this->kolicina=p.kolicina;
    }
    
    Product &operator=(const Product &p){
        if(this!=&p){
            delete [] ime;
            
            this->ime=new char[strlen(p.ime)+1];
            strcpy(this->ime, p.ime);
            this->cena=p.cena;
            this->popust=p.popust;
            this->kolicina=p.kolicina;
        }
        return *this;
    }
    
    ~Product(){
        delete [] ime;
    }
    
    void print(){
        cout<<ime<<"Regular price: "<<cena<<"Price with discount: "<<cena*(1-popust)/100<<"Quantity: "<<kolicina<<endl;
    }
    
    void zgolemi_procent(int k){
        if(popust+k<=99){
            popust+=k;
        }
    }
    
    void increment(){
        kolicina++;
    }
    
    void int get_kolicina(){
        return kolicina;
    }
    
};

class Store{
  
private:
    char ime[50];
    Product *niza;
    int n;
    
public:
    Store(char *ime=" ", int n=0){
        strcpy(this->ime, ime);
        niza=new Product[0];
        n=0;
    }
    Store(const Store &s){
        strcpy(this->ime, s.ime);
        n=s.n;
        niza=new Product[n];
        for(int i=0;i<n;i++){
           niza[i]=s.niza[i];
        }
    }
    
    Store &operator=(const Store &s){
        
        if(this!=&s){
            
            delete [] niza;
            strcpy(this->ime, s.ime);
            n=s.n;
            niza=new Product[n];
            for(int i=0;i<n;i++){
                niza[i]=s.niza[i];
            }
        }
        return *this;
    }
    
    ~Store(){
        delete [] niza;
    }
    
    void print(){
        cout<<ime<<endl;
        for(int i=0;i<n;i++){
            niza[i].print();
        }
    }
    
    void add(Product p){
        
        if(p.get_kolicina()<5){
            return;
        }
        
        Product *tmp = new Product[n+1];
        for(int i=0;i<n;i++){
            tmp[i]=niza[i];
            
        }
        tmp[n++]=p;
        delete [] niza;
        niza=tmp;
    }
    
    void removeProduct(int kol){
        for(int i=0;i<n;i++){
            if(niza[i].get_kolicina()<kol){
                niza[i].zgolemi_procent(20);
            }
        }
    }
    
    void removeProductMax(){
        
        Product *tmp=new Product[n-1];
        for(int i=0,j=0;i<n;i++){
            if(i!=index){
                tmp[j]=niza[i];
                j++
            }
        }
        delete [] niza;
        n--;
        niza=tmp;
    }
    
};
*/


//10 ZAD
/*
struct Igrac{

    char korisnicko_ime[15];
    int nivo;
    int poeni;

};

typedef struct Igrac Igrac;

typedef struct {
    char ime_igra[20];
    Igrac igraci[30];
    int br_igraci;
}KompjuterskaIgra;

void najdobarIgrac(KompjuterskaIgra *lista, int n){

    int max_i=0,max=0;
    for(int i=0;i<n;i++){ //ja barame igrata so ima najgolem broj igraci
        if (lista[i].br_igraci > max) {
            max=lista[i].br_igraci;
            max_i = i;
        }
    }
    int indeksigrac=0,maxpoeni=0;
    //najdobar igrac
    for (int i = 0; i < lista[max_i].br_igraci; ++i) {
        if((lista[max_i].igraci[i].poeni>maxpoeni) || ((lista[max_i].igraci[i].poeni==maxpoeni))){
            indeksigrac=i;
        }
    }

    cout << "Najdobar igrac e igracot so korisnicko ime " << lista[max_i].igraci[max_i].korisnicko_ime << " koj ja igra igrata " << lista[max_i].ime_igra << endl;

}

int main() {
    KompjuterskaIgra igra[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>igra[i].ime_igra;
        cin>>igra[i].br_igraci;
        for (int j = 0; j < igra[i].br_igraci; ++j) {
            cin>>igra[i].igraci[j].korisnicko_ime;
            cin>>igra[i].igraci[j].nivo;
            cin>>igra[i].igraci[j].poeni;
        }

    }

    najdobarIgrac(igra,n);
    return 0;
}
*/


//17 ZAD
/*
enum Tip{
    LINUX,UNIX,WINDOWSG
};

class OperativenSistem{
private:
    char *ime;
    float verzija;
    Tip tip;
    float golemina;

    void copy(const OperativenSistem &os){
        this->ime=new char[strlen(os.ime)+1];
        strcpy(this->ime,os.ime);
        this->verzija=os.verzija;
        this->tip=os.tip;
        this->golemina=os.golemina;
    }
public:
    OperativenSistem(char *ime=" ",float verzija=0.0,Tip tip=LINUX,float golemina=0.0){
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->verzija=verzija;
        this->tip=tip;
        this->golemina=golemina;
    }

    OperativenSistem(const OperativenSistem &os){
        copy(os);
    }

    OperativenSistem &operator=(const OperativenSistem &os){
        if(this!=&os){
            delete[]ime;
            copy(os);
        }
        return *this;
    }

    ~OperativenSistem(){
        delete[]ime;
    }

    void pecati(){
        cout<<"Ime: "<<ime<<" Verzija: "<<verzija<<" Tip: "<<tip<<" Golemina:"<<golemina<<"GB"<<endl;
    }

    bool ednakviSe(const OperativenSistem &os){
        if((strcmp(ime, os.ime)==0) && (this->verzija==os.verzija) && (this->tip==os.tip) && (this->golemina==os.golemina)){
            return true;
        }
        else {
            return false;
        }
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (verzija == os.verzija) {
            return 0;
        }
        if(os.verzija>verzija) {
            return -1;
        }
        return 1;
    }

    bool istaFamilija(const OperativenSistem &sporedba){
        if((strcmp(this->ime, sporedba.ime)) && (tip==sporedba.tip)){
            return true;
        }
        return false;
    }

};

class Repozitorium{

private:
    char ime[20];
    OperativenSistem *niza;
    int brojOperativniSistemi;
    void copy(const Repozitorium &r){
        strcpy(this->ime, r.ime);
        this->brojOperativniSistemi=r.brojOperativniSistemi;
        this->niza=new OperativenSistem[brojOperativniSistemi];
        for(int i=0;i<brojOperativniSistemi;i++){
            this->niza[i]=r.niza[i];
        }
    }

public:
    Repozitorium(const char *ime){
        strcpy(this->ime, ime);
        this->brojOperativniSistemi=brojOperativniSistemi;
        this->niza=new OperativenSistem[brojOperativniSistemi];
        for(int i=0;i<brojOperativniSistemi;i++){
            this->niza[i]=niza[i];
        }
    }

    Repozitorium(const Repozitorium &r){
        copy(r);
    }

    Repozitorium &operator =(const Repozitorium &r){
        if(this!=&r) {
            delete [] niza;
            copy(r);
        }
        return *this;
    }

    ~Repozitorium(){
        delete [] niza;
    }

    void pecatiOperativniSistemi(){
        cout<<"Repozitorium: FINKICloud"<<endl;
        for(int i=0;i<brojOperativniSistemi;i++){
            niza[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem &operativenSistem){
        int flag=0;
        for(int i=0;i<brojOperativniSistemi;i++) {
            if (this->niza[i].ednakviSe(operativenSistem)){
                flag=1;
                // break;
            }
        }
        if(flag==0){
            return;
        }

        OperativenSistem *tmp = new OperativenSistem[brojOperativniSistemi-1];
        for(int i=0, j=0;i<brojOperativniSistemi;i++) {
            if (!this->niza[i].ednakviSe(operativenSistem)) {
                tmp[j] = niza[i];
                j++;
            }
        }
        brojOperativniSistemi--;
        delete [] niza;
        niza=tmp;
    }

    void dodadi(const OperativenSistem &nov){
        int flag=0;
        for(int i=0;i<brojOperativniSistemi;i++){
            if(niza[i].istaFamilija(nov)){
                if(niza[i].sporediVerzija(nov)==1){ //-1 доколку верзијата на оперативниот систем од аргументот е поголема
                    niza[i]=nov;
                }
                // return;
            }
        }

        OperativenSistem *tmp = new OperativenSistem[brojOperativniSistemi+1];
        for(int i=0;i<brojOperativniSistemi;i++){
            tmp[i]=niza[i];
        }
        tmp[brojOperativniSistemi++]=nov;
        delete [] niza;
        niza=tmp;
    }

};

int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
*/



