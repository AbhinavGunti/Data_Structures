#include "dll.h"
int main()
{
	int ch,key,pos;
	dlist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("/n");
		printf("\n1.insert_head");
		printf("\n2.insert_tail");
		printf("\n3.Display");
		printf("\n4.delete first node");
		printf("\n5.Delete Last Node..");
		printf("\n6.Delete a node given value");
		printf("\n7.Delete at a position");
		printf("\n8.Insert at a Given Position");
		printf("\n9.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_head(&l,key);
						 break;
		case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
						 insert_tail(&l,key);
						 break;			 
		  case 3:display(&l);
			             break;
			case 4:delete_first(&l);
              			break;		
			case 5:delete_last(&l);
              			break;				
		   case 6:printf("\nEnter the key...");
			             scanf("%d",&key);
						 delete_node(&l,key);	
                         break;	
		  case 7:printf("\nEnter the position");
			             scanf("%d" ,&pos);
						 delete_pos(&l,pos);
						 break;	
			case 8:printf("\nEnter the key and position");
			             scanf("%d %d" ,&key,&pos);
						 insert_pos(&l,key,pos);
						 break;
			case 9:exit(0);
		}
	}
}
						 
			
			
			
			