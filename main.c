#include <stdio.h>
#include <malloc.h>

int dizi[];
int temp;

struct dugum{
    struct dugum* sonraki;
    struct dugum* onceki;
    int veri;
};

struct dugum* baslangic = NULL;

int dugumYap(int sayi){

    struct dugum* yenidugum = (struct dugum*)malloc(sizeof(struct dugum));

    yenidugum->veri = sayi;
    yenidugum->sonraki = NULL;
    yenidugum->onceki = NULL;

}

int sonaEkle(int sayi){

    struct dugum* sonaGelsin = dugumYap(sayi);

    if(baslangic == NULL){
        baslangic = sonaGelsin;
    }
    else{
        struct dugum* temp = baslangic;

        while(temp->sonraki != NULL){
              temp = temp->sonraki;
    }
    temp->sonraki = sonaGelsin;
    sonaGelsin->onceki = temp;
    }
}

int basaEkle(int sayi){

    struct dugum* basaGelsin = dugumYap(sayi);

    if(baslangic == NULL){
        baslangic = basaGelsin;
        return basaGelsin;
    }
            struct dugum* temp = baslangic;

            baslangic->onceki = basaGelsin;
            basaGelsin->sonraki = baslangic;
            baslangic = basaGelsin;
    }

int arayaEkle(int sayi, int x){

    struct dugum* arayaGelsin = dugumYap(sayi);
    struct dugum* temp = baslangic;
    struct dugum* onundeki = NULL;

    while(temp->sonraki != NULL){
        if(temp->veri == x){
            onundeki = temp->onceki;
            break;
        }
        temp= temp->sonraki;
    }

    temp->onceki = arayaGelsin;
    arayaGelsin->sonraki = temp;
    arayaGelsin->onceki = onundeki;
    onundeki->sonraki = arayaGelsin;


}

void yazdir(){

    struct dugum* temp = baslangic;
     while(temp != NULL){
        printf("%d -> ", temp->veri);
        temp = temp->sonraki;
    }
}

int main(){

    int x,sayi,secim;

    while(1 == 1){

        printf("\n1) Basa Eleman Ekle");
        printf("\n2) Sona Eleman Ekle");
        printf("\n3) Araya Eleman Ekle");
        printf("\n\nBir Secenegi Seciniz...> ");
        scanf("%d", &secim);

        switch(secim){

        case 1: printf("\nBasa Eklemek Istediginiz Sayiyi Giriniz...> ");
                scanf("%d", &sayi);
                basaEkle(sayi);
                yazdir();
                break;

        case 2: printf("\nSona Eklemek Istediginiz Sayiyi Giriniz...> ");
                scanf("%d", &sayi);
                sonaEkle(sayi);
                yazdir();
                break;

        case 3: printf("\nHangi Sayinin Soluna Eleman Eklemek Istersiniz?..> ");
                scanf("%d", &x);
                printf("\nEklemek Istediginiz Sayiyi Yaziniz...> ");
                scanf("%d", &sayi);
                arayaEkle(sayi,x);
                yazdir();
                break;
        default:
            printf("\nLutfen Gecerli Bir Sayi Giriniz...\n\n");
        }
    }
}
