%{
#include <stdio.h>
#include <string.h>
#include "grammar.tab.h"
void count();
int comment ();
%}
D[0-9]
L[a-zA-Z_]
%option yylineno
%%
"/*"		{ comment(); }
"//".*          { count(); }
"float"		{ count(); printf("%s\n",yytext); return(FLOAT); }
"if"		{ count(); printf("%s\n",yytext); return(IF); }
"else"		{ count(); printf("%s\n",yytext); return(ELSE); }
"int"		{ count(); printf("%s\n",yytext); return(INT); }
"return"	{ count(); printf("%s\n",yytext); return(RETURN); }
"void"		{ count(); printf("%s\n",yytext); return(VOID); }
"double"        { count(); printf("%s\n",yytext); return(DOUBLE); }
"while"		{ count(); printf("%s\n",yytext); return(WHILE); }
"for"		{ count(); printf("%s\n",yytext); return(FOR); }
"do"            { count(); printf("%s\n",yytext); return(DO); }

[$]?{L}({L}|{D})*	{ count(); yylval.string=strdup(yytext); return(IDENTIFIER); }
{D}+    	{ count(); yylval.string=strdup(yytext); return(CONSTANTI); }
{D}+"."{D}*     { count(); yylval.string=strdup(yytext); return(CONSTANTF); }
"+="		{ count(); return(ADD_ASSIGN); }
"-="		{ count(); return(SUB_ASSIGN); }
"*="		{ count(); return(MUL_ASSIGN); }
"/="		{ count(); return(DIV_ASSIGN); }
"<<="		{ count(); return(SHL_ASSIGN); }
">>="		{ count(); return(SHR_ASSIGN); }
"++"		{ count(); return(INC_OP); }
"--"		{ count(); return(DEC_OP); }
"<="		{ count(); return(LE_OP); }
">="		{ count(); return(GE_OP); }
"=="		{ count(); return(EQ_OP); }
"!="		{ count(); return(NE_OP); }
";"		{ count(); return(';'); }
"{"      	{ count(); return('{'); }
"}"      	{ count(); return('}'); }
","		{ count(); return(','); }
"/"		{ count(); return('/'); }
"="		{ count(); printf("%s\n",yytext); return('='); }
"("		{ count(); return('('); }
")"		{ count(); return(')'); }
"."		{ count(); return('.'); }
"!"		{ count(); return('!'); }
"-"		{ count(); return('-'); }
"+"		{ count(); return('+'); }
"*"		{ count(); return('*'); }
"%"             { count(); return(REM); }
"<<"            { count(); return(SHL); }
">>"            { count(); return(SHR); }
"<"		{ count(); return('<'); }
">"		{ count(); return('>'); }
"||"            { count(); return(OR);  }
"&&"            { count(); return(AND); }
[ \t\v\n\f]	{ count(); }
.		{ /* ignore bad characters */ }

%%
int yywrap() {
	return 1;
}
/* This function reads a comment. Comments are not part of the grammar. */
int comment() {
	char c, c1;
loop:
	while ((c = input()) != '*' && c != 0);
	if ((c1 = input()) != '/' && c != 0) {
		unput(c1);
		goto loop;
	}
	return 0;
}

int column = 0;
/* This function counts the number of character, for debugging purposes */
void count() {
	int i;
	for (i = 0; yytext[i] != '\0'; i++) {
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	}
}

