#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void intchange(int *a,int *b){
    int acopy = *a;
    int bcopy = *b;
    *a = bcopy;
    *b = acopy;
}

void exercice2(){
    printf("Hello, World!\n");
    int a;
    int b;
    printf("What is A ?");
    scanf("%d",&a);
    while(getchar()!='\n');
    printf("What is B ?");
    scanf("%d",&b);
    while(getchar()!='\n');
    printf("A = %d, B = %d\n",a,b);
    intchange(&a,&b);
    printf("A = %d, B = %d\n",a,b);
}

int pair(int a){
    return a%2;
}

int calculatrice(int n1, char signe, int n2){
    switch (signe) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        case '%':
            return n1 % n2;
    }
    return 0;
}
void exercice10(){
    int n1;
    int n2;
    while(1){
        char op = 'a';
        while (op != '+' && op != '-' && op != '*' && op != '/' && op != '%'){
            printf("Calcul :\n");
            scanf("%d %c %d",&n1,&op,&n2);
        }
        int g = calculatrice(n1,op,n2);
        printf("%d\n",g);
    }
}

void check_index(int *t, int *indexes, int len_t){
    int *first_index = t;
    for (t=t;t-first_index < len_t; t++){
        if (*t == 0){
            printf("T is NULL at index %lld\n",t-first_index);
            *indexes = t-first_index;
            indexes++;
            }
        }
    }

void exercice12(){
    srand(time(NULL));
    int t[15];
    int i;
    for (i=0;i<15;i++) {
        if (rand() % 2) {
            t[i] = 17;
        }else{
            t[i] = 0;
        }
    }
    int indexes[15];
    check_index(&t[0], &indexes[0],15);
    for (i=0;i<15;i++) {
        printf("%d, ", t[i]);
    }
    printf("\n");
    for (i=0;i<15;i++){
        printf("%d, ",indexes[i]);
    }

}
void print_tableau(int *t, int len_tableau){
    int *index = t;
    printf("Le tableau est [");
    for (t=t;t-index<len_tableau-1;t++){
        printf("%d, ",*t);
    }
    printf("%d]\n",*t);
}
void tri_tableau(int *t, int len_tableau,int iteration){
    int i;
    int j;
    for (j=iteration;j<len_tableau-1;j++){
        for (i=1;i<len_tableau-j;i++){
            if (*(t+j+i)<*(t+j)){
                intchange((t+j+i),t+j);
                tri_tableau(t,len_tableau,j);
            }
        }
    }
    t++;
}
void exercice16(){
    int len_tableau;
    printf("De quelle longueur est le tableau ?\n");
    scanf("%d",&len_tableau);
    int t[len_tableau];
    int i;
    for (i=0;i<len_tableau;i++){
        printf("The %d th number is :\n",i);
        scanf("%d",&t[i]);
    }
    print_tableau(&t[0],len_tableau);
    tri_tableau(&t[0],len_tableau,0);
    print_tableau(&t[0],len_tableau);
}
int main() {
    //exercice2();
    //exercice4();
    //exercice10();
    //exercice12();
    exercice16();
    return 0;
    }