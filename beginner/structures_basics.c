#include <stdio.h>

/*
Basics
* The variables named in a structure are called members.
* A structure member or tag and an ordinary (i.e., non-member) variable can have the same name without conflict,
since they can always be distinguished by context.
* A struct declaration defines a type.
* The right brace that terminates the list of members may be followed by a list of variables, just as for any basic
type. ex: struct { ... } x, y, z;
* A structure declaration that is not followed by a list of variables reserves no storage; it merely describes a
template or the shape of a structure. If the declaration is tagged, however, the tag can be used later in definitions
of instances of the structure.
* A member of a particular structure is referred to in an expression by a construction of the form structure-name.member
* Structures can be nested.
 */

struct point makepoint(int, int);
struct point addpoint(struct point, struct point);

/* 
* creating a structure suitable for graphics. It has a x and y coordinate, both integers.
*/ 
struct point {
    int x;
    int y;
};
struct rect {
    struct point pt1;
    struct point pt2;
};

int main(int argc, char *argv[]){

    // defines a variable pt which a structure of type struct point
    struct point pt1 = {1, 2};
    struct point pt2 = makepoint(3, 4);

    printf("pt1 x: {%d}, y: {%d}\n", pt1.x, pt1.y);
    printf("pt2 x: {%d}, y: {%d}\n", pt2.x, pt2.y);
    printf("Adding both of these points => x: {%d}\n", (addpoint(pt1, pt2).x));

    // pp is a pointer to a structure of type struct point
    struct point *pp = &pt1;
    printf("pp x: {%d}, y: {%d}\n", (*pp).x, (*pp).y);

}

// make a point from x and y components
struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

// add two points
struct point addpoint(struct point pt1, struct point pt2){
    pt1.x += pt2.x;
    pt2.y += pt2.y;
    return pt1;
}

