// ascyrax


/* Definition Section */
digit [0-9]
digits {digit}+
letter [A-Za-z]
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
 
	struct Node {
    		int rowNo;
		char type[10];
		char refId[10];
    		struct Node* next;
	};

	int getId();
	int getNumO();
%}


/* Rule Section */
/* Check the identifier */
/* Ignore everything else */
%%
{letter}({letter}|{digit}|_)*		 {printf("\n%s -> Identifier. \t", yytext); int rowNo = getId(); printf("Row No = %d.\n",rowNo); }
[+-]?{digits}(.{digits})?(e[+-]?{digits})?	 {printf("\n%s -> Number. \t", yytext);	int rowNo=getNumO(); printf("Row No = %d.\n",rowNo);}
.|\n 								;

%%


struct Node* head = NULL;
int nNodes;
int main()
{
	nNodes=0;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->rowNo=0;
	head->type[0]='r';
	head->refId[0]='r';


	extern FILE *yyin;
	char filename[100]; 
	//printf("\nEnter the name of the file to read:\t");
	//scanf("%s", filename);
	/* Opening file to read */
	//yyin = fopen(filename, "r");
	yyin=fopen("input.txt","r");
	if (yyin == NULL){
		printf("Cannot open file %s\n", filename);
	    exit(0);
	}
	/*call the yylex function.*/
	yylex();						
	return 0;
}

/*call the yywrap function*/
int yywrap()					
{
	return 1;
}

int getId(){
	// check the id for yytext.
	struct Node* temp=head;

	// traversal of the nodes
	/*
	printf("Traversal of the nodes:-\n");
	while(1){
		int i;
		for(i=0;temp->refId[i]!='\0';i++){
			printf("%c",temp->refId[i]);	
		}
		printf("\n");

		if(temp->next!=NULL)
			temp=temp->next;
		else
			break;
	}
	*/

	temp=head;
	while(1){
		bool flag=true;
		int i;
		for(i=0;;i++){
			if((yytext[i]=='\0' && temp->refId[i]!='\0')||(yytext[i]!='\0' && temp->refId[i]=='\0')){
				flag=false;
				break;
			}
			if(yytext[i]=='\0' && temp->refId[i]=='\0')break;
			//printf("compared : %c	%c\n",yytext[i],temp->refId[i]);
			if(yytext[i]!=temp->refId[i]){
				flag=false;
				break;
			}	
		}
		if(flag){
		// this string already exists
			return temp->rowNo;	
		}
		if(temp->next!=NULL)
			temp=temp->next;
		else
			break;
	}

	nNodes++;

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	temp->next=newNode;
	newNode->rowNo=temp->rowNo+1;
	int i;
	for(i=0;yytext[i]!='\0';i++){
		newNode->refId[i]=yytext[i];	
	}
	newNode->type[0]='i';
	newNode->type[1]='d';
	newNode->type[2]='\0';
	return newNode->rowNo;

	
}

int getNumO(){

	// check the id for yytext.
	struct Node* temp=head;

	// traversal of the nodes
	/*
	printf("Traversal of the nodes:-\n");
	while(1){
		int i;
		for(i=0;temp->refId[i]!='\0';i++){
			printf("%c",temp->refId[i]);	
		}
		printf("\n");

		if(temp->next!=NULL)
			temp=temp->next;
		else
			break;
	}
	*/

	temp=head;
	while(1){
		bool flag=true;
		int i;
		for(i=0;;i++){
			if((yytext[i]=='\0' && temp->refId[i]!='\0')||(yytext[i]!='\0' && temp->refId[i]=='\0')){
				flag=false;
				break;
			}
			if(yytext[i]=='\0' && temp->refId[i]=='\0')break;
			//printf("compared : %c	%c\n",yytext[i],temp->refId[i]);
			if(yytext[i]!=temp->refId[i]){
				flag=false;
				break;
			}	
		}
		if(flag){
		// this string already exists
			return temp->rowNo;	
		}
		if(temp->next!=NULL)
			temp=temp->next;
		else
			break;
	}

	nNodes++;

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	temp->next=newNode;
	newNode->rowNo=temp->rowNo+1;
	int i;
	for(i=0;yytext[i]!='\0';i++){
		newNode->refId[i]=yytext[i];	
	}
	newNode->type[0]='N';
	newNode->type[1]='o';
	newNode->type[2]='\0';
	return newNode->rowNo;


}





















