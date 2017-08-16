int insertarFin(nodo_t** ptr_h, int d){
	nodo_t* aux;
	nodo_t* i;

	
	aux=(nodo_t*)malloc(sizeof(nodo_t));
	if(aux==NULL){
		return -1;
	}
	aux->a=d;
	aux->next=NULL;
	
	

	if((*ptr_h)==NULL){
		(*ptr_h)=aux;
	}
	else{
		i=*ptr_h;
		while(i->next!=NULL){
			i=i->next;
		}
		i->next=aux;
	}
	return 0;
}

void imprimir (nodo_t* h){
	nodo_t* i;
	i=h;
	while(1!=NULL){
		printf("dato: %d\n", i->a);
	}
}