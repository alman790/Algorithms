#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int FAILED_TESTS = 0;

void write_inp(std::string &text) {
    std::ofstream input("input.txt");
    input << text;
    input.close();
}

void write_script(std::string &text) {
    std::ofstream script("script.txt");
    script << text;
    script.close();
}

std::string read_out() {
    std::ifstream output("output.txt");

    std::string result;
    std::string line;

    while (std::getline(output, line)) {
        result += line;
        result += "\n";
    }

    return result;
}

void clear_out() {
    std::ofstream output("output.txt", std::ios::trunc);
}

bool run_program(std::string &program) {
    std::string command = "\"" + program + "\" > output.txt";
    return std::system(command.c_str()) == 0;
}

void check(std::string &name, std::string &actual, std::string &expected) {
    if (actual == expected) {
        std::cout << "[PASSED] : " << name << "\n";
    } else {
        std::cout << "[FAILED] : " << name << "\n";
        std::cout << actual << " != " << expected << "\n";
        FAILED_TESTS++;
    }
}

void test_jollyscript(std::string &program) {
    {
        clear_out();

        std::string script =
            "          + *\n"
            "           ^\n"
            "          ^ ^\n"
            "         \" \" \"\n"
            "        H W l l\n"
            "       e o @ o d\n"
            "      l r O @   !\n"
            "     \" \" @ @ O \" \"\n"
            "    ~~~~~~|_|~~~~~~";

        std::string input = "";

        write_script(script);
        write_inp(input);

        if (!run_program(program)) {
            std::cout << "[FAILED] JollyScript: Hello World program error\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "Hello World!\n";
            std::string actual = read_out();
            std::string name = "JollyScript: Hello World";

            check(name, actual, exp);
        }
    }

    {
        clear_out();

        std::string script =
            "         *\n"
            "        ^\n"
            "       { ?\n"
            "      # . 1\n"
            "     / / } }\n"
            "    ~~~/-\\~~~";

        std::string input = "0";

        write_script(script);
        write_inp(input);

        if (!run_program(program)) {
            std::cout << "[FAILED] JollyScript: Truth-machine program error\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "0\n";
            std::string actual = read_out();
            std::string name = "JollyScript: Truth-machine zero";

            check(name, actual, exp);
        }
    }

    {
        clear_out();

        std::string script =
            "          *\n"
            "         {\n"
            "        ^ 0\n"
            "       & ? %\n"
            "      : + / ?\n"
            "     ~ + $ \\ /\n"
            "      ^ ,   $\n"
            "     : }   , \\\n"
            "    ~~~~{_}~~~~";

        std::string input = "Hello World!";

        write_script(script);
        write_inp(input);

        if (!run_program(program)) {
            std::cout << "[FAILED] JollyScript: Cat program error\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "Hello World!\n";
            std::string actual = read_out();
            std::string name = "JollyScript: Cat";

            check(name, actual, exp);
        }
    }

    {
        clear_out();

        std::string script =
R"JOLLY(                   @ *
                    {
                   0 ?
                  1 ^ ?
                 1 " X ?
                / F ^ X \
               / i / X $ \
              \ z ^ ^ \ \ /
               z / ^ \ \ \
              " X + ? ^ ^ ^
             ^ / : + X X X 1
            + X / % \ X X 2 /
           : + ? \ $ \ X 0 / \
          ~ ? \ 4 : } \ $ \ O ~
           ^ 1 \ - \ O : ~ n \
          + ? + \ ? ? O 9 O } \
         A 0 / / ^ $ ^ O - O O \
        - { B 0 ^ O 0 % O ? O O \
       ~ / + O " " + ~ . ^ $ O \ ~
        / 0 ~ B " z 1 O O 1 1 O \
       / 0 O u % $ z ~ + O + + O \
      / O O " . . O " $ O O 0 O O \
     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                 ///^\\\
                 /// \\\
                 \/___\/)JOLLY";

        std::string input = "";

        write_script(script);
        write_inp(input);

        if (!run_program(program)) {
            std::cout << "[FAILED] JollyScript: FizzBuzz program error\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "";

            for (int i = 1; i <= 100; i++) {
                if (i % 15 == 0) {
                    exp += "FizzBuzz\n";
                } else if (i % 3 == 0) {
                    exp += "Fizz\n";
                } else if (i % 5 == 0) {
                    exp += "Buzz\n";
                } else {
                    exp += std::to_string(i);
                    exp += "\n";
                }
            }

            std::string actual = read_out();
            std::string name = "JollyScript: FizzBuzz";

            check(name, actual, exp);
        }
    }

    {
        clear_out();

        std::string script =
R"JOLLY(                         + *
                          {
                         9 ^
                        9 / ?
                       \ : ^ ^
                      / X \ X \
                     / ? } / ^ ^
                    \ $ / ^ \ X /
                     % $ ^ ^ " ^
                    : 0 $ X " T 1
                   ? ~ / / " " a ^
                  $ ^ \ / " " 0 k ~
                 1 $ / / / ? 2 / " /
                \ ~ % / / + / ^   ^ /
                 { 0 / / 1 / " ^ \ "
                ^ ~ \ / - /   " ^ "
               " ^   X 9 / g s / ^ e a
                " / " X / l s / " ?   n
             s r " G % / a " /   " ^ a d
            t e m o ^ % " % $ o l / ^   "
           o , e   / ? \ ? ~ f k " " ? s ^
          "     t / % 1 ~ /   . l h " / " ^
         ~ b m o / ?   / " m " k e . "   " ^
        / u o   / " / + e i n     " , a k " ^
       \ y r t 1 N : . " " ~ o w n "   i o " /
          e h + o ^ \ \ ~   n a n n c e   p i
       s , e ? " 1 + % "     l $ $ o   d , + p
      o " " 9 1 ~ @ . . s t l \ ~ o t i " / @ ,
     " n } + / $ @ @ % 1 " "   } " " " n / @ @ "
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      |/// \\\|
                      |//   \\|
                      /_______\)JOLLY";

        std::string input = "";

        write_script(script);
        write_inp(input);

        if (!run_program(program)) {
            std::cout << "[FAILED] JollyScript: 99 glasses program error\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "";

            for (int i = 99; i >= 1; i--) {
                if (i == 1) {
                    exp += "1 glass of milk on the wall,\n";
                    exp += "1 glass of milk.\n";
                } else {
                    exp += std::to_string(i);
                    exp += " glasses of milk on the wall,\n";

                    exp += std::to_string(i);
                    exp += " glasses of milk.\n";
                }

                exp += "Take a sip, and a cookie to dip,\n";

                if (i - 1 == 0) {
                    exp += "No glasses of milk on the wall.\n";
                } else if (i - 1 == 1) {
                    exp += "1 glass of milk on the wall.\n";
                } else {
                    exp += std::to_string(i - 1);
                    exp += " glasses of milk on the wall.\n";
                }

                exp += "\n";
            }

            exp += "No glasses of milk on the wall,\n";
            exp += "No glasses of milk.\n";
            exp += "Go to the store, buy some more,\n";
            exp += "99 glasses of milk on the wall.\n";
            exp += "\n";

            std::string actual = read_out();
            std::string name = "JollyScript: 99 glasses of milk";

            check(name, actual, exp);
        }
    }

    {
        clear_out();

        std::string script =
R"JOLLY(                                        *
                                       {
                                      B ^
                                     / " ^
                                    / O " ^
                                   / n t " ?
                                  /   r a ^ ?
                                 / t u v " ^ ?
                                / h e e T " ^ ?
                               / e     w E " ^ ?
                              /   l t e l T " ^ ?
                             / " o o l e e N " ^ ?
                            / : v   v v n i E " ^ ?
                           / B e m e e   n i S " ^ ?
                          / %   e   n l e g e S " ^ ?
                         / - g , d   o   h v i F " ^ ?
                        \ / " " r p r l t e x i F " ^ "
                       / X ~ n u i d a   n   v o T " ^ A
                      / ^ } : m p s d m   g e u h T / \ "
                     / ^ " ~ " " " " " " " " " " " / O \ /
                    \ ? " a \ \ \ \ \ \ \ \ \ \ \ \ O O /
                     " ?   s " " " " " " " " " " " " O ^ \
                    f " ? d , m e   i a s e   r r w A \ " \
                   i s " ^ a " e r a e i w e g   e o n "   \
                  r e t ? " y n r s - s d " s o c e   d   t \
                 s c h " ? t   " s   l   s ^ e l a   t   p r \
                t o i f " ? h o M   p e d   "   d l F u a a e \
               " n r o f " ? " f y d i a a a a a   l r r " " e \
              / d d u i s " ? $     r p p n - - - r i e t ~ ^ . \
             \ " " r f i s " ? ~ C " u i i c m s l i n n l \ " " /
              ^   " " x e e " ?   " ~ m n n i i w a n g c e " i \
             / $ O / " v i n " ?   / " m g g n l i y g   h   r n \
            ^ O / O / e g i t " / " a O i , , g k m i s g   d t   \
           / \ O / O n h n e e " h n / ^ n " " , i m n , e h o r a \
          /   \ O / " " " n l t r s O / \ g O \ " n i g " e e v i   $
         /     \ O / O / " e w i   / /   \ , \ O \ g n , \ s n e d p n
        /  /\/\ \ O / O / v e s " O /     \ " O \ O , g " O e s s g e ?
       /  (=''=) \ O / O e l t O / /    <| \ O \ O \ " , O \ , , , e a n
      /    /  \   \ O / n f m / O / /\/\ |  \ \ O \ O \ " \ O " " "   r \
     /  (_( UU )   \ O " " " O / / (=''=)|   \ n n n n n n n n n n n " " }
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                   \^^/^\^^/
                                   |//   \\|
                                   \/_____\/)JOLLY";

        std::string input = "";

        write_script(script);
        write_inp(input);

        if (!run_program(program)) {
            std::cout << "[FAILED] JollyScript: Twelve Days program error\n";
            FAILED_TESTS++;
        } else {
            std::string exp = "";

            for (int day = 1; day <= 12; day++) {
                exp += "On the ";

                if (day == 1) exp += "first";
                else if (day == 2) exp += "second";
                else if (day == 3) exp += "third";
                else if (day == 4) exp += "fourth";
                else if (day == 5) exp += "fifth";
                else if (day == 6) exp += "sixth";
                else if (day == 7) exp += "seventh";
                else if (day == 8) exp += "eighth";
                else if (day == 9) exp += "ninth";
                else if (day == 10) exp += "tenth";
                else if (day == 11) exp += "eleventh";
                else if (day == 12) exp += "twelfth";

                exp += " day of Christmas,\n";
                exp += "My true love gave to me,\n";

                for (int gift = day; gift >= 1; gift--) {
                    if (gift == 12) exp += "Twelve drummers drumming,\n";
                    else if (gift == 11) exp += "Eleven pipers piping,\n";
                    else if (gift == 10) exp += "Ten lords a-leaping,\n";
                    else if (gift == 9) exp += "Nine ladies dancing,\n";
                    else if (gift == 8) exp += "Eight maids a-milking,\n";
                    else if (gift == 7) exp += "Seven swans a-swimming,\n";
                    else if (gift == 6) exp += "Six geese a-laying,\n";
                    else if (gift == 5) exp += "Five gold rings,\n";
                    else if (gift == 4) exp += "Four calling geese,\n";
                    else if (gift == 3) exp += "Three French hens,\n";
                    else if (gift == 2) exp += "Two turtle doves,\n";
                    else if (gift == 1 && day == 1)
                        exp += "A partridge in a pear tree.\n";
                    else if (gift == 1)
                        exp += "And a partridge in a pear tree.\n";
                }

                exp += "\n";
            }

            std::string actual = read_out();
            std::string name = "JollyScript: Twelve Days of Christmas";

            check(name, actual, exp);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "JollyScript executable not specified\n";
        return 1;
    }

    std::string program = argv[1];

    test_jollyscript(program);

    std::cout << '\n';

    if (FAILED_TESTS == 0) {
        std::cout << "All tests passed!! Time for matcha latte with a coconut milk\n";
        return 0;
    }

    std::cout << FAILED_TESTS << " test(s) failed. sh..\n";

    return 1;
}