#include <stdio.h>

//student e imeto na strukturata koe se koristi za DEKLARIRANJE NA PROMENLIVI OD TIPOT STRUKTURA
struct Student
{    //posledovatelni se elementite
    char ime[30];
    int indeks;
    float prosek;
    
    struct Student * a; //pokazuva kon PROMENLIVA vo taa struktura, NE KON SAMATA STRUKTURA
    //pointerot cuva adresa
};
//ovie se narekuvaat fields(polinja) ili clenovi


//struktura vo struktura - finki_student e posebna struktura i se cuva druga struktura od tipot student
struct finki_student
{
    char pol;
    char adresa[20];
    //struct student lice;
    float stipendija;
} apsolventi[100];

//typedef struct finki_student apsolvent;

struct vraboten2{
    
    char ime[20];
    char prezime[20];
    int vozrast;
    char pol;
    double plata;
    
    struct vraboten2 *vPok; //pokazuvac
} s, *p; //pokazuva kon tipot struktura s

//isto kako

//struct Student s
//struct Student *p

//int main() {
//
//    //GOLEMINATA NA s e 30+4+4=38 bajti vkupno sve od strukturata.
//
//    //struct Student s; //deklariram promenliva od tipot struct s
//
//    //so s imame pristap do site podatoci
//
//    struct Student s = {"Ivan", 123, 6.6, NULL};
//
//    printf("%s %d %f %p", s.ime, s.indeks, s.prosek, s.a);
//
//    return 0;
//}




/*
struct koordinati_tocka{
    
    float tocka_x;
    float tocka_y;
    
};

typedef struct koordinati_tocka tocka;

struct pravoagolnik{
    
    tocka pt1;
    tocka pt2;
    
};

typedef struct pravoagolnik pravoagolnik;

tocka centar(pravoagolnik p){
    
    tocka c;
    c.tocka_x=(p.pt1.tocka_x+p.pt2.tocka_x)/2;
    c.tocka_y=(p.pt1.tocka_y+p.pt2.tocka_y)/2;
    
    return c; //novata tocka koja e kreirana
    
}

float povrsina(pravoagolnik r){
    
    return((r.pt2.tocka_x-r.pt1.tocka_x)*(r.pt2.tocka_y-r.pt2.tocka_y));
    
}

int main(){
    

    return 0;
}
*/



//se dava celobrojna vrednsot na promenliva sto sme ja dale
//pocnuvaat od 0
            //1         2       3       4...
enum Day{Sun=100, Mon=2, Tue=3, Wed=4, Thu=5, Fri=6, Sat=7};

//elementite vnatre vo enum se koristeni kako integer - redni broevi, ne kako strings

int main(){
    
    enum Day today = Sun;
    
    printf("%d", today); //go dava redniot broj zadaden za elementot
    
    //if(today==1 || today == 7){
//    if(today==Sun || today == Sat){
//        printf("It's the weekend\n");
//    }
//    else {
//        printf("Treba da rabotam\n");
//    }
    
    return 0;
}
