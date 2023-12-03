﻿#include <iostream>


void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void p_swap(int* pointer1, int* pointer2) {
	int tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}
void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << *(arr + i) << ' ';
	std::cout << std::endl;
}
void p_sum_arr(int arr[], const int length, int* var);




int main() {
	setlocale(LC_ALL, "ru");
	int n, m;
	//Указатели на переменные
	                
	n = 7;
	std::cout << "n = " << n << std::endl;
	std::cout << "&n = " << &n << std::endl; // & - операция обращения к памяти элемента.

	//Указатели - это переменные, созданные для хранения адресов ячеек оперативной памяти устройства. Например, указатель может хранить адрес переменной.

	int* pn = &n; // Создание указателя на переменную n.
	std::cout << "pn = " << pn << std::endl;
	std::cout << "*pn = " << *pn << std::endl;
	// Разыменование - операция, применяемая к указателям и позволяющая обращаться через них к тем участкам памяти н акоторые они направлены.
	*pn = 15;
	std::cout << "n = " << n << std::endl; //Указатель позволяет обратится к переменной косвенно.
	std::cout << "------------------------------\n";
	m = 42;
	pn = &m; // Перенаправление указателя на другую область памяти.
	std::cout << "m = " << m << std::endl;
	std::cout << "&m = " << &m << std::endl;
	std::cout << "pn = " << pn << std::endl;
	*pn = 105;
	std::cout << "m = " << m << std::endl;
	std::cout << "------------------------------\n";

	int* pm = &m;
	std::cout << "pm = " << pm << std::endl;
	// Размер указателя НЕ ЗАВИСИТ от типа памяти на которую он направлен. Он зависит от разрядности ОС. Например в Windows х64 размер указателя - 64 бит(8 байт). 

	


	//Указатели  и массивы
	
	const int size = 5;
	int arr[size]{ 70,80,90,100,110 };
	int* parr = &arr[2];
	std::cout << "*parr = " << *parr << std::endl;
	std::cout << "parr = " << parr << std::endl;
	std::cout << "parr + 1= " << parr + 1 << std::endl; 
	//Арифметика указателей - процесс перенаправления указателя на другую область памяти посредством применения целочисленных операций сложения и вычитания.
	//pointer + n = pointer + n * тип_данных.

	parr++; // перенаправление на элемент 100
	parr -= 2; //перенаправление на элемет 80

	parr = &arr[0];
	std::cout << "Массив: \n";
	for (int i = 0; i < size; i++)
		std::cout << *(parr + i) << ' ';
	std::cout << std::endl;

	// Массив - это указатель, направленный на первый елемент упорядоченной однотипной группы элементов.

	//Ограничения фрифметики указателей:
	// 1. нельзя выполнять умножение и деление адреса;
	// 2. нельзя применять не целочисленные значения при сдвиге указателя;
	// 3. Можно вычитать значения одного указателя из другого, но нельзя их складывать;
	

	// Указатели и функции
	
	n = 7; m = 15;
	std::cout << n << ' ' << m << std::endl;
	//my_swap(n, m); // не работает, т.к. парамметры это лишь копии аргументов
	std::cout << n << ' ' << m << std::endl;
	p_swap(&n, &m);
	std::cout << n << ' ' << m << std::endl;
	
	
	//Задача 1. Сумма через указатель
	std::cout << "Задача 1.\nМассив: \n";
	const int size2 = 10;
	int arr2[size2]{ 10,20,30,40,50,10,20,30,40,50 };
	int sum;
	print_arr(arr2, size2);
	p_sum_arr(arr2, size2, &sum);
	std::cout << "Сумма его елементов: " << sum << "\n\n";

	//Области применения указателей:
	// 1.Реализация такой технологии, как массивы;
	// 2.Доступ к элементам, расположенным в других блоках программы;
	// 3.Обращение к динамической памяти;
	// 4.Создание сложных динамических структур данных;
	// 5.Реализации полиморфизма при наследовании классов;


	return 0;
}
void p_sum_arr(int arr[], const int length, int* var) {
	*var = 0;
	for (int i = 0; i < length; i++)
		*var += *(arr + i);
}
