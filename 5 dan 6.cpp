#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

    #include <string.h>
using namespace std;
#define MIN(x,y) ((x) < (y) ? (x) : (y))
    #include <stdio.h>

    

    int d[100][100];

    

    int main()

    {

        int i,j,m,n,temp,tracker;

        char s[] = "Sanfoundry";

        char t[] = "Education";

        m = strlen(s);

        n = strlen(t);

     

        for(i=0;i<=m;i++)

        d[0][i] = i;

        for(j=0;j<=n;j++)

        d[j][0] = j;

     

        for (j=1;j<=m;j++)

        {

            for(i=1;i<=n;i++)

            {

                if(s[i-1] == t[j-1])

                {

                    tracker = 0;

                }

                else

                {

                    tracker = 1;

                }

                temp = MIN((d[i-1][j]+1),(d[i][j-1]+1));

                d[i][j] = MIN(temp,(d[i-1][j-1]+tracker));

            }

        }

        printf("the Levinstein distance is %d\n",d[n][m]);
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
	int banyak;
	string arr[100];
	cin>> banyak;
	for (int i=0;i<banyak;i++)
	{
		cin>> arr[i];
	}
	quickSort(arr,0,banyak);
	//panggil fungsi distance
	for (int i=0;i<editdistance;i++)
	{
		for (int j=0;j<banyak;i++)
		{
			if (hound[j]==i)
			{
				cout<< arr[i]<<hound[i]<<freq[i]<<endl;
			}
		}
	} 
}
