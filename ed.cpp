#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void header() {
	cout<<"=========PROGRAM EDIT DISTANCE=========\n\n";
    cout<<setw(25)<<"Dibuat oleh:\n";
    cout<<"Dedy Van Hauten \t(1400910039)\n";
    cout<<"Farouq Faisal Anam \t(1400910045)\n";
    cout<<"Richard Nathaniel C \t(1400910015)\n\n";
	cout<< "\nPROGRAM EDIT DISTANCE\n";
	}

void menu() {

	}


int main() {
	string input;
	int ed;
	header();
	
	FILE *File;
	File= FileOpen("input.txt");
	if (!File) { 
		printf("File Tidak Ditemukan!\n\n");      
		exit(1); 
		}
	//Ini sekalian deh
	//Aang tolong perbaiki kalo salah
	
	cout<<"Masukkan Kata: ";
    getline(cin,input);
    
    cout<<"Masukkan Edit Distance (Minimum 0): ";
    cin>>ed;
    
    //Masukkan Codingan Edit Distance
    
    fclose(File);    	                 
	exit(1);
	}
