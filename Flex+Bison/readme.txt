Bison: v2.4.1
Flex : v2.5.4a-1

1) flex spec.l

2) bison -d spec.y

3) g++ lex.yy.c spec.tab.c

OR

3.1) gcc lex.yy.c spec.tab.c -lfl