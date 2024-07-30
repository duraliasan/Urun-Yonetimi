#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

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
void ekle();
void listele();
void guncelle();
void sil();

int main()
{

//---------------------------

    int secim;

    while(1)
    {
        printf("\n\nLutfen Birini Secin.\n________________________\n\n");
        printf("(1)Urun Ekleme\n________________________\n\n");
        printf("(2)Urun Silme\n________________________\n\n");
        printf("(3)Urunleri Listele\n________________________\n\n");
        printf("(4)Urun Guncellemesi\n________________________\n\n");
        printf("(5)Cikis\n________________________\n\n");

        scanf("%d", &secim);
        
        switch(secim)
        {
        case 1:
            ekle();
            break;
        case 2:
            sil();
            break;
        case 3:
            listele();
            break;
        case 4:
            guncelle();
            break;
        case 5:
            return 0;
        }
    }
}

void ekle()
{
    system("cls");
    printf("-------------------------------------\n");
    printf("Urun Ekleme Menusu\n");
    printf("-------------------------------------\n\n");
    int sayi;
    printf("Kac adet urun girmek istiyorsunuz ?\n");
    scanf("%d",&sayi);
    if(count != 0)
    {
        Urun = realloc(Urun,sizeof(Parca *) * (count+1));
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
    printf("Menuye donmek icin herhangi bir tusa basin");
    getch();
    system("cls");
}

void listele()
{
    if(count == 0)
        printf("Urun Bulunmamaktadir.\n");

    else
    {
        for(int j = 0; j < count; j++)
            printf("(%d)Ad: %s\tModel: %s\tTip: %s\tAdet: %d\tFiyat: %.2f\n",j+1,Urun[j]->ad,Urun[j]->model,Urun[j]->tip,Urun[j]->ozellik.adet,Urun[j]->ozellik.fiyat);
    }
    printf("Menuye donmek icin herhangi bir tusa basin");
    getch();
    system("cls");
}

void sil()
{
    int sec;
    listele();
    if(count != 0)
    {
        printf("Silmek istediginiz urunun numarasini giriniz.\n");
        scanf("%d", &sec);
        while(sec <= 0 || sec > count)
        {
            printf("Yanlis deger girdiniz! Lutfen tekrar giriniz.\n");
            scanf("%d", &sec);
        }
        if(sec == count)
        {
            Urun = realloc(Urun,sizeof(Parca *) * (count - 1));
        }
        else
        {
            for(int i = sec; i < count; i++)
            {
                Urun[i-1] = Urun[i];
            }
            Urun = realloc(Urun,sizeof(Parca *) * (count - 1));
        }
        count--;
        printf("Menuye donmek icin herhangi bir tusa basin");
        getch();
        system("cls");
    }
}

void guncelle()
{
    listele();
    if(count != 0)
    {
        int sec, sec2, kontrol;
        do
        {
            kontrol = 0;
            printf("Hangi urunu guncellemek istiyorsunuz ?\n");
            scanf("%d", &sec);
            while(sec <= 0 || sec > count)
            {
                printf("Yanlis deger girdiniz! Lutfen tekrar giriniz.\n");
                scanf("%d", &sec);
            }
            printf("1: Ad\t2: Model\t3: Tip\t4: Adet\t5: Fiyat\nLutfen guncelleme bilgisini secin.\n");
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
        printf("Menuye donmek icin herhangi bir tusa basin");
        getch();
        system("cls");
    }

}
