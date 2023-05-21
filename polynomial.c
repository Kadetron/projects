#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        int coef;
        int exp;
        struct node * next;
}x,y,z;
void createX(x * head, int c, int e)
{
        x * ptr=head;
        x * n=(x *)malloc(sizeof(x));
        while(ptr->next!=NULL)
                ptr=ptr->next;
        ptr->next=n;
        n->next=NULL;
        n->coef=c;
        n->exp=e;
}
void createY(y * head, int c, int e)
{
        y * ptr=head;
        y * n=(y *)malloc(sizeof(y));
        while(ptr->next!=NULL)
                ptr=ptr->next;
        ptr->next=n;
        n->next=NULL;
        n->coef=c;
        n->exp=e;
}
void sum(x * xhead,y * yhead,z * zhead)
{
        x * X=xhead;
        y * Y=yhead;
        z * Z=zhead;
        z * n;
        while(X!=NULL&&Y!=NULL)
        {
                n=(z *)malloc(sizeof(z));
                Z->next=n;
                n->next=NULL;
                if(X->exp==Y->exp)
                {
                        Z->coef=(X->coef)+(Y->coef);
                        Z->exp=X->exp;
                        X=X->next;
                        Y=Y->next;
                }
                else if(X->exp>Y->exp)
                {
                        Z->coef=X->coef;
                        Z->exp=X->exp;
                        X=X->next;
                }
                else
                {
                        Z->coef=Y->coef;
                        Z->exp=Y->exp;
                        Y=Y->next;
                }
                Z=Z->next;
        }
        while(X!=NULL)
        {
                n=(z *)malloc(sizeof(z));
                Z->next=n;
                n->next=NULL;
                Z->coef=X->coef;
                Z->exp=X->exp;
                X=X->next;
                Z=Z->next;
        }
        while(Y!=NULL)
        {
                n=(z *)malloc(sizeof(z));
                Z->next=n;
                n->next=NULL;
                Z->coef=Y->coef;
                Z->exp=Y->exp;
                Y=Y->next;
                Z=Z->next;
        }
}
void displayZ(z * head)
{
        printf("(");
        z * ptr=head;
        while(ptr->next!=NULL)
        {
                if(ptr->exp!=0&&ptr->next->next!=NULL)
                {
                        printf("%dx^%d + ",ptr->coef,ptr->exp);
                }
                else if(ptr->exp==0)
                {
                        printf("%d",ptr->coef);
                }
                else
                {
                        printf("%dx^%d",ptr->coef,ptr->exp);
                }
                ptr=ptr->next;
        }
        printf(")\n");
}
void displayX(x * head)
{
        printf("(");
        x * ptr=head;
        int swapE,swapC;
        x * nptr;
        while(ptr!=NULL)
        {
                for(nptr=head;nptr!=NULL;nptr=nptr->next)
                {
                        if(ptr->exp>=nptr->exp)
                        {
                                swapC=ptr->coef;
                                swapE=ptr->exp;
                                ptr->coef=nptr->coef;
                                ptr->exp=nptr->exp;
                                nptr->coef=swapC;
                                nptr->exp=swapE;
                        }
                }
                ptr=ptr->next;
        }
        ptr=head;
        while(ptr!=NULL)
        {
                if(ptr->exp!=0&&ptr->next!=NULL)
                {
                        printf("%dx^%d + ",ptr->coef,ptr->exp);
                }
                else if(ptr->exp==0)
                {
                        printf("%d",ptr->coef);
                }
                else
                {
                        printf("%dx^%d",ptr->coef,ptr->exp);
                }
                ptr=ptr->next;
        }
        printf(")");
}
void displayY(y * head)
{
        printf("(");
        y * ptr=head;
        int swapE,swapC;
        y * nptr;
        while(ptr!=NULL)
        {
                for(nptr=head;nptr!=NULL;nptr=nptr->next)
                {
                        if(ptr->exp>=nptr->exp)
                        {
                                swapC=ptr->coef;
                                swapE=ptr->exp;
                                ptr->coef=nptr->coef;
                                ptr->exp=nptr->exp;
                                nptr->coef=swapC;
                                nptr->exp=swapE;
                        }
                }
                ptr=ptr->next;
        }
        ptr=head;
        while(ptr!=NULL)
        {
                if(ptr->exp!=0&&ptr->next!=NULL)
                {
                        printf("%dx^%d + ",ptr->coef,ptr->exp);
                }
                else if(ptr->exp==0)
                {
                        printf("%d",ptr->coef);
                }
                else
                {
                        printf("%dx^%d",ptr->coef,ptr->exp);
                }
                ptr=ptr->next;
        }
        printf(")");
}
int main()
{
        x * xhead=(x *)malloc(sizeof(x));
        y * yhead=(y *)malloc(sizeof(y));
        z * zhead=(z *)malloc(sizeof(z));
        xhead->next=NULL;
        xhead->coef=0;
        yhead->next=NULL;
        yhead->coef=0;
        zhead->next=NULL;
        zhead->coef=0;
        int n,c,e;
        char q;
        printf("Expression X:\n");
        while(1)
        {
            q=' ';
            printf("Enter the coeficient:");
            scanf("%d",&c);
            printf("Enter the exponent:");
            scanf("%d",&e);
            if(xhead->coef==0)
            {
                xhead->coef=c;
                xhead->exp=e;
            }
            else
                createX(xhead,c,e);
            system("cls");
            printf("X:");
            displayX(xhead);
            printf("\nAdd more?[y/n]:");
            scanf(" %c",&q);
            if(q=='n'||q=='N')
            {
                system("cls");
                printf("X:");
                displayX(xhead);
                break;
            }
        }
        printf("\nExpression Y:\n");
        while(1)
        {
            q=' ';
            printf("Enter the coeficient:");
            scanf("%d",&c);
            printf("Enter the exponent:");
            scanf("%d",&e);
            if(yhead->coef==0)
            {
                yhead->coef=c;
                yhead->exp=e;
            }
            else
                createY(yhead,c,e);
            system("cls");
            printf("Y:");
            displayY(yhead);
            printf("\nAdd more?[y/n]:");
            scanf(" %c",&q);
            if(q=='n'||q=='N')
            {
                system("cls");
                printf("X:");
                displayX(xhead);
                break;
            }
        }
        printf("\nY:");
        displayY(yhead);
        printf("\nsum: ");
        sum(xhead,yhead,zhead);
        displayZ(zhead);
        return 0;
}
