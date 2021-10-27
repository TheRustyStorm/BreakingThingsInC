#include <stdio.h>

// + add
// - subtract
// * multiply
// / divide
// % modulo (23 % 4 == 3, 16 % 5 == 1, 10 % 4 == 2)
// == (two '=' check if something is equal)
int sum_of_numbers(int x) {
    int sum = 0;
    for(int i = 0; i < x; i++){
        sum = sum + i;
    }
    return sum;
}

int main(){
    int result = sum_of_numbers(23);
    printf("%i\n",result);
}
