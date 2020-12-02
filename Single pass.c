#include<stdio.h>
#include<conio.h>
#include<string.h>
struct menumonic_table  
{
char op_code[7]; 
char class1[3]; 
char info[3]; 
}nem[20]; 
int checkreg(char var1[])  
    {
        if(strcmp(var1,"AREG")==0)
            return 1;
        if(strcmp(var1,"BREG")==0)
            return 2;
        if(strcmp(var1,"CREG")==0)
            return 3;
        else
            return 0;
    }
char symb[6][10],symb1[14][11];
int add[6];
int insert(char var[])
{
    static int i=1;
    strcpy(symb1[i],var);
    i+=1;
    return 0; 
}
int checksym(char var[])
{
    static int i=1;
    int j;
    for(j=1;j<=i;j++)
    {
       if(strcmp(symb[j],var)==0)
         return j;
    }
    strcpy(symb[i],var);
    i++;
    return 0;
}
int search(char var2[])
{
    int i;
    for(i=0;i<19;i++)
    {
        if(strcmp(var2,nem[i].op_code)==0)
            return i;
    }
    return 20;
}
main()
{ 
    int i;
   strcpy(nem[0].op_code,"ADD");
    strcpy(nem[0].class1,"IS");
    strcpy(nem[0].info,"01");
    strcpy(nem[1].op_code,"SUB");
    strcpy(nem[1].class1,"IS");
    strcpy(nem[1].info,"02");
    strcpy(nem[2].op_code,"MULT");
    strcpy(nem[2].class1,"IS");
    strcpy(nem[2].info,"03");
    strcpy(nem[3].op_code,"MOVER");
    strcpy(nem[3].class1,"IS");
    strcpy(nem[3].info,"04");
    strcpy(nem[4].op_code,"MOVEM");
    strcpy(nem[4].class1,"IS");
    strcpy(nem[4].info,"05");
    strcpy(nem[5].op_code,"COMP");
    strcpy(nem[5].class1,"IS");
    strcpy(nem[5].info,"06");
    strcpy(nem[6].op_code,"STOP");
    strcpy(nem[6].class1,"IS");
    strcpy(nem[6].info,"00");
    strcpy(nem[7].op_code,"BC");
    strcpy(nem[7].class1,"IS");
    strcpy(nem[7].info,"07");
    strcpy(nem[8].op_code,"DIV");
    strcpy(nem[8].class1,"IS");
    strcpy(nem[8].info,"08");
    strcpy(nem[9].op_code,"READ");
    strcpy(nem[9].class1,"IS");
    strcpy(nem[9].info,"09");
    strcpy(nem[10].op_code,"PRINT");
    strcpy(nem[10].class1,"IS");
    strcpy(nem[10].info,"10");
    strcpy(nem[11].op_code,"START");
    strcpy(nem[11].class1,"AD");
    strcpy(nem[11].info,"01");
    strcpy(nem[12].op_code,"END");
    strcpy(nem[12].class1,"AD");
    strcpy(nem[12].info,"02");
    strcpy(nem[13].op_code,"LTROG");
    strcpy(nem[13].class1,"AD");
    strcpy(nem[13].info,"03");
    strcpy(nem[14].op_code,"EQU");
    strcpy(nem[14].class1,"AD");
    strcpy(nem[14].info,"04");
    strcpy(nem[15].op_code,"ORIGIN");
    strcpy(nem[15].class1,"AD");
    strcpy(nem[15].info,"05");
    strcpy(nem[16].op_code,"DS");
    strcpy(nem[16].class1,"DL");
    strcpy(nem[16].info,"02");
    strcpy(nem[17].op_code,"DC");
    strcpy(nem[17].class1,"DL");
    strcpy(nem[17].info,"01");
    strcpy(nem[18].op_code,"LE");
    strcpy(nem[18].class1,"CS");
    strcpy(nem[18].info,"02");
    FILE *f1,*f2,*f3;
    int j=0,k=0,lc,sy,no,sym=0,reg,num,mac[20][10],add1[13];
    char var[256],var1[4][10];
    char delim[] = " ";
    static int m=1,n=1;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    f3=fopen("symtab.txt","w");
    while(k<18)
    {
        fgets(var,sizeof(var),f1);
        i=0;
        char *ptr = strtok(var, delim);
        while(ptr != NULL)
        {
            strcpy(var1[i],ptr);
            ptr = strtok(NULL, delim);
            i++;
        }
        j=i;
        strtok(var1+0,"\n");
        no=search(var1+0);
        if(strcmp(var1+0,"START")==0)
        {
            lc=atoi(var1+1);
        }
        if(strcmp(nem[no].info,"09")==0)
        {
            insert(var1+1);
            add1[n]=lc;
            n++;
            mac[m][0]=lc;
            mac[m][1]=atoi(nem[no].info);
            mac[m][2]=0;
            lc+=1;
            m+=1;
        }
        if(strcmp(nem[no].info,"04")==0||strcmp(nem[no].info,"05")==0||strcmp(nem[no].info,"06")==0)
        {
            insert(var1+2);
            add1[n]=lc;
            n++;
            reg=checkreg(var1+1);
            mac[m][0]=lc;
            mac[m][1]=atoi(nem[no].info);
            mac[m][2]=reg;
            //fprintf(f2,"%s %s %d s %d\n",nem[no].class1,nem[no].info,reg,sy);
            lc+=1;
            m+=1;
        }
        if(no==20)
        {
            int ad;
            no=search(var1+1);

            sy=checksym(var1+0);
            add[1]=lc;
            reg=checkreg(var1+2);
            if(strcmp(nem[no].class1,"DL")==0)
            {
                ad=checksym(var1+0);
                add[ad]=lc;
                mac[m][0]=lc;
                mac[m][1]=11;
                mac[m][2]=1;
                mac[m][3]=111;
                if(strcmp(nem[no].info,"01")==0)
                {
                    mac[m][1]=00;
                    mac[m][2]=0;
                    mac[m][3]=001;
                }
                m+=1;
            }
            else
            {
                insert(var1+3);
                add1[n]=lc;
                n++;
                mac[m][0]=lc;
                mac[m][1]=atoi(nem[no].info);
                mac[m][2]=reg;
                m+=1;
            }
            lc+=1;
        }
        if(strcmp(var1+0,"STOP")==0)
        {
            mac[m][0]=lc;
            mac[m][1]=00;
            mac[m][2]=0;
            mac[m][3]=000;
            lc+=1;
            m+=1;
        }
        if(strcmp(nem[no].info,"01")==0&&strcmp(nem[no].class1,"IS")==0)
        {
            insert(var1+2);
            add1[n]=lc;
            n++;
            reg=checkreg(var1+1);
            mac[m][0]=lc;
            mac[m][1]=atoi(nem[no].info);
            mac[m][2]=reg;
            //printf("(%s,%s) (%d) (s,%d)\n",nem[no].class1,nem[no].info,reg,sy);
            //fprintf(f2,"%s %s %d s %d\n",nem[no].class1,nem[no].info,reg,sy);
            lc+=1;
            m+=1;
        }
        if(strcmp(nem[no].info,"07")==0)
        {
            num=search(var1+1);
            mac[m][0]=lc;
            mac[m][1]=atoi(nem[no].info);
            mac[m][2]=atoi(nem[num].info);
            mac[m][3]=add[1];
            lc+=1;
            m+=1;
        }
        if(strcmp(nem[no].info,"10")==0)
        {
            insert(var1+1);
            add1[n]=lc;
            n++;
            reg=checkreg(var1+1);
            mac[m][0]=lc;
            mac[m][1]=atoi(nem[no].info);
            mac[m][2]=reg;
            lc+=1;
            m++;
        }
        k++;
    }
    for(i=1;i<=11;i++)
    {
        int l=*(add1+i)%100;
        for(j=1;j<=5;j++)
        {
            strtok(symb[j],"\n");
            strtok(symb1[i],"\n");
                if(strcmp(symb1[i],symb[j])==0)
                {
                    mac[l][3]=add[j];
                }
        }
    }
    for(i=1;i<=16;i++)
    {
        printf("%d %d %d %d\n",mac[i][0],mac[i][1],mac[i][2],mac[i][3]);
    }
}
