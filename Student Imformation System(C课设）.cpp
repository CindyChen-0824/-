#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define LEN sizeof(struct student)
#define FORMAT "%-12d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].sum


struct student//ѧ���ɼ���Ϣ�ṹ�� 
{ int num;//ѧ��
  char name[15];//����
  double elec;//ѡ�޿�
  double expe;//ʵ���
  double requ;//���޿�
  double sum;//�ܷ�
};


struct student stu[50];/*����ṹ������*/
void log();/*�����½*/
void input();/*¼��ѧ���ɼ���Ϣ*/
void show();/*��ʾѧ����Ϣ*/
void order();/*���ܷ�����*/
void del();/*ɾ��ѧ���ɼ���Ϣ*/
void modify();/*�޸�ѧ���ɼ���Ϣ*/
void menu();/*�˵�*/
void insert();/*����ѧ����Ϣ*/ 
void total();/*ͳ��������*/
void search();/*����ѧ����Ϣ*/


void log()/*�����½*/
{  
	int i; 
    char password[20]={0};
		printf("����������:\n");
	for(i=0;i<3;i++)
	{
		scanf("%s",password);
			if(i<2)
			{
				if(strcmp("GXU19282018",password)!=0)
				{
					do
					{
						printf("��������ٴ�����:\n");
					}while(strcmp("GXU19282018",password)==0);
				}
				else
					if(strcmp("GXU19282018",password)==0)
					{
						printf("��ӭʹ��ѧ���ɼ�����ϵͳ!\n");
						printf("\n\n");		
						menu(); break;/*����˵�*/		
				    }
			}
			if(i==2)
			printf("NULLNULLNULL\n");	
	}
}
  
void input()/*¼��ѧ����Ϣ*/
{ int i,m=0;/*m�Ǽ�¼������*/
  char ch[2];  
  FILE *fp;/*�����ļ�ָ��*/
  if((fp=fopen("score.dat","a+"))==NULL)/*��ָ���ļ�*/
  { 
	  printf("can not open\n");
	  return;
  }
  while(!feof(fp))
  {
	  if(fread(&stu[m] ,LEN,1,fp)==1)
		  m++;/*ͳ�Ƶ�ǰ��¼����*/
  }
  fclose(fp);
  if(m==0)
	  printf("No record!\n");
  else
  {
	  system("cls");
          show();/*����show��������ʾԭ����Ϣ*/
  }

  if((fp=fopen("score.dat","wb"))==NULL)
  {
	  printf("can not open\n");
	  return;
  }
  for(i=0;i<m;i++)
  {
   fwrite(&stu[i] ,LEN,1,fp);/*��ָ���Ĵ����ļ�д����Ϣ*/
  }
    system("cls");
    printf("please input(1/0)(1Ϊ������0Ϊ����¼��)):");
  scanf("%s",ch);
while(strcmp(ch,"1")==0||strcmp(ch,"1")==0)/*�ж��Ƿ�Ҫ¼������Ϣ*/
	{
    printf("ѧ��:");
	scanf("%d",&stu[m].num);/*����ѧ��ѧ��*/
   for(i=0;i<m;i++)
	    if(stu[i].num==stu[m].num)
	    {
	    printf("����Ϣ�Ѿ�����!");
	    getch();
	    fclose(fp);
	    return;
	    }
	
     printf("����:");
	 scanf("%s",stu[m].name);/*����ѧ������*/

     printf("ѡ�޿�:");

     scanf("%lf",&stu[m].elec);/*����ѡ�޿γɼ�*/
     printf("ʵ���:");
	 scanf("%lf",&stu[m].expe);/*����ʵ��γɼ�*/
     printf("���޿�:");
	 scanf("%lf",&stu[m].requ);/*������޿γɼ�*/
     stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ;/*������ܳɼ�*/
     if(fwrite(&stu[m],LEN,1,fp)!=1)/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
     {
		 printf("can not save!");
		 getch();
	 }
     else
	 {
		 printf("%s ͬѧ����Ϣ�ɹ�����!\n",stu[m].name);
		 m++;
	 }
     printf("������ǰ����?(1/0)(1Ϊ������0Ϊ�˳�):");/*ѯ���Ƿ����*/
     scanf("%s",ch);
  }
  fclose(fp);
  printf("OK!\n");
}

void show()
 { FILE *fp;
   int i,m=0;
   fp=fopen("score.dat","rb");
   while(!feof(fp))
   {
   if(fread(&stu[m] ,LEN,1,fp)==1) 
   m++;
   }  
   fclose(fp);
   printf("ѧ��       ����       ѡ�޿�      ʵ���      ���޿�      �ܷ�\t\n");
   for(i=0;i<m;i++)
       { 
	   printf(FORMAT,DATA);/*����Ϣ��ָ����ʽ��ӡ*/
       }
     }
 
void menu()/*�Զ��庯��ʵ�ֲ˵�����*/
{
  system("cls");
  printf("\n\n\n\n\n");
  printf("\t\t|----------------------------STUDENT------------------------|\n");
  printf("\t\t|\t 0. �˳�ϵͳ exit                                   |\n");
  printf("\t\t|\t 1. ¼��ѧ���ɼ���Ϣinput record                    |\n");
  printf("\t\t|\t 2. ��ѯѧ����Ϣsearch record                       |\n");
  printf("\t\t|\t 3. ɾ��ѧ���ɼ���Ϣdelete record                   |\n");
  printf("\t\t|\t 4. �޸����ɼ���Ϣmodify record                     |\n");
  printf("\t\t|\t 5. �����¼���ɼ���Ϣinsert record                 |\n");
  printf("\t\t|\t 6. �ɼ�����order                                   |\n");
  printf("\t\t|\t 7. ͳ��¼��������number                            |\n");
  printf("\t\t|\t 8. ��ӡ�ɼ��ܱ�show                                |\n");
  printf("\t\t|-----------------------------------------------------------|\n\n");
  printf("\t\t\t��ѡ��������Ҫ�Ĺ���(��������0-8):");
}

void order()/*�Զ���ɼ����� */ 
{ FILE *fp;
  struct student t;
  int i=0,j=0,m=0;
  if((fp=fopen("score.dat","r+"))==NULL)
     { 
	printf("can not open!\n");
        return;
  }
  while(!feof(fp)) 
  if(fread(&stu[m] ,LEN,1,fp)==1) 
	  m++;
  fclose(fp);
  if(m==0) 
  {
	  printf("error!\n");
	  return;
  }
  if((fp=fopen("score.dat","wb"))==NULL)
     {
	  printf("can not open\n");
	  return;}
  for(i=0;i<m-1;i++)
      for(j=i+1;j<m;j++)//���á�ð�����򷨡��Գɼ����� 
          if(stu[i].sum<stu[j].sum)
          { t=stu[i];stu[i]=stu[j];stu[j]=t;}
	  if((fp=fopen("score.dat","wb"))==NULL)
     { printf("can not open\n");return;}
  for(i=0;i<m;i++)/*�������ź������������д��ָ���Ĵ����ļ���*/
      if(fwrite(&stu[i] ,LEN,1,fp)!=1)
       { 
        printf("%s can not save!\n"); 
        getch();
      }
  fclose(fp);
  printf("����ɹ�\n");
}


void del()/*�Զ���ɾ������*/
{
	system("cls");
	FILE *fp;
	int snum,i,j,m=0;
	char ch[2];
	if((fp=fopen("score.dat","r+"))==NULL)
	{
		printf("can not open\n");return;}
		while( !feof(fp) )  
			if(fread(&stu[m],LEN,1,fp)==1) m++;
			fclose(fp);
		if(m==0) 
		{
			printf("no record!\n");
			return;
		}
  show();
		printf("please input the number:");
		scanf("%d",&snum);

		for(i=0;i<m;i++)
		{
			if(snum==stu[i].num)
			{    
				printf("find the student,delete?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ����ɾ��*/
				for(j=i;j<m;j++)
				stu[j]=stu[j+1];/*����һ����¼�Ƶ�ǰһ����¼��λ��*/
				m--;/*��¼���ܸ�����1*/
				if((fp=fopen("score.dat","wb"))==NULL)
				{ printf("can not open\n");return;}
				for(j=0;j<m;j++)/*�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���*/
				if(fwrite(&stu[j] ,LEN,1,fp)!=1)
				{ printf("can not save!\n");
				getch();}
				fclose(fp);
				printf("ɾ���ɹ�!\n");
				return;
			}
		}
		printf("û���ҵ�Ҫɾ������Ϣ��\n");
}



void search()/*�Զ�����Һ���*/
{ FILE *fp;
  int snum,i,m=0;
  char ch[2];
  if((fp=fopen("score.dat","rb"))==NULL)
     { printf("can not open\n");return;}
  while(!feof(fp))  if(fread(&stu[m],LEN,1,fp)==1) m++;
  fclose(fp);
  if(m==0) {printf("error!\n");return;}
  printf("������ѧ��:");
  scanf("%d",&snum);
  for(i=0;i<m;i++)
     if(snum==stu[i].num)/*���������ѧ���Ƿ��ڼ�¼��*/
     { printf("���ҵ�Ŀ�꣬�Ƿ�չʾ��(y/n)");
     scanf("%s",ch);
      if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
        {
          printf("ѧ��       ����       ѡ�޿�       ʵ���     ���޿�     �ܷ�\t\n");
          printf(FORMAT,DATA);/*�����ҳ��Ľ����ָ����ʽ���*/
	  break;
     }
     }   
  if(i==m) printf("������!\n");/*δ�ҵ�Ҫ���ҵ���Ϣ*/
}



void modify()/*�Զ����޸ĺ���*/
{ FILE *fp;
  int i,j,m=0,snum;
  if((fp=fopen("score.dat","r+"))==NULL)
     { printf("can not open\n");return;}
  while(!feof(fp))  
 if(fread(&stu[m],LEN,1,fp)==1) m++;
  if(m==0) 
  {
	printf("no record!\n");
	fclose(fp);
	return;
  }
  show();
  printf("��������Ҫ�޸ĵ�ѧ����Ϣ��ѧ��!\n");
  printf("ѧ��:");
  scanf("%d",&snum);
  for(i=0;i<m;i++)
  {
	if(snum==stu[i].num)/*������¼���Ƿ���Ҫ�޸ĵ���Ϣ*/
	{
	  printf("���ҵ�Ŀ�꣬��ʼ�޸�!\n");
	 
	  printf("����:");
	  scanf("%s",stu[i].name);/*��������*/
          printf("ѡ�޿�:");
	  scanf("%lf",&stu[i].elec);/*����ѡ�޿γɼ�*/
          printf("ʵ���:");
	  scanf("%lf",&stu[i].expe);/*����ʵ��γɼ�*/
          printf("���޿�:");
	  scanf("%lf",&stu[i].requ);/*������޿γɼ�*/
	  printf("�޸ĳɹ�!");
	  
		stu[i].sum=stu[i].elec+stu[i].expe+stu[i].requ;
	  if((fp=fopen("score.dat","wb"))==NULL)
     { printf("can not open\n");return;}
	  for(j=0;j<m;j++)/*�����޸ĵ���Ϣд��ָ���Ĵ����ļ���*/
	  if(fwrite(&stu[j] ,LEN,1,fp)!=1)
       { printf("can not save!"); getch(); }
	fclose(fp);
	return ;
	}	 
  }
	printf("û���ҵ�ƥ����Ϣ��\n");
 }




void insert()/*�Զ�����뺯��*/
{ FILE *fp;
  int i,j,k,m=0,snum;
  if((fp=fopen("score.dat","r+"))==NULL)
     { printf("can not open\n");return;}
  while(!feof(fp))  
 if(fread(&stu[m],LEN,1,fp)==1) m++;
  if(m==0) {printf("no record!\n");
  fclose(fp);
  return;
  }
  printf("�������������λ��\n");
  scanf("%d",&snum);/*����Ҫ�����λ��*/
  for(i=0;i<m;i++)
	  if(snum==stu[i].num)
		  break;
	  for(j=m-1;j>i;j--)
           stu[j+1]=stu[j];/*�����һ����¼��ʼ�������һλ*/
	  printf("���ڣ��������µ���Ϣ\n");
          printf("ѧ��:");
	  scanf("%d",&stu[i+1].num);
	  for(k=0;k<m;k++)
	    if(stu[k].num==stu[m].num)
	    {
	    printf("�Ѵ���!");
	    getch();
	    fclose(fp);
	    return;
	    }
	  printf("����:");
	  scanf("%s",stu[i+1].name);
          printf("ѡ�޿�:");
	  scanf("%lf",&stu[i+1].elec);
          printf("ʵ���:");
	  scanf("%lf",&stu[i+1].expe);
          printf("���޿�:");
	  scanf("%lf",&stu[i+1].requ);
	  stu[i+1].sum=stu[i+1].elec+stu[i+1].expe+stu[i+1].requ;
	  if((fp=fopen("score.dat","wb"))==NULL)
     { printf("can not open\n");return;}
	  for(k=0;k<=m;k++)
	  if(fwrite(&stu[k] ,LEN,1,fp)!=1)/*���޸ĺ�ļ�¼д������ļ���*/
       { printf("can not save!"); getch(); }
  fclose(fp);
 }




void total()
{ 
  FILE *fp;
  int m=0;
  if((fp=fopen("score.dat","r+"))==NULL)
     { 
	 printf("can not open\n");
	 return;
	 } 
  while(!feof(fp))  
	  if(fread(&stu[m],LEN,1,fp)==1) 
		  m++;/*ͳ�Ƽ�¼������ѧ������*/
  if(m==0) 
  {
  printf("no record!\n");
  fclose(fp);
  return;
  }
  printf("һ���� %d ��ѧ��!\n",m);/*��ͳ�Ƶĸ������*/
  fclose(fp);
 }
 



 
int main()/*������*/
{
    log();
    int n;
	scanf("%d",&n);/*����ѡ���ܵı��*/
						while(n)
						{ 
						    switch(n)
							{ case 1: input();break;
                              case 2: search();break;
                              case 3: del();break;
                              case 4: modify();break;
                              case 5: insert();break;
                              case 6: order();break;
                              case 7: total();break;
	                          case 8: show();break;
                              default:break;
							}
							  getch();
							  menu();/*ִ���깦���ٴ���ʾ�˵�����*/
							   scanf("%d",&n);
						}
    return 0;
}
