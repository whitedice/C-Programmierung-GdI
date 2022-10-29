#include<stdio.h>


int carry = 0;
int halfadd( int A, int B ){
    carry = A & B;
    return A ^ B;
}
int fulladd( int A, int B ){
    int xor = A ^ B;
    int ret = carry ^ xor;
    carry = (carry & xor) | (A & B);
    return ret;
}

void fillNum( int num, int *array ){
    int i;
    for( i = 0; i < 4; ++ i ){
        array[i] = ( num >> i ) & 1;
    }
}

int main(){
    int num1[4] = {0}, num2[4] = {0};
    num1[0] = 0;
    num1[1] = 0;
    num1[2] = 1;
    num1[3] = 0;

    num2[0] = 0;
    num2[1] = 0;
    num2[2] = 0;
    num2[3] = 1;
    //int num1[4] = {0}, num2[4] = {0};
    //int A = 0010, B = 0001;
    //fillNum( A, num1 );
    //fillNum( B, num2 );

    int r = 0;
    int tmp = halfadd( num1[0], num2[0] );
    putchar( tmp ? '1' : '0' );
    r = tmp;
    int i;
    for( i = 1; i < 4; ++i ){
        tmp = fulladd( num1[i], num2[i] );
        r += tmp << i;
        putchar( tmp ? '1' : '0' );
    }
    putchar( carry ? '1' : '0' );

    printf("\n%d\n\n%d + %d = %d", r);
    //printf("\n%d\n\n%d + %d = %d", r, A, B, A+B);
    return 0;
}