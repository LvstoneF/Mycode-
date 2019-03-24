代码1：抽象数据类型顺序表的表示和实现(SqList.cpp)

//库函数头文件包含
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define  NULL       0    //代表空指针
typedef int  Status;


//顺序表的存储结构定义
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType;  //假设线性表中的元素均为整型
typedef struct{
	ElemType* elem;   //存储空间基地址
	int length;       //表中元素的个数
	int listsize;     //表容量大小	
}SqList;    //顺序表类型定义



//顺序表基本操作的实现

//结构初始化与销毁操作
Status InitList_Sq(SqList &L){
  //初始化L为一个空的有序顺序表
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)exit(OVERFLOW);
	L.listsize=LIST_INIT_SIZE;
	L.length=0;
	return OK;
}
Status DestroyList_Sq(SqList &L){
  //销毁有序顺序表L
	free(L.elem);
	L.elem=NULL;
	L.length=0;
	L.listsize=0;
	return OK;
}


//加工型操作
Status ClearList_Sq(SqList &L){
	//顺序表置空
	L.length=0;
	return OK;
}

Status ListInsert_Sq(SqList &L,int i, ElemType e){
//在顺序表L的第i个位置前插入元素e,i的合法值为..L.length+1
  if(i<1||i>L.length+1) return ERROR;   //插入位置不合法
  if(L.length>=L.listsize){               //表满，增加存储容量
	  ElemType *newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
	  if(!newbase) exit(OVERFLOW);
	  L.elem=newbase; L.listsize+=LISTINCREMENT;
  }
  ElemType *q=&L.elem[i-1],*p=&L.elem[L.length-1];
  while(p>=q){*(p+1)=*p;--p;}  //插入位置后的元素右移
  *q=e; 
  ++L.length; //表长加
  return OK;
}//ListInsert_Sq

Status ListDelete_Sq(SqList &L,int i,ElemType &e){
	//删除L中第i个元素并用e带回，i介于与表长之间
	if(i<1||i>L.length)return ERROR;
	e=L.elem[i-1];
	ElemType *p=L.elem+i-1,*q=L.elem+L.length-1;
	while(p<q){*p=*(p+1);++p;}
	--L.length;
	return OK;
}

Status SetElem_Sq(SqList &L,int i,ElemType e){
	//更新第i个元素结点的值为e，若i不合法则返回ERROR
	if(i<1||i>L.length)return ERROR;
	L.elem[i-1]=e;
	return OK;
}


//引用型操作
Status ListEmpty_Sq(SqList L){
	//判表空
	if(L.length)return TRUE;
	return FALSE;
}
int ListLength_Sq(SqList L){
	//求表长
	return(L.length);
}
Status GetElem_Sq(SqList L,int i,ElemType &e){
	//用e带回L中第i个元素的值并返回OK,i介于与L.length之间，否则返回ERROR
	if(i>=1&&i<=L.length){e=L.elem[i-1];return OK;}//注意位序与下标的关系
	else return ERROR;
}

//如下函数用于元素定位时大小的比较
Status SmallEqual(ElemType e1,ElemType e2){
	if(e1<=e2)     
		return TRUE;
	else
		return FALSE;
}

Status Equal(ElemType e1,ElemType e2){
	if(e1==e2) return TRUE;
	else return FALSE;
}

Status BigEqual(ElemType e1,ElemType e2){
	if(e1>=e2)return TRUE;
	else return FALSE;
}

int LocateElem_Sq(SqList L,ElemType e,Status (*cmp)(ElemType,ElemType)){
	//返回L中第一个与元素e满足关系cmp()的元素的位序，若不存在则返回	
	ElemType *p=L.elem;
	int i=1;
	while(i<=L.length&&!cmp(e,*p++))++i;
	if(i<=L.length)return i;
	else return 0;
}
Status PriorElem_Sq(SqList L,ElemType cur_e,ElemType &pre_e){
	int i=LocateElem_Sq(L,cur_e,Equal);
	if(!i||i==1)return ERROR;
	pre_e=L.elem[i-2];
	return OK;
}
Status NextElem_Sq(SqList L,ElemType cur_e,ElemType &next_e){
	int i=LocateElem_Sq(L,cur_e,Equal);
	if(!i||i==L.length)return ERROR;
	next_e=L.elem[i];
	return OK;
}	

Status PrintList_Sq(SqList L){
  //依次输出有序顺序表L中的各个元素
	ElemType *p,*q;
	if(!L.length){	printf("空表\n\n");return OK;	}
	else{
		p=L.elem;q=L.elem+L.length-1;
		printf("共%d个元素\n",L.length);
		while(p<=q){printf("--%d--",*p);++p;}
		printf("\n\n");
		return OK;
	}
}

//测试用程序
/*

void main(){
	SqList L;
	InitList_Sq(L);
    PrintList_Sq(L);
	if(ListEmpty_Sq(L))printf("NULL");

	ElemType e1=5,e2=3,e3=6;
	ListInsert_Sq(L,1,e1);
	PrintList_Sq(L);
	if(ListEmpty_Sq(L))printf("NULL");
	ListInsert_Sq(L,2,e2);
	PrintList_Sq(L);
	ListInsert_Sq(L,3,e3);
	PrintList_Sq(L);
	ListInsert_Sq(L,2,e1);
	PrintList_Sq(L);
	GetElem_Sq(L,1,e1);
	printf("%d\n",e1);
	printf("%d\n",LocateElem_Sq(L,e1,Equal));

	if(NextElem_Sq(L,e1,e1))printf("%d\n",e1);
	if(!PriorElem_Sq(L,e1,e1))printf("OVER\n");

	printf("%d\n",e1);
	ListDelete_Sq(L,1,e2);
	printf("%d\n",e2);
	PrintList_Sq(L);
	ListDelete_Sq(L,2,e2);
	printf("%d\n",e2);
	PrintList_Sq(L);
	printf("%d\n",LocateElem_Sq(L,4,SmallEqual));

	ClearList_Sq(L);
	PrintList_Sq(L);
	DestroyList_Sq(L);
}*/

代码2：抽象数据类型有序顺序表的表示和实现
(SortedSqList.cpp)

//库函数头文件包含
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//--------------文件SqList.cpp中含有顺序表的类型定义及基本操作的函数说明和具体实现，本程序在顺序表的基础上通过顺序表的定义和基本操作实现有序顺序表的类型定义和操作，故将其包含进来
#include"Sqlist.cpp"   



//--------------有序顺序表的类型定义与基本操作的函数原型声明-----------------------------------------------------------------
typedef SqList SortedSqList;//有序表类型定义

//有序顺序表操作的函数原型说明
int LocateElem_SortedSq(SqList L, ElemType e,Status (*cmp)(ElemType,ElemType));
	//在顺序表L中查找第一个满足cmp(e,x)的元素x的位序,找不到则返回，当cmp为SmallEqual时用于定位第一个满足SmallEqual(e,x)的元素x，即定位第一个“大于等于”e的x；
    //当cmp为BigEqual时定位第一个满足BigEqual(e,x)的元素x，即第一个“小于等于”e的元素x；   cmp为Equal时定位第一个等于e的元素x。务必注意对应关系
Status ListInsert_SortedSq(SortedSqList &L,ElemType e,Status (*cmp)(ElemType,ElemType));
    //在有序顺序表L中插入元素e,使得L中各元素仍然按cmp序排列,当cmp为SmallEqual时为升序,即将e插入到第第一个大于或等于e的元素之前，当cmp为BigEqual时为降序,将e插入到第一个小于等于e的元素前
int ListDelete_SortedSq(SqList &L,ElemType e,Status (*cmp)(ElemType,ElemType));
	//在有序表中删除“所有”满足cmp(e,x)的元素x,返回删除的元素个数。
	//当cmp为SmallEqual时删除所有满足SmallEqual(e,x)的元素x，即所有“大于等于e”的元素x；
	//当cmp为BigEqual时删除所有满足BigEqual(e,x)的元素x，即所有“小于等于e”的元素x；当cmp为Equal时删除所有与e相等的元素x
Status ListMerge_SortedSq(SortedSqList La,SortedSqList Lb,SortedSqList &Lc);
   //将有序顺序表La与Lb合并为有序顺序表Lc，原表La与Lb保持不变

Status SmallEqual(ElemType e1, ElemType e2);
  //若元素e1<=e2则返回TRUE，否则返回FAlSE
Status BigEqual(ElemType e1, ElemType e2);
////若元素e1>=e2则返回TRUE，否则返回FAlSE
Status Equal(ElemType e1, ElemType e2);
////若元素e1==e2则返回TRUE，否则返回FAlSE

			
//---------------有序顺序表中各操作的函数实现------------------------------------------------------------------------------------

Status SmallEqual(ElemType e1,ElemType e2){
	if(e1<=e2)     
		return TRUE;
	else
		return FALSE;
}

Status Equal(ElemType e1,ElemType e2){
	if(e1==e2) return TRUE;
	else return FALSE;
}

Status BigEqual(ElemType e1,ElemType e2){
	if(e1>=e2)return TRUE;
	else return FALSE;
}

int LocateElem_SortedSq(SqList L, ElemType e,Status (*cmp)(ElemType,ElemType)){
    //在顺序表L中查找第一个满足cmp(e,x)的元素x的位序,找不到则返回，当cmp为SmallEqual时用于定位第一个满足SmallEqual(e,x)的元素x，即定位第一个“大于等于”e的x；
    //当cmp为BigEqual时定位第一个满足BigEqual(e,x)的元素x，即第一个“小于等于”e的元素x；   cmp为Equal时定位第一个等于e的元素x。务必注意对应关系
	ElemType *p=L.elem;//p指向第一个元素
    int i=1;     //i始终为p所指向元素的位序
    while(i<=L.length&&!(*cmp)(e,*p++))++i;
	if(i>L.length)return 0;
	return i;
}//LocateElem_Sq


Status ListInsert_SortedSq(SortedSqList &L,ElemType e,Status (*cmp)(ElemType,ElemType)){
  //在有序顺序表L中插入元素e,使得L中各元素仍然按cmp序排列,当cmp为SmallEqual时为升序,即将e插入到第第一个大于或等于e的元素之前，当cmp为BigEqual时为降序,将e插入到第一个小于等于e的元素前
	int i=LocateElem_SortedSq(L,e,(*cmp));  //定位e的插入位置，应插入到第i个元素前
	if(i)ListInsert_Sq(L,i,e);   //若找到合适的i则在线性表L的第i个位置前插入元素e
	else ListInsert_Sq(L,L.length+1,e);  //若未找到合适的i则在表尾插入元素e
	return OK;
}

int ListDelete_SortedSq(SqList &L,ElemType e,Status (*cmp)(ElemType,ElemType)){
	//在有序表中删除“所有”满足cmp(e,x)的元素x,返回删除的元素个数。
	//当cmp为SmallEqual时删除所有满足SmallEqual(e,x)的元素x，即所有“大于等于e”的元素x；
	//当cmp为BigEqual时删除所有满足BigEqual(e,x)的元素x，即所有“小于等于e”的元素x；当cmp为Equal时删除所有与e相等的元素x
	int i,count=0;ElemType r;
	while(i=LocateElem_SortedSq(L,e,(*cmp))){   //逐个定位满足cmp(e,x)的元素x，找不到时i为，停止循环
		ListDelete_Sq(L,i,r);
		++count;
	}
	printf("共%d个元素被删除！",count);
	return count;

}

Status ListMerge_SortedSq(SortedSqList La,SortedSqList Lb,SortedSqList &Lc){
	//将两个有序顺序表La与Lb归并为有序顺序表Lc，原La与Lb保持不变
	int la_len=ListLength_Sq(La),lb_len=ListLength_Sq(Lb);
	int i=1,j=1,k=0;
	ElemType ai,bj;
	InitList_Sq(Lc);
	while(i<=la_len&&j<=lb_len){  //归并
     GetElem_Sq(La,i,ai);GetElem_Sq(Lb,j,bj); 
     if(ai<bj){ListInsert_Sq(Lc,++k,ai);++i;}
     else{ ListInsert_Sq(Lc,++k,bj); ++j;}
  }
 while(i<=la_len)   //插入La的剩余元素
  {GetElem_Sq(La,i++,ai); ListInsert_Sq(Lc,++k,ai);}
 while(j<=lb_len) //插入Lb的剩余元素
  {GetElem_Sq(Lb,j++,bj); ListInsert_Sq(Lc,++k,bj);}
 return OK;
}




//----------------------------主函数主要用以验证前述操作实现的正确性，注意测试数据要选择合理--------------------------------------------------------------------------
void main(){

	SortedSqList La,Lb,Lc;
	InitList_Sq(La);
    PrintList_Sq(La);

	//以下初始化La，依次向其插入元素,3,6,3，如此则既有在表头、表尾的插入操作，也有在表中间的插入，还有插入元素相等情况的出现，只要这几种情况都正确则说明插入操作正确
	ElemType e1=5,e2=3,e3=6;
	ListInsert_SortedSq(La,e1,SmallEqual);
	PrintList_Sq(La);
	ListInsert_SortedSq(La,e2,SmallEqual);
	PrintList_Sq(La);
	ListInsert_SortedSq(La,e3,SmallEqual);
	PrintList_Sq(La);	
	ListInsert_SortedSq(La,e2,SmallEqual);
	PrintList_Sq(La);

	//以下初始化Lb，并向其中插入元素,4,0,3；将来将La与Lb合并为Lc用以验证合并操作的正确性，注意Lb中的数据比La中元素小的、大的、相等的都有，如此方能验证合并操作的正确性
	InitList_Sq(Lb);
	ListInsert_SortedSq(Lb,8,SmallEqual);
	PrintList_Sq(Lb);
	ListInsert_SortedSq(Lb,4,SmallEqual);
	PrintList_Sq(Lb);
	ListInsert_SortedSq(Lb,0,SmallEqual);
	PrintList_Sq(Lb);
	ListInsert_SortedSq(Lb,3,SmallEqual);
	PrintList_Sq(Lb);

    //以下合并La与Lb为有序顺序表Lc
	ListMerge_SortedSq(La,Lb,Lc);
	PrintList_Sq(Lc);

	//以下从Lc中删除若干数据，既删除与指定值e相等的元素，也删除与指定值e满足SmallEqual(e,x)即“大于等于”e的元素x，还删除与指定值e满足BigEqual(e,x)即“小于等于e”的元素x，删除的元素在表头、表尾、表中间及不存在表中的元素均有，都正确方能保证删除操作的正确性
	ListDelete_SortedSq(Lc,5,Equal);
	PrintList_Sq(Lc);
	ListDelete_SortedSq(Lc,3,BigEqual);//删除所有满足BigEqual(3,x)即小于等于的元素x
	PrintList_Sq(Lc);
	ListDelete_SortedSq(Lc,8,SmallEqual);//删除所有满足SmallEqual(8,x)即大于等于的元素x
	PrintList_Sq(Lc);
	ListDelete_SortedSq(Lc,-1,Equal);//删除与-1相等的元素，实际不存在
	PrintList_Sq(Lc);


	DestroyList_Sq(La);
	DestroyList_Sq(Lb);
	DestroyList_Sq(Lc);

}
