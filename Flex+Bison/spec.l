%option noyywrap

%{
    #include "spec.tab.h"
    #include <string.h>
%}

digit         [0-9]
number        {digit}+

%%
"false"                 return FALSE;
"true"                  return TRUE;
"and"                   return AND;
"or"                    return OR;
"not"                   return NOT;
"if"                    return IF;
"then"                  return THEN;
"else"                  return ELSE;
"while"                 return WHILE;
"do"                    return DO;
"print"                 return PRINT;
"readint"               return READINT;
"readstr"               return READSTR;
"begin"                 return _BEGIN;
"end"                   return END;
"exit"                  return EXIT;
"substring"             return SUBSTRING;
"length"                return LENGTH;
"position"              return POSITION;
"concatenate"           return CONCATENATE;
"<"                     return ANGLE_BRACKET_OPEN;
">"                     return ANGLE_BRACKET_CLOSE;
"["                     return BRACKET_OPEN;
"]"                     return BRACKET_CLOSE;
"{"                     return BRACE_OPEN;
"}"                     return BRACE_CLOSE;
"("                     return PARENTHESIS_OPEN;
")"                     return PARENTHESIS_CLOSE;
":"                     return COLON;
";"                     return SEMICOLON;
"."                     return DOT;
","                     return COMMA;
"?"                     return QUESTION_MARK;
"!"                     return EXCLAMATION_MARK;
"="                     return EQUALS_SIGN;
"+"                     return PLUS;
"-"                     return MINUS;
"*"                     return MULTIPLY;
"\/"                    return DEVIDE;
"\%"                    return IS_DEVIDE;

\"[^"]*\"               return STRING;
{number}                return NUM;
[a-zA-Z_][a-zA-Z0-9_]*  { 
                            yylval.str = strdup(yytext); 
                            return IDENT; 
                        }
[\n\t ]+                ;

%%
