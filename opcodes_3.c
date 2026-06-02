#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void rotl(stack_t **head, unsigned int counter)
{
	stack_t *tmp = *head, *aux;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	*head = aux;
}

/**
 * rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void rotr(stack_t **head, unsigned int counter)
{
	stack_t *copy;
	(void)counter;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	*head = copy;
}

/**
 * set_stack - sets mode to stack (LIFO)
 * @head: stack head (unused)
 * @counter: line_number (unused)
 * Return: no return
 */
void set_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

/**
 * set_queue - sets mode to queue (FIFO)
 * @head: stack head (unused)
 * @counter: line_number (unused)
 * Return: no return
 */
void set_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}
