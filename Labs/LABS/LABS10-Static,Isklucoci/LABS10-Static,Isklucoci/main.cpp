#include <iostream>
#include <cstring>

using namespace std;

//1va ZAD
/*
Дадени ви се класите User и SocialNetwork.
Во класата User се чуваат информации за корисничко име, возраст и бро на приатели во рамки на некоа социална мрежа.
Во класата SocialNetwork се чува листа на членови (обекти од класата User) и големина на листата.
Да се дополни почетниот код со следите работи:
1. Да се спречи додавае на корисник со векепостоечко корисничко име преку фрлане исклучок од тип UserAlreadyExistsException. Справете се со исклучокот на потребното место.
2. Да се додаде променлива за лимитот на дозволени приатели на еден корисник (цел броз). Променливата да важи за сите корисници (облекти од класа User) и истата да може да се менува преку методот setLimit. Инициално променливата да има вредност 3.
3. Да се фрли исклучок од тип UserNotFoundException во методот friendRequest доколку friendRequest или secondUsername не се кориснички имиьа на корисници во социзалната
мрежа. Справете се со исклучокот на потребното место.
4. Да се спречи зголемувае на броот на приатели на неко корисник (над дозволениот лимит) со исклучок од тип FriendsLimitExceeded Exception. Справете се со исклучокот на
потребното место.
*/


//class UserAlreadyExistsException{
//
//private:
//    char username[50];
//
//public:
//
//    UserAlreadyExistsException(char *username=" "){
//        strcpy(this->username, username);
//    }
//
//    void showMessage(){
//        cout<<"User with username: "<<username<<"already exists"<<endl;
//    }
//};
//
//class UserNotFoundException{
//
//private:
//    char username[50];
//
//public:
//    UserNotFoundException(char *username=" "){
//        strcpy(this->username, username);
//    }
//    void showMessage(){
//        cout<<"User: "<<username<<"is not found!"<<endl;
//    }
//
//};
//
//class FriendsLimitExceededException{
//
//private:
//    int num_friends;
//
//public:
//
//    FriendsLimitExceededException(int num_friends=0){
//        this->num_friends=num_friends;
//    }
//
//    void showMessage(){
//        cout<<"Can't have more than "<<num_friends<<" friends."<<endl;
//    }
//
//};
//
//class User {
//private:
//    char username[50];
//    int age;
//    int friends;
//
//public:
//    //2
//    static int LIMIT;
//    User(char *username = "", int age = 18) : age(age) {
//        strcpy(this->username, username);
//        friends = 0;
//    }
//
//    friend ostream &operator<<(ostream &os, const User &user) {
//        os << "Username: " << user.username << " Age: " << user.age << " # of friends: " << user.friends;
//        return os;
//    }
//
//    User &operator++() {
//        ++friends;
//        return *this;
//    }
//
//    static void setLimit(int newLimit){
//        LIMIT=newLimit;
//    }
//
//    friend class SocialNetwork;
//
//};
//
////2
//int User::LIMIT=3;
//
//class SocialNetwork {
//private:
//    User *users;
//    int n;
//public:
//    SocialNetwork() {
//        n = 0;
//        users = new User[n];
//    }
//
//    SocialNetwork &operator+=(User &u) {
//
//        //1
//        for(int i=0;i<n;i++){
//            if(strcmp(users[i].username, u.username)==0){
//                throw UserAlreadyExistsException(u.username);
//            }
//        }
//
//        User *tmp = new User[n + 1];
//        for (int i = 0; i < n; i++) {
//            tmp[i] = users[i];
//        }
//        tmp[n++] = u;
//        delete[] users;
//        users = tmp;
//        return *this;
//    }
//
// //   void friendRequest(char *firstUsername, char *secondUsername) {
//
////        User *firstUser=nullptr;
////        User *secondUser=nullptr;
////
////        for (int i = 0; i < n; i++) {
////            if (strcmp(users[i].username, firstUsername) == 0) {
////                for (int j = 0; j < n; j++) {
////                    if (strcmp(users[j].username, secondUsername) == 0) {
////                        ++users[i];
////                        ++users[j];
////                        return;
////                    }
////                }
////            }
////            if(!firstUser || !secondUser){
////                throw UserNotFoundException();
////            }
////
////            if(firstUser->friends >= User::LIMIT && secondUser->friends >= User::LIMIT){
////                throw FriendsLimitExceededException();
////            }
////
////        }
//
//   // }
//
//    void friendRequest(char *firstUsername, char *secondUsername) {
//        int ima1=0;
//        int ima2=0;
//        for (int i = 0; i < n; i++) {
//            if (strcmp(users[i].username, firstUsername) == 0) {
//                ima1=1;
//                for (int j = 0; j < n; j++) {
//                    if (strcmp(users[j].username, secondUsername) == 0) {
//                        ima2=1;
//                        if(users[i].friends < User::LIMIT && users[j].friends < User::LIMIT){
//                            ++users[i];
//                            ++users[j];
//                        }
//                        else {
//                            throw FriendsLimitExceededException(User::LIMIT);
//                            return;
//                        }
//                    }
//                }
//            }
//        }
//        if(ima2==0){
//            throw UserNotFoundException(secondUsername);
//        }
//        if(ima1==0){
//            throw UserNotFoundException(firstUsername);
//        }
//
//    }
//
//    friend ostream &operator<<(ostream &os, const SocialNetwork &network) {
//        os << "Users: " << endl;
//        for (int i=0;i<network.n;i++) {
//            os << network. users[i] << endl;
//        }
//        return os;
//    }
//};
//
//int main() {
//    SocialNetwork sn;
//    int n;
//    cin >> n;
//    for (int i=0;i<n;i++){
//        char username[50]; int age;
//        cin >> username >> age;
//        //1
//        //ako userot ima vekepostoecko korisnicko ime ke mu se prikaze porakata vo klasata
//        try{
//            User u(username, age);
//            sn += u;
//        }
//        catch(UserAlreadyExistsException u){
//            u.showMessage();
//        }
//
//    }
//
//    cout << "Registration of users " << endl;
//    cout << sn << endl;
//    cout << "Friend requests " << endl;
//
//    int friendships;
//    cin >> friendships;
//    for (int i=0;i<friendships;i++){
//        char username1[50], username2[50];
//        cin >> username1 >> username2;
//        //3
//        try{
//            sn.friendRequest(username1, username2);
//        }
//        catch(UserNotFoundException user){
//            user.showMessage();
//        }
//        catch(FriendsLimitExceededException friends){
//            friends.showMessage();
//        }
//
//    }
//
//    cout << sn << endl;
//
//    cout << "CHANGE STATIC VALUE" << endl;
//
//    int maxFriends;
//    cin >> maxFriends;
//    cin >> friendships;
//    User::setLimit(maxFriends);
//    for (int i=0;i<friendships;i++){
//        char username1[50], username2[50];
//        cin >> username1 >> username2;
//        try{
//            sn.friendRequest(username1, username2);
//        }
//
//        catch(FriendsLimitExceededException f){
//            f.showMessage();
//        }
//
//    }
//    cout << sn;
//    return 0;
//}




//TOCNAAA
//2ra zad

class InvalidTimeException{

public:
    void print(){
        cout<<"Time is not valid"<<endl;;
    }

};

class Race{

protected:
    char city[40];
    int year;
    int month;
    float seconds;
    float km;

public:
    Race(char *city=" ", int year=0, int month=0, float seconds=0.0, float km=0.0){
        strcpy(this->city, city);
        this->year=year;
        this->month=month;
        this->seconds=seconds;
        this->km=km;

    }

    virtual float heaviness(){
        return (float)seconds/km;
    }

    friend ostream &operator<<(ostream &out, Race &r){
        out<<r.city<<" "<<r.month<<"."<<r.year<<" "<<r.heaviness()<<endl;
        return out;
    }

};

class CarRace : public Race{

private:
    float *bestTimesPrep;
    int number_bestTimes;
    int num_Laps;
    static float CAR_KOEF;

public:
    CarRace(char *city=" ", int year=0, int month=0, float seconds=0.0, float km=0.0, float *bestTimesPrep=0, int number_bestTimes=0, int num_Laps=0):Race(city,year,month,seconds,km){

        this->number_bestTimes=number_bestTimes;
        this->num_Laps=num_Laps;
        this->bestTimesPrep=new float[number_bestTimes];
        for(int i=0;i<number_bestTimes;i++)
        {
            this->bestTimesPrep[i]=bestTimesPrep[i];
        }
    }

    CarRace(const CarRace &cr){
            this->number_bestTimes=cr.number_bestTimes;
            this->num_Laps=cr.num_Laps;
        for(int i=0;i<cr.number_bestTimes;i++){
            this->bestTimesPrep=&cr.bestTimesPrep[i];
        }
    }

    CarRace &operator=(const CarRace &cr){
        if(this!=&cr){
            delete [] bestTimesPrep;
            this->number_bestTimes=cr.number_bestTimes;
            this->num_Laps=cr.num_Laps;
            for(int i=0;i<number_bestTimes;i++){
                this->bestTimesPrep[i]=cr.bestTimesPrep[i];
            }
        }
        return *this;
    }


    float heaviness(){
        float prosek=0;

        for(int i=0;i<number_bestTimes;i++){
            prosek+=bestTimesPrep[i];
        }

        float averageBestTime=(prosek/(float)number_bestTimes);
        float heavy=Race::heaviness() + (averageBestTime*CAR_KOEF);

        if(num_Laps>15){
           return (float)heavy * 1.1;//se zgolemuva za 10%
        }
        else {
            return heavy;
        }

    }

    static void setKoeficient(float newKoeficient){
        CAR_KOEF=newKoeficient;
    }

    void setNumberLaps(int krugovi){
        num_Laps=krugovi;
    }

    CarRace operator +=(float vreme){

        if(vreme<10){
            throw InvalidTimeException();
        }

        float *tmp = new float[number_bestTimes+1];
        for(int i=0;i<number_bestTimes;i++){
            tmp[i]=bestTimesPrep[i];
        }
        tmp[number_bestTimes++]=vreme;
        delete [] bestTimesPrep;
        bestTimesPrep=tmp;
        return *this;

    }

//    ~CarRace(){
//        delete [] bestTimesPrep;
//    }

};

float CarRace::CAR_KOEF=0.3;

int main(){
    int testCase;
    cin >> testCase;
    char city[50];
    int year;
    int month;
    float bestTime;
    float length;
    float bestTimes[50];
    int n;
    int m;
    int izbor;
    int numberLaps;
    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        Race t(city, year, month, bestTime, length);
        cout<<t;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        cin>>n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];
        CarRace mgt(city, year, month, bestTime, length, bestTimes, n, numberLaps);
        cout << mgt;
        CarRace mgt2;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        Race **niza;
        cin >> m;
        niza = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (izbor == 1){
                niza[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                niza[i] = new CarRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje novo najdobro vreme za prvata CarRace
        float best;
        cin >> best;
        int flag = 1;
        for (int i = 0; i < m; i++){
            CarRace* nn = dynamic_cast<CarRace*>(niza[i]);
            if (nn != 0){
                flag = 0;
                try{ //ako se napravi obid da se dodade vreme
                    (*nn) += best;
                    break;
                }
                catch(InvalidTimeException i){
                    i.print();
                }
            }
        }


        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        CarRace mgt(city, year, month, bestTime, length);
        mgt.setNumberLaps(numberLaps);
        float vreme1,vreme2;
        cin>>vreme1>>vreme2;
        try{
            mgt+=vreme1;
            mgt+=vreme2;
        }
        catch(InvalidTimeException e)
        {
            e.print();
        }
        cout<<mgt;
    }

    if (testCase == 5){
        cout << "===== Testiranje na static clenovi ======" << endl;
        Race **niza;
        cin >> m;
        niza = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (izbor == 1){
                niza[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                niza[i] = new CarRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        CarRace::setKoeficient(0.7);
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }



    return 0;
}

