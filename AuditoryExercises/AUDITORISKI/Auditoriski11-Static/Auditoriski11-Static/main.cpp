#include <iostream>
#include <cstring>

using namespace std;

//static- site objekti ja imaat taa vrednosta, vazi za site objekti
//const static - ako vrednosta ne moze da se menuva
//const static tip_promenliva

/*
class User{

protected:
    int id;
    char username[50];
    static int ID_TRACKER; //statickite promenlivi se pisuvaat so golemi bukvi i so _
    //ovoj tracker ke se zgolemuva sekogas koga ke se povikuvaat konstruktorite

public:
    User (char * username = "test", int id = 0) {
        strcpy (this->username, username);
        this->id = ID_TRACKER++; //prviot objekt ke bide 1 i edinicata ke se zgolemi na 2, pa na 3ka ...
        
    }

    void print(){
        cout<< id << " "<<username<<endl;
    }

};

int User::ID_TRACKER = 1; //ja inicijaliziram na 1 od klasata USER

//static clenovite koi se deklarirani za 1 klasa se isti za site objekti od taa klasa

int main(){

 
        User u1 ("stefan"); // ID = 1
        User u2 ("trajce"); // ID = 2
        User u3 ("petko"); // ID = 3
    
        u1.print();
        u2.print();
        u3.print();
        
  
    //SEKVENCIJALNI SO STATIC - 1,2,3
//    1 stefan
//    2 trajce
//    3 petko

    return 0;
}
*/


//1va ZAD
/*
Секое плаќање преку картичка има некои подобности. Имено државата сакајќи
да го поттикне користењето на картичките, нуди поволни услови за плаќање.
Да се моделира основна класа Kartichka како и класи Master и Maestro кои ја
наследуваат. Една картичка е опишана со својот идентификациски број, како и
со салдото на сметката која ја претставува.
При плаќање со маестро картичка, секоја сума се плаќа со попуст од 5% за
СИТЕ корисници на маестро картичка. Овој процент е фиксен и не смее да се
менува!
При плаќање со мастер картичка, ако лимитот на картичката е над 6000 денари
тогаш попустот е 10%, наместо стандардните 3% за картички со лимит под 6000
денари.
Попустот од 10% е ист за сите корисници, но тој може да биде променет од
страна на Народна Банка.
 */


/*
class Karticka{
    
protected:
    char id[16];
    double balance;
    double limit;
    
public:
    Karticka(char *id=" ", double balance=0.0, double limit=0.0){
        
        strcpy(this->id, id);
        this->balance=balance;
        this->limit=limit;
    }
    
     void uplati(double suma){
        this->balance+=suma;
        //vo nasiot balance ke dodade suma na saldoto
    }
    
    virtual float isplati(double suma){
        
        if(balance>=suma){
            balance-=suma; //se odzema od saldoto(balansot)
            return suma;
        }
        else {
            return 0;
        }
    }
    
    virtual void print(){
        cout << id << " Balance: " << balance << " Limit: " << limit << endl;
    }
    
};

class MasterCard : public Karticka{
    
private:
    
     static float POPUST1;
     const static float POPUST2; //vrednost sto ne se menuva
    
public:
    MasterCard(char *id=" ", double balance=0.0, double limit=0.0) : Karticka(id,balance,limit){
        
    }
    
    //STATICKA FCJA KOJA PRISAPUVA DO STATICKI CLEN
    static void setPOPUST1(float newPOPUST1){ //fcja koja pristapuva do stasticki clen od klasta mora i taa da bide static
        
        POPUST1=newPOPUST1;
    }
    
    float isplati(double suma){
        if(limit>=6000){
            suma*=(1-POPUST1); //ако лимитот на картичката е над 6000 денари тогаш попустот е 10%
        }
        else {
            suma*=(1-POPUST2); //3%
        }
        return Karticka::isplati(suma);
    }
    
    void print(){
        cout<<"Master"<<endl;
        Karticka::print();
    }

};

float MasterCard::POPUST1=0.1; //NO MOZE DA SE PROMENI , ZNACI NE E CONST - 10%
const float MasterCard::POPUST2=0.03; //3%

    
class MaestroCard : public Karticka {
                  
private:

    const static float POPUST; //const - ne treba da bide promenliva

public:
    MaestroCard(char *id=" ", double balance=0.0, double limit=0.0) : Karticka(id,balance,limit){
        
    }
    
    float isplati(double suma){
        suma*=(1-POPUST);
        return Karticka::isplati(suma);
    }
    
    void print(){
        cout<<"Maestro"<<endl;
        Karticka::print();
    }
                   
                   
};

const float MaestroCard::POPUST=0.05; //popustot 5%

int main(){
    
    Karticka **cards=new Karticka *[4];
    cards[0]=new MasterCard("11111111111111", 8000,1000);
    cards[1]=new MasterCard("11111111111111", 4000,5000);
    cards[2]=new MaestroCard("111111111111113", 2000,2000);
    cards[3]=new MaestroCard("111111111111115", 0,10000);
    
    
    for(int i=0;i<4;i++){
        cards[i]->print();
    }
 
    MasterCard::setPOPUST1(0.15);//povik na staticki metod
    
    
    return 0;
}
*/


