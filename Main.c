#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct directory{
    char c_name[30];
    char hs_name[30];
    char locality[30];                                           //STRUCTURE DECLARATION
    char dist[30];
    char s_pr[30];
    long long int phone_no;
}details[200];

struct space{
    char dup_name[30];
};                                                          


                                                     //NAME VALIDATION FUNCTION                                                      

int valid_name(char *dup)
{
    int j,flag=1;
    j = strlen(dup);
    for(int i=0;i<j;i++)
    {
        if(!(isalpha(*(dup+i)) || isspace(*(dup+i))))                                                      
        {
            flag=0;
            break;
        }
        
        
    }
    if(!flag)
        {
            printf("\nEnter the valid details and make sure that \nname should contain only alphabets...\n\n");
        }
    return(flag);
}


                                                     //SERVICE VALIDATION

int valid_sevice(char *dup)
{
    int flag=0;
    if(!strcmp(dup,"JIO"))
    {
        flag=1;
    }
    else if(!strcmp(dup,"BSNL"))
    {
        flag=1;
    }
    else if(!strcmp(dup,"VI"))
    {
        flag=1;
    }
    else if(!strcmp(dup,"AIRTEL"))
    {
        flag=1;
    }
    else
    {
        printf("\nEnter the valid service providers shown in the list...\n\n");
    }
    return (flag);
}


                                                     //PHONE NUMBER VALIDATION

                                                     
int valid_ph_no(long long int dup)
{
    int count=0,flag=1;
    while(dup!=0)  
   {  
       dup=dup/10;  
       count++;                                                 //Counting number of digits
   }
   if(count!=10)
   {
      flag=0;
      printf("\nEnter the valid 10 digit phone number....\n\n");
      return(flag);
   }
   else if(count==10)
   {
     return(flag);
   }
}








                                                     //ADD CUSTOMER FUNCTION



void Add_customer(struct directory details[],int max_size,int sz)                  //FUNCTION DEFINITION(Add_customer)
{
    int k,j;
    printf("%d\n",sz);
    printf("Enter the details\n");
    
    do{
    printf("Customer Name: ");
    scanf(" %[^\n]s",details[sz].c_name);                                                   //ADDING CUSTOMER
    k = valid_name(details[sz].c_name);
    }while(!k);
    
    do{
    printf("\nHouse Name: ");
    scanf(" %[^\n]s",details[sz].hs_name);
    k = valid_name(details[sz].hs_name);
    }while(!k);
    
    do{
    printf("\nLocality: ");
    scanf(" %[^\n]s",details[sz].locality);
    k = valid_name(details[sz].locality);
    }while(!k);
    
    do{
    printf("\nDistrict: ");
    scanf(" %[^\n]s",details[sz].dist);
    j=0;
    while (details[sz].dist[j]!='\0')                                   
        {
        details[sz].dist[j]=toupper(details[sz].dist[j]);
        j++;
        }
    k = valid_name(details[sz].dist);
    }while(!k);
    //printf("\n%s\n",details[sz].dist);
    
    do{
    printf("Our Service Providers are:\n1.AIRTEL\n2.VI\n3.JIO\n4.BSNL\n Choose and Enter any of the service providers from above list:\n");
    scanf(" %[^\n]s",details[sz].s_pr );
    j=0;
    while (details[sz].s_pr[j]!='\0')                                   
        {
        details[sz].s_pr[j]=toupper(details[sz].s_pr[j]);
        j++;
        }
        //printf("%s\n",details[sz].s_pr);
        k = valid_sevice(details[sz].s_pr);
    }while(!k);
    
    do{
        printf("Mobile Number: ");
        scanf("%lld",&details[sz].phone_no);
        k = valid_ph_no(details[sz].phone_no);
    }while(!k);
 
    printf("                                               ............................................\n\t\t\t\t\t\tYou have succesfully registered with us \n\n\t\t\t\t\t\t\t\tTHANK YOU\n                                               ............................................." );   
    printf("\n\n\n\n\t\t\t\t\t\t\t\tUPDATED LIST\n");
    printf("\n\nName\t\t\t\tHouse Name\t\tLocality\t\tDistrict\t  Service Provider\tPhone no.\n");
    printf(".......................................................................................................................................\n");
    for(int i=0;i<=sz;i++)
    {
    printf("%s\t%s\t\t%s\t%s\t\t%s\t\t%lld\n",details[i].c_name,details[i].hs_name,details[i].locality,details[i].dist,details[i].s_pr,details[i].phone_no);
    }
    
}



                                                     //REMOVE SPACE FUNCTION



int remove_space(struct directory details[],int size1,char *s)                 //remove_space FUNCTION DEFINITION
{
    struct space dup[size1];
    int j,fl=0;
    
    for(j=0;j<size1;j++)
    {
        int i=strlen(details[j].c_name);
        int flag=1;
        while(flag)
       {
          if(isalpha(details[j].c_name[i-1]))                                     //REMOVING RIGHT SPACES
         {
            flag=0;
         }
       i--; 
      }
      for(int k=0;k<=i;k++)
      {
        dup[j].dup_name[k]=details[j].c_name[k];
      }
      dup[j].dup_name[i+1]='\0';
      if(!strcmp(dup[j].dup_name,s))
      {                                                                         //COMPARING THE GIVEN STRING WITH THE CUSTOMER NAME
          fl=j;
          break;
      }
    }
    return ( fl );
}


                                                     //SEARCHING FUNCTION




void searching(struct directory details[],int size)                             //FUNCTION DEFINITION(SEARCHING)
{
    int ch,flag=0,size1,i;
    long long int ph_no;
 do
 {
    printf("\nEnter the Respective choice: \n");
    printf("\n1.Name of customer via Mobile Number\n2.list of customers of a particular service provider\n3.Mobile Number of customer given a Name\n4.To exit from the function\n\n");
    
    scanf("%d",&ch);
    
    
    if(ch==1)
    {
        printf("Enter Mobile Number: ");                                //SEARCHING FOR A CUSTOMER VIA MOBILE NUMBER
        scanf("%lld",&ph_no);
        for(i=0;i<size;i++)
        {
            if(ph_no==details[i].phone_no)
            {
                size1=i;
                flag=1;
                break;
            }
        }
        if(flag==1)
        printf("\n\nName of the customer is: %s\n\n",details[size1].c_name);
        else if(flag==0) 
        printf("\nEntered Mobile number has not registered with us................\n\n");
    }
    
    
    else if(ch==2)
    {
        
        int j=0;
        char service[10];
        printf("\nEnter service provider: ");
        scanf("%s",service);
        while (service[j]!='\0')                                    //SEARCHING FOR A LIST OF CUSTOMERS OF A PARTICULAR SERVICE PROVIDER
        {
        service[j]=toupper(service[j]);
        j++;
        }
        printf("\n\nName\t\t\t\tHouse Name\t\tLocality\t\tDistrict\t  Service Provider\t\tPhone no.\n");
        printf("...............................................................................................................................................................\n");
        for(i=0;i<size;i++)
        {
            if(!strcmp(service,details[i].s_pr))
            {
                printf("%s\t%s\t\t%s\t%s\t\t  %s\t\t   \t%lld\n\n",details[i].c_name,details[i].hs_name,details[i].locality,details[i].dist,details[i].s_pr,details[i].phone_no);
            }
        }
        
    }
    
    
    else if(ch==3)
    {                                                                            //SEARCHING FOR A MOBILE NUMBER VIA NAME OF THE CUSTOMER
        int k;
        char name[30];
	    printf("Enter name: ");
	    scanf(" %[^\n]",name);
	
        k = remove_space(details,size,name);                                      //CALLING THE remove_space function   
        
        if(k)
        printf("\nPhone Number of the customer is: %lld\n\n",details[k].phone_no);
        else if(k==0) 
        printf("\nEntered Customer Name has not registered with us................\n\n");
        
    }
 }while(ch!=4);
 
}



                                                     //UPDATE DETAILS FUNCTION

void update_details(struct directory details[],int size)
{
    int ch,i,j,k,size1,flag=0;
    char dup[50];
    long long int ph_no;
do{
    printf("\nEnter the Respective choice: \n");
    printf("\n1.change service provider(Mobile Number Porting)\n2.Change in House name,Locality and District\n3.Adding a new number for an existing customer\n4.To exit from the function\n\n");
    scanf("%d",&ch);
    if(ch==1)
    {
     do{
      printf("Enter Mobile Number of the Customer to change the details: ");                                //SEARCHING FOR A CUSTOMER VIA MOBILE NUMBER
      scanf("%lld",&ph_no);
      k = valid_ph_no(ph_no);
     }while(!k);
      
        for(i=0;i<size;i++)
        {
            if(ph_no==details[i].phone_no)
            {
                size1=i;
                flag=1;
                break;
            }
        }  
    
       if(flag==1)
       {
        printf("\nCustomer Name: %s\n\nYour current service provider is %s...\n\n",details[size1].c_name,details[size1].s_pr);
        strcpy(dup,details[size1].s_pr);
       }
       
    do{
        printf("Our Service Providers are:\n1.AIRTEL\n2.VI\n3.JIO\n4.BSNL\n Choose and Enter any of the service providers from above list:\n");
        scanf(" %[^\n]s",details[size1].s_pr );
        
        j=0;
        while (details[size1].s_pr[j]!='\0')                                   
        {
          details[size1].s_pr[j]=toupper(details[size1].s_pr[j]);
          j++;
        }
          //printf("%s\n",details[size1].s_pr);
          k = valid_sevice(details[size1].s_pr);
         if(!strcmp(dup,details[size1].s_pr))
         {
           printf("\nDont enter the existing service provider \nEnter the service provider you want to port\n\n");
           k=0;
         }
       }while(!k);        
        printf("\nYour new service provider is %s\n",details[size1].s_pr);
        printf("\nYour service provider has been succesfully changed\n\n");
        printf("Thank you\n\n");
    }
    
    else if(ch==2)
    {
       flag=0;
      do{
      printf("Enter Mobile Number of the Customer to change the details: ");                                //SEARCHING FOR A CUSTOMER VIA MOBILE NUMBER
      scanf("%lld",&ph_no);
      k = valid_ph_no(ph_no);
     }while(!k);
      
        for(i=0;i<size;i++)
        {
            if(ph_no==details[i].phone_no)
            {
                size1=i;
                flag=1;
                break;
            }
        }
        if(flag==1)
       {
        printf("\n......................................................................................\n");
        printf("\nExisting details of the customer are: \n");
        printf("\nCustomer Name   : %s\nHouse Name      : %s\nLocality        : %s\nDistrict        : %s\n",details[size1].c_name,details[size1].hs_name,details[size1].locality,details[size1].dist);
        printf("\n......................................................................................\n");
       }
       
    do{
    printf("\nHouse Name: ");
    scanf(" %[^\n]s",details[size1].hs_name);
    k = valid_name(details[size1].hs_name);
    }while(!k);
    
    do{
    printf("\nLocality: ");
    scanf(" %[^\n]s",details[size1].locality);
    k = valid_name(details[size1].locality);
    }while(!k);
    
    do{
    printf("\nDistrict: ");
    scanf(" %[^\n]s",details[size1].dist);
     j=0;
    while (details[size1].dist[j]!='\0')                                   
        {
        details[size1].dist[j]=toupper(details[size1].dist[j]);
        j++;
        }
    k = valid_name(details[size1].dist);
    }while(!k);
    
    
    printf("\n......................................................................................\n");
    printf("\nUpdated details of the customer are: \n");
    printf("\nCustomer Name   : %s\nHouse Name      : %s\nLocality        : %s\nDistrict        : %s\n",details[size1].c_name,details[size1].hs_name,details[size1].locality,details[size1].dist);
    printf("\n......................................................................................\n");   
    }
    
    
    else if(ch==3)
    {
        flag=0;
      do{
      printf("Enter old Mobile Number of the Customer to change to new mobile Number: ");                                //SEARCHING FOR A CUSTOMER VIA MOBILE NUMBER
      scanf("%lld",&ph_no);
      k = valid_ph_no(ph_no);
     }while(!k);
      
        for(i=0;i<size;i++)
        {
            if(ph_no==details[i].phone_no)
            {
                size1=i;
                flag=1;
                break;
            }
        }
        if(flag==1)
       {
        printf("\n......................................................................................\n");
        printf("\nCustomer Name: %s\n",details[size1].c_name);
        printf("\nExisting Mobile Number of the customer is: %lld\n",details[size1].phone_no);
        printf("\n......................................................................................\n\n");
        
        printf("Enter new Mobile Number of the Customer: ");
        scanf("%lld",&details[size1].phone_no);
        
        printf("\n\n......................................................................................\n");
        printf("\nCustomer Name: %s\n",details[size1].c_name);
        printf("\nUpdated(new) Mobile Number of the customer is: %lld\n",details[size1].phone_no);
        printf("\n......................................................................................\n");
       }
       else if(flag==0)
       {
           printf("\nEntered Mobile number has not registered with us................\n\n");
       }
    }
    
}while(ch!=4); 

}


                                                     //REPORT FUNCTION

void reports(struct directory details[],int size)
{
   int ch,flag=0,size1,i,k;
    long long int ph_no;
    char s[30];
    
 do
 {
    printf("\nEnter the Respective choice: \n");
    printf("\n1.Full details of a customer provided his number\n2.Percentage of people using each service provider in a district\n3.Percentage of each service provider\n4.Exit from reports\n");
    scanf("%d",&ch);
    
    
    if(ch==1)
    {
     do{
        printf("Enter Mobile Number of the Customer to find the details: ");                                //SEARCHING FOR A CUSTOMER VIA MOBILE NUMBER
        scanf("%lld",&ph_no);
        k = valid_ph_no(ph_no);
       }while(!k);
      
        for(i=0;i<size;i++)
        {
            if(ph_no==details[i].phone_no)
            {
                size1=i;
                flag=1;
                break;
            }
        }  
        
    
        if(flag==1)
        {
        printf("\n......................................................................................\n");
        printf("\nCustomer Name   : %s\nHouse Name      : %s\nLocality        : %s\nDistrict        : %s\nService Provider: %s\nPhone Number    : %lld\n",details[size1].c_name,details[size1].hs_name,details[size1].locality,details[size1].dist,details[size1].s_pr,details[size1].phone_no);
        printf("\n......................................................................................\n");
        }
        else if(flag==0) 
        printf("\nEntered Mobile number has not registered with us................\n\n");
    }
    
    
    else if(ch==2)
    {
        int j=0,b=0,a=0,v=0,flag=0,p;
        float tot;
        do{
            p=0;
           printf("Enter name of the district to get percentage of mobile numbers of each Service Provder: ");
           scanf(" %[^\n]s",s);
           while (s[p]!='\0')                                   
           {
            s[p]=toupper(s[p]);
            p++;
        
           }
        k = valid_name(s);
        //printf("%s\n",s);
        }while(!k);
        printf("\n\nName\t\t\t\tDistrict\t  Service Provider\n");
        printf("......................................................................................\n");
        for(i=0;i<size;i++)
        {
            if(!strcmp(details[i].dist,s))
            {
              flag=1;
              printf("%s\t\t%s\t\t  %s\t\t\n\n",details[i].c_name,details[i].dist,details[i].s_pr);
              if(!strcmp(details[i].s_pr,"JIO"))
              {
                 j=j+1;
              }
              
              else if(!strcmp(details[i].s_pr,"BSNL"))
              {
                 b=b+1;
              }
              
              else if(!strcmp(details[i].s_pr,"AIRTEL"))
              {
                 a=a+1;
              }
              else if(!strcmp(details[i].s_pr,"VI"))
              {
                 v=v+1;
              }
            
            }
        }
        if(flag==0)
        {
            printf("\nThere are no customers in the district: %s.......\n",s);
        }
        else if(flag==1)
        {
           tot=j+b+a+v;
           printf("Total number of JIO customers are: %d\n\nTotal number of BSNL customers are: %d\n\nTotal number of AIRTEL customers are: %d\n\nTotal number of VI customers are: %d\n\n",j,b,a,v);
        
           printf("\n......................................................................................\n\n");
           printf("Percentage of people using JIO   : %.1f percent\nPercentage of people using AIRTEL: %.1f percent\nPercentage of people using VI    : %.1f percent\nPercentage of people using BSNL  : %.1f percent\n",(j*100)/tot,(a*100)/tot,(v*100)/tot,(b*100)/tot);
           printf("\n......................................................................................\n");
        }
    }
    else if(ch==3)
    {
        int j=0,b=0,a=0,v=0,flag=0,p;
        float tot;
        for(i=0;i<size;i++)
        {
              if(!strcmp(details[i].s_pr,"JIO"))
              {
                 j=j+1;
              }
              
              else if(!strcmp(details[i].s_pr,"BSNL"))
              {
                 b=b+1;
              }
              
              else if(!strcmp(details[i].s_pr,"AIRTEL"))
              {
                 a=a+1;
              }
              else if(!strcmp(details[i].s_pr,"VI"))
              {
                 v=v+1;
              }
            
            
        }
        
           tot=j+b+a+v;
           printf("Total number of JIO customers are: %d\n\nTotal number of BSNL customers are: %d\n\nTotal number of AIRTEL customers are: %d\n\nTotal number of VI customers are: %d\n\n",j,b,a,v);
        
           printf("\n......................................................................................\n\n");
           printf("Percentage of people using JIO   : %.1f percent\nPercentage of people using AIRTEL: %.1f percent\nPercentage of people using VI    : %.1f percent\nPercentage of people using BSNL  : %.1f percent\n",(j*100)/tot,(a*100)/tot,(v*100)/tot,(b*100)/tot);
           printf("\n......................................................................................\n");
        if((j>b&&j>a)&&j>v)
        {
            printf("\nJIO has highest number of Customers....\n");
        }
        else if((b>j&&b>a)&&b>v)
        {
            printf("\nBSNL has highest number of Customers....\n");
        }
        else if((a>j&&a>b)&&a>v)
        {
            printf("\nAIRTEL has highest number of Customers....\n");
        }
        else
        {
            printf("\nVI has highest number of Customers....\n");
        }
    }
    
 }while(ch!=4);
 
}





                                                     //MAIN FUNCTION



int main()
{
    int choice;
    int size=50;
    struct directory details[50]
    = { { "Tanmay Hirawat          ","The Cottage    ","Rajendra Nagar   ","ANANTAPUR",      "AIRTEL",  9848193160}, 
        { "Varenya Guthikonda      ","Rose Cottage   ","RC Nagar         ","CHITTOOR",       "JIO",     9491081950},
        { "Hemanth Saketh Rayaprolu","The Bungalow   ","Ashok Nagar      ","EAST GODAVARI",  "BSNL",    9581717788}, 
        { "Yashnav                 ","The lodge      ","Vimla Nagar      ","ANANTAPUR",      "VI",      8978844887}, 
        { "Venkat                  ","Wood lands     ","Kamla Nagar      ","EAST GODAVARI",  "JIO",     7093429161},
        { "Aditya                  ","Old school     ","Vishal Nagar     ","ANANTAPUR",      "AIRTEL",  9848195260}, 
        { "Samhita                 ","Ivy Cottage    ","TC Nagar         ","CHITTOOR",       "VI",      9484081950},
        { "Ananaya                 ","The Villow     ","Gandhi Nagar     ","VISAKHAPATNAM",  "BSNL",    7581717788}, 
        { "Yashnav                 ","The lodge      ","Vimla Nagar      ","ANANTAPUR",      "AIRTEL",  8978844887}, 
        { "Aryan                   ","Wood lands     ","TC Nagar         ","EAST GODAVARI",  "JIO",     7993429161},
        
        { "Radha Hirawat           ","The Cottage    ","Rajendra Nagar   ","ANANTAPUR",      "AIRTEL",  9848793160}, 
        { "Vanshika                ","Rose Cottage   ","RC Nagar         ","CHITTOOR",       "BSNL",    9491081850},
        { "Lakshmi                 ","The Bran       ","Lakshmi Nagar    ","HAKIMPUR",       "BSNL",    9381717788}, 
        { "Utkar singh             ","The croft      ","Shalini Nagar    ","VIZIANAGRAM",    "AIRTEL",  7978844887}, 
        { "Venkat singh            ","Wood hill      ","Sai Nagar        ","HAKIMPUR",       "JIO",     7193429161},
        { "Nirma                   ","Old Vicrage    ","Vishal Complex   ","EAST GODAVARI",  "AIRTEL",  9748195260}, 
        { "Latha                   ","Ivory Cottage  ","TC Colony        ","HAKIMPUR",       "VI",      9564081950},
        { "Sai                     ","Sun Shide      ","Police Barracks  ","LAKHIMPUR",      "BSNL",    7382717788}, 
        { "Keerthana               ","River lodge    ","Vimla Colony     ","VIZIANAGRAM",    "JIO",     8988844887}, 
        { "Aryan singh             ","Top lands      ","KC Nagar         ","EAST GODAVARI",  "JIO",     7999429161},
        
        { "Varma                   ","The Knook      ","Bank Colony      ","ANANTAPUR",      "AIRTEL",  9848193790}, 
        { "Baggam                  ","Rose Block     ","RC Colony        ","CHITTOOR",       "JIO",     9491081930},
        { "Harini                  ","Fair View      ","Ashok Nagar      ","EAST GODAVARI",  "BSNL",    9581717768}, 
        { "Srinivas                ","Mill House     ","Vimla Nagar      ","ANANTAPUR",      "VI",      8978844547}, 
        { "Manoj                   ","Corner lands   ","shaamla Nagar    ","VIZIANAGRAM",    "JIO",     7093429321},
        { "Satya                   ","Way side       ","Trishal Nagar    ","ANANTAPUR",      "AIRTEL",  9848195269}, 
        { "Raja                    ","White House    ","TC Nagar         ","CHITTOOR",       "VI",      9484081958},
        { "Srikanth                ","Tree Villow    ","Gandhi Nagar     ","VISAKHAPATNAM",  "BSNL",    7581717786}, 
        { "Raju                    ","Wood lands     ","KV Nagar         ","EAST GODAVARI",  "JIO",     7993429131},
        { "Rajesh                  ","Wood Oaks      ","Kamla Nagar      ","ANANTAPUR",      "JIO",     6993429831},
        
        { "Deepthi                 ","The Villa      ","Rajendra Nagar   ","ANANTAPUR",      "AIRTEL",  9848792160}, 
        { "Swetha                  ","Rose Heaven    ","RC Nagar         ","CHITTOOR",       "BSNL",    9491081650},
        { "Poorna                  ","The Cottage    ","Army Colony      ","ANANTAPUR",      "BSNL",    9381717888}, 
        { "Kalpana                 ","The Frizz      ","Shalini Nagar    ","EAST GODAVARI",  "VI",      7978844447}, 
        { "Rajani                  ","Wood Heaven    ","Sai Nagar        ","VISAKHAPATNAM",  "JIO",     7193429761},
        { "Vinilla                 ","Old Heaven     ","Vidhya Complex   ","VIZIANAGRAM",    "AIRTEL",  9748195360}, 
        { "Sridevi                 ","Ivory School   ","TC Complex       ","EAST GODAVARI",  "VI",      9564081850},
        { "Sangeetha               ","Sun Shade      ","Police Barracks  ","LAKHIMPUR",      "BSNL",    7382717488}, 
        { "Pavithra                ","River School   ","Nehuru Colony    ","HAKIMPUR",       "JIO",     8988854887}, 
        { "Sirisha                 ","Top View       ","KLC Nagar        ","EAST GODAVARI",  "JIO",     7999429341},
        
        { "Uday                    ","The Hill       ","Rajendra Nagar   ","ANANTAPUR",      "AIRTEL",  9848792179}, 
        { "Rajeshwari              ","Hill Heaven    ","RC Nagar         ","CHITTOOR",       "BSNL",    9491081432},
        { "Anjana                  ","The Tops       ","Army Colony      ","ANANTAPUR",      "BSNL",    9381917988}, 
        { "Sunitha                 ","The Orchards   ","Shalini Nagar    ","VIZIANAGRAM",    "AIRTEL",  7978544447}, 
        { "Kalyani                 ","Wood Falls     ","Sai Nagar        ","EAST GODAVARI",  "JIO",     7193426761},
        { "Neelima                 ","Mill House     ","Vidhya Complex   ","VISAKHAPATNAM",  "AIRTEL",  9748195389}, 
        { "Mythri                  ","Oak House      ","TC Complex       ","VIZIANAGRAM",    "VI",      9564081850},
        { "Assema                  ","Sun Oaks       ","Police Barracks  ","LAKHIMPUR",      "BSNL",    7383417488}, 
        { "Lavanya                 ","River Fields   ","Nehuru Colony    ","EAST GODAVARI",  "JIO",     8943354887}, 
        { "Sukidevi                ","Top Oaks       ","Windcent Colony  ","HAKIMPUR",       "JIO",     7999428741} 
        
    };
    
    printf("\n\n");
    printf("\t\t\t\t\t\t      ..............................\n");
    printf("\t\t\t\t\t\t\t!EXISTING CUSTOMER DETAILS!\n");
    printf("\t\t\t\t\t\t      ..............................\n");
    printf("\n\nName\t\t\t\tHouse Name\t\tLocality\t\tDistrict\t  Service Provider\tPhone no.\n");
    printf(".......................................................................................................................................\n");
    
                                                     //PRINTING EXISTING CUSTOMERS
    
    for(int i=0;i<50;i++)
    {
    printf("%s\t%s\t\t%s\t%s\t\t%s\t\t%lld\n",details[i].c_name,details[i].hs_name,details[i].locality,details[i].dist,details[i].s_pr,details[i].phone_no);
    }
    printf("\n\n");
    printf("\t\t\t\t\t   ................................................\n");
    printf("\t\t\t\t\t\t!WELCOME TO MOBILE DIRECTORY MANAGEMENT!\n");
    printf("\t\t\t\t\t   ................................................\n");

    do 
    {
    printf("\nEnter the respective choice: \n");
    
    printf("\n1.Register as a New Customer\n2.Search for Details of Customer\n3.Update Details\n4.For Reports\n5.Exit Application\n\n");
    
    scanf("%d",&choice);
    
    if(choice==1)
    {
        
        Add_customer(details,200,size);              //CHOICE 1
        size++;
        continue;
    }
    
    
    else if(choice==2)
    {
        searching(details,size);                     //CHOICE 2
        continue;
    }
    
    
    else if(choice==3)
    {
        update_details(details,size);               //CHOICE 3
        continue;
        
    }
    else if(choice==4)
    {
        reports(details,size);                      //CHOICE 4
        continue;
    }
    }while(choice!=5); 
    
    
printf("Thank You\n");

    return 0;
}
