%union{
  struct val{
    int type;
    char s[40000];
    int reg;
  }val;
 };

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include "variable.h"
#include "hash_table.h"

  int yyerror (char*);  
  struct Hash_table hash_table_new;
  const char* types[] = {"void", "i32", "double"};

  char type_assignement[4];
  char type_name[6];

  int tmps = 1;		        /* pour les variables temporaires */
  int labels = 0; 		/* pour les boucles if */
  int results = 0;		/* pour les tests avec un resultat binaire */
  int loops = 0;		/* pour les boucles for */

  char buf[1024];		/* pour appeler une fonction */

  char block_vars[100][1024]; 	/* variables utilisées dans un block */
  int nb_vars;			/* nombre de variables par block */

  void rm_vars(){
    int i;
    char to_rm[1024];
    for(i=0; i<nb_vars; i++){
      sprintf(to_rm, "%s", block_vars[i]);
      ht_remove(&hash_table_new, to_rm);
    }
  }


  char *fonctions_args[3]={
    "norm_pi_pi", "@norm_pi_pi(double", "no"};


  void is_in_fonctions(char *s, char *dest){
    char *str1 = s;
    char tst[100];
    if (ht_exists(&hash_table_new,s))
      printf("exists\n");
    else
      ht_add(&hash_table_new,s,s,V_FUNCTION);

    printf("declare %s @%s()\n", s, tst);
  }

  void is_in_fonctions_args(char *s1, char *s2, char *dest){
    char *str1 = s1;
    char *str2 = s2;
    int i;
    for (i=0; i<1; i++){
      if (strcmp(str1, fonctions_args[3*i])==0){
    	if (strcmp(fonctions_args[3*i+2], "no")==0){
    	  printf("%%%s = alloca double\n", s1);
    	  fonctions_args[3*i+2] = "ok";
    	}
    	sprintf(buf, "%s", str2);
    	sprintf(buf+strlen(buf), "%%r%d = call double %s %%r%d)\n", tmps, fonctions_args[3*i+1], tmps-1);
    	sprintf(buf+strlen(buf), "store double %%r%d, double* @%s\n", tmps, str1);
    	tmps++;
    	return;
      }
    }
    printf("call @%s(%s)\n", s1, s2);
  }

  int print_values(struct val s1, struct val s2, char type_op[3], char *dst){
    char *str1 = s1.s;
    char *str2 = s2.s;
    struct Variable *v1 = ht_get(&hash_table_new, str1);
    struct Variable *v2 = ht_get(&hash_table_new, str2);
    int t1, t2;
    
    if(s1.type == 0){
      t1 = var_get_type(v1);
    }
    else
      t1 = s1.type;

    if(s2.type == 0){
      t2 = var_get_type(v2);
    }
    else
      t2 = s2.type;

    if(t1!=t2)
      //yyerror("Operations entre des entites de type different");
    
    sprintf(dst+strlen(dst), "%s", str2);

    if (t1==1){			/* int */
      char type_operation[3];
      if (strcmp("div", type_op)==0)
	sprintf(type_operation, "sdiv");
      else
	sprintf(type_operation, "%s", type_op);
      sprintf(dst+strlen(dst), "%%r%d = %s i32 %%r%d, %%r%d\n", tmps, type_operation, tmps-2, tmps-1);
    }

    else{			/* double */
      sprintf(dst+strlen(dst), "%%r%d = %s double %%r%d, %%r%d\n", tmps, type_op, tmps-2, tmps-1);
    }

    tmps+=1;
    return t1;
  }

 int print_value(struct val s1, char *dst){
    char *str1 = s1.s;
    char *buf1 = buf;
    memset(dst,0,sizeof(dst));
    struct Variable *v = NULL;
    int t;
    if(s1.type == 0){
      v = ht_get(&hash_table_new, str1);
      if (var_is_declared(v)){
      	t = var_get_type(v);
      }


      if (var_is_special(v)){
	sprintf(dst+strlen(dst), "r%d = load %s* @%s\n", tmps, types[t], var_get_llvm_name(v));
	printf("%s\n",dst);
      }
      else{
	sprintf(dst+strlen(dst), "r%d = load %s* @%s\n", tmps, types[t], var_get_name(v));
	printf("%s\n",dst);
      }
      tmps++;
      return t; 
    }
    
    else if (s1.type != 0) {
      str1 = s1.s;
      sprintf(dst, "\n%s", buf1);
      if (s1.type==1)		/* int */
	sprintf(dst+strlen(dst), "%%var%d = add i32 0, %s\n", tmps, str1);
      else			/* double */
	sprintf(dst+strlen(dst), "%%var%d = add double 0.0, %s\n", tmps, str1);
      tmps++;
      return s1.type;
    }
    return -1;
  }

  int compare(struct val s1, struct val s2, char *dest, char int_comparison[3], char double_comparison[3]){
    char *str1 = s1.s;
    char *str2 = s2.s;
    char c='i';
    char c2[3];
    sprintf(c2, "%s", int_comparison);
    
    if (s1.type!=s2.type)
      //yyerror("Probleme de typage sur condition");
    
    if(s1.type == 2){
      c='f';
      sprintf(c2, "%s", double_comparison);
    }
    
    sprintf(dest, "%s %s", str1, str2);
    sprintf(dest+strlen(dest), "%%result%d = %ccmp %s %s %%r%d, %%r%d\n\n", results, c, c2, types[s1.type], tmps-2, tmps-1);
    ;
    results++;
    return s1.type;
}

  extern int yylineno;
  int yylex ();

  void print_struct_definition();
%}

%token <val> IDENTIFIER
%token <val> CONSTANTF
%token <val> CONSTANTI
%token <val> INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token <val> SUB_ASSIGN MUL_ASSIGN ADD_ASSIGN
%token <val> TYPE_NAME
%token <val> INT DOUBLE VOID
%token <val> IF ELSE WHILE RETURN FOR
%start program

%type <val> primary_expression
%type <val> comparison_expression 
%type <val> additive_expression
%type <val> multiplicative_expression
%type <val> unary_expression
%type <val> argument_expression_list
%type <val> postfix_expression
%type <val> expression

%type <val> assignment_operator
%type <val> declaration
%type <val> declarator_list
%type <val> type_name
%type <val> declarator
%type <val> parameter_list
%type <val> parameter_declaration
%type <val> statement
%type <val> compound_statement
%type <val> declaration_list
%type <val> statement_list
%type <val> expression_statement
%type <val> selection_statement
%type <val> iteration_statement
%type <val> jump_statement
%type <val> program
%type <val> external_declaration
%type <val> function_definition

%%


primary_expression
: IDENTIFIER         {buf[0]='\0';}
| CONSTANTI          {buf[0]='\0';}
| CONSTANTF          {buf[0]='\0';}
| '(' expression ')' {$$=$2;}
| IDENTIFIER '(' ')' {is_in_fonctions($1.s, $$.s);}
| IDENTIFIER '(' argument_expression_list ')' {is_in_fonctions_args($1.s, $3.s, $$.s);}
| IDENTIFIER INC_OP  //{yyerror("Le ++ n'est pas gere");}
| IDENTIFIER DEC_OP  //{yyerror("Le -- n'est pas gere");}
;

postfix_expression
: primary_expression
| postfix_expression '[' expression ']' {yyerror("Les tableaux ne sont pas geres");}
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
| multiplicative_expression '/' unary_expression {$$.type=print_value($3, $3.s); struct val v; sprintf(v.s, "%s", $3.s); v.type = $$.type; $$.type=print_values($1, v, "div", $$.s);}
;

additive_expression
: multiplicative_expression
| additive_expression '+' multiplicative_expression {printf("r%d = add nsw %s r%d, r%d\n", tmps,types[$1.type],$1.reg,$3.reg);tmps++;}//$$.type=print_values($1, $3, "add", $$.s);}
| additive_expression '-' multiplicative_expression {$$.type=print_values($1, $3, "sub", $$.s);}
;

comparison_expression
: additive_expression		/* Pose problème si mis en condition */
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

  struct Variable *v = ht_get(&hash_table_new, str1);
  t1 = var_get_type(v);
  
  if (var_is_declared(v)){
    t1 = var_get_type(v);
  }/*
  else
  yyerror("Affectation dans une variable non declaree");*/
    
  if (t1!=t2)
    //yyerror("Affectation dans une variable de type different");
    sprintf($$.s, "%s", str3);

  if(strlen(type_assignement)>0){
    char assign=' ';
    char a_type[6] = "i32";
    if (t2 == 2){
      assign='d';
      sprintf(a_type, "double");
    }

    if(var_is_special(v)){
      sprintf($$.s+strlen($$.s),"%%r%d = load %s* @%s\n", tmps, types[t2], var_get_llvm_name(v));
    }
    else{
      sprintf($$.s+strlen($$.s),"%%r%d = load %s* @%s\n", tmps, types[t2], var_get_llvm_name(v));
    }
    sprintf($$.s+strlen($$.s), "%%r%d = %c%s %s %%r%d, %%r%d\n", tmps+1, assign, type_assignement, a_type, tmps-1, tmps);
  }

  if (t1==1){ 			/* int */
    if (var_is_special(v)){
      sprintf($$.s+strlen($$.s), "store i32 %%r%d, i32* @%s\n", tmps-1, var_get_llvm_name(v));
      var_set_modified(v, V_MODIFIED);
    }
    else
      sprintf($$.s+strlen($$.s), "store i32 %%r%d, i32* @%s\n", tmps-1, var_get_llvm_name(v));
  }
  else{				/* double */
    if (var_is_special(v)){
      var_set_modified(v, V_MODIFIED);
      sprintf($$.s+strlen($$.s), "store double %%r%d, double* @%s\n", tmps-1, var_get_llvm_name(v));
    }
    else
      sprintf($$.s+strlen($$.s), "store double %%r%d, double* @%s\n", tmps-1, var_get_llvm_name(v));
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
  int t = (strcmp(type_name, "i32") == 0)?V_INT:V_DOUBLE;
  char *str1 = $1.s;
  if(ht_exists(&hash_table_new, str1)){
    yyerror("Variable deja declare\n");
  }
  ht_add(&hash_table_new, $1.s, str1, t);
  printf("@%s = common global %s 0\n", str1, type_name);
 }
| declarator_list ',' declarator {
  sprintf(block_vars[nb_vars], "%s", $3.s); nb_vars++;
  int t = (strcmp(type_name, "i32") == 0)?V_INT:V_DOUBLE;
  char *str2 = $3.s;
  if(ht_exists(&hash_table_new, str2)){
    yyerror("Variable deja declare\n");
  }
  ht_add(&hash_table_new, str2, str2, t);
  printf("@%s = common global %s 0\n", str2, type_name);
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
| declarator '[' CONSTANTI ']'       {yyerror("Les tableaux ne sont pas geres");}
| declarator '[' ']'                 {yyerror("Les tableaux ne sont pas geres");}
| declarator '(' parameter_list ')'  
| declarator '(' ')'                 {printf("define %s @%s() {\n",types[$$.type],$1.s);}
;

parameter_list
: parameter_declaration		/* parametres de la fonction declaree */
| parameter_list ',' parameter_declaration
;

parameter_declaration
: type_name declarator
;

statement
: compound_statement   {char *str1 = $1.s; $$.type=$1.type; sprintf($$.s, "%s", str1);} 
| expression_statement {char *str1 = $1.s; $$.type=$1.type; sprintf($$.s, "%s", str1);}
| selection_statement  {char *str1 = $1.s; $$.type=$1.type; sprintf($$.s, "%s", str1);}
| iteration_statement  {char *str1 = $1.s; $$.type=$1.type; sprintf($$.s, "%s", str1);}
| jump_statement       {char *str1 = $1.s; $$.type=$1.type; sprintf($$.s, "%s", str1);}
;

compound_statement
: '{' '}' 
| '{' statement_list '}' {char *str2 = $2.s; $$.type=$2.type; sprintf($$.s, "%s", str2);}
| '{' declaration_list statement_list '}' {rm_vars(); nb_vars=0;char *str3 = $3.s; sprintf($$.s, "%s", str3);}
;

declaration_list
: declaration
| declaration_list declaration {nb_vars=0;}
;

statement_list
: statement                 {char *str1 = $1.s; $$.type=$1.type; sprintf($$.s, "%s", str1);}
| statement_list statement  {char *str2 = $2.s; sprintf($$.s+strlen($$.s), "%s", str2);}
;

expression_statement
: ';'
| expression ';' {char *str1 = $1.s; sprintf($$.s, "%s", str1);}
;

selection_statement
: IF '(' expression ')' statement {
  char *str3 = $3.s;
  char *str5 = $5.s;
  sprintf($$.s, "%s", str3);
  sprintf($$.s+strlen($$.s), "br i1 %%result%d, label %d, label %d\n\n", results-1, labels, labels+1);
  sprintf($$.s+strlen($$.s), "label%d:\n", labels);
  labels++;
  /* expr */
  sprintf($$.s+strlen($$.s), "%s\n", str5);
  sprintf($$.s+strlen($$.s), "br label %d\n \nlabel%d:\n;;", labels, labels);
  labels++;
 }
| IF '(' expression ')' statement ELSE statement {
  sprintf($$.s, "%s", $3.s);
  sprintf($$.s+strlen($$.s), "br i1 %%result%d, label %d, label %d\n\n", results-1, labels, labels+1);
  sprintf($$.s+strlen($$.s), "label%d:\n", labels);
  labels++;
  /* expr */
  sprintf($$.s+strlen($$.s), "%s\n", $5.s);
  sprintf($$.s+strlen($$.s), "br label %d\n", labels+2);
  sprintf($$.s+strlen($$.s), "label%d:\n", labels);
  labels++;
  /* expr */
  sprintf($$.s+strlen($$.s), "%s\n", $7.s);
  sprintf($$.s+strlen($$.s), "br label %d\n \nlabel%d:\n;;", labels+1, labels+1);
  labels++;
  }
| FOR '(' expression_statement expression_statement expression ')' statement {
  sprintf($$.s, "%s", $3.s);
  sprintf($$.s+strlen($$.s), "br label %d\n \n; <label>:%d\n", loops, loops);
  loops++;
  sprintf($$.s+strlen($$.s), "%s", $4.s);
  sprintf($$.s+strlen($$.s), "br i1 %%result%d, label %d, label %d\n\n", results-1, loops, loops+1);
  sprintf($$.s+strlen($$.s), "; <label>:%d\n", loops);
  /* i=i+1 */
  sprintf($$.s+strlen($$.s), "%s", $5.s);
  /* contenu boucle */
  sprintf($$.s+strlen($$.s), "%s", $7.s);
  /* on revient au début de la boucle */
  sprintf($$.s+strlen($$.s), "br label %d\n", loops-1);
  sprintf($$.s+strlen($$.s), "; <label>:%d\n;;", loops+1);
 loops++;
  }
;

iteration_statement
: WHILE '(' expression ')' statement
{
  sprintf($$.s, "br label %d\n \nlabel%d:\n", labels, labels);
  labels++;
  sprintf($$.s+strlen($$.s), "%s", $3.s);
  sprintf($$.s+strlen($$.s), "br i1 %%result%d, label %d, label %d\n", results-1, loops, loops+1);
  sprintf($$.s+strlen($$.s), "\n; <label>:%d\n", loops);
  sprintf($$.s+strlen($$.s), "%s", $5.s);
  sprintf($$.s+strlen($$.s), "br label %d\n \n; <label>:%d\n;;", labels-1, loops+1);
  loops+=2;
  labels++;
}
;

jump_statement
: RETURN ';'           {printf("ret\n");}
| RETURN expression ';' {printf("ret\n");}
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
    /* file_name = strdup (argv[1]); */

    if (!input){
      fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
      return 1;
    }

    printf("; ModuleID = '%s'\ntarget datalayout = \"e-p:32:32-i64:64-v128:32:128-n32-S128\"\ntarget triple = \"asmjs-unknown-emscripten\"\n\n",argv[1]);

    ht_init(&hash_table_new);
    
    yyin = input;
 
    yyparse ();

    fclose(input);
    return 0;
}
