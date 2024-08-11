#include <stdio.h>
#include <ctype.h>


/*
 Date
Да се напише програма која ќе споредува два датуми (ден, месец, година) и ќе ја
пресмета разликата во денови од едниот до другиот датум. Пресметките да се
реализираат во посебни функции. За датумот да се дефинира посебна
структура date.
 */

/*
struct Date{
  
    //podatoci za datumot
    int den;
    int mesec;
    int godina;
    
};//d1,d2;

typedef struct Date datum; //samo datum ke pisuvam namesto celo struct Date

//

int compare(datum d1, datum d2){ //parametrite gi pisuvam prvo vo main-ot
    
    //gi sporeduvam datumite
    
    //za pogolem go zimame datumot sto e poblisku do segasnost
    
    if(d1.godina>d2.godina){ //ako prvata god e pogolema vraka 1
        
        return 1;
    }
    else if(d1.godina<d2.godina){ //naopaku
        
        return -1;
        
    }
    else { //AKO SE ISTI GODINITE
        
        //gi proveruva mesecite
        if(d1.mesec>d2.mesec){
            return 1;
        }
        else if(d1.mesec<d2.mesec){
            return -1;
        }
        
    else { //AKO SE ISTI MESECITE
            
            if(d1.den>d2.den){
                return 1;
            }
            else if(d1.den<d2.den){
                return -1;
            }
            else {
                return 0; //vraka 0 ako datumite se celosno isti
                
            }
        }
    }
}

//25.04.2003
//11.12.2003

int days_different(datum d1, datum d2){
    
    int denovi=d1.den-d2.den; //ja glea razlikata so odzemanje na denovite
    
    //25-11=14 - odi vo denovi
    
    //gi pretvora vo denoovi i godinite i mesecite so mnozenje na 30 i 365

    denovi+=(d1.mesec-d2.mesec)*30; //denovi+=razlikata negju mesecite ja pretvora vo denovi i 14 se dodava na denovi
    denovi+=(d1.godina-d2.godina)*365; //denovi+=razlikata megju godinite ja pretvora vo denovi i 14 se dodava na denovo
    
    return denovi;
}

int main() {
    
    //objekt od struktura datum i gi sodrzi site 3 od strukturata.Moze da gi primi i da pristapi sprema tie elementi vo strukturata od cij tip e podatokot.
    //Vo situacijava piusvame d1 i d2 bidejki treba da gi sporeduvame.
    datum d1;
    datum d2;
    
    scanf("%d.%d.%d",&d1.den,&d1.mesec,&d1.godina);
    scanf("%d.%d.%d",&d2.den,&d2.mesec,&d2.godina);
    
    if(compare(d1,d2)==0){
        printf("Datumite se isti");
    }
    else if(compare(d1,d2)==1){ //>0
        printf("Razlikata megju denovite e %d\n", days_different(d1, d2)); //ako prviot datum e pogolem od vtoriot zatoa d1 pa d2.
    }
    else {
        printf("Razlikata megju denovite e %d\n", days_different(d2, d1)); //ako vtoruot datum e pogolem od prviot zatoa d2 pa d1.
    }
    
    //25.05.1969
    //11.12.1999
    
    //1999-1969=30 god
    //30*365=10950
    //12-5=7*30=210
    //11-25=-14
    
    //vkupno:11146
    
    return 0;
}
*/

/*
1.5 Држави
Да се напише програма која од стандарден влез ќе чита податоци за држави и
на екран ќе го отпечати името и презимето на претседателот на државата чиj
што главен град има најмногу жители.

Податоци за држава:
• име
• претседател
• главен град
• број на жители.

Податоци за град:
• име
• број на жители.

Податоци за претседател:
• име
• презиме
• политичка партија.
*/


/*
//typedef struct pretsedatel
struct pretsedatel{

    char ime[20];
    char prezime[20];
    char politicka_partija[20];

}; //pretsedatel

typedef struct pretsedatel pretsedatel;

struct grad{

    char ime[20];
    int br_ziteli;

};

typedef struct grad grad;

struct drzava{

    char ime[20];
    int br_zhiteli;
    pretsedatel pr; //ova pr ke gi sodrzi elementite vo strukturata pretsedatel
    grad glaven_grad; //od tip grad

};

typedef struct drzava drzava;

int main(){

    int max=0,max_i=0;
    int n; //brojot na drzavi sto ke gi vneseme
    drzava drzavi[100]; //vnesuvame poveke drzavi
    //drzavi ima pristap do strukturata drzava i nejzinite elementi.
    scanf("%d", &n);
    printf("Vnesi podatoci za drzavata - ime,br zhiteli,ime na pretsedatel,prezime na predsedatel,politicka_partija,ime_glaven_grad,broj_na_ziteli");

    for(int i=0;i<n;i++){
        scanf("%s", drzavi[i].ime); //imeto na drzavata, go zimame od
        scanf("%d", &drzavi[i].br_zhiteli); //brojot na ziteli
        scanf("%s", drzavi[i].pr.ime);
        scanf("%s", drzavi[i].pr.prezime);
        scanf("%s", drzavi[i].pr.politicka_partija);
        scanf("%s", drzavi[i].glaven_grad.ime);
        scanf("%d", &drzavi[i].glaven_grad.br_ziteli);

        if(drzavi[i].glaven_grad.br_ziteli>max){ //barame max br na ziteli na gl.gra
            max=drzavi[i].glaven_grad.br_ziteli;
            max_i=i; //indeksot treba na drzavata sto glavniot grad ima najmnogu ziteli
        }

    }

    //optimalno
    for(int i=0;i<n;i++){
        printf("%s", drzavi[i].ime); //imeto na drzavata, go zimame od
        printf("%d", drzavi[i].br_zhiteli); //brojot na ziteli
        printf("%s", drzavi[i].pr.ime);
        printf("%s", drzavi[i].pr.prezime);
        printf("%s", drzavi[i].pr.politicka_partija);
        printf("%s", drzavi[i].glaven_grad.ime);
        printf("%d\n", drzavi[i].glaven_grad.br_ziteli);

    }

    printf("%s %s", drzavi[max_i].pr.ime, drzavi[max_i].pr.prezime); //indeksot na taa drzava [max_i], imeto na pretsedatelot i prezimeto.

    return 0;
}
*/


//1.4 Студенти

/*
Од стандарден влез се читаат податоци за непознат број студенти (не повеќе од 100). Податоците се внесуваат така што во секој ред се состои од:
• името
• презимето
• бројот на индекс (формат xxyzzzz)
• четири броја (поени од секоја задача)
со произволен број празни места или табулатори меѓу нив.
Да се напише програма која ќе испечати список на студенти, каде во секој ред
ќе има: презиме, име, број на индекс, вкупен број на бодови сортиран според
бројот на бодови. При тоа имињата и презимињата да се напишат со голема
почетна буква.
 
 INPUT:
 3 - studenti
 david
 hristov
 221085
 5 - BROJ NA POENI ZA SEKOJA ZADACA
 6
 7
 8
 
 leonora
 siljanovska
 221099
 9
 4
 1
 6
 
 marko
 poposki
 221041
 4
 6
 8
 3
 
 OUTPUT
 David Hristov 221085 27
 Leonora Siljanovska 221099 22
 Marko Poposki 221041 21
 */


struct student{

    char ime[20];
    char prezime[20];
    int indeks;
    int poeni;

};

typedef struct student student;

void sort(student studenti [], int n){

    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(studenti[i].poeni<studenti[j].poeni){
                temp=studenti[i].poeni;
                studenti[i].poeni=studenti[j].poeni;
                studenti[j].poeni=temp;
            }
        }
    }
}


int main(){

    student studenti[100]; //max 100 studenti - nova niza deklarirame
    int n,i,j;
    int poeni=0;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",studenti[i].ime);

        //elementot na nulta pozicija da bide golema bukva od istiot toj element.
        studenti[i].ime[0]=toupper(studenti[i].ime[0]);

        scanf("%s",studenti[i].prezime);

        studenti[i].prezime[0]=toupper(studenti[i].prezime[0]);

        scanf("%d", &studenti[i].indeks);

        studenti[i].poeni=0; //ja stava vrednosta na 0


        for(j=0;j<4;j++){
            scanf("%d", &poeni);
            studenti[i].poeni+=poeni; //ako vneseme 2 poeni i se dodavaat vo poenite na studentot, potoa 5 ako vneseme se dodavaat vo poenite na studentot itn.
        }
    }

    sort(studenti, n);

    for(i=0;i<n;i++){
        printf("%s %s %d %d\n", studenti[i].ime,studenti[i].prezime,studenti[i].indeks,studenti[i].poeni);
    }

    return 0;
}


//SORTIRANJE - moe

//for(i=0;i<n;i++){
//    for(j=i+1;j<n;j++){
//        if(a[i]>a[j]){
//            temp=a[i];
//            a[i]=a[j]=
//            a[j]=temp;
//        }
//    }
//}




//typedef struct Employee{
//    char ime_vraboten[100];
//    char EMBG[100];
//    char oddel[100];
//    int plata;
//
//}Employee;
//
//typedef struct Company{
//    char ime_kompanija[100];
//    Employee vraboteni[100];
//    int br_vraboteni;
//
//}Company;
//
//void printEmployeesBelowAverageSalary(Company *comp, int num_Companies)
//                                //Company comp [], int num_companies
//{
//
//    float prosek=0;
//    int min=0;
//    int min_i=0;
//
//    printf("\nEmployees with salaries below the average:\n");
//    for (int i = 0; i < num_Companies; i++) {
//        for (int j = 0; j < comp[i].br_vraboteni; j++) {
//            if(comp[i].vraboteni[i].plata<min){
//                min=comp[i].vraboteni[i].plata;
//                min_i=i;
//            }
//            prosek+=min/num_Companies;
//        }
//        printf(" %s %s %s %d\n",
//               comp[min_i].vraboteni[min_i].ime_vraboten, comp[min_i].vraboteni[min_i].EMBG,
//               comp[min_i].vraboteni[min_i].oddel, comp[min_i].vraboteni[min_i].plata);
//    }
//
//}
//
//void printHighestSalaryEmployee(Company *comp, int numCompanies, char *department){
//
//    int max=0, max_i=0,i, j, k;
//
//    printf("\nEmployees with highest salaries for given department:\n");
//    for(i=0;i<comp[i].vraboteni[i].oddel;i++) {
//        for (j = 0; j < numCompanies; j++) {
//            for(k=0; k < comp[i].br_vraboteni;k++){
//                if (comp[i].vraboteni[i].plata > max) {
//                    max = comp[i].vraboteni[i].plata;
//                    max_i = i;
//                }
//            }
//        }
//        printf(" %s %s %s %d\n",
//               comp[max_i].vraboteni[max_i].ime_vraboten, comp[max_i].vraboteni[max_i].EMBG,
//               comp[max_i].vraboteni[max_i].oddel, comp[max_i].vraboteni[max_i].plata);
//    }
//
//}
//
//int main(){
//
//    Company k[100];
//    int num_Companies,i;
//    char department[50];
//    //struct Company *comp;
//    scanf("%d", &num_Companies);
//
//    for(i=0;i<num_Companies;i++){
//        scanf("%s", k[i].ime_kompanija);
//        scanf("%d", &k[i].br_vraboteni);
//        for (int j = 0; j < k[i].br_vraboteni; ++j) {
//            scanf("%s", k[j].vraboteni[j].ime_vraboten);
//            scanf("%s", k[j].vraboteni[j].EMBG);
//            scanf("%s", k[j].vraboteni[j].oddel);
//            scanf("%d", &k[j].vraboteni[j].plata);
//        }
//    }
//
//    printEmployeesBelowAverageSalary(k,num_Companies);
//    printHighestSalaryEmployee(k,num_Companies,department);
//
//    return 0;
//}


