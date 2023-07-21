#include  <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void AddAbonent()
{
int i=0;
printf("Name: "); scanf("%s",&PhoneBook1[i].Name);
printf("Family: "); scanf("%s", &PhoneBook1[i].Family);
printf("Phone: "); scanf("%s",&PhoneBook1[i].NumberPhohne);
i++;
}

/*
void RemoveAbonent()
{
return 0;
}
void FindAbonent()
{
return 0;
}
void FuulPhoneBook()
{
}
*/

int main() 
{
struct PhoneBook
{
char Name[24];
char Family[24];
char NumberPhone[12];
};
struct PhoneBook *PhoneBook1;
PhoneBook1=(struct PhoneBook*)malloc(10 *sizeof(struct PhoneBook));
char input;
while(1)
{
printf("Main Menu\n");
printf("Choose what function you want do\n");
printf("1)ADD ABONENT\n");
printf("2)REMOVE ABONENT\n");
printf("3)FIND ABONENT\n");
printf("4)WATCH FULL PHONE BOOK\n");
printf("5)END PROGRAMM\n");
input=getchar();

switch(input)
{
case '1': AddAbonent(); break;
/*case '2': RemoveAbonent(PhoneBook1);break;
case '3': FindAbonent(PhoneBook1);break;
case '4': FullPhoneBook(PhoneBook1);break;
case '5': return 0; */
default: printf("Wrong text\n");
}


}


return 0;
}

