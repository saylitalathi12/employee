#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void add();
void emp_display();
void emp_remove();
void emp_update();
void manager_login();
void employee_login();
void sort();
void search();
void remov();
void menu1();
void menu2();
//void count();
void empp();
void sort1();
void salary();
char file[20];
typedef struct Employee
{
	char fname[20];
	char mname[20];
	char lname[20];
	char address[20];
	int  bdate[20];
	char sex[20];
	char sub_taken[20];
	char last_edu[20];
	char join_date[20];
	
	int id;
	int age;
	int bsal;
	
}Employee;
FILE *outfile,*infile,*fr;
Employee emp;
int main()
{




	//FILE *outfile,*infile;
	int choice1;
	while(1){
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LOGIN AS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\n1.manager\n2.employee\n3.exit\n");
		scanf("%d", &choice1);
		switch(choice1) {
			case 1:
				manager_login();
				break;
			case 2:
				employee_login();
				break;
			case 3:
                                exit(1);
                	default :
                        	printf("Wrong choice");
                       		break;

		}
	}
}
void manager_login() {
	char pwd[20],user[20];
	char fname[20]="manager";
	printf("Enter username and password for manager login\n");
	scanf("%s %s", user,pwd);
	if(strcmp(user,fname)==0) {
		if(strcmp(pwd,fname)==0){
			menu1();
		}
		else {
			printf("please enter correct username and password\n");
		}
	}	
}

void employee_login() {
	char pwd[20],user[20];
	char fname[20]="employee";
	printf("Enter username and password for employee  login\n");
	scanf("%s %s", user,pwd);
	if(strcmp(user,fname)==0) {
		if(strcmp(pwd,fname)==0){
			menu2();
		}
		else {
			printf("please enter correct username and password\n");
		}
	}	
}
void menu1(){
	int choice;
	while(1)
	{
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<EMPLOYEE MANAGEMENT SYSTEM>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
		printf("\n1.Add Records in new file\n2.Delete Records\n3.Modify Records\n4.ListRecords\n5.Sort on id\n6. calculate salary of every empoyee\n7.search record on name\n8.view salary of every employy\n9.sort by name\n10.remove file.\n0.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				add();
				break;
			case 2:
				emp_remove();
				break;
			case 3:
				emp_update();
				break;
			case 4:
				emp_display();
				break;
			case 5:
				sort();
				break;
			case 6:
				salary();
				break;
			case 7:
				search();
				break;
			case 8:
				empp();
				break;
			case 9:
				sort1();
				break;
			
			case 10: 
				remov();
				break;
			case 0:
				exit(1);
				break;
			
			
			default:
				printf("wrong choice");
				break;
		}
	}
	
}
void menu2(){
	int choice2;
	while(1)
	{
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<EMPLOYEE MANAGEMENT SYSTEM>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("1.ListRecords\n2.Sort on id\n3.sort on name\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice2);
		switch(choice2)
		{
	
			case 1:
				emp_display();
				break;
			case 2:
				sort();
				break;
			case 3:
				sort1();
				break;
			case 4:	
				exit(1);
				break;
			default:
				printf("wrong choice");
				break;
		}
	}

}
void add(){
		int n,i;
		outfile = fopen ("dataa.dat","a+");
		 if (outfile == NULL)
     		{
      			fprintf(stderr, "\nError empty file\n\n");
     			exit (1);
     		}
		printf("Enter number of records you want to add:\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
     		{
      			printf("enter id:");
			scanf("%d",&emp.id);
			printf("Enter first name:");
                        scanf("%s",emp.fname);        		
			printf("Enter  middle name: ");
                        scanf("%s",emp.mname);
                        printf("Enter  last name: ");
                        scanf("%s",emp.lname);
                        printf("Enter the address: ");
                        scanf("%s",emp.address);
                        printf("Enter the sex: ");
                        scanf("%s",emp.sex);
                        printf("Enter the age: ");
                        scanf("%d",&emp.age);
                        printf("Enter the basic_salary: ");
                        scanf("%d",&emp.bsal);
                        printf("Enter the joining_date: ");
                        scanf("%s",emp.join_date);
                      	printf("Enter the last_education: ");
                        scanf("%s",emp.last_edu);
                        printf("Enter the subject_taken: ");
                      	scanf("%s",emp.sub_taken);
     			fwrite (&emp, sizeof(emp), 1, outfile);
     			
		}
		fclose(outfile);
}

void salary(){
	int ta,da,sal;
        int id;
 	//char fname[20];
        label2:outfile=fopen("dataa.dat","rb");
	 if(outfile==NULL)
                {
                        fprintf(stderr, "\nError opening empty file\n\n");
                        exit (1);
                }
		printf("ENTER 0 TO STOP CALCULATING SALARY\n");
	label1:printf("enter id of employ to calculate  salary\n");
       		scanf("%d",&id);
		if(id==0)
			menu1();
        while(fread(&emp,sizeof(emp),1,outfile)){
                if(id==emp.id){
			da=(10*emp.bsal)/100;
      		        ta=(12*emp.bsal)/100;
        		sal=emp.bsal+da+ta;
			printf("|id\t| Name\t|  Basicsalary\t|  da\t|  ta\t|  salary\t|   \n");

			printf("|%-10d| %-10s| %-10d| %-10d| %-10d| %-10d|\n",emp.id,emp.fname, emp.bsal,da,ta,sal);
			goto label1;
		}
        }
	if(id!=emp.id && id!=0){
	        printf("\n EMPLOYEE OF SUCH ID  DOESNOT EXISTS\n");
		goto label2;
        	
	}
}
void emp_display(){
		outfile = fopen ("dataa.dat","a+");
		if(outfile==NULL)
      		{
      			fprintf(stderr, "\nError opening empty file\n\n");
      			menu1();
    		}
		printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DATA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("id\t| Name\t| middle_name\t|  last_name\t|  Address\t| Sex\t|   Age\t| Basicsalary\t|  Joint_date\t|  Last_education\t| Subject_taken\t|\n");

		while (fread (&emp, sizeof(emp), 1, outfile)==1)
			 
			printf(" |%-10d| %-10s| %-10s| %-10s| %-10s| %-10s|   %-10d| %-10d| %-10s| %-10s| %-10s|\n",emp.id,emp.fname, emp.mname, emp.lname, emp.address ,emp.sex ,emp.age, emp.bsal,emp.join_date,emp.last_edu,emp.sub_taken);		

}
void remov(){
   	int status;
   	char file_name[25];
	printf("Enter the name of file you wish to delete\n");
   	scanf("%s",file_name);
 	status = remove(file_name);
 	if( status == 0 )
     		 printf("%s file deleted successfully.\n",file_name);
   	else
   	{
      		printf("Unable to delete the file\n");
      		perror("Error\n");
   	}
 
}
void empp(){
	int ta[20],da[20];
	int i,sal[20],bsal[20];
	int id[20];
	char name[20][20];
                outfile = fopen ("dataa.dat","a+");
                if(outfile==NULL)
                {
                        fprintf(stderr, "\nError opening empty file\n\n");
                        exit (1);
                }
		printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DATA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("id\t| Name\t| da\t| ta\t| Basicsalary\t| salary\t|\n");
		while(fread(&emp,sizeof(emp),1,outfile))
        	{
               		 i=1;
                	id[i]=emp.id;
                	strcpy(name[i],emp.fname);
			bsal[i]=emp.bsal;
              		da[i]=(10*emp.bsal)/100;
                	ta[i]=(12*emp.bsal)/100;
			sal[i]=emp.bsal+da[i]+ta[i];
                	printf("%d\t %s\t %d\t %d\t %d\t %d\t\n",id[i],name[i],da[i],ta[i],bsal[i],sal[i]);
                	i++;	
        	}
}
void emp_remove(){
	char fname[20];
	printf("Enter the first name of the employee to be deleted : ");
	scanf("%s",fname);
	infile=fopen("temp.dat","wb");
	rewind(outfile);
	while(fread(&emp,sizeof(emp),1,outfile)==1){
		if(strcmp(emp.fname,fname)!=0)
			fwrite(&emp,sizeof(emp),1,infile);
		}
	fclose(outfile);
	fclose(infile);
	remove(file);
	rename("temp.dat","dataa.dat");
	outfile=fopen("dataa.dat","rb+");
	printf("record deleted successfully\n");
}
void emp_update(){
	int records=0;
	outfile=fopen("dataa.dat","rb+");
	char empname[20];
	printf("Enter the employee fname to modify: ");
        scanf("%s", empname);
        rewind(outfile);	
        while(fread(&emp,sizeof(emp),1,outfile)==1){/// fetch all record from file
		if(strcmp(emp.fname,empname) == 0){///if entered name matches with that in file
                	printf("\nEnter new fname,mname,lname,address,sex,bs,jointdate,age,id,last_education,subject_taken: ");
                	
			scanf("%s%s%s%s%s%d%d%s%d%s%s",emp.fname, emp.mname, emp.lname, emp.address ,emp.sex ,&emp.age, &emp.bsal,emp.join_date,&emp.id,emp.last_edu,emp.sub_taken);
			fseek(outfile,sizeof(emp)*records,SEEK_SET); /// move the cursor 1 step back from current position
	 	                 
          		fwrite(&emp,sizeof(emp),1,outfile); /// override the record
                 }
		records++;
         }
}
void sort(){
	int a[20],count=0,i,j,t,c;
        outfile=fopen("dataa.dat","r");
        while(fread(&emp,sizeof(emp),1,outfile))
        {
            a[count]=emp.id;
            count++;
        }
        c=count;
        for(i=0;i<count-1;i++){
		for(j=i+1;j<count;j++)
            	{
                	if(a[i]>a[j])
                	{
                   	 	t=a[i];
                    		a[i]=a[j];
                    		a[j]=t;
                	}
            	}
        }
         printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SORTED_DATA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("|id\t| Name\t|  middle_name\t|  last_name\t|  Address\t| Sex\t|  Age\t| Basicsalary\t|  Joint_date\t|  Last_education\t| Subject_taken\t|\n");
	count=c;
        for(i=0;i<count;i++){
		rewind(outfile);
            	while(fread(&emp,sizeof(emp),1,outfile)==1){
                	if(a[i]==emp.id)
                  		printf("\n|%-10d| %-10s| %-10s| %-10s| %-10s| %-10s| %-10d| %-10d| %-10s| %-10s| %-10s|\n",emp.id,emp.fname, emp.mname, emp.lname, emp.address ,emp.sex ,emp.age, emp.bsal,emp.join_date,emp.last_edu,emp.sub_taken);
	    	}

	}
}
void sort1(){
	char a[20][20];
	int count=0,i,j,c;
	char t[20];
        outfile=fopen("dataa.dat","r");
        while(fread(&emp,sizeof(emp),1,outfile))
        {
		strcpy(a[count],emp.fname);
        	count++;
        }
        c=count;
        for(i=1;i<count;i++){
		for(j=1;j<count;j++){
            		if(strcmp(a[j-1],a[j])>0){
                	
                   	 	strcpy(t,a[j-1]);
                    		strcpy(a[j-1],a[j]);
                    		strcpy(a[j],t);
                	}
            	}
        }
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DATA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("|id\t| Name\t|  middle_name\t|  last_name\t|  Address\t| Sex\t|  Age\t| Basicsalary\t|  Joint_date\t|  Last_education\t| Subject_taken\t|\n");
	count=c;
        for(i=0;i<count;i++){
		rewind(outfile);
            	while(fread(&emp,sizeof(emp),1,outfile)==1){
                	if(strcmp(a[i],emp.fname)==0)
                  		printf("\n|%-10d| %-10s| %-10s| %-10s| %-10s| %-10s| %-10d| %-10d| %-10s| %-10s| %-10s|\n",emp.id,emp.fname, emp.mname, emp.lname, emp.address ,emp.sex ,emp.age, emp.bsal,emp.join_date,emp.last_edu,emp.sub_taken);
	    	}

	}
}
void search(){
	char fname[20];
	outfile=fopen("dataa.dat","rb");
	printf("Search record\n");
        printf("enter name of employ to search: \n");
	scanf("%s",fname);
        while(fread(&emp,sizeof(emp),1,outfile)){
		if(strcmp(fname,emp.fname)==0){
       			printf("\nRECORD EXISTS AND DETAILS ARE :\n");
			printf("|%-10d| %-10s| %-10s| %-10s| %-10s| %-10s| %-10d| %-10d| %-10s| %-10s| %-10s|\n",emp.id,emp.fname, emp.mname, emp.lname, emp.address ,emp.sex ,emp.age, emp.bsal,emp.join_date,emp.last_edu,emp.sub_taken);
        
		}
	}
 	if(strcmp(fname,emp.fname)!=0){
		printf("\n RECORD DOESNOT EXISTS\n");
       		//fclose(outfile);
 	}
}

