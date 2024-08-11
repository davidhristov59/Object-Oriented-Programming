#include <iostream>
#include <cstring>
#define MAX 50

using namespace std;

//1va ZAD

/*
class Book{
    
protected:
    char ISBN[21];
    char naslov[51];
    char avtor[31];
    double cena;
    
public:
    Book(char *ISBN=" ", char *naslov=" ", char *avtor=" ", double cena=0.0){
        
        strcpy(this->ISBN, ISBN);
        strcpy(this->naslov, naslov);
        strcpy(this->avtor, avtor);
        this->cena=cena;
    }
    
    Book(const Book &b){
        
        strcpy(this->ISBN, b.ISBN);
        strcpy(this->naslov, b.naslov);
        strcpy(this->avtor, b.avtor);
        this->cena=b.cena;
    }
    
    Book &operator=(const Book &b){
        if(this!=&b){
            strcpy(this->ISBN, b.ISBN);
            strcpy(this->naslov, b.naslov);
            strcpy(this->avtor, b.avtor);
            this->cena=b.cena;
        }
        return *this;
    }
    
    virtual ~Book(){}
    
    virtual double bookPrice()=0;
    
    virtual bool operator>(Book &b)=0;
    
//    bool operator>(const Book &b){
//
//        return this->cena > b.cena;
//    }
    
    friend ostream &operator<<(ostream &out, Book &b){
        
        out<<b.ISBN<<": "<<b.naslov<<", "<<b.avtor<<" "<<b.bookPrice()<<endl;
        
        return out;
    }
};

class OnlineBook: public Book{
    
private:
    
    char *url;
    int MB;

public:
    
//    OnlineBook():Book(){
//
//        this->url=new char[0];
//        this->MB=0;
//
//    }
    
//    OnlineBook(char *url=" ", int MB=0):Book(ISBN, naslov, avtor, cena){
//
//        this->url=new char[strlen(url)+1];
//        strcpy(this->url, url);
//        this->MB=MB;
//    }
    
    OnlineBook(char *ISBN=" ", char *naslov=" ", char *avtor=" ", double cena=0.0, char *url=" ", int MB=0):Book(ISBN, naslov, avtor, cena){
        
        this->url=new char[strlen(url)+1];
        strcpy(this->url, url);
        this->MB=MB;
    }
    
    OnlineBook(const OnlineBook &ob):Book(ob){
        
        this->url=new char[strlen(ob.url)+1];
        strcpy(this->url, ob.url);
        this->MB=ob.MB;
    }
    
    OnlineBook &operator=(const OnlineBook &ob){
        
        if(this!=&ob){
            Book::operator=(ob); //prepokriva
            delete[]url;
            this->url=new char[strlen(ob.url)+1];
            strcpy(this->url, ob.url);
            this->MB=ob.MB;
        }
        return *this;
    }
    
    ~OnlineBook(){
        delete [] url;
    }
    
    double bookPrice(){
        if(MB>20){
            return cena + (cena*20)/100;
        }
      
        return cena;
    }
    
    bool operator>(Book &b){
        if (bookPrice()>b.bookPrice()){
            return true;
        }
            return false;
    }
    
    friend ostream &operator<<(ostream &out, OnlineBook &OB){
        out<<OB.ISBN<<": "<<OB.naslov<<", "<<OB.avtor<<" "<<OB.bookPrice()<<endl;
        return out;
    }

    void setISBN(char *ISBN){
        strcpy(this->ISBN, ISBN);
    }

};

class PrintBook : public Book{
    
private:
    double kg;
    bool zaliha;
    
public:
    PrintBook() : Book(){
        
        this->kg=0;
        this->zaliha=false;
    }
    
    PrintBook(char *ISBN=" ", char *naslov=" ", char *avtor=" ", double cena=0.0, float kg=0.0, bool zaliha=false) : Book(ISBN, naslov, avtor, cena){
        
        this->kg=kg;
        this->zaliha=zaliha;
        
    }
    
    PrintBook(const PrintBook &pb):Book(pb){
        
        this->kg=pb.kg;
        this->zaliha=pb.zaliha;
        
    }
    
    PrintBook &operator=(const PrintBook &pb)
       {
           if (this!=&pb)
           {
               Book::operator=(pb);
               this->kg=pb.kg;
               this->zaliha=pb.zaliha;
           }
           return *this;
       }

    
    ~PrintBook(){}
    
    double bookPrice(){
        
        if(kg>0.7){
           return cena+(cena*15)/100;
        }
        return cena;
    }
    
    bool operator>(Book &b){
        if(bookPrice()>b.bookPrice()){
            return true;
        }
        return false;
    }
    
    friend ostream &operator<<(ostream &out, PrintBook &pb){
        out<<pb.ISBN<<": "<<pb.naslov<<", "<<pb.avtor<<" "<<pb.bookPrice()<<endl;
        
        return out;
    }
};

//void mostExpensiveBook (Book** books, int n){
//
//    int online_brojac=0, print_brojac=0;
//    Book *max=books[0];
//
//    for(int i=0;i<n;i++){
//        OnlineBook *ob=dynamic_cast<OnlineBook *>(books[i]);
//        PrintBook *pb=dynamic_cast<PrintBook *>(books[i]);
//
//        if (online_brojac != 0){
//            online_brojac++;
//        }
//
//        if(print_brojac != 0){
//            print_brojac++;
//        }
//
//    }
//
//        //vkupen broj na online knigi
//        //        if(online_brojac){
//        //            online_brojac++;
//        //        }
//        //        //vkupen broj na printani knigi
//        //        if(print_brojac){
//        //            print_brojac++;
//        //        }
//        //        //najskapata kniga
//        //        if(*books[i]>*max){
//        //            max=books[i];
//        //        }
//
//
//        cout << "FINKI-Education" << endl;
//        cout << "Total number of online books: " << online_brojac << endl;
//        cout << "Total number of print books: " << print_brojac << endl;
//        for (int i = 1; i < n; i++)
//            if (*books[i] > *max)
//                max = books[i];
//        cout << "The most expensive book is: " << endl;
//        cout << *max;
//}

void mostExpensiveBook (Book** books, int n){

    int online_brojac=0,pecatena_brojac=0;
    
    cout<<"FINKI-Education"<<endl;
    for(int i=0;i<n;i++){
        
        if(dynamic_cast<OnlineBook*>(books[i])!=0){
            online_brojac++;
        }
        else if(dynamic_cast<PrintBook*>(books[i])!=0) {
            pecatena_brojac++;
        }
        
//        2 opcija
//                OnlineBook *ob=dynamic_cast<OnlineBook *>(books[i]);
               //     PrintBook *pb=dynamic_cast<PrintBook *>(books[i]);

               // if (ob != 0){
               //     online_brojac++;
               // }

               // if(pb != 0){
               //     pecatena_brojac++;
               // }
    }
    
    cout<<"Total number of online books: "<<online_brojac<<endl;
    cout<<"Total number of print books: "<<pecatena_brojac<<endl;
    cout<<"The most expensive book is: "<<endl;
    
    int flag=1, max_indeks;
    double max;
    
    for(int i=0;i<n;i++){
        if(flag){
            max_indeks=i;
            max=books[i]->bookPrice();
            flag=0;
        }
        if(books[i]->bookPrice()>max){
            max_indeks=i;
            max=books[i]->bookPrice();
        }
    }
    cout<<*books[max_indeks]<<endl;
    
};

int main(){

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book  **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2){
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3){
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4){
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i<n; i++){

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            }
            else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i<n; i++) delete books[i];
        delete[] books;
    return 0;
}


 */


//7MA ZAD


/*
class OutOfBoundException{
public:
    void showMessage(){
        cout<<"Brojot na pin kodovi ne moze da go nadmine dozvolenoto"<<endl;
    }
};

class Karticka{
    
protected:

    char smetka[16];
    int pin;
    bool pin_kodovi;//dali ima poveke pin kodovi

public:
    Karticka(char *smetka=" ", int pin=0, bool pin_kodovi=true){
        strcpy(this->smetka,smetka);
        this->pin=pin;
        this->pin_kodovi=pin_kodovi;
    }

    Karticka(const Karticka &k){
        strcpy(this->smetka,k.smetka);
        this->pin=k.pin;
        this->pin_kodovi=k.pin_kodovi;
    }

    Karticka &operator=(const Karticka &k){
        if(this!=&k){
            strcpy(this->smetka,k.smetka);
            this->pin=k.pin;
            this->pin_kodovi=k.pin_kodovi;
        }
        return *this;
    }

    virtual int tezinaProbivanje(){
        int brojac=0;
        int temp=pin;
        while(temp>0){ //se delka pinot- se baraat cifrite
            brojac++;
            temp/=10;
        }
        return brojac;
    }
    
    virtual ~Karticka(){}

    friend ostream &operator<<(ostream &out,  Karticka &k){
        out<<k.smetka<<": "<<k.tezinaProbivanje()<<endl;
        return out;
    }

    bool getDopolnitelenPin(){
        return pin_kodovi;
    }

    const char *getSmetka() const {
        return smetka;
    }

};

class SpecijalnaKarticka:public Karticka{

protected:
    int *dopol_pinkodovi;
    int broj_pinkodovi;
    static const int P;
    //   static const int P=4;
public:
    SpecijalnaKarticka(char *smetka=" ", int pin=0, bool pin_kodovi=true, int *dopol_pinkodovi=0, int broj_pinkodovi=0) : Karticka(smetka, pin, pin_kodovi){

        this->dopol_pinkodovi= new int[broj_pinkodovi];
        this->broj_pinkodovi=broj_pinkodovi;
    }

    SpecijalnaKarticka(const SpecijalnaKarticka &sk) : Karticka(sk){
        this->broj_pinkodovi=sk.broj_pinkodovi;
        this->dopol_pinkodovi= new int[sk.broj_pinkodovi];
        for(int i=0;i<broj_pinkodovi;i++){
            this->dopol_pinkodovi[i]=sk.dopol_pinkodovi[i];
        }
    }

    SpecijalnaKarticka &operator=(const SpecijalnaKarticka &sk){
        if(this!=&sk){
            Karticka::operator=(sk);
            delete [] dopol_pinkodovi;
            this->dopol_pinkodovi= new int[sk.broj_pinkodovi];
            this->broj_pinkodovi=sk.broj_pinkodovi;
        }
        return *this;
    }

    ~SpecijalnaKarticka(){
        delete[]dopol_pinkodovi;
    }

     int tezinaProbivanje() override{
        return Karticka::tezinaProbivanje()+broj_pinkodovi;
    }

    SpecijalnaKarticka &operator+=(int PIN){
        if (broj_pinkodovi>=P){ //broj pinkodovi  e pogolem od 4 bidejki P=4
            throw OutOfBoundException();
        }
        else {
            int *tmp = new int[broj_pinkodovi + 1];
            for (int i = 0; i < broj_pinkodovi; i++) {
                tmp[i] = dopol_pinkodovi[i];
            }

            tmp[broj_pinkodovi++] = PIN;
            delete[] dopol_pinkodovi;
            dopol_pinkodovi = tmp;

            return *this;
        }
    }

};

class Banka {
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    static int LIMIT;
public:
    Banka(char *naziv, Karticka** karticki,int broj ){
        strcpy(this->naziv,naziv);
        for (int i=0;i<broj;i++){
            //ako kartickata ima dopolnitelni pin kodovi
            if (karticki[i]->getDopolnitelenPin()){
                this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(karticki[i]));
            }
            else this->karticki[i]=new Karticka(*karticki[i]);
        }
        this->broj=broj;
    }

    Banka(const Banka &b){
        strcpy(this->naziv,b.naziv);
        for (int i=0;i<broj;i++){
            //ako kartickata ima dopolnitelni pin kodovi
            if (karticki[i]->getDopolnitelenPin()){
                this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(b.karticki[i]));
            }
            else this->karticki[i]=new Karticka(*b.karticki[i]);
        }
        this->broj=b.broj;
    }

    static void setLIMIT(int limit);

    ~Banka(){
        for (int i=0;i<broj;i++) delete karticki[i];
    }

    void pecatiKarticki(){
        cout<<"Vo bankata "<< naziv<<" moze da se probijat kartickite:"<<endl;
        for(int i=0;i<broj;i++){
            if(karticki[i]->tezinaProbivanje() <= LIMIT){
                cout<< *karticki[i];
            }
        }
    }

    void dodadiDopolnitelenPin(char * smetka, int novPin){

        for(int i=0;i<broj;i++){
            SpecijalnaKarticka *sk = dynamic_cast<SpecijalnaKarticka *>(karticki[i]);
            if(sk!=0 && strcmp(karticki[i]->getSmetka(), smetka)==0) {
                try{
                    *sk+=novPin; //dodadi go noviot pin
                }
               catch(OutOfBoundException ob){
                   ob.showMessage();
               }
            }
        }
    }

};

const int SpecijalnaKarticka::P=4;
int Banka::LIMIT=7;

void Banka::setLIMIT(int limit) {
    LIMIT = limit;
}

int main(){

    Karticka **niza;
    int n,m,pin;
    char smetka[16];
    bool daliDopolnitelniPin;
    cin>>n;
    niza=new Karticka*[n];
    for (int i=0;i<n;i++){
        cin>>smetka;
        cin>>pin;
        cin>>daliDopolnitelniPin;
        if (!daliDopolnitelniPin)
            niza[i]=new Karticka(smetka,pin);
        else
            niza[i]=new SpecijalnaKarticka(smetka,pin);
    }

    Banka komercijalna("Komercijalna",niza,n);
    for (int i=0;i<n;i++) delete niza[i];
    delete [] niza;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>smetka>>pin;
            komercijalna.dodadiDopolnitelenPin(smetka, pin);
    }

    Banka::setLIMIT(5);

    komercijalna.pecatiKarticki();

}
*/


//MEDIASEGMENT - KOLOKVIUMSKA ZADACA
/*
Да се напише апстрактна класа што репрезентира медија сегмент ( MediaSegment ). За секој медија сегмент се дефинира:

Наслов (низа од најмногу. 100 знаци)
Автор (низа од најмногу 100 знаци)
Времетраење во секунди (позитивен цел број)
Големина на записот во мегабајти (позитивен цел број).
За класата да се имплементираат потребните методи/конструктори за правилно функционирање (според дадената функција main).

Од класата за MediaSegment да се изведат класите за аудио и видео запис.

Класата за аудио запис ( AudioRecording) репрезентира аудио снимка. За аудио записот се чува:

Формат на аудио записот: може да има една од следните вредности: mp3, wav, ogg и flac.
Број на канали - променлива од тип short.
За класата AudioRecording да се имплементираат потребните методи/конструктори за правилно функционирање (според дадената функција main ).
За класата да се обезбеди функција price што ja пресметува цената на аудио записот. Цената на аудио записот (изразена во евра) се добива на следниот начин:

Се пресметува производ од времетраењето (во секунди) и бројот на канали.
Ако форматот е flac тогаш пресметаниот производ во чекор 1 дополнително се зголемува за 50%
Да се преоптовари операторот << за печатење на информациите за аудио сегментот во форматот:

Наслов - Автор - Времетраeње - големина - цена
Класата за видео запис (VideoRecording) репрезентира видео снимка. За секој видео запис се чува:

Ширина на сликата на видео записот - позитивен цел број
компресија на видео записот - може да има една од следните вредности: х264, Theora, AV1
За класата VideoRecording да се обезбедат потребните методи/конструктори за правилно функционирање (според дадената функција main).

За класата да се обезбеди и функција price што пресметува цена на видео записот. Цената на видео записот (изразена во евра) се пресметува на следниот начин:

Ако ширината е помала или еднаква на 1920 тогаш видео записот чини 100 евра по секунда. Ако ширината е поголема од 1920 тогаш цената е 170 евра по секунда.
Ако компресијата е x264 тогаш пресметаната цена во чекор 1 дополнително се зголемува за 50%. Ако компресијата е Theora, пресметаната цена во чекор 1 се намалува за 10%.
Да се преоптовари операторот << за печатење на информациите за видео записот во формат:

Наслов - Автор - Времетраeње - големина - димензии - цена
Да се креира класа Музичко видео (MusicVideo) што истовремено наследува од класите AudioRecording и VideoRecording. Класата треба чува:

Датум на публикација - низа од знаци во форматот ddmmgggg.
Да се обезбеди метод price за пресметување на цената на музичкото видео. Таа се пресметува како сума од цената на аудио и на видео записот. Ако датумот на публикација е по 2010 година, цената дополнително се зголемува за 30%.

Да се преоптовари операторот << за печатење на информациите за музичкото видео во форматот:

Наслов - Автор - датум на публикација - Времетраeње - цена
Да се имплементира глобална функција total_price што прима низа од покажувачи од тип MediaSegment и нивниот број и пресметува колку чинела продукцијата на сите тие записи.

Да се имплементира глобална функција cheapest_music_video што прима низа од покажувачи од тип MediaSegment и нивниот број и го враќа најевтиното музичко видео во рамките сите записи.
*/

/*
class MediaSegment{
    
protected:
    char naslov[100];
    char avtor[100];
    int seconds;
    int MB;
    
public:
    MediaSegment(char *naslov=" ", char *avtor=" ", int seconds=0, int MB=0){
        
        strcpy(this->naslov, naslov);
        strcpy(this->avtor, avtor);
        this->seconds=seconds;
        this->MB=MB;
    }
    
    virtual float price()=0;
    
};


enum tipFormat{
    mp3,wav,ogg,flac
};

enum tipKompresija{
    x264,Theora,AV1
};

class AudioRecording : virtual public MediaSegment{
    
protected:
    tipFormat format;
    short int brKanali;
    
public:
    AudioRecording(char *naslov=" ", char *avtor=" ", int seconds=0, int MB=0, tipFormat format=mp3, short int brKanali=0) : MediaSegment(naslov,avtor,seconds,MB){
        
        this->format=format;
        this->brKanali=brKanali;
        
    }
    
    float price(){
        
        float proizvod=seconds*brKanali;
        
        if(format==flac){
            proizvod*=1.5; //1.5 bidejki e proizvod i mora so 1 d ase mnozi
        }
        return proizvod;
    }
                                            //const da se trgne
    friend ostream &operator<<(ostream &out, AudioRecording &ar){
        
        out<<ar.naslov<<" - "<<ar.avtor<<" - "<<ar.seconds<<"- "<<ar.MB<<" - "<<ar.price()<<endl;
        return out;
    }
    
};


class VideoRecording : virtual public MediaSegment{
    
protected:
    tipKompresija kompresija;
    int width;
    
public:
    VideoRecording(char *naslov=" ", char *avtor=" ", int seconds=0, int MB=0, tipFormat format=mp3, short int brKanali=0, tipKompresija kompresija=x264,int width=0) : MediaSegment(naslov,avtor,seconds,MB){
        
        this->kompresija=kompresija;
        this->width=width;
    }
    
    float price() {
        float cena_po_sekunda;
        if(width<=1920){
            cena_po_sekunda=100*seconds;//100 evra po sekunda
        }
        else{
            cena_po_sekunda=170*seconds;
        }
        
        if(kompresija==x264){
            cena_po_sekunda*=1.5;
        }
        else if(kompresija==Theora){
            cena_po_sekunda*=0.9; //ke namalama za 10%
        }
        return cena_po_sekunda;
    }
    
    
    friend ostream &operator<<(ostream &out, VideoRecording &vr){
        
        out<<vr.naslov<<" - "<<vr.avtor<<" - "<<vr.seconds<<"- "<<vr.MB<<" - "<<vr.width<<vr.price()<<endl;
        return out;
    }
    
    
};

class MusicVideo : public AudioRecording, public VideoRecording{
    
private:
    char date[9];
    
public:
    MusicVideo(char *naslov=" ", char *avtor=" ", int seconds=0, int MB=0, tipFormat format=mp3, short int brKanali=0, tipKompresija kompresija=x264,int width=0, char *date=" ") : AudioRecording(naslov,avtor,seconds,MB,format,brKanali) , VideoRecording(naslov,avtor,seconds,MB,format,brKanali,kompresija,width){
        
        strcpy(this->date, date);
    }
    
    //AKO PRAVI PROBLEM KAJ KONSTRUKTORITE VO KRAJNATA KLASA MOZE DA SE STAI OD MEDIASEGMENT I VO NEA DA GI HANDLAME OD AUDIORECORDING I OD VIDEORECORDING ELEMENTITE
    
//    MusicVideo (char *title = "", char *author = "', int duration = 0, int size = 0, int format = 0,
//    short channels = 0, int width = 0, int compression = 0, char *date = "01012020")
//    MediaSegment (title, author, duration, size) {
//    this->format = (AudioFormat) format;
//    this->channels = channels;
//    this->width = width;
//    this->compression = (VideoCompression) compression;
//    strcpy ( this-›date,  date);
    
    float price(){
        
        float result=AudioRecording::price() + VideoRecording::price();
        
        char year[5];
        
        strcpy(year, date+4); //poslednite 4 cifri od datumot - samo kon godinata da pokazuva
        
        int yearINT=atoi(year);
        
        //strcmp(year, "2010")>0
        
        if(yearINT>=2010){
            result*=1.3;
        }
        return result;
    }
           
    friend ostream &operator<<(ostream &out, MusicVideo &mv){
               
        out<<mv.naslov<<" - "<<mv.avtor<<" - "<<mv.date<<" - "<<mv.seconds<<" - "<<mv.price()<<endl;
               
        return out;
    }
    
};

float total_price(MediaSegment **segments, int n){
    
    float suma=0;
    for(int i=0;i<n;i++){
        suma+=segments[i]->price();
    }
    return suma;
}


MusicVideo *cheapest_music_video(MediaSegment **segments, int n){
        
    MusicVideo *min=nullptr;
    for(int i=0;i<n;i++){
        MusicVideo *mv = dynamic_cast<MusicVideo *>(segments[i]);
        if(mv!=0){ //ako e razlicen od 0, sme naisle na muzicko video
            if(min==nullptr){
                min=mv;
            }
            else if(min->price() > mv->price()){
                    min=mv;
            }
        }
    }
    return min;
}
*/


//KOLOKVIUMSKA

/*
Дадена е класа User во која се чуваат информации за корисничко име, име на компанијата во која работи и ниво на позицијата во компанијата (број од 1 - 10). Во класата се дефинирани сите потребни конструктори, оператори, set, get методи, оператор за печатење и вчитување. Оваа класа не треба да се менува.

Да се дефинира класа Group што ќе означува група корисници. Во неа се чуваат информации за:

Членовите на групата (динамички алоцирана низа од објекти од класата User)
Големина на групата (број на елементи во низата)
Име на групата (низа од најмногу 50 знаци)
За класата да се имплементираат:

Потребните конструктори и деструктор
метод void addMember (User & u)- што ќе додава нов член во групата. Ако веќе постои член со исто корисничко име, да се фрли исклучок од тип OperationNotSupported. Треба да се обезбеди справување со овој исклучок во функцијата main. При фаќање на овој исклучок да се испечати порака "Username already exists".
метод double rating() - што ќе го пресмета рејтингот на групата со формулата: (10 - просечно_ниво_на_позициите_на_членовите) * број_на_членови / 100.
Да се имплементира класа PrivateGroup во која покрај основните информации за една група ќе се чува и:

Капацитет на приватната група (цел број). Капацитетот е ист за сите приватни групи и иницијално има вредност 10. Тој може да се менува.
За класата да се имплеметнираат потребните конструктори и деструктор.

Во класата PrivateGroup да се препокријат методите од класата Group на следниот начин:

метод void addMember (User & u) - што ќе додава нов член во групата. Да не се дозволи надминување на капацитетот на групата. Ако се направи обид да се додаде член кога капацитетот е исполнет да се фрли исклучок од тип OperationNotSupported. Треба да се обезбеди справување со овој исклучок во функцијата main. При фаќање на овој исклучок да се испечати порака "The group’s capacity has been exceeded.".
метод double rating() - што ќе го пресмета рејтингот на групата со формулата: (10 - просечно_ниво_на_позициите_на_членовите) * (број_на_членови / капацитет_на_група) * коефициент_за_приватна_група. Коефициентот за приватна група е ист за сите приватни групи и изнесува 0.8. Тој не може да се менува!
За двете класи да се дефинира оператор за печатење <<. Форматот на печатење на двете групи погледнете го во првите два тест примера.
*/

/*
class OperationNotSupported{
    
protected:
    char message[30];
    
public:
    OperationNotSupported(char *message=" "){
        strcpy(this->message, message);
    }
    
    void showMessage(){
        cout<<message<<endl;
    }
    
};

class User {
protected:
char *username;
char *companyName;
int position;

    void copy (const User &u) {
        this->username = new char[strlen(u.username) + 1];
        strcpy (this->username,u.username);
        this->companyName = new char[strlen (u.companyName) + 1];
        strcpy (this->companyName,u. companyName);
        this->position = u.position;

    }


public:
    User(char *username = " ",char *companyName = "", int position = 0) {
        this->username = new char[strlen(username) + 1];
        strcpy( this->username,username);
        this->companyName = new char[strlen(companyName) + 1];
        strcpy (this->companyName,companyName);
        this->position = position;
    }

    User(const User &u){
        copy(u);
    }

    User &operator=(const User &u){
        if(this!=&u){
            delete [] username;
            delete [] companyName;
            copy(u);
        }
        return *this;
    }

    int getPosition () const {
        return position;
    }

    void setPosition(int position) {
    this->position = position;
    }

    friend ostream &operator<<(ostream &os, const User &user) {
    return os << "Username: " << user. username << " Company name: " << user.companyName << "Position: " << user.position;
    }

    friend istream &operator>> (istream &in, User &user) {
         in >> user.username >> user.companyName >> user.position;
        return in;
    }

    bool operator== (User &u) {
        return strcmp(this->username, u.username) == 0;
    }

};

class Group {

protected:
    User *users;
    int n;
    char name[50];
    
    void copy(const Group &g){
        strcpy(this->name,g.name);
        users=new User[n];
        for(int i=0;i<n;i++){
            users[i]=g.users[i];
        }
        this->n=g.n;
    }

public:
    Group(char *name="test"){
        strcpy(this->name,name);
        this->n=0;
        users=new User[n];
    }
    
    Group(const Group &g){
        copy(g);
    }
    
    Group &operator=(const Group &g){
        if(this!=&g){
            delete [] users;
            copy(g);
        }
        return *this;
    }
    
    ~Group(){
        delete [] users;
    }

    virtual void addMember (User & u){
        
        for(int i=0;i<n;i++){
            //ako veke postoi clen so isto korisnicko ime
            if(users[i]==u){ //frlame isklucok
                throw OperationNotSupported("Username already exists");//ako exception-ot pecati razlicni poraki za 2 klasi
            }
        }
        
        //ako ne najdeme takov user
        //DODAVAME USER
        User *tmp = new User[n+1];
        for(int i=0;i<n;i++){
            tmp[i]=users[i];
        }
        tmp[n++]=u;
        delete [] users;
        users=tmp;
    
    }
    
//    пресмета рејтингот на групата со формулата: (10 - просечно_ниво_на_позициите_на_членовите) * број_на_членови / 100.
    
    virtual double rating(){
        
        double sum=0;
        double rate=0;
        double prosek=0;
        for(int i=0;i<n;i++){
            sum+=users[i].getPosition(); //prosecno nivo na poziciite na clenovite;
        }
        if(n==0){
            return 0;
        }
//        return sum/n;
        prosek=sum/n;
        
        rate=(10-prosek)*(n/100.0);
        
        return rate;
        
    }
    
    friend ostream &operator<<(ostream &out, Group &g){
        out<<"Group: "<<g.name<<endl;
        out<<"Members: "<<g.n<<endl;
        out<<"Rating: "<<g.rating();
        out<<"Members list: "<<endl;
        if(g.n==0){
            return out<<"EMPTY"<<endl;
        }
        for(int i=0;i<g.n;i++){
            out<<i+1<<" "<<g.users[i]<<endl;
        }
        return out;
    }
    
};

class PrivateGroup:virtual public Group{
    
protected:
    static int CAPACITY;
    const static double COEFFICIENT;
    
public:
    PrivateGroup(char *name=" "):Group(name){
        
    }
    
    static void setCapacity(int newCapacity){
        CAPACITY=newCapacity;
    }
    
//    Да не се дозволи надминување на капацитетот на групата
    void addMember(User &u) override{
        if(this->n==CAPACITY) { //full ni e capacity
            throw OperationNotSupported("The group’s capacity has been exceeded."); //ako exception-ot pecati razlicni poraki za 2 klasi
        }
        Group::addMember(u); //go povikuvame ovoj metod ako ne ni e poln kapaciteto POTOCNO KE DODADE NOV USER - go prepokrivame metodot
    }
    
    double rating() override{
        
        double sum=0;
        double rata=0;
        double prosek=0;
        for(int i=0;i<n;i++){
            sum+=users[i].getPosition(); //prosecno nivo na poziciite na clenovite;
        }
        if(n==0){
            return 0;
        }
//        return sum/n;
        prosek=sum/n;
        
        rata=(10-prosek)*(this->n/CAPACITY)*(COEFFICIENT);
        
        return rata;
        
    }
    
    static void getCapacity(int newCapacity){
        CAPACITY=newCapacity;
    }
    
    friend ostream &operator<<(ostream &out, PrivateGroup &pg){
        out<<"Private";
        Group g(pg);
        out<<g;
    }
    
    
};

int PrivateGroup::CAPACITY=10;
const double PrivateGroup::COEFFICIENT=0.8;
*/

//5TA ZAD
/*
enum typeC{
    standard,
    loyal,
    vip
};

class UserExistsException{

public:

    void showMessage(){
        cout<<"The user already exists in the list"<<endl;
    }

};

class Customer {
protected:
    char name[MAX];
    char email[MAX];
    int numProducts;
    typeC kupuvac;
    static int POPUST_LOJALNI;
    const static int POPUST_VIP;

public:
    Customer(char const *name=" ", char const *email=" ", typeC kupuvac=standard, int numProducts=0){
        strcpy(this->name,name);
        strcpy(this->email,email);
        this->kupuvac=kupuvac;
        this->numProducts=numProducts;
    }

    Customer(const Customer &c){
        strcpy(this->name,c.name);
        strcpy(this->email,c.email);
        this->kupuvac=c.kupuvac;
        this->numProducts=c.numProducts;
    }

    Customer &operator=(const Customer &c){
        if(this!=&c){
            strcpy(this->name,c.name);
            strcpy(this->email,c.email);
            this->kupuvac=c.kupuvac;
            this->numProducts=c.numProducts;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out,Customer &c){
        out<<c.name<<endl;
        out<<c.email<<endl;
        out<<c.numProducts<<endl;

        //OBAVEZNO KASTIRANJE vo int
        if((int)c.kupuvac==0){
            out<<"standard 0"<<endl; //ili popust*0
        }
        else if((int)c.kupuvac==1){
            out<<"loyal "<<POPUST_LOJALNI<<endl;//c.popust
        }
        else if(c.kupuvac==2){
//            int zbir=c.popust+c.dopolnitelen_popust;
            out<<"vip "<<POPUST_LOJALNI+POPUST_VIP<<endl;

        }

        return out;
    }

    const char *getEmail() const{
        return email;
    }

    typeC getKupuvac() const;

    void setKupuvac(typeC t){
        kupuvac=t;
    }

    int getNumProducts() {
        return numProducts;
    }
    

    static void setDiscount1(int new_discount){
        POPUST_LOJALNI=new_discount;
    }

};

int Customer::POPUST_LOJALNI=10;
const int Customer::POPUST_VIP=20;

class FINKI_bookstore{

protected:
    Customer *customers;
    int num_customers;

public:
    FINKI_bookstore() {
        
        num_customers=0;
        customers=new Customer[num_customers];
    }

    FINKI_bookstore(const FINKI_bookstore &fb){
        this->num_customers=fb.num_customers;
        customers=new Customer[num_customers];//so fb.
        for(int i=0;i<num_customers;i++){
            customers[i]=fb.customers[i];
        }
    }

    void setCustomers(Customer *c,int n) {
        num_customers=n;
        customers=new Customer[n];
        for (int i = 0; i < n; ++i) {
            customers[i] = c[i];
        }
    }

    FINKI_bookstore &operator=(const FINKI_bookstore &fb) {
        if (this != &fb) {
            delete [] customers;
            this->num_customers=fb.num_customers;
            customers=new Customer[num_customers];//so fb.
            for(int i=0;i<num_customers;i++){
                customers[i]=fb.customers[i];
            }
    }
        return *this;
    }


    FINKI_bookstore &operator+=(const Customer &new_customer){
        for(int i=0;i<num_customers;i++){
            if(strcmp(customers[i].getEmail(),new_customer.getEmail())==0) {
                throw UserExistsException();
            }
        }
        Customer *temp = new Customer[num_customers + 1];

        for (int i = 0; i < num_customers; i++) {
            temp[i] = customers[i];
        }
        temp[num_customers++] = new_customer;
        delete[] customers;
        customers = temp;
        return *this;
    }

    void update(){
        for (int i = 0; i < num_customers; ++i) {
            if ((customers[i].getKupuvac()== standard) && (customers[i].getNumProducts() > 5)) {
                customers[i].setKupuvac(loyal);
            } else if ((customers[i].getKupuvac() == loyal) && (customers[i].getNumProducts() > 10)) {
                customers[i].setKupuvac(vip);
            }
        }
    }

    ~FINKI_bookstore(){
        delete [] customers;
    }

    friend ostream &operator<<(ostream &out, FINKI_bookstore &fb){
        for(int i=0;i<fb.num_customers;i++){
            out<<fb.customers[i];
        }
        return out;
    }

};


typeC Customer::getKupuvac() const {
    return kupuvac;
}


int main(){
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1){
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2){
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3){
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc <<endl;
    }

    if (testCase == 4){
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try{
            fc+=c;
        }
       catch (UserExistsException u){
            u.showMessage();
       }

        cout << fc;
    }

    if (testCase == 5){
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try{
            fc+=c;
        }
        catch (UserExistsException u){
            u.showMessage();
        }

        cout << fc;
    }

    if (testCase == 6){
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}
*/


//12zad

/*
class InvalidProductionDate {
public:
    void showMessage (){
        cout<<"Невалидна година на производство"<<endl;
    }
};

enum tip{
    smartphone, computer
};

class Device{
protected:
    char model[100];
    tip ured;
    static float proverka;
    int god;
public:
    Device(char *model=" ", tip ured=smartphone,  int god=0){
        strcpy(this->model, model);
        this->ured=ured;
        this->god=god;
    }

    float casovizaproverka (){
        if(god>2015&&ured==computer){
            return proverka+4;
        }
        else if(god>2015){
            return proverka+2;
        }
        else if(ured==computer){
            return proverka+2;
        }
        else {
            return proverka;
        }
    }

    friend ostream &operator<<(ostream &out, Device &d) {
        out << d.model << endl;
        if(d.ured){
            cout<<"Laptop";
        } else{
            cout<<"Mobilen";
        }
        out<< " " <<d.casovizaproverka()<< endl;
        return out;
    }

    int getGod() const {
        return god;
    }

    const char *getModel() const{
        return model;
    };

    tip getUred() const{
        return ured;
    };

    static float getProverka(){
        return proverka;
    };

    static void setPocetniCasovi(float newProverka){
        proverka=newProverka;
    }
};

float Device::proverka=1.0;


class MobileServis{

protected:
    char address[100];
    Device *devices;
    int n;

public:
    MobileServis(char *address=" "){
        strcpy(this->address, address);
        n=0;
        devices=new Device[n];
    }

    MobileServis(const MobileServis &ms){
        strcpy(this->address,ms.address);
        this->n=ms.n;
        devices= new Device[ms.n];
        for (int i = 0; i < ms.n; ++i) {
            devices[i]=ms.devices[i];
        }
    }

    MobileServis &operator=(const MobileServis &ms){
        if(this!=&ms){
            delete [] devices;
            strcpy(this->address, ms.address);
            n=ms.n;
            devices=new Device[ms.n];
            for(int i=0;i<ms.n;i++){
                devices[i]=ms.devices[i];
            }
        }
        return *this;
    }

    ~MobileServis(){
        delete [] devices;
    }


    MobileServis &operator+=(Device &newDevice){

        for(int i=0;i<n;i++){
            if((newDevice.getGod()>2019) || (newDevice.getGod())<2000){
                throw InvalidProductionDate();
            }
        }

        Device *tmp = new Device[n+1];
        for(int i=0;i<n;i++){
            tmp[i]=devices[i];
        }
        tmp[n++]=newDevice;
        delete [] devices;
        devices=tmp;
        return *this;

    }

    void pecatiCasovi(){
        cout << "Ime: " << address << endl;
        for (int i = 0; i < n; i++){
            cout << devices[i];
        }
    }


};

int main()
{
    int testCase;
    cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> tipDevice;
        cin >> godina;
        Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
        MobileServis t(ime);
        cout<<ig;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{
                t+=tmp;
            }
            catch(InvalidProductionDate i){
                i.showMessage();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 3){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{
                t+=tmp;
            }
            catch(InvalidProductionDate i){
                i.showMessage();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 4){
        cout <<"===== Testiranje na konstruktori ======"<<endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{
                t+=tmp;
            }
            catch(InvalidProductionDate i){
                i.showMessage();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }
    if (testCase == 5){
        cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

            try{
                t+=tmp;
            }
            catch(InvalidProductionDate i){
                i.showMessage();
            }
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
        Device::setPocetniCasovi(2);
        t.pecatiCasovi();
    }

    if (testCase == 6){
        cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{
                t+=tmp;
            }
            catch(InvalidProductionDate i){
                i.showMessage();
            }
        }
        Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }

    return 0;

}
*/


//14ta ZAD

/*
class SMS{
    
protected:
    float cena_poraka;
    char broj[20];
    
public:
    SMS(float cena_poraka=0.0, char *broj=" "){
        this->cena_poraka=cena_poraka;
        strcpy(this->broj, broj);
    }
    
    virtual float SMS_cena()=0;
    
    friend ostream &operator<<(ostream &out, SMS &s){
        
        out<<"Tel: "<<s.broj<<" - "<<"cena: "<<s.cena_poraka<<"den."<<endl;
        return out;
    }
    
    virtual ~SMS(){}
    
    char *getBroj(){
        return broj;
    }
};

class RegularSMS: public SMS{
    
protected:
    bool roaming;
    char message[1000];
    static float STRANSTVO;
    const static float DOMA;
    
public:
    RegularSMS(char *broj=" ", float cena_poraka=0.0,char *message=" ", bool roaming=true):  SMS(cena_poraka,broj){
        
        this->roaming=roaming;
        strcpy(this->message, message);
    }
    
    float  SMS_cena(){
        float total=cena_poraka;
        if(roaming==true){
            total*=(1.0+STRANSTVO/100.0);
        }
        else {
            total*=(1+DOMA);
        }
        
        if(strlen(message)>160){
            total*=(1.0+strlen(message)/160.0);
        }
        return total;
    }
    
    friend ostream &operator<<(ostream &out, RegularSMS &rs){
        
        out<<"Tel: "<<rs.broj<<" - "<<"cena: "<<rs.cena_poraka<<"den."<<endl;
        return out;
    }
    
    static void set_rProcent(float newProcent){
        STRANSTVO=newProcent;
    }
    
};

float RegularSMS::STRANSTVO=300;
const float RegularSMS::DOMA=0.18;

class SpecialSMS: public SMS{
    
protected:
    bool humanitarni_celi;
    static float HUM_CELI;
    
public:
    
    SpecialSMS(char *broj=" ", float cena_poraka=0.0,bool humanitarni_celi=true):SMS(cena_poraka, broj){
        
        this->humanitarni_celi=humanitarni_celi;
    }
    
    float SMS_cena(){
        float total=cena_poraka;
        
        if(humanitarni_celi==false){
            total*=(1+HUM_CELI/100);
        }
        return total;
    }
    
    friend ostream &operator<<(ostream &out, SpecialSMS &ss){
        
        out<<"Tel: "<<ss.broj<<" - "<<"cena: "<<ss.cena_poraka<<"den."<<endl;
        return out;
    }
    
    static void set_sProcent(float newSProcent){
        HUM_CELI=newSProcent;
    }

};

float SpecialSMS::HUM_CELI=150;

void vkupno_SMS(SMS** poraka, int n){
    
    int regularsms=0, specialsms=0;
    float regularcena=0, specialcena=0;
    
    q
    
    cout<<"Vkupno ima "<< regularsms <<" regularni SMS poraki i nivnata cena e: "<< regularcena<<endl;
    cout<<"Vkupno ima "<< specialsms <<" specijalni SMS poraki i nivnata cena e: "<< specialsms<<endl;

}


int main(){

    char tel[20], msg[1000];
    float cena;
    float price;
    int p;
    bool roam, hum;
    SMS  **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 2){
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 3){
        cout << "====== Testing method vkupno_SMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i<n; i++){

            cin >> tip;
            cin >> tel;
            cin >> cena;
            if (tip == 1) {

                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;
                
                sms[i] = new RegularSMS(tel, cena, msg, roam);

            }
            else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }

        vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 4){
        cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            sms1 = new RegularSMS(tel, cena, msg, roam);
            cout << *sms1;
        
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cin >> p;
            RegularSMS::set_rProcent(p);
            sms2 = new RegularSMS(tel, cena, msg, roam);
            cout << *sms2;
        
        delete sms1, sms2;
    }
    if (testCase == 5){
        cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
            cin >> tel;
            cin >> cena;
            cin >> hum;
            sms1 = new SpecialSMS(tel, cena, hum);
            cout << *sms1;
        
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cin >> p;
            SpecialSMS::set_sProcent(p);
            sms2 = new SpecialSMS(tel, cena, hum);
            cout << *sms2;
        
        delete sms1, sms2;
    }
    
    return 0;
}
*/

//13ZAD

/*
class Image{
    
protected:
    
    char *name;
    char user_name[50];
    int width;
    int height;
    
public:
    Image(char *name="untitled", char *user_name="unknown", int width=800, int height=800){
        
        this->name=new char[strlen(name)+1];
        strcpy(this->name, "untitled");
        strcpy(this->user_name, "unknown");
        this->width=800;
        this->height=800;
        
    }
    
    Image(const Image &i){
        
        this->name=new char[strlen(i.name)+1];
        strcpy(this->name, i.name);
        strcpy(this->user_name, i.user_name);
        this->width=i.width;
        this->height=i.height;
    }
    
    Image &operator=(const Image &i){
        
        if(this!=&i){
            delete [] name;
            this->name=new char[strlen(i.name)+1];
            strcpy(this->name, i.name);
            strcpy(this->user_name, i.user_name);
            this->width=i.width;
            this->height=i.height;
        }
        return *this;
    }
    
    ~Image(){
        delete [] name;
    }
    
    virtual int fileSize(){
 
        return width*height*3;
    }
    
    friend ostream &operator<<(ostream &out, Image &i){
        
        out<<i.name<<" "<<i.user_name<<" "<<i.fileSize()<<endl;
        return out;
    }
    
    bool operator>(Image &i){
        return fileSize() > i.fileSize();
    }
    
};

class TransparentImage : public Image{
    
protected:
    bool transparency;
    
public:
    TransparentImage(char *name="untitled", char *user_name="unknown", int width=800, int height=800, bool transparency=false) : Image(name, user_name, width, height){
        
        this->transparency=false;
    
    }
    
    TransparentImage(const TransparentImage &ti):Image(ti){
        this->transparency=ti.transparency;
    }
    
    TransparentImage &operator=(const TransparentImage &ti){
        if(this!=&ti){
            Image::operator=(ti);
            this->transparency=ti.transparency;

        }
        return *this;
    }
    
    ~TransparentImage(){}
    
    int fileSize(){
        if(transparency==true){
           return width*height*4;
        }
        else {
            return (width*height+(width*height)/8);
        }
    }
    
    friend ostream &operator<<(ostream &out, TransparentImage &ti){
        
        out<<ti.name<<" "<<ti.user_name<<" "<<ti.fileSize()<<endl;
        return out;
    }
    
    bool operator>(TransparentImage &ti){
        return fileSize() > ti.fileSize();
    }
    
};


class Folder{
    
protected:
    char name_folder[255];
    char user_folder[50];
    Image *images;
    int n;
    
public:
    Folder(char *name_folder=" ", char *user_folder="unknown"){
        
        images = new Image[100];
        strcpy(this->name_folder, name_folder);
        strcpy(this->user_folder, "unknown");
        this->n=0;
        
    }
    
    Folder(const Folder &f){
        images = new Image[100];
        strcpy(this->name_folder, f.name_folder);
        strcpy(this->user_folder, f.user_folder);
        this->n=f.n;
        for(int i=0;i<f.n;i++){
            images[i]=f.images[i];
        }
    }
    
    Folder &operator=(const Folder &f){
        if(this!=&f){
            delete [] images;
            images = new Image[100];
            strcpy(this->name_folder, f.name_folder);
            strcpy(this->user_folder, f.user_folder);
            this->n=f.n;
            for(int i=0;i<f.n;i++){
                images[i]=f.images[i];
            }
        }
        return *this;
    }
    
    int folderSize(){
        
        int suma=0;
        for(int i=0;i<n;i++){
            suma+=images[i].fileSize();
        }
        return suma;
    }
    
    ~Folder(){}
    
    Image *getMaxFile(){
        
        int index=0;
        //        int max[0];
        
        for(int i=0;i<n;i++){
            if(images[i].fileSize()>images[index].fileSize()){
                index=i;
            }
        }
        return &images[index];
    }
    
    Folder &operator+=( Image &slika){
        
        Image *tmp = new Image[n+1];
        
        for(int i=0;i<n;i++){
            tmp[i]=images[i];
        }
        tmp[n++]=slika;
        delete [] images;
        images=tmp;
        return *this;
        
    }
    
    friend ostream &operator<<(ostream &out, Folder &f){
        
        out<<f.name_folder<<" "<<f.user_folder<<" "<<f.getMaxFile()<<endl;
        out<<f.name_folder<<" "<<f.user_folder<<" "<<f.getMaxFile()<<f.folderSize()<<endl;
        
        return out;
    }

    
    //ke vrati int - sostaven e od integeri
    //OPERATOR [] - PRISTAP DO ELEMENT I PROMENA NA VREDNOST NA ELEMENT OD POLETO
    Image *operator[](int index){
        
        if(index >= 0 && index<n){
            
            return &images[n];
            
        }
        return NULL;
    }
    
    Folder max_folder_size(Folder **folders, int n){
        
        int max=0;
        
        for(int i=0;i<n;i++){
            
            if(folders[i]->folderSize()>folders[max]->folderSize()){
                max=i;
            }
        }
        
        return *folders[max];
    }
    
};


int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;


      Image f1;

      cout<< f1;

      Image f2(name);
      cout<< f2;

      Image f3(name, user_name);
      cout<< f3;

      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;

      TransparentImage tf1;
      cout<< tf1;

      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image * f;
      TransparentImage *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        Image* f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

      cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
};
*/



//11 ZAD
/*
class Delo{
    
protected:
    char name[50];
    int year;
    char country[50];
    
public:
    Delo(char *name=" ", int year=0, char *country=" "){
        
        strcpy(this->name, name);
        this->year=year;
        strcpy(this->country, country);
        
    }
    
    bool operator==(Delo &d){
        
        if(strcmp(d.name, name)==0){
            return true;
        }
        return false;
        
    }
    
    int getYear(){
        return year;
    }
    
    char *getCountry(){
        return country;
    }
    
    char *getIme(){
        return name;
    }
    
};

class Pretstava{
    
protected:
    Delo dela;
    int num_tickets;
    char date[15];
    
public:
    Pretstava(Delo dela=0, int num_tickets=0, char *date=" "){
        
        this->dela=dela;
        this->num_tickets=num_tickets;
        strcpy(this->date, date);
    } 
    
    virtual int cena(){
        
        int N=0, M=0;
        
        if(dela.getYear() >= 1900 && dela.getYear()< 2000){
            M=50;
        }
        else if(dela.getYear() >= 1800 && dela.getYear()<1900 ){
            M=75;
        }
        else if(dela.getYear()<1800){
            M=100;
        }
        if(strcmp(dela.getCountry(), "Italija")==0){
            N=100;
        }
        else if(strcmp(dela.getCountry(), "Rusija")==0){
            N=150;
        }
        else {
            N=80;
        }
        return N+M;
    }
    
    Delo getDelo(){
        return dela;
    }
    
    virtual int get_BrKarti(){
        return num_tickets;
    }
    
};

class Opera : public Pretstava{
    
private:
    
public:
    Opera(Delo dela=0, int num_tickets=0, char *date=" ") : Pretstava(dela,num_tickets, date){
        
    }
    
};


class Balet : public Pretstava{
    
private:

    static int CENA;
    
public:
    Balet(Delo dela=0, int num_tickets=0, char *date=" ") : Pretstava(dela,num_tickets, date){
        
    }
    
 int cena(){
        
        return Pretstava::cena() + CENA;
    }
    
    static void setCenaBalet(int newCena){
        CENA=newCena;
    }
    
};

int Balet::CENA=150;

int prihod(Pretstava **pretstavi,int n)
{
    int prihod=0;
    for(int i=0; i<n; i++)
    {
        prihod+=pretstavi[i]->cena()*pretstavi[i]->get_BrKarti();
    }
    return prihod;
}

int brojPretstaviNaDelo(Pretstava **pretstavi, int n, Delo delo){
    
    int brojac=0;
    for(int i=0;i<n;i++){
        if(pretstavi[i]->getDelo()==delo){
            brojac++;
        }
    }
    return brojac;

}




//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;
    
    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDelo().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDelo().getIme()<<endl;
    }break;
        
    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;
    
    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        Delo f1=readDelo();
        Delo f2=readDelo();
        Delo f3=readDelo();
        
        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
    
    }break;
    
    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        
        }
        cout<<prihod(pole,n);
    }break;
    
    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;
        
    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        
        Delo f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;
    
    };


return 0;
}

*/


//4 ZAD

/*
class Pizza{
    
protected:
    char name[21];
    char ingredients[101];
    float cena;
    
public:
    Pizza(char *name=" ", char *ingredients=" ", float cena=0){
        
        strcpy(this->name, name);
        strcpy(this->ingredients, ingredients);
        this->cena=cena;
        
    }
    
    virtual float price()=0;
    
    friend ostream& operator<<(ostream& out, Pizza &p){
        out<<p.name<<": "<<p.ingredients<<", ";
        return out;
    }
    
    bool operator<( Pizza &p){
                return this->price()<p.price();
    }
    
    virtual float getPrice(){
        return cena;
    }
    
};


enum Size{
    mala,golema,familijarna
};

class FlatPizza:public Pizza{
    
private:
    Size size;
    
public:
    FlatPizza(char *name=" ", char *ingredients=" ", float cena=0, Size size=mala):Pizza(name,ingredients,cena){
        
        this->size=size;
        
    }
    
    float price(){
     
        int suma=0;
        if(size==mala){
            suma=cena*1.1;
        }
        else if(size==golema){
            suma=cena*1.2;

        }
        else {
            suma=cena*1.3;

        }
        return suma;
    }
    
    friend ostream &operator<<(ostream &out, FlatPizza &fp){
        
        out<<static_cast<Pizza&>(fp);
        
        if(fp.size==mala){
            out<<"small - ";
        }
        else if(fp.size==golema){
            out<<"big - ";
        }
        else
            out<<"family - ";
        out<<fp.price()<<endl;
        
        return out;
    }
    
//    bool operator<(FlatPizza &fp){
//        return price() < fp.price();
//    }

};


class FoldedPizza:public Pizza{
    
protected:
    
    bool whiteFlour;
    
public:
    FoldedPizza(char *name=" ", char *ingredients=" ", float cena=0, bool whiteFlour=true):Pizza(name,ingredients,cena){
        
        this->whiteFlour=whiteFlour;
        
    }
    
    float price(){
        int suma=0;
        if(whiteFlour==1){
            suma = cena*1.1;
        }
        else
            suma=cena*1.3;
        return suma;
    }
    
    
    friend ostream &operator<<(ostream &out, FoldedPizza &fop){
        
        
        out<<static_cast<Pizza &>(fop);
        if(fop.whiteFlour){
            out<<"wf - ";
        }
        else
            out<<"nwf - ";
        
        out<<fop.price()<<endl;
        
        return out;
    }
    
//    bool operator<(FoldedPizza &fop){
//        return price() < fop.price();
//    }
//
    void setWhiteFlour(bool wf){
        this->whiteFlour=wf;
    }
    
};


void expensivePizza(Pizza **pizzas, int n){
    
    Pizza *p = pizzas[0];
    
//    int index=0;
//    for(int i=0;i<n;i++){
//        if(pizzas[i]->price() > pizzas[index]->price()){
//            index=i;
//        }
//    }
    
    for(int i=0;i<n;i++){
        if(pizzas[i]->price() > p->price()){
            p=pizzas[i];
        }
    }
    
    FlatPizza *f = dynamic_cast<FlatPizza*>(p);
    if(f)
        cout<<*f<<endl;

    FoldedPizza *fp = dynamic_cast<FoldedPizza*>(p);
        
    if(fp)
        cout<<*fp<<endl;
    
}



int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Size size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Size)s);
    cout << fp;
    
  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setWhiteFlour(false);
    cout << fp;

  } else if (test_case == 5) {
    // Test Cast - operator <, price
    int s;
    
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp1;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp2;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setWhiteFlour(false);
    cout << *fp4;
      
    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->price()<<endl;
    else cout<<fp2->price()<<endl;
        
    if(*fp1<*fp3)
        cout<<fp1->price()<<endl;
    else cout<<fp3->price()<<endl;
        
    if(*fp4<*fp2)
        cout<<fp4->price()<<endl;
    else cout<<fp2->price()<<endl;
    
    if(*fp3<*fp4)
        cout<<fp3->price()<<endl;
    else cout<<fp4->price()<<endl;

  } else if (test_case == 6) {
    // Test Cast - expensivePizza
    int num_p;
    int pizza_type;

    cin >> num_p;
    Pizza **pi = new Pizza *[num_p];
    for (int j = 0; j < num_p; ++j) {

      cin >> pizza_type;
      if (pizza_type == 1) {
        cin.get();
        cin.getline(name,20);
          
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << (*fp);
        pi[j] = fp;
      }
      if (pizza_type == 2) {

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp =
            new FoldedPizza (name, ingredients, inPrice);
        if(j%2)
          (*fp).setWhiteFlour(false);
        cout << (*fp);
        pi[j] = fp;

      }
    }

    cout << endl;
    cout << "The most expensive pizza:\n";
    expensivePizza(pi,num_p);


  }
  return 0;
}
*/


//10zad
/*
class NegativnaVrednost{

public:
    void showMessage(){
        cout<<"Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!"<<endl;
    }
};

class Oglas {
    char naslov[50];
    char kategorija[30];
    char opis[100];
    double cena;
public:
    Oglas(char * naslov=" ",char * kategorija=" ",char * opis=" ",double cena=0){
        strcpy(this->naslov,naslov);
        strcpy(this->kategorija,kategorija);
        strcpy(this->opis,opis);
        this->cena=cena;
    }

    bool operator>(Oglas &o){
        return this->cena>o.cena;
    }

    friend ostream & operator<<(ostream  &out,Oglas &o){
        out<<o.naslov<<endl;
        out<<o.opis<<endl;
        out<<o.cena<<" evra"<<endl;
        return out;
    }

    double getCena() const {
        return cena;
    }

    const char *getNaslov() const {
        return naslov;
    }

    const char *getOpis() const {
        return opis;
    }

    const char *getKategorija() const {
        return kategorija;
    }

};

class Oglasnik {
private:
    char ime[20];
    Oglas *oglasi;
    int n;
public:
    Oglasnik(char * ime=""){
        strcpy(this->ime,ime);
        this->n=0;
        oglasi=new Oglas[n];

    }

    Oglasnik(const Oglasnik &og){
        strcpy(this->ime,og.ime);
        this->n=og.n;
        oglasi=new Oglas[og.n];
    }

    Oglasnik &operator=(const Oglasnik &og){
        if(this!=&og){
            delete [] oglasi;
            strcpy(this->ime,og.ime);
            this->n=og.n;
            oglasi=new Oglas[og.n];
            for(int i=0;i<og.n;i++){
                oglasi[i]=og.oglasi[i];
            }
        }
       return *this;
    }

    Oglasnik &operator+=(const Oglas &og){
        if(og.getCena()<0){
            throw NegativnaVrednost();
        }

        Oglas *temp=new Oglas[n+1];
        for (int i = 0; i < n; ++i) {
            temp[i]=oglasi[i];
        }
        temp[n++]=og;
        delete [] oglasi;
        oglasi= temp;
        return *this;
    }

    friend ostream &operator<<(ostream &out, Oglasnik &og){

        out<<og.ime<<endl;
        for(int i=0;i<og.n;i++){
            out<<og.oglasi[i]<<endl;
        }

        return out;
    }

    ~Oglasnik(){
        delete [] oglasi;
    }


    int getN() const {
        return n;
    }

    void oglasiOdKategorija(const char *k){
        for (int i = 0; i < n; ++i) {
            if(strcmp(oglasi[i].getKategorija(),k)==0){
                cout<<oglasi[i]<<endl;
            }
        }
    }

    void najniskaCena(){

        int index=0;
        for(int i=0;i<n;i++){
            if(oglasi[i].getCena() < oglasi[index].getCena()){
                index=i;
            }
        }
        cout<<oglasi[index]<<endl;
    }

};

int main(){

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin>>tip;

    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
        cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
        cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl += o;
            }
            catch(NegativnaVrednost &n){
                n.showMessage();
            }
        }
        cout<<ogl;
    }
    else if (tip==4){
        cout<<"-----Test oglasOdKategorija -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl += o;
            }
            catch(NegativnaVrednost &n){
                n.showMessage();
            }
        }
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

    }
    else if (tip==5){
        cout<<"-----Test Exception -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl += o;
            }
            catch(NegativnaVrednost &n){
                n.showMessage();
            }
        }
        cout<<ogl;

    }
    else if (tip==6){
        cout<<"-----Test najniskaCena -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl += o;
            }
            catch(NegativnaVrednost &n){
                n.showMessage();
            }
        }
        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }
    else if (tip==7){
        cout<<"-----Test All -----" <<endl ;
        cin.get();
        cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
            Oglas o(naslov, kategorija, opis, cena);
            try {
                ogl += o;
            }
            catch(NegativnaVrednost &n){
                n.showMessage();
            }
        }
        cout<<ogl;

        cin.get();
        cin.get();
        cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
        ogl.oglasiOdKategorija(k);

        cout<<"Oglas so najniska cena:"<<endl;
        ogl.najniskaCena();

    }

    return 0;
}

*/
