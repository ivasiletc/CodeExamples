%{
    #include <stdio.h>
    #include <string>
    #include <iostream>

    void yyerror(const char *str) 
    {
        fprintf(stderr,"error: %s\n",str);
    }
    
    extern "C" int yyparse (void);
    int yylex();

    int length(std::string word);
    
    std::string concatenate(std::string first_word, std::string second_word);
    std::string substring(std::string word, int position, int lenght);
    
    int position(std::string main_word, std::string substring);
    
    void print(char* word);
    void print(int number);
    void print();
    
    int readint();
    std::string readstr();
    
    void exit();
    
    int line_counter = 1;
    
    int main()
    {
        while(true)
        {
            yyparse();
        }    
        return 0;
    }
%}

%union 
{ 
    char* str; 
    int integer;
    bool boolean;
}

%type<str> str_expr;
%type<integer> num_expr;
%type<boolean> bool_expr;

%token <boolean>  FALSE TRUE
%token <integer>  NUM 
%token <str>      STRING IDENT
%token <operator> OR                  "||"
%token <operator> AND                 "&"
%token <operator> EXCLAMATION_MARK    "!"
%token <operator> QUESTION_MARK       "?"
%token <operator> ANGLE_BRACKET_OPEN  "<"
%token <operator> ANGLE_BRACKET_CLOSE ">"
%token <operator> EQUALS_SIGN         "="
%token <operator> PLUS                "+"
%token <operator> MINUS               "-"
%token <operator> IS_DEVIDE           "%"
%token <operator> DEVIDE              "/"
%token <operator> MULTIPLY            "*"

%token IF THEN ELSE

%token NOT
%token WHILE DO
%token PRINT
%token READINT READSTR
%token _BEGIN END
%token EXIT
%token SUBSTRING LENGTH POSITION CONCATENATE

%token BRACKET_OPEN BRACKET_CLOSE
%token BRACE_OPEN BRACE_CLOSE
%token PARENTHESIS_OPEN PARENTHESIS_CLOSE
%token COLON SEMICOLON DOT COMMA
%token COMMENT_SINGLE_LINE

%%
program:        instr;

instr:          instr SEMICOLON simple_instr | simple_instr;

simple_instr:   assign_stat
              | if_stat
              | while_stat
              | _BEGIN instr END
              | output_stat
              | EXIT { exit(); };

assign_stat:    IDENT COLON EQUALS_SIGN num_expr
              | IDENT COLON EQUALS_SIGN str_expr;
              
if_stat:        IF bool_expr THEN simple_instr
              | IF bool_expr THEN simple_instr ELSE simple_instr;
              
while_stat:     WHILE bool_expr DO simple_instr
              | DO simple_instr WHILE bool_expr;
              
output_stat:    PRINT PARENTHESIS_OPEN num_expr PARENTHESIS_CLOSE { print($3); }
              | PRINT PARENTHESIS_OPEN str_expr PARENTHESIS_CLOSE { print($3); }
              | PRINT PARENTHESIS_OPEN PARENTHESIS_CLOSE { print(); };

num_expr:       NUM 
              | IDENT { printf("Log line %d: $$ = @todo get value from variable by IDENT value\n\n", line_counter); line_counter++; }
              | READINT { readint(); }
              | MINUS num_expr { $$ = $2*(-1); }
              | num_expr num_op num_expr
              | PARENTHESIS_OPEN num_expr PARENTHESIS_CLOSE { $$ = $2; }
              | PARENTHESIS_OPEN str_expr PARENTHESIS_CLOSE { length($2); }
              | PARENTHESIS_OPEN str_expr COMMA str_expr PARENTHESIS_CLOSE { position($2, $4); } ;
              
str_expr:       STRING | IDENT
              | READSTR { readstr(); }
              | PARENTHESIS_OPEN str_expr COMMA str_expr PARENTHESIS_CLOSE { concatenate($2, $4); }
              | PARENTHESIS_OPEN str_expr COMMA num_expr COMMA num_expr PARENTHESIS_CLOSE { substring($2, $4, $6); };
              
bool_expr:      TRUE | FALSE
              | PARENTHESIS_OPEN bool_expr PARENTHESIS_CLOSE { $$ = $2; }
              | NOT bool_expr { $$ = $2; }
              | bool_expr bool_op bool_expr
              | num_expr num_rel num_expr { printf("Log line %d: there should be some yacc IF, but I don't know how to do it\n\n", line_counter); line_counter++;}
              | str_expr str_rel str_expr;

num_op:         PLUS | MINUS | MULTIPLY | IS_DEVIDE;

bool_op:        AND | OR;

num_rel:        EQUALS_SIGN 
              | ANGLE_BRACKET_OPEN 
              | ANGLE_BRACKET_OPEN EQUALS_SIGN 
              | ANGLE_BRACKET_CLOSE 
              | ANGLE_BRACKET_CLOSE EQUALS_SIGN 
              | ANGLE_BRACKET_OPEN ANGLE_BRACKET_CLOSE;
              
str_rel:        EQUALS_SIGN EQUALS_SIGN 
              | EXCLAMATION_MARK EQUALS_SIGN;

%%

int length(std::string word)
{
    return word.length();
}

std::string concatenate(std::string first_word, std::string second_word)
{
    std::string result = first_word + second_word;
    printf("String after concatenate: %s\n", result.c_str());
    
    return result;
}

std::string substring(std::string word, int position, int length)
{
    std::string result = word.substr(position, length);
    return result;
}

int position(std::string main_word, std::string substring)
{
    size_t found = main_word.find(substring);
    if (found != std::string::npos) {
        return found;
    }
    
    return 0;
}

void print(int num)
{
    printf("Log line %d: Number is %d (@todo fix incorrect argument passing to print(int) function))\n\n", line_counter, num);
    line_counter++;
}

void print(char* str)
{
    printf("Log line %d: String is %s (@todo fix incorrect argument passing to print(string) function)\n\n", line_counter, str);
    line_counter++;
}

/* 
 *  Helper function for testing.
 */
void print()
{
    printf("Log line %d: print function successfully called\n\n", line_counter);
    line_counter++;
}

int readint()
{    
    int i = 0;
    bool negative = false;
    int c = getchar();

    if (c == '-') 
    {
        negative = true;
        c = getchar();
    }

    while (c >= 48 && c <= 57)
    {
        i = (i << 3) + (i << 1) + c - 48; c = getchar();
    }

    if (negative)
        i*=(-1);

    printf("Log line %d: readint function called successfully. Int from input is: %d\n\n", line_counter, i);
    line_counter++;

    return i;
}

std::string readstr()
{
    std::string str;
    std::getline(std::cin, str);
    return str;
}

void exit()
{
    exit(0);
}
