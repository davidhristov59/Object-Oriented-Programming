#include <iostream>
#include <cstring>

using namespace std;

/*
class Airplane{
  
private:
    char ID[12];
    char *company_name;
    char company_airport[20];
    int state;
    int flight_hours;
    
public:
    Airplane(char *ID=" ", char *company_name=" ", char *company_airport=" ", int state=0, int flight_hours=0){
        
        strcpy(this->ID, ID);
        this->company_name=new char[strlen(company_name)+1];
        strcpy(this->company_name, company_name);
        strcpy(this->company_airport, company_airport);
        this->state=state;
        this->flight_hours=flight_hours;
        
    }
    
    Airplane(const Airplane &a){
        strcpy(this->ID, a.ID);
        this->company_name=new char[strlen(a.company_name)+1];
        strcpy(this->company_name, a.company_name);
        strcpy(this->company_airport, a.company_airport);
        this->state=a.state;
        this->flight_hours=a.flight_hours;
    }
    
    Airplane &operator=(const Airplane &a){
        if(this!=&a){
            delete [] company_name;
            strcpy(this->ID, a.ID);
            this->company_name=new char[strlen(a.company_name)+1];
            strcpy(this->company_name, a.company_name);
            strcpy(this->company_airport, a.company_airport);
            this->state=a.state;
            this->flight_hours=a.flight_hours;
        }
        return *this;
    }
    
    ~Airplane(){
        delete [] company_name;
    }
    
    void print(){
        cout<<"ID: "<<ID<<" - ";
        if(state==1){
            cout<<"REPAIRING ";
        }
        else if(state==0){
            cout<<"NOT_WORKING ";
        }
        else {
            cout<<"WORKING ";
        }
        cout<<company_name<<", "<<flight_hours<<", "<<company_airport<<endl;
    }
    
    int get_state(){
        return state;
    }
    
    char *get_companyname(){
        return company_name;
    }
    
    int get_flighthours(){
        return flight_hours;
    }
    
    void set_state(int state){
        this->state=0;
    }
    
    char *get_companyairport(){
        return company_airport;
    }
    
};

class AirportService{
    
private:
    
    char ime_aerodrom[20];
    Airplane *airplanes;
    int broj_avioni;
    
public:
    
    AirportService(char *ime_aerodrom=" ", Airplane *airplanes=0, int broj_avioni=0){
        strcpy(this->ime_aerodrom, ime_aerodrom);
        this->broj_avioni=0;
        this->airplanes=0;
    }
    
    AirportService(const AirportService &as){
        strcpy(this->ime_aerodrom, ime_aerodrom);
        this->broj_avioni=as.broj_avioni;
        this->airplanes=as.airplanes;
        for(int i=0;i<broj_avioni;i++){
            airplanes[i]=as.airplanes[i];
        }
    }
    
    AirportService &operator =(const AirportService &as){
        if(this!=&as){
            delete [] airplanes;
            strcpy(this->ime_aerodrom, ime_aerodrom);
            this->broj_avioni=as.broj_avioni;
            this->airplanes=as.airplanes;
            for(int i=0;i<broj_avioni;i++){
                airplanes[i]=as.airplanes[i];
            }
        }
        return *this;
    }
    
    ~AirportService(){
        delete [] airplanes;
    }
    
    
    void addAirplane(Airplane plane){
        if(plane.get_state()==0){
            plane.set_state(1); //. Кога авион се додава во сервисот неговата состојба преминува во состојба СЕ_ПОПРАВА
            for(int i=0;i<broj_avioni;i++){
                if(strcmp(airplanes[i].get_companyname(), plane.get_companyname())==0){
                    if(plane.get_flighthours()>airplanes[i].get_flighthours()){
                        
                        airplanes[i]=plane;
                    }
                    return;
                }
            }
            Airplane *tmp=new Airplane[broj_avioni+1];
            for(int i=0;i<broj_avioni;i++){
                tmp[i]=airplanes[i];
            }
            delete [] airplanes;
            tmp[broj_avioni++]=plane;
            airplanes=tmp;
        }
    }
    
    Airplane serviceOldestAirplane(){
        
        Airplane oldest = airplanes[0];
        int index=0;
        
        for(int i=1;i<broj_avioni;i++){
            if(airplanes[i].get_flighthours()>oldest.get_flighthours()){
                oldest=airplanes[i];
                index=i;
            }
            else if(airplanes[i].get_flighthours()==oldest.get_flighthours()){
                if(strcmp(airplanes[i].get_companyairport(), ime_aerodrom)==0){
                    index=i;
                }
            }
        }
        
        Airplane *tmp=new Airplane[broj_avioni-1];
        for(int i=0,j=0;i<broj_avioni;i++){
            tmp[j++]=airplanes[i];
        }
        broj_avioni--;
        delete [] airplanes;
        airplanes=tmp;
        oldest.set_state(2); //ISPRAVEN
        return oldest;
    }
    
    void print(){
        cout<<ime_aerodrom<<endl;
        for(int i=0;i<broj_avioni;i++){
            if(airplanes[i].get_state()==1){ //se naogaat na popravka
                airplanes[i].print();
            }
        }
    }
    
};


int main() {
    int testCase;
    cin >> testCase;
    char ID[12];
    char company_name[20];
    char company_airport[20];
    int flight_hours;
    int state;
    if (testCase == 1) {
        cout << "TESTING CONSTRUCTOR FOR AIRPLANE" << endl;
        Airplane a;
        cout << "TEST FOR DEFAULT CONSTRUCTOR PASSED" << endl;
        Airplane a1("ZHN-96-TY", "FINKI-Airline", "TMF", 13);
        cout << "TEST FOR CONSTRUCTOR WITH 3 ARGUMENTS PASSED" << endl;
        Airplane a2("ZHN-96-TA", "FINKI1-Airline", "TMF", 13, 0);
        cout << "TEST FOR CONSTRUCTOR WITH 4 ARGUMENTS PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING COPY-CONSTRUCTOR AND OPERATOR = (ASSIGNMENT) FOR AIRPLANE" << endl;
        Airplane p("ZHN-96-TA", "FINKI-Airline", "TMF", 13, 0);
        Airplane p1(p);
        cout << "TEST FOR COPY CONSTRUCTOR PASSED" << endl;
        Airplane p2;
        p2 = p;
        cout << "TEST FOR OPERATOR = (ASSIGNMENT) PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING PRINT() FOR AIRPLANE" << endl;
        cin>>ID>>company_name>>company_airport>>flight_hours>>state;
        Airplane p(ID, company_name, company_airport, flight_hours, state);
        p.print();
    } else if (testCase == 4) {
        cout << "TESTING CONSTRUCTOR FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        cout << "TEST PASSED" << endl;
    } else if (testCase == 5) {
        cout << "TESTING ADD() AND PRINT() FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ID>>company_name>>company_airport>>flight_hours>>state;
            Airplane p(ID, company_name, company_airport, flight_hours, state);
            as.addAirplane(p);
        }
        as.print();
    } else if (testCase == 6) {
        cout << "TESTING serviceOldestAirplane() AND PRINT() FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ID>>company_name>>company_airport>>flight_hours>>state;
            Airplane p(ID, company_name, company_airport, flight_hours, state);
            as.addAirplane(p);
        }
        Airplane p = as.serviceOldestAirplane();
        cout<<"Removed plane:"<<endl;
        p.print();
        cout<<"-----------------"<<endl;
        as.print();
    }  else if (testCase == 7) {
        cout << "TESTING COPY CONSTRUCTOR AND OPERATOR = FOR AIRPORTSERVICE" << endl;
        AirportService as("FINKI");
        Airplane a1("ZHN-96-TY", "FINKI-Airline", "TMF", 13);
        as.addAirplane(a1);

        AirportService s1 = as; //copy constructor
        AirportService s2;
        s2 = s1; //operator =
        s1.print();
        s2.print();
    }
    return 0;
}
*/


//MENE MI SE PADNA 
/*
class Vehicle
{
private:
    char registracija[9];
    char *ime;
    int lokacija;
    int kapacitet;
    double brojNaIzvozeniKilometri=0.0;//?
public:
    //Defolten konstruktor
    Vehicle()
    {
        strcpy(this->registracija,"");
        this->ime=new char[0];//this->ime=NULL;//this->ime=0;
        this->lokacija=0;
        this->kapacitet=0;
        this->brojNaIzvozeniKilometri=0.0;
    }
    //Konstruktor so parametri
    Vehicle(char *registracija,char *ime,int lokacija,int kapacitet)
    {
        strcpy(this->registracija,registracija);
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->lokacija=lokacija;
        this->kapacitet=kapacitet;
        this->brojNaIzvozeniKilometri=0.0;
    }
    //Copy konstruktor
    Vehicle(const Vehicle &v)
    {
        strcpy(this->registracija,v.registracija);
        this->ime=new char[strlen(v.ime)+1];
        strcpy(this->ime,v.ime);
        this->lokacija=v.lokacija;
        this->kapacitet=v.kapacitet;
        this->brojNaIzvozeniKilometri=v.brojNaIzvozeniKilometri;
    }
    //Operator =
    Vehicle &operator=(const Vehicle &v)
    {
        if(this!=&v)
        {
            strcpy(this->registracija,v.registracija);
            delete [] ime;
            this->ime=new char[strlen(v.ime)+1];
            strcpy(this->ime,v.ime);
            this->lokacija=v.lokacija;
            this->kapacitet=v.kapacitet;
            this->brojNaIzvozeniKilometri=v.brojNaIzvozeniKilometri;
        }
        return *this;
    }
    //Destruktor
    ~Vehicle()
    {
        delete [] ime;
    }
    //print metoda
    void print()
    {
        cout<<"ID: "<<registracija<<" "<<"Driver's name:"<<ime<<" Passenger  capacity: "<<kapacitet<<" Location: "<<lokacija<<" kms driven: "<<brojNaIzvozeniKilometri<<endl;
    }
    //get metoda
    char* get_registracija()
    {
        return registracija;
    }
    //get lokacija
    int get_lokacija()
    {
        return lokacija;
    }
  //get kapacitet
  int get_kapacitet()
  {
        return kapacitet;
  }
  //set lokacija
  void set_lokacija(int l)
  {
       lokacija=l;
  }
  //set brojNaIzvozeniKilometri
  void set_brojNaIzvozeniKilometri(int d)
  {
        brojNaIzvozeniKilometri+=d;
  }
  //get metoda za brojNaIzvozeniKilometri
  double get_brojNaIzvozeniKilometri()
  {
        return brojNaIzvozeniKilometri;
  }
};


class RideApp
{
private:
    char ime[21];
    Vehicle *niza_od_vozila;
    int brojNaVozila;
public:
    //Defolten konstruktor
    RideApp()
    {
        strcpy(this->ime," ");
        this->niza_od_vozila=new Vehicle[0];
        this->brojNaVozila=0;

    }
    //Konstrukor so argumenti
    RideApp(char *ime)
    {
        strcpy(this->ime,ime);
        this->niza_od_vozila=new Vehicle[0];
        this->brojNaVozila=0;
    }
    //Copy konstruktor
    RideApp(const RideApp &r)
    {
        strcpy(this->ime,r.ime);
        this->brojNaVozila=r.brojNaVozila;
        this->niza_od_vozila=new Vehicle[brojNaVozila];
        for(int i=0;i<brojNaVozila;i++)
        {
            this->niza_od_vozila[i]=r.niza_od_vozila[i];
        }
    }
    //Operator =
    RideApp &operator=(const RideApp &r)
    {
        if(this!=&r)
        {
            strcpy(this->ime,r.ime);
            this->brojNaVozila=r.brojNaVozila;
            delete [] niza_od_vozila;
            this->niza_od_vozila=new Vehicle[brojNaVozila];
            for(int i=0;i<brojNaVozila;i++)
            {
                this->niza_od_vozila[i]=r.niza_od_vozila[i];
            }
        }
        return *this;
    }
    //Destruktor
    ~RideApp()
    {
        delete [] niza_od_vozila;
    }
    //metoda print
    void print()
    {
        cout<<ime<<endl;
        for(int i=0;i<brojNaVozila;i++)
        {
            niza_od_vozila[i].print();
        }
    }
    //metoda signUpVehicle
    void signUpVehicle(Vehicle &vehicle)
    {
        int flag=1;
        for(int i=0;i<brojNaVozila;i++)
        {
            if(strcmp(niza_od_vozila[i].get_registracija(),vehicle.get_registracija())==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            Vehicle *temp=new Vehicle[brojNaVozila+1];
            for(int i=0;i<brojNaVozila;i++)
            {
                temp[i]=niza_od_vozila[i];
            }
            temp[brojNaVozila++]=vehicle;
            delete [] niza_od_vozila;
            niza_od_vozila=temp;
        }
    }
    //metoda void addRide
    void addRide(int area,int passengers,int distanceKm)
    {
        int minArea=area,maxArea=area;
        Vehicle nova[10];
        int brojac=0;
        for(int i=0;i<5;i++)
        {
            if(minArea<1 || maxArea>10)
            {
                break;
            }
            for(int j=0;j<brojNaVozila;j++)
            {
                if((niza_od_vozila[j].get_lokacija()==minArea || niza_od_vozila[j]==maxArea) && niza_od_vozila[j].get_kapacitet()>=passengers)
                {
                    nova[brojac]=niza_od_vozila[j];
                    brojac++;
                }
            }
            if(brojac!=0)
            {
                break;
            }
            minArea--;
            maxArea++;
        }
        int flag=1;
        double minKilometraza;
        Vehicle najmalaKilometraza;
        if(brojac==1)
        {
            nova[0].set_lokacija(area);
            nova[0].set_brojNaIzvozeniKilometri(distanceKm);
        }else
        {
            for(int i=0;i<brojac;i++)
            {
                if(flag)
                {
                    najmalaKilometraza=nova[i];
                    minKilometraza=nova[i].get_brojNaIzvozeniKilometri();
                    flag=0;
                }
                if(nova[i].set_brojNaIzvozeniKilometri()<minKilometraza)
                {
                    najmalaKilometraza=nova[i];
                    minKilometraza=nova[i].get_brojNaIzvozeniKilometri();
                }
            }
            najmalaKilometraza.set_lokacija(area);
            najmalaKilometraza.set_brojNaIzvozeniKilometri(distanceKm);
        }
    }

};
*/
