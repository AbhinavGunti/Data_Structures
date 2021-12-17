#include"list.h"

void init_list(list_t * ptr_list)
{
   ptr_list->head=NULL;
   }


void insert_head(list_t *ptr_list, int key)
{
	//empty list
	//list already present
	
	//create node and populate
	node_t *temp;
	
	 temp= (node_t*)malloc(sizeof(node_t));
	 temp->key=key;
	 temp->link=NULL;
	 
	 //empty list ?
	 if(ptr_list->head==NULL)
		 ptr_list->head=temp;
	 else
	 {
		 //list not empty
		 temp->link=ptr_list->head;
		 ptr_list->head=temp;
	 }
}
		
void insert_tail(list_t *ptr_list, int key)
{
//empty list
//list already present

	node_t *temp, *pres;
	//create node and populate it
	 temp= (node_t*)malloc(sizeof(node_t));
	 temp->key=key;
	 temp->link=NULL;
		 
	//empty list
	if(ptr_list->head==NULL)
		 ptr_list->head=temp;
	 else
	 {
		 pres=ptr_list->head; // get address of the first node
		 while(pres->link!=NULL)//go to the last node
			 pres=pres->link;
		 pres->link=temp;
	 }
}

void display(list_t *ptr_list)
{
	node_t* pres;
	if(ptr_list->head==NULL)//empty list
		printf("Empty List..\n");
	else
	{
		pres=ptr_list->head;
		while(pres!=NULL) //list present
		{
			printf("%d-> ",pres->key);
			pres=pres->link;
		}
	}
}

void insert_pos(list_t *ptr_list,int key, int pos)
{
  node_t *temp,*pres,*prev;
  int i=1;
  prev=NULL;
  
  pres=ptr_list->head;
  i=1;
  
  temp= (node_t*)malloc(sizeof(node_t));
  temp->key=key;
  temp->link=NULL;
	
	//keep moving forward until the position is found
	//or end of list is reached
	while((pres!=NULL)&&(i<pos))
	{
		prev=pres;
		pres=pres->link;
		i++;
	}
	if(pres!=NULL)//poistion found
	{
		//if first position
		if(prev==NULL)
		{
			temp->link=ptr_list->head;
			ptr_list->head=temp;
		}
		else 
		{
			temp->link=pres;
			prev->link=temp;
		}
	}
	else //pres=NULL
	{
       if(i==pos)//insert at end	
          prev->link=temp;
      else
          printf("Invalid position..\n");
	}
}	
			
	//function to delete first occurance of a node	
	void delete_node(list_t *ptr_list, int key)
	{
		node_t *prev, *pres;
		prev=NULL;
		pres=ptr_list->head;
		
		//move forward until the node is found
		//or you go beyond the last
		
		while((pres!=NULL)&&(pres->key!=key))
		{
			prev=pres;
			pres=pres->link;
		}
		if(pres==NULL)//node not found
		   printf("Node not found..\n");
		 else//node found
		 {
			 //first node
			 if(prev==NULL)
				 ptr_list->head=pres->link;
			 else
				 prev->link=pres->link;//somewhere in middle or last node
			 free(pres);
		 }
	}
			 
	void delete_pos(list_t *ptr_list, int pos)
    {
		node_t *prev,*pres;
		int i;
		
		prev=NULL;
		pres=ptr_list->head;//get address of first node
		  
		i=1;
		
		while((pres!=NULL)&&(i<pos))
		{
			prev=pres;
			pres=pres->link;
			i++;
		}
		
		if(pres==NULL)
		   printf("Invalid Position..\n");
	   else
	   {
		   if(prev==NULL)//first position
		     ptr_list->head=pres->link;
			else
              prev->link=pres->link;
		  free(pres);
	   }
	}	   
			   
		int count_nodes(list_t *ptr_list)
		{
             return(count_nodes_recur(ptr_list->head));
             printf("\n");
		}			 

        void reverse_list(list_t *ptr_list)
		{
			node_t *pres,*prev,*temp;
			prev=NULL;
			pres=ptr_list->head;
			
			while(pres!=NULL)
			{
				temp=pres->link;
				pres->link=prev;
				prev=pres;
				pres=temp;
			}
			ptr_list->head=prev;
		}
				
				
				
			
			
			   
		 int count_nodes_recur(node_t *pres)
		 {
			 if(pres->link==NULL)//one node
			    return 1;
			return(1+count_nodes_recur(pres->link));
		 }
		 
		 void display_reverse(list_t *ptr_list)
		 {
			 node_t *pres;
			 pres = ptr_list->head;//copy address of the first node
			 display_reverse_nodes(pres);
			 printf("\n");
		 }
		 
		 
		 void display_reverse_nodes(node_t *pres)
		 {
			 if(pres->link!=NULL)
				 display_reverse_nodes(pres->link);
			 printf("%d->",pres->key);
		 }
			 
			 
			 
		   
			
		
		
		
		  
		
		
		
		
		
		
	
	
		
		
		
	
		 
		 
		 
	 
		 
	 
	 
	