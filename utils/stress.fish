function stress --description "A simple function to stress test solution"
  argparse 'h/help' 't/tests=' 'g/gen=' 's/sol=' 'b/brute=' 'c/check=' 'd/delete=' -- $argv
  or return 1

  if set -q _flag_help
    echo "Example usage: stress -t <number_of_tests> -g <gen.cpp> -s <main.cpp> -b <sol.cpp> -c <check.cpp>"
    return 0
  end

  set -l tests $_flag_tests
  set -l gen_file $_flag_gen
  set -l sol_file $_flag_sol
  set -l brute_file $_flag_brute
  set -l check_file $_flag_check

  printf "Number of tests: %d\n" $tests
  g++ $gen_file -o gen # Compile the generator
  echo "Generator compiled"
  g++ $check_file -o check # Compile the checker
  echo "Checker compiled"

  g++ -O2 -g --std=gnu++23 -Wall -Wextra -Warith-conversion -Wlogical-op -Wshift-overflow=2 -Wcast-qual -Wcast-align -Wduplicated-cond -DLOCAL -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector $sol_file -o sol # Compile the solution
  echo "Solution compiled"
  g++ -O2 -g --std=gnu++23 -Wall -Wextra -Warith-conversion -Wlogical-op -Wshift-overflow=2 -Wcast-qual -Wcast-align -Wduplicated-cond -DLOCAL -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector $brute_file -o brute # Compile the brute solution
  echo "Brute compiled"

  for i in (seq 1 $tests)
    ./gen $i > input
    ./sol < input > output
    ./brute < input > output_brute 
    printf "Test %02d: " $i
    ./check input output_brute output
    if test $status -ne 0
      return 1
    end
  end
end