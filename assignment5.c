#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct poly{
    int exp;
    float coeff;
    struct poly *next;
} Poly;

void add(Poly *head, int exp, float coeff){
    Poly *newNode = (Poly *)malloc(sizeof(Poly));
    newNode->exp = exp;
    newNode->coeff = coeff;
    newNode->next = head;

    if (head->next == head) {
        head->next = newNode;
        return;
    }

    Poly *current = head->next;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
}

void displayPoly(Poly *head){
    if(head->next == head){
        printf("Polynomial is empty\n");
        return;
    }
    Poly *current = head->next;
    while(current != head){
        printf("%.2fx^%d ", current->coeff, current->exp);
        current = current->next;
        if(current != head){
            printf("+ ");
        }
    }
    printf("\n\n");
}

void sortPoly(Poly *head){
    if(head->next == head){
        return;
    }
    Poly *curr1 = head->next;
    while(curr1 != head){
        Poly *curr2 = curr1->next;
        while(curr2 != head){
            if(curr1->exp < curr2->exp){
                int temp_exp = curr1->exp;
                curr1->exp = curr2->exp;
                curr2->exp = temp_exp;

                float temp_coeff = curr1->coeff;
                curr1->coeff = curr2->coeff;
                curr2->coeff = temp_coeff;
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
}

void addPoly(Poly *head1, Poly *head2, Poly *res){
    Poly *p1 = head1->next;
    Poly *p2 = head2->next;

    while(p1 != head1 && p2 != head2){
        if(p1->exp == p2->exp){
            float sumCoeff = p1->coeff + p2->coeff;
            if(sumCoeff != 0){
                add(res, p1->exp, sumCoeff);
            }
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if(p1->exp > p2->exp){
            add(res, p1->exp, p1->coeff);
            p1 = p1->next;
        } 
        else {
            add(res, p2->exp, p2->coeff);
            p2 = p2->next;
        }
    }

    while(p1 != head1){
        add(res, p1->exp, p1->coeff);
        p1 = p1->next;
    }

    while(p2 != head2){
        add(res, p2->exp, p2->coeff);
        p2 = p2->next;
    }
}

double evaluatePoly(Poly *head, double x){
    double result = 0.0;
    Poly *current = head->next;

    while(current != head){
        result += current->coeff * pow(x, current->exp);
        current = current->next;
    }

    return result;
}

void multiplyPoly(Poly *head1, Poly *head2, Poly *res){
    Poly *p1 = head1->next;
    while(p1 != head1){
        Poly *p2 = head2->next;
        while(p2 != head2){
            int newExp = p1->exp + p2->exp;
            float newCoeff = p1->coeff * p2->coeff;

            add(res, newExp, newCoeff);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    sortPoly(res);
}

int main() {
    Poly *poly1 = (Poly*)malloc(sizeof(Poly));
    poly1->next = poly1;

    Poly *poly2 = (Poly*)malloc(sizeof(Poly));
    poly2->next = poly2;

    Poly *result = (Poly*)malloc(sizeof(Poly));
    result->next = result;

    int choice;
    int polyChoice;
    int exp;
    float coeff;
    double value;

    do{
        printf("Enter 1 to add term to polynomial\nEnter 2 to display polynomial\nEnter 3 to evaluate polynomial\nEnter 4 to add two polynomials\nEnter 5 to multiply polynomials\nEnter 0 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){

            case 1 :
                printf("Enter polynomial number (1 or 2): ");
                scanf("%d", &polyChoice);
                printf("Enter exponent: ");
                scanf("%d", &exp);
                printf("Enter coefficient: ");
                scanf("%f", &coeff);

                if(polyChoice == 1){
                    add(poly1, exp, coeff);
                } 
                else if(polyChoice == 2){
                    add(poly2, exp, coeff);
                } 
                else {
                    printf("Invalid polynomial number\n");
                }
                break;

            case 2 :
                printf("Enter polynomial number (1 or 2): ");
                scanf("%d", &polyChoice);

                if(polyChoice == 1){
                    printf("Polynomial 1 : ");
                    displayPoly(poly1);
                } 
                else if(polyChoice == 2){
                    printf("Polynomial 2 : ");
                    displayPoly(poly2);
                } 
                else {
                    printf("Invalid polynomial number\n");
                }
                break;

            case 3 :
                printf("Enter polynomial number (1 or 2): ");
                scanf("%d", &polyChoice);
                printf("Enter value of x: ");
                scanf("%lf", &value);
                double evalResult;

                if(polyChoice == 1){
                    evalResult = evaluatePoly(poly1, value);
                    printf("Polynomial 1 evaluated at x=%lf: %.2lf\n", value, evalResult);
                } 
                else if(polyChoice == 2){
                    evalResult = evaluatePoly(poly2, value);
                    printf("Polynomial 2 evaluated at x=%lf : %.2lf\n", value, evalResult);
                } 
                else {
                    printf("Invalid polynomial number\n");
                }
                break;

            case 4 :
                addPoly(poly1, poly2, result);
                printf("Resultant Polynomial : ");
                displayPoly(result);
                break;

            case 5 :
                multiplyPoly(poly1, poly2, result);
                printf("Resultant Polynomial : ");
                displayPoly(result);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
                break;
        }

    }while(choice != 0);

    return 0;
}