#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

int count = 0;
typedef struct Ozellik
{
    int adet;
    float fiyat;
} Ozellik;
typedef struct Parca
{
    char ad[20];
    char model[20];
    char tip[20];
    Ozellik ozellik;
} Parca;

Parca ** Urun;

///Bazi fonksiyonlar gizlidir. Islevi var ama secim olarak degil.
void menu();///gizli
void ekle();
void fiyataGoreListele();///gizli
void listele(); ///gizli
void listele2();
void guncelle();
void sil();

int main()
{

///---------------------------
    int secim;
    while(1)
    {
        printf("\n___________________\n\n");
        printf("(1)Urun Ekleme\n___________________\n\n");
        printf("(2)Urun Silme\n___________________\n\n");
        printf("(3)Urunleri Listele\n___________________\n\n");
        printf("(4)Urun Guncellemesi\n___________________\n\n");
        printf("(5)Cikis\n___________________\n\n-> ");

        scanf("%d", &secim);
        while(secim < 1 || secim > 5)
            printf("\n->"), scanf("%d", &secim);

        switch(secim)
        {
        case 1:
            ekle(), menu();
            break;
        case 2:
            sil(), menu();
            break;
        case 3:
            listele2(), menu();
            break;
        case 4:
            guncelle(), menu();
            break;
        case 5: system("cls"), printf("IYI GUNLER. YINE BEKLERIZ."), getch();
            return 0;
        }
    }
}
void ekle()
{
    system("cls");
    printf("-----------------------------------\n");
    printf("       Urun Ekleme Menusu\n");
    printf("-----------------------------------\n\n");
    int sayi;
    printf("Kac adet urun girmek istiyorsunuz ?\n-> ");
    scanf("%d",&sayi);
    if(count != 0)
    {
        Urun = realloc(Urun,sizeof(Parca *) * (count + sayi));
    }
    else
    {
        Urun = malloc(sizeof(Parca *) * sayi);
    }
    for(int i = count; i < count + sayi; i++)
    {
        Urun[i] = malloc(sizeof(Parca));
        printf("%d. Urunun Adi: ",i+1);
        scanf("%s",Urun[i]->ad);
        printf("%d. Urunun Modeli: ",i+1);
        scanf("%s",Urun[i]->model);
        printf("%d. Urunun Tipi: ",i+1);
        scanf("%s",Urun[i]->tip);
        printf("%d. Urunun Adeti: ",i+1);
        scanf("%d",&Urun[i]->ozellik.adet);
        printf("%d. Urunun Fiyati: ",i+1);
        scanf("%f",&Urun[i]->ozellik.fiyat);
    }
    count += sayi;
    if(sayi == 1)
        printf("\nUrun Eklendi.\n");
    else
        printf("\nUrunler Eklendi.\n");
}
void menu()
{
    printf("\nMenuye donmek icin herhangi bir tusa basin");
    getch();
    system("cls");
}
void fiyataGoreListele()
{
    for(int i = 0; i < count; i++)
    {
        for(int j = i+1; j < count; j++)
        {
            if(Urun[i]->ozellik.fiyat < Urun[j]->ozellik.fiyat)
            {
                Parca *temp = Urun[i];
                Urun[i] = Urun[j];
                Urun[j] = temp;

            }
        }
    }
}
void listele()
{
    fiyataGoreListele();
    if(count == 0)
        printf("\nUrun Bulunmamaktadir.\n");

    else
    {
        for(int j = 0; j < count; j++)
            printf("(%d)Ad: %s\tModel: %s\tTip: %s\tAdet: %d\tFiyat: %.2f\n",j+1,Urun[j]->ad,Urun[j]->model,Urun[j]->tip,Urun[j]->ozellik.adet,Urun[j]->ozellik.fiyat);
    }
}
void sil()
{
    system("cls");
    int sec;
    printf("-------------------------------------\n");
    printf("        Urun Silme Menusu\n");
    printf("-------------------------------------\n\n");
    listele();
    if(count != 0)
    {
        printf("\nSilmek istediginiz urunun numarasini giriniz. Silmekten vazgectiyseniz 0'i tuslayin.\n-> ");
        scanf("%d", &sec);
        while(sec < 0 || sec > count)
        {
            printf("Yanlis deger girdiniz! Lutfen tekrar giriniz.\n-> ");
            scanf("%d", &sec);
        }
        if(sec == 0)
        {
            printf("Hicbir urun silinmedi.");
        }
        else if(sec == count)
        {
            Urun = realloc(Urun,sizeof(Parca *) * (count - 1));
            printf("\nUrun silindi.\n");
            count--;
        }

        else
        {
            for(int i = sec; i < count; i++)
            {
                Urun[i-1] = Urun[i];
            }
            Urun = realloc(Urun,sizeof(Parca *) * (count - 1));
            printf("\nUrun silindi.\n");
            count--;
        }

    }
}
void listele2()
{
    fiyataGoreListele();
    system("cls");
    printf("-------------------------------------\n");
    printf("          Mevcut Urunler\n");
    printf("-------------------------------------\n\n");
    if(count == 0)
        printf("Urun Bulunmamaktadir.\n");

    else
    {
        for(int j = 0; j < count; j++)
            printf("(%d) Ad: %s\tModel: %s\tTip: %s\tAdet: %d\tFiyat: %.2f\n",j+1,Urun[j]->ad,Urun[j]->model,Urun[j]->tip,Urun[j]->ozellik.adet,Urun[j]->ozellik.fiyat);
    }
}
void guncelle()
{
    system("cls");
    printf("------------------------------------\n");
    printf("      Urun Guncelleme Menusu\n");
    printf("------------------------------------\n\n");
    listele();
    if(count != 0)
    {
        int sec, sec2, kontrol;
        do
        {
            kontrol = 0;
            printf("\nHangi urunu guncellemek istiyorsunuz ?\n-> ");
            scanf("%d", &sec);
            while(sec <= 0 || sec > count)
            {
                printf("Yanlis deger girdiniz! Lutfen tekrar giriniz.\n-> ");
                scanf("%d", &sec);
            }
            printf("\n1: Ad\n2: Model\n3: Tip\n4: Adet\n5: Fiyat\nLutfen guncelleme bilgisini secin.\n-> ");
            scanf("%d", &sec2);

            switch(sec2)
            {
            case 1:
                printf("Ad: "), scanf("%s",Urun[sec-1]->ad);
                break;
            case 2:
                printf("Model: "), scanf("%s",Urun[sec-1]->model);
                break;
            case 3:
                printf("Tip: "), scanf("%s",Urun[sec-1]->tip);
                break;
            case 4:
                printf("Adet: "), scanf("%d",&Urun[sec-1]->ozellik.adet);
                break;
            case 5:
                printf("Fiyat: "), scanf("%f",&Urun[sec-1]->ozellik.fiyat);
                break;
            default:
                printf("Yanlis deger girdiniz. Lutfen tekrar giriniz.\n"), kontrol = 1;
            }
        }
        while(kontrol == 1);
    printf("\nUrun guncellendi.\n");
    }
}
