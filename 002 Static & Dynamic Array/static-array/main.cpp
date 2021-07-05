#include "array.h"

/* driver-program */
int32_t main(int32_t argc, char* argv[]) {

    Array<std::string, 12> months_name;

    /* access months_name elements */
    months_name.at(0) = std::string{"January"};
    months_name.at(1) = std::string{"February"};
    months_name.at(2) = std::string{"March"};
    months_name.at(3) = std::string{"April"};
    months_name.at(4) = std::string{"May"};
    months_name.at(5) = std::string{"June"};
    months_name.at(6) = std::string{"July"};
    months_name.at(7) = std::string{"August"};
    months_name.at(8) = std::string{"September"};
    months_name.at(9) = std::string{"October"};
    months_name.at(10) = std::string{"November"};
    months_name.at(11) = std::string{"December"};

    /* print months_name */
    std::cout << "\nMonths: \n" << std::endl;
    months_name.display_element();
    return 0;
}