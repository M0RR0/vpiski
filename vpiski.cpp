#define _CRT_SECURE_NO_WARNINGS
#define _let (helper->value) == 32 && ((65 <= (helper->next->value) && (helper->next->value) <= 90) || (97 <=(helper->next->value) && (helper->next->value) <= 122))
#define first_let (helper == head && ((65 <=(helper->next->value) && (helper->next->value) <= 90) || (97 <= (helper->next->value) && (helper->next->value) <= 122)))
#define списка_нет 	\
			{printf("\n\x1b[1;4;34mСписка не существует. Создайте сначала список\n");\
			printf("\n\x1b[0m");\
			_getch();}\

#include <stdio.h>
#include <iostream>
#include <conio.h>


struct list {
	char value;
	struct list* next;
};

int check_for_empty(struct list*);

void end_ptr(struct list*, struct list**);

int print(struct list* head, struct list* work) {
	struct list* helper = (struct list*)malloc(sizeof(struct list));
	if (helper == NULL) {
		printf("\x1b[1;4;34mNot memmory added.\n");
		printf("\x1b[0m");
		return 0;
	}
	if (head == NULL) {
		printf("\x1b[1;4;34mСписок пуст.\n");
		return 0;
	}

	helper = head;
	while (helper != NULL) {
		if (helper == work) {
			printf("\x1b[5;1;4;31m");
			printf("%c", helper->value);
			printf("\x1b[0m");
		}
		else printf("%c", helper->value);

		helper = helper->next;
	}
	printf("\n");
	return 1;
}

int print_previos(struct list* head, struct list** work) {
	struct list* helper = (struct list*)malloc(sizeof(struct list)), * hel = *work;
	if (helper == NULL) {
		printf("\x1b[1;4;34mNot memmory added.\n");
		printf("\x1b[0m");
		return 0;
	}
	if (head == NULL) {
		printf("\x1b[1;4;34mСписок пуст.\n");

		return 0;
	}
	end_ptr(head, work);
	helper = *work;
	*work = hel;
	while (helper != NULL) {
		if (helper == *work) {
			printf("\x1b[5;1;4;31m");
			printf("%c", helper->value);
			printf("\x1b[0m");
		}
		else printf("%c", helper->value);

	}
	printf("\n");

	return 1;
}

struct list* added(struct list* head, struct list** work) {
	char element;
	struct list* helper = (struct list*)malloc(sizeof(struct list)), * workd = *work, * help;
	if (helper == NULL) {
		printf("\x1b[1;4;34mNot memmory added.\n");
		printf("\x1b[0m");
		return 0;
	}		// проверка на выделение памяти

	printf("Ввод: ");
	//while (getchar() != '\n');
	scanf("%c", &element);
	while (element != '\n') {
		if (head == NULL) {
			head = (struct list*)malloc(sizeof(struct list));
			if (head == NULL) {
				printf("\x1b[1;4;34mNot memmory added.\n");
				printf("\x1b[0m");
				return 0;
			}
			head->value = element;
			head->next = NULL;
			*work = head;

		}

		else {
			struct list* helper = (struct list*)malloc(sizeof(struct list));
			help = head;
			while (help->next != NULL)
			{
				help = help->next;
			}
			helper->value = element;
			help->next = helper;
			helper->next = NULL;


		}
		//while (getchar() != '\n');
		scanf("%c", &element);


	}

	return head;
}


struct list* added(struct list* head, struct list** work, char element) {
	struct list* helper = (struct list*)malloc(sizeof(struct list)), * workd = *work, * help;
	if (helper == NULL) {
		printf("\x1b[1;4;34mNot memmory added.\n");
		printf("\x1b[0m");
		return 0;
	}		// проверка на выделение памяти

	//while (getchar() != '\n');
	if (head == NULL) {
		head = (struct list*)malloc(sizeof(struct list));
		if (head == NULL) {
			printf("\x1b[1;4;34mNot memmory added.\n");
			printf("\x1b[0m");
			return 0;
		}
		head->value = element;
		head->next = NULL;
		*work = head;

	}

	else {
		struct list* helper = (struct list*)malloc(sizeof(struct list));
		help = head;
		while (help->next != NULL)
		{
			help = help->next;
		}
		helper->value = element;
		help->next = helper;
		helper->next = NULL;


	}
	//while (getchar() != '\n');



	return head;
}

struct list* added_file(struct list* head, struct list** work) {
	char name[] = "str.txt", element;
	FILE* foo;
	foo = fopen(name, "r");
	struct list* helper = (struct list*)malloc(sizeof(struct list)), * workd = *work, * help;
	if (helper == NULL) {
		printf("\x1b[1;4;34mNot memmory added.\n");
		printf("\x1b[0m");
		return 0;
	}		// проверка на выделение памяти
	element = fgetc(foo);
	while (element != EOF) {
		if (head == NULL) {
			head = (struct list*)malloc(sizeof(struct list));
			if (head == NULL) {
				printf("\x1b[1;4;34mNot memmory added.\n");
				printf("\x1b[0m");
				return 0;
			}
			head->value = element;
			head->next = NULL;
			*work = head;

		}

		else {
			struct list* helper = (struct list*)malloc(sizeof(struct list));
			help = head;
			while (help->next != NULL)
			{
				help = help->next;
			}
			helper->value = element;
			help->next = helper;
			helper->next = NULL;
		}
		//while (getchar() != '\n');
		element = fgetc(foo);


	}


	return head;
}



int start_ptr(struct list* head, struct list** work) {
	if (check_for_empty(head)) {
		return 0;
	}
	*work = head;
}

int check_for_recent(struct list* head, struct list* work) {
	struct list* helper = head;
	if (check_for_empty(head)) {
		printf("\x1b[1;4;34mСписок пуст. Заполните сначала список\n");
		printf("\x1b[0m");
		return 0;
	}
	while (helper->next != NULL) {
		helper = helper->next;
	}
	if (helper == work) {
		return 1;
	}
	else return 0;
}

int mouve_ptr_next(struct list* head, struct list** work) {
	if (head == NULL) {
		return 0;
	}
	struct list* helper = *work;
	if (helper->next != NULL) {
		helper = helper->next;
		*work = helper;
	}
	else *work = head;


}


char show_next_element(struct list* head, struct list* word) {
	if (word->next != NULL) {

		return word->next->value;
	}
	else {
		printf("\x1b[1;4;34mУказатель находится в конце списка");
		printf("\x1b[0m");
		return 0;
	}

}

void delete_element(struct list** head, struct list** work) {

	struct list* helper = *work;
	if (*work == *head) {
		*head = (*head)->next;
		(*work) = (*work)->next;
	}
	else if ((*work)->next == NULL) (*work)->next = helper->next;
	else mouve_ptr_next(*head, work);
	free(helper);
}

struct list* removeall(struct list* head)
{
	while (head != NULL)
	{
		struct list* p = head;
		head = head->next;
		free(p);
	}
	return NULL;
}

struct list* swap(struct list* head, int M, int N)
{
	int count = 0;
	struct list* prev1, * prev2, * next1, * next2, *helper = head, *lst1 = NULL, *lst2 = NULL;
	while (helper->next != NULL) {
		if (count == M - 1) {
			lst1 = helper;
		}
		if (count == N - 1) {
			lst2 = helper;
		}
		helper = helper->next;
		count++;
	}

	// Возвращает новый корень списка
	prev1 = head;
	prev2 = head;
	if (prev1 == lst1)
		prev1 = NULL;
	else
		while (prev1->next != lst1) // поиск узла предшествующего lst1
			prev1 = prev1->next;
	if (prev2 == lst2)
		prev2 = NULL;
	else
		while (prev2->next != lst2) // поиск узла предшествующего lst2
			prev2 = prev2->next;
	next1 = lst1->next;  // узел следующий за lst1
	next2 = lst2->next;  // узел следующий за lst2
	if (lst2 == next1)
	{                       // обмениваются соседние узлы
		lst2->next = lst1;
		lst1->next = next2;
		if (lst1 != head)
			prev1->next = lst2;
	}
	else
		if (lst1 == next2)
		{
			// обмениваются соседние узлы
			lst1->next = lst2;
			lst2->next = next1;
			if (lst2 != head)
				prev2->next = lst2;
		}
		else
		{
			// обмениваются отстоящие узлы
			if (lst1 != head)
				prev1->next = lst2;
			lst2->next = next1;
			if (lst2 != head)
				prev2->next = lst1;
			lst1->next = next2;
		}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}


void task(struct list* head, struct list* work) {//сама задача
	int x = 1, y = 1, count = 0;
	struct list* helper, * u = NULL;
	helper = head;
	bool in_word = 0;
	struct list* help = NULL;
	//char* m = (char*)malloc(y * sizeof(char));
	while (helper->next != NULL) { //A=65 Z=90, a=97, z=122 //   123 qwe 

		if (_let || first_let) {
			help = added(help, &u, helper->value);
			//m = (char*)realloc(m, y * sizeof(char));
			in_word = 1;
			count++;
		}
		else if (in_word) {
			help = added(help, &u, helper->value);
			//m = (char*)realloc(m, y * sizeof(char));
			if ((helper->next->value) == 32 || (helper->next->value) == '/0') in_word = 0;

		}


		helper = helper->next;

	}


	print(help, u);
	_getch();


}



int main()
{
	bool flag = 1;
	struct list* lst = NULL, * work = NULL;
	setlocale(LC_ALL, "Russian");
	char c, c49, c50, c51;

	while (true)
	{
		if (lst != NULL) print(lst, work);
		printf("\n\n\t Меню:\n |1| Ввод списка\n |2| Переместить указатель\n |3| Добавить элемент \n |4| Удалить текущий элемент \n |5| Удaлить все и освободить память \n |6| Задача \n |7| Вывод списка в обратном порядке \n |8| Поменять m и n\n");
		char c = _getch();
		switch (c)
		{
		case 49://1
			printf("\nВвод списка:");
			printf("\n |1| С клавиатуры \n |2| Из файла\n");
			c49 = _getch();
			switch (c49)
			{
			case 49:
				lst = added(lst, &work);
				break;
			case 50:
				lst = added_file(lst, &work);
				break;
			default:
				printf("\nMisclick!");
				_getch();
				break;
			}
			break;
		case 50://2
			if (lst != NULL) {
				printf("\n |1| Переместить вперед \n |2| Переместить назад \n |3| Переместить в начало списка \n |4| Переместить в конец\n");
				c50 = _getch();
				switch (c50)
				{
				case 49:
					mouve_ptr_next(lst, &work);
					break;
				case 50:
					//mouve_ptr_previos(lst, &work);
					break;
				case 51:
					start_ptr(lst, &work);
					break;
				case 52:
					end_ptr(lst, &work);
					break;
				default:
					break;
				}
			}
			else списка_нет
				break;
		case 51://3
			printf("\n|%c|", c);
			if (lst != NULL) {
				printf("\n |1| Добавить элемент в список после указателя \n |2| Добавить элемент в список перед указателем");
				c51 = _getch();
				switch (c51) {
				case 49:
					lst = added(lst, &work);
					break;
				case 50:
					lst = added_file(lst, &work);
					break;
				default:
					printf("\nMisclick!");
					_getch();
					break;
				}
			}
			else списка_нет
				break;
		case 52://4
			printf("\n|%c|", c);
			if (lst != NULL) {
				delete_element(&lst, &work);
			}
			else списка_нет
				break;
		case 53://5
			printf("\n|%c|", c);
			if (lst != NULL) {
				lst = removeall(lst);
				work = NULL;
			}
			else списка_нет
				break;
		case 54://6
			printf("\n|%c|", c);
			if (lst != NULL) {
				task(lst, work);
			}
			else списка_нет
				break;
		case 55://7
			printf("\n|%c|", c);
			if (lst != NULL) {
				print_previos(lst, &work);
				_getch();
				break;
			}
			else списка_нет
				break;
		case 56:
			int M, N;
			printf("\n|%c|", c);
			if (lst != NULL) {
				printf("Введите индексы, которые хотите поменять\n");
				printf("поменять: ");
				scanf("%d", &M);
				printf("на ");
				scanf("%d", &N);
				lst = swap(lst, M, N);
			}
			else списка_нет
				break;
		default:
			printf("\nMisclick!");
			_getch();
			break;
		}
		system("cls");
	}
}







int check_for_empty(struct list* head) {
	if (head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void end_ptr(struct list* head, struct list** work) {
	/*if (check_for_empty(head)) {
		return 0;
	}*/
	while ((*work)->next != NULL) {
		*work = (*work)->next;
	}
}