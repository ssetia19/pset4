

#include <stdio.h>


int main(void)
{
    FILE* file = fopen("card.raw", "r");
    
   
    if (file == NULL)
    {
        fclose(file); 
        printf("unable to recover file from card.raw \n");
        return 1;
    }

    int counter = 0; 
   
    unsigned char jpeg[512];
   
   
   
    FILE* temp = NULL; 
     // until end of file is reached
   
    
    // close the file
    fclose(file);
	return 0;
}
