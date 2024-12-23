# include<stdio.h>
# include<string.h>
struct Student{
	int id;
	char fullName[100];
	int age;
	char phone[20];
};
void softArr(struct Student students[5],int n);
void printArr(struct Student students[5], int n);
int main(){
	struct Student students[5]={
		{1,"Nguyen van B",17,"0987654321"},
    	{2,"Nguyen van D",18,"0987654322"},
    	{3,"Nguyen van A",19,"0987654323"},
    	{4,"Nguyen van E",15,"0987654324"},
    	{5,"Nguyen van C",14,"0987654325"},
    };
    int n=5;
    int id;
    softArr(students,n);
    printArr(students,n);
    return 0;
}
void softArr(struct Student students[5],int n){
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
void printArr(struct Student students[5], int n){
	printf("in thong tin cac sinh vien sau khi xoa\n");
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
