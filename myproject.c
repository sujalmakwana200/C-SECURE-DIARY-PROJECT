/* a secure diary manegment system built by sujal makwana
* this program is a complete CRUD (create,Read, update,delete) application written in C,
*it has a password so only you can access the file and it's personal so don't give anyone
*it has a xor ^ encryption system which make it secure
*Date: November 2025
=================================================
*/
// i includede some needed header file which also known by c linreries which are needed to run this program
// this line is nonesense becouse it's 2:00 am(when i firstly learned about making your own function i always think how do they made and how much time would i take to make them 



                                                                                                                                                                   #include <stdio.h>// this header file is for stenderd inputoutput and filehendling like FILE,fclose,fopen and getchar for getting cherecter arrey and  and remove and rename also
#include <stdlib.h> // this is for our exit function 
#include <string.h> // this is for all string function like strcmp, strcspn,strncpy,strcpy.
// i am using define to create a constent and it does not chenge
#define SECRET_KEY 'K' // this is the secret key
#define FILENAME "diery.dat" // this is the name and it will replace every single FILENAME
// these are function prototyps if a function like char date is wayy to above and compiler didn't find that so it will tell compiler that veriable is there don't worry
void addEntry(); // these are those prototypes
void SearchEntries();
void updateEntry();
void deleteEntries();
void encryptDecrypt(char *data);
  
  // this is like blueprint for a single diary entry
  struct DiaryEntry {
     char date[20]; // this is the charecter string that holding date
     char text[100000];// this for holding texts
     };
     /* this is main function the cryption function*/
        void encryptDecrypt(char *data) {
          int i = 0;// to set up  a counter 'i' to track position in string and we are starning with 0 becouse c arreys are indexed with 0
          while (data[i] != '\0') {
          // it's xor chiper and it's reversible means all letters becames doller
            data[i] = data[i] ^ SECRET_KEY;
                 i++;// it moves to next cherecter
                }
              }
             /* this functin adds new entry to the file using loop and this is create in crud*/
              void addEntry() {
              int c;// a tempery veriable for cleaning buffer
               struct DiaryEntry entry;// it is a local veriable that holds data
                 FILE *fp;// this is the file pointer and it will pointer to file
                 
                   fp = fopen(FILENAME, "ab");// this is for opening the file in binary
                    
                       if(fp == NULL) { 
                         printf("ERROR: COULD NOT OPEN FILE!");
                              return;
                              }
                              // this loop is for very critical thing it clean's scanf '\n' buffer
                              while((c = getchar()) != '\n' && c != EOF);
                                 printf("ENTER TODAY'S DATE(E.G.,2025-10-28): ");
                                    fgets(entry.date, 20,stdin); // it gets the date user types
                                      printf("ENTER YOUR DIERY ENTRY(MAX 100000 CHARECTER:\n");
                                        fgets(entry.text,100000,stdin);
                                          entry.date[strcspn(entry.date,"\n")] = 0;
                                          entry.text[strcspn(entry.text,"\n")] = 0;
                                           // below encryptDecrypt encrypts both fileds before saving
                                           encryptDecrypt(entry.text);
                                           encryptDecrypt(entry.date);
                                           // it write whole encrypted struct fuction to file
                                              fwrite(&entry, sizeof(struct DiaryEntry),1, fp);
                                                   fclose(fp);// it closes the file
                                                     printf("\nENTRY SAVED SUCCESSFULLY (and encrypted)!\n\n");
                                                     }
                                                     /* thisview entry reads all entries from the file("rb"= read binery),
                                                     decrypts them ,and print them to screen*/
                                                     void viewEntries() {
                                                        struct DiaryEntry entry;
                                                        FILE *fp;
                                                        
                                                        fp = fopen(FILENAME, "rb");
                                                        // it checks if file exist or not
                                                          if (fp == NULL) { 
                                                             printf("FILE NOT FOUND OR NO ENTRIES ADDED YET.\n\n");
                                                               return;
                                                               }
                                                               // it is for critical thing it returns file pointer to the begning
                                                               rewind(fp);
                                                               clearerr(fp); // clear the eof flag
                                                               printf("\n--- VIEWING ALL DIERY ENTRIES ---\n");
                                                               // it is a loop to read whole struct and entry
                                                                   while (fread(&entry, sizeof(struct DiaryEntry), 1, fp) == 1) {
                                                                   encryptDecrypt(entry.date);
                                                                   encryptDecrypt(entry.text);
                                                                      printf("========================================\n");
                                                                      printf("Date: %s\n",entry.date);
                                                                      printf("TEXT: %s\n",entry.text);
                                                                      printf("=========================================\n");
                                                                       }
                                                                       
                                                                       
                                                                       fclose(fp);// it closes the file
                                                                       printf("\n=====END OF ENTRIES=====");
                                                                       }
                                                                       
                                               /* this function searches the file for an entry by date*/                         
                                                void SearchEntries() {
                                                   struct DiaryEntry entry;
                                                     FILE *fp;
                                                      char searchDate[20];
                                                       int c;
                                                        int found =  0; // this is for checking if found anything or not
                                                         while ((c = getchar()) != '\n' && c != EOF);// this cleans '\n' buffer 
                                                                       
                                                          printf("PLEASE ENTER THE DATE TO SEARCH FOR SIR (E.G 7-11-2025): ");
                                                           fgets(searchDate,20,stdin);
                                                            searchDate[strcspn(searchDate,"\n")] = 0;
                                                                         
                                                             fp = fopen(FILENAME, "rb");
                                                              if (fp == NULL) {
                                                                          
                                                                printf("ERROR: COULD NOT OPEN FILE SIR!\n\n");
                                                                 return;
                                                                   }
                                                                   // it loops through every entry 
                                                                    while (fread(&entry,sizeof(struct DiaryEntry), 1, fp) == 1) {
                                                                     encryptDecrypt(entry.date);// decrypts the only date for comperison
                                                                        if (strcmp(entry.date,searchDate) == 0) { // entry founded now decrypt
                                                                         encryptDecrypt(entry.text);
                                                                            
                                                                             printf("\n===== ENTRY FOUND SIR =====");
                                                                             
                                                                             	printf("DATE: %s\n",entry.date);
                                                                             	
                                                                             	 printf("TEXT: %s\n", entry.text);
                                                                      printf("=================================================\n\n");

                                                                      found = 1;// set flag to true 
                                                                      }
                                                                      }
                                                                      fclose(fp);
                                                                        if (found == 0) { // flag is still  0 we found nothing
                                                                          printf("\n NO ENTRY FOUND SIR YOUR GIVEN DATE: %s\n\n", searchDate);
                                                                          }
                                                                           }
                                                                                                                                                     
                                                                            
                                                                            
     /* this functin deletes an entry by date by creating an temp file and rename it to original and remove original file*/                                                                     
    void deleteEntries() {
    struct DiaryEntry entry;
    FILE *fp, *fpTemp;
    char deleteDate[20];
    int c;
    int found = 0;
    // it clears input buffer of '\n'
    while((c = getchar()) != '\n' && c != EOF);
    printf("PLEASE ENTER THE DATE YOU WENT TO DELETE SIR (E.G. 7-11-2025)");
    fgets(deleteDate, 20,stdin);
    deleteDate[strcspn(deleteDate,"\n")] = 0;
    // critical fix: this must be == (compare) not = (assign) a single here couse segment foult)
    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("ERROR: COULD NOT OPEN YOUR DESIRED FILE SIR!\n\n");
            return;
            } 
           fpTemp = fopen("temp.dat", "wb");// it opens Tempfile
             if (fpTemp == NULL) {
                printf("ERROR: COULD NOT CREATE TEMPERORY FILE SIR TRY AGAIN");
                  fclose(fp);// cleans up file we just opened
                    return;
                    }
                    // it loop through the original file
                    while (fread(&entry,sizeof(struct DiaryEntry), 1,fp) == 1) {
                      char TempDate[20];// it creates a safe copy
                      strncpy(TempDate,entry.date,19);// use strncpy to prevent overflow 
                      TempDate[19] ='\0'; // it menually sets null teminul to 0
                       
                      encryptDecrypt(TempDate);// decrypt safe copy
                      // checks if this file is we went to delete
                        if (strcmp(TempDate,deleteDate) == 0) {
                             found = 1; // do nothing it skips entry
                             } 
                             else {
                                 fwrite(&entry,sizeof(struct DiaryEntry), 1,fpTemp);
                                 }
                                 }
                                 fclose(fp);
                                 fclose(fpTemp);
                                    if (found == 1) {
                                    remove(FILENAME);
                                    rename("temp.dat",FILENAME);
                                        printf("\nENTRY FOR %s DELETED SUCCESSFULLY!\n\n",deleteDate);
                                        } 
                                        else { 
                                        remove("temp.dat");
                                        printf("\n NO ENTRY FOUND FOR YOUR DESIRED DATE %s\n\n SIR!",deleteDate);
                                        }
                                        } 
                           void updateEntry() {
                           struct DiaryEntry entry;
                           FILE *fp, *fpTemp;
                           char updateDate[20];
                           int c;
                           int found = 0;
                            
                            while ((c = getchar()) != '\n' && c != EOF);
                               printf("PLEASE ENTER THE DATE TO UPDATE FOR UPDATING YOUR ENTRY!");
                                 fgets(updateDate, 20,stdin);
                                 updateDate[strcspn(updateDate,"\n")] = 0;
                                 fp = fopen(FILENAME, "rb");
                                 if (fp == NULL) {
                                 printf("ERROR: COULD NOT OPEN FILE\n\n");
                                 return;
                                 }
                                 fpTemp = fopen("temp.dat","wb");
                                   if (fpTemp == NULL ) {
                                   printf("ERROR:COULD NOT CREATE TEMPERORY FILE SIR\n\n");
                                     fclose(fp);
                                     return;
                                     }
                                      while (fread(&entry,sizeof(struct DiaryEntry), 1, fp) == 1) {
                                         char tempDate[20];
                                         strncpy(tempDate,entry.date,19);
                                             tempDate[19] = '\0';
                                             
                                             encryptDecrypt(tempDate);
                                             if (strcmp(tempDate,updateDate) == 0) {
                                             found = 1;
                                             encryptDecrypt(entry.date);
                                               printf("\n====ENTRY FOUND ====");
                                                  printf("\nORIGINAL DATE: %s\n",entry.date);
                                                 printf("\nPLEASE ENTER THE NEW TEXT FOR THIS ENTRY:\n");
                                                  fgets(entry.text, 100000, stdin);
                                                    entry.text[strcspn(entry.text,"\n")] = 0;
                                                     encryptDecrypt(entry.date);
                                                     encryptDecrypt(entry.text);
                                                       fwrite(&entry,sizeof(struct DiaryEntry), 1,fpTemp);
                                                           }
                                                         }
                                                           fclose(fp);
                                                           fclose(fpTemp);
                                                             if (found == 1) {
                                                             remove(FILENAME);
                                                             rename("temp.dat",FILENAME);
                                                             }
                                                              else {
                                                              remove("temp.dat");
                                                              printf("\n NO ENTRY FOUND FOR THE DATE: %s\n\n", updateDate);
                                                              }
                                                              }
                                                          
                                                     
                                      
                                      
                                      
             
                                                                                                                                                                 
                                                                    
                                                                        
                                                                        

 int main() {
 int choice;
 int i;
 char correctpassword[] = "SUJAL_IS_THE_KING";
 char userinput[50];
    for(i =0; i < 3; i++) {
       printf("ENTER YOUR PASSWORD SIR(ATTEMPT %d OF 3):",i +1);
         scanf("%49s",userinput);
          if (strcmp(userinput,correctpassword) == 0 ) {
            printf("ACCESS GRANTED WELCOME SIR...\n\n");
              break;
                  }
                 else{
                     printf("ACEES DENIED WRONG PASSWORD SIR\n");
                         }
                                                                                     
                       }
                          if (i == 3) {
                        printf("TOO MANY WRONG ATTEMPS. LOCKING THE PROGRAM.\n");
                              exit(1);
                                           }
                                                                                         
                                 int c;
                          while (1) {
                   printf("===================================\n");
                                                                                            
                                                                                            
                          printf("[ 1 ] Add NEW  DIARY ENTRY\n");
                                                                                             
                                                                                              
                                printf("[ 2 ] VIEW ALL ENTRIES\n");
                                
                                printf("[ 3 ] SEARCH FOR ENTRIES\n");
                                  
                                  printf("[ 4 ] DELETE AN ENTRY\n");
                                                                                               
                                       printf("[ 5 ] UPDATE AN ENTRY\n");
                                       printf("[ 6 ] EXIT\n\n");
                                       
                                  printf("ENTER YOUR CHOICE:");
                                                                                                  
                                      if( scanf("%d", &choice) != 1) {
                                        printf("INVALID INPUT,PLEASE ENTER A NUMBER.\n");
                                             while((c = getchar()) != '\n' && c != EOF);
                                                   continue;
                                                   }
                                                    
                                                    switch (choice) {
                                                     case 1:
                                                       addEntry();
                                                         break;
                                                         case 2:
                                                          viewEntries();
                                                           break;
                                                             case 3:
                                                             SearchEntries();
                                                             break;
                                                             
                                                             case 4:                                                             
                                                               deleteEntries();
                                                               break;
                                                                  case 5:
                                                                  updateEntry();
                                                                  break;
                                                                  case 6:
                                                                  printf("GOODBYE SIR\n\n");
                                                                  exit(0);
                                                                  
                                                                  default:
                                                                     printf("INVALID CHOICE SIR! TRY AGAIN SIR.\n\n");
                                                                     
                                                                }
                                                             }
                                                                    return 0;
                                       }                                                                  
                                                           

                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                       
                                                                      
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                     
                                        
                                      
                                      
                                      
                                    
                                    
                                    
                              
                              
                      
                    
