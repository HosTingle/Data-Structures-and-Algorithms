#include<stdio.h>
#include<stdlib.h>
struct node{
	int sayi;
	struct node *sonraki;
};
struct node *baslangic=NULL;
struct node *son=NULL;

void push(int sayi){
	struct node *ekle=(struct node*)malloc(sizeof(struct node));
	ekle->sayi=sayi;
	ekle->sonraki=NULL;
	if(baslangic==NULL){
		baslangic=ekle;
		son=ekle;
		return;
	}
	struct node *temp=baslangic;
	while(temp->sonraki!=NULL){
		temp=temp->sonraki;
	}
	temp->sonraki=ekle;
	son=ekle;
	
}
void pop(){
	if(baslangic==NULL ||son==NULL){
		printf("**************************");
		printf("Silenecek eleman yok !!!!");
		printf("**************************");
		return;
	}
	
	struct node *temp=baslangic;
	struct node *tempy=baslangic->sonraki;
	free(baslangic);
	baslangic=tempy;
}
	
void yazdir(){
	struct node *temp=baslangic;
	while(temp!=NULL){
		printf("\n %d ",temp->sayi);
		
		temp =temp->sonraki;
	}
	printf("\n*********************\n");
	printf("\n %d(Ilk) %d(Son) \n",baslangic->sayi,son->sayi);
	printf("\n*******************\n");
	
}
int main()
{
    int secim;
    int sayi;
    while(1)
    {
    	 printf("*******************");
         printf("\n 1- Eleman ekle");
         printf("\n 2- Eleman Cikar");
         printf("\n*******************\n");
         scanf("%d", &secim);

         switch(secim)
         {
         case 1:
            printf("\n Eklemek istediginiz sayi..... ");
            scanf("%d", &sayi);
            push(sayi);
            yazdir();
            break;
         case 2:
            pop();
            yazdir();
            break;

         }

    }
}
