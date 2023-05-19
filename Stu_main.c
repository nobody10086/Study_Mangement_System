#include "grade.h"
#include "functions.h"
#include "globals.h"
#include "Stu_add.c"
#include "Stu_del.c"
#include "Stu_search.c"
#include "Stu_noPass.c"
#include "Stu_sort.c"
#include <stdio.h>
#include <stdlib.h>


/*��̬�Ľṹ���������洢ѧ������*/
const char *filename = "students.dat";
struct grade *students = NULL;
int numStudents = 0;


/*����Ҫ����ӡ�ɾ��ѧ����¼���Լ��ڳ����˳�ǰ����ѧ����¼д�뵽һ���ļ��С�*/
void saveDataToFile() {
	FILE *file = fopen(filename, "wb");
	if (file != NULL) {
		fwrite(&numStudents, sizeof(numStudents), 1, file);
		fwrite(students, sizeof(struct grade), numStudents, file);
		fclose(file);
	} else {
		printf("Failed to open file for writing\n");
	}
}

void loadDataFromFile() {
	FILE *file = fopen(filename, "rb");
	if (file != NULL) {
		fread(&numStudents, sizeof(numStudents), 1, file);
		students = malloc(numStudents * sizeof(struct grade));
		fread(students, sizeof(struct grade), numStudents, file);
		fclose(file);
	} else {
		printf("No existing data found\n");
	}
}

void returnMenuOrExit() {
	int subChoice;
	printf("\nSub-Menu:\n1. Return to Main Menu\n2. Exit\nEnter your choice: ");
	scanf("%d", &subChoice);

	switch (subChoice) {
		case 1:
			main();  // �������˵�
			break;
		case 2:
			saveDataToFile();  // ��������Ȼ���˳�
			printf("Data saved. Exiting program.\n");
			exit(0);
		default:
			printf("Invalid choice\n");
	}
}



/*���˵�*/
int main() {
	int choice;

	while (1) {
		printf("\nMenu:\n1. ���ѧ��\n2. ɾ��ѧ��\n3. ��ѯѧ��\n4. ����\n5. ��ʾ��Ҫ������ѧ��\n6. �˳�\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				addCard();
				returnMenuOrExit();
				break;
			case 2:
				delCard();
				returnMenuOrExit();
				break;
			case 3:
				displayCard();
				returnMenuOrExit();
				break;
			case 4:
				sortCard();
				returnMenuOrExit();
				break;
			case 5:
				noPass();
				returnMenuOrExit();
				break;
			case 6: {
				returnMenuOrExit();
				break;
			}

			default:
				printf("Invalid choice\n");
		}
	}

	return 0;
}

