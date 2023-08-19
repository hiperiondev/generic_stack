/**
 * @file stack.c
 * @brief stack
 * @copyright 2023 Emiliano Augusto Gonzalez (hiperiondev). This project is released under MIT license. Contact: egonzalez.hiperion@gmail.com
 * @see Project Site: https://github.com/hiperiondev/generic_stack
 * @note This is based on other projects. Please contact their authors for more information.
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "stack.h"

stack_t stack_create(void) {
    stack_t stack = (stack_t) malloc(sizeof(struct stack_s));
    if (stack == NULL)
        return NULL;

    stack->length = 0;
    stack->top = NULL;

    return stack;
}

void stack_release(stack_t *stack) {
    stack_flush(stack);
    free(*stack);
}

void stack_push(stack_t *stack, void *data) {
    stack_node_t *node = (stack_node_t*) malloc(sizeof(stack_node_t));
    if (node == NULL)
        return;
    node->data = data;

    node->next = (*stack)->top;
    (*stack)->top = node;

    (*stack)->length++;
}

void* stack_pop(stack_t *stack) {
    stack_node_t *current = (*stack)->top;
    if (current == NULL)
        return NULL;
    void *data = current->data;
    (*stack)->top = (*stack)->top->next;

    free(current);
    (*stack)->length--;
    return data;
}

void stack_flush(stack_t *stack) {
    int length = (*stack)->length;
    stack_node_t *current, *next;
    current = (*stack)->top;
    while (length--) {
        next = current->next;
        free(current);
        current = next;
    }

    (*stack)->length = 0;
    (*stack)->top = NULL;
}

int stack_size(stack_t *stack) {
    return (*stack)->length;
}

void* stack_top(stack_t *stack) {
    return (*stack)->top->data;
}

void* stack_next(stack_t *stack) {
    return (*stack)->top->next->data;
}

bool stack_isempty(stack_t *stack) {
    return ((*stack)->length == 0);
}

//////////////// utils ////////////////

void stack_drop(stack_t *stack) {
    free(stack_pop(stack));
}

void stack_dup(stack_t *stack) {
    stack_push(stack, (*stack)->top->data);
}

void stack_dup_next(stack_t *stack) {
    void *tmp = (*stack)->top->data;
    (*stack)->top->data = (*stack)->top->next->data;
    stack_push(stack, tmp);
}

void stack_swap(stack_t *stack) {
    void *tmp = (*stack)->top->data;
    (*stack)->top->next->data = (*stack)->top->data;
    (*stack)->top->data = tmp;
}

void stack_over(stack_t *stack) {
    stack_push(stack, (*stack)->top->next->data);
}

void stack_nip(stack_t *stack) {
    (*stack)->top->next->data = (*stack)->top->data;
    free(stack_pop(stack));
}
