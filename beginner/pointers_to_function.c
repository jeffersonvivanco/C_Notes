#include <stdio.h>
#include <string.h>

/*
* int (*)(void *, void *): says that this parameter is a pointer to a function that has two void * arguments and
returns an int.
 */
int compare_elements(void *, void *, int (*)(void *, void *));
int numcmp(int *, int *);

int main() {
    // testing with strings
    char str1[] = "Apple";
    char str2[] = "Banana";

    /*
    * The elaborate cast of the function argument casts the arguments of the comparison function. These will generally
    have no effect on actual representation, but assure the compiler that all is well.
     */
    int cmp1 = compare_elements(str1, str2, (int (*)(void *, void *))strcmp);
    printf("%s compared to %s is: {%d}\n", str1, str2, cmp1);
    
    int int1 = 2;
    int int2 = 2;
    printf("%d compared to %d is: {%d}\n", int1, int2, compare_elements(&int1, &int2, (int (*)(void *, void *)) numcmp));

}

// note: last parameter is a pointer to a functon that returns an int and take two parameters
int compare_elements(void *element1, void *element2, int (*cmp)(void *, void *)){
    /*
    * Using the function cmp that is passed to this function.
    * This use is consistent with the declaration: cmp is a pointer to a function, *cmp is the function, and
    (*cmp)(element1, element2) is the call to it.
     */
    return (*cmp)(element1, element2);
}

int numcmp(int *x, int *y) {
    if (*x < *y) return -1;
    else if (*x > *y) return 1;
    else return 0;
}
