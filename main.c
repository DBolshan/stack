//
//  main.c
//  флита
//
//  Created by Дмитрий on 21/09/2020.
//  Copyright © 2020 Дмитрий. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Stack {
    Data * a;            // указатель на динамически выделенную память под элементы стека
    unsigned int size;   // на сколько элементов выделена память
    unsigned int n;      // сколько элементов хранится в стеке
};

#define N 10
void stack_init(struct Stack * s) {
    s->n = 0;       // пустой стек
    s->size = N;    // емкостью N элементов
    s->a = malloc(s->size * sizeof(Data));
}

void stack_push(struct Stack * s, Data data) {
    // если стек полон, его нужно увеличить на 10 элементов
    if (s->n == s->size) {
        s->size += N;
        s->a = realloc(s->a, s->size * sizeof(Data));// переназначает память
    }
    s->a[s->n] = data;
    s->n ++;
}
struct Stack stack_new() {
   struct Stack * s;
   s = malloc(sizeof(struct Stack));    // пункт 1
   stack_init(s);                       // пункты 2, 3, 4
   return *s;
}
void stack_print(struct Stack * s) {
    int i;
    for(i = 0; i < s->n; i++) {
        printf("%d ", s->a[i]);
    printf("\n");
    }
}

int main(void){
    struct Stack s = stack_new();
    char ans[80];
    int numb;
    scanf("%s", &ans);
    if (strcmp(ans, "push") == 0){
        scanf("%d", &numb);
        stack_push(&s, numb);
    }
    scanf("%s", &ans);
    if (strcmp(ans, "print") == 0){
        stack_print(&s);
    }
}





/* void pop_back(struct Stack ** stack) {
   struct Stack * previous = NULL;
    if (stack == NULL) { //если элементов больше нет
        exit(printf("%d", 0));
    }
    previous = (*stack); //запоминаем предыдущий элемент
    (struct *stack) = (struct *stack)->Data;//предыдущий становиться текущим
    free(previous -> Data);//высвобождаем поле с данными
    free(previous);//высвобождаем элемент
}*/

//addValue - добавить элемент

