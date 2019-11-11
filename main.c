#include <stdio.h>
#include <stdlib.h>

/* ==================================================================================
 * Function: miToKm
 * Purpose: Prints a miles values table and their equivalent in Kilometers
 * Params: None
 * Return: void
   ==================================================================================*/
void miToKm(){
    int miles;
    float kilo;
    int lower, upper, step;

    lower = step = 1;
    upper = 10;

    miles = lower;
    printf("================================\n");
    printf("** Tabla millas vs kilometros **\n");
    printf("================================\n");
    printf("      Millas  Kilometros\n");
    while (miles <= upper){
        kilo = (1.61 * miles);
        printf("\t%d\t%.2f \n", miles, kilo);
        miles = miles + step;
    }
    printf("================================\n");
}

/* ==================================================================================
 * Function: CtoF
 * Purpose: Converts a celsius given quantity into Fahrenheit
 * Params: None
 * Return: Void
   ==================================================================================*/
void CtoF(){
    printf("================================\n");
    printf("* Conversor Celsius-Fahrenheit *\n");
    printf("================================\n");
    printf("Ingrese el valor en grados \nCelsius a convertir: ");

    int c;
    int celsius = 0;
    while((c = getchar()) != '\n'){
        if(c >= '0' && c <= '9'){
            celsius =  celsius*10 + (c - '0');
        }
    }
    float fahr = 32 + (celsius*9/5);

    printf("****** Conversion exitosa ******\n");
    printf("%d grados Celsius en Fahrenheit \nes igual a %.2f Fahrenheit.\n", celsius, fahr);
    printf("================================\n");
}

/* ==================================================================================
 * Function: digitCounter
 * Purpose: Returns the quantity of digits into a given number
 * Params: Number to count the digits
 * Return: Number of digits into the given number
   ==================================================================================*/
int digitCounter(int n){
    if(n == 0){
        printf("================================\n");
        printf("****** Contador de digitos *****\n");
        printf("================================\n");
        printf("Ingrese el numero del cual desea\ncontar los digitos: ");
    }

    int c;
    if((c = getchar()) != EOF && c != '\n'){
        if(c >= '0' && c <= '9'){
            return 1 + (digitCounter(n+1));
        }
    }
    printf("******** Conteo exitoso ********\n");
    printf("La cantidad de digitos es: %d\n", n);
    printf("================================\n");
    return 0;
}

/* ==================================================================================
 * Function: pairDigitCounter
 * Purpose: Returns the quantity of pair digits into a given number
 * Params: Number to count pair digits, and check number to conditionals
 * Return: Number of pair digits into the given number
   ==================================================================================*/
int pairDigitCounter(int n, int k){
    if(k == 0){
        printf("================================\n");
        printf("**** Contador digitos pares ****\n");
        printf("================================\n");
        printf("Ingrese el numero del cual desea\ncontar los digitos: ");
    }

    int c;
    if((c = getchar()) != EOF && c != '\n'){
        if(c >= '0' && c <= '9'){
            int dig = c - '0';
            if(dig%2 == 0){
                return 1 + (pairDigitCounter(n+1, 1));
            }else{
                return pairDigitCounter(n, 1);
            }
        }
    }
    printf("******** Conteo exitoso ********\n");
    printf("La cantidad de digitos es: %d\n", n);
    printf("================================\n");
    return 0;
}

/* ==================================================================================
 * Function: str_cmp
 * Purpose: Compares two strings and determines which one is larger.
 * Params: Both of the two strings to compare.
 * Return: Negative number if s > p, 0 if s == p and positive if s < p.
   ==================================================================================*/
int str_cmp(char* s, char* p){
    if(strlen(s) > strlen(p)){
        return -1;
    }else if(strlen(s) == strlen(p)){
        return 0;
    }else{
        return 1;
    }
}

/* ==================================================================================
 * Function: str_cat
 * Purpose: Concatenates two given strings into only one
 * Params: The both of the strings to concatenate
 * Return: void
   ==================================================================================*/
void str_cat(char* src, char* dest){
    char* ptr = dest + strlen(dest);

    while(*src != '\0'){
        *ptr++ = *src++;
    }
    *ptr = '\0';

    printf("%s \n", dest);
}

/* ==================================================================================
 * Function: read_file (Uncomplete)
 * Purpose: Returns one list with the words inside of a document, and another one with
 *          number of lines which this words appear.
 * Params: None
 * Return: void
   ==================================================================================*/
void read_file(){
    FILE* f;
    f = fopen("C:\\Users\\david\\CLionProjects\\EjerciciosImperativo\\prfct.txt","r");
    FILE* f2;
    f2 = fopen("C:\\Users\\david\\CLionProjects\\EjerciciosImperativo\\result.txt","a");
    char buff[255];
    char temp[] = "";

    while(!feof(f)){
        fgets(buff,255, f);
        printf("%s", buff);
    }

    int i = 0;
    while(buff[i] != '\0') {
        if(buff[i] == ' ' ){
            printf("%s", temp);
            fputs(temp, f2);
            temp[0] = 0;
            fputs("\n", f2);
        }else {
            strncat(temp, &buff[i], 1);
        }
        i++;

    }
    printf("%s", temp);
    fputs(temp, f2);

    fclose(f);
    fclose(f2);
}

int main(){
    //miToKm();
    //CtoF();
    //digitCounter(0);
    //pairDigitCounter(0, 0);
    //char c1[] = "abc";
    //char c2[] = "def";
    //str_cmp(c1, c2);
    //str_cat(c1, c2);
    //read_file();
}