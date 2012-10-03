// 1082_input.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#define N (11)

 #include <stdio.h>  
 long c;

//long A[N] = {3, 7, 19, 20, 21, 22, 23, 24, 25, 26};
//long A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
 long *A;
  
 long P(long l, long r)
 {
  long x=A[l],
       i=l-1,
       j=r+1,
       t;
  while(1)
  {
   do{--j; ++c;}
   while(A[j]>x);
   do{++i; ++c;}
   while(A[i]<x);
   if(i<j)
   {
    t=A[i];
    A[i]=A[j];
    A[j]=t;
   }
   else return j;
  }
 }
 
 void Q(long l, long r)
 {
  long n;
  if(l<r)
  {
   n=P(l,r);
   Q(l,n);
   Q(n+1,r);
  }
 }
 
 int main(void)
 {
	 for (int N = 1; N <= 2; N++) {
	c=0;
	A = new long[N];
  for(long i=0; i<N; ++i)
   A[i] = i + 1;
 
  Q(0,N-1);
  delete [] A;
  if(c==(N*N+3*N-4)/2)
   printf
   ("%d %d\n", N, c);
	 }
  return 0;
 }
