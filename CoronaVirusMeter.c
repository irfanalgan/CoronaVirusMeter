//IRFAN KAAN ALGAN 2328599//
#include "avltree.h" 

AVLTree readCountries(AVLTree,int);
AVLTree insertCountry(AVLTree,struct Node *,int);
void displayAllCountries(AVLTree);
void maxTotalTest(AVLTree);
void minimumTotalDeaths(AVLTree);

int main(int argc,char *argv[]) {
	

	int command,exit = FALSE,flag = 0;	
	int check = 0,check1 = 0;
	
	AVLTree myTreeCase = NULL;	//Tree sorted with respect to total case
	AVLTree myTreeTest = NULL;	//Tree sorted with respect to total test
	AVLTree myTreeDeaths = NULL;	//Tree sorted with respect to total Deaths
	

	myTreeCase=readCountries(myTreeCase,flag);

	
	
	printf(">>>Welcome to CoronaVirusMeter analyser <<<\n");
	
	while(!exit){
		fflush(stdin);
        printf(" --Menu--  \n1. Display all countries \n2. Display the country with the maximum total test cases  \n3. Display the country with the minimum total deaths \n4. Exit\nEnter Option:");
    	scanf("%d",&command);  
        fflush(stdin);
        printf("\n");
        switch(command){
        	case 1:
	        	printf("--- All countries in the database --- \n\n");
	        	displayAllCountries(myTreeCase);
	        	printf("\n\n");
	        	break;
	        case 2:
	        	flag = 1;
	        	if(check == 0){
	        		myTreeTest = readCountries(myTreeTest,flag);
	        		check++;
	        	}
	        	maxTotalTest(myTreeTest);
	        	break;
        	case 3:
				flag = 2;
	        	if(check1 == 0){
	        		myTreeDeaths = readCountries(myTreeDeaths,flag);
	        		check1++;
	        	}
	        	minimumTotalDeaths(myTreeDeaths);
	        	break;	
	        case 4:
        		printf("BYEE!");
        		exit=TRUE;
                break;
        	default:
        		printf("Please enter a valid option!\n");
                break;	
        	
		}
		
	}
	
}


AVLTree readCountries(AVLTree myTree,int flag){
	
	FILE *myFile;
	myFile=fopen("dataText.txt","r");
	if(myFile==NULL)	
	{
		printf("There was an error while reading the file!");
		exit(1);
	}

	struct Node *temp=(struct Node *)malloc(sizeof(struct Node ));

	if(temp==NULL)
	{
		printf("Out Of Memory!");
		exit(1);
	}
	
	while(fscanf(myFile, "%[^;];%d;%d;%d;%d;%d\n", temp->countryName,&temp->TotalTest,&temp->TotalCase,&temp->TotalDeaths,&temp->TotalRecovered,&temp->ActiveCases) !=EOF)
		myTree=insertCountry(myTree,temp,flag); 


	fclose(myFile);
	return myTree;
}

AVLTree insertCountry(AVLTree tree,struct Node *temp,int flag){
	if(flag == 0){
		if(tree == NULL){
			tree=malloc(sizeof(struct Node));
				
				if(tree==NULL) 
				{
	       			printf("Out Of Memory!");
	       	 		exit(1);
				}	
				
					strcpy(tree->countryName, temp->countryName); 
					tree->TotalTest = temp->TotalTest;
	            	tree->TotalCase = temp->TotalCase;
					tree->TotalDeaths = temp->TotalDeaths;
					tree->TotalRecovered = temp->TotalRecovered;
					tree->ActiveCases = temp->ActiveCases;
					
					tree->count=1;
					
					tree->height = 0;
					tree->left=NULL;	tree->right=NULL;
		}
		else{
			if(tree->TotalCase == temp->TotalCase)
				tree->count++;
			
			if(temp->TotalCase < tree->TotalCase){
				tree->left = insertCountry(tree->left,temp,flag);
				
				if (AVLTreeHeight(tree->left) - AVLTreeHeight(tree->right) == 2)
					if (temp->TotalCase < tree->left->TotalCase)
						tree= SingleRotateWithLeft(tree);
					else
						tree = DoubleRotateWithLeft(tree);
				
			}
			else if(temp->TotalCase > tree->TotalCase){
				tree->right = insertCountry(tree->right,temp,flag);
				if (AVLTreeHeight(tree->right) - AVLTreeHeight(tree->left) == 2)
					if (temp->TotalCase > tree->right->TotalCase)
						tree=SingleRotateWithRight(tree);
					else
						tree=DoubleRotateWithRight(tree);
				
			}
			
			fflush(stdin);	
		}
	}
	if(flag == 1){
		if(tree == NULL){
			tree=malloc(sizeof(struct Node));
				
				if(tree==NULL) 
				{
	       			printf("Out Of Memory!");
	       	 		exit(1);
				}	
				
					strcpy(tree->countryName, temp->countryName); 
					tree->TotalTest = temp->TotalTest;
	            	tree->TotalCase = temp->TotalCase;
					tree->TotalDeaths = temp->TotalDeaths;
					tree->TotalRecovered = temp->TotalRecovered;
					tree->ActiveCases = temp->ActiveCases;
					
					tree->count=1;
					
					tree->height = 0;
					tree->left=NULL;	tree->right=NULL;
		}
		else{
			if(tree->TotalTest== temp->TotalTest)
				tree->count++;
			
			if(temp->TotalTest < tree->TotalTest){
				tree->left = insertCountry(tree->left,temp,flag);
				
				if (AVLTreeHeight(tree->left) - AVLTreeHeight(tree->right) == 2)
					if (temp->TotalTest < tree->left->TotalTest)
						tree= SingleRotateWithLeft(tree);
					else
						tree = DoubleRotateWithLeft(tree);
				
			}
			else if(temp->TotalTest > tree->TotalTest){
				tree->right = insertCountry(tree->right,temp,flag);
				if (AVLTreeHeight(tree->right) - AVLTreeHeight(tree->left) == 2)
					if (temp->TotalTest > tree->right->TotalTest)
						tree=SingleRotateWithRight(tree);
					else
						tree=DoubleRotateWithRight(tree);
				
			}
			
			fflush(stdin);	
		}
	}
	if(flag == 2){
		if(tree == NULL){
			tree=malloc(sizeof(struct Node));
				
				if(tree==NULL) 
				{
	       			printf("Out Of Memory!");
	       	 		exit(1);
				}	
				
					strcpy(tree->countryName, temp->countryName); 
					tree->TotalTest = temp->TotalTest;
	            	tree->TotalCase = temp->TotalCase;
					tree->TotalDeaths = temp->TotalDeaths;
					tree->TotalRecovered = temp->TotalRecovered;
					tree->ActiveCases = temp->ActiveCases;
					
					tree->count=1;
					
					tree->height = 0;
					tree->left=NULL;	tree->right=NULL;
		}
		else{
			if(tree->TotalDeaths == temp->TotalDeaths)
				tree->count++;
			
			if(temp->TotalDeaths < tree->TotalDeaths){
				tree->left = insertCountry(tree->left,temp,flag);
				
				if (AVLTreeHeight(tree->left) - AVLTreeHeight(tree->right) == 2)
					if (temp->TotalDeaths < tree->left->TotalDeaths)
						tree= SingleRotateWithLeft(tree);
					else
						tree = DoubleRotateWithLeft(tree);
				
			}
			else if(temp->TotalDeaths > tree->TotalDeaths){
				tree->right = insertCountry(tree->right,temp,flag);
				if (AVLTreeHeight(tree->right) - AVLTreeHeight(tree->left) == 2)
					if (temp->TotalDeaths > tree->right->TotalDeaths)
						tree=SingleRotateWithRight(tree);
					else
						tree=DoubleRotateWithRight(tree);
				
			}
			
			fflush(stdin);	
		}
	}

		
	tree->height = Max(AVLTreeHeight(tree->left), AVLTreeHeight(tree->right)) + 1;	
	
	return tree;
	
}


void displayAllCountries(AVLTree t) 
{
	if(t!=NULL)
	{	
	
		displayAllCountries(t->right);
		
		printf("%s;%d;%d;%d;%d;%d;\n",t->countryName,t->TotalTest,t->TotalCase,t->TotalDeaths,t->TotalRecovered,t->ActiveCases);
		displayAllCountries(t->left);
						
	}
}

void maxTotalTest(AVLTree t){
	
	
    while (t->right != NULL)  
        t = t->right; 
      
   	printf("Country: %s\nTotal Test: %d\nTotal Case: %d\nTotal Deaths: %d\nTotal Recovered: %d\nActive Cases: %d\n\n",t->countryName,t->TotalTest,t->TotalCase,t->TotalDeaths,t->TotalRecovered,t->ActiveCases);
	
}
void minimumTotalDeaths(AVLTree t){
	
	 while (t->left != NULL)  
        t = t->left; 
      
   	printf("Country: %s\nTotal Test: %d\nTotal Case: %d\nTotal Deaths: %d\nTotal Recovered: %d\nActive Cases: %d\n\n",t->countryName,t->TotalTest,t->TotalCase,t->TotalDeaths,t->TotalRecovered,t->ActiveCases);
	
	
	
}

