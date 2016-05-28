//
// Created by Dima on 28.05.2016.
//

#ifndef CPPWINDOWS_TESTING_H
#define CPPWINDOWS_TESTING_H

#include <iostream>
#include <vector>
#include <functional>

#define TEST(x, y) t_tests.push_back(Test((x), []() y));

#define ASSERT(x) if(!x) { t_passed = false; return; }
#define ASSERT_F(x) if(x) { t_passed = false; return; }
#define ASSERT_EQ(x, y) if((x) != (y)) { t_passed = false; return; }
#define ASSERT_NEQ(x, y) if((x) == (y)) { t_passed = false; return; }

namespace testing {

    class Test {
    public:
        std::string Name;
        std::function<void()> Run;

        Test(std::string name_, std::function<void()> run_) : Name(name_), Run(run_) { }
    };

    std::vector<Test> t_tests;
    bool t_passed;

    bool t_addTests(){
#ifdef BUILD_TESTS
    #include "Tests.inc"
        return true;
#else
        return false;
#endif
    }

    bool RunTests() {
        std::cout << "Running tests...\n\n";

        if(!t_addTests()){
            std::cout << "ERROR: Test building is off.\n";
            return false;
        }

        int total = t_tests.size();
        int passed = 0;
        int failed = 0;
        for(Test test : t_tests){
            std::cout << test.Name << "... ";
            t_passed = true;

            test.Run();

            if(t_passed){
                std::cout << "PASSED\n";
                passed++;
            } else {
                std::cout << "FAILED\n";
                failed++;
            }
        }

        std::cout << "\nTotal:  " << total;
        std::cout << "\nPassed: " << passed;
        std::cout << "\nFailed: " << failed;
        std::cout << "\n\n";

        if(total != passed + failed){
            std::cout << "ERROR running tests.\n";
            return false;
        } else if(failed == 0) {
            std::cout << "All tests PASSED.\n";
            return true;
        } else if(failed > 0) {
            std::cout << "Some tests FAILED.\n";
            return false;
        }
    }

}

#endif //CPPWINDOWS_TESTING_H
