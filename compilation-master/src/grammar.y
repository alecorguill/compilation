%union{
  struct attr{
    int type;
    char s[40000];
    int reg;
  }attr;
 };

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym.h"
#include "hash_table.h"

  int yyerror (char*);  
  struct Hash_table sym_table;
  const char* types[] = {"void", "i32", "double"};

  char type_assignement[4];
  char type_name[6];
  int depth = 0;

  int tmps = 1;		     
  int labels = 0;       
  int results = 0;
  int loops = 0;

  char buf[1024];     

  char block_vars[100][1024]; 
  int nb_vars;	        


  void declare_function(char *s, char *dest){
    char tst[100];
    if (ht_exists(&sym_table,s))
      printf("exists\n");
    else{
      ht_add(&sym_table,s,s,S_FUNCTION);
    }

    printf("declare %s @%s()\n", s, tst);
  }

  void call_args_function(char *s1, char *s2, char *dest){
    char *str1 = s1;
    char *str2 = s2;
    if (ht_exists(&sym_table,s1))
      ht_add(&sym_table,s1,s1,S_FUNCTION);
    printf("call @%s(%s)\n", s1, s2);
  }

  int print_values(struct attr s1, struct attr s2, char type_op[3], char *dst){
    char *str1 = s1.s;
    char *str2 = s2.s;
    struct Sym *v1 = ht_get(&sym_table, str1);
    struct Sym *v2 = ht_get(&sym_table, str2);
    int t1, t2;
    
    if(s1.type == 0){
      t1 = sym_get_type(v1);
    }
    else
      t1 = s1.type;

    if(s2.type == 0){
      t2 = sym_get_type(v2);
    }
    else
      t2 = s2.type;
    
    sprintf(dst+strlen(dst), "%s", str2);

    if (t1==1){	        
      char type_operation[3];
      if (strcmp("div", type_op)==0)
	sprintf(type_operation, "sdiv");
      else
	sprintf(type_operation, "%s", type_op);
      sprintf(dst+strlen(dst), "r%d = %s i32 r%d, r%d\n", tmps, type_operation, tmps-2, tmps-1);
    }

    else{	        
      sprintf(dst+strlen(dst), "r%d = %s double r%d, r%d\n", tmps, type_op, tmps-2, tmps-1);
    }

    tmps+=1;
    return t1;
  }

 int print_value(struct attr s1, char *dst){
    memset(dst,0,sizeof(dst));
    struct Sym *v = NULL;
    if(s1.type == 0){
      v = ht_get(&sym_table, s1.s);
      if (sym_is_declared(v)){
      	s1.type = sym_get_type(v);
      }


      if (sym_is_special(v) && !sym_get_llvm_name(v)){
	/*sprintf(dst+strlen(dst),*/printf("r%d = load %s* @%s\n", tmps, types[s1.type], sym_get_llvm_name(v));
	printf("%s\n",dst);
      }
      else if (!sym_is_special(v) && !sym_get_name(v)){
        printf("r%d = load %s* @%s\n", tmps, types[s1.type], sym_get_name(v));
	printf("%s\n",dst);
      }
      tmps++;
      return s1.type; 
    }
    
    else if (s1.type != 0) {
      sprintf(dst, "\n%s", buf);
      if (s1.type==1)   
	sprintf(dst+strlen(dst), "r%d = add i32 0, %s\n", tmps, s1.s);
      else	        
	sprintf(dst+strlen(dst), "r%d = add double 0.0, %s\n", tmps, s1.s);
      tmps++;
      return s1.type;
    }
    return -1;
  }

  int compare(struct attr s1, struct attr s2, char *dest, char int_comparison[3], char double_comparison[3]){
    char *str1 = s1.s;
    char *str2 = s2.s;
    char c='i';
    char c2[3];
    sprintf(c2, "%s", int_comparison);
    
    if(s1.type == 2){
      c='f';
      sprintf(c2, "%s", double_comparison);
    }
    
    sprintf(dest, "%s%s", str1, str2);
    sprintf(dest+strlen(dest), "r%d = %ccmp %s %s r%d, r%d\n\n", tmps, c, c2, types[s1.type], tmps-2, tmps-1);
    ;
    tmps++;
    return s1.type;
}

  extern int yylineno;
  int yylex ();

  void print_struct_definition();
%}

%token <attr> IDENTIFIER CONSTANTF CONSTANTI
%token <attr> INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token <attr> SUB_ASSIGN MUL_ASSIGN ADD_ASSIGN
%token <attr> TYPE_NAME
%token <attr> INT DOUBLE VOID
%token <attr> IF ELSE WHILE RETURN FOR
%start program

%type <attr> primary_expression comparison_expression additive_expression multiplicative_expression unary_expression argument_expression_list postfix_expression expression

%type <attr> assignment_operator declaration type_name declarator parameter_declaration program external_declaration function_definition

%type <attr> declarator_list parameter_list declaration_list statement_list

%type <attr> statement compound_statement expression_statement selection_statement iteration_statement jump_statement

%%


primary_expression
: IDENTIFIER         {buf[0]='\0';}
| CONSTANTI          {buf[0]='\0';}
| CONSTANTF          {buf[0]='\0';}
| '(' expression ')' {$$=$2;}
| IDENTIFIER '(' ')' {declare_function($1.s, $$.s);}
| IDENTIFIER '(' argument_expression_list ')' {call_args_function($1.s, $3.s, $$.s);}
| IDENTIFIER INC_OP 
| IDENTIFIER DEC_OP 
;

postfix_expression
: primary_expression
| postfix_expression '[' expression ']' {yyerror("Table error");}
;

argument_expression_list
: expression
| argument_expression_list ',' expression {$$.type=$3.type;sprintf($$.s, "%s", $1.s); sprintf($$.s+strlen($$.s), "%s", $3.s);}
;

unary_expression
: postfix_expression 
| INC_OP unary_expression
| DEC_OP unary_expression
| unary_operator unary_expression
;

unary_operator
: '-'
;

multiplicative_expression
: unary_expression {$$.type=print_value($1, $$.s);$$.reg=tmps-1;}
| multiplicative_expression '*' unary_expression {$$.type=print_value($3, $3.s);printf("r%d = mul nsw %s r%d, r%d\n",tmps-1,types[$1.type],$1.reg,$3.reg);}//$$.type=print_values($1, $3, "mul", $$.s);}
| multiplicative_expression '/' unary_expression {$$.type=print_value($3, $3.s); struct attr v; sprintf(v.s, "%s", $3.s); v.type = $$.type; $$.type=print_values($1, v, "div", $$.s);}
;

additive_expression
: multiplicative_expression
| additive_expression '+' multiplicative_expression {printf("r%d = add nsw %s r%d, r%d\n", tmps,types[$1.type],$1.reg,$3.reg);tmps++;}
| additive_expression '-' multiplicative_expression {$$.type=print_values($1, $3, "sub", $$.s);}
;

comparison_expression
: additive_expression
| additive_expression '>' additive_expression   {$$.type=compare($1, $3, $$.s, "ugt", "ogt");}
| additive_expression '<' additive_expression   {$$.type=compare($1, $3, $$.s, "ult", "olt");}
| additive_expression LE_OP additive_expression {$$.type=compare($1, $3, $$.s, "ule", "ole");}
| additive_expression GE_OP additive_expression {$$.type=compare($1, $3, $$.s, "uge", "oge");}
| additive_expression NE_OP additive_expression {$$.type=compare($1, $3, $$.s, "ne",  "one");}
| additive_expression EQ_OP additive_expression {$$.type=compare($1, $3, $$.s, "eq",  "oeq");}
;

expression
: unary_expression assignment_operator comparison_expression {
  char *str1 = $1.s;
  char *str3 = $3.s;
  int t1, t2;
  t2 = $3.type;
  memset($$.s,0,sizeof($$.s));

  struct Sym *v = ht_get(&sym_table, str1);
  t1 = sym_get_type(v);
  
  if (sym_is_declared(v)){
    t1 = sym_get_type(v);
  }
  if (t1!=t2)
    printf("%s", str3);

  if(strlen(type_assignement)>0){
    char assign=' ';
    char a_type[6] = "i32";
    if (t2 == 2){
      assign='d';
      sprintf(a_type, "double");
    }

    if(sym_is_special(v)){
      sprintf($$.s+strlen($$.s),"r%d = load %s* @%s\n", tmps, types[t2], sym_get_llvm_name(v));
    }
    else{
      sprintf($$.s+strlen($$.s),"r%d = load %s* @%s\n", tmps, types[t2], sym_get_llvm_name(v));
    }
    sprintf($$.s+strlen($$.s), "r%d = %c%s %s r%d, r%d\n", tmps+1, assign, type_assignement, a_type, tmps-1, tmps);
  }
  if (t1==1){
    if (sym_is_special(v)){
      printf("store i32 r%d, i32* @%s\n", tmps-1, sym_get_llvm_name(v));
      sym_set_modified(v, S_MODIFIED);
    }
    else{
      printf("%sstore i32 r%d, i32* @%s\n",$3.s, tmps-1, sym_get_llvm_name(v));
    }
  }
  else{	        
    if (sym_is_special(v)){
      sym_set_modified(v, S_MODIFIED);
      printf("store double r%d, double* @%s\n", tmps-1, sym_get_llvm_name(v));
    }
    else
      printf("store double r%d, double* @%s\n", tmps-1, sym_get_llvm_name(v));
  }

  if(strlen(type_assignement)>0){
    tmps+=2;
  }
}
| comparison_expression   
;

assignment_operator
: '='        {type_assignement[0]='\0';}
| MUL_ASSIGN {sprintf(type_assignement, "mul");}
| ADD_ASSIGN {sprintf(type_assignement, "add");}
| SUB_ASSIGN {sprintf(type_assignement, "sub");}
;

declaration
: type_name declarator_list ';' {$$=$2;}
;

declarator_list
: declarator {sprintf(block_vars[nb_vars], "%s", $1.s); nb_vars++;
  int t = (strcmp(type_name, "i32") == 0)?S_INT:S_DOUBLE;
  char *str1 = $1.s;
  if(ht_exists(&sym_table, str1)){
    yyerror("Variable deja declare\n");
  }
  ht_add(&sym_table, $1.s, str1, t);
  if (depth == 0)
    printf("@%s = common global %s 0\n", str1, type_name);
  else
    printf("%%%s = alloca %s\n",str1,type_name);
 }
| declarator_list ',' declarator {
  sprintf(block_vars[nb_vars], "%s", $3.s); nb_vars++;
  int t = (strcmp(type_name, "i32") == 0)?S_INT:S_DOUBLE;
  if(ht_exists(&sym_table, $3.s)){
    yyerror("Variable deja declare\n");
  }
  ht_add(&sym_table, $3.s, $3.s, t);
  if (depth == 0)
    printf("@%s = common global %s 0\n", $3.s, type_name);
  else
    printf("%%%s = alloca %s\n",$3.s,type_name);
  }
;

type_name
: VOID  {sprintf(type_name, "void");}
| INT   {sprintf(type_name, "i32");}
| DOUBLE {sprintf(type_name, "double");}
;

declarator
: IDENTIFIER 		       
| '(' declarator ')'
| declarator '[' CONSTANTI ']'       {yyerror("Table error");}
| declarator '[' ']'                 {yyerror("Table error");}
| declarator '(' parameter_list ')'  
| declarator '(' ')'                 {printf("define %s @%s() {\n",types[$$.type],$1.s);}
;

parameter_list
: parameter_declaration 
| parameter_list ',' parameter_declaration
;

parameter_declaration
: type_name declarator
;

statement
: compound_statement   {$$.type=$1.type; strcpy($$.s,$1.s);} 
| expression_statement {$$.type=$1.type; strcpy($$.s,$1.s);}
| selection_statement  {$$.type=$1.type; strcpy($$.s,$1.s);}
| iteration_statement  {$$.type=$1.type; strcpy($$.s,$1.s);}
| jump_statement       {$$.type=$1.type; strcpy($$.s,$1.s);}
;

LB : '{'
{
  depth++;
}
;

RB : '}'
{
  depth--;
}
;

compound_statement
: LB RB
| LB statement_list RB {$$.type=$2.type; strcpy($$.s, $2.s);}
| LB declaration_list statement_list RB {int i; char rm[256];
    for(i=0; i<nb_vars; i++){
      sprintf(rm, "%s", block_vars[i]);
      ht_remove(&sym_table, rm);
    }; nb_vars=0; strcpy($$.s,$3.s);}
;

declaration_list
: declaration
| declaration_list declaration {nb_vars=0;}
;

statement_list
: statement                 {$$.type=$1.type; strcpy($$.s,$1.s);}
| statement_list statement  {sprintf($$.s+strlen($$.s), "%s", $2.s);}
;

expression_statement
: ';'
| expression ';' {strcpy($$.s,$1.s);}
;

selection_statement
: IF '(' expression ')' statement {
  char *str3 = $3.s;
  char *str5 = $5.s;
  sprintf($$.s, "%s", str3);
  sprintf($$.s+strlen($$.s), "br i1 r%d, label %d, label %d\n\n", tmps+1, labels, labels+1);
  sprintf($$.s+strlen($$.s), "; <label>%d:\n", labels);
  labels++;
  sprintf($$.s+strlen($$.s), "%s\n", str5);
  sprintf($$.s+strlen($$.s), "br label %d\n \n; <label>%d:\n", labels, labels);
  labels++;
  tmps++;
 }
| IF '(' expression ')' statement ELSE statement {
  sprintf($$.s, "%s", $3.s);
  sprintf($$.s+strlen($$.s), "br i1 r%d, label %d, label %d\n\n", tmps+1, labels, labels+1);
  sprintf($$.s+strlen($$.s), "; <label>%d:\n", labels);
  labels++;
  sprintf($$.s+strlen($$.s), "%s\n", $5.s);
  sprintf($$.s+strlen($$.s), "br label %d\n", labels+2);
  sprintf($$.s+strlen($$.s), "; <label>%d:\n", labels);
  labels++;
  sprintf($$.s+strlen($$.s), "%s\n", $7.s);
  sprintf($$.s+strlen($$.s), "br label %d\n \n; <label>%d:\n\n", labels+1, labels+1);
  labels++;
  tmps++;
  }
| FOR '(' expression_statement expression_statement expression ')' statement {
  sprintf($$.s,"%s", $3.s);
  sprintf($$.s+strlen($$.s), "br label %d\n \n; <label>%d:\n", loops, loops);
  loops++;
  sprintf($$.s+strlen($$.s), "%s", $4.s);
  sprintf($$.s+strlen($$.s), "br i1 r%d, label %d, label %d\n\n", tmps+1, loops, loops+1);
  sprintf($$.s+strlen($$.s), "; <label>%d:\n", loops);
  sprintf($$.s+strlen($$.s), "%s", $5.s);
  sprintf($$.s+strlen($$.s), "%s", $7.s);
  sprintf($$.s+strlen($$.s), "br label %d\n", loops-1);
  sprintf($$.s+strlen($$.s), "; <label>%d:\n;;", loops+1);
 loops++;
 tmps++;
  }
;

iteration_statement
: WHILE '(' expression ')' statement
{
  sprintf($$.s, "br label %d\n \n; <label>%d:\n", labels, labels);
  labels++;
  sprintf($$.s+strlen($$.s), "%s", $3.s);
  sprintf($$.s+strlen($$.s), "br i1 r%d, label %d, label %d\n", tmps-1, loops, loops+1);
  sprintf($$.s+strlen($$.s), "\n; <label>%d:\n", loops);
  sprintf($$.s+strlen($$.s), "%s", $5.s);
  sprintf($$.s+strlen($$.s), "br label %d\n \n; <label>%d:\n;;", labels-1, loops+1);
  loops+=2;
  labels++;
}
;

jump_statement
: RETURN ';'           {printf("ret");}
| RETURN expression ';' {printf("ret %s",$2.s);memset($$.s,0,sizeof($$.s));}
;

program
: external_declaration
| program external_declaration
;

external_declaration 
: function_definition   
| declaration
;

function_definition
: type_name declarator compound_statement  {$2.type=type_name;printf("%s\n", $3.s);printf("}\n");}
;

%%
#include <stdio.h>
#include <string.h>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    exit(1);
}


int main (int argc, char *argv[]) {
    FILE *input = NULL;

    if(argc != 2){
      fprintf (stderr, "%s: error: no input file\n", *argv);
      return 1;
    }
    
    input = fopen (argv[1], "r");

    if (!input){
      fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
      return 1;
    }

    printf("; ModuleID = '%s'\ntarget datalayout = \"e-p:32:32-i64:64-v128:32:128-n32-S128\"\ntarget triple = \"asmjs-unknown-emscripten\"\n\n",argv[1]);

    ht_init(&sym_table);
    
    yyin = input;
 
    yyparse ();


    fclose(input);
    return 0;
}
