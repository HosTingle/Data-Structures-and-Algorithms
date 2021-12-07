#include<stdio.h>
#include<stdlib.h>
struct node{
	int sayi;
	struct node *sonraki;
	struct node *onceki;
};
struct node *bas=NULL;
struct node *son=NULL;
struct node *olustur(int sayi){
	struct node *yenidugum = (struct node*)malloc(sizeof(struct node));
	yenidugum->sayi=sayi;
	yenidugum->sonraki=NULL;
	yenidugum->onceki=NULL;
	return yenidugum;
    }
void sonekle(int sayi){
	struct node *sone=olustur(sayi);
	if(bas==NULL){
		bas=sone;
	}
	else
	{
		struct node *temp=bas;
		while(temp->sonraki!=NULL){
			
			temp=temp->sonraki;
		}
		temp->sonraki=sone;
		sone->onceki=temp;
	}
	
}
void yazdir(struct node *bas, int ileri){
	struct node *temp=bas;
	while(bas!=NULL){
		printf("%d ",temp->sayi);
		if(ileri==1)
		temp=temp->sonraki;
		else
		temp=temp->onceki;
	}
}
void basaekle(int sayi){
	struct node *basae=olustur(sayi);
	if(bas==NULL){
		bas=basae;
		return;
	}
		struct node *temp=bas;
		bas=basae;
		bas->sonraki=temp;
		temp->onceki=bas;
		
	
}
void arayaekleme(int indis,int sayi){
	struct node *araya=olustur(sayi);
	
	if(indis==0){
		basaekle(sayi);
		return;
	}
	if(bas==NULL && indis>0){
		printf(" Uygun konum degil");
		return;
	}
	int counter=0;
	struct node *temp=bas;
	while(temp!=NULL)
	{
		
		if(counter==indis-1){
			struct node *eski=temp->sonraki;
			temp->sonraki=araya;
			araya->onceki=temp;
			araya->sonraki=eski;
			eski->onceki=araya;
		}
		temp=temp->sonraki;
		counter++;
	}
}
void sonsil(){
	if(bas==NULL){
		printf("Silinecek eleman yok");
		return;
	}
	if(bas->sonraki==NULL){
		free(bas);
		bas=NULL;
		return;
	}
	struct node *temp=bas;
	while(temp->sonraki!=NULL){
		temp=temp->sonraki;
	}
	struct node *onceki=temp->onceki;
	onceki->sonraki=NULL;
	free(temp);
	return;
	
}
void bastansil(){
	if(bas==NULL){
		printf("Eleman yok !!!!");
		return;
	}
	struct node *temp=bas->sonraki;
	temp->onceki=NULL;
	free(bas);
	bas=temp;
}
void aradansil(int indis){
	if(indis==0){
		if(bas!=NULL){
			bastansil();
			return;
		}
	}
	struct node *temp=bas;
	int counter=0;
	int flag=0;
	while(temp!=NULL){
		
		if(counter==indis){
			flag=1;
			struct node *gec=temp->sonraki;
			struct node *geri=temp->onceki;
			geri->sonraki=gec;
			gec->onceki=geri;
			free(temp);
			return;
			
			
	    }
		temp=temp->sonraki;
		counter++;
		if(temp->sonraki==NULL){
			sonsil();
			return;
		}
	}
	
	
}
int main(){
	sonekle(5);
	sonekle(3);
	sonekle(1);
	sonekle(2); 
	basaekle(4);
	basaekle(2);
	basaekle(3);
	basaekle(7);
    arayaekleme(4,100);	
	sonsil();
	bastansil();
	aradansil(5123213);
	arayaekleme(3,123);
	yazdir(bas,1);	
}

