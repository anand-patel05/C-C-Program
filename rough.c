#include <stdio.h>
#include <conio.h>
#include <string.h>
void main() 
{
	int i,j,keylen,datalen;
	char data[100], key[30],temp[30],rem[30],key1[30], Endata[100];

	//Sender's Side
	printf("Enter Data: ");         // taking input
	gets(data);
	printf("Enter Key: ");
	gets(key);
	keylen=strlen(key);
	datalen=strlen(data);          // finding length

	for (i=0;i<keylen-1;i++)
    {
		data[datalen+i]='0';        // appending (k-1) zeros
	}

	strcpy(key1,key); 
	for(i=0;i<keylen;i++)             
	    temp[i]=data[i];
    
	for (i=0;i<datalen;i++)         //---------------------------------        
    {
		for (j=0;j<keylen;j++)
		 {
			if (temp[0] == '0')
	 	       	key[j]='0'; 
			else
				key[j]=key1[j];
		}

	 	for (j=keylen-1;j>0;j--)      // Logic of program
         {
	 		if(temp[j]==key[j])
	 		    rem[j-1]='0';
            else
	 		    rem[j-1]='1';
	 	 }
		 
	 	rem[keylen-1]=data[i+keylen];
	 	strcpy(temp,rem);
	 }

	  strcpy(rem,temp);               //-----------------------------------

	printf("\nRemainder at sender's side: ");
	for (i=0;i<keylen-1;i++)
	printf("%c",rem[i]);

	printf("\nEncoded data: ");
    int c = 0;
	for (i=0;i<datalen;i++)
    {
        Endata[c++] = data[i];
	    printf("%c",data[i]);
    }
    for (i=0;i<keylen-1;i++){
        Endata[c++] = rem[i];
	    printf("%c",rem[i]);
    }

    //Endata[3] = 1;                                  // *** This is for checking tranmission of corrupted data *** 

	// Reciever's Side
	for(i=0;i<keylen;i++)            
	    temp[i]=Endata[i];
    
	for (i=0;i<datalen;i++)            //
    {
		for (j=0;j<keylen;j++)
		 {
			if (temp[0] == '0')
	 	       	key[j]='0'; 
			else
				key[j]=key1[j];
		}

	 	for (j=keylen-1;j>0;j--)      // Logic of program
         {
	 		if(temp[j]==key[j])
	 		    rem[j-1]='0';
            else
	 		    rem[j-1]='1';
	 	 }
		 
	 	rem[keylen-1]=Endata[i+keylen];
	 	strcpy(temp,rem);
	 }

	strcpy(rem,temp);                   //

    printf("\nRemainder at reciever's side: ");
	for (i=0;i<keylen-1;i++)
		printf("%c",rem[i]);

	int flag = 0;
	for (i=0;i<keylen-1;i++)
     {
	 if (rem[i] == '1')
		flag = 1; 
     else
		flag = 0;
     }
	 if (flag == 1)
	 	printf("\n\nError in data transmisssion!");
	 else
	 	printf("\n\nNo Error in data transmisssion!");
    
	getch();
}
