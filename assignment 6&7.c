#include <stdio.h>
#define MAX 5// max size bro pls dont break

int Stack[MAX]; 
int top = -1; // starts at -1 because empty lol

void push() {
    top++;
    printf("enter number pls: ");
    scanf("%d", &Stack[top]);
    printf("yay element pushed successfully :D\n");
}

void pop() {
    printf("\npopping rn...\n");
    printf("Element gone: %d\n", Stack[top]);
    top--; // decrement bye bye  
}

// Gives operators a hierarchy because some symbols are just better than others
int prec(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}


    

void convertInfixToPostfix() { 
    char infix[50],postfix[50]; 
    char opStack[50];            
    int opTop= -1;              // points to the top of our operator stack (starts empty lol)
    
    printf("Enter infix: "); 
    scanf("%s", infix);          
    
    int i = 0, j = 0;           
    char item;                  
    
    
    while(infix[i] != '\0') { 
        item=infix[i];         
        
        
        if (isalnum(item)) { 
            postfix[j++] =item;
        } 
        
        else if (item =='(') { 
            opStack[++opTop]=item; 
        } 
        
        else if (item == ')') { 
            while (opTop!=-1 && opStack[opTop] != '(') { 
                postfix[j++] = opStack[opTop--]; 
            } 
            if (opTop != -1) opTop--; 
        } 
        
        else { 
            
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(item)) { 
                postfix[j++]=opStack[opTop--]; 
            } 
            opStack[++opTop]=item; 
        } 
        i++; 
    } 
    
    
    while (opTop != -1) { 
        postfix[j++] = opStack[opTop--]; 
    } 
    
    postfix[j] ='\0';
    
    printf("Postfix expression: %s B)\n", postfix); 
}

    




int main(){
    int choice; // user choice 
    while (1) { // infinite loop because I forgot to add an exit option lol
        printf("\n--- MY EPIC STACK PROGRAM ---\n");
        printf("1. Push (add thing)");
        printf("2. Pop (remove thing)");
        printf("Enter choice (pls work): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                convertInfixToPostfix();
                break;
            default:
                printf("learn how to type, bad choice >:(");
            
        }
    }
    return 0; // never reached haha
}