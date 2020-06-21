/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "SysY.y" /* yacc.c:339  */


    #include <iostream>
    #include "AST.h"
    using namespace std;

    extern int yylineno; //共用
    extern int yylex();
    extern FILE *yyin;
    extern char *yytext;
    extern int yydebug;
    extern int yywrap(void);
    void yyerror(const char* fmt, ...);
    

#line 82 "SysY.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SysY.tab.h".  */
#ifndef YY_YY_SYSY_TAB_H_INCLUDED
# define YY_YY_SYSY_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    STRING = 303,
    IDENTIFIER = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "SysY.y" /* yacc.c:355  */


    class ASTTree *ast_Tree;

#line 177 "SysY.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYSY_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "SysY.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    62,    63,    66,    67,    68,    71,    72,
      75,    76,    80,    83,    84,    88,    89,    90,    93,    94,
      98,    99,   102,   103,   107,   108,   111,   112,   113,   116,
     117,   120,   123,   124,   127,   128,   132,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   149,   150,
     151,   155,   156,   157,   158,   159,   162,   163,   164,   168,
     169,   170,   173,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   194,   195
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
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
  "KEYSTARTTIME", "CONSTANTINTD", "CONSTANTINTH", "CONSTANTOCT", "STRING",
  "IDENTIFIER", "$accept", "Compiler", "CompUnits", "CompUnit", "Decl",
  "ConstDefs", "ConstDef", "VarDec", "InitVal", "InitValList", "VarDef",
  "VarDefs", "FuncFParam", "FuncFParams", "ArrayExps", "Block",
  "BlockItems", "BlockItem", "LVal", "Stmt", "Cond", "RelExp", "EqExp",
  "Number", "FuncRParams", "Exp", "Exps", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,   -32,     5,    39,    72,  -126,    23,  -126,    73,    79,
      17,    85,    31,  -126,  -126,    62,    62,   192,   179,    31,
      88,  -126,    97,    38,    43,    99,    95,   107,   192,   192,
     192,   192,  -126,  -126,  -126,  -126,    76,  -126,  -126,   239,
     135,  -126,   163,    85,  -126,    31,   114,   179,   113,    62,
     120,   120,   233,    60,    60,  -126,   149,   192,  -126,  -126,
     192,   192,   192,   192,   192,  -126,   126,  -126,    97,  -126,
    -126,   118,  -126,    65,  -126,  -126,  -126,  -126,   131,   217,
     245,    60,    60,  -126,  -126,  -126,   179,   127,  -126,   134,
    -126,    31,   138,   142,   132,   153,   125,  -126,  -126,   152,
      65,   143,  -126,    50,  -126,   192,  -126,   134,   126,  -126,
    -126,   192,   192,  -126,  -126,  -126,    93,  -126,  -126,   192,
    -126,   217,  -126,  -126,     0,    34,    10,   163,     6,  -126,
     203,  -126,   119,   192,   192,   192,   192,   192,   192,   192,
     192,   119,  -126,   155,  -126,   145,   163,   163,   163,   163,
      34,    34,  -126,   119,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     2,     3,     5,     0,    13,
      20,    22,     0,     1,     4,    26,    26,     0,     0,     0,
       0,    13,    10,     0,     0,    27,     0,     0,     0,     0,
       0,     0,    60,    61,    59,    65,    29,    64,    66,     0,
       0,    21,    15,    22,     9,     0,     0,     0,    24,    26,
       0,     0,     0,    69,    70,    71,     0,     0,    36,    14,
       0,     0,     0,     0,     0,    16,    18,    23,    10,     8,
      12,     0,    28,    32,     6,     7,    63,    67,     0,    77,
       0,    75,    76,    72,    73,    74,     0,     0,    11,    29,
      38,     0,     0,     0,     0,     0,     0,    34,    40,     0,
      32,    64,    35,     0,    68,     0,    62,    29,    18,    17,
      25,     0,     0,    44,    45,    46,     0,    31,    33,     0,
      39,    77,    30,    19,     0,    56,    48,    51,     0,    47,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    41,    49,    50,    53,    52,    54,    55,
      57,    58,    43,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,   182,  -126,   -67,   121,   148,    -8,   -37,    82,
     183,   158,  -126,   -11,   -81,   -29,   103,  -126,   -71,  -125,
     -92,  -104,  -126,  -126,  -126,   -17,    86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    46,    22,    10,    41,    87,
      11,    20,    25,    26,    58,    98,    99,   100,    37,   102,
     124,   125,   126,    38,    78,   127,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    42,   101,    66,    23,    27,    97,   143,   110,   132,
      70,    52,    53,    54,    55,   141,   152,     8,   133,   134,
     128,    74,    75,    42,   133,   134,   122,    17,   154,   101,
      42,   139,   140,    97,    18,   150,   151,    23,    72,    79,
      80,   144,   145,    81,    82,    83,    84,    85,    17,   108,
       1,     2,     3,   120,     9,    47,   103,   135,   136,   137,
     138,   101,    60,    61,    62,    63,    64,    12,    90,    42,
     101,    73,    13,    28,    62,    63,    64,    29,    30,   116,
      21,    15,   101,   103,    56,    31,    57,    16,   121,    19,
      24,    44,    48,    91,     3,    92,   129,    93,    94,    95,
      96,    45,   130,    49,    50,    60,    61,    62,    63,    64,
      32,    33,    34,    35,    36,   103,    51,    69,   146,   147,
     148,   149,    90,    71,   103,    73,    73,    28,   115,    89,
      86,    29,    30,    28,   109,   113,   103,    29,    30,    31,
     104,    40,    65,    28,    57,    31,   111,    29,    30,    92,
     112,    93,    94,    95,    96,    31,   114,    28,    77,   117,
     119,    29,    30,   133,    32,    33,    34,    35,    36,    31,
      32,    33,    34,    35,    36,    60,    61,    62,    63,    64,
      32,    33,    34,    35,    36,    40,   153,    28,    14,    88,
     123,    29,    30,    68,    32,    33,    34,    35,    36,    31,
      28,    67,    43,   118,    29,    30,   142,   131,     0,     0,
       0,     0,    31,     0,     0,    60,    61,    62,    63,    64,
       0,   105,     0,     0,    32,    33,    34,    35,    36,    60,
      61,    62,    63,    64,     0,     0,     0,    32,    33,    34,
      35,    36,    76,     0,     0,    60,    61,    62,    63,    64,
      59,    60,    61,    62,    63,    64,   107,    60,    61,    62,
      63,    64
};

static const yytype_int16 yycheck[] =
{
      17,    18,    73,    40,    12,    16,    73,   132,    89,     9,
      47,    28,    29,    30,    31,     9,   141,    49,    18,    19,
     112,    50,    51,    40,    18,    19,   107,    10,   153,   100,
      47,    21,    22,   100,    17,   139,   140,    45,    49,    56,
      57,   133,   134,    60,    61,    62,    63,    64,    10,    86,
      27,    28,    29,     3,    49,    17,    73,    23,    24,    25,
      26,   132,    12,    13,    14,    15,    16,    28,     3,    86,
     141,     6,     0,     8,    14,    15,    16,    12,    13,    96,
      49,     8,   153,   100,     8,    20,    10,     8,   105,     4,
      28,     3,    49,    28,    29,    30,     3,    32,    33,    34,
      35,     4,   119,     4,     9,    12,    13,    14,    15,    16,
      45,    46,    47,    48,    49,   132,     9,     3,   135,   136,
     137,   138,     3,    10,   141,     6,     6,     8,     3,    11,
       4,    12,    13,     8,     7,     3,   153,    12,    13,    20,
       9,     6,     7,     8,    10,    20,     8,    12,    13,    30,
       8,    32,    33,    34,    35,    20,     3,     8,     9,     7,
      17,    12,    13,    18,    45,    46,    47,    48,    49,    20,
      45,    46,    47,    48,    49,    12,    13,    14,    15,    16,
      45,    46,    47,    48,    49,     6,    31,     8,     6,    68,
     108,    12,    13,    45,    45,    46,    47,    48,    49,    20,
       8,    43,    19,   100,    12,    13,     3,   121,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    12,    13,    14,    15,    16,
      -1,     4,    -1,    -1,    45,    46,    47,    48,    49,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    45,    46,    47,
      48,    49,     9,    -1,    -1,    12,    13,    14,    15,    16,
      11,    12,    13,    14,    15,    16,    11,    12,    13,    14,
      15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    28,    29,    51,    52,    53,    54,    49,    49,
      57,    60,    28,     0,    52,     8,     8,    10,    17,     4,
      61,    49,    56,    57,    28,    62,    63,    63,     8,    12,
      13,    20,    45,    46,    47,    48,    49,    68,    73,    75,
       6,    58,    75,    60,     3,     4,    55,    17,    49,     4,
       9,     9,    75,    75,    75,    75,     8,    10,    64,    11,
      12,    13,    14,    15,    16,     7,    58,    61,    56,     3,
      58,    10,    63,     6,    65,    65,     9,     9,    74,    75,
      75,    75,    75,    75,    75,    75,     4,    59,    55,    11,
       3,    28,    30,    32,    33,    34,    35,    54,    65,    66,
      67,    68,    69,    75,     9,     4,    76,    11,    58,     7,
      64,     8,     8,     3,     3,     3,    75,     7,    66,    17,
       3,    75,    64,    59,    70,    71,    72,    75,    70,     3,
      75,    76,     9,    18,    19,    23,    24,    25,    26,    21,
      22,     9,     3,    69,    70,    70,    75,    75,    75,    75,
      71,    71,    69,    31,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    65,    66,    66,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    71,    71,    71,    71,    71,    72,    72,    72,    73,
      73,    73,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     6,     6,     5,     4,
       0,     3,     3,     1,     4,     1,     2,     4,     0,     3,
       1,     3,     0,     3,     2,     5,     0,     1,     3,     0,
       4,     3,     0,     2,     1,     1,     2,     4,     1,     2,
       1,     5,     7,     5,     2,     2,     2,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       1,     1,     2,     3,     1,     1,     1,     3,     4,     2,
       2,     2,     3,     3,     3,     3,     3,     0,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 60 "SysY.y" /* yacc.c:1646  */
    {  ASTTree *asttree = new ASTTree("Compiler", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree;(yyval.ast_Tree)->TraverseGrammerTree(0);}
#line 1511 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = NULL;}
#line 1517 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 63 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("CompUnits", 2, yylineno, (yyvsp[-1].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1523 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "SysY.y" /* yacc.c:1646  */
    {(yyval.ast_Tree)=(yyvsp[0].ast_Tree);}
#line 1529 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 67 "SysY.y" /* yacc.c:1646  */
    { printf("funcdef1\n");ASTTree *asttree = new ASTTree("voidFuncDef", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; (yyval.ast_Tree)->SetFuncType("void");(yyval.ast_Tree)->SetID((yyvsp[-4].ast_Tree)->GetID());}
#line 1535 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 68 "SysY.y" /* yacc.c:1646  */
    {printf("funcdef2\n"); ASTTree *asttree = new ASTTree("intFuncDef", 2, yylineno,(yyvsp[-2].ast_Tree), (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; (yyval.ast_Tree)->SetFuncType("int");(yyval.ast_Tree)->SetID((yyvsp[-4].ast_Tree)->GetID()); }
#line 1541 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 71 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("ConstDecl", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1547 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 72 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("VarDecl", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1553 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 75 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = NULL;}
#line 1559 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("ConstDefs", 2, yylineno, (yyvsp[-1].ast_Tree), (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1565 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("ConstOpassign", 2, yylineno, (yyvsp[-2].ast_Tree), (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1571 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 83 "SysY.y" /* yacc.c:1646  */
    {(yyval.ast_Tree) = (yyvsp[0].ast_Tree);}
#line 1577 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 84 "SysY.y" /* yacc.c:1646  */
    {ASTTree *asttree = new ASTTree("ArrayDec", 1, yylineno, (yyvsp[-3].ast_Tree));(yyval.ast_Tree) = asttree;(yyval.ast_Tree)->SetIntValue((yyvsp[-1].ast_Tree)->GetIntValue());}
#line 1583 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("ConstInitVal", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1589 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("ConstInitVal", 0, yylineno);(yyval.ast_Tree) = asttree; }
#line 1595 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("ConstInitVal", 2, yylineno,  (yyvsp[-2].ast_Tree),(yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1601 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 93 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = NULL;}
#line 1607 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("ConstInitValList", 2, yylineno, (yyvsp[-1].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1613 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "SysY.y" /* yacc.c:1646  */
    {(yyval.ast_Tree) = (yyvsp[0].ast_Tree);}
#line 1619 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 99 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("VarOPassign", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1625 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 102 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = NULL;}
#line 1631 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 103 "SysY.y" /* yacc.c:1646  */
    { printf("VarDefs\n");ASTTree *asttree = new ASTTree("VarDefs", 2, yylineno, (yyvsp[-1].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1637 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 107 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("FuncFParam", 0, yylineno);(yyval.ast_Tree) = asttree;(yyval.ast_Tree)->SetFuncPType("int");(yyval.ast_Tree)->SetID((yyvsp[0].ast_Tree)->GetID()); }
#line 1643 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 108 "SysY.y" /* yacc.c:1646  */
    { printf("array\n");ASTTree *asttree = new ASTTree("FuncFParam", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree;printf("array2\n");(yyval.ast_Tree)->SetFuncPType("array");printf("array3\n");(yyval.ast_Tree)->SetID((yyvsp[-3].ast_Tree)->GetID()); }
#line 1649 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 111 "SysY.y" /* yacc.c:1646  */
    { printf("kong\n");ASTTree *asttree = new ASTTree("FuncFParams", 0, yylineno);(yyval.ast_Tree) = asttree;}
#line 1655 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 112 "SysY.y" /* yacc.c:1646  */
    {printf("fp\n");ASTTree *asttree = new ASTTree("FuncFParams", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1661 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 113 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("FuncFParams", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1667 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 116 "SysY.y" /* yacc.c:1646  */
    {  ASTTree *asttree = new ASTTree("ArrayExps", 0, yylineno);(yyval.ast_Tree) = asttree;}
#line 1673 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 117 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("ArrayExps", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1679 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 120 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Block", 1, yylineno, (yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1685 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 123 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = NULL;}
#line 1691 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 124 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("BlockItems", 2, yylineno, (yyvsp[-1].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1697 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 127 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = (yyvsp[0].ast_Tree); }
#line 1703 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 128 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = (yyvsp[0].ast_Tree); }
#line 1709 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 132 "SysY.y" /* yacc.c:1646  */
    { printf("Lval\n");ASTTree *asttree = new ASTTree("LVal", 2, yylineno, (yyvsp[-1].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1715 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 135 "SysY.y" /* yacc.c:1646  */
    { printf("stmt1\n");ASTTree *asttree = new ASTTree("Lval_Opassign_Stmt",2, yylineno, (yyvsp[-3].ast_Tree),(yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1721 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 136 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Empty_Stmt",0, yylineno);(yyval.ast_Tree) = asttree; }
#line 1727 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 137 "SysY.y" /* yacc.c:1646  */
    {ASTTree *asttree = new ASTTree("Exp_Stmt", 1, yylineno, (yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree;  }
#line 1733 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 138 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Block_Stmt", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1739 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 139 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("IF_Stmt", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1745 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 140 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("IF_ELSE_Stmt", 3, yylineno,(yyvsp[-4].ast_Tree),(yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1751 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 141 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("While_Stmt", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1757 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 142 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Break_Stmt", 0,yylineno);(yyval.ast_Tree) = asttree; }
#line 1763 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 143 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Continue_Stmt", 0,yylineno);(yyval.ast_Tree) = asttree; }
#line 1769 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 144 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Return_Stmt", 0,yylineno);(yyval.ast_Tree) = asttree; }
#line 1775 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 145 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Return_Stmt", 1, yylineno, (yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1781 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 149 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Cond", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1787 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 150 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Cond_And", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1793 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 151 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Cond_Or", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1799 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 155 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree)=(yyvsp[0].ast_Tree); }
#line 1805 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 156 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPLIGHT", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1811 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 157 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPGREAT", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1817 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 158 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPGREATEQ", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1823 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 159 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPLIGHTEQ", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1829 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 162 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree)=(yyvsp[0].ast_Tree); }
#line 1835 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 163 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPEQUAL", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1841 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 164 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPNOTEQUAL", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1847 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 168 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; (yyval.ast_Tree)->SetIntValue((yyvsp[0].ast_Tree)->GetIntValue());printf("IntConst:%d\n",(yyval.ast_Tree)->GetIntValue());}
#line 1853 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 169 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree;(yyval.ast_Tree)->SetIntValue((yyvsp[0].ast_Tree)->GetIntValue()); printf("IntConst:%d\n",(yyval.ast_Tree)->GetIntValue());}
#line 1859 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 170 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("IntConst", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree;(yyval.ast_Tree)->SetIntValue((yyvsp[0].ast_Tree)->GetIntValue());printf("IntConst:%d\n",(yyval.ast_Tree)->GetIntValue()); }
#line 1865 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 173 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("FuncRParams", 2, yylineno, (yyvsp[-1].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1871 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 177 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("(Exp)", 1, yylineno,(yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree;(yyval.ast_Tree)->SetIntValue((yyvsp[-1].ast_Tree)->GetIntValue()); }
#line 1877 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 178 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("LVal_EXP", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1883 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 179 "SysY.y" /* yacc.c:1646  */
    {(yyval.ast_Tree)=(yyvsp[0].ast_Tree);printf("ExpString:%s\n",(yyval.ast_Tree)->GetString());}
#line 1889 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 180 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = (yyvsp[0].ast_Tree);printf("ExpNumber:%d\n",(yyval.ast_Tree)->GetIntValue()); }
#line 1895 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 181 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("funcall", 1, yylineno, (yyvsp[-2].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1901 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 182 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("funcall", 2, yylineno, (yyvsp[-3].ast_Tree),(yyvsp[-1].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1907 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 183 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPPLUS_Exp", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1913 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 184 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPMINUS_Exp", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1919 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 185 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("OPNOT_Exp", 1, yylineno, (yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1925 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 186 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("MulExp", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1931 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 187 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("DIVIDEExp", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1937 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 188 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("MODExp", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1943 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 189 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("PLUSExp", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1949 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 190 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("MINUSExp", 2, yylineno, (yyvsp[-2].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1955 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 194 "SysY.y" /* yacc.c:1646  */
    { (yyval.ast_Tree) = NULL;}
#line 1961 "SysY.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 195 "SysY.y" /* yacc.c:1646  */
    { ASTTree *asttree = new ASTTree("Exps", 2, yylineno, (yyvsp[-1].ast_Tree),(yyvsp[0].ast_Tree));(yyval.ast_Tree) = asttree; }
#line 1967 "SysY.tab.c" /* yacc.c:1646  */
    break;


#line 1971 "SysY.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 199 "SysY.y" /* yacc.c:1906  */


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
