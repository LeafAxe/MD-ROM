
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void encode(ofstream&);
void decode();
void writeheader(ofstream&);


int main(){
	
	char choice;
	cout << "Encode to ATRAC/Decode from ATRAC? (E/D)\n";
	cin >> choice;
	if (choice=='E'){
		ofstream outfile("output.aea",ios::binary);
		writeheader(outfile);
		encode(outfile);
		outfile.close();
	}else if (choice=='D'){
		decode();
	}
	
	return 0;
}

void writeheader(ofstream &outfile){
	string header;
	cout << "Enter desired ATRAC title (to appear as the official title on MD)\n";
	cin >> header;
	unsigned char headdata[0xB50] = {0};
	headdata[1] = 8;
	
	for(unsigned int i=0;i<header.length();i++){
		headdata[4+i] = header[i];
	}
	headdata[0x108] = 2;
	
	outfile.write((char*)headdata,sizeof(headdata));
}

void encode(ofstream &outfile){
	string filename;

	
	int sizey=0;
	cout << "Enter name of file to be converted to ATRAC (with extension)\n";
	cin >> filename;
	
	ifstream infile(filename,ios::binary);
	infile.seekg(0,ios::end);
	sizey = infile.tellg();
	
	infile.seekg(0,ios::beg);
	
	
	int sizeynew=sizey*1.0095238095238095238095238095238;
	
	char *horse = new char[sizeynew+212]{};
	char *horse2 = new char[sizey+212]{};
	
	//hidden file read:
	cout << sizey << endl;
	cout << sizeynew<< endl;
	infile.read(horse2,sizey);
	
	infile.close();
	
	
	//operations with horse and trojan
	int k=0;
	int l=0;
	
	//for(int f=0;f<;f++){
	
//for (int h=0;h<sizey;h=h+210){

while (l<sizey){
	for (int j=0;j<210;j++){
		horse[j+k]=horse2[j+l];
		
	} 
	k=k+212;
	l=l+210;
}
	
//Needed to make full 212-byte audio blocks so the burner doesn't throw a fit
int addon = sizeynew%212;

outfile.write(horse,sizeynew+(212-addon));
	
	
}




void decode(){
	string filename;

	int sizey=0;
	
	cout << "Enter ATRAC filename with .aea extension\n";
	cin >> filename;
	
	ifstream infile(filename,ios::binary);
	infile.seekg(0,ios::end);
	sizey = infile.tellg();
	sizey = sizey - 0xB50;
	infile.seekg(0xB50,ios::beg);
	
	int sizeynew=((sizey-1)/1.0095238095238095238095238095238);
	
	unsigned char *horse=new unsigned char[sizey+212]{0};
	unsigned char *horse2=new unsigned char[sizeynew+212]{0};
	
	infile.read((char*)horse,sizey);
	
	int p=0;
	int q=0;
	
	do{
		for(int i=0;i<210;i++){
			horse2[i+p]=horse[i+q];
		}
		q=q+212;
		p=p+210;
		
		
	}while(q<sizey);
	
	ofstream outfile(filename+"_decoded.bin",ios::binary);
	outfile.write((char*)horse2,sizeynew+1);
	outfile.close();
	
	
}	
