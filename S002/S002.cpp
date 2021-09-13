// S002.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	std::cout << "Hello World!\n";
	char s[256];
	char t[256];
	char m1[] = "Strochka1\n";
	char m2[] = "Strochka2\n";
	char f[] = "%s";
	char fgs[] = "1\n";
	char fls[] = "-1\n";
	char fes[] = "0\n";
	_asm
	{
		//печатаем 1 строку
		lea ebx, m1
		push ebx
		lea ecx, f
		push ecx
		call printf
		add esp, 8

		//читаем 1 строку
		lea ebx, s
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		//печатаем 2 строку
		lea ebx, m2
		push ebx
		lea ecx, f
		push ecx
		call printf
		add esp, 8

		//читаем 2 строку
		lea ebx, t
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		//подготовка цикла проверки 1 строки
		lea ebx, s
		dec ebx
		lea ecx, t
		dec ecx
		b1 :
		inc ebx
			inc ecx
			mov al, [ebx]
			mov dl, [ecx]
			cmp al, 0

			je b2//находим конец 1 строки

			cmp dl, 0
			je f3//находим конец 2 строки (2 меньше)
			cmp al, dl
			je b1//cимволы в строках равны (продолжаем цикл)

			jb f4//символ в 1 строке меньше символа во 2
			jmp f3//символ во 2 строке меньше символа в 1

			b2 ://конец в первой строке
		cmp dl, 0
			je f5//конец 2 строки (строки равны)
			jmp f4// 2 строка больше

			f3 : //1 больше
		lea ebx, fgs
			push ebx
			lea ecx, f
			push ecx
			call printf
			add esp, 8
			jmp end
			f4 ://2 больше
		lea ebx, fls
			push ebx
			lea ecx, f
			push ecx
			call printf
			add esp, 8
			jmp end
			f5 ://строки равны
		lea ebx, fes
			push ebx
			lea ecx, f
			push ecx
			call printf
			add esp, 8

			end:

	}
	system("pause");
}