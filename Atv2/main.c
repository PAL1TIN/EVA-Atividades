    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>


    int raizes(float a, float b, float c, float *x1, float *x2){



        float delta = b*b - (4 * a * c );
        if (delta > 0){
         *x1 = (-b + sqrt(delta))/ 2 * a;
         *x2 = (-b - sqrt(delta))/ 2 * a;
         return 2;
        }else{
            if(delta == 0){
                *x1 = (-b + sqrt(delta))/ 2 * a;
                *x2 = *x1;
                return 1;
            }else{
               printf("NAO EXISTE");
               return 0;
            }
        }
    }


    int main()
    {
        float a, b, c, r1, r2;
        int res;
        printf("Digite o valor de A: ");
        scanf("%f", &a);

        if(a>0){
            printf("Digite o valor de B: ");
            scanf("%f", &b);
            printf("Digite o valor de C: ");
            scanf("%f", &c);
            res = raizes(a, b, c, &r1, &r2);


            if (res == 2) {
                printf("Há duas raízes reais: %.2f e %.2f\n", r1, r2);
            }else if (res == 1) {
                printf("Há uma raiz real: %.2f\n", r1);
                } else {
                    printf("Não há raízes reais.\n");
                    }



        } else {
            printf("Nao existe glr");
        }

        return 0;
    }
