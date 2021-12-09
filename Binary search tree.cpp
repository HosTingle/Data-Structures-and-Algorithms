#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *Sagdugum;
	struct node *Soldugum;
};
struct node *root=NULL;
struct node *olustur(int sayi){
	struct node *yenisayi=(struct node*)malloc(sizeof(struct node));
	yenisayi->data=sayi;
	yenisayi->Sagdugum=NULL;
	yenisayi->Soldugum=NULL;
	return yenisayi;
}
struct node *ekle(struct node *root,int eklene){
	if(root==NULL)
	return olustur(eklene);
	if(eklene<root->data)
	root->Soldugum=ekle(root->Soldugum,eklene);
	if(eklene>root->data)
	root->Sagdugum=ekle(root->Sagdugum,eklene);
	return root;
}
void inorder(struct node *temp)
{
	if(temp==NULL)
	return;
	
	inorder(temp->Soldugum);
	printf("%d  ",temp->data);
	inorder(temp->Sagdugum);
	
}
struct node *ara(struct node *root,int sayi){
	if(root!=NULL)
	printf("\n Kontrol Edilen sayi %d",root->data);
	
	if(root->data==sayi || root==NULL)
		return root;
	if(sayi<root->data)
	ara(root->Soldugum,sayi);
	else
	ara(root->Sagdugum,sayi);
}
struct node *enkucukbul(struct node *baslangic){
	struct node *mevcut=baslangic;
	while(mevcut !=NULL && mevcut->Soldugum!=NULL)
	mevcut=mevcut->Soldugum;
	
	return mevcut;
}

struct node *sil(struct node *root,int sayi){
	if(root==NULL)
	{
		return root;
	}
	if(sayi<root->data)
	root->Soldugum=sil(root->Soldugum,sayi);
	else if(sayi>root->data)
	root->Sagdugum=sil(root->Sagdugum,sayi);
	else{
		if(root->Soldugum==NULL){
			struct node *gecici=root->Sagdugum;
			free(root);
			return gecici;
		}
		else if(root->Sagdugum==NULL)
		{
			struct node *gecici=root->Soldugum;
			free(root);
			return gecici;
		}
		struct node* Silinecekd=enkucukbul(root->Sagdugum);
		root->data=Silinecekd->data;
		root->Sagdugum=sil(root->Sagdugum,Silinecekd->data);
	}
	
	return root;
}

int main(){
	root=ekle(root,20);
	ekle(root,30);
	ekle(root,20);
	ekle(root,10);
	ekle(root,40);
	ekle(root,80);
	ekle(root,32);
	sil(root,20);
	inorder(root);
	
}
