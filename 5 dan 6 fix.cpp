#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <string.h>
#include <vector>
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

int main()
{
	int banyak,distance,editdistance;
	string arr[100],kata;
	int hound[100], freq[100];
	cin>> banyak;
	for (int i=0;i<banyak;i++)
	{
		cin>> arr[i];
	}
	quickSort(arr,0,banyak);
	cin >>kata;
	//panggil fungsi distance
	for (int i=0;i<=banyak;i++)
	{
		hound[i] = EditDistance(arr[i],kata);
	}

	cin>>editdistance;
	for (int i=0;i<=editdistance;i++)
	{
		for (int j=0;j<=banyak;j++)
		{
			if (hound[j]==i)
			{
				cout<< arr[j]<<" "<<hound[j]<<" "<<freq[j]<<endl;
			}
		}
	} 
}
//https://vinayakgarg.wordpress.com/2012/12/10/edit-distance-using-dynamic-programming/*/
