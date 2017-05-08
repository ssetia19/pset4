

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
    
    while (!feof(file))
    {
       
        
        if (jpeg[0] == 0xff && jpeg[1] == 0xd8 && jpeg[2] == 0xff && (jpeg[3] == 0xe0 || jpeg[3] == 0xe1))
        {
         
            if (temp != NULL)
            {
                fclose(temp);
                
            }
            
           
            sprintf(fname, "%03d.jpg", counter);
            
         
            temp = fopen(fname, "w");
            
           
            counter++;
            
            
            fwrite(jpeg, sizeof(jpeg), 1, temp);
        }
        else if (counter > 0)
        {
            
            fwrite(jpeg, sizeof(jpeg), 1, temp);            
            
        }
      
        fread(jpeg, sizeof(jpeg), 1, file);
        
    }
  
    
   
    fclose(file);
	return 0;
}
