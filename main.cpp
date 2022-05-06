#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
string read(int i, int j){
	string line [i*7];
	string x;
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x&&ii<i*7) {
		line[ii]=x;
		ii++;
   	}	
   	inFile.close();
   	return line[i*7-8+j];
}
long int decodeShort(string s){
	char c;
	int bit;
	long int x=0;
	for(int i=0; i<16; i++)
	{
		c=s[15-i];
		if(c=='1')
		{
			bit=1;
		}
		else
		{
			bit=0;
		}
		for(int j=0; j<i; j++)
		{
			bit=bit*2;
		}
		x=x+bit;
	}
	return x;
}
string encodeLong(long int x){
	string cs="";
	string sc="";
	char c;
	int bit;
	for(int j=0; j<32; j++)
	{
		bit=x%2;
		if(bit==1)
		{
			c='1';
		}
		else
		{
			c='0';
		}
		sc=sc+c;
		x=x/2;
	}
	for(int i=sc.size()-1; i>=0; i--)
	{
		c=sc[i];
		cs=cs+c;
	}
	return cs;
}
string encodeShort(short int x){
	string cs="";
	string sc="";
	char c;
	int bit;
	for(int j=0; j<16; j++)
	{
		bit=x%2;
		if(bit==1)
		{
			c='1';
		}
		else
		{
			c='0';
		}
		sc=sc+c;
		x=x/2;
	}
	for(int i=sc.size()-1; i>=0; i--)
	{
		c=sc[i];
		cs=cs+c;
	}
	return cs;
}
long int decodeLong(string s){
	char c;
	int bit;
	long int x=0;
	for(int i=0; i<32; i++)
	{
		c=s[31-i];
		if(c=='1')
		{
			bit=1;
		}
		else
		{
			bit=0;
		}
		for(int j=0; j<i; j++)
		{
			bit=bit*2;
		}
		x=x+bit;
	}
	return x;
}
string decodeString(string s)
{
	char c;
	string cs="";
	int x;
	int b;
	for(int i=0; i<s.size()/8; i++)
	{
		b=0;
		for(int j=7; j>=0; j--)
		{
			c=s[i*8+j];
			if(c=='1')
			{
				x=1;
			}
			else
			{
				x=0;
			}
			for(int k=0; k<7-j; k++)
			{
				x=x*2;
			}
			b=b+x;
		}
		c=char(b);
		cs=cs+c;
	}
	return cs;
}
string encodeString(string s)
{
	char c;
	int byte;
	int bit [8];
	string cs="";
	for(int i=0; i<s.size(); i++)
	{
		c=s[i];
		byte=c;
		for(int j=0; j<8; j++)
		{
			bit[7-j]=byte%2;
			byte=byte/2;
		}
		for(int k=0; k<8; k++)
		{
			if(bit[k]==1)
			{
				c='1';
			}
			else
			{
				c='0';
			}
			cs=cs+c;
		}
	}
	return cs;
}
void szukajRok (){
	string x;
	system("cls");
	cout<<"wpisz szukany Rok"<<endl;
	short int w;
	cin>>w;
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
	}	
	inFile.close();
	for(int i=1; i<=ii/7; i++)
	{
		if(decodeShort(read(i,7))==w)
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
		}
	}
	int uselessStoper=getch();

}
void szukajWydaw (){
	string x;
	system("cls");
	cout<<"wpisz szukane wydawnictwo"<<endl;
	string w;
	getline(cin, w);
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
	}	
	inFile.close();
	for(int i=1; i<=ii/7; i++)
	{
		if(decodeString(read(i,6))==w)
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
		}
	}
	int uselessStoper=getch();

}
void szukajISBN (){
	string x;
	system("cls");
	cout<<"wpisz szukany ISBN"<<endl;
	string w;
	getline(cin, w);
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
	}	
	inFile.close();
	for(int i=1; i<=ii/7; i++)
	{
		if(decodeString(read(i,5))==w)
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
		}
	}
	int uselessStoper=getch();

}
void szukajTytul (){
	string x;
	system("cls");
	cout<<"wpisz szukany Tytul"<<endl;
	string w;
	getline(cin, w);
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
	}	
	inFile.close();
	for(int i=1; i<=ii/7; i++)
	{
		if(decodeString(read(i,4))==w)
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
		}
	}
	int uselessStoper=getch();

}
void szukajAutor (){
	string x;
	system("cls");
	cout<<"wpisz szukanego Autora"<<endl;
	string w;
	getline(cin, w);
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
	}	
	inFile.close();
	for(int i=1; i<=ii/7; i++)
	{
		if(decodeString(read(i,3))==w)
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
		}
	}
	int uselessStoper=getch();

}
void szukajSygil (){
	string x;
	system("cls");
	cout<<"wpisz szukana sygnature"<<endl;
	string w;
	getline(cin, w);
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
	}	
	inFile.close();
	for(int i=1; i<=ii/7; i++)
	{
		if(decodeString(read(i,2))==w)
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
		}
	}
	int uselessStoper=getch();

}
void szukajNumer (){
	string x;
	system("cls");
	cout<<"wpisz szukany numer"<<endl;
	long int w;
	cin>>w;
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
	}	
	inFile.close();
	for(int i=1; i<=ii/7; i++)
	{
		if(decodeLong(read(i,1))==w)
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
		}
	}
	int uselessStoper=getch();

}
void szukajNumber (){
	string x;
	system("cls");
	cout<<"wpisz szukany numer"<<endl;
	long int w;
	cin>>w;
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
	}	
	inFile.close();
	for(int i=1; i<=ii/7; i++)
	{
		if(i=w)
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
			break;
		}
	}
	int uselessStoper=getch();

}
void listuj(){
	string x;
	system("cls");
	string s;
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
   	}	
   	inFile.close();
   	for(int i=1; i<=ii/7; i++)
   	{
   		cout<<"------------------------------------------------------------------------------------------"<<endl;
   		cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
   		cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
   		cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
   		cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
   		cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
   		cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
		cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
	}
	int uselessStoper=getch();
}
void removeThis(int key){
	string line;
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	ofstream temp;
	temp.open("temp.bin");
	int ii=7;
	while (getline(inFile, line))
	{
		if ((ii/7)!=key)
		{
			temp << line << endl;
		}
		ii++;
	}	
   	inFile.close();
   	temp.close();
	remove("Librarby.bin");
	rename("temp.bin", "Librarby.bin");
	
}
void menuRemove (int key){
	string x;
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
   	}	
   	inFile.close();
   	for(int i=1; i<=ii/7; i++)
   	{
   		if(i==key)
   		{
   			cout<<"------------------------------------------------------------------------------------------"<<endl;
   			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<"  <<"<<endl;
   			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<"  <<"<<endl;
   			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<"  <<"<<endl;
   			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<"  <<"<<endl;
   			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<"  <<"<<endl;
   			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<"  <<"<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<"  <<"<<endl;
		}
		else
		{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
   			cout<<i<<"."<<"numer        "<<decodeLong(read(i,1))<<endl;
   			cout<<i<<"."<<"sygnatura    "<<decodeString(read(i,2))<<endl;
   			cout<<i<<"."<<"autor        "<<decodeString(read(i,3))<<endl;
   			cout<<i<<"."<<"tytul        "<<decodeString(read(i,4))<<endl;
   			cout<<i<<"."<<"ISBN         "<<decodeString(read(i,5))<<endl;
   			cout<<i<<"."<<"wydawnictwo  "<<decodeString(read(i,6))<<endl;
			cout<<i<<"."<<"rok          "<<decodeShort(read(i,7))<<endl;
		}
	}
}
void remove(){
	string x;
	system("cls");
	ifstream inFile;
	inFile.open("Librarby.bin");
	if (!inFile) {
		cout<<"Unable to open file datafile.txt";
    	exit(1);
	}
	int ii=0;
	while (inFile>>x) {
		ii++;
   	}	
   	inFile.close();
	int enter=0;
	int key=1;
	int c=0;
	menuRemove(key);
	while(enter==0)
	{
		c=getch();
		if(c==0||c==224)
		{
			switch((c=getch())) {
       	 		case 72:
            	key--;
            	break;
        		case 80:
            	key++;
            	break;
        	}
        	if(key<=0)
        	{
				key=key+ii/7;
			}
			if(key>ii/7)
			{
				key=key%ii/7;
			}
			menuRemove(key);
		}
		else
		{
			if(c==13)
			{
				enter=1;
			}
		}
	}
	removeThis(key);
	
}
void add (){
	system("cls");
	long int n=0;
	short int y=2000;
	string s="undefined";
	ofstream outFile;
	outFile.open("Librarby.bin",ios::app);
		cout<<"podaj numer";
		cin>>n;
		outFile<<"\n"<<encodeLong(n);
		cout<<"podaj sygnature";
		getline(cin, s);
		getline(cin, s);
		outFile<<"\n"<<encodeString(s);
		s="undefined";
		cout<<"podaj autora";
		getline(cin, s);
		outFile<<"\n"<<encodeString(s);
		s="undefined";
		cout<<"podaj tytul";
		getline(cin, s);
		outFile<<"\n"<<encodeString(s);
		s="undefined";
		cout<<"podaj ISBN";
		getline(cin, s);
		outFile<<"\n"<<encodeString(s);
		s="undefined";
		cout<<"podaj wydawnictwo";
		getline(cin, s);
		outFile<<"\n"<<encodeString(s);
		cout<<"podaj rok";
		cin>>y;
		outFile<<"\n"<<encodeShort(y);
	outFile.close();		
}
void menu1 (int key){
	switch (key){
	case 1:
	system("cls");
	cout<<"Dodaj Ksiazke <<"<<endl;
	cout<<"Listuj Ksiazki"<<endl;
	cout<<"Wyszukaj Ksiazke"<<endl;
	cout<<"Usun Ksiazke"<<endl;
	break;
	case 2:
	system("cls");
	cout<<"Dodaj Ksiazke"<<endl;
	cout<<"Listuj Ksiazki <<"<<endl;
	cout<<"Wyszukaj Ksiazke"<<endl;
	cout<<"Usun Ksiazke"<<endl;
	break;
	case 3:
	system("cls");
	cout<<"Dodaj Ksiazke"<<endl;
	cout<<"Listuj Ksiazki"<<endl;
	cout<<"Wyszukaj Ksiazke <<"<<endl;
	cout<<"Usun Ksiazke"<<endl;
	break;	
	case 4:
	system("cls");
	cout<<"Dodaj Ksiazke"<<endl;
	cout<<"Listuj Ksiazki"<<endl;
	cout<<"Wyszukaj Ksiazke"<<endl;
	cout<<"Usun Ksiazke <<"<<endl;
	break;
	}
}
void menu2(int key){
	switch (key){
	case 1:
	system("cls");
	cout<<"Wyszukaj Ksiazke przez:"<<endl;
	cout<<"numer <<"<<endl;
	cout<<"sygnature"<<endl;
	cout<<"autora"<<endl;
	cout<<"tytul"<<endl;
	cout<<"ISBN"<<endl;
	cout<<"wydawnictwo"<<endl;
	cout<<"rok wydania"<<endl;
	break;
	case 2:
	system("cls");
	cout<<"Wyszukaj Ksiazke przez:"<<endl;
	cout<<"numer"<<endl;
	cout<<"sygnature <<"<<endl;
	cout<<"autora"<<endl;
	cout<<"tytul"<<endl;
	cout<<"ISBN"<<endl;
	cout<<"wydawnictwo"<<endl;
	cout<<"rok wydania"<<endl;
	break;
	case 3:
	system("cls");
	cout<<"Wyszukaj Ksiazke przez:"<<endl;
	cout<<"numer"<<endl;
	cout<<"sygnature"<<endl;
	cout<<"autora <<"<<endl;
	cout<<"tytul"<<endl;
	cout<<"ISBN"<<endl;
	cout<<"wydawnictwo"<<endl;
	cout<<"rok wydania"<<endl;
	break;
	case 4:
	system("cls");
	cout<<"Wyszukaj Ksiazke przez:"<<endl;
	cout<<"numer"<<endl;
	cout<<"sygnature"<<endl;
	cout<<"autora"<<endl;
	cout<<"tytul <<"<<endl;
	cout<<"ISBN"<<endl;
	cout<<"wydawnictwo"<<endl;
	cout<<"rok wydania"<<endl;
	break;
	case 5:
	system("cls");
	cout<<"Wyszukaj Ksiazke przez:"<<endl;
	cout<<"numer"<<endl;
	cout<<"sygnature"<<endl;
	cout<<"autora"<<endl;
	cout<<"tytul"<<endl;
	cout<<"ISBN <<"<<endl;
	cout<<"wydawnictwo"<<endl;
	cout<<"rok wydania"<<endl;
	break;
	case 6:
	system("cls");
	cout<<"Wyszukaj Ksiazke przez:"<<endl;
	cout<<"numer"<<endl;
	cout<<"sygnature"<<endl;
	cout<<"autora"<<endl;
	cout<<"tytul"<<endl;
	cout<<"ISBN"<<endl;
	cout<<"wydawnictwo <<"<<endl;
	cout<<"rok wydania"<<endl;
	break;
	case 7:
	system("cls");
	cout<<"Wyszukaj Ksiazke przez:"<<endl;
	cout<<"numer"<<endl;
	cout<<"sygnature"<<endl;
	cout<<"autora"<<endl;
	cout<<"tytul"<<endl;
	cout<<"ISBN"<<endl;
	cout<<"wydawnictwo"<<endl;
	cout<<"rok wydania <<"<<endl;
	break;
	case 8:
	system("cls");
	cout<<"Wyszukaj Ksiazke przez:"<<endl;
	cout<<"numer"<<endl;
	cout<<"sygnature"<<endl;
	cout<<"autora"<<endl;
	cout<<"tytul"<<endl;
	cout<<"ISBN"<<endl;
	cout<<"wydawnictwo"<<endl;
	cout<<"rok wydania"<<endl;
	cout<<"numer kolejnosci w bazie danych <<"<<endl;
	break;
	}
	
}
void menukey2(){
	int enter=0;
	int key=1;
	menu2(key);
	int c=0;
	while(enter==0)
	{
		c=getch();
		if(c==0||c==224)
		{
			switch((c=getch())) {
       	 		case 72:
            	key--;
            	break;
        		case 80:
            	key++;
            	break;
        	}
        	if(key<=0)
        	{
				key=key+8;
			}
			if(key>8)
			{
				key=key%8;
			}
			menu2(key);
		}
		else
		{
			if(c==13)
			{
				enter=1;
			}
		}
	}
	switch (key){
		case 1:
		szukajNumer ();
		break;
		case 2:
		szukajSygil ();
		break;
		case 3:
		szukajAutor ();
		break;
		case 4:
		szukajTytul ();
		break;
		case 5:
		szukajISBN ();
		break;
		case 6:
		szukajWydaw ();
		break;
		case 7:
		szukajRok ();
		break;
		case 8:
		szukajNumber();
		break;
	}
}
void menukey1 () {
	int enter=0;
	int key=1;
	menu1(key);
	int c=0;
	while(enter==0)
	{
		c=getch();
		if(c==0||c==224)
		{
			switch((c=getch())) {
       	 		case 72:
            	key--;
            	break;
        		case 80:
            	key++;
            	break;
        	}
        	if(key<=0)
        	{
				key=key+4;
			}
			if(key>4)
			{
				key=key%4;
			}
			menu1(key);
		}
		else
		{
			if(c==13)
			{
				enter=1;
			}
		}
	}
	switch (key){
	case 1:
	add ();
	break;
	case 2:
	listuj ();
	break;
	case 3:
	menukey2 ();
	break;
	case 4:
	remove ();
	break;
	}
}
int main(int argc, char** argv) {
	while(0==0)
	{
	menukey1();
	}
	
	
	return 0;
}
