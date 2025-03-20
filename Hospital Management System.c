#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

// Struct for Patient Information
struct patient
{
    int patientid;
    char name [50];
    int age;
    char gen[20];
    int phn;
    char ins_name [50];
    char allergies [50];
};


// Struct for Medical Records
struct medi_rec
{
    int medid;
    char name[50];
    int age;
    char gen[10];
    char ins_name [50];
    char allergies [50];
    char prob [50];
    char dname [50];
};

int pat_id = 100; //global variable

// Function to register a new patient
void pat_reg(struct patient p[],int size)
{
    pat_id=pat_id+1;
    p[size].patientid= pat_id;
    printf("\nEnter Patient's Full Name: ");
    scanf(" %[^\n]",p[size].name);
    printf("Enter Patient's Age: ");
    scanf(" %d",&p[size].age);
    printf("Enter Patient's Gender: ");
    scanf(" %[^\n]",&p[size].gen);
    while(1) // Loop until a valid 10-digit phone number is entered
    {
        printf("Enter Patient's Phone Number (Start after 0) : 0");
        scanf("%d",&p[size].phn);
        if(p[size].phn>9999999999 || p[size].phn<100000000)
        {
            printf("Invalid Phone Number!\n");
        }
        else
        {
            break;// Valid phone number, break the loop
        }
    }
    printf("Enter Insurance Name: ");
    scanf(" %[^\n]",p[size].ins_name);
    printf("Describe the allergies in 50 words or less: ");
    scanf(" %[^\n]",p[size].allergies);
}

// Function to view all patient records
void viewpatient(struct patient p[],int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("\n");
        printf("Patient ID: %d\n", p[i].patientid);
        printf("Patient Name: %s\n", p[i].name);
        printf("Patient's age: %d\n", p[i].age);
        printf("Patient's Gender: %s\n", p[i].gen);
        printf("Contact Number: %d\n", p[i].phn);
        printf("Insurance : %s\n",p[i].ins_name);
        printf("Allergies: %s\n",p[i].allergies);
    }
}

// Function to search for a patient by ID
void searched(struct patient p[],int size,int id)
{
    int i,flag=0;
    for(i=0; i<size; i++)
    {
        if (id == p[i].patientid)
        {
            flag=1;
            printf("\n");
            printf("Patient ID: %d\n", p[i].patientid);
            printf("Patient Name: %s\n", p[i].name);
            printf("Patient's age: %d\n", p[i].age);
            printf("Patient's Gender: %s\n", p[i].gen);
            printf("Contact Number: %d\n", p[i].phn);
            printf("Insurance : %s\n",p[i].ins_name);
            printf("Allergies: %s\n",p[i].allergies);

        }
    }
    if(flag==0)
    {
        printf("Invalid Patient ID!!!\n");
    }
}

// Function to update patient details
void update (struct patient p[],int size,int id)
{
    int i,a,b,flag=0;
    for(i=0; i<size; i++)
    {

        if (id == p[i].patientid)
        {
            flag=1;
            printf("1) Update Patient's Name\n");
            printf("2) Update Patient's Age\n");
            printf("3) Update Patient's Gender\n");
            printf("4) Update Patient's Insurance\n");
            printf("5) Update Patient's Allergies\n");
            printf("0) Return to main menu\n");
            printf("Select an option from the menu: ");
            scanf("%d",&a);
            switch (a)
            {

            case 1:
            {
                printf("Enter Patient's Updated Name: ");
                scanf(" %[^\n]", p[i].name);
                printf("Successfully Updated...");
                printf("\n");
                break;

            }
            case 2:
            {
                printf("Enter Patient's Updated age: ");
                scanf("%d", &p[i].age);
                printf("Successfully Updated...");
                printf("\n");
                break;
            }
            case 3:
            {
                printf("Change Patient's Gender: ");
                scanf(" %[^\n]", p[i].gen);
                printf("Successfully Updated...");
                printf("\n");
                break;
            }
            case 4:
            {
                printf("Enter Patient's Updated Insurance: ");
                scanf(" %[^\n]", p[i].ins_name);
                printf("Successfully Updated...");
                printf("\n");
                break;
            }
            case 5:
            {
                printf("Enter Patient's Updated Allergies: ");
                scanf(" %[^\n]", p[i].allergies);
                printf("Successfully Updated...");
                printf("\n");
                break;
            }
            default:
            {
                continue;
            }
            }
        }
    }
    if(flag==0)
    {
        printf("Invalid Patient ID!!!\n");
    }
}

// Function to delete patient details by ID
void dlt(struct patient p[],int size,int id)
{
    int i,flag=0;
    char d;
    for(i=0; i<size; i++)
    {
        if (id == p[i].patientid)
        {
            flag=1;
            printf("Are you Sure you want to Delete Patient ID %d (Y/N): ",p[i].patientid);
            scanf(" %c",&d);
            if(d=='y'||d=='Y')
            {
                p[i]=p[size+1];//patient info te null copy hoy.
                printf("Patient id %d is successfully deleted\n",id);

            }
            else if (d=='n'||d=='N')
            {
                break;
            }

        }
    }
    size--;
    if(flag==0)
    {
        printf("Invalid Patient Id/n");
    }


}
void addmed(struct patient p[],struct medi_rec m[],int medi_size,int m_id,int size)
{
    int i,flag=0;
    for(i=0; i<=medi_size; i++)
    {
        if(p[i].patientid == m_id)
        {
            flag=1;
            m[medi_size].medid = p[i].patientid;
            strcpy(m[medi_size].name,p[i].name);
            m[medi_size].age=p[i].age;
            strcpy(m[medi_size].gen,p[i].gen);
            strcpy(m[medi_size].ins_name,p[i].ins_name);
            strcpy(m[medi_size].allergies,p[i].allergies);
            printf("Enter Patient's Diagnosis: ");
            scanf(" %[^\n]",m[medi_size].prob);
            printf("Enter Appointed Doctor: ");
            scanf(" %[^\n]",m[medi_size].dname);
            printf("Patient Record Successfully Created\n");
        }
    }
    if(flag==0)
    {
        printf("Invalid Patient Id!!\n");
    }
}

void viewmed(struct patient p[],struct medi_rec m[],int medi_size,int size)
{
    int i;
    for(i=0; i<medi_size; i++)
    {
        printf("\n");
        printf("Patient's Id : %d\n",m[i].medid);
        printf("Patient's Name : %s\n",m[i].name);
        printf("Patient's Age : %d\n",m[i].age);
        printf("Patient's Gender : %s\n",m[i].gen);
        printf("Patient's Insurance : %s\n",m[i].ins_name);
        printf("Patient's Allergies : %s\n",m[i].allergies);
        printf("Patient's Diagnosis : %s\n",m[i].prob);
        printf("Patient's Appointed Doctor : %s\n",m[i].dname);
        printf("\n");
    }
}
void searchedmed(struct patient p[],struct medi_rec m[],int medi_size,int m_id,int size)
{
    int i,flag=0;
    for(i=0; i<medi_size; i++)
    {
        if(m_id == m[i].medid)
        {
            flag=1;
            printf("\n");
            printf("Patient's Id : %d\n",m[i].medid);
            printf("Patient's Name : %s\n",m[i].name);
            printf("Patient's Age : %d\n",m[i].age);
            printf("Patient's Gender : %s\n",m[i].gen);
            printf("Patient's Insurance : %s\n",m[i].ins_name);
            printf("Patient's Allergies : %s\n",m[i].allergies);
            printf("Patient's Diagnosis : %s\n",m[i].prob);
            printf("Patient's Appointed Doctor : %s\n",m[i].dname);
            printf("\n");
        }
    }
    if(flag==0)
    {
        printf("Invalid Id!!\n");
    }
}
void editmed(struct patient p[],struct medi_rec m[],int medi_size,int m_id,int size)
{
    int i,flag=0;
    for(i=0; i<medi_size; i++)
    {
        if(m_id == m[i].medid)
        {
            flag=1;
            printf("Enter Patient's Diagnosis: ");
            scanf(" %[^\n]",m[i].prob);
            printf("Enter Appointed Doctor: ");
            scanf(" %[^\n]",m[i].dname);
            printf("Patient Record Successfully Updated\n");
        }
    }
    if(flag==0)
    {
        printf("Invalid Input!!\n");
    }
}
void dltmed(struct patient p[],struct medi_rec m[],int medi_size,int m_id,int size)
{
    int i,flag=0;
    char d;
    for(i=0; i<medi_size; i++)
    {
        if(m_id == m[i].medid)
        {
            flag=1;
            printf("Are you Sure you want to Delete Patient Id %d (Y/N): ",p[i].patientid);
            scanf(" %c",&d);
            if(d=='y'||d=='Y')
            {
                m[i]=m[size+1];
                printf("Medical Record Patient id %d is successfully deleted\n",m_id);
            }
            else if (d=='n'||d=='N')
            {
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("Invalid Id!!\n");
    }

}

void flreports1(struct patient p[],struct medi_rec m[],int medi_size,int size)
{
    int i;
    FILE *file1;
    file1 = fopen("Patient Report.txt","w");
    fprintf(file1,"%d\n",medi_size);//bondho kore khulleo jeno paoa jay
    for(i=0; i<size; i++)
    {
        fprintf(file1,"\n");
        fprintf(file1,"Patient's Id : %d\n",p[i].patientid);
        fprintf(file1,"Patient's Name : %s\n",p[i].name);
        fprintf(file1,"Patient's Age : %d\n",p[i].age);
        fprintf(file1,"Patient's Gender : %s\n",p[i].gen);
        fprintf(file1,"Patient's Contact Number: %d\n", p[i].phn);
        fprintf(file1,"Patient's Insurance : %s\n",p[i].ins_name);
        fprintf(file1,"Patient's Allergies : %s\n",p[i].allergies);
        fprintf(file1,"Patient's Diagnosis : %s\n",m[i].prob);
        fprintf(file1,"Patient's Appointed Doctor : %s\n",m[i].dname);
        printf("File Successfully Genarated..\n");
        fprintf(file1,"\n");
    }
    fclose(file1);
}
void flreports2(struct patient p[],struct medi_rec m[],int size)
{
    int i,medi_size2;

    FILE *file1;
    file1 = fopen("Patient Report.txt","r");
    fscanf(file1,"%d\n",&medi_size2);
    for(i=0; i<medi_size2; i++)
    {
        fscanf(file1,"\n");
        fprintf(stdout,"\n");
        fscanf(file1,"Patient's Id : %d\n",&p[i].patientid);
        fprintf(stdout,"Patient's Id : %d\n",p[i].patientid);
        fscanf(file1,"Patient's Name : %[^\n]\n",p[i].name);
        fprintf(stdout,"Patient's Name : %s\n",p[i].name);
        fscanf(file1,"Patient's Age : %d\n",&p[i].age);
        fprintf(stdout,"Patient's Age : %d\n",p[i].age);
        fscanf(file1,"Patient's Gender : %[^\n]\n",p[i].gen);
        fprintf(stdout,"Patient's Gender : %s\n",p[i].gen);
        fscanf(file1,"Patient's Contact Number: %d\n", &p[i].phn);
        fprintf(stdout,"Patient's Contact Number: %d\n", p[i].phn);
        fscanf(file1,"Patient's Insurance : %[^\n]\n",p[i].ins_name);
        fprintf(stdout,"Patient's Insurance : %s\n",p[i].ins_name);
        fscanf(file1,"Patient's Allergies : %[^\n]\n",p[i].allergies);
        fprintf(stdout,"Patient's Allergies : %s\n",p[i].allergies);
        fscanf(file1,"Patient's Diagnosis : %[^\n]\n",m[i].prob);
        fprintf(stdout,"Patient's Diagnosis : %s\n",m[i].prob);
        fscanf(file1,"Patient's Appointed Doctor : %[^\n]\n",m[i].dname);
        fprintf(stdout,"Patient's Appointed Doctor : %s\n",m[i].dname);
        printf("File Successfully Loaded..\n");
        fscanf(file1,"\n");
        fprintf(stdout,"\n");
    }
    fclose(file1);
}

int main()
{
    printf("\t\t\tWelcome to INDRA Hospital Management System....");

    int menu,sub,pat_size=0,med_size=0;
    struct patient pat[1000];

    struct medi_rec medic [1000];
    while(1)
    {
        printf("\n\n\t\t\t\t\t Main Menu\n");
        printf("\n");
        printf("1) Patient Management\n");
        printf("2) Medical Records\n");
        printf("3) Reports & Analytics\n");
        printf("4) Exit\n");
        printf("\n");
        printf("Please Select an Option from the Menu to Proceed: ");
        scanf("%d",&menu);
        if(menu==1)
        {
            printf("\n1)Patient Management:\n");
            printf("   1) Patient Registration.\n");
            printf("   2) View All Patient Records.\n");
            printf("   3) Search Patient Record.\n");
            printf("   4) Update Patient Information.\n");
            printf("   5) Delete Patient Record.\n");
            printf("   0) Return To Main Menu.\n\n");
            printf("Please select an option from the sub-menu: ");
            scanf("%d",&sub);
            if(sub==0)
            {
                continue;
            }
            else if(sub==1)
            {
                printf("\nPatient Registration: ");
                printf("\n");
                while(1)
                {
                    char ch;
                    pat_reg(pat,pat_size);
                    printf("Patient ID %d Successfully Added\n",pat_id);
                    pat_size++;
                    printf("Do You Want To Register Another Patient (Y/N): ");
                    scanf(" %c",&ch);
                    if(ch=='n'||ch=='N')
                    {
                        printf("\n");
                        printf("\n");
                        break;
                    }
                    else if(ch=='y'||ch=='Y')
                    {
                        continue;
                    }
                    else
                    {
                        printf("Invalid Input!!\n");
                    }
                }
            }
            else if (sub==2)
            {
                printf("\n");
                printf("\n");
                viewpatient(pat,pat_size);
            }
            else if (sub==3)
            {
                int userid;
                printf("Enter Patient Id :");
                scanf("%d",&userid);
                printf("\n");
                searched(pat,pat_size,userid);
                printf("\n");

            }
            else if(sub==4)
            {
                int userid2;
                printf("Enter Patient Id :");
                scanf("%d",&userid2);
                printf("\n");
                update(pat,pat_size,userid2);
            }
            else if(sub==5)
            {
                int userid3;
                printf("Enter Patient Id :");
                scanf("%d",&userid3);
                printf("\n");
                dlt(pat,pat_size,userid3);
            }

            else
            {
                printf("Invalid Input!!\n");
            }

        }
        else if(menu==2)
        {
            printf("\n");
            printf("3) Medical Report:\n");
            printf("   1) Add A New Medical Record.\n");
            printf("   2) View All Medical Record.\n");
            printf("   3) Search a Medical Record\n");
            printf("   4) Edit a Medical Record.\n");
            printf("   5) Delete a Medical Record.\n");
            printf("   0) Return To Main Menu.\n");
            printf("Please select an option from the sub-menu: ");
            scanf("%d",&sub);
            if(sub==0)
            {

                continue;
            }

            else if(sub==1)
            {
                printf("\nMedical Record : ");
                printf("\n");
                while(1)
                {
                    int uerid;
                    char ch3;
                    printf("Enter Patient ID to Create a Medical Record: ");
                    scanf("%d",&uerid);
                    addmed(pat,medic,med_size,uerid,pat_size);
                    med_size++;
                    printf("Do You Want To Create Another Patient Record? (Y/N): ");
                    scanf(" %c",&ch3);
                    if(ch3=='n'||ch3=='N')
                    {
                        printf("\n");
                        printf("\n");
                        break;
                    }
                    else if(ch3=='y'||ch3=='Y')
                    {
                        continue;
                    }
                    else
                    {
                        printf("Invalid Input!!\n");

                    }
                }


            }
            else if(sub==2)
            {
                printf("\n");
                printf("\n");
                viewmed(pat,medic,med_size,pat_size);

            }
            else if(sub==3)
            {
                int uerid1;
                printf("\nEnter Patient Id: ");
                scanf("%d",&uerid1);
                printf("\n");
                searchedmed(pat,medic,med_size,uerid1,pat_size);
                printf("\n");
            }
            else if(sub==4)
            {
                int uerid2;
                printf("\nEnter Patient Id: ");
                scanf("%d",&uerid2);
                printf("\n");
                editmed(pat,medic,med_size,uerid2,pat_size);
                printf("\n");
            }
            else if(sub==5)
            {
                int uerid3;
                printf("\nEnter Patient Id: ");
                scanf("%d",&uerid3);
                printf("\n");
                dltmed(pat,medic,med_size,uerid3,pat_size);
                printf("\n");
            }
            else
            {
                printf("Invalid Input!!\n");
            }



        }
        else if(menu==3)
        {
            printf("4) Reports & Analytics:\n");
            printf("   1) Search & Generate a All Patient Report.\n");
            printf("   2) Load Patient Record. \n");
            printf("   0) Return To Main Menu.\n");
            printf("Please select an option from the sub-menu: ");
            scanf("%d",&sub);
            if(sub==0)
            {
                continue;
            }
            else if(sub==1)
            {
                flreports1(pat,medic,med_size,pat_size);
            }
            else if(sub==2)
            {
                flreports2(pat,medic,pat_size);
                printf("\n");

            }
            else
            {
                printf("Invalid Input!!\n");
            }
        }
        else if(menu==4)
        {
            break;
        }
        else
        {
            printf("Invalid Input!!\n");
        }

    }
}
