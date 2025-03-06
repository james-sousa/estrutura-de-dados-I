int numero(int n){
    if(n < 0){
        return 0;
    }

    return numero + (numero(n % 10));
}

int main(int argc, char const *argv[])
{
    int num,resultado;
    scanf("%d",&num);
    resultado = numero(num);
    printf("N: %d",resultado);
    return 0;
}
