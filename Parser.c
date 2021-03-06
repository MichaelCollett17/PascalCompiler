#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "tokens.h"
#include "./Machines/machines.h"
//#include "./LinkedLists/TokenLinkedList.h"
#include "./LinkedLists/TokenLLV2.h"
#include "reservedWords.h"
#include "LexicalAnalyzer.h"
#include "./Productions/productions.h"

FILE *listFile;
char *eof;
FILE *rfp;
FILE *tokFile;
FILE *memoryFile;
char buff[72];
int lineNum;


void writeSyntaxError(char *expecting, char *received){
  fprintf(listFile, "-SYNTAX ERROR-\n\tExpecting one of: %s\n\tReceived: %s\n",
    expecting, received);
  printf("-SYNTAX ERROR-\n\tExpecting: %s\n\tReceived: %s\n",
    expecting, received);
}

void writeSemanticError(char *error){
  fprintf(listFile, "-SEMANTIC ERROR-\n\t: %s\n", error);
  printf("-SEMANTIC ERROR-\n\t: %s\n", error);
}

void getToken(){
  struct tokenNode check = getNextToken();
  if(check.lineNo != -10){
    tok = check;
  }
  else{
    if(eof!=NULL){
      eof = loadBuffer(buff,rfp);
      if(eof!=NULL){
        lineNum++;
        printBuffer(buff,listFile,lineNum);
        machines(buff, listFile, lineNum);
        getToken();//calls self because the previous call needed getToken still!
      }
      else{
        printf("PARSE OVER\n");
        insertToken(EOF, "EOF", EOFTOKEN, 0);
        tok = getNextToken();
      }
    }
    // else{
    //   printf("PARSE OVER 2\n");
    //   //insertToken(EOF, "EOF", EOFTOKEN, 0);
    // }
  }
}

int printAddress(char *var,int off){
  printf("%s\t\t\t%d\n", var,off);
  return fprintf(memoryFile, "%s\t\t\t%d\n", var,off);
}

void parse(){
  getToken();
  program();
  match(EOFTOKEN, 0, "EOF");//match($)
  return;
}

int main()
{
  rfp = fopen("./InputFiles/shenoi_my_test.pas", "r");
  listFile = fopen("./OutputFiles/fibTestlist.txt", "w+");
  tokFile = fopen("./OutputFiles/fibTesttok.txt", "w+");
  memoryFile = fopen("./OutputFiles/memoryAddrs.txt", "w+");
  fprintf(memoryFile, "Variable\t\t\tOffset\n");

  loadReservedWords();

  eof = loadBuffer(buff,rfp);
  lineNum = 1;
  int blank = 1;
  while(blank == 1){
    if(buff[0]=='\n'){
      printBuffer(buff,listFile,lineNum);
      lineNum++;
      eof = loadBuffer(buff,rfp);
    }
    else{
      blank = 0;
    }
  }
  if(eof!=NULL){
    printBuffer(buff,listFile,lineNum);
    machines(buff, listFile, lineNum);
    parse();
    //eof = loadBuffer(buff,rfp);
    //lineNum++;
    //break;
  }
  printList(tokFile);
  fclose(rfp);
  return 0;
}
