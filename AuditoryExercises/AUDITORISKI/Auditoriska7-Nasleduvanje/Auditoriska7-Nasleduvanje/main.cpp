#include <iostream>
#include <cstring>

using namespace std;

/*
Да се дефинира класа за репрезентација на тениски играч. За секој тениски
играч треба да се чуваат името, презимето како и тоа дали игра во лига (bool).
Од класата тениски играч да се изведе класа за рангиран тениски играч, која ќе
репрезентира играч кој игра на меѓународно ниво. За рангираните тениски
играчи дополнително треба да се чува и рангот на тенискиот играч
*/


/*
class TeniskiIgrach{
//private: za da mozhe nadvor od klasata ovie raboti da bidat nedostapni ama da bidat dostapni za site naslednici na ovaa klasa kje napravime mesto private protected da bide
//ako se private ovde, vo drugata klasa
protected:
    char *ime;
    char *prezime;
    bool igra_liga;

public:
    TeniskiIgrach(char *ime=" ", char *prezime=" ", bool igra_liga=true){
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->prezime=new char[strlen(prezime)+1];
        strcpy(this->prezime,prezime);
        this->igra_liga=igra_liga;
    }
    
    TeniskiIgrach(const TeniskiIgrach &tp) {
        this->ime=new char[strlen(tp.ime)+1];
        strcpy(this->ime,tp.ime);
        this->prezime=new char[strlen(tp.prezime)+1];
        strcpy(this->prezime,tp.prezime);
        this->igra_liga=tp.igra_liga;
    }

    TeniskiIgrach &operator=(const TeniskiIgrach &tp){
        if(this!=&tp){
            delete[]ime;
            delete[]prezime;
            this->ime=new char[strlen(tp.ime)+1];
            strcpy(this->ime,tp.ime);
            this->prezime=new char[strlen(tp.prezime)+1];
            strcpy(this->prezime,tp.prezime);
            this->igra_liga=tp.igra_liga;
        }
        return *this;
    }
    
    ~TeniskiIgrach()
    {
        delete[]ime;
        delete[]prezime;
    }
    
    bool Igra_vo_Liga(){
        return igra_liga;
    }

    friend ostream &operator<<(ostream &out, const TeniskiIgrach &tp){
       
        if(tp.igra_liga){
            out<<tp.ime<<" "<<tp.prezime<<", igra vo Liga";
        }
        else {
            out<<tp.ime<<" "<<tp.prezime<<", ne igra vo Liga";

        }
        return out;
    }

};

//rangiran teniski igrac nasleduva od teniskiigrac
//IZVEDUVAME NASLEDUVANJE
class RangiranTeniskiIgrach : public TeniskiIgrach{
private:
    int rank; //go dodavame rankot vo izvedena klasa

public:
   
    //vo konstruktorot vo izvedena klasa mora da se vklucat i promenlivite od osnovnata klasa
    //mora da go povikate konstruktorot na osnovnata klasa vo ramki na konstruktorot od izvedenata klasa : ...
    RangiranTeniskiIgrach(char *ime=" ", char *prezime=" ", bool igra_liga=true, int rank=0) :  TeniskiIgrach(ime,prezime, igra_liga){
        
        this->rank=rank;
    }
    
    //ovoj konstruktor e teniskiot igrac da go napravime rangiran teniski igrac
                                                         //copy konstruktor (bez referenca) - imeto i igra_liga ke se smestat vo nasiot rangiran teniski igrac-
    RangiranTeniskiIgrach(TeniskiIgrach &tp, int rank) : TeniskiIgrach(tp){
        this->rank=rank;
    }
    
    //copy konstruktor za rangiraniot teniski igrac
    //mozeme da go pratime copy konstruktorot od osnovnata klasa tennisplayer
    RangiranTeniskiIgrach(const RangiranTeniskiIgrach &rti) : TeniskiIgrach(rti){
        this->rank=rti.rank;
    }
    
    friend ostream &operator<<(ostream &out, const RangiranTeniskiIgrach &rti){
        
        out<<TeniskiIgrach(rti)<<" "<<rti.rank;
        return out;
        
    }
};


int main() {
    TeniskiIgrach rf("Roger", "Federer");
    TeniskiIgrach ng("Novak", "Djokovikj");
    cout << rf << endl;
    cout << ng << endl;
    //TennisPlayer t;
    RangiranTeniskiIgrach rn("Rafael", "Nadal", true, 2750);
    cout << rn << endl;
    TeniskiIgrach tp = rn;
    cout << tp << endl;
    //RankedTennisPlayer copy(tp);
    RangiranTeniskiIgrach copy(ng, 3320);
    cout << copy << endl;
    RangiranTeniskiIgrach copy1 = rn;
    cout << copy1 << endl;
    return 0;
}
*/


//2ra zad
/*Да се дефинира класа DebitAccount за работа со дебитна банкарска сметка. За
 секоја банкарска сметка треба да се чува име и презиме на корисникот (низа од
 макс. 100 знаци), број на сметка (long број) и моментално салдо (double). Да се
 овозможат методи за преглед на сметката, депонирање и подигнување на пари
 од сметката.
 Потоа да се дефинира класа CreditAccount што ќе овозможува корисникот на
 сметката да зема заем од банката. Треба да се овозможи механизам за
 пресметување на камата доколку корисникот должи пари на банката*/


/*
class DebitAccount{
    
protected:
    char owner[50];
    char accountNumber[16];
    double balance;
    
public:
    DebitAccount(char *owner=" ", char *accountNumber=" ", double balance=0.0){
        
        strcpy(this->owner, owner);
        strcpy(this->accountNumber, accountNumber);
        this->balance=balance;
    }
    
    void printReport(){
        
        cout<<"Owner: "<<owner<<endl;
        cout<<"Account number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    
    void deposit(double amount){
        
        balance+=amount;
    }
    
    void withdraw(double amount){
        if(amount<=balance){ //ako imame na smetka dovolno pari
            balance-=amount;
        }
        else {
            cout<<"You don't have sufficient funds"<<endl;
            cout<<"Withdrawing"<<balance<<endl;
            balance=0;
        }
    }
    
    ~DebitAccount() {}
    
};

class CreditAccount : public DebitAccount{

private:
    double limit;
    const double interest=0.05;
    double debt;
    
public:
    CreditAccount(double limit=0.0) : DebitAccount(owner,accountNumber,balance){
        
        this->limit=limit;
        
    }
    
    //ko nstruktor so 2 argumenti
    CreditAccount(const DebitAccount &da, double limit=0) : DebitAccount(da){
        this->limit=limit;
        this->debt=0;
    }
    
    void printReport(){
                    //scope operator pristapuvam do print report sto e vo osnovnata klasa
        DebitAccount :: printReport();
            cout<<"Debt: "<<debt<<endl;
    }
    
    void deposit(double amount){
        
        if(amount<=debt){
            debt-=amount;
            
        }
        else{
            balance+=(amount-debt);
            debt=0;
        }
    }
    
    void withdraw(double amount){
        
        if(balance>=amount){
            
            DebitAccount::withdraw(amount);
            
        }
        else {
            double diff=amount-balance;
        }
    }

};

*/


