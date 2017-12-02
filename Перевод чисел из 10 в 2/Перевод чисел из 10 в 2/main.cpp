﻿#include <iostream>
#include <cmath>

using namespace std;

int input(char in[]);
void div_2(char in[], int n);
int isNull(char in[], int n);

int main() {
	setlocale(LC_ALL, "Russian");

	char input_value[100]; // Десятичное число, которое введет пользователь

	int count; // Переменная отвечает за кол-во чисел в входном числе
	int newCount = 0; // Переменная отвечает за кол-во чисел в выходном числе

	count = input(input_value); // Вводим число и получаем кол-во чисел в входном числе
	char output_value[1000]; // Массив, куда будем записывать остаток от деления


							 // Пока число, которое мы постепенно делим на 2 (и после чего записываем остаток в выходное число) не равно нулю
	while (!isNull(input_value, count)) {
		// если в двух словах, то операция (Символ - 0) дает нам int'овое число
		// а операция (Int'овое число + 0) дает нам опять же символ того же числа 
		//
		// Тут мы делим каждую цифру в десятичном числе на 2 и записываем остаток в массив
		output_value[newCount] = '0' + (input_value[count - 1] - '0') % 2;
		newCount++; // После записи остатка увеличиваем кол-во цифр в выходном числе на 1
					// Эта функция делит входное число на 2
		div_2(input_value, count);
	}

	// А тут мы просто разворачиваем массив, где содержатся остатки от деления входного числа на 2
	for (int i = 0; i < newCount / 2; ++i) {
		char buf = output_value[i];
		output_value[i] = output_value[newCount - 1 - i];
		output_value[newCount - 1 - i] = buf;
	}

	// В конце выходного числа у нас '\0' - чтобы оно приняло вид строки, и чтобы cout знал, когда останавливаться
	output_value[newCount++] = '\0';

	cout << output_value << endl;
	system("pause");
}

// Функция, в которой происходит считывание десятичного числа
int input(char input_value[]) {

	int isCorrect = 0; // Переменная отвечает за корректные данные
	int count; //переменная отвечает за кол-во цифр в числе

			   // Пока данные некорректны
			   // Функция нужна, чтобы заставить юзера вводить число еще раз, если данные некорректны
	while (!isCorrect) {

		isCorrect = 1; // Говорим, что данные корректны, 
		count = 0; // Кол-во цифр в числе равно нулю
		cout << "Введите десятичное число и нажмите энтер:" << endl;
		cin >> input_value; // Заносим введенную строку в массив input

							// Для каждого символа в строке
		while (input_value[count] != '\0') {
			// Если символ не цифра от 0 до 9
			if (input_value[count] < '0' || '9' < input_value[count]) {
				isCorrect = 0; // Говорим, что данные не корректны и выводим сообщение
				cout << "Вы ввели недопустимые символы!" << endl << endl;
				break; // Выводим из цикла 
			}
			count++; // Переход к следующему символу
		}
	}
	return count;
}

// Функция для получениz следующего числа, которое нужно будет делить на 2
//
// Пример того, что она делает:
// 123 -> 61
// 61 -> 30
// 30 -> 15
// 15 -> 7
// 7 -> 3
// 3 -> 1
// 1 -> 0
void div_2(char input_value[], int count) {
	// Число 'в уме'
	int p = 0;
	for (int i = 0; i < count; ++i) { // Для всех цифр в числе
									  // Получаем текущее число, с учетом того, что у нас могло быть число в 'уме'
									  //
									  // Т.е. например при делении на 100 мы не можем разделить 1 на 2 и записать туда 0.5
									  // Нам нужно вместо единички записать (int)1/2, а это 0
									  // И в 'число в уме' записать 1 % 2, а это 5
									  // Чтобы в в следующую итерацию делить не  00 на 2, а (00 + 5 * 10), т.е. 50
									  // Как-то атк

		int current_number = input_value[i] - '0' + p * 10;
		// Получаем целое число при делении текущего числа на два
		input_value[i] = (int)(current_number / 2) + '0';
		// Получаем остаток, от деления текущего числа на два
		p = current_number % 2;
	}
}


// Функция возвращает 1, если строка состоит из нулей
//
// На деле эта функция нужна, чтобы проверять, нужно ли еще делить input_value
int isNull(char input_value[], int count) {
	for (int i = 0; i < count; ++i) // Для всех цифр в числе
		if (input_value[i] != '0') // Если цифра в числе не равна нулю возаращаем 0
			return 0;
	// Если предыдущий цикл выполнился, значит в строке нет нулей, значит возращаем 1
	return 1;
}