#include <iostream>
#include <cstring>

using namespace std;

/*
class Employee{
  
protected:
    char ime[30];
    int godini;
    
public:
    Employee(char *ime=" ", int godini=0){
        strcpy(this->ime, ime);
        this->godini=godini;
    }
    
    virtual void displayInfo()=0;
    
};

class Payable{
  
protected:
    float plata;
    
public:
    Payable(float plata=0.0){
        this->plata=plata;
    }
    
    virtual float calculateSalary()=0;
    
};

class Developer : public Employee, public Payable{
  
private:
    char programskijazik[20];
    
public:
    Developer(char *ime=" ", int godini=0, float plata=0.0, char *programskijazik=" ") : Employee(ime,godini), Payable(plata){
        strcpy(this->programskijazik, programskijazik);
    }
    
    void displayInfo(){
        cout<<"-- Developer Information --"<<endl;
        cout<<"Name: "<<ime<<endl;
        cout<<"Age: "<<godini<<endl;
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Programming language: "<<programskijazik<<endl;
    }
    
    float calculateSalary(){
        
        float vkupnaplata;
        vkupnaplata=plata-(plata/10.0);
        return vkupnaplata;
    }
    
};

class Manager : public Employee, public Payable{
private:
    int broj_oddeli;
    
public:
    Manager(char *ime=" ", int godini=0, float plata=0.0, int broj_oddeli=0) : Employee(ime,godini), Payable(plata){
        
        this->broj_oddeli=broj_oddeli;
        
    }
    
    void displayInfo(){
        cout<<"-- Manager Information --"<<endl;
        cout<<"Name: "<<ime<<endl;
        cout<<"Age: "<<godini<<endl;
        cout<<"Salary: $"<<calculateSalary()<<endl;
        cout<<"Number of Departments: "<<broj_oddeli<<endl;
    }
    
    float calculateSalary(){
        float VkupnaPlata, temp;
        temp = ( plata * 5) / 100;
        VkupnaPlata = plata + (temp * broj_oddeli);
        return VkupnaPlata;
    }
        
};

double biggestSalary(Payable* payable[], int n) {
    Payable* maxSalaryEmployee = payable[0];

    for (int i = 1; i < n; i++) {
        if (payable[i]->calculateSalary() > maxSalaryEmployee->calculateSalary()) {
            maxSalaryEmployee = payable[i];
        }
    }

    return maxSalaryEmployee->calculateSalary();
}

int main()
{
    Payable* payable[5];
    Developer developers[5];
    Manager managers[5];
    int j=0, k=0;
    for(int i=0; i<5; i++)
    {
        char name[50];
        int age;
        double salary;
        cin>>name>>age>>salary;
        if(i%2==0)
        {
            char programmingLanguage[50];
            cin>>programmingLanguage;
            developers[j]=Developer(name, age, salary, programmingLanguage);
            developers[j].displayInfo();
            payable[i]=&developers[j];
            j++;
        }
        else {
            int numberOfDepartments;
            cin>>numberOfDepartments;
            managers[k]=Manager(name, age, salary, numberOfDepartments);
            managers[k].displayInfo();
            payable[i]=&managers[k];
            k++;
        }
    }
    cout<<endl<<"Biggest Salary: "<<biggestSalary(payable, 5);
    return 0;
}
*/


//2ra ZAD
//class Game{
//
//protected:
//    char title[40];
//
//public:
//    Game(char *title=" "){
//        strcpy(this->title, title);
//    }
//
//    virtual void displayInfo(){;
//        cout<<"Game: "<<title<<endl;
//    }
//
//    virtual int complexity()=0;
//
//};
//
//class BoardGame: virtual public Game{
//
//protected:
//    int maxPlayers;
//
//public:
//    BoardGame(char *title=" ", int maxPlayers=0):Game(title){
//
//        this->maxPlayers=maxPlayers;
//    }
//
//
//    int complexity() override {
//        if (maxPlayers>6) {
//            return 10;
//        }
//        else if (maxPlayers>3 && maxPlayers<6) {
//            return 5;
//        }
//        else if(maxPlayers<3){
//            return 3;
//        }
//        else {
//            return 0;
//        }
//}
//
//    void displayInfo() override{
//        Game::displayInfo();
//        cout<<"Max players: "<<maxPlayers<<endl;
//        cout<<"Complexity: "<<complexity()<<endl;
//    }
//
//};
//
//class CardGame : virtual public Game{
//
//protected:
//    int numCards;
//
//public:
//    CardGame(char *title=" ",int maxPlayers=0, int numCards=0):Game(title){
//
//        this->numCards=numCards;
//    }
//
//    int complexity() override{
//        if(numCards>20){
//            return 10;
//        }
//        else if(numCards>10 && numCards<20){
//            return 5;
//        }
//        else if(numCards<10){
//            return 3;
//        }
//        else {
//            return 0;
//        }
//    }
//
//    void displayInfo() override{
//        Game::displayInfo();
//        cout<<"Number of cards: "<<numCards<<endl;
//        cout<<"Complexity: "<<complexity()<<endl;
//    }
//
//    int getnumCards(){
//        return numCards;
//    }
//
//};
//
//class BoardCardGame : public BoardGame, public CardGame{
//
//public:
//    BoardCardGame(char *title=" ", int maxPlayers=0, int numCards=0):BoardGame(title, maxPlayers), CardGame(title, maxPlayers, numCards), Game(title){
//
//    }
//
//    int complexity(){
//        return (BoardGame::complexity()+CardGame::complexity())/2;
//    }
//
//    void displayInfo(){
//        Game::displayInfo();
//        cout<<"Complexity: "<<complexity()<<endl;
//    }
//};
//
//Game * mostComplexCardGame(Game **games, int n){
//
//    Game *mostComplex = nullptr;
//        int maxValue = 0;
//        for (int i = 0; i < n; i++) {
//            CardGame *cardGame = dynamic_cast<CardGame *>(games[i]);
//            if (cardGame) {
//                if (cardGame->complexity() > maxValue) {
//                    maxValue = cardGame->complexity();
//                    mostComplex = cardGame;
//                }
//            }
//        }
//        return mostComplex;
//
//}
//
//int main() {
//    char title[50];
//    int maxPlayers;
//    int numCards;
//    int n;
//    int choice;
//
//    cin>>choice;
//    if(choice==1)
//    {
//        cin>>title;
//        BoardCardGame boardCardGame(title, 8, 15);
//        boardCardGame.displayInfo();
//    }
//    else {
//
//        cin >> n;
//
//        Game **g = new Game *[n];
//        for (int i = 0; i < n; i++) {
//            cin >> choice;
//            if (choice == 1) {
//                cin >> title >> maxPlayers;
//
//                g[i] = new BoardGame(title, maxPlayers);
//            } else {
//                cin >> title >> numCards;
//
//                g[i] = new CardGame(title, numCards);
//            }
//
//        }
//
//        mostComplexCardGame(g,n)->displayInfo();
//
//    }
//
//    return 0;
//}
//
//

class Game{

protected:
    char title[40];

public:
    Game(char *title=" "){
        strcpy(this->title, title);
    }

    virtual void displayInfo()
    {
        cout<<"Game: "<<title<<endl;
    }

    virtual int complexity()=0;

};

class BoardGame: virtual public Game{

protected:
    int maxPlayers;

public:
    BoardGame(char *title=" ", int maxPlayers=0):Game(title){

        this->maxPlayers=maxPlayers;
    }


    int complexity()  {
        if (maxPlayers>6) {
            return 10;
        } else if (maxPlayers>3 && maxPlayers<6) {
            return 5;
        } else if(maxPlayers<3)
            return 3;
        else
            return 0;
    }

    void displayInfo() {
        Game::displayInfo();
        cout<<"Max players: "<<maxPlayers<<endl;
        cout<<"Complexity: "<<complexity()<<endl;
    }

};

class CardGame : virtual public Game{

protected:
    int numCards;

public:
    CardGame(char *title=" ", int numCards=0):Game(title){

        this->numCards=numCards;
    }

    int complexity(){
        if(numCards>20){
            return 10;
        }
        else if(numCards>10 && numCards<20){
            return 5;
        }
        else if(numCards<10){
            return 3;
        }
        else
            return 0;
    }

    void displayInfo() {
        Game::displayInfo();
        cout<<"Number of cards: "<<numCards<<endl;
        cout<<"Complexity: "<<complexity()<<endl;
    }

    int getnumCards(){
        return numCards;
    }

};

class BoardCardGame : public BoardGame, public CardGame{

public:
    BoardCardGame(char *title=" ", int maxPlayers=0, int numCards=0):BoardGame(title, maxPlayers), CardGame(title, numCards),Game(title){

    }

    int complexity(){
        return (BoardGame::complexity()+CardGame::complexity())/2;
    }

    void displayInfo(){

        Game::displayInfo();
        cout<<"Complexity: "<<complexity()<<endl;
    }
};


Game *mostComplexCardGame(Game **games, int n) {
    Game *mostComplex = nullptr;
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        CardGame *cardGame = dynamic_cast<CardGame *>(games[i]);
        if (cardGame) {
            if (cardGame->complexity() > maxValue) {
                maxValue = cardGame->complexity();
                mostComplex = cardGame;
            }
        }
    }
    return mostComplex;
}


int main() {
    char title[50];
    int maxPlayers;
    int numCards;
    int n;
    int choice;

    cin>>choice;
    if(choice==1)
    {
        cin>>title;
        BoardCardGame boardCardGame(title, 8, 15);
        boardCardGame.displayInfo();
    }
    else {

        cin >> n;

        Game **g = new Game *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> title >> maxPlayers;

                g[i] = new BoardGame(title, maxPlayers);
            } else {
                cin >> title >> numCards;

                g[i] = new CardGame(title, numCards);
            }

        }

        mostComplexCardGame(g,n)->displayInfo();

    }

    return 0;
}
