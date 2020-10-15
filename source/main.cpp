#include <iostream> 
#include "exam.h"


void runTests() {




}

int main() { 

    srand(time(NULL)); // seed random library with time.

    Rolldice test(50, 20, 6, 500);

    Rolldice g1(100, 20 ,8, 200);

    Rolldice g2(70, 20, 8, 75);


    std::vector<RDtest> testing;

    testing.push_back(RDtest(test));
    testing.push_back(RDtest(g1));
    testing.push_back(RDtest(g2));


    // using random library to generate values for roles dice, and pushing it to vector

    int x=0,y=0,z=0, a=0; // to hold the values of dice accordingly
 

    // Pushing the testing objects into the vector
    for ( int i=0; i < 50; i++ ) {
        x = 70 + (rand() %100)*10, y = 20, z= 6 + rand() % 7, a = 10*i;
        testing.push_back(RDtest(Rolldice(x,y,z,a)));
    }

    //Simple testing approach
    // Testing Sides
    if (testing[0].game_test.sides != 14) {
        std::cout << "failed for < Side = 14 >\n"; 
        std::cout << " sides is " <<testing[0].game_test.sides << std::endl;
    }
    
    if (testing[0].game_test.balance != 170 ) {
        std::cout << "failed for <Balance = 170 >\n"; 
        std::cout << " Balance  is " <<testing[0].game_test.balance  << std::endl;
    }
    if (testing[0].game_test.count != 10 ) {
        std::cout << "failed for <count = 170 >\n"; 
        std::cout << " count is " <<testing[0].game_test.count << std::endl;
    }
    
      if (testing[0].game_test.bet != 90 ) {
        std::cout << "failed for <Bet = 90 >\n"; 
        std::cout << " Bet is actually " <<testing[0].game_test.balance  << std::endl;
    }
    

    // Performing A lot of tests on the functions.
    std::cout << " If you don't see Test fail, it means the test passed. And I also performed a Blackboard testing on it" << std::endl; 
    for ( int i=0; i < 53; i++ ) {
        mother_tests( testing[i]); 
    }

    return 0;

}
