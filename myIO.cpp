#include<iostream>
#include<string.h>
#include <conio.h>

using namespace std;
int const ZERO = 48,NINE = 73,A = 65,Z = 90,a = 97,z = 122,Enter = 13,Space = 32,BS = 8,ESC = 27;

int justInNum();
char * justInChar(bool const mode);
char * justInString(bool const mode,int &leng);
string outString(char const * listString);
char * convertString2Char(string s);
string insertStyleName(int leng);
string uperCaseAll(string s);
string rightName(string s);
void delFirstArray(char *a);
void delInArray(char *a,int n);
void delLastArray(char *a);
char convertLowcase2Uppercase(char c);
char convertUppercase2Lowcase(char C);
int char2int(int cin);
string inPassWord(int leng);
string hashPassWord(string s);
////////////////////////////////////
//int main(){
////	cout<<"Nhap\n";
////	char * c;int leng;
////	c = justInString(1,leng);
////	cout<<"\nChuoi vua nhap la:" + outString(c,leng);
////	delete c;
//	cout<<"Nhap ten:\n";
//	string name = insertStyleName(10);
//	string name2 = "     nGuyEn  le HAI Son      ";
////	char * c = convertString2Char(name2);
////	delFirstArray(c);
////	delInArray(c,5);
////	delLastArray(c);
////	char* c = convertString2Char(name2);
//	cout<<endl<<"Ten vua nhap la:\n"+name;
//	cout<<endl<<"Ten vua nhap la:\n"+rightName(name2);
////	delete []c;
//	return 0;
//}
////////////////////////////////////
int char2int(const char cin){
	return (int)cin-48;
}
int justInNum(){
	char temp;
	int num = 0;
	do{
		temp = getch();
		fflush(stdin);
		if(temp>= ZERO && temp<= NINE||temp ==Enter){
			num = num*10+(int)temp-48;
		}else{
			cout<<"Chi nhap so, moi nhap lai!!";
		}
	}while(temp!= Enter);
	return char2int(temp);
}
char * justInChar(bool const mode){
	char character,*list1character;
	bool loop = true;
	do{
		character = getch();
		fflush(stdin);
		if(mode){
			if(character == Enter||character == Space){
				loop = false;
			}
		}
		if((character>= a && character<= z)||(character>= A && character<= Z)){
			loop = false;
		}else{
			cout<<"Chi nhap chu cai, moi nhap lai!!";
		}
	}while(loop);
	cout<<character;
	list1character = &character;
	return list1character;
}
char * justInString(bool const mode,int &leng){
	switch(mode){
    case 0  :
       	cout<<"\nHam chi nhap 1 ky tu abc:";
       	return justInChar(0);
       	break;
    case 1  :
       	cout<<"\nHam nhap chuoi:";
       	cout<<"Nhap do dai chuoi:";
       	cin>>leng;
       	fflush(stdin);
       	bool loop = true;
       	char *string,temp;
       	string = new char[leng];
       	for(int i = 0;i<leng;i++){
       		string[i] = 0;
		}
       	int i = 0;
       	do{
       		temp = getch();
			fflush(stdin);
       		string[i] = temp;
       		cout<<string[i];
       		i++;
		}while(temp!=Enter&&i<leng);
		i = 0;
		while(string[i]&&i<leng){
			cout<<string[leng];
			i++;
		}
		return string;
       	break;
	}
}
char * convertString2Char(string s){
	char *c = new char[(s.size()+1)];
	std::copy(s.begin(),s.end(),c);
	c[s.size()]='\0';
	return c;
}
char convertLowcase2Uppercase(char c){
	return c+(A-a);
}
char convertUppercase2Lowcase(char C){
	
	return C-(A-a);
}
string outString(char const * listString){
	return string(listString);
}
string uperCaseAll(string s){
	char*c = convertString2Char(s);
	int i = 0;
	while(c[i]!='\0'){
		if(a<=c[i]&&c[i]<=z){
			c[i]=c[i]&'_';
		}
		i++;
	}
	s = string(c);
	delete []c;
	return s;
}
void delFirstArray(char *a){
	int i = 0;
	while(a[i]!='\0'){
		a[i] = a[i+1];
		i++;
	}
}
void delInArray(char *a,int n){
	int i = n;
	while(a[i]!='\0'){
		a[i] = a[i+1];
		i++;
	}
}
void delLastArray(char *a){
	int i = 0;
	while(a[i]!='\0'){
		i++;
	}
	a[i-1] = '\0';
}
string rightName(string s){
	char*c = convertString2Char(s);
	int i = 0;
	while(c[i]==Space){
		delFirstArray(c);
	}
	while(c[i]!='\0'){
		if(A<=c[i]&&c[i]<=Z){
			c[i] = convertUppercase2Lowcase(c[i]);
		}
		i++;
	}
	while(c[i-1]==Space&&c[i]=='\0'){
		delLastArray(c);
		i--;
	}
	i=0;
	while(c[i]!='\0'){
		if(c[i-1]==Space&&a<=c[i]&&c[i]<=z){
			c[i]=convertLowcase2Uppercase(c[i]);
		}
		if(c[i]==Space&&c[i+1]==Space){
			delInArray(c,i);
			continue;
		}
		i++;
	}
	c[0]=convertLowcase2Uppercase(c[0]);
	s = string(c);
	delete []c;
	return s;
}
string insertStyleName(int leng){
       	fflush(stdin);
       	bool loop = true;
       	char *string,temp;
       	string = new char[leng];
       	for(int i = 0;i<leng;i++){
       		string[i] = 0;
		}
		string[leng] = '\0';
       	int i = 0;
       	do{
       		temp = getch();
			fflush(stdin);
			cout<<temp;
			if((A<=temp&&temp<=Z)||(a<=temp&&temp<=z)||temp == Space||temp == Enter||temp == BS){
				string[i] = temp;
				if(temp == BS){
					delLastArray(string);
					i--;
					continue;
				}
				i++;
				if(temp == Enter){
					break;
				}
			}else{
				cout<<"\nYeu cau chi nhap ky tu ABC!!";
				continue;
			}
		}while(temp!=Enter&&i<leng);
		return rightName(string);
}
string hashPassWord(string s){
	string add = "PTITHCM";
	s+=add;
	char *c = convertString2Char(s);
	int i =0;
	while(c[i]!='\0'){
		c[i]=(c[i]&'a')|'b';
		cout<<c[i];
	}
	s = string(c);
	delete c;
	return s;
}
string inPassWord(int leng){
	cin>>leng;
       	fflush(stdin);
       	bool loop = true;
       	char *string,temp;
       	string = new char[leng];
       	for(int i = 0;i<leng;i++){
       		string[i] = 0;
		}
       	int i = 0;
       	do{
       		temp = getch();
			fflush(stdin);
       		string[i] = temp;
       		cout<<"*";
       		i++;
		}while(temp!=Enter&&i<leng);
		return hashPassWord(string);
}
