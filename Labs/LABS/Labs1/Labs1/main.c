#include <stdio.h>
#include <string.h>

/*
 1 LABS
Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".

Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
- Идентификациски број (int)
- Платена сума (int)
- Провизија (int)
- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)

Ограничување: 0 < N < 100

Структура на влезните податоци:
N
id1 sum1 commission1 type1
...
idn sumn Commissionn typen
*/

//1 nacin

/*
struct Transaction{
  
    int ID;
    int suma;
    int provizija;
    int vid_plakanje;
    //int vkupna_suma;
};

typedef struct Transaction Transaction;


int main() {
    
    Transaction t;
    int n,i;
    //int flag=0;
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        scanf("%d", &t.ID);
        scanf("%d", &t.suma);
        scanf("%d", &t.provizija);
        scanf("%d", &t.vid_plakanje); //ako e so debitna -0, kreditna-1
                    
        if(t.vid_plakanje==1){
            printf("%d %d\n", t.ID, t.suma+t.provizija); //t.vkupna_suma - samo ova
            //flag=1;
        }
    }
    
    if(t.vid_plakanje==0){
        printf("No credit card transaction\n");
    }
    
    return 0;
}
*/

//2 nacin - PODOBRO
/*
struct Transaction
{
int ibroj;
int suma;
int provizija;
int tip;
};

typedef struct Transaction Transaction;

int main(){

    Transaction t[20];
    int n,i;
    int brojac=0;
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &t[i].ibroj);
        scanf("%d", &t[i].suma);
        scanf("%d", &t[i].provizija);
        scanf("%d", &t[i].tip);
    }
    for (i=0; i<n; i++) {
        if(t[i].tip==1){
            brojac++;
            printf("%d %d\n", t[i].ibroj, t[i].suma+t[i].provizija);
            }
    }
    
//    for (int  j=0; j<n; j++) {
//            if(t[j].tip==1){
//                brojac++;
//                printf("%d %d\n", t[j].ibroj, t[j].suma+t[j].provizija);
//                }
//        }
    
    if(brojac==0){
        printf("No credit card transaction");
    }
    return 0;
}
*/


//2ra ZAD - KRUG

/*
const float PI=3.14;
struct Tocka{
  
    int x;
    int y;
    
};

typedef struct Tocka Tocka;

struct Krug {
  
    int radius;
    Tocka centar;

};

typedef struct Krug Krug;

//float plostina(Krug k){
//
//    return k.radius * k.radius * PI;
//
//}

int main(){
    
    Krug k[20];
    
    int n,i;
    int x_koordinata=0, y_koordinata=0;
    float plostina = 0, max_plostina=0;
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        scanf("%d", &k[i].centar.x); //x i y go pretstavuvaat centarot na krugot kako i radiusot na krugot
        scanf("%d", &k[i].centar.y);
        scanf("%d", &k[i].radius);
        
        plostina=k[i].radius * k[i].radius * PI;
        
        if(plostina>max_plostina){
            max_plostina=plostina;
            
            //x koord i y koord gi zima za da znae deka ovie specificni koordinati za da gi isprinta
            x_koordinata = k[i].centar.x;
            y_koordinata = k[i].centar.y;
        }
    }
    
    printf("Largest circle has area of: %.2f with centre: (%d, %d)", max_plostina, x_koordinata, y_koordinata);
    
    return 0;
}
*/


//2 nacin

//#define Pi 3.14
//typedef struct
//{
//    int x;
//    int y;
//}tocka;
//
//typedef struct
//{
//    tocka centar;
//    int radius;
//}krug;
//
//float plostina(krug k)
//{
//    return Pi*k.radius*k.radius;
//}
//
//int main()
//{
//    krug k[20];
//    int  n,max_i=0;
//    float max=0;
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d %d %d", &k[i].centar.x,&k[i].centar.y,&k[i].radius);
//    }
//    for (int i = 0; i < n; ++i) {
//        if(plostina(k[i])>max)
//        {
//            max = plostina(k[i]);
//            max_i=i;
//        }
//    }
//    printf("Largest circle has area of: %.2f with centre: (%d,%d)", max,k[max_i].centar.x,k[max_i].centar.y);
//}



//3ta ZAD - EMPLOYEE

//struct Employee{
//    char ime_vraboten[20];
//    char EMBG[12];
//    char oddel[20];
//    int plata;
//
//};
//
//typedef struct Employee Employee;
//
//struct Company{
//    char ime_kompanija[20];
//    Employee vraboteni[20];
//    int br_vraboteni;
//
//};
//
//typedef struct Company Company;
//
//void printEmployeesBelowAverageSalary(Company *comp, int numCompanies){
//
//    //float prosek, suma;
//    int i,j;
//
//    printf("Employees with salaries below the average\n");
//    for(i=0;i<numCompanies;i++){
//       float suma=0;
//       float prosek=0;
//        for(j=0;j<comp[i].br_vraboteni;j++){
//
//            suma+=comp[i].vraboteni[j].plata; //gi sobira site plati na vrab
//
////            if(comp[i].vraboteni[i].plata<min){ //ja barame najniskata plata
////                min=comp[i].vraboteni[i].plata;
////                min_i=i; //indeksot
//            }
//            prosek=suma/comp[i].br_vraboteni;
//
//            for(j=0;j<comp[i].br_vraboteni;j++){
//                if(comp[i].vraboteni[j].plata<prosek){
//                    //prosek=comp[i].vraboteni[j].plata;
//
//                    printf("%s %s %s %d\n", comp[i].vraboteni[j].ime_vraboten, comp[i].vraboteni[j].EMBG, comp[i].vraboteni[j].oddel, comp[i].vraboteni[j].plata);
//                }
//            }
//        }
//    }
//
//void printHighestSalaryEmployee(Company *comp, int numCompanies, char *department){
//
//    int i,j;
//    int max=0, max_j=0;
//
//    printf("Employees with highest salaries for given department:\n");
//    for(i=0;i<numCompanies;i++){
//       for(j=0;j<comp[i].br_vraboteni;j++){
//            if(comp[i].vraboteni[j].plata>max && strcmp(department, comp[i].vraboteni[j].oddel)==0){
//                max=comp[i].vraboteni[j].plata;
//                max_j=j;
//            }
//        }
//        printf("%s %s %s %d\n", comp[max_j].vraboteni[max_j].ime_vraboten, comp[max_j].vraboteni[max_j].EMBG, comp[max_j].vraboteni[max_j].oddel, comp[max_j].vraboteni[max_j].plata);
//    }
//}
//
//int main(){
//
//    Company comp[100];
//    int num_companies,i,j;
//    char department[50];
//
//    scanf("%d", &num_companies);
//
//    for(i=0;i<num_companies;i++){
//
//        scanf("%s", comp[i].ime_kompanija);
//        scanf("%d", &comp[i].br_vraboteni);
//
//        //ciklus za vrabotenite posebno
//        for(j=0; j<comp[i].br_vraboteni; j++){
//            scanf("%s", comp[j].vraboteni[j].ime_vraboten);
//            scanf("%s", comp[j].vraboteni[j].EMBG);
//            scanf("%s", comp[j].vraboteni[j].oddel);
//            scanf("%d", &comp[j].vraboteni[j].plata);
//
//        }
//    }
//
//    scanf("%s", department);
//
//    printEmployeesBelowAverageSalary(comp, num_companies);
//    printHighestSalaryEmployee(comp, num_companies, department);
//
//
//    return 0;
//}








//typedef struct {
//    char ime_vraboten[20];
//    char EMBG[12];
//    char oddel[20];
//    int plata;
//
//}Employee;
//
//typedef struct {
//    char ime_kompanija[20];
//    Employee vraboteni[20];
//    int br_vraboteni;
//
//}Company;
//
//void printEmployeesBelowAverageSalary(Company *k, int num_Companies)
////Company comp [], int num_companies
//{
//
//
////    int min=0;
////    int min_i=0;
//
//    printf("Employees with salaries below the average:\n");
//    for (int i = 0; i < num_Companies; i++) {
//        float prosek=0;
//        int suma=0;
//        for (int j = 0; j < k[i].br_vraboteni; j++) {
//            suma+=k[i].vraboteni[j].plata;
//
////            if(comp[i].vraboteni[i].plata<min){
////                min=comp[i].vraboteni[i].plata;
////                min_i=i;
//        }
//        prosek=suma/k[i].br_vraboteni;
//        for (int j = 0; j < k[i].br_vraboteni; j++)
//        {
//            if (k[i].vraboteni[j].plata < prosek)
//            {
//                printf ("%s %s %s %d\n", k[i].vraboteni[j].ime_vraboten, k[i].vraboteni[j].EMBG,
//                        k[i].vraboteni[j].oddel, k[i].vraboteni[j].plata);
//
//            }
////            prosek+=min/num_Companies;
//        }
//    }
//
//}
//
//void printHighestSalaryEmployee(Company *k, int numCompanies, char *department){
//
//    int max=0, max_j=0,i, j;
//
//    printf("Employees with highest salaries for given department:\n");
//    for(i=0;i<numCompanies;i++) {
//        for (j = 0; j < k[i].br_vraboteni; j++) {
//            if (k[i].vraboteni[j].plata > max && strcmp(department, k[i].vraboteni[j].oddel) == 0) {
//                max = k[i].vraboteni[j].plata;
//                max_j = j;
//            }
//        }
//        printf("%s %s %s %d\n", k[i].vraboteni[max_j].ime_vraboten, k[i].vraboteni[max_j].EMBG,
//               k[i].vraboteni[max_j].oddel, k[i].vraboteni[max_j].plata);
//
//    }
//
//}
//
//int main(){
//
//    Company k[100];
//    int num_Companies;
//    scanf("%d", &num_Companies);
//    char department[100];
//    for(int i=0;i<num_Companies;i++){
//        scanf("%s", k[i].ime_kompanija);
//        scanf("%d", &k[i].br_vraboteni);
//        for (int j = 0; j < k[i].br_vraboteni; j++) {
//            scanf("%s", k[i].vraboteni[j].ime_vraboten);
//            scanf("%s", k[i].vraboteni[j].EMBG);
//            scanf("%s", k[i].vraboteni[j].oddel);
//            scanf("%d", &k[i].vraboteni[j].plata);
//        }
//    }
//    scanf("%s", department);
//    printEmployeesBelowAverageSalary(k, num_Companies);
//    printHighestSalaryEmployee(k, num_Companies, department);
//
//    return 0;
//}




//2 зад LABS

/*
Да се креира структура Student во која се чува ат податоци за еден студент. За студентот се чуваат информации за името на студентот(низа од карактери), број на индекс на студентот, број на курсеви кои ги слуша, низа од кодови на курсевите кои ги слуша.

Потоа, да се креира структура Course во која се чуваат податоци за името на курсот(низа од карактери), код на курсто(Цел број) и број на студенти кои гио слушаат.

Да се направи функција int get_most_popular_course(struct course courses[], int num_courses) која што го враќа кодот на најпопуларниот курс.

НАПОМЕНА - Прво од тастатура се чита бројот на студенти, потоа бројот на курсеви.Потоа се внесуваат курсевите и студентите, притоа за секој студент се читаат и кодовите на курсевите кои ги слуша.
*/


//DA SE DORABOTI
/*
struct Student {
  
    char ime_student[100];
    int br_indeks;
    int broj_kursevi;
    char kodovi_kursevi[100];
    
};

typedef struct Student Student;

struct Course{
  
    char ime_kurs[100];
    int kod_kurs;
    int br_studenti;
    
};

typedef struct Course Course;

int get_most_popular_course(Course course[],int num_courses){
    
    int i,j,max=0,max_i=0;
    
    for(i=0;i<num_courses;i++){
        if(course[i].kod_kurs>max){
            max=course[i].kod_kurs;
            max_i=i;
        }
    }
    return course[max_i].kod_kurs;
    //return max_i;
}

int main(){
    
    int broj_studenti=0,i,broj_kursevi=0;
    Course kurs[100];
    Student student[100];
    
    scanf("%d", &broj_studenti);
    scanf("%d", &broj_kursevi);
    
    for(i=0;i<broj_kursevi;i++){
        
        scanf("%s", kurs[i].ime_kurs);
        scanf("%d", &kurs[i].kod_kurs);
    
    }
    
    for(i=0;i<broj_studenti;i++){
        
        scanf("%s", student[i].ime_student);
        scanf("%d", &student[i].br_indeks);
        scanf("%d", &student[i].broj_kursevi);
    }
    
    int najpopularen_kurs_indeks = get_most_popular_course(courses, num_courses);
    
    
    return 0;
}
*/


//3-ta ZAD LABS

/*
struct Item {
    
    char ime_proizvod[100];
    int cena_proizvod;
    
};

typedef struct Item Item;

struct ShoppingCart {
  
    int ID_kosnicka;
    Item proizvodi[100]; //tuka se stava niza
    
};

typedef struct ShoppingCart ShoppingCart;


void printAveragePriceOfLowestItems(ShoppingCart kosnicka [], int n){
    
    int min=0, min_i=0;
    int i;
    float sredna_vrednost=0;
    
    for(i=0;i<n;i++){
                                        //0
        //int min = kosnicka[i].proizvodi[i].cena_proizvod;
                
            //vo kosnickata se proizvodi i cenata - fakticki pristapuvame prvo vo kosnickata pa vo proizvodot
        if(kosnicka[i].proizvodi[i].cena_proizvod<min){
            min=kosnicka[i].proizvodi[i].cena_proizvod;
            min_i=i;
        }
        
        sredna_vrednost+=min/n;
    }
                        //sredna vrednosta na proizvodite so najmala cena vo sekoja kosnicka
    printf("Sredna vrednost na cena na proizvodite e: %.2f\n", sredna_vrednost); //sredna_vrednost/n
}

void printHighestPricedItem(ShoppingCart kosnicka [], int n){
    
    int max=0, max_i=0,i;
    
    for(i=0;i<n;i++){
        
        if(kosnicka[i].proizvodi[i].cena_proizvod>max){
            max=kosnicka[i].proizvodi[i].cena_proizvod;
            max_i=i;
        }
        printf("Shopping cart ID:%d\n Product:%s", kosnicka[max_i].ID_kosnicka, kosnicka[max_i].proizvodi[i].ime_proizvod);
    }
}

int main(){
    
    ShoppingCart kosnicka[100]; //samo za ShoppingCart se prai uste edna dopolnitelna niza bidejki vo ShoppingCart imame pristap do elementite na ITEM.
    
    int n,i;
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        scanf("%s %d", kosnicka[i].proizvodi[i].ime_proizvod, kosnicka[i].proizvodi[i].cena_proizvod);
    }
    
    printAveragePriceOfLowestItems(kosnicka, n);
    printHighestPricedItem(kosnicka, n);
    
    return 0;
}

*/




//struct Item{
//
//    char ime_proizvod[100];
//    int cena_proizvod;
//
//};
//
//typedef struct Item item;
//
//struct ShoppingCart{
//
//    int ID_kosnicka;
//    struct Item proizvod;
//
//};
//
//typedef struct ShoppingCart shoppingcart;
//
//void printAveragePriceofLowestItems(item proizvod[], shoppingcart kosnicka[]){
//
//    int min=0,i,min_i=0;
//
//    for(i=0;i<kosnicka;i++){
//        if(proizvod[i].cena_proizvod<min){
//            min=proizvod[i].cena_proizvod;
//            min_i=i;
//        }
//    }
//
//
//}
//
//
//int main(){
//
//    shoppingcart kosnicka;
//    item proizvod;
//
//
//    return 0;
//}





//2ra - KRUG 

//#define Pi 3.14
//typedef struct tocka
//{
//    int x;
//    int y;
//}tocka;
//
//
//struct krug{
//    tocka centar;
//    int radius;
//    tocka tocka1;
//};
//
//typedef struct krug krug;
//
//float plostina(krug k){
//    return k.radius*k.radius*Pi;
//}
//
//int main(){
//    krug k;
//    int n,i;
//    float max=0;
//    int max_i=0;
//
//    scanf("%d", &n);
//
//    for(i=0;i<n;i++){
//        scanf("%d", &k.tocka1.x);
//        scanf("%d", &k.tocka1.y);
//        scanf("%d", &k.radius);
//
//        if(plostina(k)>max){
//            max= plostina(k);
//        }
//    }
//
////    for (int j = 0; j < n; ++j) {
////        if(plostina(k)>max){
////            max= plostina(k);
////            max_j=j;
////        }
////    }
//
//    plostina(k);
//
//    printf("Largest circle has area of: %.2f with centre (%d,%d)", max, k.tocka1.x,k.tocka1.y);

    //TOCEN E MAX, SAMO USTE TOCKA1.X I TOCKA1.Y E GRESKA

//    return 0;
//}


//3RA - EMPLOYEES

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
//    printf("Employees with salaries below the average\n");
//    for (int i = 0; i < num_Companies; i++) {
//        for (int j = 0; j < comp[i].br_vraboteni; j++) {
//            if(comp[i].vraboteni[i].plata<min){
//                min=comp[i].vraboteni[i].plata;
//                min_i=i;
//            }
//            prosek+=min/num_Companies;
//        }
//        printf(" %s %s %s %d",
//               comp[min_i].vraboteni[min_i].ime_vraboten, comp[min_i].vraboteni[min_i].EMBG,
//               comp[min_i].vraboteni[min_i].oddel, comp[min_i].vraboteni[min_i].plata);
//    }
//
//}
//
//void printHighestSalaryEmployee(Company *comp, int numCompanies, char *department){
//
//    int max=0, max_i=0,i, j;
//
//    printf("Employees with highest salaries for given department\n");
//    for(i=0;i<numCompanies;i++) {
//        for (j = 0; j < comp[i].br_vraboteni; j++) {
//            if (comp[i].vraboteni[i].plata > max) {
//                max = comp[i].vraboteni[i].plata;
//                max_i = i;
//            }
//        }
//        printf(" %s %s %s %d",
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
//    //struct Company *comp;
//    scanf("%d", &num_Companies);
//
//    for(i=0;i<num_Companies;i++){
//
//        scanf("%s", k[i].ime_kompanija);
//        scanf("%d", &k[i].br_vraboteni);
//        scanf("%s", k[i].vraboteni[i].ime_vraboten);
//        scanf("%s", k[i].vraboteni[i].EMBG);
//        scanf("%s", k[i].vraboteni[i].oddel);
//        scanf("%d", &k[i].vraboteni[i].plata);
//    }
//
//    printEmployeesBelowAverageSalary()
//
//
//    return 0;
//}
