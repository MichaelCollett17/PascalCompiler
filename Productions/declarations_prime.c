#include <stdio.h>
#include <stdbool.h>
#include "../tokens.h"
#include "../LinkedLists/TokenLLV2.h"
#include "./productions.h"
#include "../reservedWords.h"
#include "../Parser.h"

void declarations_prime(){
  struct resWord var = getTokAndAtt("var");
  struct resWord procedure = getTokAndAtt("procedure");
  struct resWord begin = getTokAndAtt("begin");
  if(tok.tokenType ==var.tokenResWord){
    match(var.tokenResWord, var.attributeResWord, "var");
    match(ID, 0, "ID");
    match(TYPE, 0, ":");
    type();
    match(PUNCTUATION,SEMICOLON, ";");
    declarations_prime();
  }
  else if(((tok.tokenType == begin.tokenResWord)
    &&(tok.attribute == begin.attributeResWord)) || (tok.tokenType == procedure.tokenResWord)){
      return;
  }
  else{
    writeSyntaxError("var begin or procedure", tok.lexeme);
    while(tok.tokenType != EOFTOKEN && (!((tok.tokenType == begin.tokenResWord)
      &&(tok.attribute == begin.attributeResWord))) && (!(tok.tokenType == procedure.tokenResWord))){
      getToken();
    }
  }
}
