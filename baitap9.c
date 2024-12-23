# include<stdio.h>
# include <string.h>
struct Student{
	int id;
	char fullName[100];
	int age;
	char phone[20];
};
struct Student students[100]={
	{1,"Nguyen van B",17,"0987654321"},
	{2,"Nguyen van D",18,"0987654322"},
	{3,"Nguyen van A",19,"0987654323"},
	{4,"Nguyen van E",15,"0987654324"},
	{5,"Nguyen van C",14,"0987654325"},
};
void menu();
void printArr(struct Student students[], int n);
void addStudent(int pos, struct Student students[], int *n);
void uploadStudent(int pos, struct Student students[], int *n);
void deleteStudent(int pos, struct Student students[], int *n);
void searchStudent(int id, struct Student students[],int *n);
void softStudent(struct Student students[],int n);

int main(){
	int choice;
	int n=5,pos,id;
	do{
		menu(choice);
		printf("nhap lua chon cua ban: ");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				printArr(students,n);
				break;
			case 2:
                addStudent(pos,students,&n);
				break;
			case 3:
				uploadStudent(pos,students,&n);
				break;
			case 4:
				deleteStudent(pos,students,&n);
				break;
			case 5:
				searchStudent(id,students,&n);
				break;
			case 6:
				softStudent(students,n);
				break;
			case 7:
				printf("Thoat");
				break;
	        default:
			    printf("lua chon khong hop le (moi nhap lai)");		
        }
	}while(choice!=7);
	return 0;
}				
void menu(int choice){
	printf("\nMenu\n");
	printf("1.Hien thi danh sach sinh vien\n");
	printf("2.Them sinh vien\n");
	printf("3.Sua thong tin sinh vien\n");
	printf("4.Xoa thong tin sinh vien\n");
	printf("5.Tim kiem sinh vien\n");
	printf("6.Sap xep danh sach sinh vien\n");
	printf("7.Thoat\n");
}
void printArr(struct Student students[5], int n){
	printf("thong tin cac sinh vien\n");
    printf("\n");
    int i;
	for(i=0;i<n;i++){
        printf("\n--thong tin sinh vien %d\n",i+1);
		printf("id sinh vien %d la: %d\n",i+1,students[i].id);
		printf("ho va ten sinh vien %d la:  %s\n",i+1,students[i].fullName);
	    printf("Tuoi sinh vien sinh vien %d la:  %d\n",i+1,students[i].age);
	    printf("so dien thoai sinh vien %d la: %s\n",i+1,students[i].phone);
    }   
}
void addStudent(int pos, struct Student students[], int *n){
	printf("them sinh vien vao vi tri: ");
    scanf("%d",&pos);
    struct Student newsudents;
    newsudents.id=*n+1;
	fflush(stdin);
    printf("nhap ten sinh vien moi: ");
    fgets(newsudents.fullName,sizeof(newsudents.fullName),stdin);
	newsudents.fullName[strcspn(newsudents.fullName,"\n")]='\0';
	printf("nhap tuoi sinh vien moi: ");
	scanf("%d",&newsudents.age);
	fflush(stdin);
    printf("nhap so dien thoai sinh vien moi: ");
    fgets(newsudents.phone,sizeof(newsudents.phone),stdin);
    newsudents.phone[strcspn(newsudents.phone,"\n")]='\0';
    int i;
	if(pos<0||pos>*n){
    	printf("ko hop le");
	}else{
		for(i=*n;i>pos;i--){
		    students[i]=students[i-1];
        }
        students[pos]=newsudents;
        (*n)++;
	}
}
void uploadStudent(int pos, struct Student students[], int *n){
    if(pos<0||pos>=*n){
    	printf("ko hop le");
	}
	fflush(stdin);
    printf("nhap ten sinh vien moi: ");
    fgets(students[pos].fullName,sizeof(students[pos].fullName),stdin);
	students[pos].fullName[strcspn(students[pos].fullName,"\n")]='\0';
	printf("nhap tuoi sinh vien moi: ");
	scanf("%d",&students[pos].age);
	fflush(stdin);
    printf("nhap so dien thoai sinh vien moi: ");
    fgets(students[pos].phone,sizeof(students[pos].phone),stdin);
   students[pos].phone[strcspn(students[pos].phone,"\n")]='\0';
}
void deleteStudent(int pos, struct Student students[], int *n){
	printf("xoa sinh vien o vi tri: ");
    scanf("%d",&pos);
	if(pos<0||pos>*n){
    	printf("ko hop le");
	}else{
		int i;
		for(i=pos;i<*n-1;i++){
		    students[i]=students[i+1];
        }
        (*n)--;
	}
}
void softStudent(struct Student students[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for (j=0;j<n-i-1;j++){
			if(strcmp(students[j+1].fullName,students[j].fullName)<0){
				struct Student temp = students[j];
			    students[j] =students[j+1];
			    students[j + 1]=temp;
			}
		}
	}
}
void searchStudent(int id, struct Student students[],int *n){
	printf("moi ban nhap id sinh vien can tim: ");
    scanf("%d",&id);
	int i,check=-1;
	for(i=0;i<*n;i++){
		if(students[i].id==id){
			check=i;
			break;
		}
	}
	if(check==-1){
		printf("khong ton tai");
	}else{
		printf("sinh vien ten la: %s",students[i].fullName);
    }
}


