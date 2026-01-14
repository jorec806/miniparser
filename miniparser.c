#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
// edit valid_str_num to receive a str parameter only
// fixed bug where num_and_sign was no detecting '-' properly

static bool valid_num(const char digit);
static bool check_valid_str(const char* str);
static bool valid_str_num(const char* str);
static bool num_and_sign(const char* str);
static char* remove_leading_zeros(const char* str);

static bool check_valid_str(const char* str)
{
    /*CONSTAINTS*/
    //NULL and empty str constraint
    if (str == NULL || str[0] == '\0') return false;
    
    //Check numbers and negative sign
    if (!num_and_sign(str)) return false;    

    //Overflow, underflow

    /*FORMAT*/
    //leading zeros

    return true;
}

static bool valid_num(const char digit)
{
    if ('0' <= digit && digit <= '9') {
        return true;
    }

    return false;
}

static bool valid_str_num(const char* str){
    for (int i = 0; str[i] != '\0'; i++){ 
        if (!valid_num(str[i])){
            return false;
        }
    }
    
    return true;
}

static bool num_and_sign(const char* str)
{
    if (str[0] == '-'){
        if (strlen(str) < 2){
            return false;
        } 
        
        return valid_str_num(str + 1);
    }

    return valid_str_num(str);
}

static int convert_to_int(const char* str, size_t index)
{
    int total = 0;
    for(size_t i = index; str[i] != '\0'; i++){
        int new = str[i] - '0';
        total = total*10 + new;
    }
    
    return total;
}

static char* remove_leading_zeros(const char* str)
{
    size_t qty = strlen(str);
    char* new_str = malloc(sizeof(*new_str) * (qty + 1));
    if(!new_str) return NULL;
    
    strcpy(new_str, str);    

    /*
    
    si tiene '-' al inicio
        si tiene al menos 3 digitos
            mientrs el digito en cuestion sea CERO
                - verificar que despues del - hay un cero y memmove hasta 
                  llegar al \0
                - retornar new_str

        si no los tiene
            retorna new_str
    
    si no tiene - al inicio
        si tiene al menos 2
            mientras el char en cuestion sea cero, memmove
        si no tiene al menos 2 char
            retornar new_str

    OJO: FREE(STR) 

    -3
    -0
    -0212
    -- (fix it with flags true/false)
    90-3434 (check it, could be a bug)

    */
    if (new_str[0] == '-'){
        if (strlen(new_str) > 2){
            while(new_str[1] == '0'){
                memmove(new_str + 1, new_str + 2, strlen(new_str + 2) + 1);
            }
            return new_str;
        } else {
            return new_str;
        }        
    }

    if (strlen(new_str) > 1){
        while(new_str[0] == '0'){
            memmove(new_str, new_str + 1, strlen(new_str + 1) + 1);
        }
    }  
    
    return new_str;
}

int str_to_int(const char* str, int* out)
{
    if (!check_valid_str(str)) return -1;
    
    char* temp = remove_leading_zeros(str);
    if (temp == NULL) return -1;

    int total = 0;
    if (str[0] == '-'){
        total = convert_to_int(str, 1) * -1;
    } else {
        total = convert_to_int(str, 0);
    }

    //Overflow, underflow detection

    *out = total;
    free(temp);
    return 0;    
}
