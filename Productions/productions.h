#ifndef PRODUCTIONS
#define PRODUCTIONS
struct tokenNode tok;
void program();
void idlst();
char* match(int tokenToMatch, int attributeToMatch, char *lexeme);
void idlst_prime();
void program_prime();
void program_prime_prime();
void subdeclarations();
void subdeclarations_prime();
void declarations();
void declarations_prime();
struct tw type();
int matchNum();
struct tw standard_type();
void compound_statement();
void compound_statement_prime();
void subdeclaration();
void subdeclaration_prime();
void subdeclaration_prime_prime();
void subdeclaration_prime_prime();
void subprogram_head();
void subprogram_head_prime();
void arguments();
void parameter_list();
void parameter_list_prime();
void optional_statements();
void statement_list();
void statement_list_prime();
void statement();
void statement_prime();
void variable();
void variable_prime();
void procedure_statement();
void procedure_statement_prime();
void expression_list();
void expression_list_prime();
void expression();
void expression_prime();
void simple_expression();
void simple_expression_prime();
void term();
void term_prime();
int factor();
int factor_prime();
void sign();
#endif
