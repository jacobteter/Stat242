#include <stdio.h>
#include "Move.h"

#define BLUE 1 // ones move up
#define RED 2 // twos move right

int fullRow(int *map, int, int, int);
int fullCol(int *map, int, int, int);
void moveRow(int *map, int, int, int);
void moveCol(int *map, int, int, int);
void printMap(int * map);
  
int fullRow(int * map, int r, int row, int col){ /*returns 1 if all cells on row r have cars*/
  int c;
  for(c=0; c<col; c++)
    if(*((map+r*col+c)) == 0)
      return 0;             /* in C, 0 and only zero, is interpreted as false */
    return 1;                 /* true */
}

int fullCol(int * map, int c, int row, int col){ /*returns 1 if all cells on col c have cars*/
  int r;
  for(r=0; r<row; r++)
    if(*((map+r*col+c)) == 0)
      return 0;
  return 1;
}

void 
moveRow(int * map, int r, int row, int col){ /*moves all unblocked red cars on row r*/
  int cc,c=0; // c is the offset from the beginning of the row...
  if(fullRow(map, r, row, col))  /*no blanks*/
    return;
  while(c<col){
    while(c<col && (*(map+col*r+c)==0 || *(map+col*r+c)==BLUE)) // the star in front dereferrences the location its looking at. 
      c++;                            /* pass over blanks and blue cars*/
      if(c==col)
	return;                         /*no more red cars*/
        /*map[r][c] is a red car*/
      cc=c;                    /*find next non-red cell*/ // c has been marked as the first red car encountered
      while(*(map+col*r+cc)==RED)
	cc=(cc+1)%col; // at the end of this loop, cc is the cell ahead of (with wrap around) the front of a limo of red cars
    if(*(map+col*r+cc)==0){ /*cars from c to cc can move*/
      *(map+col*r+c)=0;
      *(map+col*r+cc)=RED;
    }
    /* else cars from c to cc are blocked*/
    c=cc;
    if(c==0)         /*done*/
      return;
    c++;
  }                                                
}  

void 
moveCol(int * map, int c, int row, int col){
  int rr,r=0;
  if(fullCol(map, c, row, col))  /*no blanks*/
    return;
  while(r<row){
    while(r<row && (*(map+col*r+c)==0 || *(map+col*r+c)==RED))
      r++;                            /* pass over blanks and red cars*/
      if(r==row)
        return;                         /*no more blue cars*/
      /*map[r][c] is a blue car*/
      rr=r;                    /*find next non-blue cell*/
      while(*(map+col*rr+c)==BLUE)
        rr=(rr+1)%row;
    if(*(map+col*rr+c)==0){ /*cars from r to rr can move*/
                              *(map+col*r+c)=0;
                            *(map+col*rr+c)=BLUE;
    }
    /* else cars from r to rr are blocked*/
      r=rr;
    if(r==0)         /*done*/
      return;
    r++;
  }
}  

