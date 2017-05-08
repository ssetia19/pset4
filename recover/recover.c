

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
    while (!feof(file))
    {
       
        // check first couple of sequence of the jpg
        if (jpeg[0] == 0xff && jpeg[1] == 0xd8 && jpeg[2] == 0xff && (jpeg[3] == 0xe0 || jpeg[3] == 0xe1))
        {
            // if already exist, then close file
            if (temp != NULL)
            {
                fclose(temp);
                
            }
            
            // label the files with three digits
            sprintf(fname, "%03d.jpg", counter);
            
            // next file in line
            temp = fopen(fname, "w");
            
            // bump the counter up
            counter++;
            
            // new file with jpeg
            fwrite(jpeg, sizeof(jpeg), 1, temp);
        }
        else if (counter > 0)
        {
            // put jpg into temp
            fwrite(jpeg, sizeof(jpeg), 1, temp);            
            
        }
      
        fread(jpeg, sizeof(jpeg), 1, file);
        
    }
  
    
    // close the file
    fclose(file);
	return 0;
}
