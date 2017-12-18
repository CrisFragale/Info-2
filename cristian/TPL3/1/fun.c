int my_strEqu( char * str1, char * str2)
{
	int i;
	for (i=0;str1[i]!='\0';i++)
	{
	    if((str1[i])!=(str2[i]))
	    { 
         	return (0);   
	    }	
	}
	if(str2[i]=='\0')
	{
		return 1;
	}else{
		return 0;
	}
}

  
