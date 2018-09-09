#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reservedWords.h"

struct resWord *resWordHead = NULL;
struct resWord *resWordCurrent = NULL;

void insertResWord(char *lexResWord, int tokenResWord, int attributeResWord) {
   struct resWord *link = (struct resWord*) malloc(sizeof(struct resWord));
   link->lexResWord = lexResWord;
   link->tokenResWord = tokenResWord;
   link->attributeResWord = attributeResWord;
   link->nextResWord = resWordHead;
   resWordHead = link;
}

void printResWordList() {
  struct resWord *ptr = resWordHead;
  while(ptr != NULL){
    printf("%s\t%d\t%d\n", ptr->lexResWord,ptr->tokenResWord,ptr->attributeResWord);
    ptr = ptr -> nextResWord;
  }
}

struct resWord getTokAndAtt(char *lexeme){
  struct resWord *ptr = resWordHead;
  while(ptr != NULL){
    if(ptr->lexResWord == lexeme){
      return *ptr;
    }
    ptr = ptr -> nextResWord;
  }
  return *ptr;
}

void loadReservedWords(){
  FILE *resWordFile;
  char *eof;
  int tok;
  int att;
  resWordFile = fopen("./reservedWords.dat", "r");
  char lex[32];
  //This could be made much more efficient. Ask Bray about it perphaps
  while(fscanf(resWordFile,"%s\t%d\t%d\n", lex, &tok, &att)!=EOF){
    char *lexeme = (char*)malloc(strlen(lex));
    const char* from = lex;
    strncpy(lexeme, from, strlen(lex)+1);
    insertResWord(lexeme, tok, att);
  }
}
