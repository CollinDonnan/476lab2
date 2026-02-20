#include <tuple>
#include <iostream>
#include <print>

// Prompt and get input. 
std::tuple<unsigned, std::string, unsigned>
getInput ();


void
printResults (); 

/*
void
fillRandom (Matrix<T>& matrix, U min, U max);


template<typename T>
void
multiplyIjk (Matrix<T>& C, Matrix<T> const& A, Matrix<T> const& B);

template<typename T>
void
multiplyJki (Matrix<T>& C, Matrix<T> const& A, Matrix<T> const& B);

template<typename T>
void
multiplyKij (Matrix<T>& C, Matrix<T> const& A, Matrix<T> const& B);

template<typename T>
void
multiplyBlock (Matrix<T>& C, Matrix<T> const& A, Matrix<T> const& B,
               unsigned blockSize);

template<typename T>
void
multiplyParallel (Matrix<T>& C, Matrix<T> const& A, Matrix<T> const& B);

*/

int main(){
    std::tuple<unsigned, std::string, unsigned> input = getInput();
    unsigned n = std::get<0>(input);
    std::string version = std::get<1>(input);
    unsigned block_size = std::get<2>(input);
    std::print("{} {} {}", n, version, block_size);

}



std::tuple<unsigned, std::string, unsigned>
getInput (){
    unsigned n = 0;
    std::print("N       ==> ");
    std::cin>>n;
    std::println("");
    std::string version = "";
    std::print("Version ==> ");
    std::cin>>version;
    std::println("");
    unsigned block_size = 0;
    if(version == "Block"){
        std::print("B       ==> ");
        std::cin>>block_size;
        std::println("");
    }
    return std::tuple(n, version, block_size);
}