#include <iostream.h>
#include <conio.h>

void quick_sort(int darr[max], int lb, int ub)
{
  int a;
   int up,down;
   int temp;

   if (lb>=ub)
   return;
   a=darr[lb];
   up=ub;
   down=lb;

   while (down < up)
   {
     while (darr[down] <= a)
       down++;
      while (darr[up]>a)
       up--;
      if(down<up)
      {
       temp=darr[down];
         darr[down]=darr[up];
         darr[up]=temp;
      }
   }
   darr[lb]=darr[up];
   darr[up]=a;

   quick_sort(darr,lb,up-1);
   quick_sort(darr,up+1,ub);
}

void main()
{
  int arr[max];
   int i,n,lb,ub;
   lb=0;

   cout<<"Masukkan banyak data yang ingin diurut: ";
   cin>>n;

   cout<<"Masukkan data-datanya: \n\n";
   for(i=0;i<n;i++)
   {
     cin>>arr[i];
   }

   quick_sort(arr,lb,n);
   cout<<"\nHasil pengurutan data: ";
   for(i=1; i<=n;i++)
    cout<<" "<<arr[i];

}

//reference http://sandblog-sandyblogger.blogspot.co.id/2011/04/quick-sort-c.html