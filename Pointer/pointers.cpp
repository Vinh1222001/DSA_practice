#include <iostream>

/**
 * @brief function pointer and function pointer array
*/

typedef void (*func_ptr)(float);

func_ptr func_arr[3];

void print_Hello(float){
    std::cout << "Hello"<<std::endl;
}

void print_Hi(float){
    std::cout << "Hi" <<std::endl;
}

void print_Hola(float){
    std::cout << "Hola" << std::endl;
}

void initFuncArr(){
    func_arr[0]= print_Hello;
    func_arr[1]= print_Hi;
    func_arr[2]= print_Hola;
}

int main(void){
    
    initFuncArr();
    
    for(int i =0; i < 3; i++){
        std::cout << sizeof(func_arr[i](10.00f))<< std::endl;
    }
    return 0;
}