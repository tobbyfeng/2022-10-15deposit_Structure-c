#include <stdio.h>

struct thing
{
	int num;
	char name[20];
	char *data;
};

void deposit(char **par,struct thing *pbr,int sizeA,int sizeB)  //存入
{
	int i = 0;
	for(i=0; i<sizeA; i++)
	{
		char *str = *(par+i);
		//num
		int val = 0;
		while(*str!=' ')
		{
			val = *str-'0'+val*10;
			str++;
		}
		pbr[i].num = val;
		str++;
		//name
		char *name = pbr[i].name;
		while(*str!=' ')
		{
			*name = *str;
			str++;
			name++;
		}
		str++;
		//data
		pbr[i].data = str;
	}
}

void show(struct thing *pbr,int size)
{
	int i = 0;
	for(i=0; i<size; i++)
	{
		printf( "brr.num = %d    \t", pbr[i].num );
		printf( "brr.name = %s   \t", pbr[i].name );
		printf( "brr.data = %s   \n", pbr[i].data );
	}
}

void swap(struct thing *arr,struct thing *brr)
{
	int num = arr->num;
	arr->num = brr->num;
	brr->num = num;
	
	int i = 0;
	for( i=0; i<20; i++ )
	{
		char name = arr->name[i];
		arr->name[i] = brr->name[i];
		brr->name[i] = name;
	}
	
	char *data = arr->data;
	arr->data = brr->data;
	brr->data = data;
}

void sortNum(struct thing *pbrr, int size)
{	
	int i = 0;
	int j = 0;
	for( i=0; i<size; i++ )
	{
		for( j=0; j<size-1-i; j++ )
		{
			if( pbrr[j].num > pbrr[j+1].num )
			{
				swap( pbrr+j, pbrr+j+1 );
			}
		}
	}
}

int cmp( char *arr, char *brr )
{
	while(*arr==*brr )
	{
		arr++;
		brr++;
	}
	return *arr-*brr;
}

void sortName( struct thing *pbrr, int size )
{
	int i = 0;
	int j = 0;
	for( i=0; i<size; i++ )
	{
		for( j=0; j<size-1-i; j++ )
		{
			if( cmp(pbrr[j].name, pbrr[j+1].name)>0 )
			{
				swap( pbrr+j, pbrr+j+1 );
			}
		}
	}
}

void sortData( struct thing *pbrr, int size )
{
	int i = 0;
	int j = 0;
	for( i=0; i<size; i++ )
	{
		for( j=0; j<size-1-i; j++ )
		{
			if( cmp(pbrr[j].data, pbrr[j+1].data)>0 )
			{
				swap( pbrr+j, pbrr+j+1 );
			}
		}
	}
}

void sort( struct thing *pbrr, int size, int idx )
{
	if( idx == 1 )
	{
		//	num
		sortNum( pbrr, size );
	}
	else if( idx == 2 )
	{
		//	name
		sortName( pbrr, size );
	}
	else if( idx == 3 )
	{
		//	data
		sortData( pbrr, size );
	}
}

int main()
{
	char *arr[] = {"70 snake tree","90 cat flower","60 pig grass","40 dog desk","20 fish vegetable"};
	struct thing brr[5] = {0};
	deposit( arr, brr, sizeof(arr)/sizeof(char*), sizeof(brr)/sizeof(struct thing) );
	sort( brr, sizeof(brr)/sizeof(brr[0]), 2 );
	show( brr, sizeof(brr)/sizeof(struct thing) );
	return 0;
}

