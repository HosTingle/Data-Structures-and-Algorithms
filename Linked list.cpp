#include<stdio.h>
#include<stdlib.h>


struct node{
	int sayi;
	struct node* sonraki;
    };
    struct node *baslangic = NULL;
    struct node *olustur(int sayi)
    {
	struct node *yenidugum = (struct node*)malloc(sizeof(struct node));
	yenidugum->sayi=sayi;
	yenidugum->sonraki=NULL;
	
	return yenidugum;
    }
    void sonaekle(int sayi){
	struct node *sonaek =olustur(sayi);
	if(baslangic==NULL){
		baslangic=sonaek;
	}
	else
	{
	struct node *temp =baslangic;
	while( temp -> sonraki !=NULL)
	{
		temp= temp->sonraki;
	}
	temp->sonraki=sonaek;
	
    }
}
    void basaekle(int sayi){
    struct node *basaek =olustur(sayi);
    if(baslangic==NULL){
    	baslangic=basaek;
    	return;
	}
	else
	{
		struct node *temp =baslangic;
		baslangic=basaek;
		baslangic->sonraki=temp;
		
	}
	}
	void arayaekle(int sayi,int indis){
		struct node *araya = olustur(sayi);
		if(baslangic==NULL){
			baslangic=araya;
			return;
		}
		else
		{
			struct node *temp=baslangic;
			int counter=0;
			while(temp!=NULL){
				if(indis-1==counter){
					araya->sonraki=temp->sonraki;
					temp->sonraki=araya;
					
				}
				counter++;
				temp=temp->sonraki;
				
			}
			
			
		}
	}
	void sonsil(){
		struct node *temp=baslangic;
		while(temp->sonraki->sonraki!=NULL){
			temp=temp->sonraki;
		}
		free(temp->sonraki);
		temp->sonraki=NULL;
		
	}
	void bassil(){
		if(baslangic==NULL){
			printf("Eleman kalmadi !!!!!!");
		}
		if(baslangic->sonraki==NULL){
			baslangic=NULL;
			return;
		}
		
		struct node *temp=baslangic->sonraki;
		free(baslangic);
		baslangic=temp;
		
	}
    void aradansil(int boyut){
    	
    	struct node *temp= baslangic;
    	int counter=0;
    	while(temp!=NULL)
		{
    		if(boyut-1==counter)
    			break;
    			temp=temp->sonraki;
    			counter++;
		}
		if(counter +1!=boyut)
		{
			printf("Belirttiginiz indis bulumuyor...");
			return;
		}
		if(temp->sonraki==NULL)
		{
			sonsil();
		}
		struct node *gecici=temp->sonraki->sonraki;
		free(temp->sonraki);
		temp->sonraki=gecici;
	}
    void arasile(int eleman){
    	
    	if(baslangic==NULL){
    		printf("Eleman kalmadý !!!");
    		return;
		}
    	if(baslangic->sayi==eleman){
    		bassil();
    		return;
		}
    	struct node *temp=baslangic;
    	while(temp->sonraki!=NULL){
    		if(temp->sonraki->sayi==eleman){
    			struct node *gecici=temp->sonraki->sonraki;
		        free(temp->sonraki);
		        temp->sonraki=gecici;
			}
			temp=temp->sonraki;
		}
	}
    struct node* tersr(struct node*MEVCUT){
    	if( MEVCUT==NULL){
    		return MEVCUT;
		}
		if(MEVCUT->sonraki == NULL)
		{
			baslangic=MEVCUT;
			return MEVCUT;
		}
		struct node* DUGUM = tersr(MEVCUT->sonraki);
		DUGUM->sonraki=MEVCUT;
		MEVCUT->sonraki= NULL;
		return MEVCUT;
	}
	void terscev(){
    	struct node *mevcut =baslangic;
    	struct node *onceki =NULL;
    	struct node *sonraki =NULL;
    	while(mevcut != NULL)
		{
			sonraki=mevcut->sonraki;
			mevcut->sonraki=onceki;
			onceki=mevcut;
			mevcut=sonraki;
		}
		baslangic=onceki;
    	
	}
	void yazdir(){
	struct node *caba=baslangic;
	while(caba!=NULL){
		printf("%d  ",caba->sayi);
		caba=caba->sonraki;
	}
	
}

int main()

{

    int secim, sayi, pos;



    while(1)

    {

        printf("\n ****** Ekleme Islemleri ****** ...");

        printf("\n 1- Sona Eleman Ekle ...");

        printf("\n 2- Basa Eleman Ekle ...");

        printf("\n 3- Araya Eleman Ekle ...");

        printf("\n");

        printf("\n ****** Silme Islemleri ****** ...");

        printf("\n 4- Sondan Sil ...");

        printf("\n 5- Bastan Sil ...");

        printf("\n 6- Aradan Sil (pozisyona gore)...");

        printf("\n 7- Aradan Sil (elemana gore)...");

        printf("\n 8- Ters Cevir (Iterative)...");

        printf("\n 9- Ters Cevir (Recursive)...");

        printf("\n Yapmak istediginiz islemi secin ...");

        scanf("%d", &secim);



        switch(secim)

        {

        case 1:

            printf("\n Hangi elemani ekleyeceksiniz? ... ");

            scanf("%d", &sayi);

            sonaekle(sayi);

            yazdir();

            break;

        case 2:

            printf("\n Hangi elemani ekleyeceksiniz? ... ");

            scanf("%d", &sayi);

            basaekle(sayi);

            yazdir();

            break;

        case 3:

            printf("\n Hangi elemani ekleyeceksiniz? ... ");

            scanf("%d", &sayi);

            printf("\n Hangi pozisyona ekleyeceksiniz? ... ");

            scanf("%d", &pos);

            arayaekle(pos, sayi);

            yazdir();

            break;

        case 4:

            sonsil();

            yazdir();

            break;

        case 5:

            bassil();

            yazdir();

            break;

        case 6:

            printf("\n Hangi pozisyondan sileceksiniz? ... ");

            scanf("%d", &pos);

            aradansil(pos);

            yazdir();

            break;

        case 7:

            printf("\n Hangi elemani sileceksiniz? ... ");

            scanf("%d", &sayi);

            arasile(sayi);

            yazdir();

        case 8:

            terscev();

            yazdir();

            break;

        case 9:

            printf("\n Baslangic Dugumunden Baslaniyor %d\n", baslangic->sayi);


            tersr(baslangic);

            yazdir();

            break;



        }

    }

}

