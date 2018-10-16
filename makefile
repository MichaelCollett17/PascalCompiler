makelexical: Parser.c LexicalAnalyzer.c ./Machines/idres.c ./Machines/whitespace.c ./LinkedLists/TokenLinkedList.c reservedWords.c ./LinkedLists/SymbolTable.c ./Machines/Catchall.c ./Machines/Relop.c ./Machines/Number.c ./Productions/program.c ./Productions/match.c ./Productions/idlst.c
	gcc -o Lex Parser.c LexicalAnalyzer.c ./Machines/idres.c ./Machines/whitespace.c ./LinkedLists/TokenLinkedList.c reservedWords.c ./LinkedLists/SymbolTable.c ./Machines/Catchall.c ./Machines/Relop.c ./Machines/Number.c ./Productions/program.c ./Productions/match.c ./Productions/idlst.c
