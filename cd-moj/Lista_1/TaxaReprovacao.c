#include <stdio.h>

int main() {
    int num_disciplinas;
    scanf("%d", &num_disciplinas);

    int ano, semestre, num_aulas;
    int codigo, alunosMatriculados, alunosAprovados;

    while (scanf("%d %d %d", &ano, &semestre, &num_aulas) != EOF) {

        int reprovados_por_codigo[num_disciplinas];
        for (int i = 0; i < num_disciplinas; i++) {
            reprovados_por_codigo[i] = -1; 
        }

        int maiorReprovados = -1;

        for (int i = 0; i < num_aulas; i++) {
            scanf("%d %d %d", &codigo, &alunosMatriculados, &alunosAprovados);
            int alunosReprovados = alunosMatriculados - alunosAprovados;

            reprovados_por_codigo[codigo] = alunosReprovados;

            if (alunosReprovados > maiorReprovados) {
                maiorReprovados = alunosReprovados;
            }
        }
        printf("%d/%d\n", ano, semestre);

        for (int i = 0; i < num_disciplinas; i++) {
            if (reprovados_por_codigo[i] == maiorReprovados) {
                printf("%d ", i);
            }
        }

        printf("\n\n");
    }

    return 0;
}
