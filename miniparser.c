#include <stdio.h>
#include <stdbool.h>

static bool valid_num(const char digit);
static bool check_valid_str(const char* str);

static bool check_valid_str(const char* str)
{
    /*CONSTAINTS*/
    //NULL and empty str constraint
    if (str == NULL || str[0] == '\0') return false;
    
    //Check numbers and negative sign
    for(int i = 0; str[i] != '\0'; i++){
        if (!valid_num(str[i])){
            return false;
        }      
    }

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

int str_to_int(const char* str, int* out)
{
    if (!check_valid_str(str)) return -1;

    int total = 0;
    for(int i = 0; str[i] != '\0'; i++){
        int new = str[i] - '0';
        total = total*10 + new;
    }
    
    *out = total;
    return 0;    
}
