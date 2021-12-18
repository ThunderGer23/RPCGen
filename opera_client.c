/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "opera.h"


void
ope_prog_1(char *host)
{
	CLIENT *clnt;
	EsMat  *result_1;
	r_times_Mat  product_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, OPE_PROG, OPE_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

int flag=1;
	int choice;
	int n;
	float r;

	do
	{
		printf("==========================\n");
		printf("=====Vector * Escalar=====\n");
		printf("==========================\n");
		printf("1. r*X[]\n");
		printf("2. Quit\n");
		printf("==========================\n");
		printf("Choice: ");
		scanf("%d", &choice);
		printf("==========================\n");
		
	if(choice==1){
			///////////////////////////////////////////////////////
			//r*X[]
			///////////////////////////////////////////////////////
			printf("Give size of X[]: ");
			scanf("%d", &n);
		
			printf("\n");
			
			product_1_arg.Mat.Mat_len=n;
			product_1_arg.Mat_size=n;
			product_1_arg.Mat.Mat_val=(int *) malloc(n*sizeof(int));
			
			for(int i=0;i<n;i++)
			{
				printf("X[%d] = ", i);
				scanf("%d", &product_1_arg.Mat.Mat_val[i]);	
			}
			
			printf("Give floating number r: ");
			scanf("%f", &r);
			
			product_1_arg.Es=r;
			
			printf("\n");

		result_1 = product_1(&product_1_arg, clnt);
		if (result_1 == (EsMat *) NULL) {
			clnt_perror (clnt, "call failed");
		}else{
			printf("\n");
				for(int i=0;i<n;i++)
					printf("r*X[%d] == %.2f\n", i, result_1->prod.prod_val[i]);
				printf("\n");
		}
		
	}else if(choice == 2){
		flag=0;
	}else{
		printf("Invalid Choice. Try Again.\n\n");
	}
}while(flag);

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	ope_prog_1 (host);
exit (0);
}
