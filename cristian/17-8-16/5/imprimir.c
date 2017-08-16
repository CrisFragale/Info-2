void imprimir (nodo_t *h)
{
	nodo_t* i;
	i=h;
	while (i!=NULL)
	{
		printf("dato %d \n",i->a);
		i=i->next;
	}
	return;
} 
