#ifndef GNBNNODE
#define GNBNNODE

struct gbnode{
    struct gbnode *upleft;
    struct gbnode *right;
    struct gbnode *down;
    struct gbnode *nextGreen;
    int type2;
    char *lex;
    int type;
    int offset_;
    int borg;// 0 for blue 1 for green
    int array_size;//for aints or areals
};

void printStatus();
void printUpLeftChain();
void checkAddGreenNode(char *lex_in, int type);
void checkAddBlueNode(char *lex_in, int type, int offset_param, int print);
void checkAddBlueNodeParam(char *lex_in, int type, int paramtype);
void procedureCall(char* id_lex);
void checkNoParams();
void checkParam(int type);
int getType(char* id_lex);
void popStack();
void checkNoMoreParams();
int getOffset();


#endif
