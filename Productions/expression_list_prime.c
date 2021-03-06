#include <stdio.h>
#include <stdbool.h>
#include "../tokens.h"
#include "../LinkedLists/TokenLLV2.h"
#include "./productions.h"
#include "../reservedWords.h"
#include "../Parser.h"
#include "../GNBNTree/GNBNNode.h"

void expression_list_prime(){
  if(tok.tokenType == PUNCTUATION && tok.attribute == COMMA){
    match(PUNCTUATION, COMMA, ",");
    int type_ = expression();
    checkParam(type_);
    expression_list_prime();
  }
  else if(tok.tokenType==GROUPING && tok.attribute == RPAR){
    checkNoMoreParams();
    return;
  }
  else{
    writeSyntaxError(", )", tok.lexeme);
    while((tok.tokenType != EOFTOKEN) &&
    !((tok.tokenType == GROUPING) && (tok.attribute == RPAR))){
      getToken();
    }
  }
}
