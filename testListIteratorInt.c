/*
  client to test listIteratorInt.
  Written by ....
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "listIteratorInt.h"

char *myitoa(int *i){
	char *str;
	if (i == NULL){
		return "NULL";
	}
	if((str = malloc(20 * sizeof(char))) == NULL){
		return "ERROR";
	}

	sprintf(str, "%d", *i);
	return str;
}


int main(int argc, char *argv[]) {
  
	  /* The following code, inside the comments, may or may not be correct!
	     
	     It's provided in case you find it difficult to understand 
	     how to create a list iterator, and use it's functions.
	     
	     The code below only tests basic operations, however 
	     make sure that you do test all the required functions properly in
	     your test file. 

	  */
	  
	  

	  int val, result;

	  IteratorInt it1 = IteratorIntNew();

	  
	  val = 25;
	  result = add(it1 , val); 
	  printf("Inserting %d: %s \n", val, (result==1 ? "Success" : "Failed") );
	  // should print "Inserting 25: Success"

	  val = 12;
	  result = add(it1 , val); 
	  printf("Inserting %d: %s \n", val, (result==1 ? "Success" : "Failed") );
	  // should print "Inserting 12: Success"

	  val = 6;
	  result = add(it1 , val); 
	  printf("Inserting %d: %s \n", val, (result==1 ? "Success" : "Failed") );
	  // should print "Inserting 6: Success"

	  val = 82;
	  result = add(it1 , val); 
	  printf("Inserting %d: %s \n", val, (result==1 ? "Success" : "Failed") );
	  // should print "Inserting 82: Success"

	  val = 11;
	  result = add(it1 , val); 
	  printf("Inserting %d: %s \n", val, (result==1 ? "Success" : "Failed") );
	  // should print "Inserting 11: Success"

	  printf("next %s\n", myitoa(next(it1)));

	  int *vp1 = previous(it1);
	  printf("Previous value is: %d \n", *vp1 );  
	  // should print "Previous value is: 11" 
	  
	  int *vp2 = previous(it1);
	  printf("Previous value is: %d \n", *vp2 );  
	  // should print "Previous value is: 82" 


	  int *vp16 = next(it1);
	  printf("Next value is: %d\n", *vp16);

	  printf("next %s\n", myitoa(next(it1)));
	

		

	  int *vp5 = previous(it1);
	  printf("Previous value is: %d \n", *vp5 );  
	  // should print "Previous value is: 6" 
	  
	  int *vp3 = next(it1);
	  printf("Next value is: %d \n", *vp3 );     
	  // should print "Next value is: 6" 
	  
	  int *vp7 = previous(it1);
	  printf("Previous value is: %d \n", *vp7 );  
	  // should print "Previous value is: 6" 
	  
	  int *vp4 = next(it1);
	  printf("Next value is: %d \n", *vp4 );     
	  // should print "Next value is: 6" 
	
	  printf("next %s\n", myitoa(next(it1)));
	  printf("next %s\n", myitoa(next(it1)));


	 int *vp9 = findPrevious(it1, 6);
	 printf("findPrevious 6 is %d\n", *vp9);
	 //12

	 int *vp10 = findNext(it1, 82);
	 printf("findNext 82 is %d\n", *vp10);
	 //11

	 result = set(it1, 666);
	 printf("11 changed to 666\n");

	 reset(it1);
	
	 int *vp11 = findNext(it1, 82);
	 printf("findNext 82 is %d\n", *vp11);
	 //666

	 int *vp12 = previous(it1);
	 printf("Previous value is %d\n", *vp12);
	 //666
	 
	 
	 result = set(it1, 665);
	 printf("%d 666 changed to 665\n", result);

	 result = set(it1, 665);
	 printf("%d 665 changed to 669\n", result);


	 int *vp13 = next(it1);
	 printf("Next value is: %d\n", *vp13);
	 //665

	 reset(it1);

	 int *vp14 = findNext(it1, 12);
	 printf("findNext 12 is %d\n", *vp14);
	 //6

	 result = deleteElm(it1);
	 printf("6 is deleted\n");

	 reset(it1);

	 int *vp15 = findNext(it1, 12);
	 printf("findNext 12 is: %d\n", *vp15);
	 //82

	 reset(it1);

	  printf("previous %s\n", myitoa(previous(it1)));


	 reset(it1);

	 int *vp20 = next(it1);
	 printf("Next value is %d\n", *vp20);

//	 int *vp21 = findNext(it1, 6);
//	 printf("findNext 6 is %d\n", *vp21);

	 result = deleteElm(it1);
	 printf("%d is deleted\n", result);

	 result = set(it1, 619);
	 printf("%d di set ke 619\n", result);


	 result = deleteElm(it1);
	 printf("%d double delete\n", result);

	 reset(it1);

	 printf("findNext 999 %s\n", myitoa(findNext(it1, 999)));
	  printf("findPrevious %s\n", myitoa(findPrevious(it1, 999)));

	 int *vp21 = findNext(it1, 82);
	 printf("findNext 82 is: %d\n", *vp21);

	 result = deleteElm(it1);
	 printf("%d is deleted\n", result);

	 result = deleteElm(it1);
	 printf("%d is deleted\n", result);

	 reset(it1);

	 int *vp22 = next(it1);
	 printf("Next value is: %d\n", *vp22);

	 reset(it1);

	 printf("next %s\n", myitoa(next(it1)));
	 printf("findNext 999 %s\n", myitoa(findNext(it1, 12)));

	free(it1);

  return EXIT_SUCCESS;

}
