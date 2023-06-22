#ifndef __MONTY_H__
#define __MONTY_H__
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
#define STACK 0
#define QUEUE 1

#define DELIMS " \n\t\a\b"
extern char **op_toks;
/*for errors */
int openFileError(char *filename);
int malloc_error(void);
int short_stack_error(unsigned int line_number, char *op);
void set_op_tok_error(int error_code);
int unknownOpError(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int divError(unsigned int line_number);
int popError(unsigned int line_number);
int pintError(unsigned int line_number);
/* functions */
void my_add(stack_t **stack, unsigned int line_number);
void my_pall(stack_t **stack, unsigned int line_number);
void my_push(stack_t **stack, unsigned int line_number);
void my_nop(stack_t **stack, unsigned int line_number);
void my_pint(stack_t **stack, unsigned int line_number);
void my_swap(stack_t **stack, unsigned int line_number);
void my_pop(stack_t **stack, unsigned int line_number);
void my_mul(stack_t **stack, unsigned int line_number);
void my_div(stack_t **stack, unsigned int line_number);
void my_sub(stack_t **stack, unsigned int line_number);
void my_mod(stack_t **stack, unsigned int line_number);
/* stack */
int initializStack(stack_t **stack);
void freeStack(stack_t **stack);
int check_mode(stack_t *stack);


void (*getMyOpFunc(char *opcode))(stack_t**, unsigned int);
int runMonty(FILE *script_fd);
/* for tokens */
void freeTokens(void);
unsigned int token_arr_len(void);
int is_delim(char ch, char *delims);
int checkEmptyLine(char *line, char *delims);
char **_strtok(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);;

int get_word_length(char *str, char *delims);
char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

#endif /* __MONTY_H__ */
