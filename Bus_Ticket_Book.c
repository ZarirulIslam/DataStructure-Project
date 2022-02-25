#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    char b[50];
    char c[20];
    char d[20];
    struct Node *next;
} node;
node *temp;
node *head;
node *s;
int seatno;
int passenger_count=0;
void creatnode()
{
    node *newNode;
    newNode=(node*)malloc(sizeof(node));
    newNode->data=seatno;
    printf("You name : ");
    scanf("%s",newNode->b);
    printf("Your mobile number : ");
    scanf("%s",newNode->c);
    printf("Your destination : ");
    scanf("%s",newNode->d);
    newNode->next = NULL;
    if(head==NULL)
    {
        head=newNode;
        passenger_count++;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        passenger_count++;
    }
}
void edit_list()
{
    int n;
    char b[50];
    char c[20];
    char d[20];
    printf("Enter sit number : ");
    scanf("%d",&n);
    temp=head;
    while(temp!= NULL && n!=temp->data)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Sorry! this seat is not booked\nTry again\n");
        edit_list();
    }
    else
    {
        printf("Enter Name : ");
        scanf("%s",b);
        strcpy(temp->b,b);
        printf("Enter Mobile number : ");
        scanf("%s",c);
        strcpy(temp->c,c);
        printf("Enter your Destination : ");
        scanf("%s",d);
        strcpy(temp->d,d);

    }
}
void total_empty_sit()
{
    int i;
    int count=0;
    temp=head;
    while(temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    count=40-count;
    printf("Total empty sit :%d\n",count);
    if(count==40)
    {
        for(i=1; i<=40; i++)
        {
            printf("%d no. sit is empty !\n",i);
        }
    }
    printf("\n\n\n");

}
void empty_sits()
{
    int count=0;
    printf("Enter sit no. that you want : ");
    scanf("%d",&seatno);

    if(head==NULL)
    {
        creatnode();
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==seatno)
            {
                count++;
            }
            temp=temp->next;
        }
        if(count==0)
        {
            creatnode();
        }
        else if(count>0)
        {
            printf("sorry! %d no. sit is booked\n",seatno);
        }
    }
    printf("\n\n");
}
void printlist()
{
    int count=0;
    temp=head;
    while(temp != NULL)
    {
        count++;
        printf("Passenger's sit : %d\n",temp->data);
        printf("Passenger's name : %s\n",temp->b);
        printf("Mobile Number : 0%s\n",temp->c);
        printf("Destination : %s\n",temp->d);
        temp=temp->next;
    }
    printf("\n\n\n");
}

void delete()
{
    int a;
    temp=head;
    printf("Enter your sit number : ");
    scanf("%d",&a);
    if(a==head->data)
    {
        head=head->next;
        free(temp);
        passenger_count--;

    }
    else
    {
        node *p;
        while(temp!= NULL && a!=temp->data)
        {
            p=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("Sorry! this seat is not booked\n");
            delete();
        }
        else
        {
            p->next=temp->next;
            free(temp);
        }
        passenger_count--;
    }
}
int main()
{
    int n,i,p;
    printf("\t\t\t\tWelcome to Private Transportation Limited\n");
    printf("\t\t\t________________________________________________________\n\n\n");
    printf("How many operation you want : ");
    scanf("%d",&n);
    printf("\n\n\n");
    for(i=0; i<n; i++)
    {
        printf("Operation no : %d\n\n\n",i+1);
        printf("About us(press 1)\n");
        printf("Want to see the total no. of empty sit(s) (press 2)\n");
        printf("Want to book a sit (press 3)\n");
        printf("Want to cancel a a booking (press 4)\n");
        printf("Want to see to total booking (press 5)\n");
        printf("Want to edit booking (press 6)\n");
        scanf("%d",&p);
        if(p==1)
        {
            printf("This is Private Transportation Limited\n");
            printf("We provide faster and 24 hour transportation service\n");
            printf("Owner of our company is Zarirul,Hadi,Nahid.\n");
            printf("\n\n\n");
        }
        else if(p==2)
        {
            total_empty_sit();
        }
        else if(p==3)
        {
            empty_sits();
        }
        else if(p==4)
        {
            delete();
        }
        else if(p==5)
        {
            if(passenger_count==0)
            {
                printf("No seat are booked\n");
                printf("Our bus is empty. You can book a seat\n");
            }
            else
            {
                printlist();
            }
        }
        else if(p==6)
        {
            if(passenger_count==0)
            {
                printf("No seat are booked\n");
                printf("Our bus is empty. You can book a seat\n");
            }
            else
            {
                edit_list();
            }
        }
    }
    return 0;
}
