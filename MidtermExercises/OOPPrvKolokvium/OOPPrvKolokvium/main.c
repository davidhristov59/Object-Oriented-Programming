#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5



//15 ZAD
/*
struct RabotnaNedela{
    
    int casovi[DENOVI];
    int nedeli;
    
};

typedef struct RabotnaNedela RabotnaNedela;

struct Rabotnik{
    
    char ime[50];
    RabotnaNedela nedeli[NEDELI];
};

typedef struct Rabotnik R;

 int maxNedela(R *r){
    
    int i,j,max=0,max_i,zbir;
    for(i=0;i<NEDELI;i++){
        zbir=0;
        for(j=0;j<DENOVI;j++){
            zbir+=r->nedeli[i].casovi[j];
        }
        if(zbir>max){
            max=zbir;
            max_i=i;
        }
        //zbir=0;
    }
    return max_i+1;
}



//sobira casovite vo edna nedela od site denovi
int cas_vo_nedeli(R r, int indeks){
    
    int zbir=0;
    int i;
    for(i=0;i<DENOVI;i++){
        //zbir=0;
        zbir+=r.nedeli[indeks].casovi[i]; //fiksiran e indeksot kaj nedeli
    }
    
    return zbir;

}

void table(R *r, int n){
    
    int vkupno=0;
    int i,j;
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for(i=0;i<n;i++){
        vkupno=0;
        printf("%s\t", r[i].ime);
        for(j=0;j<NEDELI;j++){
            printf("%d\t",cas_vo_nedeli(r[i], j));
            vkupno+=cas_vo_nedeli(r[i], j);
        }
        printf("%d\n", vkupno);
    }
    
    
}

//daden e main-ot
int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}
*/


//18ta Zad
/*
struct SkiLift{

    char ime_skilift[15];
    int max_skijaci;
    int vo_upotreba;

};

typedef struct SkiLift SkiLift;

struct SkiCentar{

    char ime_skijacki_centar[50];
    char drzava[20];
    int broj_ski_liftovi;
    SkiLift sl[20];

};

typedef struct SkiCentar SkiCentar;


int kapacitet(SkiCentar sc){

    int capacity=0;
    for (int i = 0; i < sc.broj_ski_liftovi; ++i) {
            if(sc.sl[i].vo_upotreba==1){ //ako e vo upotreba
                capacity+=sc.sl[i].max_skijaci; //dodavame max broj skijaci na kapacitetot.Kolku sto ima kapacitet fakticki
            }
    }
    return capacity;
}

void najgolemKapacitet(SkiCentar *sc, int n) {

    int max = 0, max_i = 0, i;
    for (i = 0; i < n; i++) {          //ako imaat ist kapacitet liftovite(max==kapacitet) И vrti niz ski centri i site ski centri ima svoj indeks i si imame nekoj so e na max i se pojavuva drug ski centar so e ist so toj max i se sporeduvaat dvata i toj sto ima poveke kapacitet ke bide pogolem [i] > [max_i]
        if ((kapacitet(sc[i]) > max) || (max==kapacitet(sc[i]) && (sc[i].broj_ski_liftovi > sc[max_i].broj_ski_liftovi))) {
            max = kapacitet(sc[i]);
            max_i = i;
        }
    }
    printf("%s\n%s\n%d\n", sc[max_i].ime_skijacki_centar, sc[max_i].drzava, max);
}

int main() {

    SkiCentar sc[50];
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", sc[i].ime_skijacki_centar);
        scanf("%s", sc[i].drzava);
        scanf("%d", &sc[i].broj_ski_liftovi);
        for (int j = 0; j < sc[i].broj_ski_liftovi; j++) {
            scanf("%s", sc[i].sl[j].ime_skilift);
            scanf("%d", &sc[i].sl[j].max_skijaci);
            scanf("%d", &sc[i].sl[j].vo_upotreba);
        }
    }

    najgolemKapacitet(sc, n);

    return 0;
}
*/


//ZAD 8 LAPTOP

/*
typedef struct {
    char firma[100];
    float golemina_monitor;
    int touch;
    int cena;
}Laptop;

struct ITStore{

    char ime_prodavnica[100];
    char lokacija[100];
    Laptop l[100];
    int n;

};

typedef struct ITStore ITStore;

void print(ITStore it){

    int i;
    printf("%s %s\n",it.ime_prodavnica,it.lokacija);
    for(i=0;i<it.n;i++){
        printf("%s %g %d\n", it.l[i].firma, it.l[i].golemina_monitor, it.l[i].cena);
    }
}

void najeftina_ponuda(ITStore *it, int n){

    int i,j,min=99999, min_i=0;
    for(i=0;i<n;i++){
        for(j=0;j<it[i].n;j++){
            if((it[i].l[j].cena<min) && it[i].l[j].touch==1){
                min=it[i].l[j].cena;
                min_i=i;
            }
        }
    }

    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n",it[min_i].ime_prodavnica, it[min_i].lokacija);
    printf("Najniskata cena iznesuva: %d", min);
}

int main(){

    ITStore it[50];

    int n,i,j;
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%s", it[i].ime_prodavnica);
        scanf("%s", it[i].lokacija);
        scanf("%d", &it[i].n);
        for(j=0;j<it[i].n;j++){
            scanf("%s", it[i].l[j].firma);
            scanf("%f", &it[i].l[j].golemina_monitor);
            scanf("%d", &it[i].l[j].touch);
            scanf("%d", &it[i].l[j].cena);
        }
    }
    
    for(i=0;i<n;i++){
        print(it[i]);
    }

    najeftina_ponuda(it,n);

    return 0;
}
*/


