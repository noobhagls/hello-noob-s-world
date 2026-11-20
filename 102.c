#include <stdio.h>
int main(void){
    int n;
    int result = 1;
    int i = 1;
    scanf("%d",&n);
    while(i <= n){
        result = result * i;
        i++;
    }
    printf("%d\n",result);
    return 0;
}