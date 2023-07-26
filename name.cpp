//read the data from file 'cities.txt' containing
//sorted names of cities & their STD codes. accept a name
//of the city from user & use binary search algorithm
//to check whether the name is present in the file & output
//the STD code,otherwise output "city not in the list".
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cities
{
	char cname[20];
	int stdcode;
}c1[100];
int main()
{
	FILE *fp1;
	int n,flag=0,top,mid,bottom,i=0,scode;
	char name[20],x[20];
	fp1=fopen("cities.txt","r");
	if(fp1==NULL)
	{
	printf("not found");
	exit(0);
	}
while(!feof(fp1))
{
	fscanf(fp1,"%s%d",&name,&scode);
	strcpy(c1[i].cname,name);
	c1[i].stdcode=scode;
	i++;
}
n=i;
printf("enter city name to search=");
scanf("%s",&x);
top=0;
bottom=n-1;
while(top<=bottom)
{
	mid=top+bottom/2;
	if(strcmp(x,c1[mid].cname)==0)
	{
		flag=1;
		break;
	}
	if(strcmp(x,c1[mid].cname)>0)
	top=mid+1;
	else
	bottom=mid-1;
}
if(flag==1)
printf("STD code=%d",c1[mid].stdcode);
else
printf("city not found in the list");
fclose(fp1);
}
