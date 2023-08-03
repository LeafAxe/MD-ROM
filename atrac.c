#include <stdio.h>
#include <stdlib.h>


void encode();
void decode();


int main(){
	char choice;
	printf("Encode/Decode (E/D)\n");
	scanf(" %c",&choice);
	if (choice=='E'){
		encode();
	}else if (choice=='D'){
		decode();
	}
	
	return 0;
}

void encode(){
	char filename[60];

	
	int sizey=0;
	
	printf("Put in # of bytes of src\n");
	scanf("%d",&sizey);
	
	int sizeynew=sizey*1.0095238095238095238095238095238;
	
	unsigned char *horse=malloc(sizeynew+213);
	unsigned char *trojan=malloc(sizey+212);
	
	//hidden file read:
	
	FILE *point2;
	
	do{
	printf("Put in hidden file filename\n");
	scanf("%s",&filename);
	point2=fopen(filename,"rb");
	}while(point2==NULL);
	
	
	fread(trojan,sizey,1,point2);
	
	fclose(point2);
	
	//operations with horse and trojan
	int k=0;
	int l=0;
	
	//for(int f=0;f<;f++){
	
//for (int h=0;h<sizey;h=h+210){

while (l<sizey){
	for (int j=0;j<210;j++){
		horse[j+k]=trojan[j+l];
		
	} 
	k=k+212;
	l=l+210;
}

	
	FILE *point3;
	point3=fopen("newfile.bin","wb");
	
	fwrite(horse,1,sizeynew+1,point3);
	
	fclose(point3);
	
	free(horse);
	free(trojan);
	
}









void decode(){
	char filename[60];

	int sizey=0;
	
	printf("Put in # of bytes of src\n");
	scanf("%d",&sizey);
	
	int sizeynew=((sizey-1)/1.0095238095238095238095238095238);
	
	unsigned char *horse=malloc(sizey+212);
	unsigned char *horse2=malloc(sizeynew+212);

	FILE *point2;
	
	do{
		printf("Put in filename\n");
		scanf("%s",&filename);
		point2=fopen(filename,"rb");
	}while(point2==NULL);
	
	fread(horse,sizey,1,point2);
	fclose(point2);
	
	int p=0;
	int q=0;
	
	do{
		for(int i=0;i<210;i++){
			horse2[i+p]=horse[i+q];
		}
		q=q+212;
		p=p+210;
		
		
	}while(q<sizey);
	
	
	FILE *point3;
	point3=fopen("decod.bin","wb");
	
	fwrite(horse2,1,sizeynew+1,point3);
	
	fclose(point3);
	
	free(horse);
	free(horse2);
	
	
}	
	
