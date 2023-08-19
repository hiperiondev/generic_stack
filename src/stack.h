/**
 * @file stack.h
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

#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

typedef struct stack_node_s {
    struct stack_node_s *next; //
    void *data;                //
} stack_node_t;

typedef struct stack_s {
    stack_node_t *top; //
    int length;        //
} *stack_t;

stack_t stack_create(void);
void stack_release(stack_t *stack);

void stack_push(stack_t *stack, void *data);
void* stack_pop(stack_t *stack);
void stack_flush(stack_t *stack);
int stack_size(stack_t *stack);
void* stack_top(stack_t *stack);
void* stack_next(stack_t *stack);
bool stack_isempty(stack_t *stack);

//////////////// utils ////////////////
void stack_drop(stack_t *stack);     // ( a -- )
void stack_dup(stack_t *stack);      // ( a -- a a )
void stack_dup_next(stack_t *stack); // ( a b -- a a b )
void stack_swap(stack_t *stack);     // ( a b -- b a )
void stack_over(stack_t *stack);     // ( a b -- a b a )
void stack_nip(stack_t *stack);      // ( a b -- b ) (swap drop)

#endif /* STACK_H_ */
