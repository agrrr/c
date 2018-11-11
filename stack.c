/******************************************

* 83-120-03
* Ex 5
******************************************/
// I made the stack to contain a pointers to the element (for better usage of memory)(because i didnt understand the code at first)
//but after i finished i realized i can do it as an array of elements (not pointers).
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int i;
	long int l;
	double d;
	float f;
	char c;
	char s[11];
}Element;
typedef struct {
	Element **content;
	int size;
	int topIndex;
} Stack;
int isFull(Stack*);
int isHalfEmpty(Stack*);
int isEmpty(Stack*);
Element top(Stack *stackPtr);
Element pop(Stack *stackPtr);
void push(Stack*);
void destroy(Stack*);
//change values here to change the type of the elements in the stack
#define ELEMENT_FORMAT_SCANF "%d	%ld	%lf	%f	%c	%s"
#define ELEMENT_FORMAT_PRINTF "int:	%d\nlong:	%ld\ndouble:	%lf\nfloat:	%f\nchar:	%c\nstring:	%s\n"
     // char/int/float ...
void printStack(Stack* stackPtr) {
    int i;
    printf("Size of stack = %d, Size of content = %d\n", stackPtr->size, stackPtr->topIndex + 1);
    printf("Content:\n ");
    for (i = (stackPtr->topIndex)-1; i >=0; i--) {//"%d %ld %lf %f %c %s"
        printf(ELEMENT_FORMAT_PRINTF, stackPtr->content[i]->i, stackPtr->content[i]->l, stackPtr->content[i]->d, stackPtr->content[i]->f, stackPtr->content[i]->c, stackPtr->content[i]->s);
        printf(" ");
    }
    printf("\n\n");
}
void scans(Stack* stackPtr)
{
	scanf("%d %ld %lf %f %c %s", &(stackPtr->content[stackPtr->topIndex]->i), &(stackPtr->content[stackPtr->topIndex]->l), &(stackPtr->content[stackPtr->topIndex]->d),
			&(stackPtr->content[stackPtr->topIndex]->f), &(stackPtr->content[stackPtr->topIndex]->c), &(stackPtr->content[stackPtr->topIndex]->s));
	//fixing the topindex
	stackPtr->topIndex++;
	//making sure there is enought menory maximize  it if needed
	//push(stackPtr);
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void init(Stack* stackPtr) {
    Element** newContent = (Element**) malloc(sizeof(Element*));
    if (newContent == NULL) {
        printf("Insufficient memory to initialize stack.\n");
        exit(1);  /* Exit, returning error code. */
    }
    stackPtr->content = newContent;
    stackPtr->size = 0;
    stackPtr->topIndex = 0;  /* I.e., empty */
}
void destroy(Stack* stackPtr) {
    free(stackPtr->content);
    stackPtr->content = NULL;
    stackPtr->size = 0;
    stackPtr->topIndex = -1;  /* I.e., empty */
}
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void push(Stack* stackPtr) {
    //Put information in array; update topIndex

    if (isFull(stackPtr)) {
        Element* newContent = (Element*) realloc(stackPtr->content,sizeof(Element) * stackPtr->size * 2);
        if (newContent == NULL) {
            free(stackPtr->content);
            printf("Push: Insufficient memory to realloc stack.\n");
            exit(1);  // Exit, returning error code
        }
        stackPtr->content[stackPtr->topIndex] = newContent;
        stackPtr->size *= 2;
        printf("---------------------------------> Expanding size of stack to %d\n", stackPtr->size);
    }
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Element pop(Stack *stackPtr) {
    //note - before using pop, the user must check that the stack is not empty
    if (isEmpty(stackPtr)) {
        printf("Can't pop Element from Stack: Stack is empty.\n");
        exit(1);  // Exit, returning error code
    }
    //Get information from the array; update topIndex
    Element returnVal = (*stackPtr->content[(stackPtr->topIndex)-1]);

    if (isHalfEmpty(stackPtr)) {
        Element** newContent = (Element**) realloc(stackPtr->content,sizeof(Element*) * stackPtr->size / 2);
        if (newContent == NULL) {
            printf("Pop: Insufficient memory to realloc stack.\n");
            exit(1);  /* Exit, returning error code. */
        }
        stackPtr->content = newContent;
        stackPtr->size /= 2;
        printf("---------------------------------> Shrinking size of stack to %d\n", stackPtr->size);
    }

    return returnVal;
}
Element top(Stack *stackPtr) {
    //note - before using top, the user must check that the stack is not empty
    if (isEmpty(stackPtr)) {
        printf("Can't top Element from Stack: Stack is empty.\n");
        exit(1);  // Exit, returning error code
    }
    return *(stackPtr->content[stackPtr->topIndex]);
}
int isEmpty(Stack* stackPtr) {
    return stackPtr->topIndex == 0;
}
int isHalfEmpty(Stack* stackPtr) {
    return stackPtr->topIndex < (stackPtr->size / 2) ;
}
int isFull(Stack* stackPtr) {
    return stackPtr->topIndex >= stackPtr->size - 1;
}
int main() {

	int input;
	Stack stack;
	stack.topIndex = 0;

	init(&stack);
	printf("Welcome to the elements stack!\n");

	do {
		printf("Please choose option from the menu:\n\t1 : push\n\t2 : top\n\t3 : pop\n\t4 : print stack\n\tother : exit\n");
		scanf("%d", &input);
		switch (input) {
		case 1: printf("Enter element to push by the following order:\n	int:	long:	double:	float:	char:	string:\n ");
			stack.content = (Element**)realloc(stack.content, stack.topIndex + 1);
			stack.content[stack.topIndex] = (Element*)malloc(sizeof(Element));
			scans(&stack);
			stack.size++;
			//push(&stack);
			break;
		case 2: if (!isEmpty(&stack)) {
			printf("top\n");
			stack.topIndex =stack.topIndex - 1;
			printf(ELEMENT_FORMAT_PRINTF, stack.content[stack.topIndex]->i, stack.content[stack.topIndex]->l, stack.content[stack.topIndex]->d, stack.content[stack.topIndex]->f, stack.content[stack.topIndex]->c, stack.content[stack.topIndex]->s);
			stack.topIndex = stack.topIndex + 1;
			printf("\n");
		}
				else {
					printf("can't top! stack is empty!\n");
				}
				break;
		case 3: if (!isEmpty(&stack)) {
			printf("pop\n");
			stack.topIndex -= 1;
			printf(ELEMENT_FORMAT_PRINTF, stack.content[stack.topIndex]->i, stack.content[stack.topIndex]->l, stack.content[stack.topIndex]->d, stack.content[stack.topIndex]->f, stack.content[stack.topIndex]->c, stack.content[stack.topIndex]->s);
			stack.topIndex += 1;
			pop(&stack);
			printf("\n");
		}
				else {
					printf("can't pop! stack is empty!\n");
				}
				break;
		case 4: printStack(&stack);
		}
	} while (1 <= input && input <= 4);

	destroy(&stack);
	return 0;
}