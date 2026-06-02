#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

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

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value of push
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue (0 for stack, 1 for queue)
 * Description: carries values through the program
 */
typedef struct bus_s
{
        char *arg;
        FILE *file;
        char *content;
        int lifi;
}  bus_t;

extern bus_t bus;

/* Opcodes Part 1 */
void push(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int number);
void pop(stack_t **head, unsigned int number);
void swap(stack_t **head, unsigned int number);
void add(stack_t **head, unsigned int number);
void nop(stack_t **head, unsigned int number);

/* Opcodes Part 2 & advanced */
void sub(stack_t **head, unsigned int number);
void div_op(stack_t **head, unsigned int number);
void mul(stack_t **head, unsigned int number);
void mod(stack_t **head, unsigned int number);
void pchar(stack_t **head, unsigned int number);
void pstr(stack_t **head, unsigned int number);
void rotl(stack_t **head, unsigned int number);
void rotr(stack_t **head, unsigned int number);
void set_stack(stack_t **head, unsigned int number);
void set_queue(stack_t **head, unsigned int number);

/* Stack helper functions */
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);

/* Execution and Line reading */
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file);
long _getline(char **lineptr, size_t *n, FILE *stream);

#endif /* MONTY_H */
