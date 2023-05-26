#include <iostream>
#include <stdlib.h>
#include <stdexcept>

const double ratio_mile2km = 1.609344;
const double ratio_km2mile = ratio_mile2km/1;

enum class Option {
  help,
  km,
  mile
};

void print_help(){
  std::cout << \
    "Usage: discalc [options...] <number>" << std::endl << \
    "   -h | --help         Print this message" << std::endl << \
    "   -K | --km           Convert KM into miles" << std::endl << \
    "   -M | --miles        Convert miles into KM" << std::endl \
    ;
}

void cout(std::string message, std::string type){
  std::cout << type << ": " << message << std::endl;
}

void ProcessOption(Option option) {
  switch (option) {
      case Option::help:
        print_help();
        break;
      case Option::km: 
        std::cout << "km option selected via switch" << std::endl;
        break;
      case Option::mile:
        std::cout << "mile option selected via switch" << std::endl;
        break;
      default:
        throw std::invalid_argument("Invalid Option value");
        break;
  }
}

Option ToOption(const std::string& str) {
    if (str == "--help") return Option::help;
    if (str == "--km") return Option::km;
    if (str == "--mile") return Option::mile;
    throw std::invalid_argument("Invalid string value");
}

int main (int argc, char* argv[]){

  // check argc length
  if (argc != 3){
    print_help();
    std::exit(1);
  }


  // store option and value
  const std::string option(argv[1]);
  const std::string value(argv[2]);
  
  Option optionvar;
  optionvar = ToOption(option);
  ProcessOption(optionvar);

//  if (option == "-h" | option == "--help"){
//    
//    print_help();
//    std::exit(0);
//
//  } else if (option == "-K" || option == "--km"){
//    
//    std::cout << "km option selected" << std::endl;
//  
//  } else if (option == "-M" || option == "--miles"){
//    
//    std::cout << "mile option selected" << std::endl;
//
//  }else{
//
//    // fallback reached, wrong option?
//    
//    print_help();
//    exit(2);
//  
//  }

  //std::cout << "hello ying!" << std::endl;
  
}
