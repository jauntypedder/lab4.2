#include <stdio.h>
#include <stdlib.h>


void print_arr( int **A, int **B, int M, int N);
void max(int **A,int M,int N);
void sum_of(int **A,int **B,int M,int N);
void prod(int **A,int **B,int **Prod,int M,int N);
void trans(int **B,int **T,int M,int N);
void sort(int **A,int M,int N);



int main()
{
    int variant_1,variant_2,M,N;
    int **A = NULL;
    int **B=NULL;
    int **Prod=NULL;
    int **T=NULL;

    printf("\nEnter size of:");
    printf("\nLines:");
    scanf("%d", &M);
    printf("\nColumns:");
    scanf("%d", &N);
    system("cls");

    A=(int**) malloc(M * sizeof(int));
    for(int i=0;i<M;i++){
        A[i]=(int*) malloc(M * sizeof(int));
    }

    B=(int**) malloc(N * sizeof(int));
    Prod=(int**) malloc(N * sizeof(int));
    T=(int**) malloc(M * sizeof(int));

    for(int i=0;i<N;i++){
        B[i]=(int*) malloc(M * sizeof(int));
        Prod[i]=(int*) malloc(M * sizeof(int));
        T[i]=(int*) malloc(M * sizeof(int));
    }

    do{
    printf("Fill:\n1.Auto\n2.Manually\n");
    scanf("%d",&variant_1);
    }while(variant_1 != 1 && variant_1 != 2);
    system("cls");
    if(variant_1==2){
    printf("Mat A:\n");
        for (int i=0;i<M;i++)
        {
            for (int j=0;j<M;j++){
            printf("A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);
            }
        }
    printf("Mat B:\n");
        for (int i=0;i<M;i++)
        {
            for (int j=0;j<N;j++){
            printf("B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
            }
        }
    }
    else{
        for (int i=0;i<M;i++){
            for (int j=0;j<M;j++){
                A[i][j]= rand()%101;
            }
        }
        for (int i=0;i<M;i++){
            for (int j=0;j<N;j++){
                B[i][j]= rand()%101;
            }
        }
    }
    print_arr(A, B, M, N);

    do{
        printf("\nChoose action:\n1.Maximum of A \n2.Transpose B\n3.AxB\n4.Sort A\n5.A+B\n");
        scanf("%d",&variant_2);
    }while(variant_2 != 1 && variant_2 != 2 && variant_2 != 3 && variant_2 != 4 && variant_2 != 5);
    system("cls");

    switch (variant_2){
    case 1:
        max(A,M,N);
    break;

    case 2:
        trans(B,T,M,N);
    break;

    case 3:
        printf("AxB\n");
        prod(A,B,Prod,M,N);
    break;

    case 4:
        sort(A,M,N);
    break;

    case 5:
        sum_of(A,B,M,N);
    break;
    }

 return 0;
}



void print_arr( int **A, int **B, int M, int N){

printf("A:\n");

for (int i=0;i<M;i++){
    for (int j=0;j<M;j++)
    {
        printf("%3d ", A[i][j]);
    }
    printf("\n");
}

printf("B:\n");

for (int i=0;i<M;i++){
    for (int j=0;j<N;j++){
        printf("%3d ", B[i][j]);
    }
    printf("\n");
}

}



void max(int **A,int M,int N){
int maximal= 0;

for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
        if (A[i][j] > maximal){
            maximal = A[i][j];
        }
    }
}
printf("\nMax value A: %d\n",maximal);
}



void trans(int **B,int **T,int M,int N){
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            T[j][i] = B[i][j];
        }
    }
printf("\nTransposition of B:\n");
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            printf("%3d ", T[i][j]);
        }
    printf("\n");
    }
}



void prod(int **A,int **B,int **Prod,int M,int N){
     for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                Prod[i][j]=0;
                for(int p=0;p<M;p++){
                    Prod[i][j] += A[i][p] * B[p][j];
                }
            }
        }

        for (int i=0;i<M;i++){
            for (int j=0;j<N;j++)
            {
                printf("%3d ", Prod[i][j]);
            }
        printf("\n");
        }
}



void sort(int **A,int M,int N){

int variant;
int temp;

    do{
        printf("\nSort:\n1.Matrix\n2.Line\n");
        scanf("%d", &variant);
    }while(variant!=1 && variant!=2);
    if (variant == 1){
        for(int k = 0; k < M * N; ++k) {
            for(int i = 0; i < M; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(j != N - 1) {
                        if(A[i][j+1] < A[i][j]) {
                            int temp = A[i][j+1];
                            A[i][j+1] = A[i][j];
                            A[i][j] = temp;
                        }
                    }

                }
            }
        }

    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++){
            printf("%3d ", A[i][j]);
        }
    printf("\n");
    }
}
if(variant == 2){
int sort = 0;

printf("\nEnter the line to sort: ");
scanf("%d",&sort);
    for(int k=1;k<M;k++)
    {
        for(int j=0;j<M-k;j++){
            if(A[sort][j]>A[sort][j+1]){
                temp = A[sort][j];
                A[sort][j] = A[sort][j+1];
                A[sort][j+1] = temp;
            }
        }
    }

    for(int j=0;j<M;j++){
        printf("%3d ",A[sort][j]);
    }
}
}



void sum_of(int **A,int **B,int M,int N){

int sum;

    for(int i=0;i<M;i++){
    sum=0;
        for(int j=0;j<N;j++){
            sum = sum + A[i][j];
        }
    printf("\nSum line:%d  A=%d",i,sum);
    }

    for(int j=0;j<N;j++){
        sum=0;
            for(int i=0;i<M;i++){
                sum = sum + B[i][j];
            }
    printf("\nSum column:%d  B=%d",j,sum);
    }
}





