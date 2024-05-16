#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//prototypes
void doweird();
void doabsolutevalue(int *a, int*b);
int dorandom1(int parameter);
void dorandom2(int parameter,int *a);
void ctof();
void doconcat(char *first, char *second);
void doconstant();
void ggiddy(char *word, int size);

int main() {
    printf("Welcome to my code\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

    //question 1
    doweird();

    //skipped question 2 for now
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    //question 3
    int a = 5;
    int b = 10;
    printf("Value of A initial: %d, Value of B initial: %d\n",a,b);
    doabsolutevalue(&a,&b);
    printf("Value of A final: %d, Value of B final: %d\n",a,b);

    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    //question 4
    printf("Random Number in Main is: %d\n", dorandom1(100));
    int num1 = 50;
    printf("num 1 before random: %d\n",num1);
    dorandom2(100,&num1);
    printf("num 1 after the random change: %d\n",num1);
    
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    //question5
    ctof();

    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    //question6
    char name1[100] = "James";
    char name2[50] = "Haimoff";
    doconcat(name1,name2);

    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    //question 2 (difficult for me)
    #define string "today is a delightful day to take a final exam" 
    printf("%s\n",string);
    doconstant();
    //initialized constant
    //got length and y count
    //struggling on logic for splitting the string up like in java
    //my logic so far - thinking finding the places where the string == ' ' and using those locations as word initializers and regoing
    //over the string for each interval and determining idk

    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    //question 7
    char word[10] = "biggy"; //double in word //should be true 
    char word2[10] = "ggiy"; //edge case 1 //should be true
    char word3[10] = "iygg"; //edge case 2 //should be true
    char word4[10] = "ggigy"; //triple g check //should be false
    char word5[10] = "James"; //random letters //should be false

    ggiddy(word,10);
    ggiddy(word2,10);
    ggiddy(word3,10);
    ggiddy(word4,10);
    ggiddy(word5,10);
    return 0;
}

void ggiddy(char *word, int size) {
    int gposition = 0;
    for (int i = 0; i < size; i ++) {
        if (word[i] == 'g') {
            gposition = i;
        }
    }
    int before = gposition -1;
	int after = gposition +1;
	if (gposition > 0 && word[before] == 'g' || gposition < size && word[after] == 'g') {
		printf("True\n");
		}else {
			printf("False\n");
		}
}

void doconstant() {
    int length = 0;
    int i = 0;
    int ycount = 0;
    while (string[i] != '\0') {
        i += 1;
        length += 1;

        if (string[i] == 'y') {
            ycount += 1;
        }
    }
    printf("Length: %d, Y Count: %d\n",length,ycount);
}


void doconcat(char *first, char *second) {
    int i = 0;
    int j = 0;
    // int r = 0;
    while (first[i] != '\0') { //gets length of first
        i += 1;
    }
    while (second[j] != '\0') { //start j from nothing
        first[i] = second[j]; //start i from previous word end
        j += 1;
        i += 1;
    }
    // int k = counter1;
    // while (first[k] > counter1 && first[k] < counter1+counter2+1) {
    //     first[k] = second[r];
    //     k += 1;
    //     r += 1;
    // }
    printf("%s\n",first);
}


void ctof() {
    int celsius = 0;
    printf("What is the value in celsius that you would like to convert to farenheit: ");
    scanf("%d",&celsius);
    int farenheit = ((9 * celsius)/5 ) + 32;
    printf("The Value of %d celsius in farenheit is: %d\n",celsius,farenheit);
}


void dorandom2(int parameter,int *a) {
    srand(time(NULL));
    int random = rand() % parameter;
    *a = random;
}

int dorandom1(int parameter) {
    srand(time(NULL));
    int random = rand() % parameter;
    return random;
}

void doabsolutevalue(int *a, int*b) {
    int temp1 = *a;
    int temp2 = *b;
    *a = *a - *b;
    *b = temp1 + temp2;
}

void doweird() {
    int number = 0;
    printf("Please select a number between 1 and 100: \n");
    scanf("%d",&number);
    if (number % 2 != 0) {
        printf("Odd\n");
    }
    if (number % 2 == 0 && number >= 2 && number <= 5) {
        printf("Not wierd\n");
    }
    if (number % 2 ==0 && number >= 6 && number <= 20) {
        printf("Wierd\n");
    }
    if (number % 2 == 0 && number > 20) {
        printf("Not Wierd\n");
    }

}