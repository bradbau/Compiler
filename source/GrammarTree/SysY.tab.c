/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SPSEMICOLON = 258,
     SPCOMMA = 259,
     SPDOT = 260,
     SPLEFTBRACE = 261,
     SPRIGHTBRACE = 262,
     OPLEFTPRNT = 263,
     OPRIGHTPRNT = 264,
     OPLEFTBRACKET = 265,
     OPRIGHTBRACKET = 266,
     OPPLUS = 267,
     OPMINUS = 268,
     OPMULTIPLY = 269,
     OPDIVIDE = 270,
     OPMOD = 271,
     OPASSIGN = 272,
     OPAND = 273,
     OPOR = 274,
     OPNOT = 275,
     OPEQUAL = 276,
     OPNOTEQUAL = 277,
     OPGREAT = 278,
     OPLIGHT = 279,
     OPGREATEQ = 280,
     OPLIGHTEQ = 281,
     TYPEVOID = 282,
     TYPEINTEGER = 283,
     KEYCONST = 284,
     KEYIF = 285,
     KEYELSE = 286,
     KEYWHILE = 287,
     KEYBREAK = 288,
     KEYCONTINUE = 289,
     KEYRETURN = 290,
     KEYGETINT = 291,
     KEYGETCHAR = 292,
     KEYGETARRAY = 293,
     KEYPUTINT = 294,
     KEYPUTCHAR = 295,
     KEYPUTARRAY = 296,
     KEYPUTF = 297,
     KEYSTOPTIME = 298,
     KEYSTARTTIME = 299,
     CONSTANTINTD = 300,
     CONSTANTINTH = 301,
     CONSTANTOCT = 302,
     IDENTIFIER = 303
   };
#endif
/* Tokens.  */
#define SPSEMICOLON 258
#define SPCOMMA 259
#define SPDOT 260
#define SPLEFTBRACE 261
#define SPRIGHTBRACE 262
#define OPLEFTPRNT 263
#define OPRIGHTPRNT 264
#define OPLEFTBRACKET 265
#define OPRIGHTBRACKET 266
#define OPPLUS 267
#define OPMINUS 268
#define OPMULTIPLY 269
#define OPDIVIDE 270
#define OPMOD 271
#define OPASSIGN 272
#define OPAND 273
#define OPOR 274
#define OPNOT 275
#define OPEQUAL 276
#define OPNOTEQUAL 277
#define OPGREAT 278
#define OPLIGHT 279
#define OPGREATEQ 280
#define OPLIGHTEQ 281
#define TYPEVOID 282
#define TYPEINTEGER 283
#define KEYCONST 284
#define KEYIF 285
#define KEYELSE 286
#define KEYWHILE 287
#define KEYBREAK 288
#define KEYCONTINUE 289
#define KEYRETURN 290
#define KEYGETINT 291
#define KEYGETCHAR 292
#define KEYGETARRAY 293
#define KEYPUTINT 294
#define KEYPUTCHAR 295
#define KEYPUTARRAY 296
#define KEYPUTF 297
#define KEYSTOPTIME 298
#define KEYSTARTTIME 299
#define CONSTANTINTD 300
#define CONSTANTINTH 301
#define CONSTANTOCT 302
#define IDENTIFIER 303




/* Copy the first part of user declarations.  */
#line 5 "SysY.y"

    //#include<stdio.h>
    //#include<unistd.h>
    #include <iostream>
    //#include"lex.yy.cc"
    //#include "grammartree.cpp"
    #include "grammartree.h"
    using namespace std;
    //extern "C"
    
    //int yyparse();
    extern int yylineno; //共用
    extern int yylex();
    extern FILE *yyin;
    extern char *yytext;
    extern int yydebug;
    extern int yywrap(void);
    void yyerror(const char* fmt, ...);
    
    
    


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "SysY.y"
{

    class ASTTree *ast_Tree;
}
/* Line 193 of yacc.c.  */
#line 220 "SysY.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 245 "SysY.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    17,
      23,    24,    28,    33,    34,    39,    41,    44,    49,    50,
      54,    59,    62,    67,    68,    72,    74,    77,    82,    83,
      87,    93,    99,   106,   113,   116,   122,   124,   128,   129,
     134,   138,   139,   142,   144,   146,   151,   153,   156,   158,
     164,   172,   178,   181,   184,   187,   191,   193,   195,   198,
     202,   204,   206,   208,   210,   212,   214,   216,   220,   225,
     228,   230,   232,   234,   237,   238,   242,   244,   248,   252,
     256,   258,   262,   266,   268,   272,   276,   280,   284,   286,
     290,   294,   296,   300,   302,   306
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    -1,    52,    51,    -1,    53,
      -1,    65,    -1,    54,    -1,    60,    -1,    29,    28,    56,
      55,     3,    -1,    -1,    55,     4,    56,    -1,    48,    57,
      17,    58,    -1,    -1,    57,    10,    89,    11,    -1,    89,
      -1,     6,     7,    -1,     6,    58,    59,     7,    -1,    -1,
      59,     4,    58,    -1,    28,    61,    62,     3,    -1,    48,
      57,    -1,    48,    57,    17,    63,    -1,    -1,    62,     4,
      61,    -1,    73,    -1,     6,     7,    -1,     6,    63,    64,
       7,    -1,    -1,    64,     4,    63,    -1,    27,    48,     8,
       9,    69,    -1,    28,    48,     8,     9,    69,    -1,    27,
      48,     8,    67,     9,    69,    -1,    28,    48,     8,    67,
       9,    69,    -1,    28,    48,    -1,    28,    48,    10,    11,
      68,    -1,    66,    -1,    67,     4,    66,    -1,    -1,    68,
      10,    73,    11,    -1,     6,    70,     7,    -1,    -1,    71,
      70,    -1,    53,    -1,    72,    -1,    75,    17,    73,     3,
      -1,     3,    -1,    73,     3,    -1,    69,    -1,    30,     8,
      74,     9,    72,    -1,    30,     8,    74,     9,    72,    31,
      72,    -1,    32,     8,    74,     9,    72,    -1,    33,     3,
      -1,    34,     3,    -1,    35,     3,    -1,    35,    73,     3,
      -1,    84,    -1,    88,    -1,    48,    68,    -1,     8,    73,
       9,    -1,    75,    -1,    77,    -1,    78,    -1,    47,    -1,
      45,    -1,    46,    -1,    76,    -1,    48,     8,     9,    -1,
      48,     8,    81,     9,    -1,    80,    79,    -1,    12,    -1,
      13,    -1,    20,    -1,    73,    82,    -1,    -1,    82,     4,
      73,    -1,    79,    -1,    83,    14,    79,    -1,    83,    15,
      79,    -1,    83,    16,    79,    -1,    83,    -1,    84,    12,
      83,    -1,    84,    13,    83,    -1,    84,    -1,    85,    24,
      84,    -1,    85,    23,    84,    -1,    85,    25,    84,    -1,
      85,    26,    84,    -1,    85,    -1,    86,    21,    85,    -1,
      86,    22,    85,    -1,    86,    -1,    87,    18,    86,    -1,
      87,    -1,    88,    19,    87,    -1,    84,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    69,    70,    72,    73,    76,    77,    81,
      84,    85,    88,    90,    91,    94,    95,    96,    99,   100,
     104,   107,   108,   110,   111,   114,   115,   116,   119,   120,
     124,   125,   126,   127,   131,   132,   135,   136,   139,   140,
     143,   146,   147,   150,   151,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   169,   173,   176,   179,
     180,   181,   184,   187,   188,   189,   192,   193,   194,   195,
     199,   200,   201,   204,   207,   208,   211,   212,   213,   214,
     217,   218,   219,   222,   223,   224,   225,   226,   229,   230,
     231,   234,   235,   238,   239,   242
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SPSEMICOLON", "SPCOMMA", "SPDOT",
  "SPLEFTBRACE", "SPRIGHTBRACE", "OPLEFTPRNT", "OPRIGHTPRNT",
  "OPLEFTBRACKET", "OPRIGHTBRACKET", "OPPLUS", "OPMINUS", "OPMULTIPLY",
  "OPDIVIDE", "OPMOD", "OPASSIGN", "OPAND", "OPOR", "OPNOT", "OPEQUAL",
  "OPNOTEQUAL", "OPGREAT", "OPLIGHT", "OPGREATEQ", "OPLIGHTEQ", "TYPEVOID",
  "TYPEINTEGER", "KEYCONST", "KEYIF", "KEYELSE", "KEYWHILE", "KEYBREAK",
  "KEYCONTINUE", "KEYRETURN", "KEYGETINT", "KEYGETCHAR", "KEYGETARRAY",
  "KEYPUTINT", "KEYPUTCHAR", "KEYPUTARRAY", "KEYPUTF", "KEYSTOPTIME",
  "KEYSTARTTIME", "CONSTANTINTD", "CONSTANTINTH", "CONSTANTOCT",
  "IDENTIFIER", "$accept", "Compiler", "CompUnits", "CompUnit", "Decl",
  "ConstDecl", "ConstDefs", "ConstDef", "ArrayDef", "ConstInitVal",
  "ConstInitValList", "VarDecl", "VarDef", "VarDefs", "InitVal",
  "InitVals", "FuncDef", "FuncFParam", "FuncFParams", "ArrayExps", "Block",
  "BlockItems", "BlockItem", "Stmt", "Exp", "Cond", "LVal", "PrimaryExp",
  "Number", "IntConst", "UnaryExp", "UnaryOp", "FuncRParams", "Exps",
  "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      55,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    74,    75,    76,
      76,    76,    77,    78,    78,    78,    79,    79,    79,    79,
      80,    80,    80,    81,    82,    82,    83,    83,    83,    83,
      84,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      86,    87,    87,    88,    88,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     5,
       0,     3,     4,     0,     4,     1,     2,     4,     0,     3,
       4,     2,     4,     0,     3,     1,     2,     4,     0,     3,
       5,     5,     6,     6,     2,     5,     1,     3,     0,     4,
       3,     0,     2,     1,     1,     4,     1,     2,     1,     5,
       7,     5,     2,     2,     2,     3,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     2,
       1,     1,     1,     2,     0,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     2,     3,     5,     7,     8,
       6,     0,    13,    23,     0,     1,     4,     0,     0,    21,
       0,    13,    10,     0,     0,    36,     0,     0,     0,     0,
       0,    20,     0,     0,     0,    41,    30,    34,     0,     0,
      31,     0,     0,    70,    71,    72,    64,    65,    63,    38,
      60,    66,    61,    62,    76,     0,    80,    95,     0,     0,
      22,    25,    56,    13,    24,     0,     9,     0,    46,     0,
       0,     0,     0,     0,     0,    43,    48,     0,    41,    44,
       0,    60,     0,    37,    32,    33,     0,     0,    58,    69,
       0,     0,     0,     0,     0,    14,    26,    28,     0,    12,
      15,    11,     0,     0,    52,    53,    54,     0,    40,    42,
      47,     0,    38,    59,    67,    74,     0,     0,    77,    78,
      79,    81,    82,     0,    16,    18,     0,    83,    88,    91,
      93,    57,     0,    55,     0,    35,    73,    68,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,    39,    29,     0,    17,    49,    85,
      84,    86,    87,    89,    90,    92,    94,    51,    75,    19,
       0,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    34,    22,    19,    99,
     141,     9,    13,    20,    60,   123,    10,    25,    26,    88,
      76,    77,    78,    79,    80,   126,    50,    51,    52,    53,
      54,    55,   116,   136,    56,    62,   128,   129,   130,   131,
     100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -137
static const yytype_int16 yypact[] =
{
      57,   -41,   -30,    -8,    30,  -137,    57,  -137,  -137,  -137,
    -137,    37,    61,  -137,    23,  -137,  -137,    -4,     1,     2,
      33,  -137,  -137,    72,    26,  -137,     7,    72,    13,   202,
     153,  -137,    42,    25,    60,    20,  -137,    78,    54,    72,
    -137,    72,   202,  -137,  -137,  -137,  -137,  -137,  -137,    90,
    -137,  -137,  -137,  -137,  -137,   202,    89,    48,    95,   133,
    -137,  -137,    48,  -137,  -137,   196,  -137,    23,  -137,    42,
     102,   118,   128,   130,   124,  -137,  -137,   127,    20,  -137,
     135,   125,   132,  -137,  -137,  -137,   138,   183,   141,  -137,
     202,   202,   202,   202,   202,  -137,  -137,  -137,   142,  -137,
    -137,  -137,   202,   202,  -137,  -137,  -137,   149,  -137,  -137,
    -137,   202,  -137,  -137,  -137,  -137,   147,   202,  -137,  -137,
    -137,    89,    89,    34,  -137,  -137,   148,    48,    68,    74,
     140,   144,   151,  -137,   161,   141,   163,  -137,   157,   153,
    -137,    40,    67,   202,   202,   202,   202,   202,   202,   202,
     202,    67,  -137,   202,  -137,  -137,   196,  -137,   143,    48,
      48,    48,    48,    68,    68,    74,   140,  -137,  -137,  -137,
      67,  -137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   169,  -137,   -27,  -137,  -137,   109,   156,   -94,
    -137,  -137,   150,  -137,   -58,  -137,  -137,   145,   166,    73,
     -14,   108,  -137,  -136,   -28,    91,   -35,  -137,  -137,  -137,
     -34,  -137,  -137,  -137,    15,   -26,   -19,    44,    47,  -137,
     176
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      81,    97,    61,    57,   125,    23,   158,    11,    75,    36,
      27,    38,    29,    40,    86,   167,    39,    38,    12,    30,
      14,    89,    41,    68,    24,    84,    35,    85,    42,    24,
      15,    61,    43,    44,   171,    29,    31,    32,   139,    57,
      45,   140,    65,    81,   156,    17,   107,   157,    69,     3,
      70,    75,    71,    72,    73,    74,   118,   119,   120,   115,
      93,    94,   169,    66,    67,    46,    47,    48,    49,    18,
      68,    21,    57,    35,    37,    42,   127,   127,    35,    43,
      44,   155,    24,   134,     1,     2,     3,    45,    82,   138,
      63,   143,   144,   145,   146,   147,   148,    70,    87,    71,
      72,    73,    74,    90,    91,    92,    95,    81,   121,   122,
     102,    61,    46,    47,    48,    49,    81,   159,   160,   161,
     162,   127,   127,   127,   127,   168,   103,   106,   163,   164,
      57,   104,    42,   105,   108,    81,    43,    44,   110,    59,
      96,    42,   111,   112,    45,    43,    44,   113,    98,   124,
      42,   117,   133,    45,    43,    44,   137,   142,   149,    59,
     151,    42,    45,   150,   152,    43,    44,   153,   154,    46,
      47,    48,    49,    45,   170,    16,   101,    33,    46,    47,
      48,    49,    64,    83,    28,   135,   109,    46,    47,    48,
      49,    42,   114,   165,   132,    43,    44,   166,    46,    47,
      48,    49,    98,    45,    42,    58,     0,     0,    43,    44,
      42,     0,     0,     0,    43,    44,    45,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,    46,    47,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,    48,    49,     0,     0,    46,    47,    48,
      49
};

static const yytype_int16 yycheck[] =
{
      35,    59,    30,    29,    98,     9,   142,    48,    35,    23,
       9,     4,    10,    27,    42,   151,     9,     4,    48,    17,
      28,    55,     9,     3,    28,    39,     6,    41,     8,    28,
       0,    59,    12,    13,   170,    10,     3,     4,     4,    65,
      20,     7,    17,    78,     4,     8,    74,     7,    28,    29,
      30,    78,    32,    33,    34,    35,    90,    91,    92,    87,
      12,    13,   156,     3,     4,    45,    46,    47,    48,     8,
       3,    48,    98,     6,    48,     8,   102,   103,     6,    12,
      13,   139,    28,   111,    27,    28,    29,    20,    10,   117,
      48,    23,    24,    25,    26,    21,    22,    30,     8,    32,
      33,    34,    35,    14,    15,    16,    11,   142,    93,    94,
       8,   139,    45,    46,    47,    48,   151,   143,   144,   145,
     146,   147,   148,   149,   150,   153,     8,     3,   147,   148,
     156,     3,     8,     3,     7,   170,    12,    13,     3,     6,
       7,     8,    17,    11,    20,    12,    13,     9,     6,     7,
       8,    10,     3,    20,    12,    13,     9,     9,    18,     6,
       9,     8,    20,    19,     3,    12,    13,     4,    11,    45,
      46,    47,    48,    20,    31,     6,    67,    21,    45,    46,
      47,    48,    32,    38,    18,   112,    78,    45,    46,    47,
      48,     8,     9,   149,   103,    12,    13,   150,    45,    46,
      47,    48,     6,    20,     8,    29,    -1,    -1,    12,    13,
       8,    -1,    -1,    -1,    12,    13,    20,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    -1,    -1,    45,    46,    47,
      48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    28,    29,    50,    51,    52,    53,    54,    60,
      65,    48,    48,    61,    28,     0,    51,     8,     8,    57,
      62,    48,    56,     9,    28,    66,    67,     9,    67,    10,
      17,     3,     4,    57,    55,     6,    69,    48,     4,     9,
      69,     9,     8,    12,    13,    20,    45,    46,    47,    48,
      75,    76,    77,    78,    79,    80,    83,    84,    89,     6,
      63,    73,    84,    48,    61,    17,     3,     4,     3,    28,
      30,    32,    33,    34,    35,    53,    69,    70,    71,    72,
      73,    75,    10,    66,    69,    69,    73,     8,    68,    79,
      14,    15,    16,    12,    13,    11,     7,    63,     6,    58,
      89,    56,     8,     8,     3,     3,     3,    73,     7,    70,
       3,    17,    11,     9,     9,    73,    81,    10,    79,    79,
      79,    83,    83,    64,     7,    58,    74,    84,    85,    86,
      87,    88,    74,     3,    73,    68,    82,     9,    73,     4,
       7,    59,     9,    23,    24,    25,    26,    21,    22,    18,
      19,     9,     3,     4,    11,    63,     4,     7,    72,    84,
      84,    84,    84,    85,    85,    86,    87,    72,    73,    58,
      31,    72
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 67 "SysY.y"
    { ASTTree *asttree = new ASTTree("Compiler", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; asttree->TraverseGrammerTree(0);;}
    break;

  case 3:
#line 69 "SysY.y"
    { ASTTree *asttree = new ASTTree("CompUnit",0, -1);(yyval.ast_Tree) = asttree;;}
    break;

  case 4:
#line 70 "SysY.y"
    { ASTTree *asttree = new ASTTree("CompUnits", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 5:
#line 72 "SysY.y"
    { ASTTree *asttree = new ASTTree("CompUnit", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree;;}
    break;

  case 6:
#line 73 "SysY.y"
    { ASTTree *asttree = new ASTTree("CompUnit", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 7:
#line 76 "SysY.y"
    { ASTTree *asttree = new ASTTree("Decl", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 8:
#line 77 "SysY.y"
    { ASTTree *asttree = new ASTTree("Decl", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 9:
#line 81 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstDecl", 5, (yyvsp[(1) - (5)].ast_Tree), (yyvsp[(2) - (5)].ast_Tree),(yyvsp[(3) - (5)].ast_Tree),(yyvsp[(4) - (5)].ast_Tree),(yyvsp[(5) - (5)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 10:
#line 84 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstDefs", 0, -1);(yyval.ast_Tree) = asttree; ;}
    break;

  case 11:
#line 85 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstDefs", 3, (yyvsp[(1) - (3)].ast_Tree), (yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 12:
#line 88 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstDef", 4, (yyvsp[(1) - (4)].ast_Tree), (yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 13:
#line 90 "SysY.y"
    { ASTTree *asttree = new ASTTree("ArrayDef", 0, -1);(yyval.ast_Tree) = asttree; ;}
    break;

  case 14:
#line 91 "SysY.y"
    { ASTTree *asttree = new ASTTree("ArrayDef", 4, (yyvsp[(1) - (4)].ast_Tree), (yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 15:
#line 94 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstInitVal", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 16:
#line 95 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstInitVal", 2, (yyvsp[(1) - (2)].ast_Tree), (yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 17:
#line 96 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstInitVal", 4, (yyvsp[(1) - (4)].ast_Tree), (yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 18:
#line 99 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstInitValList", 0, -1);(yyval.ast_Tree) = asttree; ;}
    break;

  case 19:
#line 100 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstInitValList", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 20:
#line 104 "SysY.y"
    { ASTTree *asttree = new ASTTree("VarDecl", 4, (yyvsp[(1) - (4)].ast_Tree),(yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 21:
#line 107 "SysY.y"
    { ASTTree *asttree = new ASTTree("VarDef", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 22:
#line 108 "SysY.y"
    { ASTTree *asttree = new ASTTree("VarDef", 4, (yyvsp[(1) - (4)].ast_Tree),(yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 23:
#line 110 "SysY.y"
    { ASTTree *asttree = new ASTTree("VarDefs", 0, -1);(yyval.ast_Tree) = asttree; ;}
    break;

  case 24:
#line 111 "SysY.y"
    { ASTTree *asttree = new ASTTree("VarDefs", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 25:
#line 114 "SysY.y"
    { ASTTree *asttree = new ASTTree("InitVal", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 26:
#line 115 "SysY.y"
    { ASTTree *asttree = new ASTTree("InitVal", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 27:
#line 116 "SysY.y"
    { ASTTree *asttree = new ASTTree("InitVal", 4, (yyvsp[(1) - (4)].ast_Tree),(yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 28:
#line 119 "SysY.y"
    { ASTTree *asttree = new ASTTree("InitVals", 0, -1);(yyval.ast_Tree) = asttree; ;}
    break;

  case 29:
#line 120 "SysY.y"
    { ASTTree *asttree = new ASTTree("InitVals", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 30:
#line 124 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncDef", 5, (yyvsp[(1) - (5)].ast_Tree),(yyvsp[(2) - (5)].ast_Tree),(yyvsp[(3) - (5)].ast_Tree),(yyvsp[(4) - (5)].ast_Tree),(yyvsp[(5) - (5)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 31:
#line 125 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncDef", 5, (yyvsp[(1) - (5)].ast_Tree),(yyvsp[(2) - (5)].ast_Tree),(yyvsp[(3) - (5)].ast_Tree),(yyvsp[(4) - (5)].ast_Tree),(yyvsp[(5) - (5)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 32:
#line 126 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncDef", 6, (yyvsp[(1) - (6)].ast_Tree),(yyvsp[(2) - (6)].ast_Tree),(yyvsp[(3) - (6)].ast_Tree),(yyvsp[(4) - (6)].ast_Tree),(yyvsp[(5) - (6)].ast_Tree),(yyvsp[(6) - (6)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 33:
#line 127 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncDef", 6, (yyvsp[(1) - (6)].ast_Tree),(yyvsp[(2) - (6)].ast_Tree),(yyvsp[(3) - (6)].ast_Tree),(yyvsp[(4) - (6)].ast_Tree),(yyvsp[(5) - (6)].ast_Tree),(yyvsp[(6) - (6)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 34:
#line 131 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncFParam", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 35:
#line 132 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncFParam", 5, (yyvsp[(1) - (5)].ast_Tree),(yyvsp[(2) - (5)].ast_Tree),(yyvsp[(3) - (5)].ast_Tree),(yyvsp[(4) - (5)].ast_Tree),(yyvsp[(5) - (5)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 36:
#line 135 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncFParams", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 37:
#line 136 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncFParams", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 38:
#line 139 "SysY.y"
    { ASTTree *asttree = new ASTTree("ArrayExps", 0, -1);(yyval.ast_Tree) = asttree; ;}
    break;

  case 39:
#line 140 "SysY.y"
    { ASTTree *asttree = new ASTTree("ArrayExps", 4, (yyvsp[(1) - (4)].ast_Tree),(yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 40:
#line 143 "SysY.y"
    { ASTTree *asttree = new ASTTree("Block", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 41:
#line 146 "SysY.y"
    { ASTTree *asttree = new ASTTree("BlockItems", 0, -1);(yyval.ast_Tree) = asttree; ;}
    break;

  case 42:
#line 147 "SysY.y"
    { ASTTree *asttree = new ASTTree("BlockItems", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 43:
#line 150 "SysY.y"
    { ASTTree *asttree = new ASTTree("BlockItem", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 44:
#line 151 "SysY.y"
    { ASTTree *asttree = new ASTTree("BlockItem", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 45:
#line 154 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 4, (yyvsp[(1) - (4)].ast_Tree),(yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 46:
#line 155 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 47:
#line 156 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 48:
#line 157 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 49:
#line 158 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 5, (yyvsp[(1) - (5)].ast_Tree),(yyvsp[(2) - (5)].ast_Tree),(yyvsp[(3) - (5)].ast_Tree),(yyvsp[(4) - (5)].ast_Tree),(yyvsp[(5) - (5)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 50:
#line 159 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 7,(yyvsp[(1) - (7)].ast_Tree),(yyvsp[(2) - (7)].ast_Tree),(yyvsp[(3) - (7)].ast_Tree),(yyvsp[(4) - (7)].ast_Tree),(yyvsp[(5) - (7)].ast_Tree),(yyvsp[(6) - (7)].ast_Tree),(yyvsp[(7) - (7)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 51:
#line 160 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 5,  (yyvsp[(1) - (5)].ast_Tree),(yyvsp[(2) - (5)].ast_Tree),(yyvsp[(3) - (5)].ast_Tree),(yyvsp[(4) - (5)].ast_Tree),(yyvsp[(5) - (5)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 52:
#line 161 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 53:
#line 162 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 54:
#line 163 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 55:
#line 164 "SysY.y"
    { ASTTree *asttree = new ASTTree("Stmt", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 56:
#line 169 "SysY.y"
    { ASTTree *asttree = new ASTTree("Exp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 57:
#line 173 "SysY.y"
    { ASTTree *asttree = new ASTTree("Cond", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 58:
#line 176 "SysY.y"
    { ASTTree *asttree = new ASTTree("LVal", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 59:
#line 179 "SysY.y"
    { ASTTree *asttree = new ASTTree("PrimaryExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 60:
#line 180 "SysY.y"
    { ASTTree *asttree = new ASTTree("PrimaryExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 61:
#line 181 "SysY.y"
    { ASTTree *asttree = new ASTTree("PrimaryExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 62:
#line 184 "SysY.y"
    { ASTTree *asttree = new ASTTree("Number", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 63:
#line 187 "SysY.y"
    { ASTTree *asttree = new ASTTree("IntConst", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 64:
#line 188 "SysY.y"
    { ASTTree *asttree = new ASTTree("IntConst", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 65:
#line 189 "SysY.y"
    { ASTTree *asttree = new ASTTree("IntConst", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 66:
#line 192 "SysY.y"
    { ASTTree *asttree = new ASTTree("UnaryExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 67:
#line 193 "SysY.y"
    { ASTTree *asttree = new ASTTree("UnaryExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 68:
#line 194 "SysY.y"
    { ASTTree *asttree = new ASTTree("UnaryExp", 4, (yyvsp[(1) - (4)].ast_Tree),(yyvsp[(2) - (4)].ast_Tree),(yyvsp[(3) - (4)].ast_Tree),(yyvsp[(4) - (4)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 69:
#line 195 "SysY.y"
    { ASTTree *asttree = new ASTTree("UnaryExp", 2, (yyvsp[(1) - (2)].ast_Tree),(yyvsp[(2) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 70:
#line 199 "SysY.y"
    { ASTTree *asttree = new ASTTree("UnaryOp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 71:
#line 200 "SysY.y"
    { ASTTree *asttree = new ASTTree("UnaryOp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 72:
#line 201 "SysY.y"
    { ASTTree *asttree = new ASTTree("UnaryOp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 73:
#line 204 "SysY.y"
    { ASTTree *asttree = new ASTTree("FuncRParams", 1, (yyvsp[(1) - (2)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 74:
#line 207 "SysY.y"
    { ASTTree *asttree = new ASTTree("Exps", 0, -1);(yyval.ast_Tree) = asttree; ;}
    break;

  case 75:
#line 208 "SysY.y"
    { ASTTree *asttree = new ASTTree("Exps", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 76:
#line 211 "SysY.y"
    { ASTTree *asttree = new ASTTree("MulExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 77:
#line 212 "SysY.y"
    { ASTTree *asttree = new ASTTree("MulExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 78:
#line 213 "SysY.y"
    { ASTTree *asttree = new ASTTree("MulExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 79:
#line 214 "SysY.y"
    { ASTTree *asttree = new ASTTree("MulExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 80:
#line 217 "SysY.y"
    { ASTTree *asttree = new ASTTree("AddExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 81:
#line 218 "SysY.y"
    { ASTTree *asttree = new ASTTree("AddExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 82:
#line 219 "SysY.y"
    { ASTTree *asttree = new ASTTree("AddExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 83:
#line 222 "SysY.y"
    { ASTTree *asttree = new ASTTree("RelExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 84:
#line 223 "SysY.y"
    { ASTTree *asttree = new ASTTree("RelExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 85:
#line 224 "SysY.y"
    { ASTTree *asttree = new ASTTree("RelExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 86:
#line 225 "SysY.y"
    { ASTTree *asttree = new ASTTree("RelExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 87:
#line 226 "SysY.y"
    { ASTTree *asttree = new ASTTree("RelExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 88:
#line 229 "SysY.y"
    { ASTTree *asttree = new ASTTree("EqExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 89:
#line 230 "SysY.y"
    { ASTTree *asttree = new ASTTree("EqExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 90:
#line 231 "SysY.y"
    { ASTTree *asttree = new ASTTree("EqExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 91:
#line 234 "SysY.y"
    { ASTTree *asttree = new ASTTree("LAndExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 92:
#line 235 "SysY.y"
    { ASTTree *asttree = new ASTTree("LAndExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 93:
#line 238 "SysY.y"
    { ASTTree *asttree = new ASTTree("LOrExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 94:
#line 239 "SysY.y"
    { ASTTree *asttree = new ASTTree("LOrExp", 3, (yyvsp[(1) - (3)].ast_Tree),(yyvsp[(2) - (3)].ast_Tree),(yyvsp[(3) - (3)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;

  case 95:
#line 242 "SysY.y"
    { ASTTree *asttree = new ASTTree("ConstExp", 1, (yyvsp[(1) - (1)].ast_Tree));(yyval.ast_Tree) = asttree; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2116 "SysY.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 245 "SysY.y"


#include<stdarg.h>


int main(int argc, char *argv[]){
        //extern int yyparse(void);
        //extern int yylex(void);
	yyin=fopen(argv[1],"r");
	if (!yyin) return -1;
	yylineno=1;
	yyparse();
	return 0;
}
void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Error type B at Line %d Column %d: ", yylineno, yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}

