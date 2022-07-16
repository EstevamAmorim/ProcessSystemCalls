#define _GNU_SOURCE           
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <linux/sched.h>
#include <sched.h>
#include <string.h>

#define STACK 8192

int flag = 1;

void catch_ctrl_c(int signo) 
{

	/*printf("\n\nApos cinco dias, o inevitavel acontece, o jovem rei espulsa seus       \n");
	printf("inimigos e volta para a sua capital, onde inicia uma frutifera linha-      \n");
	printf("gem e por seu carater um longo tempo de paz se inicia, posteriormente      \n");
	printf("ele anexa o pais ao norte ao seu reino e consegue um apoio popular         \n");
	printf("enorme, pelo fato de ser muito justo e compassivo, do modo que seu         \n");
	printf("pai o aconselhou. Depois de um longo reinado, o rei morre de causas        \n");
	printf("naturais.\n\n");*/

    printf("\n\n   After five days, the inevitable happens, the young king expels his enemies and \n");    
    printf("   returns to his capital, where he begins a fruitful lineage and for his character   \n");      
    printf("   a long time of peace begins, later he annexes the country to the north to his      \n");   
    printf("   kingdom and succeeds. huge popular support, for being very fair and compassionate, \n");          
    printf("   as his father advised him.                                                         \n");
    printf("\n   After a long reign, the king dies of natural causes.                             \n\n");  
    
    printf("-------------------------------------------------------------------------------------------\n");

	flag = 0;
}

int clone_behavior()
{  
	pid_t pid;
		
    if((pid = fork()) < 0)
    {
		perror("fork");
  		exit(1);
	}
    	
    if(pid != 0) 
    {
   	   /*printf("O Rei do pais ao norte lidera diversas batalhas tentando sempre     \n"); 
       printf("alcancar o centro do exercito de seu inimigo, pois acredita que o   \n");
	   printf("novo rei estaria la.                                                \n\n");*/
       
       printf("   The King of the country to the north leads several battles, always trying to reach \n");      
       printf("   the center of his enemys army, because he believes that the new king would be      \n");      
       printf("   there.                                                                             \n\n");          
       
   	   sleep(10);
   	   
       /*printf("Porem, quando ele descobre a verdade, sua raiva eh tanta que manda    \n");
	   printf("decapitar seu proprio general por medo de estar sendo traido...       \n\n");*/
         
       printf("   However, when he discovers the truth, his anger is so great that he has his own    \n");       
       printf("   general beheaded for fear of being betrayed...                                     \n\n");  

       sleep(10);
	   
	   //printf("Rei do Norte: Jamais!!! \n\n");
       
       printf("   King from North: Never!!! \n\n");

	   sleep(4);
	   
       kill(pid, SIGTERM);
       
       /*printf("Desse modo o general foi morto por quem ele havia servido durante     \n");
	   printf("toda a sua vida...                                                    \n\n");*/

       printf("   In this way the general was killed by whom he had served all his life...\n\n");
       
       sleep(8);
       
       /*printf("Ato este que enfraquece mais ainda a moral do orgulhoso e incompe-    \n");
	   printf("tente rei e de seus guerreiros, enfraquecendo sua forca de combate    \n");
	   printf("enormemente.                                                          \n");
	   printf("Esse ato condenou definitivamente aquele rei.                         \n\n");*/
         
       printf("   This act further weakens the morale of the proud and incompetent king and his      \n");           
       printf("   warriors, weakening their fighting strength enormously. This act definitively      \n");            
       printf("   condemned that king.                                                               \n\n");      

	   sleep(12);	
			
       exit(0);
    }

    //New King code
    //codigo executado pelo filho do rei
    else 
    {
    	sleep(16);
        
        //printf("General Inimigo: Por favor, poupe a minha vida!!!  \n\n");

        printf("   Enemy General: Please spare my life!!!  \n\n");

	    while(1) {}  
 	}
	     	    
    return 0;
}

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

    //New King code
    //Codigo executado pelo novo Rei
    if(pid != 0) 
    {
        char received[3];
        struct sigaction act;
        
        act.sa_handler = catch_ctrl_c;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sigaction(SIGINT, &act, NULL);
		
        //printf("O novo Rei parte rumo ao norte, para conter o ataque iminente. \n\n");

        printf("   The new King heads north to contain the impending attack. \n\n");
        
        sleep(5);
        
        /*printf("Por ser muito inteligente, ele se aproveita do fato de que seu   \n");
		printf("rosto eh desconhecido pelos comandantes inimigos e apos capturar \n");
		printf("um de seus generais faz uma proposta a ele..                     \n\n");*/
        
        printf("   Because he is very intelligent, he takes advantage of the fact that his face is    \n");      
        printf("   unknown to enemy commanders and he, after capturing one of his generals, makes him \n");      
        printf("   a proposal...                                                                      \n\n");     
        
        sleep(10);
        
        /*printf("Novo Rei: Voce, grande general, pode morrer aqui ou ser usado     \n");
		printf("          como um clone meu, vestira roupas reais e dois esqua-   \n");
		printf("          droes protegerao a sua localizacao, quando o exercito   \n");
		printf("          do seu pais descobrir a verdade voce estara livre.      \n\n");*/

        printf("   New King: You, great general, can die here or be used as a clone of me, you will   \n");         
        printf("   wear royal clothes and two squads will protect your location, when your countrys   \n");        
        printf("   army finds out the truth you will be free.                                         \n\n");     
         
        sleep(18);
		close(fd[1]);

        waitpid(-1, &status, WNOHANG);
        read(fd[0], received, sizeof(received));
        
        /*printf("Novo Rei: Sua resposta foi %s. como imaginei, voce inevitavelmente    \n", recebida);
		printf("          escolheria isso.                                            \n\n");*/
		
        printf("   New King: Your answer was as I imagined, you would inevitably choose that.    \n\n");

        close(fd[0]);
		sleep(6);
		
		void *stack = malloc(STACK);    // Stack for the new process
        if(!stack) {
                perror("Malloc Failed");
                exit(0);
        }
		
		if( clone(&clone_behavior, (char *)stack + STACK, CLONE_VM, 0) < 0)
        {
                perror("Clone Failed");
                exit(0);
        }
        
        free(stack);
        
        sleep(42);
        
        //printf("Pressione CTRL + C para ver o final da historia.\n\n");

        printf("   Press CTRL + C to see the end of the story. \n\n");
        
		while(flag) pause();
        
		exit(0);	
    }
    else
    {
    	sleep(30);
        char str[3] = "yes";
        close(fd[0]);

        //printf("General Inimigo: Tudo bem, eu aceito a sua proposta. \n\n");

        printf("   Enemy General: All right, I accept your proposal. \n\n");

        write(fd[1], str , strlen(str));
        close(fd[1]);
    }

    exit(0);
}
