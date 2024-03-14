#include <stdio.h>
#define SIZE 6

int cqueue[SIZE];
int rear = -1, front = 0;
int cnt = 0;

int add(int data) {
	if (cnt == SIZE) {
		printf("Circular Queue is Full!\n");
		return -1;
	}
	cnt++;
	cqueue[++rear % SIZE] = data;
	return 0;
}

int delete(void) {
	if (cnt == 0) {
		printf("Circular Queue is Empty!\n");
		return -1;
	}
	cnt--;
	return cqueue[front++ % SIZE]; // front 1������ delete() ȣ�⹮ ���� ����
}

int main(void) {
	add(10);
	add(20);
	add(30);
	printf("% d\n", delete());
	printf("% d\n", delete());
	printf("% d\n", delete());
	printf("% d\n", delete());
	add(40);
	add(50);
	add(60);
	add(70);
	add(80);
	add(90);
	add(100);

	return 0;
}