#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool valid_num(const char digit);
static bool check_valid_str(const char* str);
static bool valid_str_num(const char* str, size_t index);
static bool num_and_sign(const char* str);

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

// assume size is at least >= index, str not null, str not empty
static bool valid_str_num(const char* str, size_t index){
    for (size_t i = index; str[i] != '\0'; i++){ 
        if (!valid_num(str[i])){
            return false;
        }
    }
    
    return true;
}

//si el primero no es signo, deben ser solo numeros 
//si el primero es - o mas, el resto puros numeros, pero no debe haber menos de 2 elementos

static bool num_and_sign(const char* str)
{
    if (str[0] == '-'){
        if (strlen(str) < 2){
            return false;
        } 
        
        if (!(valid_str_num(str, 1))){
            return false;
        }
    }

    return valid_str_num(str, 0);
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

int str_to_int(const char* str, int* out)
{
    if (!check_valid_str(str)) return -1;

    int total = 0;
    if (str[0] == '-'){
        total = convert_to_int(str, 1) * -1;
    } else {
        total = convert_to_int(str, 0);
    }

    *out = total;
    return 0;    
}
