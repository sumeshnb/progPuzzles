#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
  int numberOfTestCases = 0;
  int * numberOfCyclesPtr = NULL;
  int loopCount = 0;
  int innerLoopCount=0;
  scanf("%d",&numberOfTestCases);
  if(numberOfTestCases<1 || numberOfTestCases>10)
      printf("Number of test cases should be between 1-10 !\n");

  numberOfCyclesPtr =(int *)malloc(numberOfTestCases*sizeof(int));

  if(numberOfCyclesPtr == NULL){
      printf("Memory allocation failed..exiting application\n");
      exit(1);
  }

  for(loopCount=0;loopCount<numberOfTestCases;loopCount++){
      scanf("%d",&numberOfCyclesPtr[loopCount]); 
      if(numberOfCyclesPtr[loopCount]<0 || numberOfCyclesPtr[loopCount]>60){
          printf("Growth cycle should be between 0 and 60,including both\n");
      }    
  }
  /*calculate the height for each test case*/
  for(loopCount=0;loopCount<numberOfTestCases;loopCount++){   
      //numberOfCyclesPtr[loopCount]
      //int height = calculateHeight(1,numberOfCyclesPtr[loopCount]);
      int flag =0;
      int height=1;
      for(innerLoopCount=0;innerLoopCount<numberOfCyclesPtr[loopCount];
              innerLoopCount++){
          if(flag==0){
              height*=2;
              flag=1;
          }else{
              height+=1;
              flag=0;
          }
      }
      printf("%d\n",height);
  }
  return 0;
}
