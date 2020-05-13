/* ���µ��㷨������Դ���ͷ���ĵ�����*/ 
Status ListInit_Link(LinkList &L) 
{ /* �������������һ���յ����Ա�L */ 
L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ���,��ʹL ָ���ͷ���*/ 
if(!L) /* �洢����ʧ��*/ 
exit(OVERFLOW); 
L->next=NULL; /* ָ����Ϊ��*/ 
return OK; 
}

Status ListDestroy_Link (LinkList L) 
{ /* ��ʼ���������Ա�L �Ѵ��ڡ�*/ 
/* ����������������Ա�L */ 
LinkList q; 
while(L) 
{ 
q=L->next; 
free(L); 
L=q; 
}
return OK; 
}

Status ListClear_Link (LinkList L) /* ���ı�L */ 
{ /* ��ʼ���������Ա�L �Ѵ��ڡ�*/ 
/* �����������L ����Ϊ�ձ�*/ 
LinkList p,q; 
p=L->next; /* p ָ���һ�����*/ 
while(p) /* û����β*/ 
{ 
q=p->next; 
free(p); 
p=q; 
}
L->next=NULL; /* ͷ���ָ����Ϊ��*/ 
return OK; 
}

Status ListEmpty_Link (LinkList L) 
{ /* ��ʼ���������Ա�L �Ѵ��ڡ�*/ 
/* �����������L Ϊ�ձ����򷵻�TRUE�����򷵻�FALSE */
if(L->next) /* �ǿ�*/ 
return FALSE; 
else
return TRUE; 
}

int ListLength_Link (LinkList L) 
{ /* ��ʼ���������Ա�L �Ѵ��ڡ�*/ 
/* �������������L ������Ԫ�ظ���*/ 
int i=0; 
LinkList p=L->next; /* p ָ���һ�����*/ 
while(p) /* û����β*/ 
{ 
i++; 
p=p->next; 
}
return i; 
}

Status GetElem_Link (LinkList L,int i,ElemType &e) /* �㷨2.8 */ 
{ /* ��ʼ����: L Ϊ��ͷ���ĵ�������ͷָ��*/ 
/* �������������i ��Ԫ�ش���ʱ,��ֵ����e ������OK,���򷵻�ERROR */ 
int j=1; /* j Ϊ������*/ 
LinkList p=L->next; /* p ָ���һ�����*/ 
while(p&&j<i) /* ˳ָ��������,ֱ��p ָ���i ��Ԫ�ػ�p Ϊ��*/ 
{ 
p=p->next; 
j++; 
}
if(!p||j>i) /* ��i ��Ԫ�ز�����*/ 
return ERROR;
e=p->data; /* ȡ��i ��Ԫ��*/ 
return OK; 
}

int LocateElem_Link (LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)) 
{ /* ��ʼ����: ���Ա�L �Ѵ���,compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0) */ 
/* �������: ����L �е�1 ����e �����ϵcompare()������Ԫ�ص�λ��*/ 
/* ������������Ԫ�ز�����,�򷵻�ֵΪ0 */ 
int i=0; 
LinkList p=L->next; 
while(p) 
{ 
i++; 
if(compare(p->data,e)) /* �ҵ�����������Ԫ��*/ 
return i; 
p=p->next; 
}
return 0; 
}

Status ListInsert_Link (LinkList L,int i,ElemType e) /* �㷨2.9,���ı�L */ 
{ /* �ڴ�ͷ���ĵ������Ա�L �е�i ��λ��֮ǰ����Ԫ��e */ 
int j=0; 
LinkList p=L,s; 
while(p&&j<i-1) /* Ѱ�ҵ�i-1 �����*/ 
{ 
p=p->next; 
j++; 
}
if(!p||j>i-1) /* i С��1 ���ߴ��ڱ���*/ 
return ERROR;
s=(LinkList)malloc(sizeof(struct LNode)); /* �����½��*/ 
s->data=e; /* ����L ��*/ 
s->next=p->next; 
p->next=s; 
return OK; 
}

Status ListDelete_Link (LinkList L,int i,ElemType &e) /* �㷨2.10,���ı�L */ 
{ /* �ڴ�ͷ���ĵ������Ա�L �У�ɾ����i ��Ԫ��,����e ������ֵ*/ 
int j=0; 
LinkList p=L,q; 
while(p->next&&j<i-1) /* Ѱ�ҵ�i �����,����p ָ����ǰ��*/ 
{ 
p=p->next; 
j++; 
}
if(!p->next||j>i-1) /* ɾ��λ�ò�����*/ 
return ERROR; 
q=p->next; /* ɾ�����ͷŽ��*/ 
p->next=q->next; 
e=q->data; 
free(q); 
return OK; 
}

Status ListTraverse_Link (LinkList L) 
{ /* ��ʼ���������Ա�L �Ѵ���*/ 
/* �������:���ζ�L ��ÿ������Ԫ�ص�ֵ�������*/ 
LinkList p=L->next; 
while(p) 
{
printf("%d",p->data); 
p=p->next; 
}
printf("\n"); 
return OK; 
} 

void CreateList_Link (LinkList &L,int n) /* �㷨2.11 */ 
{ /* ��λ��(���ڱ�ͷ)����n ��Ԫ�ص�ֵ����������ͷ�ṹ�ĵ������Ա�L */ 
int i; 
LinkList p; 
L=(LinkList)malloc(sizeof(struct LNode)); 
L->next=NULL; /* �Ƚ���һ����ͷ���ĵ�����*/ 
printf("������%d ������\n",n); 
for(i=n;i>0;--i) 
{ 
p=(LinkList)malloc(sizeof(struct LNode)); /* �����½��*/ 
scanf("%d",&p->data); /* ����Ԫ��ֵ*/ 
p->next=L->next; /* ���뵽��ͷ*/ 
L->next=p; 
} 
}

void CreateList2_Link (LinkList &L,int n) 
{ /* ��λ��(���ڱ�β)����n ��Ԫ�ص�ֵ����������ͷ�ṹ�ĵ������Ա�*/ 
int i; 
LinkList p,q; 
L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ���*/ 
L->next=NULL; 
q=L; 
printf("������%d ������\n",n); 
for(i=1;i<=n;i++)
{ 
p=(LinkList)malloc(sizeof(struct LNode)); 
scanf("%d",&p->data); 
q->next=p; 
q=q->next; 
}
p->next=NULL; 
} 

Status PriorElem_Link (LinkList L,ElemType cur_e,ElemType &pre_e) 
{ /* ��ʼ����: ���Ա�L �Ѵ���*/
/* �������: ��cur_e ��L ������Ԫ��,�Ҳ��ǵ�һ��,����pre_e ��������ǰ��, */
/* ����OK;�������ʧ��,pre_e �޶���,����INFEASIBLE */
LinkList q,p=L->next; /* p ָ���һ�����*/
while(p->next) /* p ��ָ����к��*/
{
q=p->next; /* q Ϊp �ĺ��*/
if(q->data==cur_e)
{
pre_e=p->data;
return OK;
}
p=q; /* p �����*/
}
return INFEASIBLE;
}


Status NextElem_Link (LinkList L,ElemType cur_e,ElemType &next_e) 
{ /* ��ʼ���������Ա�L �Ѵ���*/
/* �����������cur_e ��L ������Ԫ�أ��Ҳ������һ��������next_e �������ĺ�̣� */
/* ����OK;�������ʧ�ܣ�next_e �޶��壬����INFEASIBLE */
LinkList p=L->next; /* p ָ���һ�����*/
while(p->next) /* p ��ָ����к��*/
{
if(p->data==cur_e)
{ next_e=p->next->data;
return OK;
}
p=p->next;
}
return INFEASIBLE;
}


void MergeList_Link (LinkList &La,LinkList &Lb,LinkList &Lc) 
{ /* ��֪�������Ա�La ��Lb ��Ԫ�ذ�ֵ�ǵݼ����С�*/
/* �鲢La ��Lb �õ��µĵ������Ա�Lc��Lc ��Ԫ��Ҳ��ֵ�ǵݼ�����*/
LinkList pa=La->next,pb=Lb->next,pc;
Lc=pc=La; /* ��La ��ͷ�����ΪLc ��ͷ���*/
while(pa&&pb)
if(pa->data<=pb->data)
{
pc->next=pa;
pc=pa;
pa=pa->next;
}
else
{
pc->next=pb;
pc=pb;
pb=pb->next;
}
pc->next=pa?pa:pb; /* ����ʣ���*/	
//free(La);   /* �ͷ�La ��ͷ���*/
free(Lb); /* �ͷ�Lb ��ͷ���*/
Lb=NULL;
}

void Sort_Link (LinkList &La) 
{ /*��ʼ����: ���Ա�La �Ѵ���,La ��Ԫ���������С�*/
/* �����������La������Ԫ���������ɰ�ֵ�ǵݼ����е�����La*/
	int j;
	j=ListLength_Link(La);
	LinkList pa=La->next,pb=pa->next;
	for(int i=0;i<=j;i++)
		for(int k=0;k<j;k++)
		{
			if(pa->data <= pb->data)
			{
				int n;
				n=pa->data;
				pa->data=pb->data;
				pb->data=n;
			}
			pa=pa->next;
			pb=pb->next;
			while(!pa->next)
			{
				pa=La->next;
				pb=pa->next;
			}
		}
}