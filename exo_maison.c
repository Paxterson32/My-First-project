#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 9
#define M 2
/*******************************Prototypes************************************/
void affiche_tab(char**);
char **tri_bulle(char**, int);
char **Remplir_tableau(char**);
/*******************************************************************************/

int main()
{
    char **tab;
    //char tab[N][M];
    int i;
    /*******************************construction du tableau a deux dimensions et remplissage************************************/
    tab = (char**)malloc(N*sizeof(char*));
    for(i=0;i<N;i++)
        tab[i] = (char*)malloc(M*sizeof(char));
    //Remplissage
    tab = Remplir_tableau(tab);
    /**************************************************************************************************************************/
    /*****************************************************Traitement*******************************************************************/
    printf("Vous avez saisi : \n");
    affiche_tab(tab);
    printf("\n");

    tab = tri_bulle(tab,1);//Premier tri

    printf("Apres la premiere phase : \n");
    affiche_tab(tab);

    tab = tri_bulle(tab,2);

    printf("\nApres la deuxieme phase : \n" );
    affiche_tab(tab);
    /*****************************************************************************************************************************************/
    return 0;

}

char **Remplir_tableau(char **tableau)
{
    int i;
        printf("Elements du tableau : \n");
    for(i=0;i<N;i++){
        printf("Mot[%d] = ",i+1);
        scanf("%s",tableau[i]);
    }
    return tableau;
}

void affiche_tab(char **tableau)
{
    int i;
    for(i=0;i<N;i++)
    printf("%s ",tableau[i]);
}

char **tri_bulle(char **tableau, int pos) //Pos designe la position des elements a classer dans l'ordre alphabetique
{
    int i, permute;
    char temp[M];
    do
    {
        permute = 0;
        for(i=0;i<N-1;i++)
        {
            if(strncmp(tableau[i], tableau[i+1],pos) > 0) // Si le premier element de tableau i succede le premier element de tableau i+1
            {
                //permute tab de i+1 et tab i puis affecter a permute 1
                strcpy(temp, tableau[i]);
                strcpy(tableau[i], tableau[i+1]);
                strcpy(tableau[i+1], temp);
                permute =1;
            }
        }
    } while (permute !=0);//La boucle s'arrete si on a effectue aucune permutation

    return tableau;
    
}
