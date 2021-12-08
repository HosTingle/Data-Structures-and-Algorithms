#include<stdio.h>
#include<stdbool.h>
#define BOYUT 10
int dizi[BOYUT];
int top=-1;

bool DoluMu()
{
	if(top==BOYUT-1)
	return true;
	else
	return false;
	
}
bool bosmu()
{
	
	if(top==-1)
	return true;
	else
	return false;
		
	
}
void push(int sayi){
	bool Dolu = DoluMu();
	if(Dolu==true)
	{
		printf("\n Stackoverflow...");
		return;
	}
	top=top+1;
	dizi[top]=sayi;
}
void pop(){
	
	bool Dolu = bosmu();
	if(Dolu==true)
	{
		printf("\n Stack zaten boþ.");
		return;
	}
	int eski=dizi[top];
	top=top-1;
}
int peek()
{
	return dizi[top];
}
void yazdir(){
	for(int i=top;i>=0;i--){
		printf( "\n %d",dizi[i]);
	}
}
int main(){
	int a,b,secim,sayi;
    
    while(1)

    {

        printf("\n*******************");

        printf("\n 1-Eleman Ekle...");

        printf("\n 2-Eleman Sil...");
        
        printf("\n 3-Top degerini goster...");

        printf("\n Yapmak istediginiz islemi secin ...");

        scanf("%d", &secim);

        switch(secim)

        {

        case 1:

            printf("\n Ekleyeginiz eleman=");

            scanf("%d", &sayi);

            push(sayi);

            yazdir();

            break;

        case 2:
        	printf("\n ");


            pop();

            yazdir();

            break;
        case 3:

            peek();
            printf("%d",dizi[top]);


            break;
    
	
}
}
}
