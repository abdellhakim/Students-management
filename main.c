#include <stdio.h>
#include <stdlib.h>

typedef struct etudiant
{
    char nom[20];
    char prenom[20];
    int age;
    char CNE[10];
    int groupe;
    float ds;
    float bd;
    float os;
    float math;
} etudiant;

typedef struct Student
{
    etudiant data;
    struct Student*next;
} Student;




//------------la fonction pour afficher la  liste-------------
void afficheListe(Student* debut)
{
    Student* temp = debut;
    int count=0;
    if (debut == NULL)
    {
        printf("La liste est vide\n");
    }
    else
    {
        printf("\nLe nombre des etudiants est :%d\n",compterEtudiants(debut));
        while (temp != NULL)
        {


            printf(" stud %d / *Nom:  %10s  *Prenom:  %8s  *Age:  %2d  *Groupe:  %2d  *CNE:  %7s\n",count+1,
                   temp->data.nom, temp->data.prenom, temp->data.age, temp->data.groupe, temp->data.CNE);
            temp = temp->next;
            count++;
        }
    }
}

//-----------la fonction pour ajouter un element a la fin d'une liste-----------
Student *ajouterALaFin(Student *debut,etudiant element)
{

    Student *b,*temp;
    b=(Student *)malloc(sizeof(Student));
    b->data=element;
    b->next=NULL;
    if(debut==NULL)
    {
        debut=b;
    }
    else
    {
        temp=debut;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=b;
    }
    return debut;
}


//----------------la suppression -------------------------
Student* Supprimer(Student* debut, char CNE[10])
{
    Student* temp = debut;
    Student* prev = NULL;

    while (temp != NULL && strcmp(temp->data.CNE, CNE) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        // CNE not found in list
        printf("l'etudiant n'exit pas");
        return debut;
    }
    else if (prev == NULL)
    {
        // CNE au debut du list
        debut = temp->next;
        free(temp);
        return debut;
    }
    else
    {
        // CNE au milieu du list
        prev->next = temp->next;
        free(temp);
        return debut;
    }
}

//---------------fonction recherche----------------------
Student* Recherche(Student* L, char* CNE)
{
    Student* p = L;
    while (p != NULL && strcmp(p->data.CNE, CNE) != 0)
    {
        p = p->next;
    }
    return p;
}

//----------------Compter le nombre des etudiants de la liste----------------
int compterEtudiants(Student*debut)
{
    int count=0;
    Student*p=NULL;
    if(debut==NULL)
        printf("la liste est vide");
    p=debut;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}
//-----------------------fonction qui calcule la moyenne--------------
float moyenne_notes(Student* debut)
{
    float Somme=0;
float moyen=0;
    Student* temp=debut;
    while(temp!=NULL)
    {
        Somme+=temp->data.bd+temp->data.ds+temp->data.os+temp->data.math;
        temp=temp->next;
    }
   moyen=  Somme /4;

        return moyen;
    }

//-----------------------fonction qui tri les etudiants--------------
void trier_Etudiants(Student* debut)
{

    if (debut == NULL || debut->next == NULL)
        return 0 ;

    int swapped;
    Student* tmp;
    Student* ptmp = NULL;

    do
    {
        swapped = 0;
        tmp = debut;

        while (tmp->next != ptmp)
        {
            if (strcmp(tmp->data.CNE, tmp->next->data.CNE) > 0)
            {
                // swap data of adjacent nodes
                etudiant ptr = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = ptr;
                swapped = 1;
            }
            tmp = tmp->next;
        }
        ptmp = tmp;
    }
    while (swapped);
}
int main()
{
    Student* debut = NULL;
    Student*temp= NULL;
    etudiant etud;
    char choix;
    int choix1;
    int q;
    int run;
    char CNE[10];
    int n,i,j=0;
    printf("\t\n\t--------------------Menu--------------------\n");

    printf("\n\t\t1:Ajouter un etudiant \n\t\t2:Chercher un etudiant \n\t\t3:Supprimer un etudiant\n\t\t4:Calculer la moyeen\n\t\t5:Trier les etudiants\n\t\t6:Quitter\n\n");
    scanf("%d",&run);
    system("cls");
    if(run==1)
    {

        do
        {
            printf("\nEntrer les informations de l'etudiant %d :\n",i+1);
            printf ("Nom: ");
            scanf("%s", &etud.nom);
            printf ("Prenom: ");
            scanf("%s", &etud.prenom);
            printf ("Age: ");
            scanf("%d", &etud.age);
            printf ("Groupe: ");
            scanf("%d", &etud.groupe);
            printf ("CNE: ");
            scanf("%s", &etud.CNE);

            printf("la note du module bs:");
            scanf("%f",&etud.ds);
            printf("la note du module bd:");
            scanf("%f",&etud.bd);
            printf("la note du module os:");
            scanf("%f",&etud.os);
            printf("la note du module math:");
            scanf("%f",&etud.math);

            debut = ajouterALaFin(debut, etud);
            i++;
            printf("\nVous voulez entrer un autre etudiant? (y/n)");
            scanf(" %c", &choix);
        }
        while (choix != 'n');
        system("cls");

        printf("\n----Informations des etudiants----\n");
        afficheListe(debut);
        printf("\n--------------------------------------\n");
        do
        {
            printf("\n1: Ajouter un etudiant\n");
            printf("2:Rechercher un etudiant \n");
            printf("3:Supprimer un etudiant\n");
            printf("4:Trier les etudiants\n");
            printf("5:Calculer la moyeen\n");
            printf("6:Quiter\n");
            scanf("%d",&choix1);
            system("cls");
            switch(choix1)
            {
            case 2 :
                printf("\nEnter le CNE de l'etudiant que vous voulez chercher : ");
                scanf("%s", CNE);

                Student* result = Recherche(debut, CNE);
                if (result != NULL)
                {
                    printf("\nEtudiant existe:\n\n");
                    printf("Nom: %s\n", result->data.nom);
                    printf("Prenom: %s\n", result->data.prenom);
                    printf("Age: %d\n", result->data.age);
                    printf("Groupe: %d\n", result->data.groupe);
                    printf("CNE: %s\n", result->data.CNE);
                }
                else
                {
                    printf("\nEtudiant n'existe pas \n");
                }
                break;
            case 3 :
                printf("\nEnter le CNE de l'etudiant que vous voulez supprimer : ");
                scanf("%s", CNE);
                debut = Supprimer(debut, CNE);
                printf("\nListe des etudiants apres la suppression:\n");
                afficheListe(debut);
                break;
            case 1 :
                do
                {
                    printf("\nEntrer les informations de l'etudiant %d :\n",i+1);
                    printf ("Nom: ");
                    scanf("%s", &etud.nom);
                    printf ("Prenom: ");
                    scanf("%s", &etud.prenom);
                    printf ("Age: ");
                    scanf("%d", &etud.age);
                    printf ("Groupe: ");
                    scanf("%d", &etud.groupe);
                    printf ("CNE: ");
                    scanf("%s", &etud.CNE);
                    printf("la note du module bs:");
                    scanf("%f",&etud.ds);
                    printf("la note du module bd:");
                    scanf("%f",&etud.bd);
                    printf("la note du module os:");
                    scanf("%f",&etud.os);
                    printf("la note du module math:");
                    scanf("%f",&etud.math);
                    debut = ajouterALaFin(debut, etud);
                    i++;
                    printf("\nVous voulez ajouter un autre etudiant ? (y/n)");
                    scanf(" %c", &choix);
                }
                while (choix != 'n');
                system("cls");
                printf("\n----Informations des etudiants----\n\n");
                afficheListe(debut);
                break;
            case 4 :
                trier_Etudiants(debut);
                afficheListe(debut);
                break;
            case 5:
                printf("\nEntrer le CNE de l'etudiant : ");
                scanf("%s", CNE);
                Student* result1 = Recherche(debut, CNE);
                if (result1 != NULL)
                {
                    printf("\nEtudiant existe:\n\n");
                    printf("Nom: %s\n", result1->data.nom);
                    printf("Prenom: %s\n", result1->data.prenom);
                    printf("moyeen: %.3f\n", moyenne_notes(result1));
                    if (moyenne_notes(result1)< 6)
                        printf("*non valide\n");
                    else if (moyenne_notes(result1) < 12)
                        printf("*rattrapage\n");
                    else
                        printf("*valide\n");
                }
                else
                {
                    printf("\nL'etudiant n'existe pas.\n");
                }
                break;
            case 6 :  printf(" merci de votre exucution!"); return 0 ;
                break;
            default :
                printf("le choix est invalide\n") ;
            }
        }
        while(1);



    }else if(run!=6)
    printf("\n     la liste est vide\n");

    return 0;
}
