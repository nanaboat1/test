#pragma once

#include <cstdlib> 
#include <ctime> 
#include <vector> // STL for vector
#include <iostream>

#include <string> 


class Rolldice {  

    public : 
        int bet;
        int sides;
        int count; 
        int balance;
        std::vector<int> rolls;


        // Default Constructor 
        Rolldice( ) : Rolldice(3,20,8, 200) { } // default constructor with pre-defined values.

        Rolldice(int _bet, int _sides, int _count, int _bal ) : bet(_bet), sides(_sides), count(_count), balance(_bal) { }

        ~Rolldice() { rolls.clear();  }

        std::vector<int> GetDiceRoll() {

            
            // Check to see that count if within limit
            if ((count <= 0 || count >= 5) && sides <= 0 )
                return rolls;

            // roll the dice and push it to vector. 
            for (int i=0; i<count; i++)
                rolls.push_back(1 + (rand() % sides));

            return rolls;
        }


        int prompt () { 

           // std::cout << " You currently have $" << balance << std::endl;

           // std::cout << " Current roll: " << rolls[0] << " " << rolls[1] << std::endl;

           // std::cout << " How much will you bet that the next roll is between those? " << std::endl;

            return bet;
        }


        int takeTurn() { 

            int max_roll=0;
            int min_roll=0;

            // check to see the max and min die value.
            if ( rolls[0] >= rolls[1]) {
                max_roll = rolls[0];
                min_roll = rolls[1];
            } else {
                max_roll = rolls[1];
                min_roll = rolls[0];
            }

            // Checks if the third roll is between the first two shown rolls.
            if ( rolls[3] <= max_roll && rolls[3] >= min_roll ) {

                // player won the bet.
                return balance + bet;
            } else { 
                
                //player lost the bet. 
                balance = balance - bet; 
                return balance;
            }

            return 0;//
        }

    // 

};


class RDtest { 

    public : 


        Rolldice game_test; // tests a roll dice class. 
        int exp_results_sides;
        int exp_results_prompt;
        int exp_results_taketurn ;
        std::string exp_results_GetDiceRoll;

        // Constuctors
        RDtest( ) : RDtest( Rolldice(50, 20, 6, 500) ) {}

        RDtest( Rolldice game ) : game_test(game), exp_results_sides(game_test.sides), 
                                  exp_results_prompt(game_test.bet), exp_results_taketurn(game_test.balance) {}

        // Perform tests

        // test sides 
        int test_sides( ) {

            int actual;  

                actual = game_test.sides;
            
            return actual;
        }

        // test prompt
        int test_prompt( ) {

            int actual; 

            actual = game_test.prompt();
            
            return actual;
        }

        // test take_turn
        int test_takeTurn() {
            
            int actual =0;

            actual = game_test.takeTurn(); 

            return actual; 
        }

        // test getDiceRoll
        std::string test_getDiceRoll() {

            std::string actual ="";

            std::vector <int> out_put = game_test.GetDiceRoll();

            for ( int i=0; i<3; i++) {
                actual += std::to_string(game_test.rolls[i]);
                exp_results_GetDiceRoll += std::to_string(out_put[i]);
            }

            // expected output  
            return actual;
        }

        std::string to_stringRolls( ) {

            std::string str; 

            for ( int i=0; i<3; i++ ) {

                str += std::to_string(game_test.rolls[i]); 
            }

            return str;
        }

       
               
};


    void mother_tests(RDtest & rd) {


            std::cout << "\nDICE Testing " << std::endl;
            
            std::cout << "Sides\n";
            int act_s = rd.test_sides(), exp_s = rd.exp_results_sides;
            if ( act_s != exp_s) {
                std::cout << "Test FAILED\n";
                std::cout << "\t<"<< "Sides is 20>\n";
                std::cout << "\texp: " << rd.exp_results_sides <<"\n";
                std::cout << "\tact: " << rd.test_sides() << "\n";
            } 

            std::cout << "Prompt\n";
            int act_p = rd.test_prompt(), exp_p = rd.exp_results_prompt;
            if ( act_p != exp_p) {
                std::cout << "Test FAILED\n";
                std::cout << "\t< bet is "<< rd.game_test.bet <<">\n";
                std::cout << "\texp: " << exp_p <<"\n";
                std::cout << "\tact: " << act_p << "\n";
            }

            std::cout << "TakeTurn\n";
            int act_t = rd.test_sides(), exp_t = rd.exp_results_sides;
            if ( act_t != exp_t ) {
                std::cout << "Test FAILED\n";
                std::cout << "\t< balance is "<< rd.game_test.balance <<">\n";
                std::cout << "\texp: " << exp_t<< "\n";
                std::cout << "\tact: " << act_t << "\n";
            }

            std::cout << "GetDiceRolls\n";
            std::string act_r = rd.test_getDiceRoll(), exp_r = rd.exp_results_GetDiceRoll; 
            if ( act_r != exp_r ) {
                std::cout << "Test FAILED\n";
                std::cout << "\t< Dice Values is "<< rd.exp_results_GetDiceRoll <<">\n";
                std::cout << "\texp: " << exp_r <<"\n";
                std::cout << "\tact: " << act_r << "\n";
            }

        }

    