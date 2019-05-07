#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>

void swap(int *,int *);
void bubble_sort(int [],int);
void quick_sort(int [],int,int,int);
void draw(int [],int);

void main()
{
 int gd=DETECT,gm,arr[10000],n=200,i;

 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 printf("\nBUBBLE SORT");
 draw(arr,n);
 bubble_sort(arr,n);
 clearviewport();
 printf("\nQUICK SORT");
 draw(arr,n);
 quick_sort(arr,0,n-1,n);

 getch();
}
void draw(int arr[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  arr[i]=rand()%149;
 }
 for(i=0;i<n;i++)
 {
  line(i,getmaxy(),i,getmaxy()-arr[i]);
 }
 delay(3000);
}
void bubble_sort(int arr[],int n)
{
 int i,c,d;

 for(c=0;c<n-1;c++)
 {
  for(d=0;d<n-c-1;d++)
  {
   if(arr[d]>arr[d+1])
   {
    swap(&arr[d],&arr[d+1]);
   }
  }


  for(i=0;i<n;i++)
  {
   clearviewport();
   line(i,getmaxy(),i,getmaxy()-arr[i]);

  }

 }
 clearviewport();
 for(i=0;i<n;i++)
  {
   line(i,getmaxy(),i,getmaxy()-arr[i]);
  }
 delay(2000);
 clrscr();
}
void swap(int *a,int *b)
{
 int temp= *a;
 *a=*b;
 *b=temp;
}

void quick_sort(int arr[],int first,int last,int n)
{
 int c,d,pivot,i;
 if(first<last)
 {
  pivot=first;
  c=first;
  d=last;

  while(c<d)
  {

   while(arr[c]<=arr[pivot]&&c<last)
    c++;

   while(arr[d]>arr[pivot])
    d--;

   if(c<d)
    swap(&arr[c],&arr[d]);

  }
  swap(&arr[pivot],&arr[d]);
  quick_sort(arr,first,d-1,n);
  quick_sort(arr,d+1,last,n);

  for(i=0;i<n;i++)
  {
   clearviewport();
   line(i,getmaxy(),i,getmaxy()-arr[i]);

  }
 }
 clearviewport();
 for(i=0;i<n;i++)
  {
   line(i,getmaxy(),i,getmaxy()-arr[i]);
  }
  delay(2000);
  printf("\nAfter quick sort:");
  for(i=0;i<n;i++)
  {
   line(i,getmaxy(),i,getmaxy()-arr[i]);
  }
}

