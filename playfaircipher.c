#include<stdio.h>
int findrow(int size,char mat[size][size],char c)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(mat[i][j]==c||c=='i'&&mat[i][j]=='j'||c=='j'&&mat[i][j]=='i')
            {
                return i;
            }
        }
    }
}
int findcol(int size,char mat[size][size],char c)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(mat[i][j]==c||c=='i'&&mat[i][j]=='j'||c=='j'&&mat[i][j]=='i')
            {
                return j;
            }
        }
    }
}
int main()
{
    char mat[5][5]={' '};
    char key[26];
    printf("Enter the key \n");
    scanf("%s",key);
    int i,j;
    for(i=0;key[i]!='\0';i++)
    {
        for(j=i+1;key[j]!='\0';j++)
        {
            if(key[i]==key[j])
            {
                key[j]='*';
            }
            if(key[i]=='i'&&key[j]=='j')
            {
                key[j]='*';
            }
            if(key[i]=='j'&&key[j]=='i')
            {
                key[j]='*';
            }
        }
    }
    char key1[26];
    j=0;
    for(i=0;key[i]!='\0';i++)
    {
        if(key[i]!='*')
        {
            key1[j]=key[i];
            j++;
        }
    }
    key1[j]='\0';
    int row=0,column=0;
    for(i=0;key1[i]!='\0';i++)
    {
        if(column==5)
        {
            column=0;
            row++;
        }
        mat[row][column]=key1[i];
        column++;
    }
    int alpha[26]={0};
    for(i=0;key1[i]!='\0';i++)
    {
        alpha[key1[i]-'a']++;
    }
    if(alpha[8]==1||alpha[9]==1)
    {
        alpha[9]=1;
        alpha[8]=1;
    }
    int flag=0;
    for(i=0;i<26;i++)
    {
         if(alpha[i]==0&&i!=9)
         {
             if(column==5)
            {
            column=0;
            row++;
            }
            mat[row][column]=(char)i+97;
            column++;
         }
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }
    char string1[100];
    char string2[100];
    printf("\n Enter the string \n");
    scanf(" %[^\n]s",string1);
    j=0;
    for(int i=0;string1[i]!='\0';i++)
    {
        if(string1[i]==' ')
        {
            string2[j]='x';
            j++;
        }
        else if(string1[i]==string1[i+1])
        {
            string2[j]=string1[i];
            string2[j+1]='x';
            j=j+2;
        }
        else
        {
            string2[j]=string1[i];
            j++;
        }
    }
    string2[j]='\0';
    int len=strlen(string2);
	if(len%2!=0)
	{
		string2[len]='x';
	}
	string2[len+1]='\0';
	printf("%s\n",string2);
	int row1,row2,column1,column2;
	for(i=0;i<len;i=i+2)
	{
		row1=findrow(5,mat,string2[i]);
		row2=findrow(5,mat,string2[i+1]);
		column1=findcol(5,mat,string2[i]);
		column2=findcol(5,mat,string2[i+1]);
		if(row1==row2)
		{
		    if(column1+1==5)
		    {
		        column1=-1;
		    }
		    if(column2+1==5)
		    {
		        column2=-1;
		    }
		    printf("%c %c -> ",string2[i],string2[i+1]); 
		    printf("%c %c",mat[row1][column1+1],mat[row1][column2+1]);
		    printf("[same rows] \n");
		}
		else if(column1==column2)
		{
		    if(row1+1==5)
		    {
		        row1=-1;
		    }
		    if(row2+1==5)
		    {
		        row2=-1;
		    }
		    printf("%c %c -> ",string2[i],string2[i+1]); 
		    printf("%c %c",mat[row1+1][column1],mat[row2+1][column1]);
		    printf("[same columns]\n");
		}
		else
		{
		    printf("%c %c -> ",string2[i],string2[i+1]); 
		    printf("%c %c",mat[row1][column2],mat[row2][column1]);
		    printf("[different rows and different columns]\n");
		}
		
	}	
    return  0;
}
