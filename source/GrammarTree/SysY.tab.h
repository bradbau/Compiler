/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "SysY.y"
{

    class ASTTree *ast_Tree;
}
/* Line 1529 of yacc.c.  */
#line 150 "SysY.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
