#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu() //功能表
    {
        printf("*****************欢迎来到学生管理系统!******************\n"
                " <1>添加学生数据    <2>修改学生数据    <3>删除学生信息\n"
                " <4>查询学生成绩    <5>学生成绩排名    <6>显示所有学生\n"
                " <7>刷新系统页面    <8>清空文件数据    <9>退出管理系统\n"
                "********************************************************\n");
    }


typedef struct student
{
    char stn[20];
    char name[50];
    char gender;
    int grade[3];
    struct student *next;
}stu;

stu * creat(stu *tar) //<1>添加学生数据
    {
        stu *head, *p1, *p2;
        //struct student *head, *p1, *p2;
        head = tar;
        if(head == NULL){//判断文件是否已有数据
            while(1){
                p1 = (stu *)malloc(sizeof(stu)); //分配内存空间 
                //p1 = (struct student *)malloc(sizeof(struct student));
                p1->next = NULL;
                //输入数据
                printf("\n请输入学号:");
                scanf("%s", p1->stn);
                getchar();
                printf("\n请输入名字:");
                gets(p1->name);
                printf("\n请输入性别(m/f):");
                scanf("%c", &p1->gender);
                printf("\n请输入语文,数学,外语成绩:");
                scanf("%d %d %d", &p1->grade[0], &p1->grade[1], &p1->grade[2]);
                if(head == NULL){
                    head = p1;
                    p2 = p1;
                }
                else{
                    p2->next = p1;
                    p2 = p1;
                }


                printf("\n是否继续输入(1/0):");
                int jd;
                scanf("%d", &jd);
                if(jd == 0){
                    
                    //p2->next = NULL;
                    break;
                    
                }            
            }
        }
        else{
            p2 = tar;
            while(p2->next != NULL){//指向结尾的结点
                p2 = p2->next;
            }
            while(1){
                p1 = (stu *)malloc(sizeof(stu)); //分配内存空间 
                p1->next = NULL;
                //p1 = (struct student *)malloc(sizeof(struct student));
                //输入数据
                printf("\n请输入学号:");
                scanf("%s", p1->stn);
                getchar();
                printf("\n请输入名字:");
                gets(p1->name);
                printf("\n请输入性别(m/f):");
                scanf("%c", &p1->gender);
                printf("\n请输入语文,数学,外语成绩:");
                scanf("%d %d %d", &p1->grade[0], &p1->grade[1], &p1->grade[2]);
                
                p2->next = p1;
                p2 = p1;
                
                printf("\n是否继续输入(1/0):");
                int jd;
                scanf("%d", &jd);
                if(jd == 0){
                    
                    //p2->next = NULL;
                    break;
                    
                }            
            }
        }

        /*test
        //stu *p = NULL;
        p = head;
        while(p != NULL){
            printf("%s\n", p->name);
            p = p->next;
        }
        */
        
        
        //printf("\n%p", head);
        return (head);
        //free(p1);
    }




void fix(stu *aim)//<2>修改学生数据
    {
        stu *p = NULL;
        p = aim;
        char inf[50] = {0};
        printf("\n请输入学生学号或姓名:");
        getchar();
        gets(inf);
        while(p != NULL){
            if(strcmp(p->name, inf) == 0 || strcmp(p->stn, inf) == 0){ //比对信息
                printf("\n*******请选择需要修改的部分********" //选择界面
                        "\n a.学号 b.姓名 c.性别 d.成绩 e.全部"
                        "\n请选择对应的数字编号"
                        "\n*********************************\n");
                printf("键入对应的字母编号选择对应功能:");
                    char n = 'e';
                    scanf("%c", &n);
                    switch (n)
                    {
                    case 'a': printf("\n将学号修改为:"); getchar(); gets(p->stn); break;
                    case 'b': printf("\n将姓名修改为:"); getchar(); gets(p->name); break;
                    case 'c': printf("\n将性别修改为:"); getchar(); scanf("%c", &p->gender); break;
                    case 'd': 
                            while(1){
                                printf("\n要修改哪门学科的成绩?1.语文 2.数学 3.外语 4.全部");
                                int x = 0;
                                scanf("%d", &x);
                                if(x == 4){
                                    printf("\n请输入新的语文,数学和外语成绩:"); 
                                    scanf("%d %d %d", &p->grade[0], &p->grade[1], &p->grade[2]);
                                    break;
                                }
                                else if(x == 1){
                                    printf("\n请输入新的语文成绩:");
                                    scanf("%d", &p->grade[0]);
                                    printf("\n是否继续修改成绩?(y/n)");
                                    getchar();
                                    if(getchar() == 'n'){
                                        break;
                                    }
                                }
                                else if(x == 2){
                                    printf("请输入新的数学成绩:");
                                    scanf("%d", &p->grade[1]);
                                    printf("\n是否继续修改成绩?(y/n)");
                                    getchar();
                                    if(getchar() == 'n'){
                                        break;
                                    }
                                }
                                else if(x == 3){
                                    printf("\n请输入新的外语成绩:");
                                    scanf("%d", &p->grade[2]);
                                    printf("\n是否继续修改成绩?(y/n)");
                                    getchar();
                                    if(getchar() == 'n'){
                                        break;
                                    }
                                }
                                //else printf("\n输入非法!请重新输入!");
                            }
                            break;
                    case 'e': 
                        printf("\n将学号修改为:"); getchar(); gets(p->stn);
                        printf("\n将姓名修改为:"); getchar(); gets(p->name);
                        printf("\n将性别修改为:"); getchar(); scanf("%c", &p->gender);
                        printf("\n要修改哪门学科的成绩?1.语文 2.数学 3.外语 4.全部");
                            while(1){
                                int x = 0;
                                scanf("%d", &x);
                                if(x == 4){
                                    printf("\n请输入新的语文,数学和外语成绩:"); 
                                    scanf("%d %d %d", &p->grade[0], &p->grade[1], &p->grade[2]);
                                    break;
                                }
                                else if(x == 1){
                                    printf("\n请输入新的语文成绩:");
                                    scanf("%d", &p->grade[0]);
                                    printf("\n是否需要继续修改成绩?(y/n)");
                                    getchar();
                                    if(getchar() == 'n'){
                                        break;
                                    }
                                }
                                else if(x == 2){
                                    printf("请输入新的数学成绩:");
                                    scanf("%d", &p->grade[1]);
                                    printf("\n是否继续修改成绩?(y/n)");
                                    getchar();
                                    if(getchar() == 'n'){
                                        break;
                                    }
                                }
                                else if(x == 3){
                                    printf("\n请输入新的外语成绩:");
                                    scanf("%d", &p->grade[2]);
                                    printf("\n是否继续修改成绩?(y/n)");
                                    getchar();
                                    if(getchar() == 'n'){
                                        break;
                                    }
                                }
                                //else printf("\n输入非法!请重新输入!");
                            }
                            break;//跳出switch
                    }
                    break;//跳出while循环
                }
            p = p->next;
        }
        
        /*test
        //stu *p = NULL;
        stu *new = NULL;
        new = aim;
        while(new != NULL){
            printf("%s\n", new->name);
            new = new->next;
        }
        */
    }



stu * delete(stu *aim) //<3>删除学生信息
    {

        stu *p = NULL, *p1 = NULL;
        p = aim;
        p1 = aim;
        printf("\n请输入要删除的学生学号或姓名:");
        char tar[50] = {0};
        getchar(); //消耗回车
        gets(tar);
        while(p != NULL){
            if(strcmp(p->name, tar) == 0 || strcmp(p->stn, tar) == 0){
                printf("\n确定要删除%s号%s的数据吗?(1/0)", p->stn, p->name);
                int cf;
                scanf("%d", &cf);
                    if(cf == 1){
                        if(p != p1){
                            p1->next = p->next; //链接删除节点的前节点和节点
                            free(p); //释放节点
                        }
                        else{
                            p = p->next;
                            free(p1);
                            p1 = NULL;
                            return p;
                        }
                    }
                break;
            }
            p1 = p;
            p = p->next;
        }

/*
        //test
        //stu *p = NULL;
        printf("\n////start test////\n");
        stu *new = NULL;
        new = aim;
        while(new != NULL){
            printf("%s %s\n", new->stn, new->name);
            new = new->next;
        }
*/        
    }





void search(stu *aim) //<4>查询学生成绩
    {
        stu *p = NULL;
        p = aim;
        printf("\n输入学生学号或姓名:");
        getchar();
        char tar[50] = {0};
        gets(tar);
        int cf = 0;
        while(p != NULL){
            if(strcmp(p->name, tar) == 0 || strcmp(p->stn, tar) == 0){
                cf = 1;
                break;
            }
            p = p->next;
        }
        if(cf == 1){
            printf("\n%s号%s的成绩为:语文:%d, 数学:%d, 外语:%d", p->stn, p->name,
            p->grade[0], p->grade[1], p->grade[2]);            
        }
        else{
            printf("\n无该生信息!");
        }
    }

typedef struct 
{
    char nm[50];
    int gd[3];
}sortstu;



void sort(stu *aim)//<5>学生成绩排名
    {
        int n = 0, n1 = 0, n2 = 0, n3 = 0;
        sortstu ss[500];
        stu *p =NULL;
        p = aim;
        while(p != NULL){
            strcpy(ss[n].nm, p->name);
            for(int i = 0; i < 3; ++i){
                ss[n].gd[i] = p->grade[i];
                }
            n++;
            p = p->next;
        }
        //int sum[500] = {0};
/*
        printf("\n//////start test///////");
        for(int i = 0; i < n; ++i){
            printf("\n%d", ss[i].gd[2]);
        }
*/
        printf("\n选择学科排名(a.语文, b.数学, c.外语, d.总成绩):");
        char cf;
        getchar();
        cf = getchar();
        switch (cf)
        {
            case 'a':
                for(int i = 0; i < n - 1; ++i){ //冒泡排序
                    for(int ii = 0; ii < n - 1 - i; ++ii){
                        if(ss[ii].gd[0] < ss[ii + 1].gd[0]){
                            //交换分数
                            int temp = ss[ii].gd[0];
                            ss[ii].gd[0] = ss[ii + 1].gd[0];
                            ss[ii + 1].gd[0] = temp;

                            //交换姓名
                            char t[50];
                            strcpy(t, ss[ii].nm);
                            strcpy(ss[ii].nm, ss[ii + 1].nm);
                            strcpy(ss[ii + 1].nm, t);
                        }
                    }
                }
                //打印排名
                for(int i = 0; i < n; ++i){
                    printf("\n%s分数:%d", ss[i].nm, ss[i].gd[0]);
                }
                break;
            case 'b':
                for(int i = 0; i < n - 1; ++i){ //冒泡排序
                    for(int ii = 0; ii < n - 1 - i; ++ii){
                        if(ss[ii].gd[1] < ss[ii + 1].gd[1]){
                            //交换分数
                            int temp = ss[ii].gd[1];
                            ss[ii].gd[1] = ss[ii + 1].gd[1];
                            ss[ii + 1].gd[1] = temp;

                            //交换姓名
                            char t[50];
                            strcpy(t, ss[ii].nm);
                            strcpy(ss[ii].nm, ss[ii + 1].nm);
                            strcpy(ss[ii + 1].nm, t);
                        }
                    }
                }
                //打印排名
                for(int i = 0; i < n; ++i){
                    printf("\n%s分数:%d", ss[i].nm, ss[i].gd[1]);
                }
                break;

            case 'c':
                for(int i = 0; i < n - 1; ++i){ //冒泡排序
                    for(int ii = 0; ii < n - 1 - i; ++ii){
                        if(ss[ii].gd[2] < ss[ii + 1].gd[2]){
                            //交换分数
                            int temp = ss[ii].gd[2];
                            ss[ii].gd[2] = ss[ii + 1].gd[2];
                            ss[ii + 1].gd[2] = temp;

                            //交换姓名
                            char t[50];
                            strcpy(t, ss[ii].nm);
                            strcpy(ss[ii].nm, ss[ii + 1].nm);
                            strcpy(ss[ii + 1].nm, t);
                        }
                    }
                }
                //打印排名
                for(int i = 0; i < n; ++i){
                    printf("\n%s分数:%d", ss[i].nm, ss[i].gd[2]);
                }
                break;

            case 'd':{
                int sum[500] = {0};
                for(int i = 0; i < n; ++i){
                    sum[i] = ss[i].gd[0] + ss[i].gd[1] + ss[i].gd[2];
                }
                for(int i = 0; i < n - 1; ++i){ //冒泡排序
                    for(int ii = 0; ii < n - 1 - i; ++ii){
                        if(sum[ii] < sum[ii + 1]){
                            //交换分数
                            int temp = sum[ii];
                            sum[ii] = sum[ii + 1];
                            sum[ii + 1] = temp;

                            //交换姓名
                            char t[50];
                            strcpy(t, ss[ii].nm);
                            strcpy(ss[ii].nm, ss[ii + 1].nm);
                            strcpy(ss[ii + 1].nm, t);
                        }
                    }
                }
                //打印排名
                for(int i = 0; i < n; ++i){
                    printf("\n%s分数:%d", ss[i].nm, sum[i]);
                }
                break;}
        }
    }




void display(stu *aim)//<6>显示所有学生
    {
        stu *p = NULL;
        p = aim;
        while(p != NULL){
            printf("\n%s号%s信息: ", p->stn, p->name);
            if(p->gender == 'm'){
                printf("性别: 男 ");
            }
            else if(p->gender == 'f'){
                printf("性别: 女 ");
            }
            printf("成绩: 语文: %d, 数学: %d, 外语: %d", 
            p->grade[0], p->grade[1], p->grade[2]);
            p = p->next;
        }
    }






void clr()//<7>刷新系统页面
    {
        system("CLS");
        menu();
    }





stu * read()
    {
        FILE *fp = NULL;
        fp = fopen("stu.txt", "r");
        stu *head = NULL, *tar = NULL, *s = NULL;
        while(1){
            if(EOF != fgetc(fp)){
                tar = (stu *)malloc(sizeof(stu));
                tar->next = NULL;
                fscanf(fp, "%7s %7s %7c %8d %7d %7d", 
                tar->stn, tar->name, &tar->gender,
                &tar->grade[0], &tar->grade[1], &tar->grade[2]);
                if(head == NULL){
                    head = tar;
                    s = tar;
                }
                else{
                    s->next = tar;
                    s = tar;
                }
            }
            else break;
        }
        //s->next = NULL;
        //tar->next = NULL;
        tar = NULL;
        s = NULL;
        fclose(fp);
        return(head);
        //free(tar); 
    }

void destory(stu * aim)
    {
        stu * p = NULL;
        while(aim != NULL){
            p = aim;
            aim = aim->next;
            free(p);
            p = NULL;
        }
    }





int main()
    {
        //system("color 9F");// 设置cmd背景为淡蓝色,字体为亮白色
        
        
        
        
        
        stu *aim = NULL;
        aim = read();
        menu();
        //printf("\n%d\n", choose()); test choose
        int num = 9;
        while(1){
        //menu();
        printf("\n键入对应的数字编号选择对应功能:");
        scanf("%d", &num);
        if(num == 9){
            //写入文件
            FILE *fp = NULL;
            fp = fopen("stu.txt", "w");
            stu *tar = NULL;
            tar = aim;
            while(tar != NULL){
                fprintf(fp, "%7s %7s %7c %8d %7d %7d", 
                tar->stn, tar->name, tar->gender,
                tar->grade[0], tar->grade[1], tar->grade[2]);
                if(tar->next != NULL){
                    fprintf(fp, "\n");
                }
                tar = tar->next;
            }
            fclose(fp);
            break;
        }
        
            switch (num) //选择功能
            {
            case 1: aim = creat(aim);/*getchar();/* printf("\n%p", aim)*/; break;
            case 2: fix(aim); /*getchar();*/ break;
            case 3: aim = delete(aim);/* getchar()*/; break;
            case 4: search(aim);/* getchar();*/ break;
            case 5: sort(aim);/* getchar();*/ break;
            case 6: display(aim);/* getchar();*/ break;
            case 7: clr(); /*getchar();*/ break;
            case 8: destory(aim); aim = NULL;/* getchar();*/break;
            default: /*getchar();*/ printf("\n无效输入!"); break;
            }
        }
        destory(aim);
        aim = NULL;
        return 0;
    }


