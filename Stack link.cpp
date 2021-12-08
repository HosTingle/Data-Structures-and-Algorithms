#include<stdio.h>
#include<stdlib.h>
struct node{
	int sayi;
	struct node *sonraki;
};
struct node *top;
void push(int sayi){
	struct node *ekle=(struct node*)malloc(sizeof(struct node));
	ekle->sayi=sayi;
	ekle->sonraki=top;
	top=ekle;
}
void yazdir(){
	struct node *temp=top;
	while(temp!=NULL){
		printf(" %d  ",temp->sayi);
		temp =temp->sonraki;
	}
}
void pop(){
	if(top==NULL){
		printf("Silenecek sayi yok");
		return;
	}
	struct node *temp=top;
    top=temp->sonraki;
    free(temp);
	
}
int main()
{
    int secim;
    int sayi;
    while(1)
    {
         printf("\n 1- Eleman ekle");
         printf("\n 2- Eleman Cikar");
         printf("\n 3- Eleman Yazdir... ");
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
