/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

/* Line 371 of yacc.c  */
#line 68 "grammar.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.h".  */
#ifndef YY_YY_GRAMMAR_H_INCLUDED
# define YY_YY_GRAMMAR_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANTF = 259,
     CONSTANTI = 260,
     INC_OP = 261,
     DEC_OP = 262,
     LE_OP = 263,
     GE_OP = 264,
     EQ_OP = 265,
     NE_OP = 266,
     SUB_ASSIGN = 267,
     MUL_ASSIGN = 268,
     ADD_ASSIGN = 269,
     TYPE_NAME = 270,
     INT = 271,
     DOUBLE = 272,
     VOID = 273,
     IF = 274,
     ELSE = 275,
     WHILE = 276,
     RETURN = 277,
     FOR = 278
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 1 "grammar.y"

  struct val{
    int type;
    char s[40000];
  }val;
 

/* Line 387 of yacc.c  */
#line 142 "grammar.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_GRAMMAR_H_INCLUDED  */

/* Copy the second part of user declarations.  */
/* Line 390 of yacc.c  */
#line 8 "grammar.y"

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
  char type_name[5];

  int tmps = 0;		        /* pour les variables temporaires */
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

  char* fonctions[21]={
    "c",             "declare void @createCanvas(i32,i32)"         , "no",
    "b",           "@get_pos_to_right(%struct.tTrkLocPos* %pos)"        , "no",
    "square",          "@get_pos_to_middle(%struct.tTrkLocPos* %pos)"       , "no",
    "mul_add",            "@get_pos_to_left(%struct.tTrkLocPos* %pos)"         , "no",
    "pos_to_start",           "@get_pos_to_start(%struct.tTrkLocPos* %pos)"        , "no",
    "track_seg_length",       "@get_track_seg_length(%struct.trackSeg* %seg)"      , "no",
    "track_seg_width",        "@get_track_seg_width(%struct.trackSeg* %seg)"       , "no",
    "track_seg_start_width",  "@get_track_seg_start_width(%struct.trackSeg* %seg)" , "no",
    "track_seg_end_width",    "@get_track_seg_end_width(%struct.trackSeg* %seg)"   , "no",
    "track_seg_radius",       "@get_track_seg_radius(%struct.trackSeg* %seg)"      , "no",
    "track_seg_right_radius", "@get_track_seg_right_radius(%struct.trackSeg* %seg)", "no",
    "track_seg_left_radius",  "@get_track_seg_left_radius(%struct.trackSeg* %seg)" , "no",
    "track_seg_arc",          "@get_track_seg_arc(%struct.trackSeg* %seg)"         , "no",
    "car_angle",              "@get_car_yaw(%struct.CarElt* %car)"                 , "no",};

  char *fonctions_args[3]={
    "norm_pi_pi", "@norm_pi_pi(double", "no"};


  void is_in_fonctions(char *s, char *dest){
    char *str1 = s;
    char tst[100];
    int i;
    if (ht_exists(&hash_table_new,"toto"))
      printf("exists\n");
    else
      ht_add(&hash_table_new,s,s,V_DOUBLE);
    /*for (i=0; i<13; i++){
      if (strcmp(s, fonctions[3*i])==0){
	if (strcmp(fonctions[3*i+2], "no")==0){
	  printf("%%%s = alloca double\n", s);
	  fonctions[3*i+2] = "ok";
	}
	sprintf(dest, "%s", str1);
  	sprintf(buf, "%%d = call double %s\n", tmps, fonctions[3*i+1]);
	strcpy(tst,fonctions[3*1+1]);
  	sprintf(buf+strlen(buf), "store double %%d, double* @%s\n", tmps, str1);
  	tmps++;
  	return;
      }
      }*/
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
  	sprintf(buf+strlen(buf), "%%var%d = call double %s %%var%d)\n", tmps, fonctions_args[3*i+1], tmps-1);
  	sprintf(buf+strlen(buf), "store double %%var%d, double* @%s\n", tmps, str1);
  	tmps++;
  	return;
      }
    }
    printf("call @%s(%s)\n", s1, s2);
    //yyerror("Fonction non declaree");
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
      sprintf(dst+strlen(dst), "%%var%d = %s i32 %%var%d, %%var%d\n", tmps, type_operation, tmps-2, tmps-1);
    }

    else{			/* double */
      sprintf(dst+strlen(dst), "%%var%d = %s double %%var%d, %%var%d\n", tmps, type_op, tmps-2, tmps-1);
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

      if (var_is_declared(v))
	t = var_get_type(v);
      else
	//yyerror("Variable non definie");	

	sprintf(dst, "\n");

      if (var_is_special(v))
	sprintf(dst+strlen(dst), "%%var%d = load %s* @%s\n", tmps, types[t], var_get_llvm_name(v));
      else
	sprintf(dst+strlen(dst), "%%var%d = load %s* @%s\n", tmps, types[t], var_get_name(v));
  
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
    sprintf(dest+strlen(dest), "%%result%d = %ccmp %s %s %%var%d, %%var%d\n\n", results, c, c2, types[s1.type], tmps-2, tmps-1);
    ;
    results++;
    return s1.type;
}

  extern int yylineno;
  int yylex ();

  void print_struct_definition();

/* Line 390 of yacc.c  */
#line 378 "grammar.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    30,    32,    28,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      34,    35,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    17,    22,    25,
      28,    30,    35,    37,    41,    43,    46,    49,    52,    54,
      56,    60,    64,    66,    70,    74,    76,    80,    84,    88,
      92,    96,   100,   104,   106,   108,   110,   112,   114,   118,
     120,   124,   126,   128,   130,   132,   136,   141,   145,   150,
     154,   156,   160,   163,   165,   167,   169,   171,   173,   176,
     180,   185,   187,   190,   192,   195,   197,   200,   206,   214,
     222,   228,   231,   235,   237,   240,   242,   244
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,     3,    -1,     5,    -1,     4,    -1,    24,
      48,    25,    -1,     3,    24,    25,    -1,     3,    24,    42,
      25,    -1,     3,     6,    -1,     3,     7,    -1,    40,    -1,
      41,    26,    48,    27,    -1,    48,    -1,    42,    28,    48,
      -1,    41,    -1,     6,    43,    -1,     7,    43,    -1,    44,
      43,    -1,    29,    -1,    43,    -1,    45,    30,    43,    -1,
      45,    31,    43,    -1,    45,    -1,    46,    32,    45,    -1,
      46,    29,    45,    -1,    46,    -1,    46,    33,    46,    -1,
      46,    34,    46,    -1,    46,     8,    46,    -1,    46,     9,
      46,    -1,    46,    11,    46,    -1,    46,    10,    46,    -1,
      43,    49,    47,    -1,    47,    -1,    35,    -1,    13,    -1,
      14,    -1,    12,    -1,    52,    51,    36,    -1,    53,    -1,
      51,    28,    53,    -1,    18,    -1,    16,    -1,    17,    -1,
       3,    -1,    24,    53,    25,    -1,    53,    26,     5,    27,
      -1,    53,    26,    27,    -1,    53,    24,    54,    25,    -1,
      53,    24,    25,    -1,    55,    -1,    54,    28,    55,    -1,
      52,    53,    -1,    57,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    37,    38,    -1,    37,    59,    38,    -1,
      37,    58,    59,    38,    -1,    50,    -1,    58,    50,    -1,
      56,    -1,    59,    56,    -1,    36,    -1,    48,    36,    -1,
      19,    24,    48,    25,    56,    -1,    19,    24,    48,    25,
      56,    20,    56,    -1,    23,    24,    60,    60,    48,    25,
      56,    -1,    21,    24,    48,    25,    56,    -1,    22,    36,
      -1,    22,    48,    36,    -1,    65,    -1,    64,    65,    -1,
      66,    -1,    50,    -1,    52,    53,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   258,   258,   259,   260,   261,   262,   263,   264,   265,
     269,   270,   274,   275,   279,   280,   281,   282,   286,   290,
     291,   292,   296,   297,   298,   302,   303,   304,   305,   306,
     307,   308,   312,   370,   374,   375,   376,   377,   381,   385,
     395,   409,   410,   411,   415,   416,   417,   418,   419,   420,
     424,   425,   429,   433,   434,   435,   436,   437,   441,   442,
     443,   447,   448,   452,   453,   457,   458,   462,   474,   489,
     508,   523,   524,   528,   529,   533,   534,   538
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANTF", "CONSTANTI",
  "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "SUB_ASSIGN",
  "MUL_ASSIGN", "ADD_ASSIGN", "TYPE_NAME", "INT", "DOUBLE", "VOID", "IF",
  "ELSE", "WHILE", "RETURN", "FOR", "'('", "')'", "'['", "']'", "','",
  "'-'", "'*'", "'/'", "'+'", "'>'", "'<'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression",
  "comparison_expression", "expression", "assignment_operator",
  "declaration", "declarator_list", "type_name", "declarator",
  "parameter_list", "parameter_declaration", "statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    40,    41,    91,    93,    44,    45,
      42,    47,    43,    62,    60,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    43,    43,    43,    43,    44,    45,
      45,    45,    46,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    49,    50,    51,
      51,    52,    52,    52,    53,    53,    53,    53,    53,    53,
      54,    54,    55,    56,    56,    56,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    63,    63,    64,    64,    65,    65,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     4,     2,     2,
       1,     4,     1,     3,     1,     2,     2,     2,     1,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     4,     3,     4,     3,
       1,     3,     2,     1,     1,     1,     1,     1,     2,     3,
       4,     1,     2,     1,     2,     1,     2,     5,     7,     7,
       5,     2,     3,     1,     2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    42,    43,    41,    76,     0,     0,    73,    75,    44,
       0,     0,    39,     1,    74,     0,     0,    38,     0,     0,
       0,    77,    45,    40,    49,     0,     0,    50,     0,    47,
       2,     4,     3,     0,     0,     0,     0,     0,     0,     0,
      18,    65,    58,    10,    14,    19,     0,    22,    25,    33,
       0,    61,     0,    63,    53,     0,     0,    54,    55,    56,
      57,    52,    48,     0,    46,     8,     9,     0,    15,    16,
       0,     0,    71,     0,     0,     0,     0,    37,    35,    36,
      34,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    39,    62,     0,    59,    64,    51,
       6,     0,    12,     0,     0,    72,     0,     5,     0,    19,
      32,    20,    21,    28,    29,    31,    30,    24,    23,    26,
      27,    60,     7,     0,     0,     0,     0,    11,    13,    67,
      70,     0,     0,     0,    68,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    43,    44,   101,    45,    46,    47,    48,    49,    50,
      81,     4,    11,     5,    12,    26,    27,    53,    54,    55,
      56,    57,    58,    59,    60,     6,     7,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int16 yypact[] =
{
      85,   -62,   -62,   -62,   -62,    14,    47,   -62,   -62,   -62,
      14,    60,    48,   -62,   -62,   104,    14,   -62,    50,     9,
      76,   -62,   -62,   129,   -62,    14,   -10,   -62,    -5,   -62,
      13,   -62,   -62,    20,    20,     5,    11,   177,    16,    20,
     -62,   -62,   -62,   -62,    26,    -3,    20,   136,   185,   -62,
      10,   -62,    14,   -62,   -62,   141,   103,   -62,   -62,   -62,
     -62,   129,   -62,    85,   -62,   -62,   -62,   217,   -62,   -62,
      20,    20,   -62,    35,   204,    59,    20,   -62,   -62,   -62,
     -62,    20,   -62,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,   -62,   129,   -62,   114,   -62,   -62,   -62,
     -62,     3,   -62,    62,    79,   -62,   204,   -62,    84,   -62,
     -62,   -62,   -62,    44,    44,    44,    44,   136,   136,    44,
      44,   -62,   -62,    20,   168,   168,    20,   -62,   -62,    95,
     -62,    91,   168,   168,   -62,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   -62,   -30,   -62,     1,   144,    42,   -37,
     -62,   -12,   -62,   -13,    -4,   -62,    68,   -55,   122,   -62,
      87,   -61,   -62,   -62,   -62,   -62,   143,   -62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      73,    98,    75,    68,    69,    25,    15,    52,    51,    77,
      78,    79,    23,   106,    28,    62,    82,     9,    63,    65,
      66,    61,    64,    30,    31,    32,    33,    34,   122,    70,
     102,   123,    80,   103,   104,    71,    29,    67,    10,   108,
      74,    98,    52,    95,    39,   126,    93,    13,    94,    40,
      25,   109,    76,   111,   112,   109,   109,   109,   109,   109,
     109,   109,   109,     1,     2,     3,     1,     2,     3,   129,
     130,   105,    18,    89,    19,    24,    90,   134,   135,    30,
      31,    32,    33,    34,   107,    20,   128,   124,    16,   131,
     117,   118,     1,     2,     3,    35,    17,    36,    37,    38,
      39,     1,     2,     3,   125,    40,    30,    31,    32,    33,
      34,   127,    41,    20,    42,   132,   133,    30,    31,    32,
      33,    34,    35,   110,    36,    37,    38,    39,    18,    22,
      19,    99,    40,    35,    21,    36,    37,    38,    39,    41,
      20,    97,    96,    40,    30,    31,    32,    33,    34,    14,
      41,    20,   121,    18,     0,    19,     0,     1,     2,     3,
      35,     0,    36,    37,    38,    39,    83,    84,     0,     0,
      40,    30,    31,    32,    33,    34,     0,    41,    20,     0,
      30,    31,    32,    33,    34,     0,     0,    35,     0,    36,
      37,    38,    39,    85,    86,    87,    88,    40,     0,     0,
       0,    39,     0,     0,    41,    20,    40,    30,    31,    32,
      33,    34,     0,    72,    89,     0,     0,    90,    91,    92,
      30,    31,    32,    33,    34,     0,     0,     0,    39,   113,
     114,   115,   116,    40,     0,   119,   120,     0,     0,     0,
      41,    39,   100,     0,     0,     0,    40
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      37,    56,    39,    33,    34,    18,    10,    20,    20,    12,
      13,    14,    16,    74,     5,    25,    46,     3,    28,     6,
       7,    25,    27,     3,     4,     5,     6,     7,    25,    24,
      67,    28,    35,    70,    71,    24,    27,    24,    24,    76,
      24,    96,    55,    55,    24,   106,    36,     0,    52,    29,
      63,    81,    26,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    16,    17,    18,    16,    17,    18,   124,
     125,    36,    24,    29,    26,    25,    32,   132,   133,     3,
       4,     5,     6,     7,    25,    37,   123,    25,    28,   126,
      89,    90,    16,    17,    18,    19,    36,    21,    22,    23,
      24,    16,    17,    18,    25,    29,     3,     4,     5,     6,
       7,    27,    36,    37,    38,    20,    25,     3,     4,     5,
       6,     7,    19,    81,    21,    22,    23,    24,    24,    25,
      26,    63,    29,    19,    12,    21,    22,    23,    24,    36,
      37,    38,    55,    29,     3,     4,     5,     6,     7,     6,
      36,    37,    38,    24,    -1,    26,    -1,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    30,    31,    -1,    -1,
      29,     3,     4,     5,     6,     7,    -1,    36,    37,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    19,    -1,    21,
      22,    23,    24,     8,     9,    10,    11,    29,    -1,    -1,
      -1,    24,    -1,    -1,    36,    37,    29,     3,     4,     5,
       6,     7,    -1,    36,    29,    -1,    -1,    32,    33,    34,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    24,    85,
      86,    87,    88,    29,    -1,    91,    92,    -1,    -1,    -1,
      36,    24,    25,    -1,    -1,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    17,    18,    50,    52,    64,    65,    66,     3,
      24,    51,    53,     0,    65,    53,    28,    36,    24,    26,
      37,    57,    25,    53,    25,    52,    54,    55,     5,    27,
       3,     4,     5,     6,     7,    19,    21,    22,    23,    24,
      29,    36,    38,    40,    41,    43,    44,    45,    46,    47,
      48,    50,    52,    56,    57,    58,    59,    60,    61,    62,
      63,    53,    25,    28,    27,     6,     7,    24,    43,    43,
      24,    24,    36,    48,    24,    48,    26,    12,    13,    14,
      35,    49,    43,    30,    31,     8,     9,    10,    11,    29,
      32,    33,    34,    36,    53,    50,    59,    38,    56,    55,
      25,    42,    48,    48,    48,    36,    60,    25,    48,    43,
      47,    43,    43,    46,    46,    46,    46,    45,    45,    46,
      46,    38,    25,    28,    25,    25,    60,    27,    48,    56,
      56,    48,    20,    25,    56,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 258 "grammar.y"
    {buf[0]='\0';}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 259 "grammar.y"
    {buf[0]='\0';}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 260 "grammar.y"
    {buf[0]='\0';}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 261 "grammar.y"
    {(yyval.val)=(yyvsp[(2) - (3)].val);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 262 "grammar.y"
    {is_in_fonctions((yyvsp[(1) - (3)].val).s, (yyval.val).s);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 263 "grammar.y"
    {is_in_fonctions_args((yyvsp[(1) - (4)].val).s, (yyvsp[(3) - (4)].val).s, (yyval.val).s);}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 270 "grammar.y"
    {yyerror("Les tableaux ne sont pas geres");}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 275 "grammar.y"
    {(yyval.val).type=(yyvsp[(3) - (3)].val).type;sprintf((yyval.val).s, "%s", (yyvsp[(1) - (3)].val).s); sprintf((yyval.val).s+strlen((yyval.val).s), "%s", (yyvsp[(3) - (3)].val).s);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 282 "grammar.y"
    {(yyval.val)=(yyvsp[(2) - (2)].val);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 290 "grammar.y"
    {(yyval.val).type=print_value((yyvsp[(1) - (1)].val), (yyval.val).s);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 291 "grammar.y"
    {(yyval.val).type=print_value((yyvsp[(3) - (3)].val), (yyvsp[(3) - (3)].val).s); struct val v; sprintf(v.s, "%s", (yyvsp[(3) - (3)].val).s); v.type = (yyval.val).type; (yyval.val).type=print_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), "mul", (yyval.val).s);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 292 "grammar.y"
    {(yyval.val).type=print_value((yyvsp[(3) - (3)].val), (yyvsp[(3) - (3)].val).s); struct val v; sprintf(v.s, "%s", (yyvsp[(3) - (3)].val).s); v.type = (yyval.val).type; (yyval.val).type=print_values((yyvsp[(1) - (3)].val), v, "div", (yyval.val).s);}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 297 "grammar.y"
    {(yyval.val).type=print_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), "add", (yyval.val).s);}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 298 "grammar.y"
    {(yyval.val).type=print_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), "sub", (yyval.val).s);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 303 "grammar.y"
    {(yyval.val).type=compare((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyval.val).s, "ugt", "ogt");}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 304 "grammar.y"
    {(yyval.val).type=compare((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyval.val).s, "ult", "olt");}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 305 "grammar.y"
    {(yyval.val).type=compare((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyval.val).s, "ule", "ole");}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 306 "grammar.y"
    {(yyval.val).type=compare((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyval.val).s, "uge", "oge");}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 307 "grammar.y"
    {(yyval.val).type=compare((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyval.val).s, "ne",  "one");}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 308 "grammar.y"
    {(yyval.val).type=compare((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyval.val).s, "eq",  "oeq");}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 312 "grammar.y"
    {
  char *str1 = (yyvsp[(1) - (3)].val).s;
  char *str3 = (yyvsp[(3) - (3)].val).s;
  int t1, t2;
  t2 = (yyvsp[(3) - (3)].val).type;
  memset((yyval.val).s,0,sizeof((yyval.val).s));

  struct Variable *v = ht_get(&hash_table_new, str1);
  t1 = var_get_type(v);
  
  if (var_is_declared(v)){
    t1 = var_get_type(v);
  }/*
  else
  yyerror("Affectation dans une variable non declaree");*/
    
  if (t1!=t2)
    //yyerror("Affectation dans une variable de type different");
    sprintf((yyval.val).s, "%s", str3);

  if(strlen(type_assignement)>0){
    char assign=' ';
    char a_type[6] = "i32";
    if (t2 == 2){
      assign='d';
      sprintf(a_type, "double");
    }

    if(var_is_special(v)){
      sprintf((yyval.val).s+strlen((yyval.val).s),"%%var%d = load %s* @%s\n", tmps, types[t2], var_get_llvm_name(v));
    }
    else{
      sprintf((yyval.val).s+strlen((yyval.val).s),"%%var%d = load %s* @%s\n", tmps, types[t2], var_get_llvm_name(v));
    }
    sprintf((yyval.val).s+strlen((yyval.val).s), "%%var%d = %c%s %s %%var%d, %%var%d\n", tmps+1, assign, type_assignement, a_type, tmps-1, tmps);
  }

  if (t1==1){ 			/* int */
    if (var_is_special(v)){
      sprintf((yyval.val).s+strlen((yyval.val).s), "store i32 %%var%d, i32* @%s\n", tmps-1, var_get_llvm_name(v));
      var_set_modified(v, V_MODIFIED);
    }
    else
      sprintf((yyval.val).s+strlen((yyval.val).s), "store i32 %%var%d, i32* @%s\n", tmps-1, var_get_llvm_name(v));
  }
  else{				/* double */
    if (var_is_special(v)){
      var_set_modified(v, V_MODIFIED);
      sprintf((yyval.val).s+strlen((yyval.val).s), "store double %%var%d, double* @%s\n", tmps-1, var_get_llvm_name(v));
    }
    else
      sprintf((yyval.val).s+strlen((yyval.val).s), "store double %%var%d, double* @%s\n", tmps-1, var_get_llvm_name(v));
  }

  if(strlen(type_assignement)>0){
    tmps+=2;
  }
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 374 "grammar.y"
    {type_assignement[0]='\0';}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 375 "grammar.y"
    {sprintf(type_assignement, "mul");}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 376 "grammar.y"
    {sprintf(type_assignement, "add");}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 377 "grammar.y"
    {sprintf(type_assignement, "sub");}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 381 "grammar.y"
    {(yyval.val)=(yyvsp[(2) - (3)].val);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 385 "grammar.y"
    {
  sprintf(block_vars[nb_vars], "%s", (yyvsp[(1) - (1)].val).s); nb_vars++;
  int t = (strcmp(type_name, "i32") == 0)?V_INT:V_DOUBLE;
  char *str1 = (yyvsp[(1) - (1)].val).s;
  if(ht_exists(&hash_table_new, str1)){
    //yyerror("Variable deja declare\n");
  }
  ht_add(&hash_table_new, (yyvsp[(1) - (1)].val).s, str1, t);
  printf("@%s = common global %s 0\n", str1, type_name);
 }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 395 "grammar.y"
    {
  sprintf(block_vars[nb_vars], "%s", (yyvsp[(3) - (3)].val).s); nb_vars++;
  int t = (strcmp(type_name, "i32") == 0)?V_INT:V_DOUBLE;
  char *str2 = (yyvsp[(3) - (3)].val).s;
  if(ht_exists(&hash_table_new, str2)){
    //yyerror("Variable deja declare\n");
  }
  
  ht_add(&hash_table_new, str2, str2, t);
  printf("@%s = common global %s 0\n", str2, type_name);
  }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 409 "grammar.y"
    {sprintf(type_name, "void");}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 410 "grammar.y"
    {sprintf(type_name, "i32");}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 411 "grammar.y"
    {sprintf(type_name, "double");}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 417 "grammar.y"
    {yyerror("Les tableaux ne sont pas geres");}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 418 "grammar.y"
    {yyerror("Les tableaux ne sont pas geres");}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 433 "grammar.y"
    {char *str1 = (yyvsp[(1) - (1)].val).s; (yyval.val).type=(yyvsp[(1) - (1)].val).type; sprintf((yyval.val).s, "%s", str1);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 434 "grammar.y"
    {char *str1 = (yyvsp[(1) - (1)].val).s; (yyval.val).type=(yyvsp[(1) - (1)].val).type; sprintf((yyval.val).s, "%s", str1);}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 435 "grammar.y"
    {char *str1 = (yyvsp[(1) - (1)].val).s; (yyval.val).type=(yyvsp[(1) - (1)].val).type; sprintf((yyval.val).s, "%s", str1);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 436 "grammar.y"
    {char *str1 = (yyvsp[(1) - (1)].val).s; (yyval.val).type=(yyvsp[(1) - (1)].val).type; sprintf((yyval.val).s, "%s", str1);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 437 "grammar.y"
    {char *str1 = (yyvsp[(1) - (1)].val).s; (yyval.val).type=(yyvsp[(1) - (1)].val).type; sprintf((yyval.val).s, "%s", str1);}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 442 "grammar.y"
    {char *str2 = (yyvsp[(2) - (3)].val).s; (yyval.val).type=(yyvsp[(2) - (3)].val).type; sprintf((yyval.val).s, "%s", str2);}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 443 "grammar.y"
    {rm_vars(); nb_vars=0;char *str3 = (yyvsp[(3) - (4)].val).s; sprintf((yyval.val).s, "%s", str3);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 448 "grammar.y"
    {nb_vars=0;}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 452 "grammar.y"
    {char *str1 = (yyvsp[(1) - (1)].val).s; (yyval.val).type=(yyvsp[(1) - (1)].val).type; sprintf((yyval.val).s, "%s", str1);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 453 "grammar.y"
    {char *str2 = (yyvsp[(2) - (2)].val).s; sprintf((yyval.val).s+strlen((yyval.val).s), "%s", str2);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 458 "grammar.y"
    {char *str1 = (yyvsp[(1) - (2)].val).s; sprintf((yyval.val).s, "%s", str1);}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 462 "grammar.y"
    {
  char *str3 = (yyvsp[(3) - (5)].val).s;
  char *str5 = (yyvsp[(5) - (5)].val).s;
  sprintf((yyval.val).s, "%s", str3);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br i1 %%result%d, label %%label%d, label %%label%d\n\n", results-1, labels, labels+1);
  sprintf((yyval.val).s+strlen((yyval.val).s), "label%d:\n", labels);
  labels++;
  /* expr */
  sprintf((yyval.val).s+strlen((yyval.val).s), "%s\n", str5);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br label %%label%d\n \nlabel%d:\n;;", labels, labels);
  labels++;
 }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 474 "grammar.y"
    {
  sprintf((yyval.val).s, "%s", (yyvsp[(3) - (7)].val).s);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br i1 %%result%d, label %%label%d, label %%label%d\n\n", results-1, labels, labels+1);
  sprintf((yyval.val).s+strlen((yyval.val).s), "label%d:\n", labels);
  labels++;
  /* expr */
  sprintf((yyval.val).s+strlen((yyval.val).s), "%s\n", (yyvsp[(5) - (7)].val).s);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br label %%label%d\n", labels+2);
  sprintf((yyval.val).s+strlen((yyval.val).s), "label%d:\n", labels);
  labels++;
  /* expr */
  sprintf((yyval.val).s+strlen((yyval.val).s), "%s\n", (yyvsp[(7) - (7)].val).s);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br label %%label%d\n \nlabel%d:\n;;", labels+1, labels+1);
  labels++;
  }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 489 "grammar.y"
    {
  sprintf((yyval.val).s, "%s", (yyvsp[(3) - (7)].val).s);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br label %%loop%d\n \nloop%d:\n", loops, loops);
  loops++;
  sprintf((yyval.val).s+strlen((yyval.val).s), "%s", (yyvsp[(4) - (7)].val).s);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br i1 %%result%d, label %%loop%d, label %%loop%d\n\n", results-1, loops, loops+1);
  sprintf((yyval.val).s+strlen((yyval.val).s), "loop%d:\n", loops);
  /* i=i+1 */
  sprintf((yyval.val).s+strlen((yyval.val).s), "%s", (yyvsp[(5) - (7)].val).s);
  /* contenu boucle */
  sprintf((yyval.val).s+strlen((yyval.val).s), "%s", (yyvsp[(7) - (7)].val).s);
  /* on revient au début de la boucle */
  sprintf((yyval.val).s+strlen((yyval.val).s), "br label %%loop%d\n", loops-1);
  sprintf((yyval.val).s+strlen((yyval.val).s), "loop%d:\n;;", loops+1);
 loops++;
  }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 509 "grammar.y"
    {
  sprintf((yyval.val).s, "br label %%label%d\n \nlabel%d:\n", labels, labels);
  labels++;
  sprintf((yyval.val).s+strlen((yyval.val).s), "%s", (yyvsp[(3) - (5)].val).s);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br i1 %%result%d, label %%loop%d, label %%loop%d\n", results-1, loops, loops+1);
  sprintf((yyval.val).s+strlen((yyval.val).s), "\nloop%d:\n", loops);
  sprintf((yyval.val).s+strlen((yyval.val).s), "%s", (yyvsp[(5) - (5)].val).s);
  sprintf((yyval.val).s+strlen((yyval.val).s), "br label %%label%d\n \nloop%d:\n;;", labels-1, loops+1);
  loops+=2;
  labels++;
}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 538 "grammar.y"
    {printf("%s\n", (yyvsp[(3) - (3)].val).s);}
    break;


/* Line 1792 of yacc.c  */
#line 2134 "grammar.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 541 "grammar.y"

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
    return 0;
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

    /* Ajout des variables spéciales */
    ht_add(&hash_table_new, "$steer" , "%steer",     V_DOUBLE|V_SPECIAL);
    ht_add(&hash_table_new, "$accel" , "%accelCmd",  V_DOUBLE|V_SPECIAL);
    ht_add(&hash_table_new, "$brake" , "%brakeCmd",  V_DOUBLE|V_SPECIAL);
    ht_add(&hash_table_new, "$clutch", "%clutchCmd", V_DOUBLE|V_SPECIAL);
    ht_add(&hash_table_new, "$gear"  , "%gear",      V_INT|V_SPECIAL);


    /* Ajout des fonctions utilisables */
    ht_add(&hash_table_new, "c",             "createCanvas",             V_DOUBLE);
    ht_add(&hash_table_new, "toto",           "toto",           V_DOUBLE);
    ht_add(&hash_table_new, "square",          "square",          V_DOUBLE);
    ht_add(&hash_table_new, "mul_add",            "mul_add",            V_DOUBLE);
    ht_add(&hash_table_new, "pos_to_start",           "pos_to_start",           V_DOUBLE);
    ht_add(&hash_table_new, "track_seg_length",       "track_seg_length",       V_DOUBLE);
    ht_add(&hash_table_new, "track_seg_width",        "track_seg_width",        V_DOUBLE);
    ht_add(&hash_table_new, "track_seg_start_width",  "track_seg_start_width",  V_DOUBLE);
    ht_add(&hash_table_new, "track_seg_end_width",    "track_seg_end_width",    V_DOUBLE);
    ht_add(&hash_table_new, "track_seg_radius",       "track_seg_radius",       V_DOUBLE);
    ht_add(&hash_table_new, "track_seg_right_radius", "track_seg_right_radius", V_DOUBLE);
    ht_add(&hash_table_new, "track_seg_left_radius",  "track_seg_left_radius",  V_DOUBLE);
    ht_add(&hash_table_new, "track_seg_arc",          "track_seg_arc",          V_DOUBLE);
    ht_add(&hash_table_new, "car_angle",              "car_angle",              V_DOUBLE);
    ht_add(&hash_table_new, "norm_pi_pi",             "norm_pi_pi",             V_DOUBLE); 
    
    yyin = input;
 
    yyparse ();

    printf("%d\n",ht_exists(&hash_table_new,"toto"));

    fclose(input);
    return 0;
}
