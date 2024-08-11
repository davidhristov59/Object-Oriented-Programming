#include <iostream>
#include <cstring>

using namespace std;

//OSNOVI NA C++
    
/*
    struct student{
        
        char ime[20];
        char prezime[20];
        int  indeks;
        int poeni;
        
        //funkcija clenka na strukturata
        void print(){ //funkcija za pecatenje
            cout<<ime<<" "<<prezime<<" "<<indeks<<" "<<poeni<<endl; //nov red
        }
    };

    void sort(student studenti[], int n){
        
        int temp,i,j;
        
        //    for(i=0;i<n;i++){
        //        for(temp=0;temp<n-i-1;temp++){
        //
        //        }
        //    }
        
        //sortirame
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                //swap - bubble sort
                if(studenti[temp].poeni<studenti[temp+1].poeni){ //vo opagacki redosled
                    student pom=studenti[temp];
                    studenti[temp]=studenti[temp+1];
                    studenti[temp+1]=pom;
                }
            }
        }
    }

    int main(){
        
        student studenti[100]; //max 100 studenti - nova niza deklarirame
        int j;
        int poeni=0;
        int i,n; //ke zacuvame informacija kolku studenti saka da vnese korisnikot
        cin>>n;
        
        for(i=0;i<n;i++){
            cin>>studenti[i].ime;
            
            //elementot na nulta pozicija da bide golema bukva od istiot toj element
            studenti[i].ime[0]=toupper(studenti[i].prezime[0]);
            
            cin>>studenti[i].prezime;
            cin>>studenti[i].indeks;
            
            for(j=0;j<4;j++){ //deka se 4 zadaci
                cin>>poeni;
                studenti[i].poeni+=poeni; //ako vneseme 2 poeni i se dodavaat vo poenite na studentot, potoa 5 ako vneseme se dodavaat vo poenite na studentot.
            }
        }
        
        sort(studenti,n);
        
        for(i=0;i<n;i++){
            studenti[i].print();//ja povikuvame funkcijata print za pritnanje na elementite
        }
        
        return 0;
    }
*/

//OD PREDAVANJE 2

//:: - scope operator - ja zima vrednosta na globalnata promenliva

/*
int ccc=987;
int main(){
    
    int ccc=123;
    cout<< "main ccc="<< ccc <<endl; //123
    cout<< "global ccc="<< ::ccc <<endl; //987
    {
        int ccc=456;
        cout << "Inner ccc="<< ccc << endl; //456
        cout << "Global ccc=" << ::ccc << endl; //987
        {
            int ccc=789;
            cout << "Innest ccc=" << ccc << endl; //789
            cout << "Global ccc=" << ccc << endl; //987
            ::ccc=321; //sega tuka e globalnata i ovaa ostanuva
        }
        cout << "Inner ccc=" << ccc << endl; //456
        cout << "Global ccc=" << ::ccc << endl; //321
    }
    cout << "main ccc=" << ccc << endl; //123 - se zima vo main-ot
    cout << "Global ccc=" << ::ccc << endl; //321
    
    return 0;
}
*/


/*
void show( int = 1, float = 2.3, long = 4 );
int main()
{
show(); // All three arguments default
show( 5 ); // Provide 1st argument
show( 6, 7.8 ); // Provide 1st and 2nd
show( 9, 10.11, 12L ); // Provide all three arguments
// show( , 3.5, 7L); - NE MOZE BIDEJKI NEMA DADENO PRVA VREDNOST
}
void show( int first, float second, long third )
{
cout << "first = " << first;
cout << ", second = " << second;
cout << ", third = " << third;
cout << endl;
return;
}

//PRVO - 1 , 2.3, 4
//VTORO - 5, 2.3, 4
//TRETO - 6, 7,8, 4
//CETVRTO - 9, 10.11, 12

*/


/*
int mynum=100;
inline int &num() {
return mynum;
}
int main()
{
    int i;
    int x=123;
    int &y=x;
    cout << "x= " << x << " y= " << y << endl;  //123 123
    x=23;
    cout << "x= " << x << " y= " << y << endl; //23 23
    x++;
    cout << "x= " << x << " y= " << y << endl; //24 24
    y++;
    cout << "x= " << x << " y= " << y << endl; //25 25
    i=num();
    cout << "i= " << i << " mynum= " << mynum << endl; //100 100
    num()=5;
    cout << "mynum= " << mynum <<endl; //5
    cout << " num()= " << num()++ << endl; //5
    cout << "mynum= " << mynum << endl; //6 - ke se zgolemi prvo tuka
    cout << "++num()= " << ++num() << endl; //7 - od 6 use ednas ke se inkrementira i ke bide 7
}
*/


//3 vidovi - samo vrednost, so pokazuvaci i so referenci
/*
void swapByVal(int a, int b)
{
int t=a; a=b; b=t;
}

void swapByPtr(int *a, int *b)
{
int t=*a; *a=*b; *b=t;
}

void swapByRef(int &a, int &b)
{
    int t=a; a=b; b=t;
}

int main()
{
    int x=1, y=2;
    cout << " Initial: x=" << x << " y=" << y << endl;
    swapByVal(x,y);
    cout << "After swapByVal(x,y): x=" << x << " y=" << y << endl << endl;
    
    x=1, y=2;
    cout << " Initial: x=" << x << " y=" << y << endl;
    swapByPtr(&x,&y); //menuva vrednostite naopaku
    cout << "After swapByVal(&x,&y): x=" << x << " y=" << y << endl << endl;
    
    x=1, y=2;
    cout << " Initial: x=" << x << " y=" << y << endl;
    swapByRef(x,y); //menuva vrednostite naopaku
    cout << "After swapByRef(x,y): x=" << x << " y=" << y << endl;
    
    return 0;
}
*/


