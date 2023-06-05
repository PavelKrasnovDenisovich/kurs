#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <exception>
#include "ErrorTracker.h"

/**
@brief Класс для вычислений по вектору
*/

class Counter
{
private:
int64_t result[1]; ///< Результат вычислений
public:
    Counter(){}; ///<Конструктор без параметров

/** 
 @brief Вычисляет сумму квадратов по вектору (в случае переполнения - максимальное значение int64_t)
 @param [in] arr, вектор, std::vector<int64_t>
 @return указатель на массив с результатом, int64_t *
 @throw std::server_error в случае ошибки, критическая
 @code 
 type = invalid_argument, what ="Count Error"
 @endcode
*/

int64_t * squares(std::vector<int64_t> arr)
    {
		try{
			if (arr.empty()){
		throw server_error(std::string("Count Error"));}
    	for (std::vector<int64_t>::iterator it = arr.begin() ; it != arr.end(); ++it){
    	std::cout << ' ' << *it;}
  		std::cout << '\n';
        uint64_t sum = 0;
    		for (uint32_t i = 0; i < arr.size(); i++) {
        sum += static_cast<int64_t>(arr[i]) * static_cast<int64_t>(arr[i]);
    }
    if (sum > static_cast<int64_t>(INT64_MAX)) {
        result[0] = INT64_MAX;
    } else result[0] = sum;
		}catch(std::exception &e){
			throw server_error(std::string("Count Error"));
			}									
        return result;
    }
};

