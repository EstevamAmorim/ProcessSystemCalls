#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>


int main(int argc, char * argv []) 
{
    int status;
    pid_t pid;

    //Pipe for reading and writing, where fd[0] - read, fd[1] - write
    //Pipe para leitura e escrita, sendo fd[0] - leitura, fd[1] - escrita
    int fd[2];

    if(pipe(fd)<0) 
    {
        perror("pipe") ;
        return -1 ;
    }

    if((pid = fork()) < 0) 
    {
        perror("fork");
        exit(1);
    }

    //Old king code
    //Codigo executado pelo antigo rei
    if(pid != 0) 
    {
        char received[30];
        printf("-------------------------------------------------------------------------------------------");
        //printf("\nHa muito tempo havia um rei muito poderoso. \n\n");

        printf("\n\n   Long ago there was a very powerful king. \n\n");
        
        sleep(5);
        
        /*printf("Rei: Dediquei a minha vida para cuidar do meu reino, no entanto     \n"); 
        printf("     estou morrendo e esta na hora de eu aconselhar voce, meu fi-   \n");
		printf("     lho, que vai assumir o trono em meu lugar.                     \n\n");*/

        printf("   King: I have dedicated my life to taking care of my kingdom, however I am dying    \n");      
        printf("         and it is time for me to advise you, my son, who will take the throne  in my \n");    
        printf("         place.                                                                       \n\n");      
        
        sleep(10);
		
        /*printf("Rei: Filho, cuide do meu reino como eu cuidei, nao busque rique-  \n");
        printf("     zas as custas do sofrimento do povo e nem deixe que seu ego  \n");
        printf("     cause guerras.                                               \n\n");*/

        printf("   King: Son, take care of my kingdom as I did, don`t seek riches at the expense of   \n");          
        printf("         people`s suffering and don`t let your ego cause wars.                        \n\n");      
		
        sleep(20);
		close(fd[1]);
        
        //waits for the child to finish blocking the parent, if the child does not finish, it returns immediately
        //aguarda o termino do filho bloqueando o pai, se o filho não terminar, retorna imediatamente
        waitpid(-1, &status, WNOHANG);
        read(fd[0], received, sizeof(received));
        close(fd[0]);
        
        /*printf("Rei: %s? Malditos!\n", recebida);
		printf("     O rei de la nao tem apoio da sua populacao porque se envolve \n");
        printf("     em muitas guerras sem motivo o que faz com que o seu respei- \n");
		printf("     to seja baixo, naturalmente a sua dinastina nao ira prevale- \n");
		printf("     cer, basta expulsar seu exercito daqui, naturalmente o seu   \n");
		printf("     poder vai ruir apos mais essa derrota.                       \n\n");*/

        printf("   King: %s? Damn!                                                                    \n", received);    
        printf("         The king of there has no support from his own population because he gets     \n");       
        printf("         involved in many wars for no reason which makes your respect low, naturally  \n");       
        printf("         your dynasty will not prevail, just expel your army from here, naturally     \n");     
        printf("         your power will collapse after this defeat.                                  \n\n");   
		
        sleep(15);
		
		/*printf("Apos a morte do pai, o filho agora tem a responsabilidade de se   \n");
		printf("tornar rei.\n\n");*/

        printf("   After the father`s death, the son now has the responsibility to become king. \n\n");
		
        sleep(8);
		
		execve("./NewKing", argv, NULL);
    }
    //new king code
    //codigo executado pelo filho do rei
    else
    {
        //the file descriptor of the write part of the pipe
        //is saved in STDIN_FILENO, it can be used even if the process image is changed
        
        //o descritor de arquivo da parte de escrita do pipe
        //é salvo em STDIN_FILENO, pode ser usado mesmo que a imagem do processo seja alterada
        dup2(fd[1], 0);
        
        //close(fd[1]);
        close(fd[0]);
        
        //parameters for the new process image
        //parametros para a nova imagem do processo
        
        //char* arr[] = {"./Son","O Norte pretende atacar", NULL};
        char* arr[] = {"./Son","The North intends to attack", NULL};

        //the process image is changed
        //a imagem do processo é alterada
        execve("./Son", arr, NULL);
    }

    exit(0);
}
