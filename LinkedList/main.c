#include <stdio.h>
#include <stdlib.h>

//20010011043 Ali Ihsan TASDELEN

//verilerimizin tutulma yapisi
typedef struct List
{
    long telNum;
    char* name;
    char*surname;
    int letterNum;
    struct List *next;
}LList;

//bagli listenin ilk baglamini alir
LList* root;

//veri ekler
void ekle(LList *iter)
{
    //eklenecek verileri tanimliyoruz
    long addTelNum;
    char* addName;
    //char dizileri icin alan ayirmaliyiz
    addName = (char*)malloc(sizeof(char)*100);
    char* addSurname;
    addSurname = (char*)malloc(sizeof(char)*100);

    //verileri aliyoruz
    printf("Isim: ");
    scanf("%s", addName);
    printf("Soyisim: ");
    scanf("%s", addSurname);
    printf("Telefon numarasi: ");
    scanf("%d", &addTelNum);

    //ilk deger tanimliyorsak
    if(!root)
    {
        //alan ayiriyoruz
        root = (LList*)malloc(sizeof(LList));
        //verileri yapiya ekliyoruz
        root->telNum = addTelNum;
        root->name = addName;
        root->surname = addSurname;
        //ilk verimizin sonraki verisini NULLa isaretliyoruz
        root->next = NULL;
    }

    //eger ilk degerimiz varsa isleme giriyor
    else
    {
        //son yapimiza kadar geliyoruz
        while(iter->next)
            iter = iter->next;

        //baglamin onune yeni baglam alanini ayiriyoruz
        iter->next = (LList*)malloc(sizeof(LList));
        //baglamin onune yeni baglamimizi ekliyoruz
        iter->next->telNum = addTelNum;
        iter->next->name = addName;
        iter->next->surname = addSurname;
        //yeni baglamdan sonraki verimizi NULLa isaretliyoruz
        iter->next->next = NULL;
    }

}

//tum baglam verilerini listeler
void listele(LList* root)
{
    //birden fazla veri tipi oldugu icin her seferinde basa gecebilmemiz gerek
    LList* head = root;

    printf("\nTelefon Numaralari\n");
    //telNum adli tum veriyi yazdirir
    while(root)
    {
        printf("%ld->", root->telNum);
        root = root->next;
    }

    root = head;
    printf("\n\nIsimler\n");
    //name adli tum veriyi yazdirir
    while(root)
    {
        printf("%s->", root->name);
        root = root->next;
    }

    //tekrardan kok dizine doner
    root = head;
    printf("\n\nSoyisim\n");

    //surname adli tum veriyi yazdirir
    while(root)
    {
        printf("%s->", root->surname);
        root = root->next;
    }
}

//numaraya gore buyukten kucuge dogru siralar
void sortNum(LList* root)
{
    //takas edilmesini kontrol edecek degiskeni tanimliyoruz
    int swapped;

    //gezici degiskenini tanimliyoruz
    LList *iter;

    //less iter olarak kisalttim, tanimliyoruz
    LList *liter = NULL;
    int tempNum;
    char *tempName;
    char *tempSurname;

    //kok dizin yoksa fonksiyonu bos cevirir
    if (root == NULL)
        return;

    do
    {
        //degisim olmadi diyor
        swapped = 0;

        //iteri kok baglama atiyoruz
        iter = root;

        //iterden sonraki deger less iter midir kontrol eder
        //bubble sort mantigi uyguladim
        while (iter->next != liter)
        {
            //eger iterin telNum'u, sonraki baglamindan kucukse takas ederiz
            if (iter->telNum < iter->next->telNum)
            {
                //gecici degerleri atariz. Iterle denkleriz
                tempNum = iter->telNum;
                tempName = iter->name;
                tempSurname = iter->surname;

                //iterin verileriyle, sonraki baglamin verilerini degistiririz.
                iter->telNum = iter->next->telNum;
                iter->name = iter->next->name;
                iter->surname = iter->next->surname;

                //sonraki baglami, geciciye atadigimiz degismemis temp degeriyle degistiririz
                iter->next->telNum = tempNum;
                iter->next->name = tempName;
                iter->next->surname = tempSurname;

                //degisim oldugu icin degeri 1 e degistiriyoruz
                swapped = 1;
            }
            //iteri sonraki baglama geciriyoruz, dongunun ilerlemesine yarar.
            iter = iter->next;
        }
        //less iter en son kayittir.
        liter = iter;
    }
    //eger degisim varsa dongu devam etmelidir
    while (swapped);
}


void sortSur(LList* root)
{
    //ilk deger var mi diye kontrol ediyoruz
    if (root == NULL)
        return;

    //alfabeyi char dizisi olarak tanimladim
    char *alphabet = "abcdefghijklmnoprstuvwxyz";

    LList* iter;
    LList* liter = NULL;
    long tempNum;
    char *tempName;
    char *tempSurname;
    int tempLetterNum;

    int i = 0;


    while(*(alphabet + i) != '\0')
    {
        //iteri kok baglama tanimlariz
        iter = root;

        while(iter != liter)
        {
            if(*(iter->surname) == *(alphabet + i))
            {
                iter->letterNum = i;
            }

            iter = iter->next;
        }
        liter = iter;
        i++;
    }

    int swapped;
    liter = NULL;

    do
    {
        //degisim olmadi diyor
        swapped = 0;

        //iteri kok baglama atiyoruz
        iter = root;

        //iterden sonraki deger less iter midir kontrol eder
        //bubble sort mantigi uyguladim
        while (iter->next != liter)
        {
            //eger iterin letterNum'u, sonraki baglamindan kucukse takas ederiz
            if (iter->letterNum < iter->next->letterNum)
            {
                //gecici degerleri atariz. Iterle denkleriz
                tempNum = iter->telNum;
                tempName = iter->name;
                tempSurname = iter->surname;
                tempLetterNum = iter->letterNum;

                //iterin verileriyle, sonraki baglamin verilerini degistiririz.
                iter->telNum = iter->next->telNum;
                iter->name = iter->next->name;
                iter->surname = iter->next->surname;
                iter->letterNum = iter->next->letterNum;

                //sonraki baglami, geciciye atadigimiz degismemis temp degeriyle degistiririz
                iter->next->telNum = tempNum;
                iter->next->name = tempName;
                iter->next->surname = tempSurname;
                iter->next->letterNum = tempLetterNum;

                //degisim oldugu icin degeri 1 e degistiriyoruz
                swapped = 1;
            }
            //iteri sonraki baglama geciriyoruz, dongunun ilerlemesine yarar.
            iter = iter->next;
        }
        //literi iter yapiyoruz ki, bubble sort her defasinde 1 azalarak donguye devam edebilsin
        liter = iter;
    }
    //eger degisim varsa dongu devam etmelidir
    while (swapped);
}






int main()
{


    int key = 1;
    while(key == 1)
    {
        char choose;
        system("cls");
        printf("(e)Ekle\n(n)Numaraya gore siralama\n");
        printf("(s)Soyisme gore siralama\n(l)Listele\n");
        printf("(q)Cikis\n===> ");
        scanf("%c", &choose);


        if(choose == 'e')
        {
            ekle(root);
            system("cls");
        }

        else if(choose == 'n')
        {
            sortNum(root);
            system("cls");
        }

        else if(choose == 's')
        {
            sortSur(root);
            system("cls");

        }

        else if(choose == 'l')
        {
            char quit;
            listele(root);
            do
            {
                printf("\n\n(q)Kapat\n=> ");
                scanf("%c", &quit);
            }
            while(quit != 'q');

            system("cls");
        }

        else if(choose == 'q')
        {
            key = 0;
        }

    }
    return 0;
}
