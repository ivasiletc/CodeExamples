
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FALSE = 258,
     TRUE = 259,
     NUM = 260,
     STRING = 261,
     IDENT = 262,
     OR = 263,
     AND = 264,
     EXCLAMATION_MARK = 265,
     QUESTION_MARK = 266,
     ANGLE_BRACKET_OPEN = 267,
     ANGLE_BRACKET_CLOSE = 268,
     EQUALS_SIGN = 269,
     PLUS = 270,
     MINUS = 271,
     IS_DEVIDE = 272,
     DEVIDE = 273,
     MULTIPLY = 274,
     IF = 275,
     THEN = 276,
     ELSE = 277,
     NOT = 278,
     WHILE = 279,
     DO = 280,
     PRINT = 281,
     READINT = 282,
     READSTR = 283,
     _BEGIN = 284,
     END = 285,
     EXIT = 286,
     SUBSTRING = 287,
     LENGTH = 288,
     POSITION = 289,
     CONCATENATE = 290,
     BRACKET_OPEN = 291,
     BRACKET_CLOSE = 292,
     BRACE_OPEN = 293,
     BRACE_CLOSE = 294,
     PARENTHESIS_OPEN = 295,
     PARENTHESIS_CLOSE = 296,
     COLON = 297,
     SEMICOLON = 298,
     DOT = 299,
     COMMA = 300,
     COMMENT_SINGLE_LINE = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 43 "spec.y"
 
    char* str; 
    int integer;
    bool boolean;



/* Line 1676 of yacc.c  */
#line 106 "spec.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


