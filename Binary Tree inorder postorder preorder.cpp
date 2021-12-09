#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *Sagdugum;
	struct node *Soldugum;
};
struct node *olustur(int sayi){
	struct node *yenisayi=(struct node*)malloc(sizeof(struct node));
	yenisayi->data=sayi;
	yenisayi->Sagdugum=NULL;
	yenisayi->Soldugum=NULL;
	return yenisayi;
}
void inorder(struct node *temp)
{
	if(temp==NULL)
	return;
	
	inorder(temp->Soldugum);
	printf("%d  ",temp->data);
	inorder(temp->Sagdugum);
	
}
void preorder(struct node *temp)
{
	if(temp==NULL)
	return;
	printf("%d  ",temp->data);
	preorder(temp->Soldugum);
	preorder(temp->Sagdugum);
	
	
	
}
void postorder(struct node *temp)
{
	if(temp==NULL)
	return;
	
	postorder(temp->Soldugum);
	postorder(temp->Sagdugum);
	printf("%d  ",temp->data);
	
}


int main(){
	struct node *RootNode=olustur(2);
	struct node *NodeB=olustur(3);
	struct node *NodeC=olustur(4);
	struct node *L1=olustur(6);
	struct node *L2=olustur(7);
	struct node *L3=olustur(8);
	struct node *L4=olustur(9);
	RootNode->Soldugum=NodeB;
	RootNode->Sagdugum=NodeC;
	NodeB->Soldugum=L1;
	NodeB->Sagdugum=L2;
	NodeC->Soldugum=L3;
	NodeC->Sagdugum=L4;
	inorder(RootNode);
	printf("\n");
	preorder(RootNode);
	printf("\n");
	postorder(RootNode);

	
	
}
