#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <string>
#include <locale>
#include <algorithm> 
#include <cctype>
using namespace std;

//fungsi edit distance
int EditDistance(string word1, string word2)
{
    int i, j, l1, l2, m;
    l1 = word1.length();
    l2 = word2.length();
    vector< vector<int> > t(l1 + 1, vector<int>(l2 + 1));
 
    for (i = 0; i <= l1; i++)
        t[i][0] = i;
    for (i = 1; i <= l2; i++)
        t[0][i] = i;
 
    for (i = 1; i <= l1; i++)
    {
        for (j = 1; j <= l2; j++)
        {
            m = min(t[i-1][j], t[i][j-1]) + 1;
            t[i][j] = min(m, t[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1));
        }
    }
    return t[l1][l2];
}

//fungsi sorting
void quickSort(string arr[], int left, int right, int freq[]) {
      int i = left, j = right,tmp1;
      string tmp;
      string pivot = arr[(left + right) / 2];
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
		tmp1= freq[i];
                  arr[i] = arr[j];
		freq[i]=freq[j];
                  arr[j] = tmp;
		freq[j]=tmp1;
                  i++;
                  j--;
            }
      };
      /* recursion */
      if (left < j)
            quickSort(arr, left, j,freq);
      if (i < right)
            quickSort(arr, i, right,freq);
}
//fungsi cek punctution
int punctuation(int a )
{
if(ispunct(a) && a!='\'') return 1;
return 0;
}

void header() {
	cout<<"=========PROGRAM EDIT DISTANCE=========\n\n";
    cout<<setw(25)<<"Dibuat oleh:\n";
    cout<<"Dedy Van Hauten \t(1400910039)\n";
    cout<<"Farouq Faisal Anam \t(1400910045)\n";
    cout<<"Richard Nathaniel C \t(1400910015)\n\n";
	cout<< "\nPROGRAM EDIT DISTANCE\n";
	}

int main () {
int byk,i= 0;
int distance,editdistance,hound[10000],freq[10000];	
char pilihan;
  string arr[10000],line,kata;
  ifstream data("textupload.txt");//baca file
  if (data.is_open())
  {
    while(!data.eof())
    {
       istream & getline(data >> line);
       transform(line.begin(),line.end(),line.begin(), ::tolower);//tolower
       line.erase(remove_if(line.begin(),line.end(), ([](char x){return ::punctuation(x);}) ), line.end());//punctuation
	bool ada = false; 
	for (i=0;i<byk;i++)
	{	
		if (arr[i] == line)
		{
			ada=true;
			freq[i]++;
			break;
		}
	}
	if (ada ==false)
{
	arr[byk] = line;
			byk++;
}
    }
    data.close();
  }

  else cout << "Unable to open file"; 

do {
	system("cls");
	header();
bool adamatch=false;
	// sorting data
	quickSort(arr,0,byk,freq);
	
	cout <<"Masukkan kata yang ingin diketahui distancenya ";
	cin >>kata;
	transform(kata.begin(), kata.end(), kata.begin(), ::tolower);

	//panggil fungsi distance
	for (int i=0;i<byk;i++)
	{
		hound[i] = EditDistance(arr[i],kata);
	}
	
	loop:
	cout<<"Masukkan Edit Distance (Minimum 0): ";
	//pencarian edit distance
	cin>>editdistance;
	//error checking
	if (cin.fail()) {
        	cout <<"Maaf input yang anda masukkan harus berupa angka, silahkan masukan kembali"<<endl;
        	cin.clear ();
        	cin.ignore();
		goto loop;
   	}
	for (int i=0;i<=editdistance;i++)
	{
		for (int j=0;j<byk;j++)
		{
			if (hound[j]==i)
			{
				adamatch = true;
				cout<< arr[j]<<" "<<hound[j]<<" "<<freq[j]+1<<endl;
			}
		}
	} 
	if (adamatch==false) cout<<"No Match Found\n";
	cout<<"Apakah Anda ingin melakukan pencarian lagi? [Jika YA, masukkan Y] ";
	cin>>pilihan;
} while(pilihan=='y'||pilihan=='Y');
	
	cout<<"\nTerima kasih telah menggunakan program Edit Distance!\n";
return 0;
}

