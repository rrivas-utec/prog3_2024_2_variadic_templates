#include <iostream>

template<typename ...Ts>
auto sumarizar(Ts ...args) {
    return (... + args);
}

template<typename ...Ts>
auto productos(Ts ...args) {
    return (... * args);
}

template<typename T>
bool es_par(T a) { return a % 2 == 0;}

template<typename ...Ts>
auto son_todos_pares(Ts ...args) {
//    return (... && (args % 2 == 0));
    return (es_par(args) && ...);
}

void ejemplo_1() {
    std::cout << std::boolalpha << son_todos_pares(2, 3) << std::endl;
    std::cout << std::boolalpha << son_todos_pares(2, 4, 6) << std::endl;
}

auto fun_1(int a, int b) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
auto fun_1(T a, T b) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
auto fun_1(T a) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
auto fun_1(T* a, T* b) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ejemplo2() {
    fun_1(10, 20);
    fun_1(10.5, 20.5);
    int a = 10;
    int b = 20;
    fun_1(&a, &b);
}

// Condiciones base
bool compare() { return true; }

bool compare(int) { return true; }

// Condicion recursiva
template <typename T, typename ...Ts>
bool compare (T first, T second, Ts ... other_params) {
    return (first == second) && compare(other_params...);
}

void ejemplo3() {
    std::cout << std::boolalpha << compare(1, 1, 2, 2, 4, 3, 4, 4, 5) << std::endl;
}

auto sum_product() { return 0; }
auto sum_product(int a) { return a; }

template <typename T, typename ...Ts>
auto sum_product(T first, T second, Ts ...rest) {
    return first * second + sum_product(rest...);
}

int main() {
//    ejemplo2();
    ejemplo3();
    return 0;
}
