#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


int add_to_list(linked_list *ll, char *s)
{
	struct linked_list *x = ll;
	struct linked_list *temp = (linked_list*)malloc(sizeof(linked_list));
	int i = 0;
	
	if(x==NULL) return -1;
	temp->data = s; 
	temp->next = NULL; //add new node to the end of the list so next pointer is NULL

	while(x) 
	{
		if (x->index > i) i = x->index; //continue to "move" (number of node increase)
		if (x->next==NULL) break; //loop ends when reaching the final node
		x = x->next;
	}
	
	i++; 
	temp->index = i;
	x->next = temp;
	
	return temp->index;
}

int display_item(linked_list *ll)
{
	if(ll->data==NULL)
	{
		return -1;
	}
	else
	{
		printf("%s\n",ll->data);
		return 0;
	}
	
}

int display_list(linked_list *ll)
{
	int count=0;
	
	if(ll->data==NULL)
	{
		count=0;
		ll=ll->next;
	}
	while(ll!=NULL)
	{
		printf("%s\n",ll->data);
		ll=ll->next;
		count++;
	}
	
	return count; //return number of elements in list
}

linked_list * search_from_list(linked_list *ll, char *s)
{
	struct linked_list* x=ll;
	
	while(x!=NULL)
	{ 
		if(x->data== s)
		{
			return x;
		}
		
		x=x->next;
	}
	
	return NULL;
}

int delete_from_list(linked_list *ll, int index)
{
	struct linked_list* current=ll; //current node
	struct linked_list* temp; //temporary node
	int i=0;
	
	if(index<=0 || index>display_list(ll)) return -1;
	
	for(i=0;i<=index-2;i++){ //loop from start to the node need to be deleted
		
		current=current->next; //move the next pointer until reaching the wanted node
	}
	
	temp=current->next;
	current->next=temp->next;
	free(temp); //free the memory of the temporary node
	
	return display_list(ll)-1;
}

int empty_list(linked_list *ll)
{
    linked_list *current,*next;
 
    if(ll != NULL)
    {
        current = ll->next; 
        ll->next = NULL;
        while(current != NULL)
        {
            next = current->next; //set next as next of current node
            free(current);//free the memory of the current node
            current = next; //move current to next node
        }
    }
	
	return display_item(ll); //return number of nodes in list
}

void sort_list(linked_list *ll)
{//creat 2 temporary nodes and allocate their memories

	linked_list *temp1;                         
	temp1 = (linked_list*)malloc(sizeof(linked_list)); 
 
	linked_list *temp2;                         
	temp2 = (linked_list*)malloc(sizeof(linked_list)); 
 
	char *temp;                        
 
	for( temp1 = ll ; temp1!=NULL ; temp1 = temp1->next )
	{
		for( temp2 = temp1->next ; temp2!=NULL ; temp2 = temp2->next )
		{
            if( temp1->data > temp2->data ) //check if node1's data is greater than node2's data
            {
                  temp = temp1->data;
                  temp1->data = temp2->data;
                  temp2->data = temp;
            }
		}
	}
}

void swap_items(linked_list *f, linked_list *s)
{
	char *temp= f->data;
	f->data=s->data;
	s->data=temp;
}
