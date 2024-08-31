/*Implement the following functions to access the details of a particular student from a list of n students. Use three functions as follows.
a. Get the details of n students.
i. Roll number
ii. Name
iii. Programme
iv. CGPA
b. Sort the list based on their roll number
c. Search for a particular student’s details. (Use minimum number of comparison)*/


#include <stdio.h>
struct student{
    int Roll_Number;
    char Student_Name[80];
    char Student_Programme[80];
    int Student_Marks;
};
void Input(struct student list[80], int s){
    int i;
    for(i=0;i<s;i++)
    {
        printf("\nDetails of Student %d\n", i+1);
        printf("Enter Roll_Number       : ");
        scanf("%d", &list[i].Roll_Number);
        fflush(stdin);
        printf("Enter Student Name      : ");
        gets(list[i].Student_Name);
		printf("Enter Student Programme : ");
        gets(list[i].Student_Programme);
        printf("Enter Student Marks     : ");
        scanf("%d", &list[i].Student_Marks);
    } 
}
void Display(struct student list[80], int s){
    int i;
    printf("\n\nRollno\tName\tProgramme\tMarks\n");
    for(i=0;i<s;i++){
        printf("%d\t%s\t%s\t\t%d\n",list[i].Roll_Number,list[i].Student_Name,
		list[i].Student_Programme,list[i].Student_Marks);
    } 
}
void Search(struct student list[80], int s, int number){
    int i;
    for(i=0;i<s;i++){
        if (list[i].Roll_Number == number){
            printf("Roll Number\t: %d\nName\t\t: %s\nProgramme\t: %s\nMarks\t\t: %d\n",list[i].Roll_Number,
			list[i].Student_Name,list[i].Student_Programme,list[i].Student_Marks);
            return ;
        } 
    }
    printf("Student Details not Found\n");
}
void Sort(struct student list[80],int s){
    int i,j;
    struct student temp;
    for(i=0;i<s-1;i++){
        for(j=0;j<(s-1-i);j++){
            if(list[j].Roll_Number<list[j+1].Roll_Number){
                temp=list[j];
                list[j]=list[j + 1];
                list[j+1]=temp;
            } 
        }
    }
}
int main(){
    struct student data[20];
    int n,choice,Roll_Number;
    printf("Number of Students : ");
    scanf("%d", &n);
    Input(data, n);
    printf("\nDisplaying Details of the Students\n");
    Display(data, n);
    printf("\nSorting");
    Sort(data, n);
    Display(data, n);
    printf("\nEnter Roll Number to Search : ");
    scanf("%d", &Roll_Number);
    Search(data, n, Roll_Number);
    return 0;
}
