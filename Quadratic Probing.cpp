#include<stdio.h>
#include<stdlib.h>
int dizi[7];
int hashhesapla(int gelen){
	return gelen%7;
}
void insert(int eleman){
	int konum=hashhesapla(eleman);
	if(dizi[konum]==0){
		dizi[konum]=eleman;
	}
	else{
		for(int i=0;i<7;i++){
			int durum=dizi[(konum+i*i)%7];
			if(durum==0){
				dizi[(konum+ i*i)%7]=eleman;
				return;
			}
		}
	}
}
void yazdir(){
	for(int i=0;i<7;i++){
		printf("\n%d indis degeri %d",i,dizi[i]);
	}
}
int main(){
	insert(12);
	insert(13);
	insert(5);
	insert(15);
	yazdir();
	
}
