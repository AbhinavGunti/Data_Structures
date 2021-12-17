#include"dll.h"

void init_list(dlist_t * ptr_list)
{
	ptr_list->head=NULL;
}

void delete_node(dlist_t *ptr_list, int key)
{
	node_t *pres;
	
	pres=ptr_list->head;
	
	//move forward until the key is found
	//or you go beyond the last node
	while((pres!=NULL)&&(pres->key!=key))
	     pres=pres->next;
	
    if(pres!=NULL)//key found
   {
	  //where ?
	  //if only one node
	  if((pres->next==NULL)&&(pres->prev==NULL))
		  ptr_list->head=NULL;
	  else if(pres->prev==NULL)//first node
	  {
		  pres->next->prev=NULL;
		  ptr_list->head=pres->next;
	  }
	  else if(pres->next==NULL)//last node
	       pres->prev->next=NULL;
	  else//middle node
	  {
		  pres->prev->next=pres->next;
		  pres->next->prev=pres->prev;
	  }
	  free(pres);
  } 
  else //pres=NULL
	printf("Node not found");
}	
		  
		  
	void insert_pos(dlist_t *ptr_list, int key, int pos)
	{
          node_t *temp,*pres;
	    int i;
		temp=(node_t*)malloc(sizeof(node_t));
		temp->key=key;
		temp->next=temp->prev=NULL;

		pres=ptr_list->head;
		i=1;
		while((i<pos)&&(pres->next!=NULL))
		{
			i++;
			pres=pres->next;
		}
		if(i==pos)//position found
		{
			if(pres->prev==NULL)//first position
			{
				pres->prev=temp;
				temp->next=pres;
				ptr_list->head=temp;
			}
			else //somehere in middle position
			{
			 pres->prev->next=temp;
			  temp->prev=pres->prev;
			  temp->next=pres;
			  pres->prev=temp;
		  }
		}
		else if  (i==pos-1)//insert at end
		{ 
		   pres->next=temp;
		   temp->prev=pres;
		}
    	else
		  printf("not valid position..");
	}
		
			  
	void delete_pos(dlist_t *ptr_list, int pos)
{
	node_t *pres;
	int i;
	
	pres=ptr_list->head;
	
	//move forward until the positionis found
	//or you go beyond the last node
	i=1;
	
	while((pres!=NULL)&&(i<pos))
	{
		 i++;
	     pres=pres->next;
	}
	
    if(pres!=NULL)//position found
   {
	  //where ?
	  //if only one node
	  if((pres->next==NULL)&&(pres->prev==NULL))
		  ptr_list->head=NULL;
	  else if(pres->prev==NULL)//first node
	  {
		  pres->next->prev=NULL;
		  ptr_list->head=pres->next;
	  }
	  else if(pres->next==NULL)//last node
	       pres->prev->next=NULL;
	  else//middle node
	  {
		  pres->prev->next=pres->next;
		  pres->next->prev=pres->prev;
	  }
	  free(pres);
  } 
  else //pres=NULL
	printf("Node not found");
}		  
		  
		  
		  
	  
	  
		  
		  
		  
		  
	  
		  
	  
	  
	  
	
	
	
	 
	 
	 
	


void delete_last(dlist_t *ptr_list)
{
	node_t *pres;
	
	pres=ptr_list->head;
	
	//if only one node
	if(pres->next==NULL)
		ptr_list->head=NULL;
	else
	{ 
    //go to last node
    while(pres->next!=NULL)
		 pres=pres->next;
	 
	 pres->prev->next=NULL;
	}
	 free(pres);
}		
			

void delete_first(dlist_t *ptr_list)
{
	
	node_t* pres;
	
	pres=ptr_list->head;
	
	if(pres->next==NULL)////only one node
		ptr_list->head=NULL;
	else
	{
		pres->next->prev=NULL;
		ptr_list->head=pres->next;
	}
	free(pres);
}
		
	
	void insert_head(dlist_t *ptr_list, int key)
    {
	node_t *temp;
	
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=key;
	temp->next=temp->prev=NULL;
	
	//empty list
	if(ptr_list->head==NULL)
		ptr_list->head=temp;
	else
	{
		temp->next=ptr_list->head;
		ptr_list->head->prev=temp;
		ptr_list->head=temp;
	}
}

void display(dlist_t *ptr_list)
{
	node_t *pres;
	
	pres=ptr_list->head;
	
	if(pres==NULL)
		printf("Empty List..\n");
	else
	{
		while(pres!=NULL)
		{
			printf("%d<=>",pres->key);
			pres=pres->next;
		}
	}
}
		
	void insert_tail(dlist_t *ptr_list, int key)
    {
	node_t *temp,*pres;
	
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=key;
	temp->next=temp->prev=NULL;
		
	//empty list
	if(ptr_list->head==NULL)
		ptr_list->head=temp;	
	else
	{
		//go to the last node
		pres=ptr_list->head;
		while(pres->next!=NULL)
			   pres=pres->next;
		pres->next=temp;
		temp->prev=pres;
	}
}
		
		
		
		
		
		
		
		
	
	
	

  



			 
			 
		   
			
		
		
		
		  
		
		
		
		
		
		
	
	
		
		
		
	
		 
		 
		 
	 
		 
	 
	 
	