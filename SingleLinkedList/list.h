#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  struct node *link;
  };
  
  typedef struct node node_t;
  
  struct list
  {
	  node_t* head;
  };
  
  typedef struct list list_t;
  
  void init_list(list_t*);
  void insert_head(list_t*,int);
  void insert_tail(list_t*,int);
  void insert_pos(list_t*,int,int);
  void delete_node(list_t*,int);
  void delete_pos(list_t*,int);
  void display(list_t*);
  void display_reverse_nodes(node_t *);
  void display_reverse(list_t *);
  int count_nodes(list_t*);
  int count_nodes_recur(node_t *);
  void reverse_list(list_t*);
  
  
  
  
  
  