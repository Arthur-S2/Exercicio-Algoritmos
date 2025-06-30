/*
UNIVALI
Graduação Turma 1 Noturno
Disciplina: Introdução à Ciencia da Computação
Prof. Lucas Debatin, MSc.
Trabalho 4
Alunos: Arthur Sá, Ruan Gomes Pacheco, Erick Luiz, Igor Moreira, Rafael Fernandes
*/
#include <stdio.h>
#include <string.h>

float calcular_media(float n1, float n2, float n3)
{
    return (n1 + n2 + n3) / 3.0f;
}

int main()
{
    int i = 0;
    char alunos[5][120];
    float media[5];
    float n1[5], n2[5], n3[5];
    do
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i], 50, stdin);
        size_t len = strlen(alunos[i]);
        if (len > 0 && alunos[i][len - 1] == '\n')
        {
            alunos[i][len - 1] = '\0';
        }

        printf("Digite as 3 notas do aluno %s: ", alunos[i]);
        float nota1, nota2, nota3;
        scanf("%f %f %f", &nota1, &nota2, &nota3);
        n1[i] = nota1;
        n2[i] = nota2;
        n3[i] = nota3;

        media[i] = calcular_media(nota1, nota2, nota3);
        i++;

        if (i < 5)
        {
            printf("Deseja cadastrar mais um aluno? (1 - Sim, 0 - Nao): ");

            int continuar;
            scanf("%d", &continuar);
            getchar();
            if (continuar == 0)
            {
                break;
            }
        }
        else
        {
            break;
        }

    } while (i < 5);

    float maior_media = media[0];
    int z = 0;
    for (int j = 1; j < i; j++)
    {
        if (media[j] > maior_media)
        {
            maior_media = media[j];
            z = j;
        }
    }
    printf("\n");
    printf("%-20s %-10s %-10s %-10s %-10s %-10s\n", "ALUNO", "N1", "N2", "N3", "MEDIA", "SITUACAO");
    for (int j = 0; j < i; j++)
    {
        printf("%-20s %-10.2f %-10.2f %-10.2f %-10.2f %-10s\n",
               alunos[j], n1[j], n2[j], n3[j], media[j],
               (media[j] >= 7.0f) ? "Aprovado" : "Reprovado");
    }
    printf("\nAluno com a maior media: %s (%.2f)", alunos[z], maior_media);
    return 0;
}
