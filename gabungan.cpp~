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
using namespace std;


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

void quickSort(string arr[], int left, int right) {
      int i = left, j = right;
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
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
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
	int distance,editdistance,hound[10000],freq[10000]={1};
	string arr[10000],kata,line;
	int banyak = 0;
	bool ada;
	bool adamatch=false;
		header();
	  ifstream data("textupload.txt");//baca file
	  if (data.is_open())
	  {
	    while(!data.eof())
	    {
		ada = false;
	       istream & getline(data >> line);
	       transform(line.begin(),line.end(),line.begin(), ::tolower);//tolower
	       line.erase(remove_if(line.begin(),line.end(), ::ispunct ), line.end());//punctuation 
		for ( int i = 0; i<banyak; i++)
		{
			if (line==arr[i]) 
			{
				ada=true;
				freq[i]++;
				break;
			}
		}
		if (ada==false)  
		{
			arr[banyak] = line;
		  	banyak++;
		}
			
	    }
	    
	    data.close();
	}
	else cout << "Unable to open file"; 

	quickSort(arr,0,banyak);
	cout <<"Masukkan kata yang ingin diketahui distancenya ";
	cin >>kata;
	transform(kata.begin(), kata.end(), kata.begin(), ::tolower);
	//panggil fungsi distance
	for (int i=0;i<=banyak;i++)
	{
		hound[i] = EditDistance(arr[i],kata);
	}

	cout<<"Masukkan Edit Distance (Minimum 0): ";
	cin>>editdistance;
	for (int i=0;i<=editdistance;i++)
	{
		for (int j=0;j<=banyak;j++)
		{
			if (hound[j]==i)
			{
				adamatch = true;
				cout<< arr[j]<<" "<<hound[j]<<" "<<freq[j]<<endl;
			}
		}
	} 
	if (adamatch==false) cout<<"Kata tidak ditemukan!\n";
  return 0;
}

