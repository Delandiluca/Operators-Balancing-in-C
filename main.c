#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack {
  int top;
  int size;
  char *object;
} Stack; 

void startStack(Stack *p, int size);
int isEmpty(Stack *p);
int isFull(Stack p);
void push(Stack *p, char elem);
char pop(Stack *p);
void printStack(Stack *p);
int validateOperator(char *op, Stack *p);
char readTop(Stack *p);
int isOpenCaracter(char c);
int isCloseCaracter(char c);

void startStack(Stack *p, int size) {
  p->top = -1;
  p->size = size;
  p->object = (char *)malloc(size * sizeof(char));
}

int isEmpty(Stack *p) {
  return (p->top <= -1); 
}

int isFull(Stack p) {
  return (p.top == (MAX_SIZE - 1));
}

void push(Stack *p, char elem) {
  if (!isFull(*p)) {
    p->top++;
    p->object[p->top] = elem;
  } else {
    puts("\nError: Stack Overflow");
    exit(1);
  }
}

char pop(Stack *p) {
  if (!isEmpty(p)) {
    char element = p->object[p->top];
    p->top--;
    return element;
  } else {
    puts("\nError: Stack Underflow");
    exit(1);
  }
}

char readTop(Stack *p) { return p->object[p->top]; }

void printStack(Stack *p) {
  if (!isEmpty(p)) {
    for (int i = 0; i <= (p->top); i++) {
      printf("\nCaracter %c ", p->object[i]);
    }
  } else {
    puts("\nError: Stack Empty");
    exit(1);
  }
}

int isOpenCaracter(char c) {
  return (c == '(' || c == '{' || c == '[' || c == '<');
}

int isCloseCaracter(char c) {
  return (c == ')' || c == '}' || c == ']' || c == '>');
}

int validateOperator(char *op, Stack *p) {
  int i;
  for (i = 0; i < strlen(op); i++) {
    if (isOpenCaracter(op[i])) {
      push(p, op[i]);
    } else if (isCloseCaracter(op[i])) {
      if (!isEmpty(p)) {
        char popped = pop(p);
        if ((op[i] == ')' && popped != '(') ||
            (op[i] == '}' && popped != '{') ||
            (op[i] == ']' && popped != '[') ||
            (op[i] == '>' && popped != '<')) {
          return 0;
        }
      } else {
        return 0;
      }
    }
  }
  return isEmpty(p);
}

int main(void) {

  Stack stack;

  while (1) {
    startStack(&stack, MAX_SIZE);

    char operators[MAX_SIZE];
    puts("\nInsira a operação: ");
    scanf("%s", operators);

    printf("\nOperação %s",
           (validateOperator(operators, &stack)) ? "Válida" : "Inválida");
  }

  return 0;
}
