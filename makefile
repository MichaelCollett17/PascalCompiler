makelexical: Parser.c LexicalAnalyzer.c ./Machines/idres.c ./Machines/whitespace.c ./LinkedLists/TokenLLV2.c reservedWords.c ./LinkedLists/SymbolTable.c ./Machines/Catchall.c ./Machines/Relop.c ./Machines/Number.c ./Productions/program.c ./Productions/match.c ./Productions/idlst.c ./Productions/idlst_prime.c ./Productions/program_prime.c
	gcc -o Lex Parser.c LexicalAnalyzer.c ./Machines/idres.c ./Machines/whitespace.c ./LinkedLists/TokenLLV2.c reservedWords.c ./LinkedLists/SymbolTable.c ./Machines/Catchall.c ./Machines/Relop.c ./Machines/Number.c ./Productions/program.c ./Productions/match.c ./Productions/idlst.c ./Productions/idlst_prime.c ./Productions/program_prime.c
