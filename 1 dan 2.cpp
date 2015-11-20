#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <algorithm> 
#include <cctype>

using namespace std;

//frequensi blom

int punctuation(int a )
{
if(ispunct(a) && a!='\'') return 1;
return 0;
}

int main () {
  const int ukuran =9999;
  int a= 0;
  string array[ukuran];
  string line;
  ifstream data("datatest.txt");//baca file
  if (data.is_open())
  {
    while(!data.eof())
    {
       istream & getline(data >> line);
       transform(line.begin(),line.end(),line.begin(), ::tolower);//tolower
       line.erase(remove_if(line.begin(),line.end(), ([](char x){return ::punctuation(x);}) ), line.end());//punctuation 
	   array[a] = line;
       cout << array[a] << endl;
       a++;
    }
    cout << array[1] << endl;
    data.close();
  }
  else cout << "Unable to open file"; 


  return 0;
}


