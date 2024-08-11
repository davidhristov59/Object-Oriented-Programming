#include <iostream>
#include <cstring>

using namespace std;

/*
Да се дефинира класата Kvadrat во коа што се чува информациа за:
• должината на страната а на квадратот (double)
За класата да се дефинираат:
• default конструктор
• конструктор со аргументи
• сору конструктор
• double perimetar ( ) што пресметува периметар на квадратот
• double plostina ( ) што пресметува плоштина на квадратот
• void pecati () што печати информации за квадратот како во тест примерите
Да се имплементира класа Pravoagolnik што наследува од класата Kvadrat. Во неа се чуваат дополнителни информации за:
• прошируването х на двете паралелни страни на квадратот (doubLe)
• прошируването у на другите две паралелни страни (double)
Правоаголникот всушност сега ке има 2 страни со должина а+х и две страни со должина ану.
За класата да се дефинираат:
• default конструктор
• конструктор Pravogolnik (const Kvadrat &k, double x, double y)
• сору конструктор
Да се препокризат трите методи дефинирани погоре за класата Kvadrat.
Наломени:
• Ако х и у се исти, тогаш формата не е правоголник туку е повторно квадрат. Во тоі случа; реа ( ) се повикува исто како за квадрат.
• При препокриване на методите во класата Pravoagolnik мора да има повик кон истоимените методи од класата Kvadrat
 
 input
 5
 4.5
 4
 10
 17.5
 8.9
 1 2
 1.5 2.5
 3 4.5
 7 7
 8 9
 2
 
OUTPUT
 ===Testiranje na klasata Pravoagolnik===
 Pravoagolnik so strani 5.5 i 6.5ima plostina P=35.75 i perimetar L=24
 Pravoagolnik so strani 5.5 i 6.5ima plostina P=35.75 i perimetar L=24
 Pravoagolnik so strani 13 i 14.5ima plostina P=188.5 i perimetar L=55
 Kvadrat so dolzina a=17.5 ima plostina P=306.25 i perimetar L=70
 Pravoagolnik so strani 16.9 i 17.9ima plostina P=302.51 i perimetar L=69.6
 
*/

//PRVA ZAD

/*
class Kvadrat{

protected:
    double a;

public:
    Kvadrat(double a=0.0){
        this->a=a;
    }

    Kvadrat(const Kvadrat &k){
        this->a=k.a;
    }

    double perimetar(){
        return 4*a;
    }

    double plostina(){
        return a*a;
    }

    void pecati(){
        cout<<"Kvadrat so dolzina a="<<a<<" ima plostina P="<<plostina()<<" i "<<"perimetar L="<<perimetar()<<endl;
    }
};

class Pravoagolnik : public Kvadrat {

private:
    double x;
    double y;

public:
    
    //moze i vaka namesto default
//    Pravoagolnik(double x=0.0, double y=0.0) : Kvadrat(a){
//        this->x=x;
//        this->y=y;
//    }

    Pravoagolnik() : Kvadrat(){
        x=0;
        y=0;
    }

    Pravoagolnik(const Kvadrat &k, double x, double y) : Kvadrat(k){
        this->x=x;
        this->y=y;
    }

    Pravoagolnik(const Pravoagolnik &p) : Kvadrat(p){

        this->x=p.x;
        this->y=p.y;
    }

    double perimetar(){

        return Kvadrat::perimetar()+2*(x+y);
    }

    double plostina(){
        return Kvadrat::plostina()+a*x+a*y+x*y;
    }

    void pecati(){
        if(x==y){
            a+=x;
            Kvadrat::pecati();
            return;
        }
        else {
            cout<<"Pravoagolnik so strani: "<<(a+x)<<" i "<<(a+y)<<" ima plostina P="<<plostina()<<" i "<<"perimetar L="<<perimetar()<<endl;
        }
    }

};

int main() {
    int n;
    double a,x,y;
    Kvadrat * kvadrati;
    Pravoagolnik * pravoagolnici;

    cin>>n;

    kvadrati = new Kvadrat [n];
    pravoagolnici = new Pravoagolnik [n];

    for (int i=0;i<n;i++){
        cin>>a;

        kvadrati[i] = Kvadrat(a);
    }

    for (int i=0;i<n;i++){
        cin>>x>>y;

        pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1){
        cout<<"===Testiranje na klasata Kvadrat==="<<endl;
        for (int i=0;i<n;i++)
            kvadrati[i].pecati();
    }
    else {
        cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
        for (int i=0;i<n;i++)
            pravoagolnici[i].pecati();
    }
}
*/



class NBAPlayer {
protected:
    char *name;
    char team[40];
    double points;
    double assists;
    double rebounds;

public:
    NBAPlayer(char const *name=" ", char const *team=" ", double points=0.0, double assists=0.0, double rebounds=0.0){

        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        strcpy(this->team,team);
        this->points=points;
        this->assists=assists;
        this->rebounds=rebounds;

    }

    NBAPlayer(const NBAPlayer &p){
        this->name=new char[strlen(p.name)+1];
        strcpy(this->name,p.name);
        strcpy(this->team,p.team);
        this->points=p.points;
        this->assists=p.assists;
        this->rebounds=p.rebounds;
    }

    NBAPlayer &operator=(const NBAPlayer &p) {
        if (this !=&p){
            delete [] name;
        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);
        strcpy(this->team, p.team);
        this->points = p.points;
        this->assists = p.assists;
        this->rebounds = p.rebounds;
        }
        return *this;
    }

    ~NBAPlayer(){
        delete[]name;
    }

    double rating(){
        return points*0.45+assists*0.3+rebounds*0.25;
    }

    void print(){
        cout<<name<<" - "<<team<<endl;
        cout<<"Points: "<<points<<endl;
        cout<<"Assists: "<<assists<<endl;
        cout<<"Rebounds: "<<rebounds<<endl;
        cout<<"Rating: "<<rating()<<endl;
    }

};

class AllStarPlayer:public NBAPlayer{
private:
    double allStarPoints;
    double allStarAssists;
    double allStarJumps;
public:

    AllStarPlayer() : NBAPlayer(){
        allStarPoints = 0;
        allStarAssists = 0;
        allStarJumps = 0;
    }

    AllStarPlayer(char *name, char *team, double points, double assists,double rebounds,
                  double allStarPoints, double allStarAssists, double allStarJumps) : NBAPlayer(name,team, points, assists, rebounds){

        this->allStarPoints=allStarPoints;
        this->allStarAssists=allStarAssists;
        this->allStarJumps=allStarJumps;

    }

    AllStarPlayer(NBAPlayer &P,double allStarPoints=0.0,double allStarAssists=0.0, double allStarJumps=0.0) : NBAPlayer(P){
        this->allStarPoints=allStarPoints;
        this->allStarAssists=allStarAssists;
        this->allStarJumps=allStarJumps;

    }

    AllStarPlayer(const AllStarPlayer &P) : NBAPlayer(P){
        this->allStarPoints=P.allStarPoints;
        this->allStarAssists=P.allStarAssists;
        this->allStarJumps=P.allStarJumps;

    }

//    AllStarPlayer(NBAPlayer &np, double allStarPoints, double allStarAssists,  double allStarJumps) : NBAPlayer(np){
//
//        this->allStarPoints=allStarPoints;
//        this->allStarAssists=allStarAssists;
//        this->allStarJumps=allStarJumps;
//
//    }
    
    AllStarPlayer &operator=(const AllStarPlayer &als){
        if(this!=&als){
            NBAPlayer::operator=(als);
            this->allStarPoints=als.allStarPoints;
            this->allStarAssists=als.allStarAssists;
            this->allStarJumps=als.allStarJumps;
        }
        return *this;
    }

    ~AllStarPlayer(){}

    double allStarRating(){
           return allStarPoints*0.3+allStarAssists*0.4+allStarJumps*0.3;
       }

    double rating(){
        return ((NBAPlayer::rating() + allStarRating()) / 2);
    }

    void print(){
        NBAPlayer::print();
        cout<<"All Star Rating: "<<allStarRating()<<endl;
        cout<<"New Rating: "<<rating()<<endl;
    }

};


int main() {

    char name[50];
    char team[40];
    double points;
    double assists;
    double rebounds;
    double allStarPoints;
    double allStarAssists;
    double allStarRebounds;

    NBAPlayer* players = new NBAPlayer[5];
    AllStarPlayer* asPlayers = new AllStarPlayer[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            players[i] = NBAPlayer(name, team, points, assists, rebounds);
            players[i].print();
        }
    }
    else if (n == 2) {

        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBAPlayer(name, team, points, assists, rebounds);
            asPlayers[i] = AllStarPlayer(players[i], allStarPoints, allStarAssists, allStarRebounds);
        }

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            players[i].print();

        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            asPlayers[i].print();

    }
    else if (n == 3) {

        for (int i = 0; i < 5; ++i) {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                         allStarPoints, allStarAssists, allStarRebounds);
        }
        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            asPlayers[i].print();

    }

    delete[] players;
    delete[] asPlayers;
}

