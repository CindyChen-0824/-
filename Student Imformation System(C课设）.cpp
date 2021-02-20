#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define LEN sizeof(struct student)
#define FORMAT "%-12d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].sum


struct student//学生成绩信息结构体 
{ int num;//学号
  char name[15];//姓名
  double elec;//选修课
  double expe;//实验课
  double requ;//必修课
  double sum;//总分
};


struct student stu[50];/*定义结构体数组*/
void log();/*密码登陆*/
void input();/*录入学生成绩信息*/
void show();/*显示学生信息*/
void order();/*按总分排序*/
void del();/*删除学生成绩信息*/
void modify();/*修改学生成绩信息*/
void menu();/*菜单*/
void insert();/*插入学生信息*/ 
void total();/*统计总人数*/
void search();/*查找学生信息*/


void log()/*密码登陆*/
{  
	int i; 
    char password[20]={0};
		printf("请输入密码:\n");
	for(i=0;i<3;i++)
	{
		scanf("%s",password);
			if(i<2)
			{
				if(strcmp("GXU19282018",password)!=0)
				{
					do
					{
						printf("密码错误，再次输入:\n");
					}while(strcmp("GXU19282018",password)==0);
				}
				else
					if(strcmp("GXU19282018",password)==0)
					{
						printf("欢迎使用学生成绩管理系统!\n");
						printf("\n\n");		
						menu(); break;/*进入菜单*/		
				    }
			}
			if(i==2)
			printf("NULLNULLNULL\n");	
	}
}
  
void input()/*录入学生信息*/
{ int i,m=0;/*m是记录的条数*/
  char ch[2];  
  FILE *fp;/*定义文件指针*/
  if((fp=fopen("score.dat","a+"))==NULL)/*打开指定文件*/
  { 
	  printf("can not open\n");
	  return;
  }
  while(!feof(fp))
  {
	  if(fread(&stu[m] ,LEN,1,fp)==1)
		  m++;/*统计当前记录条数*/
  }
  fclose(fp);
  if(m==0)
	  printf("No record!\n");
  else
  {
	  system("cls");
          show();/*调用show函数，显示原有信息*/
  }

  if((fp=fopen("score.dat","wb"))==NULL)
  {
	  printf("can not open\n");
	  return;
  }
  for(i=0;i<m;i++)
  {
   fwrite(&stu[i] ,LEN,1,fp);/*向指定的磁盘文件写入信息*/
  }
    system("cls");
    printf("please input(1/0)(1为继续、0为结束录入)):");
  scanf("%s",ch);
while(strcmp(ch,"1")==0||strcmp(ch,"1")==0)/*判断是否要录入新信息*/
	{
    printf("学号:");
	scanf("%d",&stu[m].num);/*输入学生学号*/
   for(i=0;i<m;i++)
	    if(stu[i].num==stu[m].num)
	    {
	    printf("该信息已经存在!");
	    getch();
	    fclose(fp);
	    return;
	    }
	
     printf("姓名:");
	 scanf("%s",stu[m].name);/*输入学生姓名*/

     printf("选修课:");

     scanf("%lf",&stu[m].elec);/*输入选修课成绩*/
     printf("实验课:");
	 scanf("%lf",&stu[m].expe);/*输入实验课成绩*/
     printf("必修课:");
	 scanf("%lf",&stu[m].requ);/*输入必修课成绩*/
     stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ;/*计算出总成绩*/
     if(fwrite(&stu[m],LEN,1,fp)!=1)/*将新录入的信息写入指定的磁盘文件*/
     {
		 printf("can not save!");
		 getch();
	 }
     else
	 {
		 printf("%s 同学的信息成功保存!\n",stu[m].name);
		 m++;
	 }
     printf("继续当前操作?(1/0)(1为继续、0为退出):");/*询问是否继续*/
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
   printf("学号       姓名       选修课      实验课      必修课      总分\t\n");
   for(i=0;i<m;i++)
       { 
	   printf(FORMAT,DATA);/*将信息按指定格式打印*/
       }
     }
 
void menu()/*自定义函数实现菜单功能*/
{
  system("cls");
  printf("\n\n\n\n\n");
  printf("\t\t|----------------------------STUDENT------------------------|\n");
  printf("\t\t|\t 0. 退出系统 exit                                   |\n");
  printf("\t\t|\t 1. 录入学生成绩信息input record                    |\n");
  printf("\t\t|\t 2. 查询学生信息search record                       |\n");
  printf("\t\t|\t 3. 删除学生成绩信息delete record                   |\n");
  printf("\t\t|\t 4. 修改生成绩信息modify record                     |\n");
  printf("\t\t|\t 5. 插入记录生成绩信息insert record                 |\n");
  printf("\t\t|\t 6. 成绩排序order                                   |\n");
  printf("\t\t|\t 7. 统计录入总人数number                            |\n");
  printf("\t\t|\t 8. 打印成绩总表show                                |\n");
  printf("\t\t|-----------------------------------------------------------|\n\n");
  printf("\t\t\t请选择您所需要的功能(输入数字0-8):");
}

void order()/*自定义成绩排序 */ 
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
      for(j=i+1;j<m;j++)//利用“冒泡排序法”对成绩排序 
          if(stu[i].sum<stu[j].sum)
          { t=stu[i];stu[i]=stu[j];stu[j]=t;}
	  if((fp=fopen("score.dat","wb"))==NULL)
     { printf("can not open\n");return;}
  for(i=0;i<m;i++)/*将重新排好序的内容重新写入指定的磁盘文件中*/
      if(fwrite(&stu[i] ,LEN,1,fp)!=1)
       { 
        printf("%s can not save!\n"); 
        getch();
      }
  fclose(fp);
  printf("保存成功\n");
}


void del()/*自定义删除函数*/
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
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要进行删除*/
				for(j=i;j<m;j++)
				stu[j]=stu[j+1];/*将后一个记录移到前一个记录的位置*/
				m--;/*记录的总个数减1*/
				if((fp=fopen("score.dat","wb"))==NULL)
				{ printf("can not open\n");return;}
				for(j=0;j<m;j++)/*将更改后的记录重新写入指定的磁盘文件中*/
				if(fwrite(&stu[j] ,LEN,1,fp)!=1)
				{ printf("can not save!\n");
				getch();}
				fclose(fp);
				printf("删除成功!\n");
				return;
			}
		}
		printf("没有找到要删除的信息！\n");
}



void search()/*自定义查找函数*/
{ FILE *fp;
  int snum,i,m=0;
  char ch[2];
  if((fp=fopen("score.dat","rb"))==NULL)
     { printf("can not open\n");return;}
  while(!feof(fp))  if(fread(&stu[m],LEN,1,fp)==1) m++;
  fclose(fp);
  if(m==0) {printf("error!\n");return;}
  printf("请输入学号:");
  scanf("%d",&snum);
  for(i=0;i<m;i++)
     if(snum==stu[i].num)/*查找输入的学号是否在记录中*/
     { printf("已找到目标，是否展示？(y/n)");
     scanf("%s",ch);
      if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0) 
        {
          printf("学号       姓名       选修课       实验课     必修课     总分\t\n");
          printf(FORMAT,DATA);/*将查找出的结果按指定格式输出*/
	  break;
     }
     }   
  if(i==m) printf("不存在!\n");/*未找到要查找的信息*/
}



void modify()/*自定义修改函数*/
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
  printf("请输入需要修改的学生信息的学号!\n");
  printf("学号:");
  scanf("%d",&snum);
  for(i=0;i<m;i++)
  {
	if(snum==stu[i].num)/*检索记录中是否有要修改的信息*/
	{
	  printf("已找到目标，开始修改!\n");
	 
	  printf("姓名:");
	  scanf("%s",stu[i].name);/*输入名字*/
          printf("选修课:");
	  scanf("%lf",&stu[i].elec);/*输入选修课成绩*/
          printf("实验课:");
	  scanf("%lf",&stu[i].expe);/*输入实验课成绩*/
          printf("必修课:");
	  scanf("%lf",&stu[i].requ);/*输入必修课成绩*/
	  printf("修改成功!");
	  
		stu[i].sum=stu[i].elec+stu[i].expe+stu[i].requ;
	  if((fp=fopen("score.dat","wb"))==NULL)
     { printf("can not open\n");return;}
	  for(j=0;j<m;j++)/*将新修改的信息写入指定的磁盘文件中*/
	  if(fwrite(&stu[j] ,LEN,1,fp)!=1)
       { printf("can not save!"); getch(); }
	fclose(fp);
	return ;
	}	 
  }
	printf("没有找到匹配信息！\n");
 }




void insert()/*自定义插入函数*/
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
  printf("请输入所需插入位置\n");
  scanf("%d",&snum);/*输入要插入的位置*/
  for(i=0;i<m;i++)
	  if(snum==stu[i].num)
		  break;
	  for(j=m-1;j>i;j--)
           stu[j+1]=stu[j];/*从最后一条记录开始均向后移一位*/
	  printf("现在，请输入新的信息\n");
          printf("学号:");
	  scanf("%d",&stu[i+1].num);
	  for(k=0;k<m;k++)
	    if(stu[k].num==stu[m].num)
	    {
	    printf("已存在!");
	    getch();
	    fclose(fp);
	    return;
	    }
	  printf("姓名:");
	  scanf("%s",stu[i+1].name);
          printf("选修课:");
	  scanf("%lf",&stu[i+1].elec);
          printf("实验课:");
	  scanf("%lf",&stu[i+1].expe);
          printf("必修课:");
	  scanf("%lf",&stu[i+1].requ);
	  stu[i+1].sum=stu[i+1].elec+stu[i+1].expe+stu[i+1].requ;
	  if((fp=fopen("score.dat","wb"))==NULL)
     { printf("can not open\n");return;}
	  for(k=0;k<=m;k++)
	  if(fwrite(&stu[k] ,LEN,1,fp)!=1)/*将修改后的记录写入磁盘文件中*/
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
		  m++;/*统计记录个数即学生个数*/
  if(m==0) 
  {
  printf("no record!\n");
  fclose(fp);
  return;
  }
  printf("一共有 %d 个学生!\n",m);/*将统计的个数输出*/
  fclose(fp);
 }
 



 
int main()/*主函数*/
{
    log();
    int n;
	scanf("%d",&n);/*输入选择功能的编号*/
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
							  menu();/*执行完功能再次显示菜单界面*/
							   scanf("%d",&n);
						}
    return 0;
}
