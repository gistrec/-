#include <iostream>
#include <functional>

// std::function< тип_результата( аргументы функции )> 
void test_lambda(std::function<std::string(std::string)>  i) {
	std::string str = "hello world";
	std::cout << i(str).c_str() << std::endl;
}


void main() {
	// []                       без захвата переменных из внешней области видимости
	// [=]                      все переменные захватываются по значению
	// [&]                      все переменные захватываются по ссылке
	// [x, y]                   захват x и y по значению
	// [&x, &y]                 захват x и y по ссылке
	// [in, &out]               захват in по значению, а out — по ссылке
	// [=, &out1, &out2]        захват всех переменных по значению, кроме out1 и out2,	
	//	 					    которые захватываются по ссылке
	// [&, x, &y]               захват всех переменных по ссылке, кроме x…

	

	auto lambda_sum = [](int x, int y) -> int { return x + y; };
	std::cout << "5 + 7 = " << lambda_sum(5, 7) << std::endl;

	// Получаем все значение по ссылке
	auto lambda_increment = [](int &x) -> void { x++; };
	int x = 5;
	lambda_increment(x);
	std::cout << "5++ = " << x << std::endl;

	// auto == std::function<std::string(std::string)>
	std::function<std::string(std::string)> lambda_to_function = [](std::string &string) -> std::string { return string; };
	test_lambda(lambda_to_function);


	system("pause");
}