#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) 
{
    if(argc != 0) 
    {
    	
    	sleep(25);
    	
        /*printf("Filho: Seguirei seus conselhos meu pai, porem descobri que o pais              \n"); 
		printf("       ao norte pretende se aproveitar da instabilidade causada                  \n");
		printf("       por sua morte e pretende atacar, de que modo devo agir?                   \n\n");*/
         
        printf("   Son:  I will follow your advice my father, but I discovered that the country to    \n"); 
        printf("         the north intends to take advantage of the instability caused by your death  \n");  
        printf("         and intends to attack, what should I do?                                     \n\n");  
        
        //uses the file descriptor that points to the pipe, since it was saved in STDIN_FILENO
		//utiliza o descritor de arquivo que aponta para o pipe, sendo que ele estava salvo em STDIN_FILENO
        write(STDIN_FILENO, argv[1], strlen(argv[1])+1);
        close(STDIN_FILENO);
        
        exit(0);
    }

    return 0;
}
