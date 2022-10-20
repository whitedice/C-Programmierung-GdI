#include<stdio.h>

typedef char bit;
bit carry = 0;
bit halfadd( bit A, bit B ){
    carry = A & B;
    return A ^ B;
}
bit fulladd( bit A, bit B ){
    bit xor = A ^ B;
    bit ret = carry ^ xor;
    carry = (carry & xor) | (A & B);
    return ret;
}

void fillNum( int num, bit *array ){
    int i;
    for( i = 0; i < 4; ++ i ){
        array[i] = ( num >> i ) & 1;
    }
}

int main(){
    bit num1[4] = {0}, num2[4] = {0};
    int A = 2, B = 3;
    fillNum( A, num1 );
    fillNum( B, num2 );

    int r = 0;
    bit tmp = halfadd( num1[0], num2[0] );
    putchar( tmp ? '1' : '0' );
    r = tmp;
    int i;
    for( i = 1; i < 4; ++i ){
        tmp = fulladd( num1[i], num2[i] );
        r += tmp << i;
        putchar( tmp ? '1' : '0' );
    }
    putchar( carry ? '1' : '0' );
    printf("\n%d\n\n%d + %d = %d", r, A, B, A+B);
    return 0;
}