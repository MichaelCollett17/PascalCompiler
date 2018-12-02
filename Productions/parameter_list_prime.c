#include <stdio.h>
#include <stdbool.h>
#include "../tokens.h"
#include "../LinkedLists/TokenLLV2.h"
#include "./productions.h"
#include "../reservedWords.h"
#include "../Parser.h"

void parameter_list_prime(){
  if((tok.tokenType == PUNCTUATION) && (tok.attribute == SEMICOLON)){
    match(PUNCTUATION,SEMICOLON, ";");
    match(ID, 0, "ID");
    match(TYPE, 0, ":");
    type();
    parameter_list_prime();
  }
  else if(tok.tokenType == GROUPING && tok.attribute == RPAR){
    return;
  }
  else{
    writeSyntaxError("ID",tok.lexeme);
    while((tok.tokenType != EOFTOKEN) &&
    !((tok.tokenType == GROUPING) && (tok.attribute == RPAR))){
      getToken();
    }
  }
}