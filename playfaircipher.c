#include<stdio.h>
#include<string.h>
int main()
{
	char key[100];
	scanf("%s",key);
	char mat[5][5];
	int i,j;
	int row=0,column=0;
	for(i=0;key[i]!='\0';i++)
	{
		for(j=i+1;key[j]!='\0';j++)
		{
			if(key[i]==key[j])
			{
				key[j]='*';
			}
		}
	}
	j=0;
	char newmat[100];
	for(i=0;key[i]!='\0';i++)
	{
		if(key[i]!='*')
		{
		newmat[j]=key[i];
		j++;
		}
	}
	newmat[j]='\0';
	for(i=0;key[i]!='\0';i++)
	{
		mat[row][column]=newmat[i];
		if(column>=4)
		{
			column=0;
			row++;
		}
		else
		{
		column++;
		}
	}	
	int alpha[26]={0};
	for(i=0;newmat[i]!='\0';i++)
	{
		alpha[newmat[i]-'a']++;		
	}
	for(i=0;i<26;i++)
	{
		if(alpha[i]==0)
		{
			mat[row][column]=(char)i+97;
			if(mat[row][column]=='i')
			{
				i++;
			}
			if(column>=4)
			{
			column=0;
			row++;
			}
			else
			{
			column++;
			}
		}
	}
	for(i=0;i<5;i++)
	{
	for(j=0;j<5;j++)
	{
		printf("%c ",mat[i][j]);
	}
	printf("\n");
	}
	char string[100];
	scanf(" %[^\n]s",string);
	for(i=0;string[i]!='\0';i++)
	{
		if(string[i]==' ')
		{
			string[i]='x';
		}
	}
	printf("%s \n",string);
	int len=strlen(string);
	if(len%2!=0)
	{
		string[len]='x';
	}
	string[len+1]='\0';
	printf("%s",string);
	for(i=0;i<len;i=i+2)
	{
		printf("%c %c\n",string[i],string[i+1]);		
	}	
	return 0;
}

