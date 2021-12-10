#include<stdio.h>
int dizi[10];
void yazdir(){
	for(int i=0;i<10;i++){
		printf("\n %d indis %d",i,dizi[i]);
	}
}

int hashhesapla(int eklenecek){
	int mod =eklenecek%10;
	return mod;
}
void insert(int eleman)
{
	int konum=hashhesapla(eleman);
	if(dizi[konum]==0){
		dizi[konum]=eleman;
	}
	else
	{
		int temp=konum;
		while(dizi[temp]!=0){
			temp=(temp+1)%10;
			if(temp==konum){
				printf("\n Dizide hic bos yer yok...");
				return;
			}
			
		}
		dizi[temp]=eleman;
		
	}
}
	void bul(int eleman){
		int konum=hashhesapla(eleman);
		if(dizi[konum]==eleman){
			printf("Aranan eleman ilk seferde bulundu %d",eleman);
		}
		else{
			int temp=konum;
			int counter=0;
			while(dizi[temp]!=0){
				counter++;
				temp=(temp+1)%10;
				if(temp==konum){
				printf("Aradiginiz eleman bulunamadi");
				return;
			}
				if(dizi[temp]==eleman){
					printf("Aranan eleman %d.seferde %d bulundu",counter,eleman);
				    return;
				}
				
			}
			printf("Aradiginiz eleman bulunamadi",counter,temp);
		}
	}

int main(){
	insert(77);
	insert(78);
	insert(67);
	insert(37);
	insert(7);
	insert(17);
	insert(4);
	bul(6543634);
	yazdir();
	
}
